#include <optional>
#include <string>

struct TransportUnit {
    UnitId id;
    double weight_kg;
    std::optional<LocationId> current_location;
};
