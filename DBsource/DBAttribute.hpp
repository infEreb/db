#ifndef DBATTRIBUTE_HPP
#define DBATTRIBUTE_HPP

#include <QString>

class DBAttributeAbstract {
    QString _name;

public:
    DBAttributeAbstract(const QString& name);
    virtual ~DBAttributeAbstract() = default;

    QString GetName();
    void SetName(const QString& name);
};

template<class T>
class DBAttribute : public DBAttributeAbstract {

public:
    DBAttribute(const QString& name);

};

#endif
