#include <string>
#include <fstream>
#include<sstream>
#include <utility>
//^^used for multi var type arrays^^
using namespace std;
using std::string;

class BallInfo
{
	public:
		//constructors
		BallMain();
		void inputMain();

		//accessors
		void print() const;
		string getID() const;
		string getColor() const;
		string getTexture() const;
		double getDiameter() const;
		

		//mutators
		void setDiameter(double diameter);
		void setID(string IDnumber);			
		void setTexture(string ballTexture);
		void setColor(string ballColor);		
	
	private:	
		int counter;
		string ball_ID;
		double ball_mm;
		string str_counter;
		string ball_color;
		string ball_texture;




};


