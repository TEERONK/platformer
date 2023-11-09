
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game() {}

bool Game::init()
{
  // spawns player
  player.initialiseSprite(
    player_texture,
    "Data/Images/kenney_pixelplatformer/Characters/character_0001.png");
  player.getSprite()->setScale(2, 2);
  player.getSprite()->setPosition(
    300 - player.getSprite()->getGlobalBounds().width / 2,
    window.getSize().y / 1.5 -
      player.getSprite()->getGlobalBounds().height / 2);

  // spawns enemy
  enemy.initialiseSprite(
    enemy_texture,
    "Data/Images/kenney_pixelplatformer/Characters/character_0015.png");
  enemy.getSprite()->setScale(2, 2);
  enemy.getSprite()->setPosition(
    300 - enemy.getSprite()->getGlobalBounds().width / 2,
    window.getSize().y / 2.2 - enemy.getSprite()->getGlobalBounds().height / 2);

  // spawns health icon
  health.initialiseSprite(
    health_texture,
    "Data/Images/kenney_pixelplatformer/Characters/character_0001.png");
  health.getSprite()->setScale(2, 2);
  health.getSprite()->setPosition(
    window.getSize().x - health.getSprite()->getGlobalBounds().width,
    window.getSize().y / 15 - health.getSprite()->getGlobalBounds().height / 2);

  // flower spawn
  for (int i = 0; i < 5; i++)
  {
    flower[i].initialiseSprite(
      flower_texture,
      "Data/Images/kenney_pixelplatformer/Characters/character_0002.png");
    flower[i].getSprite()->setScale(2.5, 2.5);
    if (i == 0)
    {
      flower[i].getSprite()->setPosition(100, 550);
    }
    else if (i == 1)
    {
      flower[i].getSprite()->setPosition(400, 550);
    }
    else if (i == 2)
    {
      flower[i].getSprite()->setPosition(600, 430);
    }
    else if (i == 3)
    {
      flower[i].getSprite()->setPosition(650, 430);
    }
    else if (i == 4)
    {
      flower[i].getSprite()->setPosition(700, 430);
    }
  }

  // spawn platforms
  for (int i = 0; i < 7; i++)
  {
    platform[i].initialiseSprite(
      platform_texture,
      "Data/Images/kenney_physicspack/PNG/Stone elements/elementStone016.png");
    platform[i].getSprite()->setScale(0.5, 0.5);
    if (i == 0)
    {
      platform[i].getSprite()->setPosition(110, 600);
    }
    else if (i == 1)
    {
      platform[i].getSprite()->setPosition(
        platform[i - 1].getSprite()->getPosition().x + 110, 600);
    }
    else if (i == 2)
    {
      platform[i].getSprite()->setPosition(
        platform[i - 1].getSprite()->getPosition().x + 110, 600);
    }
    else if (i == 3)
    {
      platform[i].getSprite()->setPosition(
        platform[i - 1].getSprite()->getPosition().x + 1, 350);
    }
    else if (i == 4)
    {
      platform[i].getSprite()->setPosition(
        platform[i - 1].getSprite()->getPosition().x + -110, 350);
    }
    else if (i == 5)
    {
      platform[i].getSprite()->setPosition(
        platform[i - 1].getSprite()->getPosition().x + 350, 480);
    }
    else if (i == 6)
    {
      platform[i].getSprite()->setPosition(
        platform[i - 1].getSprite()->getPosition().x + 110, 480);
    }
  }

  // initialising background
  if (!background_texture.loadFromFile("Data/Images/kenney_physicspack/PNG/"
                                       "Backgrounds/blue_grass.png"))
  {
    std::cout << "background did not load \n";
  }
  background.setTexture(background_texture);
  background.setScale(1.2, 1);

  // init menu text
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  title_text.setString("THAT PLATFORMER");
  title_text.setFont(font);
  title_text.setCharacterSize(70);
  title_text.setFillColor(sf::Color(150, 200, 255, 150));
  title_text.setPosition(
    window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 - title_text.getGlobalBounds().height / 2);

  // init menu text
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  select_option.setString("Press enter to select an option");
  select_option.setFont(font);
  select_option.setCharacterSize(15);
  select_option.setFillColor(sf::Color(150, 200, 255, 120));
  select_option.setPosition(
    window.getSize().x / 2 - select_option.getGlobalBounds().width / 2,
    window.getSize().y / 5 - select_option.getGlobalBounds().height / 2);

  // init menu text
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  play_option.setString("Play");
  play_option.setFont(font);
  play_option.setCharacterSize(20);
  play_option.setFillColor(sf::Color(100, 200, 255, 255));
  play_option.setPosition(
    window.getSize().x / 4 - play_option.getGlobalBounds().width / 2,
    window.getSize().y / 2 - play_option.getGlobalBounds().height / 2);

  // init menu text
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  quit_option.setString("Quit");
  quit_option.setFont(font);
  quit_option.setCharacterSize(20);
  quit_option.setFillColor(sf::Color(100, 200, 255, 255));
  quit_option.setPosition(
    (window.getSize().x / 4 - quit_option.getGlobalBounds().width / 2) * 3,
    window.getSize().y / 2 - quit_option.getGlobalBounds().height / 2);

  // score text
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  score_text.setString(std::to_string(score));
  score_text.setFont(font);
  score_text.setCharacterSize(70);
  score_text.setFillColor(sf::Color(150, 200, 255, 150));
  score_text.setPosition(
    window.getSize().x / 2 - score_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 - score_text.getGlobalBounds().height / 2);

  // init win text
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  win_text.setString("YOU WIN, PLAY AGAIN?");
  win_text.setFont(font);
  win_text.setCharacterSize(70);
  win_text.setFillColor(sf::Color(150, 200, 255, 150));
  win_text.setPosition(
    window.getSize().x / 2 - win_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 - win_text.getGlobalBounds().height / 2);

  // init lose text
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  lose_text.setString("YOU LOSE, PLAY AGAIN?");
  lose_text.setFont(font);
  lose_text.setCharacterSize(70);
  lose_text.setFillColor(sf::Color(150, 200, 255, 150));
  lose_text.setPosition(
    window.getSize().x / 2 - lose_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 - lose_text.getGlobalBounds().height / 2);

  return true;
}

