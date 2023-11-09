
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  bool detectCollison(sf::Sprite& player2, sf::Sprite& platform);

 private:
  sf::RenderWindow& window;

  GameObject player;
  sf::Texture player_texture;

  GameObject health;
  sf::Texture health_texture;

  GameObject enemy;
  sf::Texture enemy_texture;

  GameObject platform[7];
  sf::Texture platform_texture;

  GameObject flower[5];
  sf::Texture flower_texture;

  sf::Font font;

  sf::Sprite background;
  sf::Texture background_texture;

  int in_menu = 0;
  sf::Text title_text;
  sf::Text play_option;
  sf::Text quit_option;
  sf::Text select_option;
  sf::Text score_text;
  sf::Text win_text;
  sf::Text lose_text;
  int score = 0;
  bool play_selected = true;
  bool jump;

  float velocity = 300;
  float gravity = 200;
  int jump_counter;
};

#endif // PLATFORMER_GAME_H
