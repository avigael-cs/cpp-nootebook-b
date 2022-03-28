//avigael abitbol


#include <iostream>
#include "Notebook.hpp"
#include "Direction.hpp"
#include <vector>
#include <string>
#include <stdexcept>
#include<cmath>

using namespace std;
using namespace ariel;

namespace ariel{

    // //cunstructor - initialize the note book
    // Notebook::Notebook(int page, int row, int col){
    //     for(unsigned int i = 0; i<page; i++){
    //         for(unsigned int j = 0; j<row; j++){
    //             for(unsigned int k = 0; k<col; k++){
    //                //notebook.insert<page<row<col,DEAFULT_CHAR>>>;
    //                notebook[page][row][col]=DEAFULT_CHAR;
    //             }
    //         }
    //     }
    // }


    /*
    page - represents wich page we want to write our text.
    row - represents wich line we want to write our text.
    col - represents col page we want to write our text.
    dir - is the direction of our text (horizontal/vertical)
    strint - represents the text we want to write.
    
    */
    void Notebook::write(int page, int row , int col, Direction dir ,  string const &msg){
        if(page < 0 || row < 0 || col < 0 || col > 100){
        throw std::invalid_argument("Bad Inputs - your page, row and col need to be positive and col need to be under 100"); 
         }
        //notebook[page].write(page, row, col, dir, msg);

        
        if (dir == Direction::Horizontal) {
            int tmp;
            tmp = msg.length();

            //end() – Returns an iterator to the theoretical element that follows the last element in the map.
            //map find()-Returns an iterator to the element with key-value ‘g’ in the map if found, else returns the iterator to end.
            if(this->notebook.find(page) == this->notebook.end())//if find = end it means we didnt found the page
            {
                //create page
                vector <char> vechar(100, '_');
                //this->notebook[page][row] = vechar;
                this->notebook[page][row] = vechar;
                
            } 
            //at() function is used to return the reference to the element associated with the key k.
            else if(this->notebook.at(page).find(row) == this->notebook.at(page).end()){ //check if row is in the map
                //then...create one
                vector <char> vechar(100, '_');
                this->notebook.at(page)[row] = vechar;
            }

            //check if we can write
            for(int i=0; i<tmp; i++){ 
                if(col+i>100)
                {
                    throw("Error - you can't write here");
                }

                if(this->notebook.at(page).at(row).at(col+i) != '_'|| this->notebook.at(page).at(row).at(col+i) != '~'){
                    throw("Error - already written/erased erea");
                }
                else{ //we can write
                    this->notebook.at(page).at(row).at(col+i) = msg.at(i);
                }
            }







            for (int j = 0, i = col; i < tmp; j++, i++) 
            {
                if (msg[j] == '~' || notebook[page][row][i] == '~') {
                    throw invalid_argument("message error");
                }
                if (notebook[page][row][i] == '_') {
                    notebook[page][row][i] = msg[j];
                } else {
                    throw invalid_argument("Position error");
                } 
            }
        }
        else{
            int tmp;
            tmp = row + msg.length();
            
        }



     }


    std::string Notebook::read(int page, int row, int col, Direction dir, int num){
        
        string str;
        int tmp;
        if(page < 0 || row < 0 || col < 0 || col > 100){
        throw std::invalid_argument("Bad Inputs - your page, row and col need to be positive and col need to be under 100"); 
         }
         if (dir==Direction::Horizontal)
            {
                tmp = col+num; //where we want to star reading.
            for (int i = col; i < tmp; i++)
                {
                str= str + this->notebook[page][row].at(i);
                }
            }
        else{ //dir = Vertical
            tmp = row+num; //where we want to star reading.
            for (int i = row; i < tmp; i++)
                {
                    str= str+ this->notebook[page][i].at(col);
                }
        }
        return str;
     } 


    void Notebook::erase(int page, int row, int col, Direction dir, int num ){
        if(page < 0 || row < 0 || col < 0 || col > 100){
            throw std::invalid_argument("Bad Inputs - your page, row and col need to be positive and col need to be under 100"); 
        }
        if (dir!=Direction::Horizontal || dir!=Direction::Vertical)
        {
            throw std::invalid_argument("Bad Inputs - Direction needs to be Horizonal or Vertical"); 
        }

        int tmp;
        if (dir==Direction::Horizontal)
            {
                tmp = col+num; //where we want to star reading.
            for (int i = col; i < tmp; i++)
                {
                this->notebook[page][row].at(i)=ERASE_CHAR;
                }
            }
        else{ //dir = Vertical
            tmp = row+num; //where we want to star reading.
            for (int i = row; i < tmp; i++)
                {
                    this->notebook[page][i].at(col)=ERASE_CHAR;
                }
        }
     }


    void Notebook:: show(unsigned int page){
        if(page<0){
        throw out_of_range("bad input - the Page need to be positive");
    }
        //here we pass over the row (line)
        for (unsigned int i = 0; i <= 99; i++) 
        {
            // here we pass over the collumn
            for (unsigned int j = 0; j <= 99; j++) 
            {
                if(notebook[page][i][j]!=0)
                    cout << notebook[page][i][j];
                else{
                cout<<'_';
                }
                
                cout << this->notebook[page][i][j];
            }
            cout << endl;
        }
    
    }
 }