void Game::update(float dt)
{
  // collsion with platform
  for (int i = 0; i < 7; i++)
  {
    if (!detectCollison(*player.getSprite(), *platform[i].getSprite()))
    {
      player.direction.y = 1;
    }
    else if (detectCollison(*player.getSprite(), *platform[i].getSprite()))
    {
      player.direction.y = 0;
      break;
    }
    else (jump_counter = 10);
    {
      if (jump)
      {
        gravity = 0;
        player.getSprite()->move(0, -1);
        jump_counter++;
      }
      else
      {
        gravity      = 200;
        jump_counter = 0;
      }
    }
  }

  // collision with flower
  for (int i = 0; i < 5; i++)
  {
    if (flower[i].visibility)
    {
      if (detectCollison(*player.getSprite(), *flower[i].getSprite()))
      {
        score++;
        score_text.setString(std::to_string(score));
        flower[i].visibility = false;
      }
    }
  }

  // collision with enemy
  if (health.visibility)
  {
    if (detectCollison(*player.getSprite(), *enemy.getSprite()))
    {
      health.visibility = false;
      in_menu           = 3;
    }
  }

  if (score == 5)
  {
    in_menu = 2;
  }

  // stops player from going off-screen
  if (
    player.getSprite()->getPosition().x >=
    (window.getSize().x - player.getSprite()->getGlobalBounds().width))
  {
    velocity = 0;
    player.getSprite()->move(-1, 0);
  }
  if ((player.getSprite()->getPosition().x <= 0))
  {
    velocity = 0;
    player.getSprite()->move(1, 0);
  }
  player.getSprite()->move(
    player.direction.x * velocity * dt, player.direction.y * gravity * dt);
}

