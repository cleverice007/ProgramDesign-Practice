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


// define matrix class

class Matrix {
private:
    vector2D size;
    double **data;
    bool isNull;

public:
    // constructor & destructor
    Matrix();
    Matrix(vector2D size);
    Matrix(const Matrix &m);
    ~Matrix();
}; 

// constructor
Matrix::Matrix() : size(0,0)
{
    this->isNull = true;
    this->data = nullptr;
}

Matrix::Matrix(vector2D size) : size(size),isNull(false)
{
    this->data = new double*[size.row];
    for(int i=0;i<size.row;i++){
        this->data[i] = new double[size.col];
    }
}

Matrix::Matrix(const Matrix &m) : size(m.size),isNull(m.isNull)
{
    this->data = new double*[size.row];
    for(int i=0;i<size.row;i++){
        this->data[i] = new double[size.col];
    }
    for(int i=0;i<size.row;i++){
        for(int j=0;j<size.col;j++){
            this->data[i][j] = m.data[i][j];
        }
    }
}

// destructor

Matrix::~Matrix()
{
    if(this->isNull == false){
        for(int i=0;i<this->size.row;i++){
            delete[] this->data[i];
        }
        delete[] this->data;
    }
}