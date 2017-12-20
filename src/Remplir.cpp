#include "Remplir.h"
#include <cstdlib>

using namespace std;

Remplir::Remplir()
{
}

Remplir::~Remplir()
{
}

int Remplir::operator()() const
{
    return rand() % 10;
}
