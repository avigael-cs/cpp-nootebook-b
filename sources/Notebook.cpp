//avigael abitbol


#include <iostream>
#include "Notebook.hpp"
#include "Direction.hpp"
#include <vector>
#include <string>
#include <stdexcept>
#include<cmath>

constexpr int mea =100;
constexpr char DEFAULT_C = '_';
constexpr char DEFAULT_D = '~';
using namespace std;
using namespace ariel;

namespace ariel{


    ariel::Notebook::Notebook() {}
    void check(int page, int row, int col, ariel::Direction dir, int num)
    {
        if(page < 0 || row < 0 || col < 0 || num < 0 || num>100||col>100){
            throw invalid_argument("Bad Inputs - your page, row and col need to be positive and col need to be smaller than 100."); 
         }
        
        if (dir!=Direction::Horizontal || dir!=Direction::Vertical)
        {
            throw invalid_argument("Bad Inputs - Direction needs to be Horizonal or Vertical"); 
        }
        int tmp;
        if (dir==Direction::Horizontal)
        {
            //if we write horizontal (where we are limited) in the middle of line and the text is grather than 100 - wrong
            if(col + num >= mea){
                throw invalid_argument("bad input - can't erase more than 100 char frow were you want to read to the end");
            }
        }
    }
    /*
    page - represents wich page we want to write our text.
    row - represents wich line we want to write our text.
    col - represents col page we want to write our text.
    dir - is the direction of our text (horizontal/vertical)
    strint - represents the text we want to write.
    
    */
    void Notebook::write(int page, int row , int col, Direction dir ,  string const &msg){
        int tmp;
        tmp = msg.length();
        check(page, row, col, dir, tmp);
        //notebook[page].write(page, row, col, dir, msg);
        if (dir == Direction::Horizontal) {          
            //end() – Returns an iterator to the theoretical element that follows the last element in the map.
            //map find()-Returns an iterator to the element with key-value ‘g’ in the map if found, else returns the iterator to end.           
            //if find = end it means we didnt found the page and we need to create one
            if(this->notebook.find(page) == this->notebook.end())
            {
                //create page
                vector <char> vchar(mea, DEFAULT_CHAR);
                unordered_map<int, vector<char>> r;
                r[row] = vchar;
                this->notebook[page] = r;
            } 
            //at() function is used to return the reference to the element associated with the key k.
            //check if row is in the map
            else if(this->notebook.at(page).find(row) == this->notebook.at(page).end()){ 
                //then...create one
                vector <char> vchar(mea, DEFAULT_CHAR);
                unordered_map<int, vector<char>> r;
                r[row] = vchar;
                this->notebook[page] = r;
            }
            //now - check if we can write
            for(size_t i=0; i<tmp; i++){ 
                if(this->notebook.at(page).at(row).at(col+i) != DEFAULT_CHAR|| this->notebook.at(page).at(row).at(col+i) == DEFAULT_D){
                    throw invalid_argument("Error - already written/erased erea");
                }
                //check if the char is takin <- between 33 and 126
                if((int)msg[i]<33 || (int)msg[i]>126)
                {
                    throw invalid_argument("Error - bad input");
                }

            }
            //if evrething is ok then we can write
            for(size_t i=0; i<tmp; i++){  //now - we can write
                this->notebook.at(page).at(row).at(col+i) = msg.at(i);
            }
        }
        else{ //direction = Vertical
            //check if page is not in the map
            if(this->notebook.find(page) == this->notebook.end()){ 
                //create page
                vector <char> vchar(mea, DEFAULT_C);
                unordered_map<int, vector<char>> r;
                r[row] = vchar;
                this->notebook[page] = r;
            }
            for(int i=0; i<tmp; i++){
                //now check if row is in the page - or if we have enough
                if(this->notebook.at(page).find(row + i) == this->notebook.at(page).end()){ 
                    //if we dont have enough - create
                    vector <char> vchar(mea, DEFAULT_C);
                    unordered_map<int, vector<char>> r;
                    r[row] = vchar;
                    this->notebook[page] = r;
                }
                //if we have a row check if we can write
                if(this->notebook.at(page).at(row+i).at(col) != DEFAULT_C|| this->notebook.at(page).at(row+i).at(col) == DEFAULT_D){
                    throw runtime_error("Error - already written/erased erea");
                }
            }
            //now - we can write
            for(int i=0; i<tmp; i++){  
                this->notebook.at(page).at(row+i).at(col) = msg.at(i);
            }
        }
    }


    std::string Notebook::read(int page, int row, int col, Direction dir, int num){
        string str;
        int tmp;
        check(page, row, col, dir, num);
        if (dir == Direction::Horizontal)
        {
            tmp = col+num; //where we want to star reading.           
            for(int i = col ; i < tmp; i++){
                //if the page doest exist
                if(this->notebook.find(page) == this->notebook.end()){
                    str += DEFAULT_C;
                }
                //if the row doest exist
                else if(this->notebook.at(page).find(row) == this->notebook.at(page).end()){
                    str += DEFAULT_C;
                }
                else{
                str += this->notebook[page][row].at(i);
                }
            }
        }
        //dir = Vertical
        else{ 
            tmp = row+num; //where we want to star reading.
            for(int i = row; i < tmp; i++){
                //if the page deosnt exist
                if(this->notebook.find(page) == this->notebook.end()) {
                    str += "_";
                }
                //if the row deosnt exist
                else if(this->notebook.at(page).find(row + i) == this->notebook.at(page).end()){
                    str += "_";
                }
                //if we can read
                else{
                    str += this->notebook.at(page).at(i).at(unsigned(col));
                    
                }
            }
        }
        return str;
    } 


    void Notebook::erase(int page, int row, int col, Direction dir, int num ){
        check(page, row, col, dir, num);
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


    void Notebook:: show(int page){
        if(page<=0){
            throw out_of_range("bad input - the Page need to be positive");
        }
        if(this->notebook.find(page) == this->notebook.end()){  
        cout<<"________\n________\n________\n________\n________\n________"<<endl;
    }
        //here we pass over the row (line)
        for (unsigned int i = 0; i <= 99; i++) 
        {
            // here we pass over the collumn
            for (unsigned int j = 0; j <= 99; j++) 
            {
                if(notebook[page][i][j]!= DEFAULT_C){
                    cout << notebook[page][i][j];
                }
                else{
                cout<<DEFAULT_CHAR;
                }
            }
            cout << endl;
        }
    
    }
 }
 
