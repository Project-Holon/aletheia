/*
 * function: func_02184BAC
 * address: 0x02184BAC
 * packet: pkt_ov219_02184BAC
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 */
#include "../include/Obj01439.h"
typedef unsigned short u16;
struct MsgBank;struct R;
extern void *func_02045EC0(struct MsgBank *,unsigned);
extern struct R *APP_TASKMENU_RES_Create(u16,u16,unsigned,unsigned,u16);
void func_02184BAC(char *p)
{
    ((struct Obj01439 *)p)->fC064=func_02045EC0(*(struct MsgBank * *)&((struct Obj01439 *)p)->fC070,13);
    ((struct Obj01439 *)p)->fC068=func_02045EC0(*(struct MsgBank * *)&((struct Obj01439 *)p)->fC070,16);
    *(struct R * *)&((struct Obj01439 *)p)->fC058=APP_TASKMENU_RES_Create(2,9,((struct Obj01439 *)p)->fC06C,((struct Obj01439 *)p)->fC080,(u16)((struct Obj01439 *)p)->f0);
    ((struct Obj01439 *)p)->fC08C=((struct Obj01439 *)p)->fC064;
    ((struct Obj01439 *)p)->fC090=0x39e3;((struct Obj01439 *)p)->fC094=0;
    ((struct Obj01439 *)p)->fC098=((struct Obj01439 *)p)->fC068;
    ((struct Obj01439 *)p)->fC09C=0x39e3;((struct Obj01439 *)p)->fC0A0=1;
}
