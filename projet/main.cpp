#include <iostream>
#include "classe.hpp"
#include <vector>
using namespace std ;

int main()
{
	cout << "Hello world!" << endl;
	Point P1=Point(0,3);
	Point P2=Point(2,3);
	Point P3=Point(2,5);
	Point P4=Point(0,5);
	Point P5 =Point(4,0);
	Point P6 =Point(6,0);
	Point P7 =Point(6,2);
	Point P8 = Point(4,2);

	//double a=distance(P1,P2);
	Segment S1=Segment(P2,P8);
	Segment S2=Segment(P1,P2);


	//cout << S1 << S2 << endl;
	//int m = 0;
	/*
	printf("P1.x vaut:%lf\n ",P1.x);
	double b=norme(S1);
	Point  LA[3]={P1,P2,P3};
	obstacle O(3,LA);
	affichage(O);
	O.add(P1);
	affichage(O);
	O.add(P2);
	O.add(P3);
	//obstacle G(O);
	printf("La distance entre les Points est de :%lf",a);
	printf("\n");
	printf("La norme du segement est :%lf\n",b);

	//affichage(G);
	printf("P1.x vaut:%lf\n ",P1.x);
	*/
	//affichage(S1);
	//Point_segment1(S1,P3,0.1);
	//Point_segment(S1,P3,0.1);
	//affichage(S2);
	//bool b=intersection_segment(S1,S2,0.1,0);
	//printf("%d\n",b);

    vector<Point> liste_points = {P1,P2,P3,P4};
    vector<Point> liste_points_2 = {P5,P6,P7,P8};

    const Obstacle ob1 = Obstacle(4,liste_points);
    const Obstacle ob2 = Obstacle(4,liste_points_2);

    //bool res = intersection_segment_polygon(S1,ob1);

    //cout << ob1 << ob2 << endl;

    const vector<Obstacle> vect_obst = {ob1,ob2};

    Graph graphe = Graph(2,vect_obst);

    cout << graphe << endl;

    //cout << vect_obst[0] << vect_obst[1] << endl;


    //vector<Segment> segments  = ob.segments_of_obstacle();
    //cout << segments[0] << segments[1] << endl;

    /*
	Point liste_Points1[4] = {P1,P2,P3,P4};
	Point liste_Points2[4] = {P5,P6,P7,P8};


	obstacle test1 = obstacle(4,liste_Points1);
	obstacle test2 = obstacle(4,liste_Points2);
    affichage(test1);
    affichage(test2);
    */
    /*
    printf("m = %d",m);

    m = comptage_intersection(S1,test1);
    printf("m = %d",m);

    vector<int> test{1,2};
    printf("ca marche toujours\n");

    */
    /*
    obstacle* vect_obstacles = new obstacle[2];
    vect_obstacles[0] = test1;
    vect_obstacles[1] = test2;
    */


    //vector <obstacle> vect_obstacle;
    //vect_obstacle.push_back(test1);

    //vect_obstacles.push_back(test1);

    //printf("ca marche toujours\n");
    //bool valide;



    //valide = is_arc_valide(S2, vect_obstacles,2);
    //printf("valide = %d",valide);

    return 0;

}
