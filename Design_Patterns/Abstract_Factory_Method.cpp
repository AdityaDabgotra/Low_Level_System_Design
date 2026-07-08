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
        cout<<"Preparing Basic Burger with bun, patty and ketchup! "<<endl;
    }
};

class StandardBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing Standard burger with bun,patty,cheese and lettuce! "<<endl;
    }
};

class PremiumBurger : public Burger{
public:
    void prepare()override{
        cout<<"Preparing Premium burger with gourmet bun, premium patty, cheese, lettuce and secret sauce ! "<<endl;
    }
};

class BasicWheatBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing Basic Wheat Burger with bun, patty and ketchup! "<<endl;
    }
};

class StandardWheatBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing Standard Wheat burger with bun, patty, cheese and lettuce! "<<endl;
    }
};

class PremiumWheatBurger : public Burger{
public:
    void prepare()override{
        cout<<"Preparing Premium Wheat burger with gourmet bun, premium patty, cheese, lettuce and secret sauce ! "<<endl;
    }
};

// Product class and Subclass
class GarlicBread{
public:
    virtual void prepare() = 0;     // Pure Virtual Function
    virtual ~GarlicBread(){}             // Virtual Destructor
};

class BasicGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Basic GarlicBread with bun, patty and ketchup! "<<endl;
    }
};

class StandardGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Standard GarlicBread with bun,patty,cheese and lettuce! "<<endl;
    }
};

class PremiumGarlicBread : public GarlicBread{
public:
    void prepare()override{
        cout<<"Preparing Premium GarlicBread with gourmet bun, premium patty, cheese, lettuce and secret sauce ! "<<endl;
    }
};

class BasicWheatGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Basic Wheat GarlicBread with bun, patty and ketchup! "<<endl;
    }
};

class StandardWheatGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing Standard Wheat GarlicBread with bun, patty, cheese and lettuce! "<<endl;
    }
};

class PremiumWheatGarlicBread : public GarlicBread{
public:
    void prepare()override{
        cout<<"Preparing Premium Wheat GarlicBread with gourmet bun, premium patty, cheese, lettuce and secret sauce ! "<<endl;
    }
};

class MealFactory{
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class singhBurger : public MealFactory{
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

    GarlicBread* createGarlicBread(string& type) override{
        if(type == "basic"){
            return new BasicGarlicBread();
        }
        else if(type == "standard"){
            return new StandardGarlicBread();
        }
        else if(type == "premium"){
            return new PremiumGarlicBread();
        }
        else{
            cout<<"Invalid GarlicBread Type! "<<endl;
            return nullptr;
        }
    }
};

class kingBurger : public MealFactory{
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

    GarlicBread* createGarlicBread(string& type) override{
        if(type == "basic"){
            return new BasicWheatGarlicBread();
        }
        else if(type == "standard"){
            return new StandardWheatGarlicBread();
        }
        else if(type == "premium"){
            return new PremiumWheatGarlicBread();
        }
        else{
            cout<<"Invalid GarlicBread Type! "<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "standard";

    MealFactory* myFactory = new kingBurger();

    Burger* burger = myFactory->createBurger(type);
    GarlicBread* GarlicBread = myFactory->createGarlicBread(type);

    burger->prepare();
    GarlicBread->prepare();

    return 0;
}