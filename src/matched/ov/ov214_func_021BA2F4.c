/*
 * function: func_021BA2F4
 * address: 0x021BA2F4
 * packet: pkt_ov214_021BA2F4
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FA08 0x0203FA08 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02030734 0x02030734 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021BB658 0x021BB658 data a1
 */
#include "../include/Obj04633.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const char d_021BB658[];
extern unsigned func_0203FA08(unsigned,unsigned,unsigned);
extern void func_0203FB44(unsigned,unsigned,unsigned);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void*func_02030734(unsigned,unsigned,int,const char*,u16);
extern void func_02040E78(unsigned,void*,unsigned,unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021BA2F4(int unused,char*p)
{
    unsigned off;
    u16*colors;
    off=func_0203FA08(1,0x500,1);
    func_0203FB44(1,off,0x500);
    func_02049B40(0x17,5,0,0x160,0x20,((struct Obj04633 *)p)->f0);
    colors=func_02030734(((struct Obj04633 *)p)->f0,6,1,d_021BB658,0x6f9);
    colors[0]=0x294b;colors[1]=0x5694;colors[2]=0x7fff;
    func_02040E78(2,colors,6,0x17a);
    func_020307B0(colors);
    ((struct Obj04633 *)p)->f80=1;((struct Obj04633 *)p)->f81=0x18;((struct Obj04633 *)p)->f82=0xd;((struct Obj04633 *)p)->f83=0xb;
    ((struct Obj04633 *)p)->f84=off;
}
