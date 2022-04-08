#ifndef DBFIELDS_HPP
#define DBFIELDS_HPP

#include <QVector>

#include "DBTypes.hpp"
#include "DBKeys.hpp"

class DBFieldAbtrsact {
public:
    virtual ~DBFieldAbtrsact() = default;
};

class DBField {
    std::shared_ptr<DBKey> _primaty_key;

    QVector< std::shared_ptr<DBTypeAbstract> > *_field;

public:
    DBField(const std::shared_ptr<DBKey>& primary_key);
    ~DBField();

};

#endif // DBFIELDS_HPP
