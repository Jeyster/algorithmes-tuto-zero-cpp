#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Remplir.h"
#include "TestVoyelles.h"
#include "ComparaisonLongueur.h"
#include "Afficher.h"
#include "AdditionnerFoncteur.h"

using namespace std;

int main()
{
    /* Remplissage d'un conteneur grace au foncteur Remplir
       Itération sur conteneur grâce à un itérateur à l'algorithme generate()
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


    return 0;
}
