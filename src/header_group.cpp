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
    auto index = indexOf(key);
    if (index != _keys.size()) {
        _vals[index] = _vals[index].append(", ").append(val);
    }
    if (key == HeaderGroup::SET_COOKIE_KEY) {
        throw invalid_argument("set cookie using HeaderGoup::addCookie");
    }

    _keys.push_back(key);
    _vals.push_back(val);
}

string HeaderGroup::get(const string& key) const {
    auto index = indexOf(key);
    if (index == _keys.size()) {
        throw invalid_argument("key not found");
    }
    return _vals[index];
}

string HeaderGroup::remove(const string& key) {
    auto index = indexOf(key);
    if (index == _keys.size()) {
        throw invalid_argument("key not found");
    }
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

vector<string>::size_type HeaderGroup::indexOf(const string& key) const {
    auto it = find(begin(_keys), end(_keys), key);
    return distance(begin(_keys), it);
}
