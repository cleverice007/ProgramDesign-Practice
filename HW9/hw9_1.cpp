 #include <iostream>
#include <cstring>
using namespace std;

class MyString {

// private members and functions
private:
    static const int Length = 20;
    int len;
    char str[Length+1];
    void clear();


// public members and functions
public:
    MyString();
    MyString(char c[]);
    int length();
    int find(char ch, int index);
    void assign(const char st[]);
    void assign(MyString mStr);
    void print();
    char &operator[](int);

} ;

// constructor
MyString::MyString() {
    this->clear();
}

// constructor with parameter

MyString::MyString(char c[]) {
    this->clear();
    this->assign(c);
}


// member functions

void MyString::clear() {
    this->len = 0;
    for(int i =0; i< this->Length+1; i++) {
        this->str[i] = '\0';
    }
}

int MyString::length() {
    return this->len;
}


void MyString::assign(const char st[]) {
    this->len = (strlen(st) > this->Length ? this->Length : strlen(st));
    strncpy(this->str, st, this->len);
    this->str[this->len] = '\0';  
}

void MyString::assign(MyString mStr) {
    this->len = mStr.length();
    strncpy(this->str, mStr.str, this->len); 
    this->str[this->len] = '\0'; 
}

void MyString::print(){
    cout << this->str << endl;
}

int MyString::find(char ch, int index=0){
    int index = (index <0 ? 0:index);
    for(int i =index; i<this->len; i++){
        if(this->str[i] == ch){
            return i;
        }
    }
    return -1;
}

char &MyString::operator[](int index){
    return this->str[index];
}

const int VAR_CNT = 10;
const int VARNAME_LEN = 20;
const int ARGC_MAX = 10;
const int ARGV_LEN = 65536;
const int BUF_LEN = 65536;

// find the pointer using the variable name

MyString *nameToPtr(char *name, MyString var[], char varname[][VARNAME_LEN ], const int varcnt)
{
    for (int i = 0; i < varcnt; i++)
        if (strcmp(name, varname[i]) == 0)
            return var + i; 
    return nullptr;
}


// parsing argument

void digest(char *buf, int &argc, char argv[][ARGV_LEN]) {
    int pos = 0;    
    int idx = 0;   
    int len = strlen(buf);
    int isQuote = 0;

    for (int i = 0; i < len; i++) {
        if (isQuote) { 
            if (buf[i] == '\"') {  
                isQuote = 0;
                idx++;
                pos = 0; 
            } else {
                argv[idx][pos++] = buf[i]; 
            }
        } else { 
            if (buf[i] == '\"') { 
                isQuote = 1;
            } else if (buf[i] == ' ') {  
                if (pos > 0) { 
                    argv[idx][pos] = '\0'; 
                    idx++;
                    pos = 0;
                }
            } else {  
                argv[idx][pos++] = buf[i];
            }
        }
    }

    if (pos > 0) {
        argv[idx][pos] = '\0'; 
    }
    argc = idx + 1; 
}


int main(){
    // number of instuctions
    char buf[BUF_LEN] = {0};
    int n;

    
    char varname[VAR_CNT][VARNAME_LEN] = {0};
    MyString var[VAR_CNT + 5];
    int varcnt = 0;

    int argc = 0;
    char argv[ARGC_MAX][ARGV_LEN] = {0};


    while(n--){
        digest(buf, argc, argv);
       
        if (strcmp(argv[0], "declare") == 0){
            strcpy(varname[varcnt], argv[1]);
            var[varcnt].assign(argv[2]);
            varcnt++;
        }

        else if (strcmp(argv[0], "length") == 0)
        {
            cout << nameToPtr(argv[1], var, varname, varcnt)->length() << '\n';
        }

        else if (strcmp(argv[0], "find") == 0)
        {
            cout << nameToPtr(argv[1], var, varname, varcnt)->find(argv[2][0], atoi(argv[3])) << '\n';
        }
        else if (strcmp(argv[0], "assignString") == 0)
        {
            nameToPtr(argv[1], var, varname, varcnt)->assign(argv[2]);
        }
        else if (strcmp(argv[0], "assignObject") == 0)
        {
            nameToPtr(argv[1], var, varname, varcnt)->assign(*nameToPtr(argv[2], var, varname, varcnt));
        }
        else if (strcmp(argv[0], "print") == 0)
        {
            nameToPtr(argv[1], var, varname, varcnt)->print();
        }
    }
    return 0;
    }
