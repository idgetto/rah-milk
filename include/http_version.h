#ifndef HTTP_VERSION_H
#define HTTP_VERSION_H

#include <string>
#include <ostream>
#include <boost/xpressive/xpressive.hpp>

#include "basic_regex.h"


#define HTTP_VERSION "(?:" \
                        "HTTP" "\\/" \
                        DIGIT \
                        "\\." \
                        DIGIT \
                     ")"

#define MAJOR_VERSION_NAME "majorVersion"
#define MINOR_VERSION_NAME "minorVersion"
#define HTTP_VERSION_CAPTURE "(?:" \
                                "HTTP" "\\/" \
                                "(?P<" MAJOR_VERSION_NAME ">" DIGIT ")" \
                                "\\." \
                                "(?P<" MINOR_VERSION_NAME ">" DIGIT ")" \
                             ")"

using std::ostream;
using std::string;
using boost::xpressive::sregex;

class HttpVersion {
public:
    const static sregex HTTP_VERSION_CAPTURE_REGEX;

    HttpVersion();
    HttpVersion(const string& httpVersionString);

    int getMajorVersion() const;
    int getMinorVersion() const;
private:
    int _majorVersion;
    int _minorVersion;
};

ostream& operator<<(ostream&, const HttpVersion& httpVersion);

#endif
