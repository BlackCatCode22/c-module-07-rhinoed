//
// Created by Mark Edmunds on 3/9/25.
//

#ifndef TIGER_H
#define TIGER_H
#include <string>
#include "Animal.h"
namespace animal {

class Tiger : public Animal {
    // Tiger names
    static std::string names[10];
public:
    // Constructor
    Tiger(const std::string &id,const std::string &name, int age, int weight, const std::string &species, const std::string &origin,
          const std::string &birthSeason, const std::string &color);

    // Method
    void countStripes();
    static std::string generateName();
};

} // animal

#endif //TIGER_H
