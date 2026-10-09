/*
 * file:     fldmmdl_blact_p03.c
 * unit:     yes
 * function: func_0219CAD8, func_0219CAF4, func_0219CB24
 * address:  0x0219CAD8
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
 *   func_0216D4F8  0x0216D4F8  thumb
 *   func_0219CA00  0x0219CA00  thumb  ov021
 *   func_0219CB98  0x0219CB98  thumb  ov021
 *   func_0219CA34  0x0219CA34  thumb  ov021
 *   func_0219D3F0  0x0219D3F0  thumb  ov021
 *   func_0219CA40  0x0219CA40  thumb  ov021
 */
#include "../../matched/include/Obj17970.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;

typedef struct { int n; Ent *e; } Tbl;

extern u32 func_0216D4F8(u32, u32, u32, u32);
extern u32 func_0219CA00(u32, u32, u32);
extern void func_0219CB98(u8 *, u16);
extern void func_0219CA34(u8 *p);
extern unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5);
extern void func_0219CA40(u8 *, u32, u32, u32);
int func_0219CAD8(u32 a, u32 b, u32 c, u32 d);
void func_0219CAF4(u8 *s);
void func_0219CB24(u8 *o, u32 a, u32 b, u32 c, u8 s0, u32 s1);


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D4F8 (0x0216D4F8) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219CAD8(u32 a, u32 b, u32 c, u32 d)
{
return func_0219CA00((a + 20), b, func_0216D4F8(((struct Obj17970 *)((u8 *)(a)))->f10, b, c, d));
}


void func_0219CAF4(u8 *s)
{
    int i;
    Ent *e = ((Tbl *)(s + 0x14))->e;
    i = 0;
    do {
        if (e->a != 0xFFFF) {
            func_0219CB98(s, e->a);
        }
        i++;
        e++;
    } while (i < ((Tbl *)(s + 0x14))->n);
    func_0219CA34((u8 *)(s + 0x14));
}


/*
 * Addresses are Black-image addresses.
 */
void func_0219CB24(u8 *o, u32 a, u32 b, u32 c, u8 s0, u32 s1)
{
    int r = -1;
    u32 t;
    if (s1 & 2) r = 2;
    t = func_0219D3F0((int *)o, b, c, s0, a, r);
    func_0219CA40(o + 0x14, b, t, (u16)s1);
}
