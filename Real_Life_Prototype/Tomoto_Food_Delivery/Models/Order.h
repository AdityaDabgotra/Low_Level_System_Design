#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include<vector>
#include<string>
#include"Users.h"
#include"Restaurant.h"
#include"MenuItem.h"
#include"../Strategies/PaymentStrategy.h"
#include"../utils/TimeUtils.h"
using namespace std;

class Order{
protected:
    static int nextorderId;
    int orderId;
    User* user;
    Restaurant* restaurant;
    vector<MenuItem*> items;
    PaymentStrategy* paymentStrategy;
    double totalPrice;
    string scheduled;

public:
    Order(){
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        totalPrice = 0.0;
        scheduled = "";
        orderId = ++nextorderId;
    }

    virtual ~Order(){
        delete paymentStrategy;
    }

    bool processPayment(){
        if(paymentStrategy){
            paymentStrategy->pay(totalPrice);
            return true;
        }
        else{
            cout<<"Please choose a payment method."<<endl;
            return false;
        }
    }

    virtual string getType() const = 0;

    //getters and setters
    int getOrderId() const{
        return orderId;
    }

    void setUser(User* u){
        user = u;
    }

    User* getUser() const{
        return user;
    }

    void setRestaurant(Restaurant* r){
        restaurant = r;
    }

    Restaurant* getRestaurant() const{
        return restaurant;
    }

    void setItems(const vector<MenuItem*>& its){
        items = its;
        totalPrice = 0;
        for(auto &i : items){
            totalPrice += i->getPrice();
        }
    }

    const vector<MenuItem*>& getItems() const{
        return items;
    }

    void setPaymentStrategy(PaymentStrategy* ps){
        paymentStrategy = ps;
    }

    void setScheduled(const string& s) {
        scheduled = s;
    }

    string getScheduled() const {
        return scheduled;
    }

    double getTotal() const {
        return totalPrice;
    }

    void setTotal(int total) {
        this->totalPrice = total;
    }
};

int Order::nextorderId = 0;

#endif // ORDER_H