#include<iostream>
using namespace std;


class Complex{
        public:
            float real, img;
            
            Complex(){
                real = 0;
                img = 0;
            }
            
            void get(){
                cout << "Enter the real part: "; cin >> real;
                cout << "Enter the imaginary part: "; cin >> img;
            }
            
            void display(){
                cout << real << " + " << img << "i" << endl;
            }
            
            Complex operator +(Complex obj){
                Complex temp;
                temp.real = this->real + obj.real;
                temp.img = this->img + obj.img;
                return temp;
            }
            
            Complex operator *(Complex obj){
                Complex temp;
                temp.real = (this->real * obj.real) - (this->img * obj.img);
                temp.img = (this->real * obj.img) + (this->img * obj.real);
                
                return temp;
            }
            
            Complex operator -(Complex obj){
                Complex temp;
                temp.real = this->real - obj.real;
                temp.img = this->img - obj.img;
                return temp;
            }
            
            friend ostream &operator << (ostream &out, const Complex &obj);
            friend istream &operator >> (istream &in, Complex &obj);
};

ostream &operator << (ostream &out, const Complex &obj){
    out << obj.real << " + " << obj.img << "i" << endl;
    return out;
}

istream &operator >> (istream &in, Complex &obj){
    cout << "Enter the real part: "; in >> obj.real;
    cout << "Enter the imaginary part: "; in >> obj.img;
    return in;
}


int main(){
    Complex c1, c2, c3, c4, c5;
    
    // Overloaded +, -, * operators
    c1.get();
    c2.get();
    
    cout << endl;
    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    cout << endl;
    
    c3 = c1 + c2;
    cout << "c1 + c2 = "; c3.display();
    
    c4 = c1 * c2;
    cout << "c1 * c2 = "; c4.display();
    
    c5 = c1 * c2;
    cout << "c1 * c2 = "; c5.display();
    
    //    now using overloaded insertion '<<' and extraction '>>' operator
    Complex c6;
    
    cin >> c6;
    cout << c6;
    return 0;
}
