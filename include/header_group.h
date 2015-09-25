#ifndef HEADER_GROUP_H 
#define HEADER_GROUP_H

#include <string>
#include <map>
#include <vector>
#include <utility>

using std::string;
using std::multimap;
using std::vector;

using hpair = std::pair<string, string>;
using map_t = multimap<string, string>;

class HeaderGroup {
public:
    bool contains(const string& key) const;
    unsigned count(const string& key) const;

    void add(const string& key, const string& val);

    hpair getFirst(const string& key) const;
    hpair getLast(const string& key) const;
    vector<hpair> getAll(const string& key) const;

    hpair removeFirst(const string& key);
    hpair removeLast(const string& key);
    vector<hpair> removeAll(const string& key);

private:
    map_t _mmap;
    map_t::const_iterator findLast(const string& key) const;
};

#endif
