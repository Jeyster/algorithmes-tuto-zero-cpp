#ifndef COMPARAISONLONGUEUR_H
#define COMPARAISONLONGUEUR_H

#include <string>

class ComparaisonLongueur
{
    public:
        ComparaisonLongueur();
        virtual ~ComparaisonLongueur();
        bool operator()(const std::string& a, const std::string& b);

    protected:

    private:
};

#endif // COMPARAISONLONGUEUR_H
