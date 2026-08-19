#include "wcs/ping.hpp"

namespace wcs {

std::string ping(const std::string& message) {
    if (message == "ping") {
        return "pong";
    }
    return message;
}

}  // namespace wcs
