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

    // headers with the same key are 
    //stored in a comma separated list 
    // RFC 7230 S3.2.2 https://tools.ietf.org/html/rfc7230#section-3.2.2
    //
    // Set-Cookie headers are not accepted by this 
    // method. Use HeaderGroup::addCookie instead.
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

    vector<string>::size_type indexOf(const string& key) const;
};

#endif
