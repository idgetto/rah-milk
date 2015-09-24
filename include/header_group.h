#ifndef HEADER_GROUP_H 
#define HEADER_GROUP_H

#include <string>
#include <map>
#include <vector>

using std::string;
using std::multimap;
using std::vector;

class HeaderGroup {
public:
    bool contains(const string& key) const;
    unsigned count(const string& key) const;

    void add(const string& key, const string& val);

    string getFirst(const string& key) const;
    string getLast(const string& key) const;
    vector<string> getAll(const string& key) const;

    string removeFirst(const string& key);
    string removeLast(const string& key);
    vector<string> removeAll(const string& key);

private:
    multimap<string, string> _mmap;
    multimap<string, string>::const_iterator findLast(const string& key) const;
};

#endif
