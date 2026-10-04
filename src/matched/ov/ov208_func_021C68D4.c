/*
 * function: ov208_func_021C68D4
 * address:  0x021C68D4
 * packet:   pkt_ov208_021C68D4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../include/Obj05545.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);

void ov208_func_021C68D4(void *unused, u8 *p)
{
    int on = 0;

    switch (((struct Obj05545 *)p)->f6B8) {
    case 0:
        if (((struct Obj05545 *)p)->f548 >= 2)
            on = 1;
        break;
    case 4:
        break;
    }
    if (on) {
        func_0204B3DC((struct Obj *)((struct Obj05545 *)p)->f668, 1);
        func_0204B3DC((struct Obj *)*(u32 *)(p + 0x668 + 0x28), 1);
    } else {
        func_0204B3DC((struct Obj *)((struct Obj05545 *)p)->f668, 0);
        func_0204B3DC((struct Obj *)*(u32 *)(p + 0x668 + 0x28), 0);
    }
}
