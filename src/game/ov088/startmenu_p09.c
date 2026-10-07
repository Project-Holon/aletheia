/*
 * file:     startmenu_p09.c
 * unit:     yes
 * function: func_021BB5C4, func_021BB5E0, func_021BB608
 * address:  0x021BB5C4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_021BB798  0x021BB798  thumb  ov088
 *   func_021BB810  0x021BB810  thumb  ov088
 *   func_0200C308  0x0200C308  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021BD5EC     0x021BD5EC  data  a4
 */
#include "../../matched/include/Obj00014.h"

struct Actor;
struct PtS;
struct Obj;
struct Vec2;
struct Blk34;
typedef unsigned int   u32;

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} Pos;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

struct Ent {
    u16 f0;
    u16 f2;
};

extern u32 func_020307B0(void *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_021BB798(char *p, u32 i, u32 arg);
extern void func_021BB810(void *p, u8 row, int y, int pal);
extern u8 func_0200C308(struct Blk34 *p, u32 i);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021BB5C4(char *p);
void func_021BB5E0(char *p, u32 idx, s16 y);
void func_021BB608(char *p);
extern const struct Ent d_021BD5EC[];


/*
 * Frees the eight row buffers at +0xF8 allocated by func_021BB544.
 */
void func_021BB5C4(char *p)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        func_020307B0(*(void **)(p + 0xf8 + i * 4));
}


void func_021BB5E0(char *p, u32 idx, s16 y)
{
    Pos pos;
    func_0204B454(((void **)(p + 0x1c))[idx], (struct PtS *)&pos, 0);
    pos.y = y;
    func_0204B404(((void **)(p + 0x1c))[idx], (const struct Vec2 *)(&pos), 0);
}


/*
 * Lays out the up-to-eight menu rows listed at +0x120 (8 terminates),
 * stacking them by the heights in d_021BD5EC and positioning the row
 * sprites.  Row order is filled in by ov088_func_021BB4B4.c.
 */
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
