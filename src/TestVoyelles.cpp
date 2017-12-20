#include <string>
#include "TestVoyelles.h"

TestVoyelles::TestVoyelles()
{
}

TestVoyelles::~TestVoyelles()
{
}

bool TestVoyelles::operator()(std::string const& chaine) const
{
    for(int i(0); i<chaine.size(); ++i)
    {
        switch (chaine[i])   //On teste les lettres une à une
        {
            case 'A':        //Si c'est une voyelle
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'Y':
                return true;  //On renvoie 'true'
            default:
                break;        //Sinon, on continue
        }
    }
    return false;   //Si on arrive là, c'est qu'il n'y avait pas de voyelle du tout
}
