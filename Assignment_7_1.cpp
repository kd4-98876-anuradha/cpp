#include <iostream>
using namespace std;

class Employee
{
    int id;
    double salary;

    public:
    Employee() : id(0), salary(0) {}

    virtual void accept()
    {
        cout<<"Id : ";
        cin>>id;
        cout<<"Salary : ";
        cin>>salary;
    }

    virtual void display()
    {
        cout << "Id : " << id << endl;
        cout << "Salary : " << salary << endl;
    }
    virtual ~Employee() {}
};


class Manager : virtual public Employee
{   private:
    double bonus;

    public:
    Manager() : bonus(0) {}

    void accept()
    {
        Employee::accept();
        cout << "Bonus : ";
        cin >> bonus;
    }

    void display()
    {
        Employee::display();
        cout << "Bonus : " << bonus << endl;
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    void displayBonus()
    {
        cout << "Bonus : " << bonus << endl;
    }
};


class Salesman : virtual public Employee
{   private:
    double commission;

    public:
    Salesman() : commission(0) {}

    void accept()
    {
        Employee::accept();
        cout << "Commission : ";
        cin >> commission;
    }

    void display()
    {
        Employee::display();
        cout<<"Commission : "<<commission << endl;
    }

    void setCommission(double commission)
    {
        this->commission=commission;
    }

    void displayCommission()
    {
        cout<<"Commission : "<<commission<<endl;
    }
};


class SalesManager : public Manager, public Salesman
{
public:
    void accept()
    {
        Employee::accept();
        double bonus, commission;
        cout << "Bonus : ";
        cin >> bonus;
        setBonus(bonus);
        cout << "Commission : ";
        cin >> commission;
        setCommission(commission);
    }

    void display()
    {
        Employee::display();
        displayBonus();
        displayCommission();
    }
};

int menuList()
{
    int choice;
    cout << "0. Exit"<<endl;
    cout << "1. Add Manager"<<endl;
    cout << "2. Add Salesman"<<endl;
    cout << "3. Add SalesManager"<<endl;
    cout << "4. Display Count"<<endl;
    cout << "5. Display Managers"<<endl;
    cout << "6. Display Salesmen"<<endl;
    cout << "7. Display SalesManagers"<<endl;
    cout << "Enter choice : "<<endl;

    cin >> choice;
    return choice;
}


int main()
{
    Employee *arr[100] = { NULL };

    int count = 0;
    int choice;

    while ((choice = menuList()) != 0)
    {
        switch (choice)
        {
        case 1:
            arr[count] = new Manager();
            arr[count]->accept();
            count++;
            break;

        case 2:
            arr[count] = new Salesman();
            arr[count]->accept();
            count++;
            break;

        case 3:
            arr[count] = new SalesManager();
            arr[count]->accept();
            count++;
            break;

        case 4:
        {
            int manager = 0;
            int salesman = 0;
            int salesManager = 0;

            for (int i = 0; i < count; i++)
            {
                if (dynamic_cast<SalesManager *>(arr[i]) != NULL)
                    salesManager++;
                else if (dynamic_cast<Manager *>(arr[i]) != NULL)
                    manager++;
                else if (dynamic_cast<Salesman *>(arr[i]) != NULL)
                    salesman++;
            }

            cout <<"\nManagers : "<<manager<<endl;
            cout <<"\nSalesmen : "<<salesman<<endl;
            cout <<"\nSalesManagers : "<<salesManager<<endl;

            break;
        }

        case 5:
            for (int i = 0; i < count; i++)
            {
                if (dynamic_cast<Manager *>(arr[i]) != NULL &&
                    dynamic_cast<SalesManager *>(arr[i]) == NULL)
                {
                    arr[i]->display();
                }
            }
            break;

        case 6:
            for (int i = 0; i < count; i++)
            {
                if (dynamic_cast<Salesman *>(arr[i]) != NULL &&
                    dynamic_cast<SalesManager *>(arr[i]) == NULL)
                {
                    arr[i]->display();
                }
            }
            break;

        case 7:
            for (int i = 0; i < count; i++)
            {
                if (dynamic_cast<SalesManager *>(arr[i]) != NULL)
                    arr[i]->display();
            }
            break;
        }
    }

    for (int i = 0; i < count; i++)
    {   delete arr[i];
        arr[i] = NULL;
    }
    return 0;
}