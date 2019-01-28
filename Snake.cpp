#include "Snake.h"

Snake::Snake()
{
    m_playerSnake.setFillColor(sf::Color::Green);
    m_playerSnake.setOrigin(m_playerSnake.getRadius(), m_playerSnake.getRadius());
    m_snakeSegments.push_front(startPosition);
}

Snake::~Snake()
{

}

void Snake::Move()
{
    switch(m_direction)
    {
        case EDirection::eNorth:
        m_snakePosition.y-= m_movementStep;
        break;
        case EDirection::eEast:
        m_snakePosition.x+= m_movementStep;
        break;
        case EDirection::eSouth:
        m_snakePosition.y+= m_movementStep;
        break;
        case EDirection::eWest:
        m_snakePosition.x-= m_movementStep;
        break;
    }

    newPosition = m_snakePosition;

    m_snakeSegments.push_front(newPosition);
    if (growAmount > 0)
        growAmount--;
    else
        m_snakeSegments.pop_back();


    if (rand()%30==0)
    {
        ChangeDirection((EDirection)(rand()%4));
    }

    if (m_snakePosition.x>800-m_movementStep)
        ChangeDirection(EDirection::eWest);
    if (m_snakePosition.x<0-m_movementStep)
        ChangeDirection(EDirection::eEast);
    if (m_snakePosition.y>600-m_movementStep)
        ChangeDirection(EDirection::eNorth);
    if (m_snakePosition.y<0-m_movementStep)
        ChangeDirection(EDirection::eSouth);

}

float Snake::GetRadius()
{
    return snakeRadius;
}

sf::Vector2f Snake::GetPosition()
{
    return m_snakePosition;
}

void Snake::ChangeDirection(EDirection newDirection)
{
    m_direction = newDirection;
}

void Snake::Render(sf::RenderWindow& window)
{
    for (auto& s : m_snakeSegments)
    {
        m_playerSnake.setPosition(s.x, s.y);
        window.draw(m_playerSnake);
    }
}
