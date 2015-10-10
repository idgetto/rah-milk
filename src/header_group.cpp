#include <stdexcept>
#include <algorithm>
#include <iterator>

#include "header_group.h"

using std::invalid_argument;
using std::begin;
using std::end;

const string HeaderGroup::SET_COOKIE_KEY = "Set-Cookie";

bool HeaderGroup::contains(const string& key) const {
    return find(begin(_keys), end(_keys), key) != end(_keys);
}

void HeaderGroup::add(const string& key, const string& val) {
    if (contains(key)) {
        throw invalid_argument("key is not unique");
    }
    if (key == HeaderGroup::SET_COOKIE_KEY) {
        throw invalid_argument("set cookie using HeaderGoup::addCookie");
    }

    _keys.push_back(key);
    _vals.push_back(val);
}

string HeaderGroup::get(const string& key) const {
    if (!contains(key)) {
        throw invalid_argument("key not found");
    }
    auto it = find(begin(_keys), end(_keys), key);
    auto index = distance(begin(_keys), it);
    return _vals[index];
}

string HeaderGroup::remove(const string& key) {
    if (!contains(key)) {
        throw invalid_argument("key not found");
    }
    auto it = find(begin(_keys), end(_keys), key);
    auto index = distance(begin(_keys), it);
    string val = _vals[index];

    _keys.erase(begin(_keys) + index);
    _vals.erase(begin(_vals) + index);

    return val;
}

void HeaderGroup::addCookie(const string& val) {
    _cookies.push_back(val);
}

const vector<string>& HeaderGroup::getCookies() const {
    return _cookies;
}

void HeaderGroup::clearCookies() {
    _cookies.clear();
}

ostream& operator<<(ostream& out, const HeaderGroup& headerGroup) {
    for (vector<string>::size_type index = 0;
         index < headerGroup._keys.size();
         ++index) {
        out << headerGroup._keys[index]
            << ": "
            << headerGroup._vals[index]
            << "\r\n";
    }

    for (const string& cookie : headerGroup.getCookies()) {
        out << HeaderGroup::SET_COOKIE_KEY
            << ": "
            << cookie
            << "\r\n";
    }

    return out;
}
