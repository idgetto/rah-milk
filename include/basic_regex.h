#ifndef REGEX_H
#define REGEX_H

#define DIGIT "(?:" "\\d" ")"

#include <sstream>
#include <string>
#include <boost/xpressive/xpressive.hpp>

using std::string;
using std::stringstream;
using boost::xpressive::smatch;

namespace BasicRegex {
    string getMatch(const smatch& match, const string& name);
}

#endif
