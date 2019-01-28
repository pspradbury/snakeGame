#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <list>

enum class EDirection
{
    eNorth,
    eEast,
    eSouth,
    eWest
};

class Snake
{
    public:
        Snake();
        virtual ~Snake();

        void Move();
        void Render(sf::RenderWindow& window);
        void ChangeDirection(EDirection newDirection);

        float GetRadius();

        bool CheckSelfCollision() const;
        sf::Vector2f GetPosition();
        int growAmount{0};

    protected:

    private:
        std::list<sf::Vector2f> m_snakeSegments;
        sf::Vector2f startPosition{300,200};
        sf::Vector2f newPosition;
        sf::Vector2f m_snakePosition{300,200};

        const float snakeRadius{10.0f};
        const float m_movementStep{10.0f};
        EDirection m_direction{EDirection::eSouth};
        sf::CircleShape m_playerSnake{m_movementStep};
};
#endif // SNAKE_H
