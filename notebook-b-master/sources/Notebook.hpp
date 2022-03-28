#include <iostream>
#include <map>
#include "Direction.hpp"
#include <unordered_map>
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
            

            /*unordered_map when 
            *You need to keep count of some data (Example – strings) and no ordering is required.
            *You need single element access i.e. no traversal.
            */
           //our book (page,row, col = char)
            unordered_map<unsigned int, unordered_map<unsigned int, unordered_map<unsigned int, char>>> notebook;
            int maxRow = 0;
            //uint is a keyword that is used to declare a variable which can store an integral type of value (unsigned integer)
            int minRow = UINT_MAX;  
            int maxCol = 0;
            int minCol = UINT_MAX;


        public:
            Notebook();
            Notebook(int page, int row, int col);
            void write(int page, int row , int col, Direction dir ,  string const &msg);
            std::string read(int page, int row, int col, Direction dir, int num);
            void erase(int page, int row, int col, Direction dir, int len );
            void show(unsigned int page);
            
            
    };
}
