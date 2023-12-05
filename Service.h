#include <iostream>
#include <filesystem>
#include <string.h>
#include <fstream>
#include "LinkedList.cpp"
using namespace std;

class Service
{
    private:
        std::string ID;
        std::string Name;
        std::string Price;
    public:
        Service(const std::string& id, const std::string& n, const std::string& pr);

        void display() const;
        bool editData(const std::string& id, const std::string& newName, const std::string& newRange)
        template <typename T>
        void updateService(const std::string& filename, LinkedList<T>& list);
};