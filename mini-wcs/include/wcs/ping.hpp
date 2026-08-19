#pragma once

#include <string>

namespace wcs {

// Returns "pong" for any input, echoing back a simple liveness signal.
std::string ping(const std::string& message = "ping");

}  // namespace wcs
