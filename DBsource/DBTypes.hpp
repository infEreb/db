#ifndef DBTYPES_HPP
#define DBTYPES_HPP

#include <string>

#include <QString>

#include "DBIFilters.hpp"

typedef u_int64_t DBID;

class DBTypeAbstract {

protected:
    virtual QString GetTypeName() = 0;

public:
    DBTypeAbstract();
    virtual ~DBTypeAbstract();

};

template<class T>
class DBType : DBTypeAbstract {

protected:
    T _value;

    QString GetTypeName() override;

public:
    DBType();
    DBType(T type_value);
    ~DBType();

    T GetValue();


    bool operator == (const DBType<T>& r);
    bool operator != (const DBType<T>& r);
};

class DBVarchar : public DBType<QString> {
    size_t _size;

    void SetSize(size_t size);

public:
    DBVarchar(size_t size);
    ~DBVarchar();

    QString GetTypeName() override;

    DBVarchar& operator = (const QString val);

};

class DBInteger : public DBType<u_int16_t> {
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

    QString GetTypeName() override;

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

    QString GetTypeName() override;

    DBEmail& operator = (const QString& val);
    DBEmail& operator = (const DBEmail& email);
};

#endif
