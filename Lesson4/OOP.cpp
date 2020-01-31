/*------Obejct Oriented Programming------*/

#include<bits/stdc++.h>

using namespace std;

class Car{
    public:
        // char name[20];
        char *name;
        int model;
        int price;
        int mileage;
        static int count;
        const int tyres;

        //this is a const function which doesn't change any value in any object. *helps in debugging*, as const function can't play a part in rogue values.
        void print()const{
            cout<<name<<"\n This car costs - $"<<price<<"\n The mileage is - "<<mileage<<"\n This is this car's "<<model<<"th iteration"<<endl<<endl;
        }

        void operator = (Car x){
            if(name!=NULL){
                delete []name;
                name = NULL;
            }
            cout<<"In Copy Assignment constructor"<<endl;
            name = new char[strlen(x.name)+1];
            strcpy(name, x.name);
            model = x.model;
            price = x.price;
            mileage = x.mileage;
        }

        Car(Car &x):tyres(4){
            //why did we have to pass by reference, because to pass by value, the value is copied to a temporary variable,
            //now if the copy constructor is what we are defining right now, then how can the compiler create a copy?.
            cout<<"In Copy constructor"<<endl;
            name = new char[strlen(x.name)+1];
            strcpy(name, x.name);
            model = x.model;
            price = x.price;
            mileage = x.mileage;
            count++;
        }

        Car():tyres(4){
            name = NULL;
            cout<<"In Default Constructor"<<endl;
            count++;
        }

        Car(char *n, int p, int m, int mil):tyres(4){
            cout<<"in Paramtereized constructor"<<endl;
            name = new char[strlen(n)+1];
            strcpy(name, n);
            price = p;
            model = m;
            mileage = mil;
            count++;
        }

        void SetName(char *n){
            if(name!=NULL){
                delete []name;
                name=NULL;
            }
            name = new char[strlen(n)+1];
            strcpy(name, n);
        }

        ~Car(){
            cout<<"Destructor called on object "<<name<<endl;
            if(name!=NULL){
                cout<<". this is called too"<<endl;
                delete []name;
            }
            count--;
        }
};

int Car::count = 0;

int main(){

    // Car Alfa_Romeo_4C;
    // Alfa_Romeo_4C.price = 1000000;
    // Alfa_Romeo_4C.model = 4;
    // Alfa_Romeo_4C.mileage = 11;
    // Alfa_Romeo_4C.SetName("Alfa Romeo");
    // cout<<Alfa_Romeo_4C.price<<"  and "<<Alfa_Romeo_4C.mileage<<endl;
    // strcpy(Alfa_Romeo_4C.name, "Alfa Romeo");
    // cout<<Alfa_Romeo_4C.name<<endl;
    // Alfa_Romeo_4C.print();
    //
    // Car BMW_X6;
    // BMW_X6.price = 2000000;
    // BMW_X6.model = 3;
    // BMW_X6.mileage = 8;
    // // strcpy(BMW_X6.name, "BMW X6");
    // BMW_X6.SetName("BMW X6");
    // BMW_X6.print();
    //
    // Car BMW_X6_2(BMW_X6);
    // BMW_X6_2.print();

    //Had we not used our custom copy consructor, (as we have a pointer in our class,) the address is copied instead of the value,
    //thus all objects that are created from copy constructor have a pointer pointing to the same loction,
    //thus changes in one cause changes in others as well.
    //our custom copy constructor is creating a DEEP Copy,
    //and the Default copy consructor creates a SHALLOW COPY.

    //Initializattion list
    //  Car():tyres(4),price(p){};  --  this Initializes the const values in list.

    Car *pointer = new Car("Marrusia B2", 1000000, 3, 15);
    (*pointer).print();
    cout<<(*pointer).count<<endl;
    cout<<(*pointer).tyres<<endl;

    return 0;
}
