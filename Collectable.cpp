#include "Collectable.h"

Collectable::Collectable()
{
    m_collectable.setPosition(m_collectablePosition.x, m_collectablePosition.y);
    m_collectable.setOrigin(m_collectable.getRadius(), m_collectable.getRadius());
    m_collectable.setFillColor(sf::Color::Red);
}

Collectable::~Collectable()
{

}

void Collectable::SetPosition(float x, float y)
{
    m_collectablePosition.x = x;
    m_collectablePosition.y = y;
}

sf::Vector2f Collectable::GetPosition()
{
    return m_collectablePosition;
}

bool Collectable::IsAlive()
{
    return alive;
}

void Collectable::SetAlive(bool SetActive)
{
    alive = SetActive;
    m_collectablePosition.x = rand()%(800/10)*10;
    m_collectablePosition.y = rand()%(600/10)*10;
    m_collectable.setPosition(m_collectablePosition.x, m_collectablePosition.y);
}

void Collectable::CheckCollision(Collectable& other, int screenWidth, int screenHeight)
{
    if (m_collectablePosition == other.GetPosition())
    {
        m_collectablePosition.x = rand()%screenWidth;
        m_collectablePosition.y = rand()%screenHeight;
        m_collectable.setPosition(m_collectablePosition.x, m_collectablePosition.y);
    }
}

void Collectable::SetScore(int x)
{
    score = x;
}

int Collectable::GetScore()
{
    return score;
}

void Collectable::Render(sf::RenderWindow& window)
{
    if (alive)
    {
        window.draw(m_collectable);
    }
}
