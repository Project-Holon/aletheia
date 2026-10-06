/*
 * function: func_021BB608
 * address:  0x021BB608
 * packet:   pkt_ov088_021BB608
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lays out the up-to-eight menu rows listed at +0x120 (8 terminates),
 * stacking them by the heights in d_021BD5EC and positioning the row
 * sprites.  Row order is filled in by ov088_func_021BB4B4.c.
 *
 * symbols:
 *   func_021BB798  0x021BB798  thumb  ov088
 *   func_021BB5E0  0x021BB5E0  thumb  ov088
 *   func_021BB810  0x021BB810  thumb  ov088
 *   func_0200C308  0x0200C308  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021BD5EC     0x021BD5EC  data  a4
 */
#include "../include/Obj00014.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct Ent {
    u16 f0;
    u16 f2;
};

extern const struct Ent d_021BD5EC[];

extern void func_021BB798(char *p, u32 i, u32 arg);
extern void func_021BB5E0(char *p, u32 idx, s16 y);
struct Blk34;
struct Obj;
extern void func_021BB810(void *p, u8 row, int y, int pal);
extern u8 func_0200C308(struct Blk34 *p, u32 i);
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021BB608(char *p)
{
    u32 i;
    s8 y;
    u8 v;
    void *obj;

    i = 0;
    p[0x128] = 0;
    ((struct Obj00014 *)p)->f130 = 0;
    y = 2;
    p[0x12f] = 2;
    for (i = 0; i < 8; i++) {
        if ((u8)(p + i)[0x120] == 8)
            break;
        func_021BB798(p, (u8)(p + i)[0x120], y);
        v = (p + i)[0x120];
        if (v == 0) {
            obj = ((struct Obj00014 *)p)->f1C;
        } else if (v == 5) {
            func_021BB5E0(p, 5, y * 8 + d_021BD5EC[v].f2 * 8 / 2);
            obj = ((struct Obj00014 *)p)->f30;
        } else if (v == 3) {
            if (func_0200C308(((struct Obj00014 *)p)->f8, 1) != 1)
                goto next;
            func_021BB5E0(p, 2, y * 8 + d_021BD5EC[(u8)(p + i)[0x120]].f2 * 8 / 2);
            obj = ((struct Obj00014 *)p)->f24;
        } else if (v == 4) {
            if (func_0200C308(((struct Obj00014 *)p)->f8, 2) != 1)
                goto next;
            func_021BB5E0(p, 3, y * 8 + d_021BD5EC[(u8)(p + i)[0x120]].f2 * 8 / 2);
            obj = ((struct Obj00014 *)p)->f28;
        } else if (v == 7) {
            if (func_0200C308(((struct Obj00014 *)p)->f8, 3) != 1)
                goto next;
            func_021BB5E0(p, 4, y * 8 + d_021BD5EC[(u8)(p + i)[0x120]].f2 * 8 / 2);
            obj = ((struct Obj00014 *)p)->f2C;
        } else {
            goto next;
        }
        func_0204B3DC(obj, 1);
    next:
        y += (s8)d_021BD5EC[(u8)(p + i)[0x120]].f2;
    }
    func_021BB5E0(p, 0, 0x40);
    func_021BB810(p, (u8)p[0x120], (s8)p[0x12f], 2);
}
