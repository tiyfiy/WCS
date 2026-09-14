#include "wcs/location.hpp"

#include <array>
#include <gtest/gtest.h>
#include <set>
#include <string_view>

namespace {

// Every enumerator, listed once. Adding a LocationKind without updating this
// array is caught by AllKindsHaveDistinctNames only if the array is updated;
// the real guard against a missing case is the -Wswitch error inside to_string.
constexpr std::array<wcs::LocationKind, 5> kAllKinds{
    wcs::LocationKind::Source, wcs::LocationKind::Storage,
    wcs::LocationKind::Conveyor, wcs::LocationKind::Station,
    wcs::LocationKind::Sink};

} // namespace

TEST(Location, ConstructsWithDesignatedInitialisers) {
  const wcs::Location dock{.id = wcs::LocationId{"dock-1"},
                           .kind = wcs::LocationKind::Source,
                           .capacity = 10};

  EXPECT_EQ(dock.id, wcs::LocationId{"dock-1"});
  EXPECT_EQ(dock.kind, wcs::LocationKind::Source);
  EXPECT_EQ(dock.capacity, 10);
}

TEST(LocationKindToString, MapsEveryEnumerator) {
  EXPECT_EQ(to_string(wcs::LocationKind::Source), "Source");
  EXPECT_EQ(to_string(wcs::LocationKind::Storage), "Storage");
  EXPECT_EQ(to_string(wcs::LocationKind::Conveyor), "Conveyor");
  EXPECT_EQ(to_string(wcs::LocationKind::Station), "Station");
  EXPECT_EQ(to_string(wcs::LocationKind::Sink), "Sink");
}

TEST(LocationKindToString, AllKindsHaveDistinctNonEmptyNames) {
  std::set<std::string_view> names;
  for (const wcs::LocationKind kind : kAllKinds) {
    const std::string_view name = to_string(kind);
    EXPECT_FALSE(name.empty());
    EXPECT_NE(name, "unknown");
    names.insert(name);
  }

  EXPECT_EQ(names.size(), kAllKinds.size());
}

TEST(LocationKindToString, IsUsableAtCompileTime) {
  static_assert(to_string(wcs::LocationKind::Conveyor) == "Conveyor");
  SUCCEED();
}

TEST(LocationKindToString, FoundByArgumentDependentLookup) {
  // Unqualified call: to_string lives in namespace wcs alongside LocationKind.
  const wcs::LocationKind kind = wcs::LocationKind::Station;
  EXPECT_EQ(to_string(kind), "Station");
}

TEST(LocationKind, IsScopedAndDoesNotConvertToInt) {
  static_assert(!std::is_convertible_v<wcs::LocationKind, int>);
  SUCCEED();
}
