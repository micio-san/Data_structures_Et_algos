// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Cat {
public:
    string Name;
    int Age;
    bool IsNice;
    string FurColor;
    string SayHi() {
        string l = to_string(Age);
        return "Hi my name is " + Name + "I am an " + l + " year" + (Age > 1 ? "s" : "") + " old " + FurColor + " cat";
    }
};

void callCat() {
    Cat cat1;
    cat1.Name = "Tora";
    cat1.Age = 11;
    cat1.IsNice = false;
    cat1.FurColor = "Tabby";
    cout << cat1.SayHi();
}

// WITH CONSTRUCTOR

class Dog {
public:
    string Name;
    int Age;
    string Color;
    bool IsNice;
    Dog(string name, int age, string color, bool isnice){
        this->Name = name;
        this->Age = age;
        this->Color = color;
        this->IsNice = isnice;
     }
private: 
    string AssertNiceness() {
        return IsNice ? "and I am very nice!" : "and I bite >:(";
    }
public:
    string sayBau() {
        string l = to_string(Age);
        return "Hello my name is " + Name + ", I am " + l + (Age > 1 ? " years " : " year ") + "old " + Color + "dog, " + AssertNiceness();
    }
};

void callDog() {
    Dog dog1 = Dog("Dog", 3, "Black ", false);
    cout << dog1.sayBau();
}

//ENCAPSULATION WITH GETTERS AND SETTERS

class Rabbit {
private:
    string Name;
    int Age;
    string Color;
    string FavFood;
public:    
   void setAttributes(string name, int age, string color, string favFood) {
        Name = name;
        Age = age;
        Color = color;
        FavFood = favFood;
    }
    string getName() {
        return Name;
    }
    int getAge() {
        return Age;
    }
    string getColor() {
        return Color;
    }
    string getFavFood() {
        return FavFood;
    }
    string askFood() {
        return FavFood == "Carrots" ? "Yes " + getName() + " you get " + getFavFood() : "Sorry," + getName() + " I do not have " + FavFood + " D:" + "\n";
    }
    Rabbit(string name, int age, string color, string favFood) {
        this->Name = name;
        this->Age = age;
        this->Color = color;
        this->FavFood = favFood;
    }
};

void callRabbit() {
    Rabbit rabbit1 = Rabbit("Tom", 3, "Black", "Salad");
    cout << rabbit1.askFood();
    rabbit1.setAttributes("Margrete", 1, "Black", "Carrots");
    cout << rabbit1.askFood();
}

//ABSTRACTION ABSTRACT CLASSES PURE VIRTUAL FUNCTIONS
class Shape {
public:
    virtual double area() = 0;
};

class Square :public Shape {
public:
    double Side;
    Square(double side) {
        this->Side = side;
    };
    double area() {
        return Side * Side;
    }
};

class Triangle : public Shape {
public:
    double Base;
    double Height;
    Triangle(double base, double height) {
        this->Base = base;
        this->Height = height;
    }
    double area() {
        return (Base * Height) / 2;
    }
};

void makeShape() {

    Shape *shapes[] = {
    new Square(4),
    new Triangle(6,8),
    new Square(9),
    new Triangle(1,3)
    };

    for (int i = 0; i < 4; i++) {
        cout << "Shape "<< i << ": " << shapes[i]->area() << endl;
    }
}

//INHERITANCE

class Hooman {
protected:
    string Name;
    int Age;
    string Job;
    double Height;
public:
    Hooman(string name, int age, string job, double height) {
        this->Name = name;
        this-> Age = age;
        this->Job = job;
        this->Height = height;
    }
    void func() {
        cout << Name << " " << Age << " " << Job << " " << Height << "\n";
    }
};

class SerialKiller:public Hooman {
private:
    unsigned KillCount;
public:
    SerialKiller(string name, int age, string job, double height, int killCount):
        Hooman(name,age,job,height) {
        this->KillCount = killCount;
    }
    void stab() {
        cout << Name << " stab stab " << KillCount << "\n";
    }
};

class Detective :public Hooman {
public:
    int SerialKillersCaught;
    Detective(string name, int age, string job, double height, int serialKillersCaught)
        :Hooman(name, age, job, height) {
        this->SerialKillersCaught = serialKillersCaught;
    };
};

void makeHoomans() {
    SerialKiller serialKiller1 = SerialKiller("Ed", 47, "Many", 1.70, 4);
    serialKiller1.func();
    serialKiller1.stab();
}

//POLYMORPHISM

class Animal {
protected:
    string Family;
    string Species;
    string Habitat;
public:
    Animal(string family, string species, string habitat) {
        this->Family = family;
        this->Species = species;
        this->Habitat = habitat;
    }
    void move() {
        cout << "I am a " << Species << " and I walk" << endl;
    }
};

class Seal:public Animal {
public:
    bool IsCute;
    Seal(string family, string species, string habitat, bool isCute)
        :Animal(family, species, habitat) {
        this->IsCute = isCute;
    }
    void move() {
        if (!IsCute)
            IsCute = true;
        cout << "I am a " << (IsCute ? " cute" : " not not cute ") << Species << " and I swim" << endl;
    }
};

class Owl :public Animal {
public:
    bool HasBigEyes;
    Owl(string family, string species, string habitat, bool hasBigEyes)
        :Animal(family, species, habitat) {
        this->HasBigEyes = hasBigEyes;
    }
    void move() {
        cout << "I am a " << Species << " and I fly" << "\n";
    }
};

void callAnimals() {
    Animal Racoon = Animal( "Animals with eye-masks","Raccon", "'Murica?");
    Racoon.move();
    Seal sealTeamSix = Seal("Chubby animals","Seals",  "Where it's cold", true);
    sealTeamSix.move();
    Owl owl = Owl("Animals with eye-masks","Owl",  "EVERYWHERE", true);
    owl.move();
}

int main() {
    callAnimals();
    return 0;
}

