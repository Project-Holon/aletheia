/*
 * function: func_021C48FC
 * address: 0x021C48FC
 * packet: pkt_ov136_021C48FC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 */
#include "../include/Obj00275.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 x,y,w,h; } Template;
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02027778(Template *, void *);
struct Chan02021FD8;
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void func_0202843C(u8 *p);
void func_021C48FC(u8 *p)
{
    Template t;
    ((struct Obj00275 *)p)->f110 = (u32)func_02045EC0(((struct Obj00275 *)p)->f20, 4);
    ((struct Obj00275 *)p)->f114 = 0x39E3;
    ((struct Obj00275 *)p)->f118 = 0;
    ((struct Obj00275 *)p)->f11C = (u32)func_02045EC0(((struct Obj00275 *)p)->f20, 5);
    ((struct Obj00275 *)p)->f120 = 0x39E3;
    ((struct Obj00275 *)p)->f124 = 0;
    t.heap = ((struct Obj00275 *)p)->f0;
    t.count = 2;
    t.items = p + 0x110;
    t.zero = 0;
    t.x = 23;
    t.y = 6;
    t.w = 8;
    t.h = 3;
    ((struct Obj00275 *)p)->f10C = func_02027778(&t, ((struct Obj00275 *)p)->f108);
    func_02021FD8(((struct Obj00275 *)p)->f38, 0, 0, 48, 10, 0);
    func_0202843C(((struct Obj00275 *)p)->f128);
    func_0202843C(((struct Obj00275 *)p)->f12C);
}
