#include<iostream>

using namespace std;

//abstract class:
class AbstractEmployee{
   virtual void AskForPromotion() = 0; //a leszármazott osztályoknak magunak kell implementálni
   //tehát a cpp-ben a virtual void method()-ról lehet felismerni (JAVA: abstract class).
};
//class Employee{}; ezzel kezdtünk
class Employee : AbstractEmployee{  //class Derived/child : public Base
protected:   //default: private --> encapsulation
//fields
   string Name;
   string Company;
   int Age;
public: 
//setters and getters --> encapsulation (but they are public!)
    void setAge(int Age) { //we can provide special rules with this setter
      if(Age>=18)
        this->Age = Age;
    }
    
    void setCompany(string Company) {
        this->Company = Company;
    }
    
    void setName(string Name) {
        this->Name = Name;
    }
    
    int getAge() {
        return Age;
    }
    
    string getCompany() {
        return Company;
    }
    
    string getName() {
        return Name;
    }
      
//constructors;
   Employee(){} //default, kell ha már van saját.

   Employee(string name, string company, int age){ //parametrized
      Name = name;
      Company = company;
      Age = age;

   }
   void IntroduceYourself(){
      cout << "Name - " <<Name<< endl;
      cout << "Company - " <<Company<< endl;
      cout << "Age - " <<Age<< endl;
   }

   void AskForPromotion(){
      if(Age > 30){
         cout << Name <<" got promoted." << endl;
      }else{
         cout << Name <<", sorry no promoted for you." << endl;
      }

   }
};

class Developer : public Employee{ //subclass : Base/super/parent class
public:
string FavLanguage; //új
// Creating object of sub class will
// invoke the constructor of base classes, tehát az alábbiak közül az 1. nem kell,
//a 2.-nak így nincs értelme, csak kibővítve:
/*
   Developer(){};
   
   Developer()
      : Employee ()
   {}
*/   
//tehát a base class alap konstruktora működik,a setterekkel, és a metódusa is
//DE ha akarunk egy ilyet: Developer d2 = Developer("Andras", "Sony", 31);
//akkor a fenti második konstruktort ki kell bővíteniígy:
Developer(string name, string company, int age, string favLanguage)
      : Employee (name, company, age)
   {
      //és ide jöhet a tképpeni ÚJ dolog:
      FavLanguage = favLanguage;
   }
//így viszont "no default constructor exists for class "Developer"tehát kell ez is:
Developer(){};

void IntroduceYourself(){
      cout << "Name - " <<Name<< endl;
      cout << "Company - " <<Company<< endl;
      cout << "Age - " <<Age<< endl;
      cout << "Favourite languege - " <<FavLanguage<< endl;
   }
};

int main()
{
   Employee e1 = Employee("Andras", "Sony", 31);
   Employee e2;
   Employee e3;
  /*  e1.Name = "Andras"; komment block Shift + Alt + A
   e1.Company = "GE";
   e1.Age = 42; */

   e2.setName("John");
   e2.setCompany("Honda");
   e2.setAge(22); 
   e2.setAge(12); //ez így random memóriaszemét lenne ha előtte nem lenne helyes adat

   //tudja melyik IntroduceYourself();-et kell meghívnia.
   //? az AskForPromotion()-t miért nem kötelező a Developerben implementálni?

   e1.IntroduceYourself();
   e2.IntroduceYourself();
   e1.AskForPromotion();
   e2.AskForPromotion();
   //cout << "e1.AskForPromotion(): " << e1.AskForPromotion() << endl; //ilyen nincs

   // Creating object of sub class will
   // invoke the constructor of base classes:
   Developer d1;

   Developer d2 = Developer("Bela", "Sony", 31, "C++");

   d1.setAge(23);
   d1.setName("Magdi");
   d1.setCompany("Egis");
   d1.FavLanguage = "go";//mivel public, így be lehet állítani de kerülendő, kell az encapsulation.
   cout<<endl;
   cout<<"Developers:"<<endl;
   cout<<endl;
   cout << "Developer " <<d1.getName()<<" is:" <<endl;
   d1.IntroduceYourself();
   cout << "Developer " <<d2.getName()<<" is:" <<endl;
   d2.IntroduceYourself();
   d2.AskForPromotion();
   d1.AskForPromotion();
   return 0;
}