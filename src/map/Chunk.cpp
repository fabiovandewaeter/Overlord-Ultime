#include "Chunk.hpp"

Chunk::Chunk(int positionX, int positionY, int tileSize, Texture *tileTextures, Texture *staticObjectTextures)
{
    this->positionX;
    this->positionY;
    this->tileSize = tileSize;
    this->tileTextures = tileTextures;
    this->staticObjectTextures = staticObjectTextures;
    this->box = (SDL_Rect){positionX, positionY, tileSize * SIZE, tileSize * SIZE};
    loadTiles();
    loadStaticObjects();
}
Chunk::~Chunk()
{
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        delete this->allTiles[i];
    }
    for (auto &pair : this->allStaticObjects)
    {
        delete pair.second;
    }
}

void Chunk::loadTiles()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            this->allTiles[SIZE * i + j] = new Tile(&this->tileTextures[0], (SDL_Rect){i * this->tileSize + this->box.x, j * this->tileSize + this->box.y, this->tileSize, this->tileSize});
        }
    }
}
void Chunk::loadStaticObjects()
{
    int i = 2, j = 0;
    std::string coordinates = std::to_string(i) + "," + std::to_string(j);
    this->allStaticObjects[coordinates] = new Wall(&this->staticObjectTextures[0], (SDL_Rect){i * this->tileSize + this->box.x, j * this->tileSize + this->box.y, this->tileSize, this->tileSize});
    i++;
    i++;
    coordinates = std::to_string(i) + "," + std::to_string(j);
    this->allStaticObjects[coordinates] = new Wall(&this->staticObjectTextures[1], (SDL_Rect){i * this->tileSize + this->box.x, j * this->tileSize + this->box.y, this->tileSize, this->tileSize});
    i++;
    i++;
    int x = 2 * this->tileSize, y = 0 * this->tileSize;
    //convertToTileCoordinates(x, y);
}

void Chunk::render(SDL_Renderer *renderer, Camera *camera)
{
    SDL_Rect renderBox = this->box;
    camera->convertInGameToCameraCoordinates(renderBox);
    if (camera->isVisible(renderBox))
    {
        for (int i = 0; i < SIZE * SIZE; i++)
        {
            this->allTiles[i]->render(renderer, camera);
        }
    }
    for (auto &pair : this->allStaticObjects)
    {
        pair.second->render(renderer, camera);
    }
}

void Chunk::convertToTileCoordinates(int &x, int &y)
{
    x = static_cast<int>(std::floor(static_cast<float>(x) / this->tileSize)) % SIZE;
    y = static_cast<int>(std::floor(static_cast<float>(y) / this->tileSize)) % SIZE;
    if (x < 0)
    {
        x = SIZE + x;
    }
    if (y < 0)
    {
        y = SIZE + y;
    }
}
// returns the tile that contains the coordinates
Tile *Chunk::getTile(int x, int y)
{
    int i = x, j = y;
    convertToTileCoordinates(i, j);
    return this->allTiles[SIZE * i + j];
}
bool Chunk::isStaticObject(int x, int y)
{
    int i = x, j = y;
    convertToTileCoordinates(i, j);
    std::string coordinates = std::to_string(i) + "," + std::to_string(j);
    if (this->allStaticObjects.find(coordinates) == this->allStaticObjects.end())
    {
        return false;
    }
    return true;
}
StaticObject *Chunk::getStaticObject(int x, int y)
{
    int i = x, j = y;
    convertToTileCoordinates(i, j);
    std::string coordinates = std::to_string(i) + "," + std::to_string(j);
    return this->allStaticObjects[coordinates];
}