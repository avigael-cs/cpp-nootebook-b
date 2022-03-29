#include <iostream>
#include <map>
#include "Direction.hpp"
#include <unordered_map>
#include <vector>
#include <string>
#include <limits.h>
#include <map>

#define DEFAULT_CHAR '_'
#define ERASE_CHAR '~'


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
            unordered_map< int, unordered_map< int, char[100]>> notebook;
            


        public:
            Notebook();
            void arg_check(int page, int row, int column, int num, ariel::Direction dir);
            Notebook(int page, int row, int col);
            void write(int page, int row , int col, Direction dir ,  string const &msg);
            std::string read(int page, int row, int col, Direction dir, int num);
            void erase(int page, int row, int col, Direction dir, int num );
            void show(int page);
            
            
    };
}
