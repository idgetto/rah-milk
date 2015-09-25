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

hpair HeaderGroup::getFirst(const string& key) const {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }

    return *_mmap.find(key);
}

hpair HeaderGroup::getLast(const string& key) const {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }
    
    return *findLast(key);
}

vector<hpair> HeaderGroup::getAll(const string& key) const {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }

    vector<hpair> res;
    for (auto it = _mmap.begin(); it != _mmap.end(); ++it) {
        res.push_back(*it);
    } 
    return res;
}

hpair HeaderGroup::removeFirst(const string& key) {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }

    auto it = _mmap.find(key);
    hpair val = *it;
    _mmap.erase(it);

    return val;
}

hpair HeaderGroup::removeLast(const string& key) {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }

    auto it = findLast(key); 
    hpair val = *it;
    _mmap.erase(it);

    return val;
}

vector<hpair> HeaderGroup::removeAll(const string& key) {
    if (!contains(key)) {
        throw runtime_error("key not found");
    }
   
    vector<hpair> res;
    for (auto it = _mmap.begin(); it != _mmap.end(); ++it) {
        res.push_back(*it);
        _mmap.erase(it);    
    } 
    return res;
}

map_t::const_iterator HeaderGroup::findLast(const string& key) const {
    for (auto it = _mmap.crbegin(); it != _mmap.crend(); ++it) {
        if (key == it->first) {
            return (++it).base();
        }
    }
    return _mmap.cend();
}
