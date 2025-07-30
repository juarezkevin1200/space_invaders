#include "Presentacion.h"

//void Presentacion::draw(){
//    w.draw(SpFondo);
//    for(int i=0;i<20;i++){
//        switch(i){
//    case 1:
//        texto1[i].setString("SPACE INVADERS");
//        break;
//    case 2:
//        texto1[i].setString("DALE CLICK AQUI PARA JUGAR!!!!");
//        break;
//    case 6:
//        texto1[i].setString("TABLA DE PUNTAJE:");
//        break;
//    case 7:
//        texto1[i].setString("?? MISTERIO ");
//        enemigoFondo[3].setTexture(Nave);
//        enemigoFondo[3].setTextureRect(IntRect(750,520,72,72));
//        enemigoFondo[3].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
//        break;
//    case 8:
//        texto1[i].setString("= 30 PUNTOS");
//        enemigoFondo[0].setTexture(Nave);
//        enemigoFondo[0].setTextureRect(IntRect(410,0,72,72));
//        enemigoFondo[0].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
//        break;
//    case 9:
//        texto1[i].setString("= 20 PUNTOS");
//        enemigoFondo[1].setTexture(Nave);
//        enemigoFondo[1].setTextureRect(IntRect(172,0,72,72));
//        enemigoFondo[1].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
//        break;
//    case 10:
//        texto1[i].setString("= 10 PUNTOS");
//        enemigoFondo[2].setTexture(Nave);
//        enemigoFondo[2].setTextureRect(IntRect(0,0,72,72));
//        enemigoFondo[2].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
//        break;
//        }
//        texto1[i].setOrigin(texto1[i].getGlobalBounds().width/2,texto1[i].getGlobalBounds().height/2);
//        texto1[i].setPosition(((float)w.getSize().x/2),80+i*40);
//
//        for(int j=0;j <4;j++)
//        w.draw(enemigoFondo[j]);
//        w.draw(texto1[i]);
//
//    }
//}
//
//
//if(event.type == sf::Event::MouseMoved){
//                MouseVect = sf::Mouse::getPosition(w);
//                MouseVect = (sf::Vector2i)w.mapPixelToCoords(MouseVect);
//                sf::FloatRect MouseRect(Vector2f(MouseVect),{32,32});
//                if(texto1[2].getGlobalBounds().intersects(MouseRect) && texto1[2].getColor() == sf::Color::White){
//
//                      texto1[2].setColor(sf::Color::Red);
//                      sonido.play();
//
//
//                }else if(!texto1[2].getGlobalBounds().intersects(MouseRect) && texto1[2].getColor() == sf::Color::Red ){
//                      texto1[2].setColor(sf::Color::White);
//
//            }
//
//        }


Presentacion::Presentacion(){
    Fondo.loadFromFile("space.png");
    Nave.loadFromFile("sprite_space.png");
    SpFondo.setTexture(Fondo);
        SpNave.setTexture(Nave);
    w.draw(SpFondo);
    for(int i=0;i<20;i++){
        switch(i){
    case 1:
        texto1[i].setString("SPACE INVADERS");
        break;
    case 2:
        texto1[i].setString("DALE CLICK AQUI PARA JUGAR!!!!");
        break;
    case 6:
        texto1[i].setString("TABLA DE PUNTAJE:");
        break;
    case 7:
        texto1[i].setString("?? MISTERIO ");
        enemigoFondo[3].setTexture(Nave);
        enemigoFondo[3].setTextureRect(IntRect(750,520,72,72));
        enemigoFondo[3].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
        break;
    case 8:
        texto1[i].setString("= 30 PUNTOS");
        enemigoFondo[0].setTexture(Nave);
        enemigoFondo[0].setTextureRect(IntRect(410,0,72,72));
        enemigoFondo[0].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
        break;
    case 9:
        texto1[i].setString("= 20 PUNTOS");
        enemigoFondo[1].setTexture(Nave);
        enemigoFondo[1].setTextureRect(IntRect(172,0,72,72));
        enemigoFondo[1].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
        break;
    case 10:
        texto1[i].setString("= 10 PUNTOS");
        enemigoFondo[2].setTexture(Nave);
        enemigoFondo[2].setTextureRect(IntRect(0,0,72,72));
        enemigoFondo[2].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
        break;
        }
        texto1[i].setOrigin(texto1[i].getGlobalBounds().width/2,texto1[i].getGlobalBounds().height/2);
        texto1[i].setPosition(((float)w.getSize().x/2),80+i*40);

        for(int j=0;j <4;j++)
        w.draw(enemigoFondo[j]);
        w.draw(texto1[i]);

    }

}

Presentacion::~Presentacion()
{
    //dtor
}
