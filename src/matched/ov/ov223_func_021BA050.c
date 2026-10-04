/*
 * function: func_021BA050
 * address: 0x021BA050
 * packet: pkt_ov223_021BA050
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: named row and entry pointers preserve the load scheduling.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
#include "../include/Obj10980.h"
typedef unsigned char u8;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
void func_021BA050(char *p)
{
    u8 i,j;
    char *row,*entry;
    for(i=0;i<3;i++) {
        row=p+i*148;
        for(j=0;j<2;j++) {
            func_0204B3B4(*(void **)(row+108+j*4));
            entry=row+j*12;
            func_0204AFD8(((struct Obj10980 *)entry)->f5C);
            func_0204A8D4(((struct Obj10980 *)entry)->f54);
            if(j!=1) func_0204ADA4(((struct Obj10980 *)entry)->f58);
        }
    }
}
