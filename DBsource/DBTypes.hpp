#ifndef _DBTYPES_
#define _DBTYPES_

#include <string>

#include <QString>

#include "DBIFilters.hpp"

template<class T>
class DBType {

protected:
    T _value;
    //std::string _type_name;

public:
    DBType();
    DBType(T type_value);
    ~DBType();

    virtual T GetValue();
    //virtual std::string GetType();

    bool operator == (const DBType<T>& r);
    bool operator != (const DBType<T>& r);
};

class DBVarchar : DBType<QString> {
    size_t _size;

    void SetSize(size_t size);

public:
    DBVarchar(size_t size);
    ~DBVarchar();

    QString GetValue();

    DBVarchar& operator = (const QString val);

};

class DBInteger : DBType<u_int16_t> {
public:
    DBInteger(uint16_t value);
    ~DBInteger();

    DBInteger& operator = (const u_int16_t val);
};

class DBDate : public DBType<QString>, DBIFilterDate {
public:
    DBDate();
    DBDate(const char *value);
    DBDate(const QString value);
    DBDate(const DBDate& date);
    ~DBDate();

    DBDate& operator = (const QString val);
    DBDate& operator = (const DBDate& date);
};

class DBEmail : public DBType<QString>, public DBIFilterEmail {
public:
    DBEmail();
    DBEmail(const char *value);
    DBEmail(const QString& value);
    DBEmail(const DBEmail& email);
    ~DBEmail();

    DBEmail& operator = (const QString& val);
    DBEmail& operator = (const DBEmail& email);
};

#endif
