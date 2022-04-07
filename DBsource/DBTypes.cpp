#include "DBTypes.hpp"

//
// DBType
//
template<class T>
DBType<T>::DBType() {}
template<class T>
DBType<T>::~DBType() {}
template<class T>
DBType<T>::DBType(T value) : _value(value) {}

template<class T>
T DBType<T>::GetValue() { return _value; }

template<class T>
bool DBType<T>::operator==(const DBType<T>& right) { return _value == right._value; }
template<class T>
bool DBType<T>::operator!=(const DBType<T>& right) { return _value != right._value; }

//
// DBDate
//
DBDate::DBDate() { _value = ""; }
DBDate::DBDate(const char *value) : DBType(value) { if(!Filter(value)) _value = ""; }
DBDate::DBDate(const QString value) : DBType(value) { if(!Filter(value)) _value = ""; }
DBDate::DBDate(const DBDate& date) { operator=(date); }
DBDate::~DBDate() {}

DBDate& DBDate::operator=(const QString date) {
    if (Filter(date)) {
        _value = date;
    } else {
        _value = "";
    }

    return *this;
}
DBDate& DBDate::operator=(const DBDate& date) {
    if(*this != date)
        _value = date._value;
    return *this;
}
