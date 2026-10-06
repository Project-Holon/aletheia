/*
 * function: func_021C00AC
 * address: 0x021C00AC
 * packet: pkt_ov110_021C00AC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj06393.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { s16 x,y; } Vec2;
typedef unsigned int   u32;
struct Obj;
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021C00AC(u8 *p, unsigned i) {
    Vec2 pos;
    ((struct Obj06393 *)p)->f18=func_0204B3F4(((struct Obj06393 *)p)->f14);
    func_0204B3DC(((struct Obj06393 *)p)->f14,1);
    if (i != -1) {
        pos.x=0x70*(i&1)+0x3e;
        pos.y=0x18*((i>>1)+1);
        func_0204B404(((struct Obj06393 *)p)->f14,(const struct Vec2 *)(&pos),0);
        func_0204B878(((struct Obj06393 *)p)->f14,0x1c);
    }
}
