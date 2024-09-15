#ifndef map_hpp
#define map_hpp

#define TILE_SIZE 16
#define CHUNK_SIZE 16

#include <vector>
#include <unordered_map>
#include <cmath>
#include "Tile.hpp"
#include "Chunk.hpp"
#include "../systems/Camera.hpp"
#include "../systems/TextureManager.hpp"
#include "../systems/PerlinNoise.hpp"

class Map
{
public:
    Map();
    ~Map();

    void init(Camera *camera, std::vector<Texture *> *tileTextures, std::vector<Texture *> *staticObjectTextures, std::vector<Texture *> *structureTextures, PerlinNoise *perlinNoise);
    void loadChunks();
    void generateChunk(int positionX, int positionY);
    void loadSquareMap(int size);
    void render();
    void free();

    bool isChunkGenerated(int x, int y);
    Chunk *getChunk(int x, int y);

private:
    Camera *camera;
    std::vector<Texture *> *tileTextures;
    std::vector<Texture *> *staticObjectTextures;
    std::vector<Texture *> *structureTextures;
    PerlinNoise *perlinNoise;
    std::unordered_map<std::string, Chunk *> allChunks;
    std::vector<Chunk *> nearbyChunks;

    void convertToChunkCoordinates(int &x, int &y);
};

#endif