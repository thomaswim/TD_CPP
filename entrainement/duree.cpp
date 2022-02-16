#include <iostream>

using namespace std ;

class Duree{
    public :
        Duree(int heures = 0, int minutes = 0, int secondes = 0){
            m_heures = heures;
            m_minutes = minutes;
            m_secondes = secondes; 
        };

        void afficher(){
                cout << m_heures<< " heures " << endl;
                cout << m_minutes<< " minutes " << endl;
                cout << m_secondes<< " secondes " << endl;
                cout << endl;
        }

        int getHeures(){
            return m_heures;
        }

        int getMinutes(){
            return m_minutes;
        }

        int getSecondes(){
            return m_secondes;
        }

        bool estEgal(Duree const& b) const {
        if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes)

            return true;

        else

            return false;
        }

    private :
        int m_heures;
        int m_minutes;
        int m_secondes;
};

        bool operator==(Duree const& a, Duree const& b ){
            return a.estEgal(b);
        };


int main(){

    Duree ajd , demain(3,4,5);
    ajd.afficher();
    demain.afficher();
    
    if (ajd == demain)
    {
        cout << "c est les meme" <<endl;
    }else{
        cout <<"c est paq les meme" <<endl;
    }
    
    return 0;
}