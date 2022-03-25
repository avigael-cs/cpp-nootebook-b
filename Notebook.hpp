#include <iostream>
#include <map>
#include "sources/Direction.hpp"
#include <vector>
#include <string>
#include <map>


using namespace std;
namespace ariel
{
    const int line = 100;
    class Notebook{
        private:
            int maxRow = 0;
            //uint is a keyword that is used to declare a variable which can store an integral type of value (unsigned integer)
            uint minRow = UINT_MAX;  
            int maxCol = 0;
            uint minCol = UINT_MAX;


        public:
            Notebook();
            void write(int page, int line , int colum, Direction dir , string msg);
            std::string read(int page, int line, int colum, Direction dir, int num);
            void erase(int page, int line, int colum, Direction dir, int len );
            void show(int page);
            
            
    };
}
