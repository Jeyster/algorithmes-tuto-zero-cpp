#ifndef ADDITIONNERFONCTEUR_H
#define ADDITIONNERFONCTEUR_H


class AdditionnerFoncteur
{
    public:
        AdditionnerFoncteur(int init = 0);
        virtual ~AdditionnerFoncteur();
        int getSomme() const;
        int operator()(int nombre = 0);

    protected:

    private:
        int m_addition;
};

#endif // ADDITIONNERFONCTEUR_H
