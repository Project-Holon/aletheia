/*
 * file:     research_top_p23.c
 * unit:     yes
 * function: func_021BE930, func_021BE934
 * address:  0x021BE930
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
 *   d_021C3AC8     0x021C3AC8  data  a1
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021BEB6C  0x021BEB6C  thumb  ov217
 */
#include "../../matched/include/Obj25907.h"
#include "../../matched/include/Obj25908.h"
#include "../../matched/include/G_E.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct E E;

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int func_020409B4(int);
extern u32 func_021BEB6C(u32 a0);
void func_021BE930(void *p, u32 v);
int func_021BE934(char *p);
extern struct E d_021C3AC8[];


/*
 * Field setter, u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE930(void *p, u32 v)
{
    ((struct Obj25907 *)p)->f34 = v;
}


int func_021BE934(char *p)
{
    switch (((struct Obj25908 *)p)->f34) {
    case 0:
    case 2:
    case 3:
        func_020413B0(2, d_021C3AC8[*(int *)(p + 0x34)].a,
                      d_021C3AC8[*(int *)(p + 0x34)].b,
                      d_021C3AC8[*(int *)(p + 0x34)].c,
                      d_021C3AC8[*(int *)(p + 0x34)].d, 0xa);
        break;
    case 1:
        func_020413B0(2, 0xd, 4, 0x13, 4, 0xa);
        func_020413B0(2, 0x10, 8, 0x10, 3, 0xa);
        break;
    case 4:
        func_021BEB6C((u32)p);
        break;
    }
    return func_020409B4(2);
}
