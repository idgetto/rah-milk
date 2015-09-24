#include <boost/xpressive/xpressive.hpp>
#include <sstream>

#include "http_version.h"
#include "invalid_http_version_exception.h"
#include "basic_regex.h"

using boost::xpressive::sregex;
using boost::xpressive::smatch;
using boost::xpressive::regex_match;
using std::stringstream;

const sregex HttpVersion::HTTP_VERSION_CAPTURE_REGEX = sregex::compile(HTTP_VERSION_CAPTURE);

HttpVersion::HttpVersion(const string& httpVersionString) {
    smatch match;

    if (!regex_match(httpVersionString, 
                        match, 
                        HttpVersion::HTTP_VERSION_CAPTURE_REGEX)) {
        throw InvalidHttpVersionException(httpVersionString);
    } else {
        _majorVersion = stoi(BasicRegex::getMatch(match, MAJOR_VERSION_NAME));
        _minorVersion = stoi(BasicRegex::getMatch(match, MINOR_VERSION_NAME));
    }
}

int HttpVersion::getMajorVersion() const {
    return _majorVersion;
}

int HttpVersion::getMinorVersion() const {
    return _minorVersion;
}

ostream& operator<<(ostream& out, const HttpVersion& httpVersion) {
    return out << "HTTP/" 
               << httpVersion.getMajorVersion() 
               << "." 
               << httpVersion.getMinorVersion();
}
