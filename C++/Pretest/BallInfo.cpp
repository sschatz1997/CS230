#include <string>
#include <iostream>
#include <fstream>
#include<sstream>
#include <utility>
//^^used for multi var type arrays^^
using namespace std;
using std::string;
#include "BallInfo.h"


BallInfo::BallMain(){
	int counter = 0;
	double ball_mm = 0;
	string ball_ID = "";
	string ball_color = "";
	string ball_texture = "";
	string placeHolder1 = "";
}

void BallInfo::setDiameter(double diameter){ ball_mm = diameter; }
void BallInfo::setID(string IDnumber) { ball_ID = IDnumber; }
void BallInfo::setColor(string ballColor) { ball_color = ballColor; }
void BallInfo::setTexture(string ballTexture) { ball_texture = ballTexture; }

string BallInfo::getID() const { return ball_ID; }
double BallInfo::getDiameter() const { return ball_mm; }
string BallInfo::getColor() const { return ball_color; }
string BallInfo::getTexture() const { return ball_texture;}

void BallInfo::print() const
{
	cout << "\t\tAll ball info: \n"
		<< "\t Ball Diameter: "<< ball_mm <<"\n"
		<< "\t Ball ID: "<< ball_ID << "\n"
		<< "\t Ball Color: "<< ball_color << "\n"
		<< "\t Ball Texture: "<< ball_texture<<"\n\n" <<endl;
}


