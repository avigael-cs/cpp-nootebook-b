#include <iostream>
#include <map>
#include "sources/Direction.hpp"
#include <vector>
#include <string>
#include <limits.h>
#include <map>

#define DEAFULT_CHAR '_'

using namespace std;
using namespace ariel;

namespace ariel
{
    const int line = 100;
    class Notebook{
        private:
            //our book (page,row, col - char)
            map<unsigned int, map<unsigned int, map<unsigned int,char >>> notebook;
            int maxRow = 0;
            //uint is a keyword that is used to declare a variable which can store an integral type of value (unsigned integer)
            int minRow = UINT_MAX;  
            int maxCol = 0;
            int minCol = UINT_MAX;


        public:
            Notebook();
            Notebook(int page, int row, int col);
            void write(int page, int row , int col, Direction dir , string msg);
            std::string read(int page, int row, int col, Direction dir, int num);
            void erase(int page, int row, int col, Direction dir, int len );
            void show(unsigned int page);
            
            
    };
}
