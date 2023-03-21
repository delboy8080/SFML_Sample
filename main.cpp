// Sample program main.cpp
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;
struct ball
{
    int x, y;
    int moveXBy = 1;
    int moveYBy = 1;
    int id ;
    int cellSize;
    sf::CircleShape shape;
    ball(int i, int cellSize)
    {
        shape.setRadius(10);
        shape.setFillColor(sf::Color::Blue);
        x = rand()%8;
        y = rand()%8;
        id = i;
        this->cellSize = cellSize;
    }
    void move()
    {
        x+= moveXBy;
        y+=moveYBy;

        if(x >=8||x == 0)
        {
            moveXBy *= -1;
        }
        if(y >= 8||y == 0)
        {
            moveYBy *= -1;
        }
        cout <<id <<":" << x << " " << y << endl;
    }

    void draw(sf::RenderWindow &window)
    {
        shape.setPosition(x * cellSize, y*cellSize);
        window.draw(shape);
    }
};
int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
//    sf::CircleShape shape(10.f);
//    window.setFramerateLimit(40);
//    shape.setPosition(195, 195);
//    shape.setFillColor(sf::Color::Green);
//    int moveXBy = 5;
//    int moveYBy = 5;
//    bool isGreen = true;
     vector<ball> balls;
     for(int i  = 0; i < 3; i++) {
         balls.push_back(ball(i, 50));
     }
    int size = 8;
     vector<sf::RectangleShape> board;
     bool blk = true;
    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {
            sf::RectangleShape rect(sf::Vector2f(50,50));
            rect.setPosition(x*50, y*50);
            if(blk)
            {
                rect.setFillColor(sf::Color::Black);

            }
            else
            {
                rect.setFillColor(sf::Color::White);
            }
            blk = !blk;
            board.push_back(rect);
        }
        blk = !blk;
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    for(ball &b: balls) {
                        b.move();
                    }
                }

            }
            if(event.type == sf::Event::KeyReleased)
            {
                cout << event.key.code << endl;
                cout << sf::Keyboard::C << endl;
                if(event.key.code == sf::Keyboard::Up)
                {
                    for(ball &b: balls) {
                        b.move();
                    }
                }
            }
//            if(event.type == sf::Event::MouseButtonReleased)
//            {
//                if(event.mouseButton.button == sf::Mouse::Left)
//                {
//                    if(isGreen)
//                    {
//                        shape.setFillColor(sf::Color::Red);
//                        isGreen=false;
//                    }
//                    else
//                    {
//                        shape.setFillColor(sf::Color::Green);
//                        isGreen=true;
//                    }
//                }
//            }

        }
//        shape.move(moveXBy, moveYBy);
//        if(shape.getPosition().x >=380 ||shape.getPosition().x <5 )
//        {
//            moveXBy*=-1;
//        }
//        if(shape.getPosition().y >=380 ||shape.getPosition().y <10 )
//        {
//            moveYBy*=-1;
//        }

        window.clear(sf::Color::White);
        for(sf::RectangleShape &rect : board)
        {
            window.draw(rect);
        }

        for(ball &b: balls) {

            b.draw(window);
        }
        window.display();

    }

    return 0;
}
