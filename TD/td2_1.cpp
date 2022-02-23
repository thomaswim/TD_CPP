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
    vecteur & operator += ( const vecteur & autre){
        if (autre.dim==dim)
        {
            for (int i = 0; i < dim; i++)
            {
                elements[i] = elements[i]+autre.elements[i];
            }
                
        }else{
            cout << "Pas meme dimension"<<endl;
        }
        return *this;
        
    }
};


 vecteur operator + (vecteur & v1, vecteur & v2 ){
       vecteur v3(v1.ret_dim());
       if (v1.ret_dim() == v2.ret_dim())
       
    {
       int dimension = v1.ret_dim();
        
        double value;
       for (int i = 0; i < dimension ; i++)
        {
            value = v1.ret_value(i)+ v2.ret_value(i);
            v3.input_value(value , i);
        }
        
    return v3;

        
    }else{
        cout << "Pas meme dimension"<<endl;
         
        return v3;
    } 
   return v3;
    
 }


int main (){
vecteur v1(3), v2(3,5), v3(3,10) ;
v1.afficher_vect();
cout << v1.ret_dim() << endl;
v1=v2+v3 ;
v1.afficher_vect();
v1+=v2;
v1.afficher_vect();

    return 0;
}

