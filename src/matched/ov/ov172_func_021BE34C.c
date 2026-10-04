/*
 * function: func_021BE34C
 * address:  0x021BE34C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Release the word at +0x1dc through 0x0202F038 and clear it.
 *
 * symbols:
 *   func_0202F038  0x0202F038  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05448.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0202F038(u8 *p);

void func_021BE34C(void *p)
{
    u32 v = ((struct Obj05448 *)p)->f1DC;
    if (v != 0) {
        func_0202F038((u8 *)v);
        ((struct Obj05448 *)p)->f1DC = 0;
    }
}
