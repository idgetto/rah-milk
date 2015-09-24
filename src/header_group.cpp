#include <stdexcept>

#include "header_group.h"

using std::runtime_error;

bool HeaderGroup::contains(const string& key) const {
    return _mmap.count(key) != 0;
}
unsigned HeaderGroup::count(const string& key) const {
    return _mmap.count(key);
}

void HeaderGroup::add(const string& key, const string& val) {
    _mmap.emplace(key, val);
}

string HeaderGroup::getFirst(const string& key) const {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }

    auto val = _mmap.find(key);
    return val->second;
}

string HeaderGroup::getLast(const string& key) const {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }
    
    return findLast(key)->second;
}

vector<string> HeaderGroup::getAll(const string& key) const {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }

    vector<string> res;
    for (auto it = _mmap.begin(); it != _mmap.end(); ++it) {
        res.push_back(it->second);
    } 
    return res;
}

string HeaderGroup::removeFirst(const string& key) {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }

    auto it = _mmap.find(key);
    string val = it->second;

    _mmap.erase(it);
    return val;
}

string HeaderGroup::removeLast(const string& key) {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }

    auto it = findLast(key); 
    string val = it->second;

    _mmap.erase(it);
    return val;
}

vector<string> HeaderGroup::removeAll(const string& key) {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }
   
    vector<string> res;
    for (auto it = _mmap.begin(); it != _mmap.end(); ++it) {
        res.push_back(it->second);
        _mmap.erase(it);    
    } 
    return res;
}

multimap<string, string>::const_iterator HeaderGroup::findLast(const string& key) const {
    for (auto it = _mmap.crbegin(); it != _mmap.crend(); ++it) {
        if (key == it->first) {
            return (++it).base();
        }
    }
    return _mmap.cend();
}
