#ifndef CART_H
#define CART_H

#include<iostream>
#include<vector>
#include<string>
#include"../Models/MenuItem.h"
#include"../Models/Restaurant.h"

using namespace std;

class Cart{
private:
    Restaurant* restaurant;
    vector<MenuItem> items;

public:
    Cart(){
        restaurant = nullptr;
    }

    void addItem(MenuItem& item){
        if(restaurant == nullptr){
            cerr<<"Cart: Set a restaurant before adding items."<<endl;
            return;
        }
        items.push_back(item);
    }

    double getTotalPrice(){
        double total = 0.0;
        for(auto& item : items){
            total += item.getPrice();
        }
        return total;
    }

    bool isEmpty(){
        return (!restaurant && items.empty());
    }

    void clearCart(){
        items.clear();
        restaurant = nullptr;
    }

    //getters and setters
    void setRestaurant(Restaurant* res){
        restaurant = res;
    }

    Restaurant* getRestaurant(){
        return restaurant;
    }

    const vector<MenuItem>& getItems() const{
        return items;
    }
};

#endif //CART_H