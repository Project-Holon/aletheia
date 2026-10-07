/*
 * file:     field_msgbg_p32.c
 * unit:     yes
 * function: func_0218DBAC, func_0218DBD4, func_0218DC04, func_0218DC4C
 * address:  0x0218DBAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02169848  0x02169848  thumb  ov010
 *   func_021694FC  0x021694FC  thumb ov010
 *   func_021697E0  0x021697E0  thumb ov010
 */
#include "../../matched/include/Obj01846.h"
#include "../../matched/include/Obj12585.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32_0218DBAC;

typedef int s32_0218DC04;

typedef s32_0218DC04 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Grid {
    u32 f00;
    s32_0218DC04 f04;            /* 0x04 cell size */
    u32 f08;
    u32 f0C;            /* 0x0C state */
    u32 f10;
    u16 f14;            /* 0x14 width in cells */
    u16 f16;            /* 0x16 depth in cells */
    u32 f18;
    void *f1C;          /* 0x1C */
} Grid;

typedef struct { int x, y, z; } V3;

extern void func_02169848(void *a, u8 *b, u32 c, u32 d);
extern u16 func_021694FC(u8 *p);
extern int func_021697E0(char *p);
int func_0218DBAC(u8 *a, int idx, u32 c, u8 *d);
int func_0218DBD4(char *p, int i);
int func_0218DC04(Grid *g, VecFx32 *pos);
void func_0218DC4C(char *o, V3 *v);


int func_0218DBAC(u8 *a, int idx, u32 c, u8 *d)
{
    u32 buf[0x41];
    func_02169848(buf, (u8 *)(*(u32 *)(*(u8 * *)&((struct Obj01846 *)a)->f24 + idx * 0x28)), c, ((struct Obj01846 *)a)->f4);
    ((struct Obj12585 *)d)->f8 = buf[2];
    ((struct Obj12585 *)d)->fC = buf[3];
    return 1;
}


int func_0218DBD4(char *p, int i)
{
    if (((struct Obj01846 *)p)->f1C == 0)
        return 0;
    if (func_021694FC((u8 *)(*(int *)(*(char * *)&((struct Obj01846 *)p)->f24 + i * 0x28))) == 0)
        return 0;
    return func_021697E0((char *)(*(int *)(*(char * *)&((struct Obj01846 *)p)->f24 + i * 0x28)));
}


/*
 * Unlabelled ov021 leaf (a `.word` run in the listing, no lr save), the
 * sole blocker of ov010 func_021638CC. Returns 1 (outside) unless the
 * grid is present, not in state 2, and pos.x/pos.z fall inside the
 * w*cell by d*cell rectangle.
 */
int func_0218DC04(Grid *g, VecFx32 *pos)
{
    s32_0218DC04 w;
    s32_0218DC04 d;

    if (g->f1C == 0)
        return 1;
    if (g->f0C == 2)
        return 0;
    w = g->f14 * g->f04;
    d = g->f16 * g->f04;
    if (pos->x >= 0 && pos->x < w && pos->z >= 0 && pos->z < d)
        return 0;
    return 1;
}


/*
 * Unlabelled leaf: copies the 12-byte vector at r1 into the object at +0x54.
 * Filed as the only blocker of ov052 func_021F38F0.
 */
void func_0218DC4C(char *o, V3 *v)
{
    *(V3 *)(o + 0x54) = *v;
}
