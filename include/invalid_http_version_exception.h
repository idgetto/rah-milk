#ifndef INVALID_HTTP_VERSION_EXCEPTION_H
#define INVALID_HTTP_VERSION_EXCEPTION_H

#include <stdexcept>

using std::runtime_error;

class InvalidHttpVersionException : public runtime_error {
public:
    InvalidHttpVersionException(const string& version) : 
        runtime_error("invalid version: " + version), 
        _version(version) {}

    virtual const char* what() const throw() {
        return string("invalid HTTP version: " + _version).c_str();
    }

private:
    string _version;
};

#endif
