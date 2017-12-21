#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "Remplir.h"
#include "TestVoyelles.h"
#include "ComparaisonLongueur.h"
#include "Afficher.h"
#include "AfficherIterateur.h"
#include "AdditionnerFoncteur.h"

using namespace std;

int main()
{
    /* -------------------------------------------- */
    /* --- Foncteurs, Itérateurs et Algorithmes --- */
    /* -------------------------------------------- */
    /* Remplissage d'un conteneur grace au foncteur Remplir
       Itération sur conteneur grâce à un itérateur ou à l'algorithme generate()
       Trie dans ordre croissant grâce à l'algo sort()
       Comptage dans conteneur grâce à l'algo count() */
    srand(time(0));

    vector<int> tab1(100,0);
    vector<int> tab2(100,0);
    vector<int> tab3(100,0);

    /* Avec itérateur */
    /*
    Remplir remplirFoncteur;
    for (vector<int>::iterator it=tab.begin(); it!=tab.end(); it++)
    {
        *it = remplirFoncteur();
        cout << *it << endl;
    }
    */

    /* Avec algorithme */
    generate(tab1.begin(), tab1.end(), Remplir());
    generate(tab2.begin(), tab2.end(), Remplir());
    //sort(tab1.begin(), tab1.end());
    //sort(tab2.begin(), tab2.end());
    for_each(tab1.begin(), tab1.end(), Afficher());

    int const occurence = count(tab1.begin(), tab1.end(), 5);
    cout << endl << "Nombre de 5 dans le conteneur : " << occurence << endl;

    AdditionnerFoncteur sommer;
    sommer = for_each(tab1.begin(), tab1.end(), sommer);
    double somme = sommer.getSomme();
    double moyenne = somme/tab1.size();
    cout << endl << "Somme des nombres du conteneur : " << somme << endl;
    cout << "Moyenne des nombres du conteneur : " << moyenne << endl;

    transform(tab1.begin(), tab1.end(), tab2.begin(), tab3.begin(), plus<int>());
    for_each(tab3.begin(), tab3.end(), Afficher());



    /* -------------------------------- */
    /* --- Algorithmes et Prédicats --- */
    /* -------------------------------- */
    /* Remplissage d'un conteneur avec mots du dico ods4.txt
       Comptage du nombre de mots et du nombre de ceux ayant des voyelles
       Utilisation de l'algo count_if() avec prédicat TestVoyelle */
    vector<string> tableau;
    ifstream iStream;
    string mot;

    iStream.open("liste-mots/ods4.txt");

    while (iStream >> mot)
    {
        tableau.push_back(mot);
        //cout << mot << endl;
    }

    sort(tableau.begin(), tableau.end(), ComparaisonLongueur());
    //for_each(tableau.begin(), tableau.end(), Afficher());


    cout << endl << "Nombre de mots dans ods4 : " << tableau.size() << endl;

    iStream.close();

    int motAvecVoyelles = count_if(tableau.begin(), tableau.end(), TestVoyelles());

    cout << endl << "Nombre de mots avec voyelles dans ods4 : " << motAvecVoyelles << endl;


    /* --------------------------- */
    /* --- Itérateurs sur flux --- */
    /* --------------------------- */

    /* Flux sortant */
    ostream_iterator<double> itDouble(cout, "\n");
    ostream_iterator<string> itString(cout, " ");
    cout << endl << endl;
    *itDouble = 3.14;
    *itDouble = 2.55;
    *itString = "Hello";
    *itString = "World";
    *itString = "!";
    *itString = "Hello World !";
    cout << endl << endl;

    /* Flux entrant */
    ifstream fichier;
    fichier.open("liste-mots/ods4.txt");

    istream_iterator<string> itMot(fichier); // itérateur sur le fichier
    istream_iterator<string> fin; //signal de fin
    vector<string> listeMots;

    /*
    while(itMot != fin)
    {
        listeMots.push_back(*itMot);
        itMot++;
    }
    */

    /*
    vector<string> tabMots(400000, "");
    copy(itMot, fin, tabMots.begin());
    //for_each(tabMots.begin(), tabMots.end(), AfficherIterateur(" !!\n"));
    */

    back_insert_iterator<vector<string> > itVector(listeMots);
    copy(itMot, fin, itVector);
    copy(listeMots.begin(), listeMots.end(), ostream_iterator<string>(cout, "\n"));

    fichier.close();

    /* ----------------------- */
    /* --- Flux sur string --- */
    /* ----------------------- */
    ostringstream fluxString;

    fluxString << "Salut les ";
    fluxString << 3;
    fluxString << " tocards";

    string const chaine = fluxString.str();

    cout << chaine << endl;

    return 0;
}
