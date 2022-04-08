#include "DBAttribute.hpp"

//
// DBAttributeAbstract
//
DBAttributeAbstract::DBAttributeAbstract(const QString& name) { _name = name; }

QString DBAttributeAbstract::GetName() { return _name; }
void DBAttributeAbstract::SetName(const QString& name) { _name = name; }

//
// Attribute
//
template<class T>
DBAttribute<T>::DBAttribute(const QString& name) : DBAttributeAbstract(name) {}
