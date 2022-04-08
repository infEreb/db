#ifndef DBCOLUMN_HPP
#define DBCOLUMN_HPP

#include <memory>

#include <QVector>
#include <QMap>

#include "DBTypes.hpp"
#include "DBAttribute.hpp"

class DBColumnAbstract {

public:
    ~DBColumnAbstract() = default;
};

template<class T>
class DBColumn : public DBColumnAbstract {
    std::shared_ptr< DBAttribute<T> > _attribute;
    QVector<T> *_values;

public:
    DBColumn(std::shared_ptr< DBAttribute<T> > attribute);
    ~DBColumn();

    QVector<T> *GetValues();
};

#endif // DBCOLUMN_HPP
