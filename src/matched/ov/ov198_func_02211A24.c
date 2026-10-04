/*
 * function: func_02211A24
 * address:  0x02211A24
 * packet:   pkt_02211A24
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202616C  0x0202616C  thumb
 *   func_0220B000  0x0220B000  thumb  ov196
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10855.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0202616C(void **obj, u32 idx);
extern void func_0220B000(int *p, u8 *q);

void func_02211A24(u8 *p, u32 idx)
{
    void *t = func_0202616C(*(void ** *)&((struct Obj10855 *)p)->f2184, idx);

    func_0220B000((int *)(((struct Obj10855 *)p)->f2188), (u8 *)((u32)t));
}

