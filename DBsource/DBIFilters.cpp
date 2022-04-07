#include "DBIFilters.hpp"

#include <cmath>
#include <utility>

#include "../Features/Features.hpp"

//
// IFilterName
//
IFilterName::IFilterName() {}
IFilterName::~IFilterName() {}

bool IFilterName::Filter(QString name) {
    if(name.size() > NAME_MAX_SIZE || name.size() < NAME_MIN_SIZE)
        return false;
    
    return true;
}

//
// IFilterTelephone
//
DBIFilterTelephone::DBIFilterTelephone() {}
DBIFilterTelephone::~DBIFilterTelephone() {}

bool DBIFilterTelephone::Filter(QString telephone) {
    if(telephone.size() > TELEPHONE_MAX_SIZE || telephone.size() < TELEPHONE_MIN_SIZE)
        return false;
    
    for(auto c: telephone)
        if(!c.isDigit())
            return false;
    
    return true;
}

//
// IFilterTelephone
//
DBIFilterEmail::DBIFilterEmail() {}
DBIFilterEmail::~DBIFilterEmail() {}

bool DBIFilterEmail::Filter(QString _email) {
    if(_email.size() > EMAIL_MAX_SIZE || _email.size() < EMAIL_MIN_SIZE)
        return false;
    
    u_int16_t name_counter = 0;
    u_int16_t domain_counter = 0;
    bool at_sign_contain = false;
    for(int i = 0; i < _email.size(); i++) {
        // checks at-sign and return false if its first
        if(_email[i] == '@') {
            at_sign_contain = true;
            if(name_counter > EMAIL_USERNAME_MAX_SIZE || name_counter < EMAIL_USERNAME_MIN_SIZE)
                return false;
        }

        // inc name if we didnt meet '@' otherwise inc domain
        if(!at_sign_contain)
            name_counter++;
        else
            domain_counter++;

        // domain chars check
        if(domain_counter > EMAIL_DOMAIN_MAX_SIZE || domain_counter < EMAIL_DOMAIN_MIN_SIZE)
            return false;
    }
    
    return true;
}

//
// IFilterDate
//
DBIFilterDate::DBIFilterDate() { }
DBIFilterDate::~DBIFilterDate() {}

bool DBIFilterDate::Filter(QString date) {
    if(date.size() != DATE_SIZE)
        return false;

    if(date[DATE_1_SPLIT] != DATE_SPLIT_CHAR || date[DATE_2_SPLIT] != DATE_SPLIT_CHAR)
        return false;
    
    int i = 0;
    std::pair<int, int> m[3] = { 
        {DATE_MIN_YEAR, DATE_MAX_YEAR},
        {DATE_MIN_MONTH, DATE_MAX_MONTH},
        {DATE_MIN_DAY, DATE_MAX_DAY} };
    int num = 0;
    
    for(auto elem: date.split(QChar(DATE_SPLIT_CHAR))) {
        if((num = Features::StringToNumber(elem)) == 0) {
            return false;
        }
        if(num < m[i].first || num > m[i].second) {
            return false;
        }

        num = 0;
        i++;
    }

    return true;
}
