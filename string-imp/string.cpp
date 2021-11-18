#include "string.h"

int String::stoi(){
    if(this->buffer[0]< '0'|| this->buffer[0] > '9'&& this->buffer[0]!='-'){
        std::cout << "invalid argument";
        std::exit(0);
    }
    int result = 0;
    for(int i = 0; i < this->size;++i){
        if(this->buffer[i]>='0'&& this->buffer[i]<='9')
        result = result*10 + this->buffer[i]-'0';
    }
    return result;
}
String String::substr(int start, int finish){
    String tmp;
    int j = 0;
    for(int i = start; i < finish+start;++i){
        tmp[j++] = this->buffer[i];
    }
    return tmp;
}
void String::replace(int index, char* arr){
    int count = 0;
    while (arr[count] !='\0')
    {
        ++count;
    }
    int tSize = this->size+count+1;
    char* t = new char[tSize];
    for(int i = 0; i < index;++i){
        t[i] = this->buffer[i];
    }
    int j = 0;
    for(int i = index; i < index+1+count;++i){
        t[i] = arr[j];
        ++j;
    }
    j = index;
    for(int i = index+count; i < tSize;++i){
        t[i] = this->buffer[j++];
    }
    delete [] this->buffer;
    this->buffer = t;
    this->size = tSize;
    this->buffer[size] = '\0';
    t = nullptr;
}
void String::replace(char ch, int index){
    this->buffer[index] = ch;
}
bool String::empty(){
    return this->size ==0 ? true : false;
}
void String::clear(){
    delete [] this->buffer;
    this->buffer = nullptr;
    this->size = 0;
}
void String::insert(const int index, const int count,char ch){
    int tSize = this->size+count+1;
    char * t = new char[tSize];
    
    for(int i = 0; i < index;++i){
        t[i] = this->buffer[i];
    }
    int newIndex = index;
    int newCount = count;
    while (newCount)
    {
        t[newIndex] = ch;
        --newCount;
        ++newIndex;    
    }
    newCount = index+1;
    for(int i = count+index; i < tSize;++i){
        t[i] = this->buffer[newCount];
        ++newCount;
    }
    delete [] this->buffer;
    this->buffer = t;
    t = nullptr;
    this->size= tSize;
}
void String::insert(const int index, char ch ){
    char * t = new char[this->size+2];
    for(int i = 0; i < index;++i){
        t[i] = this->buffer[i];
    }
    t[index] = ch;
    for(int i = index+1; i < this->size;++i){
        t[i] = this->buffer[i];
    }
    delete [] this->buffer;
    this->buffer = t;
    t = nullptr;
    this->buffer[size] = '\0';
    this->size+=1;
}
String::String(){
    size = 0;
    buffer = new char[1];
    buffer[size] = '\0';
}
String::String(unsigned int reserve, char simbol){
    size = reserve;
    this->buffer = new char[reserve+1];
    for(int i = 0; i < reserve; ++i){
        buffer[i] = simbol;
    }
    buffer[size] = '\0';
}
String::String(const char* tmp){
    int count = 0;
    while (tmp[count] !='\0')
    {
        ++count;
    }
    this->size = count;
    this->buffer = new char[count+1];
    
    for(int i = 0; i < size;++i){
        this->buffer[i] = tmp[i];
    }
    buffer[size] = '\0';
    
}

String::String(const String& tmp){
        this->size = tmp.size;
        this->buffer = new char[size+1];
        for(int i = 0; i < size; ++i){
            buffer[i] = tmp.buffer[i];
        }
        buffer[size] = '\0';
}
String::String(String&& tmp){
    this->size = tmp.size;
    this->buffer = tmp.buffer;
     tmp.buffer = nullptr;
     tmp.size = 0;
}
String::~String(){
    delete [] this->buffer;
    size = 0;
    buffer = nullptr;
}
char& String::operator[](unsigned int index) {
    return this->buffer[index];
}
const char& String::operator[](unsigned int index)const{
    return this->buffer[index];
}
const char& String::at(const unsigned int index) const {
    if(this->size <= index){
        std::cout << "Segmentation fault";
        std::exit(0);
    }else{
        return this->buffer[index];
    }
}
 std::ostream& operator<<(std::ostream&os,String&tmp){
         os << tmp.buffer;
         return os;
 }

