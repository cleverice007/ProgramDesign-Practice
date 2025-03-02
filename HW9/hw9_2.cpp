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


    // Operators
    friend ostream &operator<<(ostream &os, const Matrix &mat);
    friend istream &operator>>(istream &is, Matrix &mat);
    Matrix operator+(const Matrix &other) const; // addition

  

    // getter and setter

    double getElement(const vector2D &index) const {
        if (index.row < 0 || index.row >= size.row ||
            index.col < 0 || index.col >= size.col) {
            throw std::out_of_range("Index out of range in getElement()");
        }
        return data[index.row][index.col];
    }

    void setElement(const vector2D &index, double val) {
        if (index.row < 0 || index.row >= size.row ||
            index.col < 0 || index.col >= size.col) {
            throw std::out_of_range("Index out of range in setElement()");
        }
        data[index.row][index.col] = val;
    }
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

// Matrix assignment operator

Matrix &Matrix::operator=(const Matrix &m)
{
    this -> isNull = m.isNull;
    if(this -> isNull == false){
        for(int i=0;i<this->size.row;i++){
            delete[] this->data[i];
        }
        delete[] this->data;
    }

    this -> size = m.size;

    for(int i =0;i<this->size.row;i++){
        this->data[i] = new double[this->size.col];
    }

    for(int i=0;i<this->size.row;i++){
        for(int j=0;j<this->size.col;j++){
            this->data[i][j] = m.data[i][j];
        }
    }

    return *this;
}

// cout operator

ostream &operator<<(ostream &os, const Matrix &m)
{
    for(int i = 0; i < m.size.row; i++){
        for(int j = 0; j < m.size.col; j++){
          j == 0 ? os << m.data[i][j] : os << " " << m.data[i][j];
        }
        os << endl;  
    }
    return os;  
}

// cin operator

istream &operator>>(istream &is, Matrix &m)
{
    for(int i =0;i<m.size.row;i++){
        for(int j=0;j<m.size.col;j++){
            is >> m.data[i][j];
        }
    }
    return is;
}


// addition operator

Matrix Matrix::operator+(const Matrix &m) const
{
    if (this->size != m.size) {
        throw std::invalid_argument("Matrix size mismatch");
    }

    Matrix result(this->size);

    for (int i = 0; i < size.row; i++) {
        for (int j = 0; j < size.col; j++) {
            vector2D idx(i, j); 
            double sumVal = this->getElement(idx) + m.getElement(idx);
            result.setElement(idx, sumVal);
        }
    }

    return result;
}
