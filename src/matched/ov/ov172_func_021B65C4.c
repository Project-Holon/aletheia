/*
 * function: func_021B65C4
 * address:  0x021B65C4
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Release the word at +0x48 through 0x0203D7FC and clear it.
 *
 * symbols:
 *   func_0203D7FC  0x0203D7FC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02504.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0203D7FC(void *p);

void func_021B65C4(void *p)
{
    u32 v = ((struct Obj02504 *)p)->f48;
    if (v != 0) {
        func_0203D7FC((void *)v);
        ((struct Obj02504 *)p)->f48 = 0;
    }
}
