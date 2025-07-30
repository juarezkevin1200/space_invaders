#include "Ventana.h"
//#include <windows.h>
#include <string>

void Ventana::GameOver(){
    w.draw(SpFondo);
    texto1[12].setString("Puntaje Total: " + to_string(puntaje));
    texto1[12].setPosition({200,300});
    w.draw(texto1[12]);
    texto1[12].setString("Presiona Enter para volver a jugar");
    texto1[12].setPosition({200,350});
    w.draw(texto1[12]);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        puntaje = 0;
        vidas = 5;
        fps = 60;
        Gameover = 0;
    }
    texto1[12].setString("Presiona Escape para salir");
    texto1[12].setPosition({200,400});
    w.draw(texto1[12]);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        w.close();
    }

}


void Ventana::Game(){
    w.clear();
    w.draw(SpFondo);
    w.draw(SpNave);
    for(int i=0;i<10;i++){
        w.draw(enemigo1[i]);
    }
    for(int i=0;i<20;i++){
        w.draw(enemigo2[i]);
    }
    for(int i=0;i<20;i++){
        w.draw(enemigo3[i]);
    }

        w.draw(enemigoP);
    tiempo =  reloj.getElapsedTime().asSeconds();
    tiempo2 = reloj2.getElapsedTime().asSeconds();
    tiempo3 = reloj3.getElapsedTime().asSeconds();
    ///////////////////////////////////////
    if(puntaje >= puntajemax){
        for(int i{0};i<=10;i++){
            enemigo1[i].setColor(sf::Color::White);
        }
        for(int i{0};i<=20;i++){
            enemigo2[i].setColor(sf::Color::White);
        }
        for(int i{0};i<=20;i++){
            enemigo3[i].setColor(sf::Color::White);
        }
        enemigoP.setColor(sf::Color::White);
        vidas += 1;
        puntajemax += 900;
    }
    ////////////////////////////////////
    //limita la nave de no pasar los bordes de la pantalla
    charPos = SpNave.getPosition();
    if(charPos.x <0){
        charPos.x = 0;

    }
    if(charPos.x >((float)w.getSize().x-0.28*SpNave.getTexture()->getSize().x)){
        charPos.x = ((float)w.getSize().x-0.28*SpNave.getTexture()->getSize().x);

    }
    SpNave.setPosition(charPos);

    ///////////////////////////////////////
    //mueve la nave a la derecha o a la izquierda
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        SpNave.move(-5,0);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        SpNave.move(5,0);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
    for(int i{0};i<=20;i++)
            cout << "gameover" << endl;
            cout << puntaje << endl;
    exit(1);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        //el disparo se localiza en donde se presion� space
        SpDisparo.setPosition({charPos.x+50,charPos.y});
        SpDisparo.setColor(sf::Color::White);



    }

    ////////////////////////////
    //cambia la imagen del enemigo como si estuviera caminando
    if(tiempo >= 0.5){
    for (int i=0;i<10;i++){
         enemigo1[i].setTextureRect(IntRect(422,14,60,50));
      }
      for (int i=0;i<20;i++){
         enemigo2[i].setTextureRect(IntRect(266,14,60,50));
      }
      for (int i=0;i<20;i++){
         enemigo3[i].setTextureRect(IntRect(100,14,60,50));
      }

    }
    //cambia la imagen del enemigo como si estuviera caminando

    if(tiempo >= 1.0){
       for (int i=0;i<10;i++){
         enemigo1[i].setTextureRect(IntRect(351,14,60,50));
      }
       for (int i=0;i<20;i++){
         enemigo2[i].setTextureRect(IntRect(180,14,60,50));
      }
       for (int i=0;i<20;i++){
         enemigo3[i].setTextureRect(IntRect(12,14,60,50));
      }
    ////////////////////////////////////
    //rebota las naves infinitamente

      for(int i=0;i<10;i++){

    enemyPos = enemigo1[i].getPosition();
    if(enemyPos.x <0){
        charPos.x = 0;
        velChar.x *= -1;
        fps+=10;



    }
    float valor =enemigo1[i].getTexture()->getSize().x;
    valor = valor/10;
    float tamanio = ((float)w.getSize().x);
    if(enemyPos.x > tamanio-valor){
        charPos.x = tamanio;
        velChar.x *= -1;
        fps+=10;


    }
    enemigo1[i].setPosition(enemyPos);


    }

    for(int i=0;i<10;i++){
        enemigo1[i].move(velChar);

    }
    for(int i=0;i<20;i++){
        enemigo2[i].move(velChar);
    }
    for(int i=0;i<20;i++){
        enemigo3[i].move(velChar);
    }


    }
    enemigoP.move({velChar2.x,0});

    w.setFramerateLimit(fps);
    //reinicia el contador para que siga caminando
    if(tiempo >= 1.0){
        reloj.restart();
    }
    ////////////////

    //mueve la bala con una velocidad de 15 cuadros 15 cuadros * 60 fps
    w.draw(SpDisparo);
    SpDisparo.move(0,-15);
    //mueve el rayo con una velocidad de 15 cuadros 15 cuadros * 60 fps
    w.draw(SpRayo);
    SpRayo.move(0,15);
    ////////////////////////////
    if(tiempo2 >= 15){
        enemigoP.setPosition({0,0});
        reloj2.restart();
    }
    ///////////////////////////
    if(tiempo3 >= 1){
        int random = rand() % 10;
        int random2 = rand() % 5 + 1;

        switch(random2){
        case 1:
            if(enemigo1[random].getColor() == sf::Color::White){
        SpRayo.setPosition({enemigo1[random].getPosition().x+20,enemigo1[random].getPosition().y+10});
        }break;
        case 2:
            if(enemigo2[random].getColor() == sf::Color::White){
        SpRayo.setPosition({enemigo2[random].getPosition().x+20,enemigo2[random].getPosition().y+10});
        }break;
        case 3:
            if(enemigo2[random+10].getColor() == sf::Color::White){
        SpRayo.setPosition({enemigo2[random].getPosition().x+20,enemigo2[random].getPosition().y+10});
        }break;
        case 4:
            if(enemigo3[random].getColor() == sf::Color::White){
        SpRayo.setPosition({enemigo3[random].getPosition().x+20,enemigo3[random].getPosition().y+10});
        }break;
        case 5:
            if(enemigo3[random+10].getColor() == sf::Color::White){
        SpRayo.setPosition({enemigo3[random].getPosition().x+20,enemigo3[random].getPosition().y+10});
        }break;
        }
        reloj3.restart();
    }

    ////////////////////////////
    //contador de vidas del jugador

    sf::FloatRect RayoRect = SpRayo.getGlobalBounds();
    sf::FloatRect NaveRect = SpNave.getGlobalBounds();
        if(NaveRect.intersects(RayoRect)){
               contador = 1;
        }else if(!NaveRect.intersects(RayoRect) && contador  == 1){
               vidas --;
               contador = 0;
        }

        if(vidas <= 0){
            Gameover = 1;


        }

    /////////////////////////////

    //////////////////////
    //cuando muere un enemigo
    sf::FloatRect charRect = SpDisparo.getGlobalBounds();

    sf::FloatRect BallRect = enemigoP.getGlobalBounds();
    if(charRect.intersects(BallRect) && SpDisparo.getColor() == Color::White && enemigoP.getColor() == Color::White){
                enemigoP.setColor(Color::Transparent);
                SpDisparo.setColor(Color::Transparent);
                puntaje += 100;


        }

    for(int i=0;i<10;i++){
        sf::FloatRect BallRect = enemigo1[i].getGlobalBounds();
        if(charRect.intersects(BallRect) && SpDisparo.getColor() == sf::Color::White && enemigo1[i].getColor() == sf::Color::White){
                enemigo1[i].setColor(sf::Color::Transparent);
                SpDisparo.setColor(sf::Color::Transparent);
                puntaje += 30;


        }
    }

    for(int i=0;i<20;i++){
        sf::FloatRect BallRect = enemigo2[i].getGlobalBounds();
        if(charRect.intersects(BallRect) && SpDisparo.getColor() == sf::Color::White && enemigo2[i].getColor() == sf::Color::White){
                enemigo2[i].setColor(sf::Color::Transparent);
                SpDisparo.setColor(sf::Color::Transparent);
                puntaje += 20;

        }
    }

    for(int i=0;i<20;i++){
        sf::FloatRect BallRect = enemigo3[i].getGlobalBounds();
        if(charRect.intersects(BallRect) && SpDisparo.getColor() == sf::Color::White && enemigo3[i].getColor() == sf::Color::White){
                enemigo3[i].setColor(sf::Color::Transparent);
                SpDisparo.setColor(sf::Color::Transparent);
                puntaje += 10;
        }
    }

