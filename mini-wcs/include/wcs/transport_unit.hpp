#pragma once

#include <optional>

#include "ids.hpp"

namespace wcs {

struct TransportUnit {
  UnitId id;
  double weight_kg;
  std::optional<LocationId> current_location; // empty = not yet in the system
};

} // namespace wcs
