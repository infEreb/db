#ifndef DBTABLE_HPP
#define DBTABLE_HPP

#include <memory>

#include <QString>
#include <QVector>
#include <QMap>

#include "DBTypes.hpp"
#include "DBKeys.hpp"
#include "DBAttribute.hpp"
#include "DBColumn.hpp"

class DBTable {

    QString _name;
    QVector< std::shared_ptr<DBAttributeAbstract> > _attributes;

    DBKey *_primary_key;
    QVector< std::shared_ptr<DBKey> > *_foreign_keys;



};

#endif
