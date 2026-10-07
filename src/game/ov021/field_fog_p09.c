/*
 * file:     field_fog_p09.c
 * unit:     yes
 * function: func_021A0170, func_021A01A4, func_021A01AC, func_021A01B4
 * address:  0x021A0170
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
 *   func_0207DC44  0x0207DC44  arm
 *   func_0207DD10  0x0207DD10  arm
 */
#include "../../matched/include/Obj03581.h"
#include "../../matched/include/Obj12078.h"
#include "../../matched/include/Obj12079.h"
#include "../../matched/include/Obj07212.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed char    s8;

extern void func_0207DC44(int enable, int fogMode, int fogSlope, int fogOffset);
extern void func_0207DD10(u8 *);
void func_021A0170(u8 *p, u32 a1, u32 a2, u32 a3);
int func_021A01A4(u32 a, u32 b);
int func_021A01AC(u32 a, u32 b);
int func_021A01B4(u32 a, u32 b);


static inline void SetFogColor(u16 color, int alpha)
{
    *(volatile u32 *)0x04000358 = (u32)(color | (alpha << 16));
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A0170(u8 *p, u32 a1, u32 a2, u32 a3)
{
    if (((struct Obj03581 *)p)->f40) {
        func_0207DC44(p[0], p[1], p[2], ((struct Obj03581 *)p)->f4);
        SetFogColor(((struct Obj03581 *)p)->f8, p[3]);
        func_0207DD10(p + 0xc);
        ((struct Obj03581 *)p)->f40 = 0;
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A01A4(u32 a, u32 b)
{
((struct Obj12078 *)((u8 *)(a)))->f0 = b;
((struct Obj12078 *)((u8 *)(a)))->f40 = 1;
return a;
}


int func_021A01AC(u32 a, u32 b)
{
((struct Obj12079 *)((u8 *)(a)))->f1 = b;
((struct Obj12079 *)((u8 *)(a)))->f40 = 1;
return a;
}


int func_021A01B4(u32 a, u32 b)
{
((struct Obj07212 *)((u8 *)(a)))->f2 = b;
((struct Obj07212 *)((u8 *)(a)))->f40 = 1;
return a;
}
