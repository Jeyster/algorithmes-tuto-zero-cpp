#include "AfficherIterateur.h"

using namespace std;

AfficherIterateur::AfficherIterateur(char* const delimiter) : m_itInt(cout, delimiter), m_itString(cout, delimiter)
{
}

AfficherIterateur::~AfficherIterateur()
{
}

void AfficherIterateur::operator()(int a)
{
    *m_itInt = a;
}

void AfficherIterateur::operator()(string a)
{
    *m_itString = a;
}
