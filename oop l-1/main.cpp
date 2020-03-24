#include <iostream>
#include <string>
using namespace std;
class Animal
{
private:
    string name;
    int age = { 0 };
    int value;
public:
    void rename (string newName);
    string getName ();
    void setAge (int newAge);
    void setPrice (int price);
    int getAge ();
    int getPrice ();

};


void Animal::rename (string newName)
{
    name = newName;
}

string Animal::getName ()
{
    return name;
}

void Animal::setAge (int newAge)
{
    if (newAge > 0)
        age = newAge;
}

void Animal::setPrice (int price)
{
    if (price > 0)
        value = price;
}

int Animal::getPrice ()
{
    return value;
}

int Animal::getAge ()
{
    return age;
}

//Bird
class Bird:public Animal
{
public:
    static void sing ();
private:

};
void
Bird::sing ()
{
    cout << "skrra pa pa" << endl;
}

//Dog
class Dog:public Animal
{
public:
    static void bark ();
};
void Dog::bark ()
{
    cout << "Bark!" << endl;
}

//Cat
class Cat:public Animal
{
public:
    static void meow ();
};
void Cat::meow ()
{
    cout << "Meow!" << endl;
}

class Bank
{
private:
    int initialBalance;
    string animals[256];
    int agge[3] = { 0 };
    int depo;
    int act;
    int coins;
    int with;
public:
    void menu (void);
    void get (void);
    void deposite (void);
    void check (void);
    void showAnimal (void);
    void buyAnAnimal (void);
    void earn (void);
    Bank();
};

Bank::Bank() {
    act = 50;
    initialBalance = 100;
    coins = 25;
}
void Bank::earn() {
    int bet;
    int go;
    cout << "\t\t\t\t\tYour current balance: " << initialBalance  << " coins" << endl;
    if(agge[0] >= 1) {
        coins+=5;
    }
    cout << "\t\t\t\t\tHow many coins do you want to put??(from 1 - " << coins << " )" << endl;
    cin >> bet;
    if(bet > coins) {

        cout << "\t\t\t\tToo much" << endl;
        cout << "\t\t\t\tYou can put more coins if you buy any animal" << endl;
        cout << endl;
        earn();
    } else {
        int usrResult;
        if (bet > initialBalance) {
            cout << "You don\'t have enough money." << endl;
        } else {

            int randomNumber = (rand() % 3) + 1;;

            if (randomNumber == 1) {
                int n = (rand() % 40) + 1;
                int s = (rand() % 30) + 1;
                cout << n << " + " << s << "=" << endl;
                cin >> usrResult;
                if (usrResult == n + s) {
                    cout << "You won " << endl;
                    initialBalance += bet;
                } else {
                    cout << "You lose " << bet << " $" << endl;
                    initialBalance -= bet;
                }
            } else if (randomNumber == 2) {
                int n = (rand() % 20) + 1;
                int s = (rand() % 10) + 1;
                cout << n << " * " << s << "=" << endl;
                cin >> usrResult;
//            cout << usrResult << " " << n*s << endl;
                if (usrResult == n * s) {
                    cout << "You won " << endl;
                    initialBalance += bet;
                } else {
                    cout << "You lose " << bet << " $" << endl;
                    initialBalance -= bet;
                }
            } else if (randomNumber == 3) {
                int n = (rand() % 10) + 1;
                int s = (rand() % 15) + 1;
                cout << n << " * " << s << " * 2 " << "=" << endl;
                cin >> usrResult;
                if (usrResult == n * s * 2) {
                    cout << "You won " << endl;
                    initialBalance += bet;
                } else {
                    cout << "You lose " << bet << " $" << endl;
                    initialBalance -= bet;
                }
            }
        }
    }

    int a;
    cout << "\t\t\t\t\t\tAgain?" << endl;
    cout << "\t\t\t\t\t\tEnter 1(Yes) or 0(No)" << endl;
    cin >> a;
    if(a==1) {
        earn();
    } else {
        menu();
    }
    cout << endl;
}

