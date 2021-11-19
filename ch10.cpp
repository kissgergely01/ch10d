#include "std_lib_facilities.h"

//1.
struct Point 
{
	int x;
	int y;
};

void PrintDatas(string vectorN, vector<Point> vector)
{
	cout << vectorN << "'s datas: " << endl;
	for(const auto& points:vector)
		cout << "(" << points.x << "," << points.y << ")" << endl;
}

int main()
{

try{
	//2.
	cout << "give 7 (x,y) values" << endl;
	char first, last, comma;
	int coord1, coord2;
	vector<Point> original_points ;	

	while(original_points.size()!=7)
	{
		cin >> first >> coord1 >> comma >> coord2 >> last;
		if(first != '(')
		 	error("it must start with '(' ") ; 
		if(!int(coord1))
		 	error("coord1 must be an int");
		if(comma != ',')
		 	error("don't forget the comma");
		if(!int(coord2))
			error("coord2 must be an int");
		if(last != ')')
			error("it must end with ')' ");

		Point p;
		if(first == '(' && int(coord1) && comma == ',' && int(coord2) && last==')')
		{
			p.x = coord1;
			p.y = coord2;
			original_points.push_back(p);
		}
	}

	
	//3.
	PrintDatas("original_points:", original_points); 
	//4.
	string outPutName = "mydata.txt";
	ofstream ofile {outPutName};
	if(!ofile) error("Can't open ofile ", outPutName);
	for(const auto& points:original_points)
			ofile << "(" << points.x << "," << points.y <<")";
	ofile.close();
	//5.
	string inPutName = outPutName;
	ifstream ifile {inPutName};
	if(!ifile) error("Can't open ifile", inPutName);
	vector<Point> processes_points;

	Point p;
	while(ifile >> first >> coord1 >> comma >> coord2 >> last)
	{
		p.x = coord1;
		p.y = coord2;
		processes_points.push_back(p);
	}
	ifile.close(); 
	//6.
	cout << "Both vector elements: " << endl;
	PrintDatas("original_points: ", original_points);
	PrintDatas("processes_points: ", processes_points);

	//7.
	if(original_points.size() != processes_points.size())
		cout << "something's wrong" << endl;


	return 0;
}
catch(exception& e)
{
	cerr << e.what()<< endl;
	return 1;
}
}
