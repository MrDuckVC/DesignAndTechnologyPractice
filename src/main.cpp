#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu/menu.h"
#include "chess/chess.h"
#include "minesweeper/minesweeper.hpp"
#include "snake/snakeGame.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Games", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(240);

    menu::Menu menu(window);

    menu.addOption("Chess", [&window]() {
        chess::Chess chessGame(window);
        chessGame.Run();
    });
    menu.addOption("Minesweeper", [&window]() {
        minesweeper::Minesweeper minesweeperGame(window);
        minesweeperGame.Run();
    });
    menu.addOption("Snake", [&window]() {
        snake::SnakeGame snake(window);
        snake.Run();
    });
    menu.addOption("Exit", [&window]() { window.close(); });

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (event->is<sf::Event::Resized>()) {
                window.setSize({800, 800});
            }

            menu.handleEvents(*event);
        }

        window.clear();

        menu.draw();

        window.display();
    }

    return 0;
}
