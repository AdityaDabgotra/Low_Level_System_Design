#ifndef MENUITEM_H
#define MENUITEM_H

#include<string>
using namespace std;

class MenuItem{
private:
    string code;
    string name;
    double price;

public:
    MenuItem(const string& code, const string& name, double price){
        this->code = code;
        this->name = name;
        this->price = price;
    }

    //getters and setters
    string getCode() const{
        return code;
    }

    void setCode(const string& code){
        this->code = code;
    }

    string getName() const{
        return name;
    }

    void setName(const string& name){
        this->name = name;
    }

    float getPrice() const{
        return price;
    }

    void setPrice(double price){
        this->price = price;
    }
};

#endif MENUITEM_H