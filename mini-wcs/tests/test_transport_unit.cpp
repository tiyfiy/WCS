#include "wcs/transport_unit.hpp"

#include <gtest/gtest.h>
#include <optional>

TEST(TransportUnit, ConstructsWithDesignatedInitialisers) {
  const wcs::TransportUnit pallet{.id = wcs::UnitId{"unit-42"},
                                  .weight_kg = 12.5,
                                  .current_location =
                                      wcs::LocationId{"aisle-7"}};

  EXPECT_EQ(pallet.id, wcs::UnitId{"unit-42"});
  EXPECT_DOUBLE_EQ(pallet.weight_kg, 12.5);
  ASSERT_TRUE(pallet.current_location.has_value());
  EXPECT_EQ(*pallet.current_location, wcs::LocationId{"aisle-7"});
}

TEST(TransportUnit, LocationIsEmptyWhenNotYetInTheSystem) {
  const wcs::TransportUnit pallet{
      .id = wcs::UnitId{"unit-43"}, .weight_kg = 3.0, .current_location = {}};

  EXPECT_FALSE(pallet.current_location.has_value());
  EXPECT_EQ(pallet.current_location, std::nullopt);
}

TEST(TransportUnit, LocationDefaultsToEmptyWhenOmitted) {
  const wcs::TransportUnit pallet{.id = wcs::UnitId{"unit-44"},
                                  .weight_kg = 1.0};

  EXPECT_FALSE(pallet.current_location.has_value());
}

TEST(TransportUnit, ValueOnEmptyLocationThrows) {
  const wcs::TransportUnit pallet{.id = wcs::UnitId{"unit-45"},
                                  .weight_kg = 1.0};

  EXPECT_THROW((void)pallet.current_location.value(), std::bad_optional_access);
}

TEST(TransportUnit, ValueOrSuppliesAFallbackWithoutThrowing) {
  const wcs::TransportUnit pallet{.id = wcs::UnitId{"unit-46"},
                                  .weight_kg = 1.0};

  EXPECT_EQ(pallet.current_location.value_or(wcs::LocationId{"receiving"}),
            wcs::LocationId{"receiving"});
}

TEST(TransportUnit, LocationCanBeSetAndClearedLater) {
  wcs::TransportUnit pallet{.id = wcs::UnitId{"unit-47"}, .weight_kg = 8.0};
  ASSERT_FALSE(pallet.current_location.has_value());

  pallet.current_location = wcs::LocationId{"station-3"};
  ASSERT_TRUE(pallet.current_location.has_value());
  EXPECT_EQ(pallet.current_location->value(), "station-3");

  pallet.current_location.reset();
  EXPECT_FALSE(pallet.current_location.has_value());
}
