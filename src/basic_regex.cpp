#include "basic_regex.h"

namespace BasicRegex {
    string getMatch(const smatch& match, const string& name) {
        stringstream s;
        s << match[name];
        return s.str();
    }
}
