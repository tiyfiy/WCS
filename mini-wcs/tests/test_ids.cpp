#include "wcs/ids.hpp"

#include <gtest/gtest.h>
#include <type_traits>
#include <unordered_map>

TEST(StrongId, StoresAndReturnsOriginalValue) {
  const wcs::OrderId order{"order-123"};
  const wcs::LocationId location{"aisle-7"};
  const wcs::UnitId unit{"unit-42"};

  EXPECT_EQ(order.value(), "order-123");
  EXPECT_EQ(location.value(), "aisle-7");
  EXPECT_EQ(unit.value(), "unit-42");
}

TEST(StrongId, SupportsEquality) {
  const wcs::OrderId first{"order-123"};
  const wcs::OrderId same{"order-123"};
  const wcs::OrderId different{"order-456"};

  EXPECT_EQ(first, same);
  EXPECT_NE(first, different);
}

TEST(StrongId, SupportsOrdering) {
  const wcs::OrderId earlier{"order-123"};
  const wcs::OrderId later{"order-456"};

  EXPECT_LT(earlier, later);
  EXPECT_GT(later, earlier);
}

TEST(StrongId, DifferentTagsProduceDifferentTypes) {
  static_assert(!std::is_same_v<wcs::OrderId, wcs::LocationId>);
  static_assert(!std::is_same_v<wcs::OrderId, wcs::UnitId>);
  static_assert(!std::is_same_v<wcs::LocationId, wcs::UnitId>);

  SUCCEED();
}

TEST(StrongId, WorksAsAnUnorderedMapKey) {
  std::unordered_map<wcs::OrderId, std::string> orders;
  orders.emplace(wcs::OrderId{"order-123"}, "ready");

  EXPECT_EQ(orders.at(wcs::OrderId{"order-123"}), "ready");
}

// This should not compile; uncomment temporarily to verify the type safety:
// wcs::OrderId invalid = wcs::LocationId{"aisle-7"};
