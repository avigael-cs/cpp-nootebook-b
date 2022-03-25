//avigael abitbol


#include <iostream>
#include "Notebook.hpp"
#include "sources/Direction.hpp"
#include <vector>
#include <string>
#include <stdexcept>
#include<cmath>

using namespace std;
using namespace ariel;

namespace ariel{

    //cunstructor
    Notebook::Notebook(){};


    /*
    page - represents wich page we want to write our text.
    row - represents wich line we want to write our text.
    col - represents col page we want to write our text.
    dir - is the direction of our text (horizontal/vertical)
    strint - represents the text we want to write.
    
    */
    void Notebook::write(int page, int row , int col, Direction dir , string msg){
        if(page < 0 || row < 0 || col < 0 || col > 100){
        throw std::invalid_argument("Bad Inputs - your page, row and col need to be positive and col need to be under 100"); 
         }
        //notebook[page].write(row, col, dir, msg);

        //Updates the board according to the message
        this->maxRow = max(this->maxRow, row);
        this->minRow = min(this->minRow, row);
        this->maxCol = max(this->maxCol, col);
        this->minCol = min(this->minCol, col);
     }

    std::string Notebook::read(int page, int row, int colum, Direction dir, int num){
         string str;
         return str;
     } 
    void Notebook::erase(int page, int row, int colum, Direction dir, int len ){
         return;
     }
    void Notebook:: show(unsigned int page){
        //here we pass over the row (line)
        for (int i = 0; i < row; i++)
        {
            // here we pass over the collumn
            for (int j = 0; j < col; j++)
            {
                if(notebook[i][j]!=0)
                    cout << notebook[i][j];
                else{
                cout<<'_';
                }
            }
            cout<<endl;
        }

    
    }
 }
