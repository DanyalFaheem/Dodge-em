//============================================================================
// Name        : game.cpp
// Author      : Danyal Faheem
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include <fstream>
#include<ctime>
#include<cstdlib>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
float movex=400,movey=770,movex1=30,movey1=400;
string score[81]={"score=0","score=1","score=2","score=3","score=4","score=5","score=6","score=7","score=8","score=9","score=10","score=11","score=12","score=13","score=14","score=15","score=16","score=17","score=18","score=19","score=20","score=21","score=22","score=23","score=24","score=25","score=26","score=27","score=28","score=29","score=30","score=31","score=32","score=33","score=34","score=35","score=36","score=37","score=38","score=39","score=40","score=41","score=42","score=43","score=44","score=45","score=46","score=47","score=48","score=49","score=50","score=51","score=52","score=53","score=54","score=55","score=56","score=57","score=58","score=59","score=60","score=60","score=61","score=62","score=63","score=64","score=65","score=67","score=68","score=69","score=70","score=71","score=72","score=73","score=74","score=75","score=76","score=77","score=78","score=79","score=80",};
int score_count=0,lives_count=0,level_count=0,pos_opp=0,middle[5];
string lives[3]={"lives=3","lives=2","lives=1"},high_score[5],level[4]={"level=1","level=2","level=3","level=4"};
bool menu=false,lost=false,help=false,h_scores=false,level_2=false,won=false;

void Rand_Position()//Deciding for random position for oppponent
{
srand(time(0));
pos_opp=rand()%(3-1)+1;
if(pos_opp==3)
{
	movex1=30;
	movey1=400;
}
if(pos_opp==2)
{
	movex1=400;
	movey1=100;
}
if(pos_opp==1)
{
	movex1=400;
	movey1=20;
}		
}		


// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	if(menu==true&&lost==false&&help==false&&h_scores==false)
	{
	//Drawing score, level, lives boxes
	DrawString( 390, 430, score[score_count], colors[MISTY_ROSE]);
	DrawString( 390, 390, lives[lives_count], colors[BLUE_VIOLET]);
	DrawString( 390, 360, level[level_count], colors[GREEN]);
	
	// Drawing own car
	float x = movex; 
	float y = movey; 
	float width = 11; 
	float height = 8.5;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 5.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect

	//Drawing opponent car
	 x = movex1; 
	 y = movey1; 
	 width = 11; 
	 height = 8.5;
	 color = colors[DARK_RED]; 
	 radius = 5.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect
	
	// Drawing Arena
	int gap_turn = 80;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx+gap_turn, sy+80, swidth-gap_turn, sheight, scolor);//1st 
	DrawRectangle(sx+gap_turn+gap_turn, sy+80+gap_turn, swidth-gap_turn-gap_turn, sheight, scolor);//2nd
	DrawRectangle(sx+gap_turn+gap_turn*2, sy+80+gap_turn*2, swidth-gap_turn-gap_turn*2, sheight, scolor);//3rd
	DrawRectangle(sx+gap_turn+gap_turn*3, sy+80+gap_turn*3+10, swidth-gap_turn-gap_turn*3+100, sheight, scolor);//last
	
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx + swidth + gap_turn, sy+80, swidth-gap_turn, sheight, scolor);//1st 
	DrawRectangle(sx + swidth + gap_turn, sy+80+gap_turn, swidth-gap_turn-gap_turn, sheight, scolor);//2nd
	DrawRectangle(sx + swidth + gap_turn, sy+80+gap_turn*2, swidth-gap_turn-gap_turn*2, sheight, scolor);//3rd
	DrawRectangle(sx + swidth + gap_turn, sy+80+gap_turn*3+10, swidth-gap_turn-gap_turn*3, sheight, scolor);//last
	
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-gap_turn, sy+sheight+gap_turn, sheight*2-10, swidth-gap_turn, scolor);//1st
	DrawRectangle(sx+swidth*2-gap_turn, sy+sheight+gap_turn+gap_turn, sheight*2-10, swidth-gap_turn*2, scolor);//2nd
	DrawRectangle(sx+swidth*2-gap_turn*2, sy+sheight+gap_turn+gap_turn*2, sheight*2-10, swidth-gap_turn*3, scolor);//3rd
	DrawRectangle(sx+swidth*2-gap_turn*3, sy+sheight+gap_turn+gap_turn*3+10, sheight*2-10, swidth-gap_turn*4+30, scolor);//last
	
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx+swidth*2+gap_turn-gap_turn, sy+sheight+swidth+gap_turn, sheight*2-10, swidth-gap_turn, scolor); //1st
	DrawRectangle(sx+swidth*2-gap_turn, sy+sheight+swidth+gap_turn, sheight*2-10, swidth-gap_turn*2, scolor);//2nd
	DrawRectangle(sx+swidth*2-gap_turn*2, sy+sheight+swidth+gap_turn, sheight*2-10, swidth-gap_turn*3, scolor);//3rd
	DrawRectangle(sx+swidth*2-gap_turn*3, sy+sheight+swidth+gap_turn-30, sheight*2-10, swidth-gap_turn*4+20, scolor);//last
	
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx + swidth + gap_turn, sy+810-gap_turn, swidth-gap_turn, sheight, scolor);//1st
	DrawRectangle(sx + swidth + gap_turn, sy+810-gap_turn*2, swidth-gap_turn*2, sheight, scolor);//2nd
	DrawRectangle(sx + swidth + gap_turn, sy+810-gap_turn*3, swidth-gap_turn*3, sheight, scolor);//3rd
	DrawRectangle(sx + swidth + gap_turn, sy+810-gap_turn*4-10, swidth-gap_turn*4, sheight, scolor);//last
	
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx+gap_turn, sy+810-gap_turn, swidth-gap_turn, sheight, scolor);//1st
	DrawRectangle(sx+gap_turn+gap_turn, sy+810-gap_turn*2, swidth-gap_turn*2, sheight, scolor);//2nd
	DrawRectangle(sx+gap_turn+gap_turn*2, sy+810-gap_turn*3, swidth-gap_turn*3, sheight, scolor);//3rd
	DrawRectangle(sx+gap_turn+gap_turn*3, sy+810-gap_turn*4-10, swidth-gap_turn*4+100, sheight, scolor);//last
	
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2+gap_turn+10, sy+sheight+swidth+gap_turn, sheight*2-10, swidth-gap_turn, scolor);//1st
	DrawRectangle(sx-sheight*2+gap_turn+10+gap_turn, sy+sheight+swidth+gap_turn, sheight*2-10, swidth-gap_turn*2, scolor);//2nd
	DrawRectangle(sx-sheight*2+gap_turn+10+gap_turn*2, sy+sheight+swidth+gap_turn, sheight*2-10, swidth-gap_turn*3, scolor);//3rd
	DrawRectangle(sx-sheight*2+gap_turn+10+gap_turn*3, sy+sheight+swidth+gap_turn-30, sheight*2-10, swidth-gap_turn*4+20, scolor);//last
	
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	DrawRectangle(sx-sheight*2+gap_turn+10, sy+sheight+gap_turn, sheight*2-10, swidth-gap_turn, scolor);//1st
	DrawRectangle(sx-sheight*2+gap_turn+10+gap_turn, sy+sheight+gap_turn*2, sheight*2-10, swidth-gap_turn*2, scolor);//2nd
	DrawRectangle(sx-sheight*2+gap_turn+10+gap_turn*2, sy+sheight+gap_turn*3, sheight*2-10, swidth-gap_turn*3, scolor);//3rd
	DrawRectangle(sx-sheight*2+gap_turn+10+gap_turn*3, sy+sheight+gap_turn*4+10, sheight*2-10, swidth-gap_turn*4+30, scolor);//last
	
