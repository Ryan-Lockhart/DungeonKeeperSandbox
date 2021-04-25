#ifndef CONSTANTS_H

#define CONSTANTS_H

constexpr float windowWidth = 1280;
constexpr float windowHeight = 720;

constexpr size_t glyphWidth = 12;
constexpr size_t glyphHeight = 12;

constexpr size_t floorGlyph = 0xB0;
constexpr size_t wallGlyph = 0xB2;
constexpr size_t actorGlyph = 0x40;
constexpr size_t bloodGlyph = 0xF7;

constexpr const char* windowTitle = "Dungeon Sandbox v0.015 4/25/2021";

#define MARBLE raylib::Color{ 230, 230, 230, 255 }
#define CHARCOAL raylib::Color{ 25, 25, 25, 255 }
#define CRIMSON raylib::Color{ 220, 20, 60, 255 }

constexpr bool noclipMode = false;

constexpr size_t zoneWidth = 64;
constexpr size_t zoneHeight = 64;
constexpr size_t zoneSize = zoneWidth * zoneHeight;

constexpr size_t mapWidth = 8;
constexpr size_t mapHeight = 8;

constexpr size_t mapSize = mapWidth * mapHeight;

constexpr size_t worldWidth = mapWidth * zoneWidth;
constexpr size_t worldHeight = mapHeight * zoneHeight;

constexpr size_t worldSize = worldWidth * worldHeight;

constexpr int cameraSpeed = 10;

#include <string>
static std::string lastMessage("");

class Zone;
class Cell;

#include <vector>

typedef std::vector<Zone*> zones_y_t;
typedef std::vector<zones_y_t> zones_t;

typedef std::vector<Cell*> cells_y_t;
typedef std::vector<cells_y_t> cells_t;

typedef std::vector<Cell*>::iterator cells_y_iterator;
typedef std::vector<cells_y_t>::iterator cells_x_iterator;

typedef std::vector<bool> solids_t;

#endif
