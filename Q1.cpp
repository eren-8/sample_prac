#include<iostream>
using namespace std;

class Electricity{
    int sanctionload;
    int electricityslab;
    long presentreading;
    long previousreading;
    long consumption;
    void seta(int a){
        this->sanctionload=a;
    }
    public:
        //default constructor and initialilzed all values to 0.
        Electricity(){
            sanctionload=0;
            electricityslab=0;
            presentreading=0;
            previousreading=0;
            consumption=0;
        }
        //function to return values as per request
        int getsanctionload(){
            return sanctionload;
        }
        int getelectricityslab(){
            return electricityslab;
        }
        long getpresentreading(){
            return presentreading;
        }
        long getpreviousreading(){
            return previousreading;
        }
        long getconsumption(){
            return consumption;
        }
        //function to set values as per user.
        void setsanctionload(int x){
            this->sanctionload=x;
        }
        void setelectricityslab(int electricity){
            this->electricityslab=electricity;
        }
        void setpresentreading(long presentreading){
            this->presentreading=presentreading;
        }
        void setpreviousreading(long previousreading){
            this->previousreading=previousreading;
        }
        void setconsumption(long consumption){
            this->consumption=consumption;
        }
        //function calculate electricity bill
        double calculateelectricitybill(){
            if(presentreading<previousreading){
                return 0;
            }
            else{
            double bill=double(sanctionload*electricityslab)+double((consumption)*double(electricityslab)/100);
            return bill;
            }
        }
        //function to accept values
        void accept(){
            cout<<"enter sanctionload: ";
            cin>>sanctionload;
            cout<<"enter electricityslab: ";
            cin>>electricityslab;
            cout<<"enter presentreading: ";
            cin>>presentreading;
            cout<<"enter previousreading: ";
            cin>>previousreading;
            cout<<"enter consumption: ";
            cin>>consumption;
        }
        //function to display values
        void display(){
            cout<<"sanctionload is "<<this->sanctionload<<endl;
            cout<<"electricityslab is "<<this->electricityslab<<endl;
            cout<<"presentreading is "<<this->presentreading<<endl;
            cout<<"previousreading is "<<this->previousreading<<endl;
            cout<<"consumption is "<<this->consumption<<endl;
        }
};

int main(){
    Electricity e;
    e.accept();
    //e.setconsumption(100);
    e.display();
    //cout<<e.getconsumption()<<endl;
    cout<<"electricity bill is: "<<e.calculateelectricitybill()<<endl;
}