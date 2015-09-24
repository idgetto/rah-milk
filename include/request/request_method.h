#ifndef REQUEST_METHOD_H
#define REQUEST_METHOD_H

#include <string>
#include <ostream>

using std::string;
using std::ostream;

class RequestMethod {
public:
    RequestMethod(const string& str);
    static RequestMethod fromString(const string& method);        

    const string& getStr() const;

    const static RequestMethod GET;
    const static RequestMethod HEAD;
    const static RequestMethod POST;
    const static RequestMethod PUT;
    const static RequestMethod DELETE;
    const static RequestMethod TRACE;
    const static RequestMethod OPTIONS;
    const static RequestMethod CONNECT;

    const static string GET_STR;
    const static string HEAD_STR;
    const static string POST_STR;
    const static string PUT_STR;
    const static string DELETE_STR;
    const static string TRACE_STR;
    const static string OPTIONS_STR;
    const static string CONNECT_STR;

private:
    string _str;
};

ostream& operator<<(ostream& out, const RequestMethod& requestMethod);
bool operator==(const RequestMethod& a, const RequestMethod& b);

#endif
