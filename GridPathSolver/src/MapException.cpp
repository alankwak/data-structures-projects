#include "MapException.h"

MapException::MapException(string m) {
    error = m;
}
string MapException::getError() const {
    return error;
}