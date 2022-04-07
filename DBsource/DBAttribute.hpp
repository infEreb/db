#ifndef _DBATTRIBUTE_
#define _DBATTRIBUTE_

#include <string>

template<class T>
class DBAttribute {
    std::string _name;

protected:
    //T _value;

public:
    DBAttribute(std::string name);
    ~DBAttribute();

    std::string GetName();
    void SetName(std::string name);    
};

#endif