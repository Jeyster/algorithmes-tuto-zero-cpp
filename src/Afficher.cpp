#include "Afficher.h"
#include <iostream>

using namespace std;

Afficher::Afficher()
{
}

Afficher::~Afficher()
{
}

void Afficher::operator()(int a) const
{
    cout << a << endl;
}

void Afficher::operator()(string a) const
{
    cout << a << endl;
}
