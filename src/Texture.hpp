#ifndef texture_hpp
#define texture_hpp

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

// source : https://lazyfoo.net/tutorials/SDL/10_color_keying/index.php
// Texture wrapper class
class Texture
{
public:
    Texture();
    Texture(SDL_Renderer *renderer);
    ~Texture();

    Texture *loadFromFile(const char *path);
    Texture *loadFromRenderedText(TTF_Font *font, const char *text, SDL_Color textColor);
    void free();
    void render(SDL_Rect renderBox);

    int getWidth();
    int getHeight();
    void setSize(int width, int height);
    int getCenterX();
    int getCenterY();
    int getId();

private:
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    int width, height;
    int id;
};

#endif