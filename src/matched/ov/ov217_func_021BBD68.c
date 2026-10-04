/*
 * function: func_021BBD68
 * address: 0x021BBD68
 * packet: pkt_ov217_021BBD68
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BBF04 0x021BBF04 thumb ov217
 *   func_021BBF1C 0x021BBF1C thumb ov217
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021BBF04(u32 p,u32 slot);
extern u32 func_021BBF1C(u32 p,u32 slot);
extern void func_020413B0(u32 layer,u32 x,u32 y,u8 width,u8 height,u8 pal);
extern void func_02041B6C(u32 layer);
void func_021BBD68(u8 *p)
{
    u8 slot;
    u32 x;
    u32 y;
    slot=p[0x32];
    x=func_021BBF04((u32)p,slot);
    y=func_021BBF1C((u32)p,slot);
    func_020413B0(2,x,y,28,3,10);
    func_02041B6C(2);
    ((struct Obj00025 *)p)->f160=1;
}
