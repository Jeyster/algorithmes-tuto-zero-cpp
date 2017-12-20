#ifndef AFFICHER_H
#define AFFICHER_H

#include <string>

class Afficher
{
    public:
        Afficher();
        virtual ~Afficher();
        void operator()(int a) const;
        void operator()(std::string a) const;

    protected:

    private:
};

#endif // AFFICHER_H
