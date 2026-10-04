/*
 * function: func_021C5480
 * address:  0x021C5480
 * packet:   pkt_ov093_021C5480
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C54AC  0x021C54AC  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern int func_021C54AC(void *p, int v);
extern void func_021CD4B0(void *w, volatile u32 id, ...);

void func_021C5480(u8 *p, u8 *a, int b)
{
    int r = func_021C54AC(p + 0x1AB8, func_021D5440(a));
    if (r != 6) {
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x4d, r, b);
    }
}
