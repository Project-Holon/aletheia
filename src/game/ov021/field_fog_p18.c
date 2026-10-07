/*
 * file:     field_fog_p18.c
 * unit:     yes
 * function: func_021A0B4C, func_021A0C50, func_021A0C60, func_021A0C74
 * address:  0x021A0B4C
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
 *   func_021A0860  0x021A0860  thumb  ov021
 *   func_021A0918  0x021A0918  thumb  ov021
 *   func_021A0A50  0x021A0A50  thumb  ov021
 *   func_021A0B34  0x021A0B34  thumb  ov021
 *   func_021A0980  0x021A0980  thumb  ov021
 */
#include "../../matched/include/Obj01034.h"
#include "../../matched/include/Obj03125.h"
#include "../../matched/include/Obj07214.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

typedef signed char    s8;

extern u16 func_021A0860(const void *o, u32 x, u32 y);
extern void func_021A0918(u8 *a, s32 x, s32 y, s16 *out);
extern void func_021A0A50(u8 *a, u8 *b, u32 c, u32 d);
extern int func_021A0B34(u32 a);
extern void func_021A0980(u8 *a, u8 *b, u8 *c, u32 d);
void func_021A0B4C(const u8 *a, u8 *b);
int func_021A0C50(u32 a, u16 b, u32 c, u32 d);
void func_021A0C60(u16 *p, u16 a, u16 b);
s32 func_021A0C74(u16 *a, void *b, void *c, void *d);


/*
 * Inverse of func_021A0A50. The source pointer must be const: without it
 * the six trailing strh stores are scheduled ahead of the next call's
 * `adds rN, #0xf0/#0xf2` address setup (24 bytes differ).
 *
 * Addresses are Black-image addresses.
 */
void func_021A0B4C(const u8 *a, u8 *b)
{
    s32 i;
    u16 r;

    ((struct Obj03125 *)b)->f0 = *(const u16 *)&((struct Obj01034 *)a)->f0;
    ((struct Obj03125 *)b)->f2 = *(const s16 *)&((struct Obj01034 *)a)->f2;
    for (i = 0; i < 4; i++) {
        *(u16 *)(b + 8 + i * 2) = func_021A0860(a + 8 + i * 12, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
        func_021A0918((u8 *)(a + 0x38 + i * 0x1c), *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2, (s16 *)(b + 0x10 + i * 6));
        b[4 + i] = a[4 + i];
    }
    r = func_021A0860(a + 0xa8, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f28 = r;
    r = func_021A0860(a + 0xb4, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f2A = r;
    r = func_021A0860(a + 0xc0, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f2C = r;
    r = func_021A0860(a + 0xcc, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f2E = r;
    r = func_021A0860(a + 0xd8, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f30 = r;
    r = func_021A0860(a + 0xe4, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f32 = r;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0C50(u32 a, u16 b, u32 c, u32 d)
{
((struct Obj07214 *)((u8 *)(a)))->f0 = 1;
((struct Obj07214 *)((u8 *)(a)))->f2 = b;
((struct Obj07214 *)((u8 *)(a)))->f4 = c;
((struct Obj07214 *)((u8 *)(a)))->f6 = d;
return a;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A0C60(u16 *p, u16 a, u16 b)
{
    p[0] = 1;
    p[1] = a;
    p[3] = b;
    p[2] = 0xFFFF;
}


s32 func_021A0C74(u16 *a, void *b, void *c, void *d)
{
    switch (a[0]) {
    case 1:
        func_021A0A50(b, c, a[3], a[1]);
        a[0] = 2;
        break;
    case 2:
        if (func_021A0B34((u32)b) == 0) {
            if (a[2] != 0xFFFF) {
                func_021A0980(b, c, d, a[2]);
            }
            a[0] = 3;
        }
        break;
    case 3:
        if (func_021A0B34((u32)b) == 0) {
            a[0] = 0;
        }
        break;
    case 0:
        return 1;
    }
    return 0;
}
