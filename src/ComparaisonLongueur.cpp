#include "ComparaisonLongueur.h"

using namespace std;

ComparaisonLongueur::ComparaisonLongueur()
{
}

ComparaisonLongueur::~ComparaisonLongueur()
{
}

bool ComparaisonLongueur::operator()(const string& a, const string& b)
{
    return a.length() < b.length();
}
