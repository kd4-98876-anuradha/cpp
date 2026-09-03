  #include<iostream>
  using namespace std;
  class Employee{
    private:
    int id;
    double salary;
    public:
    Employee(int id, double salary): id(id), salary(salary) {}
    Employee(): id(0), salary(0.0) {}
    void setID(int id){
      this->id = id;
    }
    void setsalary(double salary){
      this->salary = salary;
    }
    int getid(void){
      return this->id;
    }
    double getsalary(void){
      return this->salary;
    }
    void Accept(void){
      cout<<"Enter Employee ID: "<<endl;
      cin>>id;
      cout<<"Enter Employee Salary: "<<endl;
      cin>>salary;
    }
    void Display(void){
      cout<<"Employee ID: "<<id<<endl;
      cout<<"Employee Salary: "<<salary<<endl;
    }
  };
  class Manager:public Employee{
    private:
    double bonus;
    public:
    Manager(double bonus): bonus(bonus){}
    Manager(int id, double salary, double bonus): Employee(id, salary) {
      this->bonus = bonus;
    }
    void setBonus(double bonus){
      this->bonus = bonus;
    }
    double getBonus(void){
      return this->bonus;
    }
    void accept(void){
      Employee::Accept();
      cout<<"Enter Manager Bonus: ";
      cin>>bonus;
    }
    void display(void){
      Employee::Display();
      cout<<"Manager Bonus: "<<bonus<<endl;
    }
    void acceptManager(void){
      this->accept();
    }
    void displayManager(void){
      this->display();
    }


  };
  class Salesman:public Employee{
    private:
    double commission;
    public:
    Salesman(double commission): commission(commission){}
    Salesman(int id,double salary,double commission): Employee(id,salary){
      this->commission = commission;
    }
    void setCommission(double commission){
      this->commission = commission;
    }
    double getCommission(void){
      return this->commission;
    }
    void accept(void){
      Employee::Accept();
      cout<<"Enter Salesman Commission: ";
      cin>>commission;
    }
    void display(void){
      Employee::Display();
      cout<<"Salesman Commission: "<<commission<<endl;
    }
    void acceptSalesman(void){
    this->accept();
   }

    void displaySalesman(void){
    this->display();
}
  };
  class SalesManager:public Manager,public Salesman{
    public:
    SalesManager(int id,double salary,double bonus,double commission): Manager(id,salary,bonus),Salesman(id,salary,commission){}
    
    void accept(void){
      Manager::accept();
      Salesman::accept();
      

    }
    void display(void){
      Manager::display();
      Salesman::display();
    }

    
  };
  int main(){
    SalesManager sm(1,50000,10000,5000);
    sm.accept();
    sm.display();
    return 0;
  }
