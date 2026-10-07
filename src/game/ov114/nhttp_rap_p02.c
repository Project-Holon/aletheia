/*
 * file:     nhttp_rap_p02.c
 * unit:     yes
 * function: func_021B97F4, func_021B9800
 * address:  0x021B97F4
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj13848.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u8 *func_021B97F4(u8 *p);
u8 *func_021B9800(int a, int b, int c);

u8 *func_021B97F4(u8 *p) { if(p==0) return 0; return p+0x10; }


u8 *func_021B9800(int a, int b, int c)
{
    u8 *p = func_02030734(a, 0x5a8, 1, (const char *)0x021CE310, 0x1aa);

    *(u32 *)0x021CF960 = (u32)p;
    ((struct Obj13848 *)p)->f5A4 = b;
    ((struct Obj13848 *)p)->f8 = c;
    return p;
}
