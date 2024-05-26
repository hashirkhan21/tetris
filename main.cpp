/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
using namespace sf;
int main(){
    srand(time(0));
    RenderWindow window(VideoMode(600, 480), title);
    Texture obj1, obj2, obj3, obj4, obj5, obj6, obj7, obj8, obj9,obj10,obj11;
    
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/shadow.png");
    obj5.loadFromFile("img/back3.png");
    obj6.loadFromFile("img/TNT.png");
    obj7.loadFromFile("img/menu.jpg");
    obj8.loadFromFile("img/level.jpg");
    obj9.loadFromFile("img/help.jpg");
    obj10.loadFromFile("img/pause.png");
    obj11.loadFromFile("img/game.png");
    
    sf::RectangleShape rectangle(sf::Vector2f(17.0f,17.0f));
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setPosition(325,100);
    
    
    Sprite sprite1(obj1), background(obj2), frame(obj3), sprite2(obj4),back1(obj5) , sprite3(obj6) , menu(obj7),levels(obj8) ,help(obj9) , pause(obj10),gm(obj11);
    int delta_x=0, colorNum=1,men=1,lv=1,hel=1,H=0; 
    float timer=0, delay=0.5;
    bool rotate=0;
    int n3=rand()%7, n1=rand()%7, n2=rand()%7, c4=rand()%7;
    int c3=1+rand()%7, c2=1+rand()%7,c1=1+rand()%7;
    bool bomb=0;
    point_8[0][1]=0;
    int mov=1;
    int lvl=1;
    int n=1;
    bool gameover=0; int tmm=1;
    Text scoretext;
    int score= 0;
    float q=0.5;
    scoretext.setCharacterSize(24);
    sf:: Font bob;
    bob.loadFromFile("YagiUhfNo2.otf");
    scoretext.setFont(bob);
    scoretext.setFillColor(sf::Color::Black);
    scoretext.setString("" + std::to_string(score)); 
    scoretext.setPosition(530,140);
    
    Clock clock;
    while (window.isOpen()){

	
    	while (men){
    	window.draw(menu);       
    		if (Keyboard::isKeyPressed(Keyboard::Escape))  
         	window.close(); 
                if (Keyboard::isKeyPressed(Keyboard::Num1))           
                    {lv=0;men=0;hel=0;}                 
                else if (Keyboard::isKeyPressed(Keyboard::Num3))     
                    {men=0; hel=0;}
                else if (Keyboard::isKeyPressed(Keyboard::Num2))    
                   {men=0 ; lv=0; hel=0;}
                else if (Keyboard::isKeyPressed(Keyboard::Num4))    
                   {men=0 ; lv=0;}
                
                window.display();}
                
         while(lv){
         window.draw(levels); hel=0; 
         if (Keyboard::isKeyPressed(Keyboard::Escape))  
         window.close();
         if (Keyboard::isKeyPressed(Keyboard::A))  
         {lvl=1; lv=0;}
         else if (Keyboard::isKeyPressed(Keyboard::B))  
         {lvl=2; lv=0;}
         else if (Keyboard::isKeyPressed(Keyboard::C))  
         {lvl=3; lv=0;}
         window.display();
         }
         
          while(hel){
         window.draw(help); lv=0;
         if (Keyboard::isKeyPressed(Keyboard::Escape))  
         window.close();
         if (Keyboard::isKeyPressed(Keyboard::Num0))  
         {hel=0; men=1;}
         else if(Keyboard::isKeyPressed(Keyboard::Num1))
         {hel=0 ; men=0;}
         window.display();
         }
        

        if(hel==0 && lv==0 && men==0){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        Event e;
        while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();
                                            
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;  
                else if (e.key.code == Keyboard::H)    //Check if the other key pressed is RIGHT key
                    H = 1;                          //Change in X-Axis - Positive
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
	if (Keyboard::isKeyPressed(Keyboard::Space))   
            Space();
        
	
	while(H){
	 window.clear(Color::Black);
         window.draw(pause); 
         if (Keyboard::isKeyPressed(Keyboard::Escape))  
         	window.close(); 
         if (Keyboard::isKeyPressed(Keyboard::Num0))  
         {H=0;}
         else if (Keyboard::isKeyPressed(Keyboard::Num1))           
          {H=0; 
          int l=0;
		for(int m=M-1 ; m>=0 ; m--){
		for(int n=N-1 ; n>=0 ; n--)
		{gameGrid[m][n]={0};}	
		}
		n3=rand()%7, n1=rand()%7, n2=rand()%7, c4=rand()%7; n= rand()%7;
		c3=1+rand()%7, c2=1+rand()%7,c1=1+rand()%7; colorNum=1+rand()%7;
		score=0; timer=0, delay=0.5;
		for( int i=0 ; i<4 ; i++)
		for (int i=0;i<4;i++){
		    point_1[i][0]=0;
		    point_1[i][1]=0;}
          }
          window.display(); 
         }
         
         while(gameover){
         if (Keyboard::isKeyPressed(Keyboard::Escape))  
         	window.close(); 
	 window.clear(Color::Black);
         window.draw(gm);
         scoretext.setFillColor(sf::Color::White); 
         scoretext.setPosition(150,230);
         scoretext.setCharacterSize(24);
         window.draw(scoretext);
         window.display(); 
         tmm++;
         if(tmm==100000)
         window.close();
         }
	
	for(int x=N ; x>=0 ; x--){
	if(gameGrid[0][x])
	gameover=1;}
	
	
	
        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***/// 	
 	
 	bombs(timer ,delay , bomb, c4, score);
        fallingPiece(timer, delay,colorNum,c1,c2,c3,n1,n2,n3,bomb,c4,mov,n,q);   //Example: fallingPiece() function is called here
        move(delta_x);          
        rotation(rotate,bomb);
        Score(score);
        line();
	scoretext.setString("" + std::to_string(score));
	
	if(score<200 && lvl!=2 && lvl!=3)
	lvl=1;
	else if(score<350 && lvl!=3)
	lvl=2;
	else if( score>350)
	lvl=3;
	
	if(lvl==1)
	q=0.5;
	else if(lvl==2)
	q=0.4;
	else if(lvl==3)
	q==0.3;
            
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////

	 
        window.clear(Color::Black);
        window.draw(background);
        back1.setPosition(320,0);
        window.draw(back1);
        window.draw(scoretext);
        
        for (int i=0; i<4; i++){
            sprite2.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite2.setPosition(point_3[i][0]*18,point_3[i][1]*18);
            sprite2.move(28,31);
            window.draw(sprite2); } 
            
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite1.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite1.setPosition(j*18,i*18);
                sprite1.move(28,31); //offset
                window.draw(sprite1);
            }
        }
        for (int i=0; i<4; i++){
            sprite1.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite1.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite1.move(28,31);
            window.draw(sprite1);
          }
        for (int i=0; i<4; i++){
            sprite1.setTextureRect(IntRect(c2*18,0,18,18));
            sprite1.setPosition(point_6[i][0]*18,point_6[i][1]*18);
            sprite1.move(440,350);
            window.draw(sprite1);
            
         }
         
         for (int i=0; i<4; i++){
            sprite1.setTextureRect(IntRect(c3*18,0,18,18));
            sprite1.setPosition(point_7[i][0]*18,point_7[i][1]*18);
            sprite1.move(540,350);
            window.draw(sprite1);}
         
       for (int i=0; i<4; i++){
            sprite1.setTextureRect(IntRect(c1*18,0,18,18));
            sprite1.setPosition(point_5[i][0]*18,point_5[i][1]*18);
            sprite1.move(350,350);
            window.draw(sprite1);}
            
            sprite3.setTextureRect(IntRect(c4*18,0,18,18));
            sprite3.setPosition(point_8[0][0]*18,point_8[0][1]*18);
            sprite3.move(28,31);
            window.draw(sprite3);
        
        }
        
       window.draw(rectangle);
          
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
       
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
     
    }
    return 0;
}

