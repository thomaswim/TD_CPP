#include <iostream> 
using namespace std; 

class vecteur
{
private:
    double *elements ;
    int dim ;
    /* data */
public:
    vecteur(int dim1, double elements1){
        dim = dim1 ;
        elements = new double [dim1];
        for (int i = 0; i < dim1; i++)
        {
            elements[i] = elements1;
        }
    };
    vecteur(int dim1){
        dim = dim1 ;
        elements = new double [dim1];
    }
    vecteur(){
        dim = 0;
        elements = NULL;
    }
    ~vecteur(){
        delete [] elements; 
    };

    void dimension(){
        cout<<"la dimension est de "<<dim<<endl;
    }

    void afficher_vect(){
        for (int i = 0; i < dim; i++)
        {
            cout<<elements[i]<<endl;
        }
    };
        
    void get_dim(){
        cout<<"La valeur de votre nouveau vecteur"<<endl;
        cin>>dim;
        delete [] elements;
        elements = new double [dim];
    }

    void get_value(){
        cout<<"nouvelle valeurs :"<<endl;
        for (int i = 0; i < dim; i++)
        {
            cout<<"nouvelle valeur de la case "<<i<<":"<<endl;
            cin>>elements[i];
        }
        
    }
    
};

int main (){
    vecteur vect1 ;
    vecteur vect2(10);
    vecteur v3(3,3.0);

    vect1.dimension();
    vect2.dimension();
    v3.dimension();
    v3.afficher_vect();
    v3.get_dim();
    v3.dimension();
    v3.get_value();
    v3.afficher_vect();
    return 0;
}

