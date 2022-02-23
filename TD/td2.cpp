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

    int ret_dim(){
        return dim ;
    }

    double ret_value( int  i ){
        return elements[i];
    }

    void get_value(){
        cout<<"nouvelle valeurs :"<<endl;
        for (int i = 0; i < dim; i++)
        {
            cout<<"nouvelle valeur de la case "<<i<<":"<<endl;
            cin>>elements[i];
        }
        
    }

    void input_value (double value, int indice){
            elements[indice] = value;
    }
    float operator [] (int indice ) const {
        return elements[indice];
    }
    double & operator [] (int indice )  { 
        return elements[indice];
     }
    vecteur & operator = (const vecteur & autre ){

        dim = autre.dim ;
        delete [] elements;
        elements = new double [dim];
        for (int i = 0; i < dim; i++)
        {
            elements[i] = autre.elements[i];
        }


        return *this;
    }
};


 vecteur operator + (vecteur v1, vecteur v2 ){
vecteur v3;
    if (v1.ret_dim() == v2.ret_dim())
    {
       //int dimension = v1.ret_dim();
        
        //double value;
     /*   for (int i = 0; i < dimension ; i++)
        {
            value = v1.ret_value(i)+ v2.ret_value(i);
            v3.input_value(value , i);
        }*/
        
    return v3;

        
    }else{
        cout << "Pas meme dimension"<<endl;
         
        return v3;
    }
    
    
 }


int main (){
    vecteur vect1(10) ;
    vecteur vect2(10);
    vecteur v3(10,3.9);
    float f;

    vect1.dimension();
    vect2.dimension();
    v3.dimension();
    v3.afficher_vect();
    f = v3[0];
    cout << "Element 0 : "<< f << endl;
    v3[0] = 5.0;
    cout << "Element 0 : "<< v3[0] << endl;
    cout << "Element 0 v2: "<< vect2[0] << endl;
    vect2=v3;
    cout << "Element 0  v2: "<< vect2[0] << endl;
    vecteur vect4 ;
    vect4 = v3;
    vect4 = operator+(vect1,vect2);
    return 0;
}

