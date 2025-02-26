#include <iostream>
#include <cstring>
#include <string>
#include <exception>
#include <stdexcept>
using namespace std;


// global function

bool isDigit(char c){
    return (c >= '0' && c <= '9');
}

bool isLowerCase(char c){
    return(c >= 'a' && c <= 'z');
}

int findOperator(string s){
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i]== '+'||s[i]=='-'){
            return i;
        }
    }
    return -1;
}

int findAlphabet(string s){
    int len = s.length();
    for(int i=0;i<len;i++){
        if(isalpha(s[i])){
            return i;
        }
    }
    return -1;
}


 // define vector2D, to define size of matrix

typedef struct vector2D{
    int row;
    int col;

    // constructor

    vector2D(){
        this->row = 0;
        this->col = 0;
    }

    vector2D(int row, int col){
        this->row = row;
        this->col = col;
    }

  vector2D(const vector2D &v) {
    this->row = v.row;
    this->col = v.col;
}

    bool operator == (const vector2D &v) const {
        return (this->row == v.row && this->col == v.col);
    }

    bool operator != (const vector2D &v) const {
        return (this->row != v.row || this->col != v.col);
    }


} vector2D; 