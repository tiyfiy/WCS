#pragma once
#include <string>
#include <utility>

namespace wcs {

template <typename Tag, typename Underlying = std::string> class StrongId {
public:
  explicit StrongId(Underlying v) : value_(std::move(v)) {}
  const Underlying &value() const noexcept { return value_; }
  auto operator<=>(const StrongId &) const = default;
  bool operator==(const StrongId &) const = default;

private:
  Underlying value_;
};

struct OrderIdTag {};
struct LocationIdTag {};
struct UnitIdTag {};

using OrderId = StrongId<OrderIdTag>;
using LocationId = StrongId<LocationIdTag>;
using UnitId = StrongId<UnitIdTag>;

} // namespace wcs
