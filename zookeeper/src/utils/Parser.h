#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

std::vector<std::vector<std::string>> parseFile(const std::string& filename);
std::string splitString(const std::string& str, char delimiter, int index);
std::vector<std::vector<std::string>> parseAnimalNames(const std::string& filename);

#endif // PARSER_H