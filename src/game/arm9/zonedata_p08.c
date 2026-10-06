/*
 * file:     zonedata_p08.c
 * unit:     yes
 * function: func_02014134, func_0201416C
 * address:  0x02014134
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj00193.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed char s8;

typedef signed int s32;

extern u32  func_02014274(u32 a);
extern u8 func_0201441C(int i);
void func_02014134(u8 *p, u16 b, int c, u16 d, u16 e, u16 f, u16 g, s16 h);
int func_0201416C(int a0, int a1, int a2, int a3);


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014134.c \
 *       --func func_02014134 --addr 0x02014134 --cc 1.1p1 --thumb
 */
void func_02014134(u8 *p, u16 b, int c, u16 d, u16 e, u16 f, u16 g, s16 h)
{
    ((struct Obj00193 *)p)->f0 = 0;
    ((struct Obj00193 *)p)->f4 = b;
    ((struct Obj00193 *)p)->f6 = c;
    ((struct Obj00193 *)p)->f8 = d;
    ((struct Obj00193 *)p)->fA = e;
    ((struct Obj00193 *)p)->fC = 1;
    *(u8 *)(p + 0x12) = 1;
    *(u16 *)&((struct Obj00193 *)p)->f10 = f;
    *(u16 *)(p + 0x16) = g;
    *(u16 *)&((struct Obj00193 *)p)->f14 = h;
    *(u8 *)(p + 0x13) = func_0201441C(func_02014274(d));
}


int func_0201416C(int a0, int a1, int a2, int a3){ int t0; t0 = func_020140F8(a0); ((struct Obj00193 *)((char *)((a0 + 0))))->f4 = (unsigned short)(a1 + 0); ((struct Obj00193 *)((char *)((a0 + 0))))->f6 = (unsigned short)(a2 + 0); ((struct Obj00193 *)((char *)((a0 + 0))))->fA = (unsigned short)(a3 + 0); return t0; }
