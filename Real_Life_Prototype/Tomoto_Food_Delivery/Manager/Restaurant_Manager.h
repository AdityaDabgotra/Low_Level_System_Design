#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include<vector>
#include<string>
#include<algorithm>
#include "../Models/Restaurant.h"
using namespace std;

class RestaurantManager{
private:
    vector<Restaurant*> restaurants;
    static RestaurantManager* instance;

    RestaurantManager() {
        //private constructor to prevent instantiation
    }

public:
    static RestaurantManager* getInstance() {
        if (!instance) {
            instance = new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* restaurant) {
        restaurants.push_back(restaurant);
    }

    vector<Restaurant*> searchByLocation(const string& location) {
        vector<Restaurant*> result;
        transform(location.begin(), location.end(), location.begin(), ::tolower);

        for (auto restaurant : restaurants) {
            string r1 = restaurant->getLocation();
            transform(r1.begin(), r1.end(), r1.begin(), ::tolower);
            if (r1 == location) {
                result.push_back(restaurant);
            }
        }
        return result;
    }
};
RestaurantManager* RestaurantManager::instance = nullptr;

#endif // RESTAURANT_MANAGER_H