/*
 * function: func_021A0140
 * address:  0x021A0140
 * packet:   pkt_ov021_021A0140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A0250  0x021A0250  thumb  ov021
 *   func_021A0280  0x021A0280  thumb  ov021
 *   func_021A0290  0x021A0290  thumb  ov021
 *   func_021A02A8  0x021A02A8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09536.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern int func_021A0250(u8 *);
extern void func_021A0280(u8 *);
extern u32 func_021A0290(u8 *);
extern u16 func_021A02A8(u8 *);

void func_021A0140(u8 *p)
{
    if (func_021A0250(p + 0x2c)) {
        func_021A0280(p + 0x2c);
        ((struct Obj09536 *)p)->f4 = func_021A0290(p + 0x2c);
        p[2] = func_021A02A8(p + 0x2c);
        ((struct Obj09536 *)p)->f40 = 1;
    }
}
