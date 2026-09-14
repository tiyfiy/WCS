#include <string>

enum class locationKind { Source, Storage, Conveyor, Station, Sink };

struct Location {
    LocationId id;
    LocationKind kind;
    int capacity;
};


std::string_view to_string(LocationKind) {
    
}