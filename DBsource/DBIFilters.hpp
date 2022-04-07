#ifndef _DBIFILTERS_
#define _DBIFILTERS_

#include <QString>
#include <QStringList>

#define TELEPHONE_FORMAT "89997771111"
#define TELEPHONE_MAX_SIZE 15
#define TELEPHONE_MIN_SIZE 8

#define EMAIL_FORMAT "name@domain"
#define EMAIL_MAX_SIZE 320
#define EMAIL_MIN_SIZE 3
#define EMAIL_USERNAME_MAX_SIZE 64
#define EMAIL_USERNAME_MIN_SIZE 1
#define EMAIL_DOMAIN_MAX_SIZE 255
#define EMAIL_DOMAIN_MIN_SIZE 1

#define DATE_FORMAT "YYYY-MM-DD"
#define DATE_SIZE 10
#define DATE_1_SPLIT 4
#define DATE_2_SPLIT 7
#define DATE_SPLIT_CHAR '-'
#define DATE_MAX_YEAR 2030
#define DATE_MIN_YEAR 1880
#define DATE_MAX_MONTH 12
#define DATE_MIN_MONTH 1
#define DATE_MAX_DAY 31
#define DATE_MIN_DAY 1

// Users defines
#define NAME_MAX_SIZE 150
#define NAME_MIN_SIZE 3


//
// DBs filters
//
template<class T>
class DBIFilter {
protected:
    virtual bool Filter(T) = 0;
};

class DBIFilterTelephone : DBIFilter<QString> {
protected:
    
    bool Filter(QString telephone) override;

public:
    DBIFilterTelephone();
    ~DBIFilterTelephone();
};

class DBIFilterEmail : DBIFilter<QString> {
protected:

    bool Filter(QString email) override;

public:
    DBIFilterEmail();
    ~DBIFilterEmail();
};

class DBIFilterDate : DBIFilter<QString> {
protected:
    bool Filter(QString date) override;

public:
    DBIFilterDate();
    ~DBIFilterDate();
};

//
// Users filters
//
class IFilterName : DBIFilter<QString> {
protected:
    bool Filter(QString name) override;

public:
    IFilterName();
    ~IFilterName();
};
#endif
