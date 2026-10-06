/*
 * function: func_02205D58
 * address:  0x02205D58
 * packet:   pkt_ov094_02205D58
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220A392  0x0220A392  data  ov094  a2
 */
#include "../include/Obj06327.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct Point { s16 x, y; } Point;
typedef struct { void *h; int x; } Slot;
extern const u16 d_0220A392[];
struct Obj;
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);

void func_02205D58(char *p, int mode)
{
    Slot *slots;
    Point pos;
    int add;
    int step;
    char *row;
    int i;

    if (mode == 1) {
        slots = (Slot *)(p + 0x14c);
        pos.x = 0x94;
        pos.y = 0x30;
        step = -8;
        add = 4;
    } else {
        slots = (Slot *)(p + 0x11c);
        pos.x = 0x58;
        pos.y = 0x88;
        step = 0x10;
        add = 0;
    }
    i = 0;
    row = p + mode * 0x48;
    for (; i < 6; i++) {
        slots[i].h = func_0204B294((void *)((struct Obj06327 *)p)->f118, ((struct Obj06327 *)p)->f104, ((struct Obj06327 *)p)->f108, ((struct Obj06327 *)p)->f10C, d_0220A392, 1, ((struct Obj06327 *)p)->f240);
        func_0204B404(slots[i].h, (const struct Vec2 *)(&pos), 1);
        func_0204B92C(slots[i].h, 1);
        func_0204B878(slots[i].h, add + *(u8 *)(row + i * 12 + 0x75));
        pos.x += (s16)step;
    }
}
