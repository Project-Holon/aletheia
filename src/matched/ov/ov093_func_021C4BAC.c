/*
 * function: func_021C4BAC
 * address:  0x021C4BAC
 * packet:   pkt_ov093_021C4BAC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
#include "../include/Obj21095.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021CD64C(void *w, u8 id, ...);

void func_021C4BAC(u8 *p, int k, int v)
{
    int r = -1;
    switch (k) {
    case 0: r = 0x7e; break;
    case 1: r = 0x82; break;
    case 2: r = 0x86; break;
    case 3: r = 0x8a; break;
    case 4: r = 0x8e; break;
    case 5: r = 0x92; break;
    case 6: r = 0x96; break;
    case 7: r = 0x9a; break;
    case 8: r = 0x9e; break;
    case 9: break;
    case 10: break;
    case 11: r = 0xa6; break;
    case 12: r = 0xaa; break;
    case 13: r = 0xae; break;
    }
    if (r >= 0) {
        func_021CD64C(((struct Obj21095 *)p)->fC, 0x5a, r, v, 0xffff0000);
    }
}
