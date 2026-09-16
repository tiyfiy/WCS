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
