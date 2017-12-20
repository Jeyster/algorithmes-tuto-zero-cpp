#ifndef TESTVOYELLES_H
#define TESTVOYELLES_H


class TestVoyelles
{
    public:
        TestVoyelles();
        virtual ~TestVoyelles();
        bool operator()(std::string const& chaine) const;

    protected:

    private:
};

#endif // TESTVOYELLES_H
