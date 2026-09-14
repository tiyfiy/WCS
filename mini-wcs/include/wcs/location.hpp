#pragma once

#include <string_view>

#include "ids.hpp"

namespace wcs {

enum class LocationKind { Source, Storage, Conveyor, Station, Sink };

struct Location {
  LocationId id;
  LocationKind kind;
  int capacity; // how many units fit here
};

// Deliberately no `default:` label: with every enumerator listed and no default,
// adding a new LocationKind makes -Wswitch fire at compile time. A `default:`
// would silence that and let the new kind quietly log as "unknown" instead.
//
// The trailing return is still needed because an `enum class` can legally hold
// an out-of-range value obtained through a cast, so the switch is not provably
// exhaustive to the compiler.
constexpr std::string_view to_string(LocationKind kind) {
  switch (kind) {
  case LocationKind::Source:
    return "Source";
  case LocationKind::Storage:
    return "Storage";
  case LocationKind::Conveyor:
    return "Conveyor";
  case LocationKind::Station:
    return "Station";
  case LocationKind::Sink:
    return "Sink";
  }
  return "unknown";
}

} // namespace wcs
