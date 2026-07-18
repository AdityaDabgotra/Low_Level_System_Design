#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include "../Models/Order.h"
#include "../Models/Cart.h"
#include "../Models/Restaurant.h"
#include "../Strategies/PaymentStrategy.h"
#include<vector>
#include<string>
using namespace std;

class OrderFactory{
public:
    virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, PaymentStrategy* paymentStrategy,const vector<MenuItems>,const string& orderType) = 0;

    virtual ~OrderFactory() {}
};

#endif // ORDER_FACTORY_H