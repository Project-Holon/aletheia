/*
 * function: ov208_func_021C6A10
 * address:  0x021C6A10
 * packet:   pkt_ov208_021C6A10
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B404        0x0204B404  arm
 *   func_0204B3DC        0x0204B3DC  arm
 *   func_0204B878        0x0204B878  arm
 *
 * show is reassigned 1 in the case 0 arm, which keeps it a live register
 * compare (cmp r1, #0) instead of a folded constant.
 */
#include "../include/Obj02258.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Ov208Pos;

extern void func_0204B404(u32 obj, Ov208Pos *pos, u16 flag);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B878(u32 obj, u8 v);

void ov208_func_021C6A10(void *unused, u8 *p)
{
    int show = 1;
    int multi = 0;
    int v;
    int w;
    Ov208Pos pos;

    switch (((struct Obj02258 *)p)->f6B8) {
    case 0:
        show = 1;
        break;
    case 4:
        if (((struct Obj02258 *)p)->f548 >= 2)
            multi = 1;
        break;
    }
    if (show && multi) {
        pos.x = 0;
        pos.y = 0;
        func_0204B404(((struct Obj02258 *)p)->f5EC, &pos, 0);
        pos.x = 0x80;
        pos.y = 0;
        func_0204B404(((struct Obj02258 *)p)->f5F0, &pos, 0);
    } else if (show) {
        pos.x = 0x40;
        pos.y = 0;
        func_0204B404(((struct Obj02258 *)p)->f5EC, &pos, 0);
    }
    if (*(u32 *)(p + ((struct Obj02258 *)p)->f54E * 16 + 0x14c) == 2)
        v = 1;
    else
        v = 0;
    func_0204B3DC((struct Obj *)((struct Obj02258 *)p)->f5EC, 1);
    func_0204B878(((struct Obj02258 *)p)->f5EC, v);
    if (multi) {
        w = *(u32 *)(p + ((struct Obj02258 *)p)->f550 * 16 + 0x14c) == 2;
        func_0204B3DC((struct Obj *)((struct Obj02258 *)p)->f5F0, 1);
        func_0204B878(((struct Obj02258 *)p)->f5F0, w);
    } else {
        func_0204B3DC((struct Obj *)((struct Obj02258 *)p)->f5F0, 0);
    }
}
