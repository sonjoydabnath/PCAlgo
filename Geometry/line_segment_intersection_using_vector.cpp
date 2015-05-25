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

class PT
{
public:
    double x, y;
    PT(){}
    PT(double x, double y):x(x),y(y){}
    void scan(){scanf("%lf%lf",&x,&y);}
};

//class LineSegment
//{
//public:
//    PT v0,v1; // Line segment through two points v0,v1
//    LineSegment(){}
//    LineSegment(PT begin,PT end){v0=begin;v1=end;}
//    enum IntersectResult { PARALLEL, COINCIDENT, INTERESECTING };
//    IntersectResult Intersect(const LineSegment& L, double& t0,double &t1){
//        double denom = ((L.v1.y - L.v0.y)*(v1.x - v0.x)) -
//                      ((L.v1.x - L.v0.x)*(v1.y - v0.y));
//        double nume_a = ((L.v1.x - L.v0.x)*(v0.y - L.v0.y)) -
//                       ((L.v1.y - L.v0.y)*(v0.x - L.v0.x));
//        double nume_b = ((v1.x - v0.x)*(v0.y - L.v0.y)) -
//                       ((v1.y - v0.y)*(v0.x - L.v0.x));
//        if(Z(denom)){
//            if(Z(nume_a) && Z(nume_b))
//                return COINCIDENT;
//            return PARALLEL;
//        }
//        t0 = nume_a / denom;
//        t1 = nume_b / denom;
//        return INTERESECTING;
//    }
//};


class LineSegment
{
public:
    PT v0;
    PT v1;

    LineSegment(){}
    LineSegment(const PT& begin, const PT& end)
        : v0(begin), v1(end) {}

    enum IntersectResult { PARALLEL, COINCIDENT, NOT_INTERESECTING, INTERESECTING };

    IntersectResult Intersect(const LineSegment& L, PT& intersection)
    {
        double denom = ((L.v1.y - L.v0.y)*(v1.x - v0.x)) -
                      ((L.v1.x - L.v0.x)*(v1.y - v0.y));

        double nume_a = ((L.v1.x - L.v0.x)*(v0.y - L.v0.y)) -
                       ((L.v1.y - L.v0.y)*(v0.x - L.v0.x));

        double nume_b = ((v1.x - v0.x)*(v0.y - L.v0.y)) -
                       ((v1.y - v0.y)*(v0.x - L.v0.x));

        if(denom == 0.0f){
            if(nume_a == 0.0f && nume_b == 0.0f)
                return COINCIDENT;
            return PARALLEL;
        }
        double ua = nume_a / denom;
        double ub = nume_b / denom;
        if(ua >= 0.0f && ua <= 1.0f && ub >= 0.0f && ub <= 1.0f){
            // Get the intersection point.
            intersection.x = v0.x + ua*(v1.x - v0.x);
            intersection.y = v0.y + ua*(v1.y - v0.y);
            return INTERESECTING;
        }
        return NOT_INTERESECTING;
    }
};
