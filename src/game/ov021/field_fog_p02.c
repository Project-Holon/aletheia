/*
 * file:     field_fog_p02.c
 * unit:     yes
 * function: func_0219F5D4, func_0219F628
 * address:  0x0219F5D4
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
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 */
#include "../../matched/include/Obj09179.h"

typedef unsigned int u32;

typedef signed int   s32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02048AE8(u32, s32 *);
extern void func_02048B0C(u32, s32 *);
extern void func_02048B30(u32, s32 *);
extern void func_0207BCA0(s32 *, s32 *, s32 *, s32 *);
extern void func_02082B60(s32 *, s32 *);
extern void func_0207B0A4(s32 *, s32 *);
extern void func_0207B51C(s32 *, s32 *, s32 *);
void func_0219F5D4(u32 a, s32 *b, s32 *c);
int func_0219F628(u32 a, u32 b, u32 c, u32 d);


/*
 * Addresses are Black-image addresses.
 */
void func_0219F5D4(u32 a, s32 *b, s32 *c)
{
    s32 v1[3];
    s32 v2[3];
    s32 v3[3];
    s32 m4[12];
    s32 m3[9];
    func_02048AE8(a, v1);
    func_02048B0C(a, v2);
    func_02048B30(a, v3);
    func_0207BCA0(v1, v2, v3, m4);
    func_02082B60(m4, m3);
    func_0207B0A4(m3, m3);
    func_0207B51C(b, m3, c);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219F628(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj09179 *)((u8 *)(d)))->f0 = 0;
((struct Obj09179 *)((u8 *)(d)))->f4 = 0;
((struct Obj09179 *)((u8 *)(d)))->f8 = 0;
return 0;
}
