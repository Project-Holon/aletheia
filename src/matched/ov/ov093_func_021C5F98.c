/*
 * function: func_021C5F98
 * address:  0x021C5F98
 * packet:   pkt_ov093_021C5F98
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
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021CD64C(void *w, u8 id, ...);

void func_021C5F98(u8 *p, u32 a, u32 b, int n, int *v)
{
    switch (n) {
    default:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, 0xffff0000);
        break;
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}
