#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;
#define EPS .0000000001
#define Z(x) fabs(x)<EPS
#define iqu(x,y) Z(fabs(x-y))
#define ge(x,y) (Z(x-y) || x>y)
#define le(x,y) (Z(x-y) || x<y)

class Vector
{
public:
    double x, y;
    Vector(){}
    Vector(double x, double y):x(x),y(y){}
    void scan(){scanf("%lf%lf",&x,&y);}
};

class LineSegment
{
public:
    Vector v0,v1; // Line segment through two points v0,v1
    LineSegment(){}
    LineSegment(Vector begin,Vector end){v0=begin;v1=end;}
    enum IntersectResult { PARALLEL, COINCIDENT, INTERESECTING };
    IntersectResult Intersect(const LineSegment& L, double& t0,double &t1)
    {
        double denom = ((L.v1.y - L.v0.y)*(v1.x - v0.x)) -
                      ((L.v1.x - L.v0.x)*(v1.y - v0.y));
        double nume_a = ((L.v1.x - L.v0.x)*(v0.y - L.v0.y)) -
                       ((L.v1.y - L.v0.y)*(v0.x - L.v0.x));
        double nume_b = ((v1.x - v0.x)*(v0.y - L.v0.y)) -
                       ((v1.y - v0.y)*(v0.x - L.v0.x));
        if(Z(denom))
        {
            if(Z(nume_a) && Z(nume_b))
                return COINCIDENT;
            return PARALLEL;
        }
        t0 = nume_a / denom;
        t1 = nume_b / denom;

        return INTERESECTING;
    }
};
