/*
 * function: func_021FCEDC
 * address: 0x021FCEDC
 * packet: pkt_ov186_021FCEDC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035BA4 0x02035BA4 arm
 *   func_02035CB8 0x02035CB8 arm
 *   d_02200AF0 0x02200AF0 data a4
 */
#include "../include/Obj00048.h"
extern int func_02035BA4(const void *);
typedef unsigned int   u32;
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern const char d_02200AF0[];
int func_021FCEDC(char *p)
{
    int x,y;
    int direction=0;
    int delta,absolute;
    if(func_02035BA4(d_02200AF0)!=-1) {
        func_02035CB8((u32 *)(&x),(u32 *)(&y));
        if(((struct Obj00048 *)p)->f84==0) {((struct Obj00048 *)p)->f84=1;((struct Obj00048 *)p)->f88=y;}
        else {
            delta=y-((struct Obj00048 *)p)->f88;
            if(delta<0) absolute=-delta;else absolute=delta;
            if(absolute>8) {
                if(delta<0) direction=-1;else direction=1;
                ((struct Obj00048 *)p)->f88=y;
            }
        }
    } else if(((struct Obj00048 *)p)->f84) ((struct Obj00048 *)p)->f84=0;
    return direction;
}
