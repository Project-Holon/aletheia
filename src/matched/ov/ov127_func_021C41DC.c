/*
 * function: func_021C41DC
 * address: 0x021C41DC
 * packet: pkt_ov127_021C41DC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B528 0x0204B528 arm
 */
#include "../include/Obj10463.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
typedef struct Pt {u16 x,y;} Pt;
extern void func_0204B528(struct Actor *, const struct Pt *);
void func_021C41DC(u8 *p,int x,int y)
{
    Pt pos;
    pos.x=x; pos.y=y;
    func_0204B528(*(struct Actor * *)&((struct Obj10463 *)p)->f4, &pos);
    if (((struct Obj10463 *)p)->f8 != 0) {
        pos.x=(s16)pos.x+8;
        pos.y=(s16)pos.y+14;
        func_0204B528(*(struct Actor * *)&((struct Obj10463 *)p)->f8, &pos);
    }
}