std::istream& operator>>(std::istream&is,String&tmp){
    is >> tmp;
    return is;
}
String& String::operator=(const String& obj) {
    if(this == &obj){
        return *this;
    }else{
        delete [] this->buffer;
        this->size = obj.size;
        this->buffer = new char[size];
        for(int i = 0; i <= this->size;++i){
            this->buffer[i] = obj.buffer[i];
        }
        this->buffer[size] = '\0';
        return *this;
    }
}
String& String::operator=(String&& obj){
      this->buffer = obj.buffer;
      this->size = obj.size;
      obj.buffer = nullptr;
      return *this;
}
String String::operator+( const String rhs) const{

    String tmp ;
    char * t = new char[this->size + rhs.size - 1] ;
    int g = 0 ;
    for(; g < this->size ; ++g) {
        t[g] = this->buffer[g] ;
    }
    for(int i = 0; i < rhs.size ; ++i , ++g) {
        t[g] = rhs.buffer[i] ;
    }

    tmp.size = this->size + rhs.size  ;
    tmp.buffer = t;
    t = nullptr ;
    return tmp ;
}
String& String::operator+=(char ch){
    char* tmp = new char[this->size+1];
    for(int i = 0; i < this->size;++i){
        tmp[i] = this->buffer[i];
    }
    tmp[this->size] = ch;
    delete [] this->buffer;
    this->buffer = tmp;
    this->size = size+1;
    return *this;
}
bool String::operator>(const String& rhs)const{
    if(this->size > rhs.size){
        return true;
    }else{
        return false;
    }
}
bool String::operator<(const String& rhs)const{
     if(this->size < rhs.size){
        return true;
    }else{
        return false;
    }
}
bool String::operator==(const String& rhs)const{
    if(this->size!=rhs.size){
        return false;
    }else{
        for(int i = 0; i < this->size;++i){
            if(this->buffer[i]!= rhs.buffer[i]){
                return false;
            }
        }
    }
    return true;
}
bool String::operator!=(const String&rhs)const{
       if(this->size!=rhs.size){
        return true;
    }else{
        for(int i = 0; i < this->size;++i){
            if(this->buffer[i]!= rhs.buffer[i]){
                return true;
            }
        }
    }
    return false;
}
bool String::operator>=(const String& rhs)const{
    if(this->size < rhs.size){
        return false;
    }else{
        return true;
    }
}
bool String::operator<=(const String& rhs)const{
    if(this->size > rhs.size){
        return false;
    }else{
        return true;
    }
}
void String::push_back(char simbol){
    this->operator+=(simbol);
}
char String::pop_back(){
    this->size = this->size-1;
    return this->buffer[size];
}
void String::push_front(char ch){
    char* t = new char[this->size+1];
    t[0] = ch;
    for(int i = 1; i <= this->size;++i){
        t[i] = this->buffer[i-1];
    }
    delete [] this->buffer;
    this->buffer = t;
    this->size = this->size+1;
    t = nullptr;
}
void String::resize(const int size,char ch){
    for(int i = 0; i < size;++i){
        this->push_back(ch);
    }
}
int String::find(const char ch){
    for(int i = 0; i < this->size;++i){
        if(this->buffer[i]== ch){
            return i;
        }
    }
    return -1;
}
int String::find(const String& rhs){
     int arr[rhs.size] {};
     for(int i = 0; i < rhs.size;++i){
         arr[i] = this->find(rhs[i]);
     }
     int sum = 0;
     for(int i = 0; i < rhs.size-1;++i){
         sum = arr[i+1]-arr[i];
         if(sum != 1){
             return -1;
         }
     }
     return arr[0];
}

int main(){
    String s1("1997");
    String s3("Karen Grigoryan Daviti");
    String s("are");
    String s5("k");
    char* arr = "karen";
    //s3.push_front('k'); 
    //std::cout << s3;
    //s1.resize(5,'m');
    //std::cout << s1.find(s);
    //String tmp =  s3.substr(6,9);
    std::cout << s1.stoi();
    //std::cout << s1; 

    return 0;
}