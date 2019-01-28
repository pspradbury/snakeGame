#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Collectable.h"

class Game
{
    public:
        Game();
        ~Game();
        void Run();

        bool gameOver{false};

        float Length(sf::Vector2f vec);

    protected:

    private:
        unsigned int m_screenWidth{800};
        unsigned int m_screenHeight{600};

        std::vector<Snake> m_snakes;
        Collectable m_collectable[5];

        sf::CircleShape m_sun{40.0f};
        sf::Vector2f m_sunPosition{m_screenWidth/2 - 40, m_screenHeight/2 - 40};

        sf::CircleShape m_planet{20.0f};
        sf::Vector2f m_planetStartPosition{m_screenWidth/2 - 150, m_screenHeight/2 - 40};

        const float sunRadius{40.0f};

        sf::RenderWindow m_window{sf::VideoMode{m_screenWidth, m_screenHeight}, "C++ Snake ICA : T7048738"};
};
#endif // GAME_H
