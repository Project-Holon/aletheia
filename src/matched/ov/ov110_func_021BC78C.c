/*
 * function: PMSIV_BGSCROLL_Start
 * address: 0x021BC78C
 * packet: pkt_ov110_021BC78C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_GetChannelScrollX 0x02041648 arm
 *   BG_SYS_GetChannelScrollY 0x02041664 arm
 */
#include "../include/Obj02461.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int BG_SYS_GetChannelScrollX(u8 channel);
typedef unsigned int   u32;
extern u32 BG_SYS_GetChannelScrollY(u8 channel);
void PMSIV_BGSCROLL_Start(u8 *p, int a, int b, int step, int n)
{
    ((struct Obj02461 *)p)->f0=a;
    if (b==0) {
        ((struct Obj02461 *)p)->f8=BG_SYS_GetChannelScrollX(a);
        ((struct Obj02461 *)p)->f4=0;
    } else {
        ((struct Obj02461 *)p)->f8=BG_SYS_GetChannelScrollY(a);
        ((struct Obj02461 *)p)->f4=3;
    }
    ((struct Obj02461 *)p)->fC=(((struct Obj02461 *)p)->f8+step)&511;
    ((struct Obj02461 *)p)->f8<<=12;
    ((struct Obj02461 *)p)->f10=(step<<12)/n;
    ((struct Obj02461 *)p)->f14=n;
    ((struct Obj02461 *)p)->f16=0;
}
