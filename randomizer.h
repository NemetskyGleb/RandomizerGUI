#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <tuple>

typedef std::vector<std::string> vstring;
typedef std::unordered_set<int> uset;
typedef std::tuple<std::string, std::vector<int> > tuple; 


/**
 * @brief 
 * Класс для рандома случайных чисел диапозона от 1 до max_number
 * Распределение происходит по объектам, кол-во чисел на объект задаётся 
 * переменной numbers_per_object 
 */
class Randomizer {
private:
    uint number_of_objects;
    uint min_number;
    uint max_number;
    uint numbers_per_object;
    tuple *tuple_array = nullptr;
    std::vector<int> *vector_array = nullptr;
public:
    Randomizer() : number_of_objects(0), min_number(0), max_number(0), numbers_per_object(0) {}
    Randomizer(vstring& obj, uint num_obj = 0, uint min_numb = 0, uint max_num = 0, uint numb_per_obj = 1);
    std::string& getFirst(int pos);
    std::vector<int>& getSecond(int pos);
    // Randomizer(const Randomizer& r);
    // Randomizer& operator=(const Randomizer& r);
    void Print();
    ~Randomizer();
};


#endif
