//
// Created by tariq on 15/04/2023.
//

#ifndef PLATFORMERSFML_GAMEOBJECT_H
#define PLATFORMERSFML_GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"


class GameObject
{
 public:
  GameObject();
  ~GameObject();

  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();
  Vector2 direction;
  bool visibility = true;

 private:
  sf::Sprite* sprite = nullptr;
};

#endif // PLATFORMERSFML_GAMEOBJECT_H
