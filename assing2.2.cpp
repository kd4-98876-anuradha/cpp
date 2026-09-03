#include<iostream>
using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

/* void initDate(struct Date* ptrDate){
    ptr->day = 01;
    ptr->month = 6;
    ptr->year = 2000;
} */

void acceptDateFromConsole(struct Date* ptrDate){ 
    cout<<"Day: ";
    cin>>ptrDate->day;
    cout<<"Month: ";
    cin>>ptrDate->month;
    cout<<"Year: ";
    cin>>ptrDate->year;
} 

void printDateOnConsole(struct Date* ptrDate){
    cout<<"Day : "<<ptrDate->day << " "; 
    cout<<"Month : "<<ptrDate->month << " "; 
    cout<<"Year : "<<ptrDate->year << " " << endl; 
}

int menuList(void){
    int choice;
    cout<<"0.Exit\n";
    cout<<"1.Accept date\n";
    cout<<"2.Print date\n";
    cout<<"Enter choice: ";
    cin>>choice;
    return choice;
}

int main(){
    struct Date dt;
    int choice;
    while((choice = menuList( )) != 0)
    {
        switch (choice)
        {
            case 1:
                acceptDateFromConsole(&dt);
                break;
            case 2:
                printDateOnConsole(&dt);
                break;
        }
    }
    return 0;
}