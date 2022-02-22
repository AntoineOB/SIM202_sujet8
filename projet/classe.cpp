#include <cstdlib>
#include <cmath>
#include <vector >
#include "classe.hpp"

ostream& operator<<(ostream& os,const Point& point){
    os << "("<< point.x << "," << point.y << ")"<<endl;
    return os;
}

bool operator ==(const Point& point1,const Point& point2)
{
    if((point1.x==point2.x)&&(point1.y==point2.y))
    {
        return(true);
    }
    return(false);
}

double distance(const Point& point1, const Point& point2)
{
    double distance;
    /*
    printf("P1.x :%lf\n",P1.x);
    printf("P2.x :%lf\n",P2.x);
    printf("P1.y :%lf\n",P1.y);
    printf("P2.y :%lf\n",P2.y);
    */
    distance=(point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*(point1.y-point2.y);
    distance=sqrt(distance);
    return distance;
}


Segment::Segment(const Point& pa,const Point& pb)
{
    P1=pa;
    P2=pb;

}

bool operator==(const Segment& seg1, const Segment& seg2)
{
    return ( (seg1.P1==seg2.P1) && (seg1.P2==seg2.P2) );
}

double produit_scalaire(const Segment& S1,const Segment& S2)
{
    Point P11=S1.P1;
    double P11x=S1.P1.x;
    Point P12=S1.P2;
    Point P21=S2.P1;
    Point P22=S2.P2;

    double v1x=P11.x-P12.x;
    double v1y=P11.y-P12.y;
    double v2x=P21.x-P22.x;
    double v2y=P21.y-P22.y;
    /*
    printf("P11.x :%lf\n",P11.x);
    printf("P11x :%lf\n",P11x);
    printf("v1x: %lf \n",v1x);
    printf("v2x: %lf \n",v2x);
    printf("v1y:%lf \n",v1y);
    printf("v2y:%lf \n",v2y);
    */
    double p=v1x*v2x+v1y*v2y;
    return(p);
}

double norme(const Segment& S1)
{
    double N=produit_scalaire(S1,S1);
    N=sqrt(N);
    return(N);
}

//a regarder
/*
segment* obstacle ::liste_segment()
{
    segment* liste_arretes=new segment[nbsom];


    for(int i=0;i<nbsom-1;++i){
        liste_arretes[i] = segment(sommets[i],sommets[i+1]);

    }

    liste_arretes[nbsom-1]=segment(sommets[nbsom-1],sommets[0]);
    return(liste_arretes);
}
*/

Segment normale_au_milieu(const Segment& S1)
{
    Point P1=S1.P1;
    Point P2=S1.P2;
    double x_M=(P1.x+P2.x)/2;
    double y_M=(P1.y+P2.y)/2;
    double x_N=P2.y-P1.y+x_M;
    double y_N=P1.x-P2.x+y_M;
    Point M=Point(x_M,y_M);
    Point N=Point(x_N,y_N);
    Segment A=Segment(M,N);
    return(A);
}
Segment normale(const Segment& S1)
{
    Point P1=S1.P1;
    Point P2=S1.P2;
    double x_M=P1.x;
    double y_M=P1.y;
    double x_N=P2.y-P1.y+x_M;
    double y_N=P1.x-P2.x+y_M;
    Point M=Point(x_M,y_M);
    Point N=Point(x_N,y_N);
    Segment A=Segment(M,N);
    return(A);
}

bool point_segment(const Segment& S,const Point& P,double eps)
{
    Segment S1=Segment(S.P1,P);
    double projete=produit_scalaire(S,S1)/(norme(S));
    double x_E=S.P1.x+projete*(S.P2.x-S.P1.x)/norme(S);
    double y_E=S.P1.y+projete*(S.P2.y-S.P1.y)/norme(S);
    Point E=Point(x_E,y_E);
    cout << E << endl;
    double d=distance(E,P);
    printf("d vaut %lf\n",d);
    if(d<=eps)
    {
        double MIN=min(S.P1.x,S.P2.x)-eps;
        double MAX=max(S.P1.x,S.P2.x)+eps;
        if((MIN<=x_E)&&(MAX>=x_E))
        {
            printf("Le Point est dans le segment\n");
            return(true);
        }
    }
    printf("Le Point n'est pas dans le segment\n");
    return(false);
}

bool point_segment1(const Segment& S,const Point& P,double eps)
{
    double a=(S.P1.y-S.P2.y)/(S.P1.x-S.P2.x);
    double b=a*S.P1.x-S.P1.y;
    if((a*P.x+b+eps>=P.y)&(a*P.x+b-eps<=P.y))
        {
        double MIN=min(S.P1.y,S.P2.y)-eps;
        double MAX=max(S.P1.y,S.P2.y)+eps;
        if((MIN<=P.y)&&(MAX>=P.y))
        {
            printf("Le Point est dans le segment\n");
            return(true);
        }

         }
    printf("Le Point n'est pas dans le segment\n");
    return(false);
}

ostream& operator<<(ostream& os,const Segment& seg){
    os << "Le premier point du segment est : "<< seg.P1 << endl;
    os << "Le deuxi�me point du segment est : " << seg.P2 <<endl;
    return os;
}

//=========================================================================
//Obstacle
//=========================================================================

/*
Obstacle::Obstacle(){
    nbsom = 0;
    sommets = vector<Point>(0,Point());
}
*/

Obstacle::Obstacle(int ns,const vector<Point> &obstacle_points){
    nbsom = ns;

    sommets = obstacle_points;
}

/*
Obstacle::Obstacle(const Obstacle& ob)
{
    nbsom=ob.nbsom;
    sommets=vector<Point>(0,Point());
    for(auto it = Ob.sommets.begin();it != Ob.sommets.end();++it){
        sommets.push_back(*it);
    }
}
*/

Obstacle::Obstacle(const Obstacle& ob)
{
    nbsom = ob.nbsom;
    sommets = ob.sommets;
}


Obstacle::~Obstacle()
{
    sommets.clear();
}

Obstacle& Obstacle::operator=(const Obstacle& ob)
{
    if (nbsom!=ob.nbsom)
    {
        nbsom=ob.nbsom;
        sommets.clear();
        sommets.resize(nbsom);
    }

    vector<Point>::iterator it = sommets.begin();
    vector<Point>::const_iterator it_ob;
    for(it_ob=ob.sommets.begin();it_ob != ob.sommets.end();it_ob++,it++) *it = *it_ob;
    return *this;
}

Obstacle& Obstacle::operator+=(Point& P){
    nbsom++;
    sommets.push_back(P);
    return *this;
}

Obstacle& Obstacle::reset(){
    nbsom=0;
    sommets.clear();
    return *this;
}

vector<Segment> Obstacle::segments_of_obstacle() const
{
    vector<Segment> segments;
    for(int i=0;i<nbsom-1;++i){
        segments.push_back(Segment(sommets[i],sommets[i+1]));
    }

    segments.push_back(Segment(sommets[nbsom-1],sommets[0]));
    return(segments);

}


ostream& operator<<(ostream& os,const Obstacle& ob){
    os << "Nb sommets = "<< ob.nbsom << endl;
    vector<Point>::const_iterator it_ob;
    for (it_ob = ob.sommets.begin(); it_ob != ob.sommets.end();++it_ob){
        os << *it_ob;
    }
    return os;
}

/*
void affichage(const obstacle& Ob)
{
    int nbsom=Ob.nbsom;
    Point * sommets=Ob.sommets;
    printf("Il y a  %d sommets\n",nbsom);
    for(int i=0;i<nbsom;i++) {
        printf("le sommet %d est :(%lf,%lf)\n",i,sommets[i].x,sommets[i].y);
    }
}
*/

//true si les segments s'intersectent et false sinon
bool intersection_segment(const Segment& seg1,const Segment& seg2, double epsilon,double eps)
{
    Point point_a = seg1.P1;
    Point point_b = seg1.P2;
    Point point_p = seg2.P1;
    Point point_q = seg2.P2;

    if(  (point_a == point_p) || (point_a == point_q) || (point_b == point_p) || (point_b == point_q) )
    {
        return false;
    }
    if(  abs( produit_scalaire(seg1,seg2) - norme(seg1)*norme(seg2) ) <= epsilon )
    {
        if(point_segment(seg2,point_a,epsilon) || point_segment(seg2,point_b,epsilon) ) //il n'y avait pas d'argument epsilon
        {
            return true;
        }
        else{return false;}
    }
    Segment segment_ab=Segment(point_a,point_b);
    Segment segment_pq=Segment(point_p,point_q);
    Segment normale_ab = normale(segment_ab);
    Segment normale_pq = normale(segment_pq);

    Segment segment_pa=Segment(point_p,point_a);
    Segment segment_ap=Segment(point_a,point_p);

    double alpha = produit_scalaire(segment_ap,normale_pq) / produit_scalaire(segment_ab,normale_pq);
    double beta = produit_scalaire(segment_pa,normale_ab) / produit_scalaire(segment_pq,normale_ab);

    if( (-eps <= alpha) && (alpha <= 1+eps) && (-eps <= beta) && (beta<= 1+eps))
    {
        /*
        printf("alpha = %lf\n",alpha);
        printf("%beta = %lf\n",beta);
        printf("Les deux segments s'intersectent\n");
        */
        return true;
    }
    else
    {
        /*
        printf("alpha = %lf\n",alpha);
        printf("%beta = %lf\n",beta);
        printf("Les deux segments ne s'intersectent pas\n");
        */
        return false;
    }

}

int comptage_intersection(const Segment& seg,const Obstacle& obst)
{

    Point p1 = seg.P1;
    Point p2 = seg.P2;
    double x_M = (p1.x+p2.x)/2;
    double y_M = (p1.y+p2.y)/2;
    Point M = Point(x_M,y_M);
    double x_M1 = x_M + 100;
    Point M1 = Point(x_M1,y_M);
    Segment seg_milieu = Segment(M,M1);
    int comptage_intersect = 0;

    const vector<Segment> segments = obst.segments_of_obstacle();
    vector<Segment>::const_iterator it;

    for(it=segments.begin();it!=segments.end();++it)
    {
        if( intersection_segment(seg_milieu,*it,0.1,0) )
        {
            comptage_intersect++;
        }
    }
    return comptage_intersect;

}

//renvoie true si le segment est valide par rapport � l'obstacle pass� en param�tre
bool intersection_segment_polygon(const Segment& seg,const Obstacle& polygone)
{
    const vector<Segment> segments = polygone.segments_of_obstacle();
    vector<Segment>::const_iterator it;

    for(it=segments.begin();it!=segments.end();++it)
    {
        if(intersection_segment(seg,*it,0.1,0))
        {
            return false;
        }
        if(seg == *it)
        {
            return true;
        }
    }
    int nombre_intersection_projete_milieu = comptage_intersection(seg,polygone);

    if(nombre_intersection_projete_milieu % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }


}

Arc::Arc(const Segment& S,double Len)
{
    edge = S;
    length_arc = Len;
}

ostream& operator <<(ostream& os,const Arc& A){
    os << A.edge <<  " : length = " <<  A.length_arc << endl;
    return os;
}

bool is_arc_valide(const Segment& seg,const vector<Obstacle> & vect_obstacles, int nb_obstacles)
{

    vector<Obstacle>::const_iterator it;
    for(it=vect_obstacles.begin();it != vect_obstacles.end();++it)
    {

        if(!intersection_segment_polygon(seg, *it))
        {
            return false;
        }
    }

    return true;
}

Graph::Graph(int nb_obstacles ,const vector<Obstacle> & vect_obstacles)
{
    liste_sommets = new Point[100];
    int m = 0;
    int nbr_arcs_crees = 0;

    vector<Obstacle>::const_iterator it_ob;

    for(it_ob=vect_obstacles.begin();it_ob!=vect_obstacles.end();++it_ob)
    {
        for(int i = 0; i<(*it_ob).nbsom;++i)
        {
            liste_sommets[m] = (*it_ob).sommets[i];
            m++;
        }
    }


    liste_arcs = new Arc[(m*(m-1))/2];
    nb_arcs = (m*(m-1)/2);
    int length_p_k = 0;

    it_ob = vect_obstacles.begin();

    for(int k=0;k<m;++k)
    {
        for(int p=k+1;p<m;++p)
        {
            const Segment segment_p_k = Segment(liste_sommets[k],liste_sommets[p]);
            if(is_arc_valide(segment_p_k,vect_obstacles,nb_obstacles))
            {
                Point p_k = liste_sommets[k];
                Point p_p = liste_sommets[p];
                length_p_k = distance(p_k,p_p);
            }
            else
            {
                length_p_k = -1;
            }
            liste_arcs[nbr_arcs_crees] = Arc(Segment(liste_sommets[k],liste_sommets[p]),length_p_k);
            nbr_arcs_crees++;
        }
    }

}


Graph::~Graph()
{
    if(liste_sommets != 0)  delete [] liste_sommets;
    if(liste_arcs != 0)  delete [] liste_arcs;
}


ostream & operator <<(ostream &os , const Graph &g)
{
    os << "affichage de tous les arcs :\n";
    for(int i=0; i<g.nb_arcs ; i++)
    {
       os<< g.liste_arcs[i] << endl;
    }
    return os ;
}