//////////////////////////////
texto1[12].setString("puntaje: " + to_string(puntaje));
texto1[12].setPosition({0,0});
texto1[13].setString("vidas: "+ to_string(vidas));
texto1[13].setPosition({0,720});
w.draw(texto1[12]);
w.draw(texto1[13]);







}


void Ventana::Presentacion(){
    w.clear();
    w.draw(SpFondo);
   // w.draw(enemiga.Draw());


    for(int i=0;i<20;i++){
        switch(i){
    case 1:
        texto1[i].setString("SPACE INVADERS ");
        break;
    case 2:
        texto1[i].setString("DALE CLICK AQUI PARA JUGAR!!!!");
        break;
    case 6:
        texto1[i].setString("TABLA DE PUNTAJE:");
        break;
    case 7:
        texto1[i].setString("?? MISTERIO ");
        enemigoFondo[3].setTexture(enemy);
        enemigoFondo[3].setTextureRect(IntRect(750,520,72,72));
        enemigoFondo[3].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
        break;
    case 8:
        texto1[i].setString("= 30 PUNTOS");
        enemigoFondo[0].setTexture(enemy);
        enemigoFondo[0].setTextureRect(IntRect(410,0,72,72));
        enemigoFondo[0].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
        break;
    case 9:
        texto1[i].setString("= 20 PUNTOS");
        enemigoFondo[1].setTexture(enemy);
        enemigoFondo[1].setTextureRect(IntRect(172,0,72,72));
        enemigoFondo[1].setPosition(((float)w.getSize().x/2)-300,80+(i-1)*40);
        break;
    case 10:
        texto1[i].setString("= 10 PUNTOS");
        enemigoFondo[2].setTexture(enemy);
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

Ventana::Ventana(){
    Init();
}

void Ventana::Init(){
    //vidas
    vidas = 5;
    //crea una ventana de esas dimensiones
    //w.create(VideoMode(tamanio.x,tamanio.y), "ventana del juego");
    w.create(VideoMode::getDesktopMode(), "ventana del juego",Style::Fullscreen);

    //::ShowWindow(w.getSystemHandle(), SW_MAXIMIZE);
    //limita el juego a 60 fps
    w.setFramerateLimit(fps);
    //carga las texturas
    Fondo.loadFromFile("space.png");
    enemy.loadFromFile("sprite_space.png");
    Nave.loadFromFile("nave.png");
    disparo.loadFromFile("disparo.png");
    rayo.loadFromFile("rayo.png");
    //carga los sprites de las texturas
    //enemiga.Init();
    SpFondo.setTexture(Fondo);
    SpNave.setTexture(Nave);
    SpDisparo.setTexture(disparo);
    SpRayo.setTexture(rayo);
    SpRayo.scale({0.5,0.5});
    SpRayo.setPosition({1366,768});
    SpNave.setScale({0.28,0.28});
    SpNave.setPosition({((float)w.getSize().x/2)-50,630});
    //SpRayo.setTextureRect(IntRect(0,0,55,72));
    // texturas del enemigo
    /*for (int i=0;i<10;i++){

         enemigo1[i].setTexture(enemy);
         enemigo1[i].setTextureRect(IntRect(439,20,55,72));
         enemigo1[i].scale({2,2});
         enemigo1[i].setPosition(i*80,1*72);

      }*/

         enemigoP.setTexture(enemy);
         enemigoP.setTextureRect(IntRect(125,532,70,50));
         enemigoP.scale({2,2});
         enemigoP.setPosition(405,0);

    for (int i=0;i<10;i++){

         enemigo1[i].setTexture(enemy);
         enemigo1[i].setTextureRect(IntRect(422,14,60,50));
         enemigo1[i].scale({2,2});
         enemigo1[i].setPosition(i*90,1*72);
      }

    n=0;
    for (int i=0;i<10;i++)
    for (int j=1;j<=2;j++)
      {
         enemigo2[n].setTexture(enemy);
         enemigo2[n].setTextureRect(IntRect(266,14,60,50));
         enemigo2[n].scale({2,2});
         enemigo2[n].setPosition(i*90,j*72+72);

         n++;
      }

      n=0;
    for (int i=0;i<10;i++)
    for (int j=1;j<=2;j++)
      {
         enemigo3[n].setTexture(enemy);
         enemigo3[n].setTextureRect(IntRect(100,14,60,50));
         enemigo3[n].scale({2,2});
         enemigo3[n].setPosition(i*90,j*72 + 72*3);

         n++;
      }



    //cargar buffer y sound
    if(!buffer.loadFromFile("sonido1.wav"))
        cout << "no se pudo cargar el efecto" << endl;
    sonido.setBuffer(buffer);


    //pone un fondo de pantalla completa
    SpFondo.setScale(((float)w.getSize().x/SpFondo.getTexture()->getSize().x),
                     ((float)w.getSize().y/SpFondo.getTexture()->getSize().y)
                    );
    //inicializa una letra con la fuente que descargu�
    fuente1.loadFromFile("PressStart2P.ttf");
    for(int i=0;i<20;i++){
        texto1[i].setFont(fuente1);
        texto1[i].setColor(sf::Color::White);
    }


    Loop();
}

void Ventana::Loop(){
    while (w.isOpen()){
        Event event;
        while (w.pollEvent(event)){

                //cierra la ventana cuando se presiona X
            if (event.type == Event::Closed){
            w.close();
            }

                //detecta si se mueve el mouse y guarda sus coordenadas
                ///////////////////////////////////////
            if(event.type == sf::Event::MouseMoved){
                MouseVect = sf::Mouse::getPosition(w);
                MouseVect = (sf::Vector2i)w.mapPixelToCoords(MouseVect);
                sf::FloatRect MouseRect(Vector2f(MouseVect),{32,32});
                //si choca con el mensaje entonces cambia de color y muestra un sonido
            if(texto1[2].getGlobalBounds().intersects(MouseRect) && texto1[2].getColor() == Color::White && VentPres == 1){
                        texto1[2].setColor(Color::Red);
                        sonido.play();

                }else if(!texto1[2].getGlobalBounds().intersects(MouseRect) && texto1[2].getColor() == sf::Color::Red ){
                      texto1[2].setColor(sf::Color::White);
            }

        }
        //////////////////////////////////////////
        if(event.type == sf::Event::MouseButtonPressed){
                MouseVect = sf::Mouse::getPosition(w);
                MouseVect = (sf::Vector2i)w.mapPixelToCoords(MouseVect);
                sf::FloatRect MouseRect(Vector2f(MouseVect),{32,32});
                if(event.key.code == sf::Mouse::Left){
                    if(texto1[2].getGlobalBounds().intersects(MouseRect)){
                        VentPres = 0;
                    }
                }
            }
            ////////////////////////////////////


        }


        w.clear();


        if(VentPres == 1){

          Presentacion();
        }else if(VentPres == 0){
            if(!Gameover){
            Game();
            }else if(Gameover){
            GameOver();
            }

        }




        w.display();
    }


}
