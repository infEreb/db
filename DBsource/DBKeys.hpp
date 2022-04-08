#ifndef DBKEYS_HPP
#define DBKEYS_HPP

#include <memory>

#include "DBAttribute.hpp"

class DBKey {
    std::shared_ptr<DBAttributeAbstract> _attribute;

public:
    DBKey(const std::shared_ptr<DBAttributeAbstract>& attribute);
    virtual ~DBKey() = default;

    virtual std::shared_ptr<DBAttributeAbstract> GetAttribute() = 0;
};

template<class T>
class DBPrimaryKey : public DBKey {

public:
    DBPrimaryKey(const std::shared_ptr< DBAttribute<T> >& attribute);
    ~DBPrimaryKey();

    std::shared_ptr< DBAttribute<T> > *GetAttribute() override;
};

template<class T>
class DBForeignKey : public DBKey {

public:
    DBForeignKey(const std::shared_ptr< DBAttribute<T> >& attribute);
    ~DBForeignKey();

    std::shared_ptr< DBAttribute<T> > GetAttribute() override;

};




#endif // DBKEYS_HPP
