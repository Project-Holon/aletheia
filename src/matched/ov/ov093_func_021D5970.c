/*
 * function: func_021D5970
 * address:  0x021D5970
 * packet:   pkt_ov093_021D5970
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D587C  0x021D587C  thumb  ov093
 */
#include "../include/Obj00041.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D587C(void *p, int k);

void func_021D5970(u8 *p, int k, u16 v)
{
    switch (func_021D587C(p, k)) {
    case 8:
        ((struct Obj00041 *)p)->fEE = v;
        break;
    case 9:
        ((struct Obj00041 *)p)->fF0 = v;
        break;
    case 10:
        ((struct Obj00041 *)p)->fF2 = v;
        break;
    case 11:
        ((struct Obj00041 *)p)->fF4 = v;
        break;
    case 12:
        ((struct Obj00041 *)p)->fF6 = v;
        break;
    }
}
