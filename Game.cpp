#include "Game.h"
#include "Snake.h"
#include "Collectable.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Run()
{
    srand(time(NULL));

    std::cout << "Starting" << std::endl;

    m_sun.setFillColor(sf::Color::Yellow);
    m_sun.setPosition(m_sunPosition);

    m_planet.setFillColor(sf::Color::Blue);


    sf::Clock clock;

    m_snakes.push_back(Snake());
    m_snakes.push_back(Snake());


    while (m_window.isOpen() && !gameOver)
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
          switch(event.type)
          {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Left:
                        m_snakes[0].ChangeDirection(EDirection::eWest);
                        std::cout << "Player 1 Moving West" << std::endl;
                        break;
                    case sf::Keyboard::Right:
                        m_snakes[0].ChangeDirection(EDirection::eEast);
                        std::cout << "Player 1 Moving East" << std::endl;
                        break;
                    case sf::Keyboard::Up:
                        m_snakes[0].ChangeDirection(EDirection::eNorth);
                        std::cout << "Player 1 Moving North" << std::endl;
                        break;
                    case sf::Keyboard::Down:
                        m_snakes[0].ChangeDirection(EDirection::eSouth);
                        std::cout << "Player 1 Moving South" << std::endl;
                        break;
                    case sf::Keyboard::A:
                        m_snakes[1].ChangeDirection(EDirection::eWest);
                        std::cout << "Player 2 Moving West" << std::endl;
                        break;
                    case sf::Keyboard::D:
                        m_snakes[1].ChangeDirection(EDirection::eEast);
                        std::cout << "Player 2 Moving East" << std::endl;
                        break;
                    case sf::Keyboard::W:
                        m_snakes[1].ChangeDirection(EDirection::eNorth);
                        std::cout << "Player 2 Moving North" << std::endl;
                        break;
                    case sf::Keyboard::S:
                        m_snakes[1].ChangeDirection(EDirection::eSouth);
                        std::cout << "Player 2 Moving South" << std::endl;
                        break;

                    default:
                        break;
                }
                break;
            default:
                break;
          }
        }

        for (Collectable& n : m_collectable)
        {
            if (rand()%50==0)
            {
                if (n.IsAlive() != true)
                {
                    n.SetAlive(true);
                    n.SetScore(rand()%2+1);
                }
            }
        }

        for (int i=0; i<5; i++)
        {
            for (int p=0; p<5; p++)
            {
                if (m_collectable[i].IsAlive() == true && i != p)
                {
                    m_collectable[i].CheckCollision(m_collectable[p], m_screenWidth, m_screenHeight);
                }
            }

            if (m_collectable[i].GetPosition() == m_snakes[0].GetPosition() && m_collectable[i].IsAlive())
            {
                m_collectable[i].SetAlive(false);
                m_snakes[0].growAmount = m_collectable[i].GetScore();
            }
        }

        for(Snake& s : m_snakes)
        {
            s.Move();
        }

        sf::Vector2f m_planetNewPosition = m_planetStartPosition - m_sunPosition;
        m_planetStartPosition.x = m_planetNewPosition.x * cos(0.1f) - m_planetNewPosition.y * sin(0.1f);
        m_planetStartPosition.y = m_planetNewPosition.y * cos(0.1f) + m_planetNewPosition.x * sin(0.1f);
        m_planetStartPosition += m_sunPosition;

        for (Snake& s : m_snakes)
        {
            sf::Vector2f vec = m_sunPosition - s.GetPosition();
            if (sunRadius + s.GetRadius() > Length(vec))
            {
                gameOver = true;
            }
        }

        m_window.clear();


        for (Snake& s : m_snakes)
            s.Render(m_window);

        for (Collectable& r : m_collectable)
        {
            if (r.IsAlive() != false)
            {
                r.Render(m_window);
            }
        }

        m_window.draw(m_sun);

        m_planet.setPosition(m_planetStartPosition);
        m_window.draw(m_planet);

        m_window.display();

        while (clock.getElapsedTime().asMilliseconds()<100);
        clock.restart();
    }

    std::cout << "Finished" << std::endl;
}

float Game::Length(sf::Vector2f vec)
{
    float total = sqrt((vec.x * vec.x) + (vec.y * vec.y));
    return total;
}
