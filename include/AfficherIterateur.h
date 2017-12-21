#ifndef AFFICHERITERATEUR_H
#define AFFICHERITERATEUR_H

#include <iostream>
#include <string>
#include <iterator>

class AfficherIterateur
{
    public:
        AfficherIterateur(char* const delimiter = "\n");
        virtual ~AfficherIterateur();
        void operator()(int a);
        void operator()(std::string a);

    protected:

    private:
        std::ostream_iterator<int> m_itInt;
        std::ostream_iterator<std::string> m_itString;
};

#endif // AFFICHERITERATEUR_H
