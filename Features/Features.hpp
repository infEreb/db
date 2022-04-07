#ifndef _FEATURES_
#define _FEATURES_

#include <string>
#include <vector>

#include <QString>
#include <QVector>

class Features {
public:
    static int StringToNumber(QString num_str);
    static std::vector<std::string> StringSplit(std::string str, std::string delim);
};

#endif
