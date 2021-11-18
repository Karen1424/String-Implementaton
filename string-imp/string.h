#ifndef STRING_H
#define STRING_H
#include <iostream>

class String {
    public:
    String();
    String(unsigned int, char);
    String(const  char*);
    String(const String&);
    String(String&&);
    ~String();
    public:
    const char& operator[](const unsigned int) const;
    char& operator[](const unsigned int);
    const char& at(const unsigned int) const;
    friend std::ostream& operator<<(std::ostream&,String&);
    friend std::istream& operator>>(std::istream&,String&);
    String& operator=(const String&);
    String& operator=( String&& ); 
    String operator+( const String rhs) const;
    String& operator+=(char);
    String operator+(char);
    String substr(int, int);
    bool operator>(const String& rhs)const;
    bool operator<(const String& rhs)const;
    bool operator==(const String& rhs)const;
    bool operator!=(const String&rhs)const;
    bool operator>=(const String& rhs)const;
    bool operator<=(const String& rhs)const;
    void push_back(char);
    char pop_back();
    void push_front(char);
    char pop_front();
    void resize(const int , char );
    int find(const char);
    int find(const String&);
    int find(const char*);
    void insert(const int, char );
    void insert(const int, const int,char);
    void clear();
    bool empty();
    void replace(char ch, int index);
    void replace(int index, char* arr); 
    int stoi();

    private:
    unsigned size;
    char* buffer; 
};
#endif /* STRING_H*/