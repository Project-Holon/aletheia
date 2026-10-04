/*
 * function: func_021D58A8
 * address:  0x021D58A8
 * packet:   pkt_ov093_021D58A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D587C  0x021D587C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */
#include "../include/Obj00041.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D587C(void *p, int k);
extern int func_021D59B4(u8 *p, int k);

int func_021D58A8(u8 *p, int k)
{
    int v = func_021D587C(p, k);
    switch (v) {
    case 8:
        return ((struct Obj00041 *)p)->fEE;
    case 9:
        return ((struct Obj00041 *)p)->fF0;
    case 10:
        return ((struct Obj00041 *)p)->fF2;
    case 11:
        return ((struct Obj00041 *)p)->fF4;
    case 12:
        return ((struct Obj00041 *)p)->fF6;
    case 6:
        return 6;
    case 7:
        return 6;
    }
    return func_021D59B4(p, v);
}
