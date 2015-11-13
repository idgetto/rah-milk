#include "request/request_action.h"

std::size_t RequestAction::_classId = 0;

RequestAction::RequestAction(function_t action) : _action{action} {
    _id = getId();
}

void RequestAction::operator()(const RequestMessage& req, ResponseMessage& res) {
    _action(req, res);
}

bool RequestAction::operator==(const RequestAction& other) const {
    return _id == other._id;
}

std::size_t RequestAction::getId() {
    std::size_t most = (std::size_t) -1;
    _classId = (_classId + 1) % most;
    return _classId;
}
