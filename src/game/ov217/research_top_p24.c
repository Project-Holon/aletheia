/*
 * file:     research_top_p24.c
 * unit:     yes
 * function: func_021BE9B8, func_021BEA3C
 * address:  0x021BE9B8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C3AC8 0x021C3AC8 data a1
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021BEB88 0x021BEB88 thumb ov217
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "../../matched/include/Obj25909.h"
#include "../../matched/include/G_E.h"
#include "../../matched/include/Obj14737.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u8 x,y,w,h; u8 rest[32]; } E;

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32);
extern u32 func_021BEB88(u32);
extern int _s32_div_f(int, int);
void func_021BE9B8(u8 *p);
void func_021BEA3C(char *p, int a);
extern struct E d_021C3AC8[];

void func_021BE9B8(u8 *p)
{
    switch (((struct Obj25909 *)p)->f34) {
    case 0:
    case 2:
    case 3:
        func_020413B0(2, d_021C3AC8[*(u32 *)(p + 52)].a,
            d_021C3AC8[*(u32 *)(p + 52)].b,
            d_021C3AC8[*(u32 *)(p + 52)].c,
            d_021C3AC8[*(u32 *)(p + 52)].d, 6);
        break;
    case 1:
        func_020413B0(2,13,4,19,4,6);
        func_020413B0(2,16,8,16,3,6);
        break;
    case 4:
        func_021BEB88((u32)p);
        break;
    }
    func_020409B4(2);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BEA3C(char *p, int a)
{
    ((struct Obj14737 *)p)->f2B8 = (u8)((((struct Obj14737 *)p)->f2B8 + a + 3) % 3);
}
