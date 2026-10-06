/*
 * function: func_02014134
 * address:  0x02014134
 * packet:   pkt_02014134
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014134.c \
 *       --func func_02014134 --addr 0x02014134 --cc 1.1p1 --thumb
 */
#include "../include/Obj00193.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;

extern u32  func_02014274(u32 a);
extern u8 func_0201441C(int i);

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
