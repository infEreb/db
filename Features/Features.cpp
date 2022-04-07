#include "Features.hpp"
#include <cmath>

int Features::StringToNumber(QString num_str) {
    int num = 0;
    bool neg = num_str[0] == '-' ? true : false;
    if(neg) num_str = num_str.remove(0,1);
    
    for(int i = 0, j = num_str.size()-1; i < num_str.size(); i++, j--) {
        if(!num_str[j].isDigit())
            return 0;
        //int jn = std::abs(QChar('0') - num_str[j]);
        num += std::pow(10, i) * num_str[j].digitValue();
    }
    if(neg) num *= -1;
    return num;
}

std::vector<std::string> Features::StringSplit(std::string str, std::string delim) {
    std::vector<std::string> res;
    size_t pos = 0;
    std::string sub_str;

    while((pos = str.find(delim)) != std::string::npos) {
        sub_str = str.substr(0, pos);
        res.push_back(sub_str);
        str.erase(0, pos + delim.size());
    }

    return res;
}
