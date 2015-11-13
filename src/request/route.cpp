#include "request/route.h"

void Route::setTarget(RequestTarget target) {
   _target = target; 
}

void Route::setAction(RequestAction action) {
    _action = action;
}

RequestTarget Route::getTarget() {
    return _target;
}

RequestAction Route::getAction() {
    return _action;
}
