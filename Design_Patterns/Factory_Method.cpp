#include<iostream>

using namespace std;

// Product class and Subclass
class Burger{
public:
    virtual void prepare() = 0;     // Pure Virtual Function
    virtual ~Burger(){}             // Virtual Destructor
};

class BasicBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing Basic Burger with bun,patty and ketchup! ";
    }
};

class StandardBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing Standard burger with bun,patty,cheese and lettuce! ";
    }
};

class PremiumBurger : public Burger{
public:
    void prepare()override{
        cout<<"Preparing Premium burger with gourmet bun,premium patty,cheese, lettuce and secret sauce ! ";
    }
};

class BasicWheatBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing Basic Wheat Burger with bun,patty and ketchup! ";
    }
};

class StandardWheatBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing Standard Wheat burger with bun,patty,cheese and lettuce! ";
    }
};

class PremiumWheatBurger : public Burger{
public:
    void prepare()override{
        cout<<"Preparing Premium Wheat burger with gourmet bun,premium patty,cheese, lettuce and secret sauce ! ";
    }
};

class BurgerFactory{
public:
    virtual Burger* createBurger(string& type) = 0;
};

class singhBurger : public BurgerFactory{
public:
    Burger* createBurger(string& type) override{
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard"){
            return new StandardBurger();
        }
        else if(type == "premium"){
            return new PremiumBurger();
        }
        else{
            cout<<"Invalid Burger Type! "<<endl;
            return nullptr;
        }
    }
};

class kingBurger : public BurgerFactory{
public:
    Burger* createBurger(string& type) override{
        if(type == "basic"){
            return new BasicWheatBurger();
        }
        else if(type == "standard"){
            return new StandardWheatBurger();
        }
        else if(type == "premium"){
            return new PremiumWheatBurger();
        }
        else{
            cout<<"Invalid Burger Type! "<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "standard";

    BurgerFactory* myBurgerFactory = new kingBurger();

    Burger* burger = myBurgerFactory->createBurger(type);

    burger->prepare();

    return 0;
}