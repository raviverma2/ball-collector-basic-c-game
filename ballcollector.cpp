#include<iostream> 

#include<conio.h>d 

#include<stdlib.h> 

using namespace std; 

bool gameover;                   //global variables 

 

int hieght=25; 

int width=35; 

int xx,yy; 

class game{ 

private: 

    int x,y,ox,score;                //variables to store  position of balls(ox and oy)and ball collector(x and y) 

    int oy; 

    enum control{left,right}; 

enum control dir; 

public : 

    game():x(width/2),y(hieght-1),ox(rand()%20),oy(1),score(0){};   //constuctor to initialise  ball and ball collector 

    ~game(){}                                                        //destructor 

void setup(){ 

while(gameover=false) 

    {}; 

    } 

void draw(){ 

    system("cls"); 

    int i,k; 

for(k=0;k<hieght+1;k++){                                               // it is a matrix of hieght by width with borders having ! sign 

        for(i=0;i<width+1;i++){ 

    if(i==0||i==width||k==0||k==hieght){                                   // and coordinates of ball collector  having @ sign 

        cout<<"!"; 

       }                                                                   //and coordinates of ball by $ sign 

      else if(k==y && i==x){cout<<"@";} 

      else if(i==x-1 && k==y) {cout<<"@";} 

       else if(i==x+1 && k==y){cout<<"@";} 

       else if(i==ox && k==oy){ 

               cout<<"$"; 

xx=i; 

yy=k; 

       } 

else{cout<<" ";} 

 

 

        } 

        cout<<endl; 

} 

if(x==ox && oy==y){ 

    ox=rand()%width;                                         //if ball is collected then the ball coordinate are changed to (random 0x and y=1) 

    oy=1;                                                    //if the ball collector coordinates(x and y) matches fruit collector(ox and oy) 

    score=score+10; 

 

cout<<score; 

}else if(ox==x-1 && oy==y){ 

     ox=rand()%width; 

    oy=1;                                                     //if ball is collected then the ball coordinate are changed to (random 0x and y=1) 

                                                //if the ball collector coordinates(x-1 and y) matches fruit collector(ox and oy) 

    score=score+10; 

cout<<score;} 

 

    else if(ox==x+1 && oy==y){                              //if ball is collected then the ball coordinate are changed to (random 0x and y=1) 

                                                    //if the ball collector coordinates(x+1 and y) matches fruit collector(ox and oy) 

         ox=rand()%width; 

    oy=1; 

    score=score+10; 

    cout<<score; 

 

 

    } 

    else {cout<<"the score is"<<" "<<score;} 

 

 

 

if( oy==hieght){ 

    gameover=true; 

 

} 

if(xx==ox && yy==oy){                           //the ball($) drops by one unit down as after every iteration of the loop oy changes to oy +_1 

    ox=ox; 

    oy=oy+1; 

} 

if(x==width){x=0;} 

else if(x==0){x=width;} 

 

 

} 

 

void controls(){ 

if(_kbhit()){ 

    switch(_getch()){ 

case 'a':                             //controls such as a for left and d for right 

    dir=left; 

    break; 

case 'd': 

    dir=right; 

    break; 

    case 'x': 

    gameover=true; 

    } 

} 

} 

void logic(){ 

switch(dir){ 

case left: 

    x=x-1; 

    break; 

    case right: 

    x=x+1; 

    break; 

} 

} 

}; 

 

int main(){ 

    game r; 

    r.setup(); 

 

while(!gameover){ 

    r.draw(); 

    r.controls(); 

    r.logic();                                //the while loop runs until the boolean gameover is false 

 

} 

} 

 

 

 

 