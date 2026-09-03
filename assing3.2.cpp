#include<iostream>
using namespace std;

class Tollbooth
{
    private:
    int totalCars;
    double totalCash;

    public:

    Tollbooth( void ) : totalCars( 0 ), totalCash( 0 )
    {
    }

    void payingCar( void )
    {
        this->totalCars++;
        this->totalCash = this->totalCash + 0.50;
    }

    void nopayCar( void )
    {
        this->totalCars++;
    }

    void acceptRecord( void )
    {
        int choice;

        cout<<"1. Paying Car"<<endl;
        cout<<"2. Non Paying Car"<<endl;

        cout<<"Enter choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                this->payingCar();
                break;

            case 2:
                this->nopayCar();
                break;

            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }

    void printRecord( void )
    {
        int payingCars;
        int nonPayingCars;

        payingCars = (int)(this->totalCash / 0.50);
        nonPayingCars = this->totalCars - payingCars;

        cout<<"Total Cars : "<<this->totalCars<<endl;
        cout<<"Total Cash : "<<this->totalCash<<endl;
        cout<<"Paying Cars : "<<payingCars<<endl;
        cout<<"Non Paying Cars : "<<nonPayingCars<<endl;
    }
};

int main()
{
    Tollbooth t1;

    t1.acceptRecord();
    t1.printRecord();

    return 0;
}