#include "shapes.h"
#include "shapeFuncs.h"
#include "tddFuncs.h"

int main()
{

   struct Box b1, b2;

   initBox(&b1, 3.0, 4.0, 7.0, 8.0);
   assertEquals("ul=(3,4),w=7,h=8", boxToString(b1), "boxToString(b1)");

   initBox(&b2, 3.14159, 6.2831853071, 7.4542124, 9.31289675);
   assertEquals("ul=(3.14,6.28),w=7.45,h=9.31", boxToString(b2), "boxToString(b2)");
   assertEquals("ul=(3,6),w=7,h=9", boxToString(b2, 1), "boxToString(b2,1)");
   assertEquals("ul=(3.142,6.283),w=7.454,h=9.313", boxToString(b2, 4), "boxToString(b2,4)");
   assertEquals("ul=(3.1416,6.2832),w=7.4542,h=9.3129", boxToString(b2, 5), "boxToString(b2,5)");

   return 0;
}