void
Bank::showAnimal ()
{
    int w;
    Bird b;
    b.rename ("Andy");
    b.setAge (1);
    b.setPrice (110);
    Dog d;
    d.rename ("Karl");
    d.setAge (5);
    d.setPrice (250);
    Cat c;
    c.rename ("Mary");
    c.setAge (3);
    c.setPrice (300);
    cout << "\t\t\t\t\tPress \'0\' to return to the Main Menu: " << endl;
    cout << "\t\t\t\t\tChoose animal you want to see:" << endl;
    cout << "\t\t\t\t\t\t1.Bird - " << b.getPrice () << " coins"<< "\n";
    cout << "\t\t\t\t\t\t2.Dog - " << d.getPrice () << " coins"<< "\n";
    cout << "\t\t\t\t\t\t3.Cat - " << c.getPrice () << " coins"<< "\n";
    cin >> w;
    int r;
    if(agge[0] < 1) {
        switch (w) {
            case 1:
                cout << "\t\t\t\t\t\t";
                cout << "Description: ";b.sing();
                cout << "\t\t\t\t\t\tName: " << b.getName() << endl;
                cout << "\t\t\t\t\t\tAge: " << b.getAge() << endl;
                cout << "\t\t\t\t\t\tPrice: " << b.getPrice() << " coins" << endl;
                cout << "\n\t\t\t\t\t\tDo you want to buy it? (You can only have one animal.)" << endl;
                cout << "\t\t\t\t\t\tEnter 1(Yes) or 0(No)" << endl;
                cin >> r;
                if (r == 1 and initialBalance >= b.getPrice()) {
                    initialBalance -= b.getPrice();
                    string name = b.getName();
                    int age = b.getAge();
                    animals[0] = name;
                    agge[0] = age;

                } else if (initialBalance >= b.getPrice() || r != 0) {
                    cout << "\t\t\t\t\t\tYou need " << b.getPrice() -
                                                       initialBalance << " more coins to buy it" << endl;
                }
                break;
            case 2:
                cout << "\t\t\t\t\t\t";
                cout << "Description: ";d.bark();
                cout << "\t\t\t\t\t\tName: " << d.getName() << endl;
                cout << "\t\t\t\t\t\tAge: " << d.getAge() << endl;
                cout << "\t\t\t\t\t\tPrice: " << d.getPrice() << " coins"<< endl;
                cout << "\n\t\t\t\t\t\tDo you want to buy it? (You can only have one animal.)" << endl;
                cout << "\t\t\t\t\t\tEnter 1(Yes) or 0(No)" << endl;
                cin >> r;
                if (r == 1 and initialBalance >= d.getPrice()) {
                    initialBalance -= d.getPrice();
                    string name = d.getName();
                    int age = d.getAge();
                    animals[0] = name;
                    agge[0] = age;

                } else if (initialBalance >= d.getPrice() || r != 0) {
                    cout << "\t\t\t\t\t\tYou need " << d.getPrice() -
                                                       initialBalance << " more coins to buy it" << endl;
                }
                break;
            case 3:
                cout << "\t\t\t\t\t\t";
                cout << "Description: ";c.meow();
                cout << "\t\t\t\t\t\tName: " << c.getName() << endl;
                cout << "\t\t\t\t\t\tAge: " << c.getAge() << endl;
                cout << "\t\t\t\t\t\tPrice: $" << c.getPrice() << " coins"<< endl;
                cout << "\n\t\t\t\t\t\tDo you want to buy it? (You can only have one animal.)" << endl;
                cout << "\t\t\t\t\t\tEnter 1(Yes) or 0(No)" << endl;
                cin >> r;

                if (r == 1) {
                    initialBalance -= c.getPrice();
                    string name = c.getName();
                    int age = c.getAge();
                    animals[0] = name;
                    agge[0] = age;

                } else if (initialBalance >= c.getPrice() || r != 0) {
                    cout << "\t\t\t\t\t\tYou need coins " << c.getPrice() -
                                                         initialBalance << " more." << endl;

                }
                break;
        }
    } else {
        cout << "\nYou cannot buy another animal since you already have one." << endl;
    }

    cout << "\t\t\t\t\tPress \'0\' to return to the Main Menu: " << endl;
    int go;
    cin >> go;
    if (go == 0)
    {
        menu ();
    }
}
void
Bank::menu ()
{
    int me;
    cout << "\t\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t\tChoose your Option from 1-5\n";
    cout << "\t\t\t\t\t1.Info\n";
    cout << "\t\t\t\t\t2.Deposite\n";
    cout << "\t\t\t\t\t3.Check your Balance\n";
    cout << "\t\t\t\t\t4.Show all Animals\n";
    cout << "\t\t\t\t\t5.Earn coins\n";
    cout << "\t\t\t\t\t6.Exit\n";
    cout << "\t\t\t\t\t---------------------------" << endl;
    cin >> me;
    switch (me)
    {
        case 1:
            get ();
            break;
        case 2:
            deposite ();
            break;
        case 3:
            check ();
            break;
        case 4:
            showAnimal ();
            break;
        case 5:
            earn ();
            break;
    }
    cout << "\t\t\t\t\tPress \'0\' to return to the Main Menu: " << endl;
}

void
Bank::get ()
{
    int go;
    int r;

    cout << "\t\t\t\t\tYou  have " << initialBalance << " coins." << endl;
    for (int i = 0; i < 3; i++)
    {
        if (agge[i] == 0)
        {
            cout << "\t\t\t\t\tYou have no animal.." << endl;
            break;
        }
        else
        {
            cout << "\t\t\t\t\tThis is your animal" << endl;
            cout << endl;
            cout << "\t\t\t\t\tName: " << animals[0] << endl;
            cout << "\t\t\t\t\tAge: " << agge[0] << endl;
            cout << endl;
            break;
        }
    }
    cout << "\t\t\t\t\tPress \'0\' to return to the Main Menu: " << endl;
    cin >> go;
    if (go == 0)
    {
        menu ();
    }
    cout << endl;
}

void
Bank::deposite ()
{
    int go;
    cout << "\t\t\t\t\tYou can deposite only " << act  << " coins!!!" << endl;
    cout << "\t\t\t\t\tEnter: ";
    cin >> depo;
    if(depo > act) {
        cout << "\t\t\t\t\tToo much" << endl;
        deposite();
    } else{
        act -= depo;
        initialBalance += depo;
    }
    cout << "\t\t\t\t\tPress \'0\' to return to the Main Menu: " << endl;
    cin >> go;
    if (go == 0)
    {
        menu ();
    }
}

void
Bank::check ()
{
    cout << "\t\t\t\t\tYour current balance: " << initialBalance << endl;
    menu ();
    cout << endl;
}

int
main ()
{
    Bank obj;
    obj.menu ();
    return 0;
}
