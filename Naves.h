#ifndef NAVES_H
#define NAVES_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;


class Naves
{

    private:
    // texturas , fuentes y buffers
        sf::Texture enemyslot;
        sf::Sprite SpEnemyslot;
    public:
        Naves(){};
        virtual ~Naves(){};
        void Init();
        sf::Sprite Draw();



};

#endif // NAVES_H
