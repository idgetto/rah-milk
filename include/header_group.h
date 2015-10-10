#ifndef HEADER_GROUP_H 
#define HEADER_GROUP_H

#include <string>
#include <vector>
#include <utility>
#include <ostream>

using std::string;
using std::vector;
using std::ostream;

class HeaderGroup {
public:
    bool contains(const string& key) const;
    void add(const string& key, const string& val);
    string get(const string& key) const;
    string remove(const string& key);

    void addCookie(const string& val);
    const vector<string>& getCookies() const;
    void clearCookies();

    friend ostream& operator<<(ostream& out, const HeaderGroup& headerGroup);
private:
    vector<string> _keys;
    vector<string> _vals;
    vector<string> _cookies;

    const static string SET_COOKIE_KEY;
};

#endif