bool Game::detectCollison(sf::Sprite& player2, sf::Sprite& objects)
{
  {
    if (
      player2.getPosition().x <=
        objects.getPosition().x + objects.getGlobalBounds().width &&
      objects.getPosition().x <=
        player2.getPosition().x + player2.getGlobalBounds().width &&
      player2.getPosition().y <=
        objects.getPosition().y + objects.getGlobalBounds().height &&
      objects.getPosition().y <=
        player2.getPosition().y + player2.getGlobalBounds().height)
    {
      return true;
    }
  }
  return false;
}

void Game::render()
{
  if (in_menu == 0)
  {
    window.draw(background);
    window.draw(title_text);
    window.draw(select_option);
    window.draw(play_option);
    window.draw(quit_option);
  }
  else if (in_menu == 1)
  {
    window.draw(background);
    window.draw(*player.getSprite());
    for (int i = 0; i < 7; i++)
    {
      window.draw(*platform[i].getSprite());
    }
    for (int i = 0; i < 5; i++)
    {
      if (flower[i].visibility)
      {
        window.draw(*flower[i].getSprite());
      }
    }
    if (health.visibility)
    {
      window.draw(*health.getSprite());
    }
    window.draw(*enemy.getSprite());
    window.draw(score_text);
  }
  else if (in_menu == 2)
  {
    window.draw(background);
    window.draw(win_text);
    window.draw(play_option);
    window.draw(quit_option);
  }
  else if (in_menu == 3)
  {
    window.draw(background);
    window.draw(lose_text);
    window.draw(play_option);
    window.draw(quit_option);
  }
}

void Game::mouseClicked(sf::Event event)
{}

void Game::keyPressed(sf::Event event)
{
  if (in_menu == 0 || in_menu == 2 || in_menu == 3)
  {
    if (
      (event.key.code == sf::Keyboard::Left) ||
      (event.key.code == sf::Keyboard::Right))
    {
      play_selected = !play_selected;
      if (play_selected)
      {
        play_option.setString("Play <");
        quit_option.setString("Quit");
      }
      else
      {
        play_option.setString("Play");
        quit_option.setString("Quit <");
      }
    }
    if (event.key.code == sf::Keyboard::Enter)
    {
      if (play_selected)
      {
        score = 0;
        score_text.setString("0");
        player.getSprite()->setPosition(
          300 - player.getSprite()->getGlobalBounds().width / 2,
          window.getSize().y / 1.5 -
            player.getSprite()->getGlobalBounds().height / 2);
        for (int i = 0; i < 5; i++)
        {
          flower[i].visibility = true;
        }
        health.visibility = true;
        in_menu           = 1;
      }
      else
      {
        window.close();
      }
    }
  }

  if (event.key.code == sf::Keyboard::Escape)
  {
    window.close();
  }

  if (in_menu == 1)
  {
    // player movement
    if (event.key.code == sf::Keyboard::D)
    {
      player.direction.x = 1;
    }
    if (event.key.code == sf::Keyboard::A)
    {
      player.direction.x = -1;
    }
    if (event.key.code == sf::Keyboard::Space)
    {
      jump = true;
      gravity = 0;
    }
  }
}

//  also player movement (player only moves when pressing A or D)
void Game::keyReleased(sf::Event event)
{
  if (event.key.code == sf::Keyboard::D)
  {
    player.direction.x = 0;
  }
  if (event.key.code == sf::Keyboard::A)
  {
    player.direction.x = 0;
  }
  if (event.key.code == sf::Keyboard::Space)
  {
    gravity      = 200;
    jump_counter = 0;
    jump = false;
  }
}
