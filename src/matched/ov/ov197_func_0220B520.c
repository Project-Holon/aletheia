/*
 * function: func_0220B520
 * address: 0x0220B520
 * packet: pkt_ov197_0220B520
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_0220B4B8 0x0220B4B8 thumb ov197
 *   d_0220DA28 0x0220DA28 data a1
 *   d_0220DA19 0x0220DA19 data a1
 */
#include "../include/Obj00314.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void func_0220B4B8(char *,u16);
extern const char d_0220DA28[],d_0220DA19[];
void func_0220B520(char *p)
{
    u16 i;
    func_02041300(5,0,0,0,0x20,0x13,0x11);
    for(i=0;i<6;i++)func_0220B4B8(p,i);
    if(((u8 *)p)[0x141]==0)
        *(const char * *)&((struct Obj00314 *)p)->f59C=d_0220DA28;
    else
        *(const char * *)&((struct Obj00314 *)p)->f59C=d_0220DA19;
    ((u8 *)p)[0x141]^=1;
}
