/*
 * function: FIELD_G3D_MAPPER_LayoutLinear
 * address:  0x0218D1D0
 * packet:   pkt_ov021_0218D1D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207C768  0x0207C768  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   _ll_mul        0x0209C054  arm
 *   FIELD_G3D_MAPPER_SetCellGridIndex  0x0218DD80  thumb  ov021
 *   FIELD_G3D_MAPPER_SetCellPos  0x0218DD9C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02687.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct Elem { int idx; int x; int y; int z; } Elem;

extern u32 func_0207C768(u32 a, u32 b);
extern void FIELD_G3D_MAPPER_SetCellGridIndex(u8 *p, u32 v);
extern void FIELD_G3D_MAPPER_SetCellPos(Elem *e, int x, int y, int z);

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}

void FIELD_G3D_MAPPER_LayoutLinear(char *p, void *a, Elem *e)
{
    int r;
    int c;
    int idx;
    int col;
    u32 rows;
    u32 n;
    int base;
    u32 row;
    int y;
    int t;
    int s;

    n = ((struct Obj02687 *)p)->f14 * ((struct Obj02687 *)p)->f16;
    rows = ((struct Obj02687 *)p)->f18 / n;
    if (((struct Obj02687 *)p)->f18 % n != 0)
        rows++;
    s = ((struct Obj02687 *)p)->f4;
    base = func_0207C768(((struct Obj02687 *)p)->f4, 0x2000);
    idx = 0;
    t = ((struct Obj02687 *)p)->f8;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < n; col++) {
            y = FX_Mul(row << 12, t);
            c = col % ((struct Obj02687 *)p)->f14;
            r = col / ((struct Obj02687 *)p)->f14;
            if (idx >= ((struct Obj02687 *)p)->f18)
                idx = -1;
            FIELD_G3D_MAPPER_SetCellGridIndex((u8 *)(e + idx), idx);
            FIELD_G3D_MAPPER_SetCellPos(e + idx, base + FX_Mul(c << 12, s), y, base + FX_Mul(r << 12, s));
            idx++;
        }
    }
}

