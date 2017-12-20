#include "AdditionnerFoncteur.h"

AdditionnerFoncteur::AdditionnerFoncteur(int init) : m_addition(init)
{
}

AdditionnerFoncteur::~AdditionnerFoncteur()
{
}

int AdditionnerFoncteur::getSomme() const
{
    return m_addition;
}

int AdditionnerFoncteur::operator()(int nombre)
{
    m_addition += nombre;
}
