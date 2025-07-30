#include "Naves.h"



void Naves::Init()
{
    enemyslot.loadFromFile("nave.png");
    SpEnemyslot.setTexture(enemyslot);
    SpEnemyslot.setPosition({500,500});
}

sf::Sprite Naves::Draw()
{
    return SpEnemyslot;
}


