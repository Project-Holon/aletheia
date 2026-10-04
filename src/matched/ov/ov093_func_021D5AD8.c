/*
 * function: func_021D5AD8
 * address:  0x021D5AD8
 * packet:   pkt_ov093_021D5AD8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D587C  0x021D587C  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */
#include "../include/Obj00041.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D587C(void *p, int k);
extern int func_021D58A8(u8 *p, int k);
extern int func_021D59B4(u8 *p, int k);

int func_021D5AD8(u8 *p, int k)
{
    int r = 0;
    switch (func_021D587C(p, k)) {
    case 8:
        if (((struct Obj00041 *)p)->fFC < 6) r = 1;
        break;
    case 10:
        if (((struct Obj00041 *)p)->fFE < 6) r = 1;
        break;
    case 9:
        if (((struct Obj00041 *)p)->fFD > 6) r = 1;
        break;
    case 11:
        if (((struct Obj00041 *)p)->fFF > 6) r = 1;
        break;
    }
    if (r) return func_021D58A8(p, k);
    return func_021D59B4(p, k);
}
