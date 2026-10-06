/*
 * function: func_020255A0
 * address:  0x020255A0
 * packet:   pkt_020255A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_0204A7A0  0x0204A7A0  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204BA20  0x0204BA20  arm
 *   func_02025A9C  0x02025A9C  thumb
 *   gModeTable     0x0209F87C  data
 *   g_020A7494     0x020A7494  data
 *
 * bmp_oam.c: build a grid of OAM actors over a bitmap, one 32x16 cell per
 * actor, each with its own character resource allocated by mode.
 *
 * Closed in wave 15 from 8 bytes (two one-instruction scheduling swaps:
 * `adds r3, r5, r3` / `ldr r2, [r4, #8]` and `str r0, [r6, #4]` /
 * `movs r2, #0`).  The lever was the declaration: param is a
 * `const struct Param *`.  With const, the stores into pt and the grid no
 * longer order the param field loads, and both swaps fall into the image's
 * order at once.  Every body spelling tried in waves 13 and 14 held at 8.
 */
#include "../include/Obj00934.h"
#include "../include/Obj06909.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Point {
    s16 x;
    s16 y;
    u16 f4;
    u8  f6;
    u8  f7;
};

struct Grid {
    void *bmp;
    void *act[25];
    void *res[24];
    u16   f_c8;
    u8    cols;
    u8    rows;
};

struct Sys {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 slot[3];
};

struct Param {
    void *bmp;
    s16   x;
    s16   y;
    u32   f8;
    u32   fc;
    u8    f10;
    u8    f11;
    u16   f12;
    u32   f14;
};

struct ModeEntry {
    u32 size;
    u32 a;
    u32 b;
};

extern const struct ModeEntry gModeTable[];
extern u8   g_020A7494[];

extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
struct Actor;
struct Bmp;
struct Obj;
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern s32 func_0204A7A0(u32 size, u32 a2, u16 heapId);
extern u32 func_02025A9C(struct Obj *obj, u32 engine, u32 arg);
extern struct Obj *func_0204B294(void *a, u32 res, u32 c, u32 d, const void *pt,
                           u16 f, u16 g);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204BA20(struct Actor *a, u32 v);

struct Grid *func_020255A0(struct Sys *sys, const struct Param *param)
{
    struct Point pt;
    u32 mode;
    struct Grid *g;
    u8 rows;
    u8 i;
    u8 j;
    u32 engine;
    u8 cols;
    u8 *row;
    u8 *cell;
    u32 yoff;
    u32 f8;

    {
        u16 *q = (u16 *)&pt;
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
    }

    g = func_02030734(sys->f4, 0xcc, 1, (const char *)g_020A7494, 0xa3);
    g->bmp = param->bmp;
    cols = (u8)(func_020437DC(g->bmp) >> 5);
    rows = (u8)(func_020437E4(param->bmp) >> 4);
    if ((s32)func_020437DC(param->bmp) % 32 != 0) {
        cols = (u8)(cols + 1);
    }
    if ((s32)func_020437E4(param->bmp) % 16 != 0) {
        rows = (u8)(rows + 1);
    }
    g->cols = cols;
    g->rows = rows;
    g->f_c8 = param->f12;
    ((struct Obj00934 *)g)->f64 = param->f14;

    engine = sys->f8;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            row = (u8 *)g + i * cols * 4;
            yoff = i << 4;
            mode = func_02025A9C((struct Obj *)sys, param->f14, engine);
            cell = row + j * 4;
            ((struct Obj06909 *)cell)->f68 =
                (void *)func_0204A7A0(gModeTable[mode].size, param->f14, sys->f4);
            pt.x = (s16)(param->x + (j << 5));
            pt.y = (s16)(param->y + yoff);
            f8 = param->f8;
            pt.f6 = param->f10;
            pt.f7 = param->f11;
            {
                void *act = func_0204B294((void *)sys->f0, (u32)((struct Obj06909 *)cell)->f68,
                                          f8, sys->slot[mode], &pt,
                                          param->f12, sys->f4);
                u32 fc = (u8)param->fc;
                ((struct Obj06909 *)cell)->f4 = act;
                func_0204B6F4(act, fc, 0);
            }
            func_0204BA20(((struct Obj06909 *)cell)->f4, 0);
        }
    }
    return g;
}
