//
// Created by Mark Edmunds on 3/9/25.
//

#ifndef BEAR_H
#define BEAR_H
#include "Animal.h"
#include <string>

using namespace std;

namespace animal {

class Bear : public Animal{
    // Inheriting constructor from Animal
    static std::string names[10];
public:
    // Constructor
    Bear(const std::string &id,const std::string &name, int age, int weight, const std::string &species, const std::string &origin,
         const std::string &birthSeason, const std::string &color);

    // Method
    void hibernate();
    static std::string generateName();
};

} // animal

#endif //BEAR_H
