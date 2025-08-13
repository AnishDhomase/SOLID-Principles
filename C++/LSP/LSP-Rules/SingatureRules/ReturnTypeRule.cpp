#include <iostream>
using namespace std;

// Return Type Rule : 
// Subtype overriden method return type should be either identical 
// or narrower then the parent method's return type.
// This is also called as return type covariance.
// C++ enforces this by covariance.

class Item {

};

class Eatable: public Item {
public:
    virtual Eatable* eat() = 0;
};

class Fruit : public Eatable {
public:
    Fruit* eat() override { 
        cout << "Eating Fruit" << endl;
    }
};
class Apple : public Fruit {
public:
    // Item* eat(Eatable *e) override { //Not allowed broader return
    //     cout << "Eating Fruit: Apple" << endl;
    // }
    Apple* eat() override { 
        cout << "Eating Fruit: Apple" << endl;
    }
};

int main(){
    Fruit *fruit = new Fruit();
    Apple *apple = new Apple();

    Eatable *output2 = fruit->eat();
    Eatable *output1 = apple->eat(); //Valid because eat in Apple return narrower value

    return 0;
}