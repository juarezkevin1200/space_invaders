#ifndef VENTANA_H
#define VENTANA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Naves.h"

using namespace std;
using namespace sf;


class Ventana
{
    private:
        //limite de fps
        size_t fps{60};
        //estado del juego
        bool VentPres{1};
        bool Gameover{0};
        bool disparar{0};
        bool enemigovivo{1};
        int n = 0;
        int vidas = 300;
        bool contador{0};
        bool contador2{0};
        bool contador3{0};
        bool contador4{0};
        bool explo{0};
        //bool contador2 {0};
        int puntaje = 0;
        int puntajemax = 900;
        //velocidad del enemigo
        sf::Vector2f velChar{50,0};
        sf::Vector2f velChar2{3,0};
        //ventana renderwindow
        sf::RenderWindow w;
        //tamaño de la pantalla
        sf::Vector2f tamanio{1366,768};
        // texturas , fuentes y buffers
        sf::Texture Fondo;
        sf::Texture Nave;
        sf::Texture enemy;
        sf::Texture disparo;
        sf::Texture rayo;
        sf::Font fuente1;
        sf::SoundBuffer buffer;
        sf::Clock reloj;
        sf::Clock reloj2;
        sf::Clock reloj3;
        //Naves enemiga;


        //sprites y texto y sonidos
        sf::Sprite SpFondo;
        sf::Sprite SpEnemy[10];
        sf::Sprite enemigo1[10];
        sf::Sprite enemigo2[20];
        sf::Sprite enemigo3[20];
        sf::Sprite enemigoP;
        sf::Sprite SpNave;
        sf::Sprite enemigoFondo[4];
        sf::Sprite SpDisparo;
        sf::Sprite SpRayo;
        sf::Text texto1[20];
        sf::Sound sonido;
        float tiempo;
        float tiempo2;
        float tiempo3;


        //posicion del mouse
        sf::Vector2i MouseVect;
        sf::FloatRect MouseRect;

        //posicion de la nave
        sf::Vector2f charPos;
        sf::Vector2f enemyPos{0,0};

    public:


        Ventana();
        virtual ~Ventana(){};
        void Init();
        void Loop();
        void Presentacion();
        void Game();
        void GameOver();


};

#endif // VENTANA_H
