
#include <iostream>

using namespace std;
struct Point
{
    int x;
    int y;
}P[10];
int Direction(struct Point pi,struct Point pj,struct Point pk)
{
    int x1 =  pk.x-pi.x;
    int x2 =  pj.x-pi.x;
    int y1 =  pk.y-pi.y;
    int y2 =  pj.y-pi.y;
    int result = (x1 * y2) - (y1 * x2);
    return result;
    
}
bool onsegment(struct Point pi,struct Point pj,struct Point pk)
{
    if((min(pi.x,pj.x)<=pk.x<=max(pi.x,pj.x)) && (min(pi.y,pj.y)<=pk.y<=max(pi.y,pj.y)))
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}
bool Segment_intersect(struct Point P1,struct Point P2,struct Point P3,struct Point P4)
{
    int d1 = Direction(P3,P4,P1);
    int d2 = Direction(P3,P4,P2);
    int d3 = Direction(P1,P2,P3);
    int d4 = Direction(P1,P2,P4);
    
    if(((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0)))
    {
        return true;
    }
    else if(d1 = 0 && onsegment(P3,P4,P1))
    {
        return true;
    }
     else if(d2 = 0 && onsegment(P3,P4,P2))
    {
        return true;
    }
     else if(d3 = 0 && onsegment(P1,P2,P3))
    {
        return true;
    }
     else if(d4 = 0 && onsegment(P1,P2,P4))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
   P[1].x = 1;
   P[1].y = 1;
   P[2].x = 4;
   P[2].y = 8;
   P[3].x = 2;
   P[3].y = 6;
   P[4].x = 6;
   P[4].y = 3;

  cout<<Segment_intersect(P[1],P[2],P[3],P[4]);
    return 0;
}