//Drawing gift boxes
	for(int counter=0,leave_vert=20;counter<10;counter++,leave_vert+=80)
	{
		if(counter==4)
		leave_vert+=30;
		for(int count=0,leave_hor=30;count<10;count++,leave_hor+=80)
		{
			if(count==4){
				leave_hor+=100;
			}
			else
			{
				if(movex==leave_hor&&movey==leave_vert){//collision detection with gift boxes
					score_count++;
					DrawSquare(  leave_hor, leave_vert , 0,colors[GREEN]);
					if(score_count==80){
						level_2=true;
						level_count++;
						score_count=0;
					}	
				}
				DrawSquare(  leave_hor, leave_vert , 10,colors[GREEN]);
				} 
			}
	}		
	
		glutPostRedisplay();
	}
	else if(menu==false&&help==false&&lost==false&&h_scores==false)//Drawing pause/start menu
	{
	DrawString( 300, 700, "Press option number to choose it.", colors[DARK_RED]);
	DrawString( 400, 600, "1) Start New Game", colors[MISTY_ROSE]);
	DrawString( 400, 500, "2) See High Scores", colors[MISTY_ROSE]);
	DrawString( 400, 400, "3) Help", colors[MISTY_ROSE]);
	DrawString( 400, 300, "4) Exit", colors[MISTY_ROSE]);
	}
	else if(lost==true&&help==false&&menu==true&&h_scores==false)//Drawing menu when all lives lost
	{
	DrawString( 400, 600, "You lost the game on ", colors[MISTY_ROSE]);
	DrawString( 640, 600, level[level_count], colors[MISTY_ROSE]);
	DrawString( 400, 500, "Your score is ", colors[MISTY_ROSE]);
	DrawString( 540, 500, score[score_count], colors[MISTY_ROSE]);
	}
	else if(help==true&&lost==false&&h_scores==false)//Drawing help menu
	{
	DrawString( 400, 700, "HELP MENU", colors[DARK_RED]);
	DrawString( 200, 600, "Turn your cars at available turns with arrow keys", colors[MISTY_ROSE]);
	DrawString( 200, 500, "Don't let the opponent car catch you!!", colors[MISTY_ROSE]);
	DrawString( 200, 400, "If you collect all gift boxes without losing all 3 lives, you win!", colors[MISTY_ROSE]);		
	}
	else if(h_scores==true&&help==false&&lost==false)//Displaying high scores menu
	{
		ifstream fin ("highscores.txt");
		if (fin.is_open())
	{
		for(int counter=0,vert=700;counter<5;counter++,vert-=100)
			{
			getline(fin,high_score[counter]);
			DrawString( 300, vert , high_score[counter], colors[MISTY_ROSE]);
			}
		fin.close();
	}
	}
	else if(won==true&&help==false&&lost==false&&menu==true&&h_scores==false)//Displaying winning menu
	{
		DrawString( 400, 600, "You won the game!!!",colors[MISTY_ROSE]);		
		DrawString( 400, 500, "Congratulations!!!", colors[MISTY_ROSE]);
	}

	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) { 
		// what to do when left key is pressed...
		if(movey<=450&&movey>=390)
		{
			if(movex<280||movex>600)
			{
				movex -= 80;
				}
		}
		
	
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if(movey<=450&&movey>=390)
		{
			if(movex<260||movex>520)
			{
				movex+=80;
			}
		}
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if(movex>=390&&movex<=450)
		{
			if(movey>520||movey<250)
			{
				movey+=80;
			}
		}
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if(movex>=390&&movex<=450)
		{
			if(movey>540||movey<270)
			{
				movey-=80;
			}
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27||key=='4'/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'p' || key == 'P')//Option for pause menu
			{
		menu=false;
		lost=false;
		}
	if (key == '1')//option for new gamwe
	{
		menu=true; 
	}
	if (key == '2')//option for high scores
	{
		h_scores=true;
	}
	if (key == '3')//option for help menu
	{
		help=true;
	}
	if (key == 8)//pressing backspace to go back to main menu
	{
		menu=false;
		help=false;
		h_scores=false;
	}	
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	
	if(menu==true)
	{
	//Players car auto movement
	//outer ring
	if(movex!=30&&movey==20)
	movex-=2;
	 if(movex==30&&movey!=770)
	movey+=2;
	 if (movey==770&&movex!=770)
	movex+=2;
	 if(movey!=20&&movex==770)
	movey-=2;
	//2nd ring
	 if(movex!=110&&movey==100&&movex>80&&movex<710)
	movex-=2;
	if(movex==110&&movey!=690&&movey>80&&movey<710)
	movey+=2;
	 if (movey==690&&movex!=690&&movex>80&&movex<710)
	movex+=2;
	 if(movey!=100&&movex==690&&movey<710&&movey>80)
	movey-=2;
	//3rd ring
	if(movex!=190&&movey==180&&movex>180&&movex<620)
	movex-=2;
	if(movex==190&&movey!=610&&movey>160&&movey<620)
	movey+=2;
	 if (movey==610&&movex!=610&&movex>180&&movex<620)
	movex+=2;
	 if(movey!=180&&movex==610&&movey<620&&movey>180)
	movey-=2;
	//innermost ring
	if(movex!=270&&movey==260&&movex>260&&movex<540)
	movex-=2;
	if(movex==270&&movey!=530&&movey>240&&movey<540)
	movey+=2;
	 if (movey==530&&movex!=530&&movex>260&&movex<540)
	movex+=2;
	 if(movey!=260&&movex==530&&movey<540&&movey>260)
	movey-=2;
	
	//opponents cars auto movement
	//outermost ring
	if(movex1!=770&&movey1==20)
	movex1+=2;
	 if(movex1==770&&movey1!=770)
	movey1+=2;
	 if (movey1==770&&movex1!=30)
	movex1-=2;
	 if(movey1!=20&&movex1==30)
	movey1-=2;
	//2nd ring
	if(movex1!=690&&movey1==100&&movex1>80&&movex1<710)
	movex1+=2;
	if(movex1==690&&movey1!=690&&movey1>80&&movey1<710)
	movey1+=2;
	 if (movey1==690&&movex1!=110&&movex1>80&&movex1<710)
	movex1-=2;
	 if(movey1!=100&&movex1==110&&movey1<710&&movey1>80)
	movey1-=2;
	//3rd ring
	if(movex1!=610&&movey1==180&&movex1>180&&movex1<620)
	movex1+=2;
	if(movex1==610&&movey1!=610&&movey1>160&&movey1<620)
	movey1+=2;
	 if (movey1==610&&movex1!=190&&movex1>180&&movex1<620)
	movex1-=2;
	 if(movey1!=180&&movex1==190&&movey1<620&&movey1>180)
	movey1-=2;
	//innermost ring
	if(movex1!=530&&movey1==260&&movex1>260&&movex1<540)
	movex1+=2;
	if(movex1==530&&movey1!=530&&movey1>240&&movey1<540)
	movey1+=2;
	 if (movey1==530&&movex1!=270&&movex1>260&&movex1<540)
	movex1-=2;
	 if(movey1!=260&&movex1==270&&movey1<540&&movey1>260)
	movey1-=2;
	
	//opponents car's AI
	//Level 1
	//Outermost ring 
	if(movex1<=440&&movex1>=400&&movey1==770){
		if(movex==110||movex==690)
		{
			movey1-=80;
		}
		if(movex==190||movex==610)
		{
			movey1-=160;
		}
		if(movex==270||movex==530)
		{
			movey1-=240;
		}
	}
	if(movex1<=440&&movex1>=400&&movey1==20){
		if(movex==110||movex==690)
		{
			movey1+=80;
		}
		if(movex==190||movex==610)
		{
			movey1+=160;
		}
		if(movex==270||movex==530)
		{
			movey1+=240;
		}
	}
	//2nd ring
	if(movex1<=440&&movex1>=400&&movey1==690){
		if(movex==30||movex==770)
		{
			movey1+=80;
		}
		if(movex==190||movex==610)
		{
			movey1-=80;
		}
		if(movex==270||movex==530)
		{
			movey1-=160;
		}
	}
	if(movex1<=440&&movex1>=400&&movey1==100){
		if(movex==30||movex==770)
		{
			movey1-=80;
		}
		if(movex==190||movex==610)
		{
			movey1+=80;
		}
		if(movex==270||movex==530)
		{
			movey1+=160;
		}
	}
	//3rd ring							
	if(movex1<=440&&movex1>=400&&movey1==610){
		if(movex==30||movex==770)
		{
			movey1+=160;
		}
		if(movex==110||movex==690)
		{
			movey1+=80;
		}
		if(movex==270||movex==530)
		{
			movey1-=80;
		}
	}
	if(movex1<=440&&movex1>=400&&movey1==180){
		if(movex==30||movex==770)
		{
			movey1-=160;
		}
		if(movex==110||movex==690)
		{
			movey1-=80;
		}
		if(movex==270||movex==530)
		{
			movey1+=80;
		}
	}
	//innermost ring
	if(movex1<=440&&movex1>=400&&movey1==530){
		if(movex==30||movex==770)
		{
			movey1+=240;
		}
		if(movex==110||movex==690)
		{
			movey1+=160;
		}
		if(movex==190||movex==610)
		{
			movey1+=80;
		}
	}
	if(movex1<=440&&movex1>=400&&movey1==260){
		if(movex==30||movex==770)
		{
			movey1-=240;
		}
		if(movex==110||movex==690)
		{
			movey1-=160;
		}
		if(movex==190||movex==610)
		{
			movey1-=80;
		}
	}
	
	//if opponent car is in outermost ring
	//Level 2
	if(level_2==true)
	{
	if(movey1<=440&&movey1>=400&&movex1==770){
		if(movey==100||movey==690)
		{
			movex1-=80;
		}
		if(movey==180||movey==610)
		{
			movex1-=160;
		}
		if(movey==260||movey==530)
		{
			movex1-=240;
		}
	}
	if(movey1<=440&&movey1>=400&&movex1==30){
		if(movey==100||movey==690)
		{
			movex1+=80;
		}
		if(movey==180||movey==610)
		{
			movex1+=160;
		}
		if(movey==260||movey==530)
		{
			movex1+=240;
		}
	}
	
	//if opponents car is in 2nd ring	
	if(movey1<=440&&movey1>=400&&movex1==690){
		if(movey==20||movey==770)
		{
			movex1+=80;
		}
		if(movey==180||movey==610)
		{
			movex1-=80;
		}
		if(movey==260||movey==530)
		{
			movex1-=160;
		}
	}
	if(movey1<=440&&movey1>=400&&movex1==110){
		if(movey==20||movey==770)
		{
			movex1-=80;
		}
		if(movey==180||movey==610)
		{
			movex1+=80;
		}
		if(movey==260||movey==530)
		{
			movex1+=160;
		}
	}
	
	//if opponents car is in 3rd ring	
	if(movey1<=440&&movey1>=400&&movex1==610){
		if(movey==20||movey==770)
		{
			movex1+=160;
		}
		if(movey==100||movey==690)
		{
			movex1+=80;
		}
		if(movey==260||movey==530)
		{
			movex1-=80;
		}
	}
	if(movey1<=440&&movey1>=400&&movex1==190){
		if(movey==20||movey==770)
		{
			movex1-=160;
		}
		if(movey==100||movey==690)
		{
			movex1-=80;
		}
		if(movey==260||movey==530)
		{
			movex1+=80;
		}
	}
	
	//if opponents car is in innermost ring	
	if(movey1<=440&&movey1>=400&&movex1==530){
		if(movey==20||movey==770)
		{
			movex1+=240;
		}
		if(movey==100||movey==690)
		{
			movex1+=160;
		}
		if(movey==180||movey==610)
		{
			movex1+=80;
		}
	}
	if(movey1<=440&&movey1>=400&&movex1==270){
		if(movey==20||movey==770)
		{
			movex1-=240;
		}
		if(movey==100||movey==690)
		{
			movex1-=160;
		}
		if(movey==180||movey==610)
		{
			movex1-=80;
		}
	}
	}
	
	//Swapping values at end hollow points
	if(movex==30-80)
	{
		movex=770;
	}
	if(movex==770+80)
	{
		movex=30;
	}
	if(movey==770+80)
	{
		movey=20;
	}
	if(movey==20-80)
	{
		movey=770;
	}			
		
	
	//crashing into each other
	if(movex == movex1 && movey == movey1)
	{
		lives_count++;
		movex=400;
		movey=770;
	}
	
	if(lives_count==3)
	{
		lost=true;//Display end screen
		ifstream fin ("highscores.txt");//Checking if high score or not
		if (fin.is_open())
	{
		int count=81;
		for(int counter=0;counter<5;counter++)//Reading from file
		{
			getline(fin,high_score[counter]);
			for(;count>0;count--)
			{
				if(high_score[counter]==score[count])
				{
					middle[counter]=count;
					count--;
					break;	
				}
			}		
		}
		fin.close();
	}	
		if(score_count>middle[4])//Checking for high score
		{
			middle[4]=score_count;
		}
		for(int counter=0;counter<5;counter++)//sorting for high score
		{
			for(int count=0;count<counter;count++)
			{
				if(middle[count]<middle[count+1])
				{
					int temp=middle[count];
					middle[count]=middle[count+1];
					middle[count+1]=temp;
				}
			}
		}
		int count=0;
		for(int counter=0;counter<5;counter++)
		{
			for(;count<81;count++)
			{
				if(middle[counter]==count)
				{
					high_score[counter]=score[count];
					count++;
					break;
				}
			}
		}					
					
	ofstream fout;//Writing to file
	fout.open ("highscores.txt");
	for (int counter= 0; counter < 5; counter++){
		fout << high_score[counter] << endl;
	}
		
	fout.close();
	}
	if(score_count == 79 and level_2 == true)
	{
		won=true;
		menu=false;
	}
	}
	glutPostRedisplay();
		
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1.0, Timer, 0);

	
}
 
/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Dodge'Em"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
