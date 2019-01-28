#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include <SFML/Graphics.hpp>

class Collectable
{
    public:
        Collectable();
        ~Collectable();

        bool IsAlive();
        void SetAlive (bool SetActive);

        void SetPosition(float x, float y);
        sf::Vector2f GetPosition();

        void SetScore(int x);
        int GetScore();

        void CheckCollision(Collectable& other, int screenWidth, int screenHeight);

        void Render(sf::RenderWindow& window);

    protected:

    private:
        int score;
        bool alive{false};
        sf::Vector2f m_collectablePosition;
        sf::CircleShape m_collectable{5.0f};
};
#endif // COLLECTABLE_H
