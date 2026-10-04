/*
 * function: func_021C59C4
 * address:  0x021C59C4
 * packet:   pkt_ov093_021C59C4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);

void func_021C59C4(u8 *p, u32 n, u8 **a, u8 *b, int flag)
{
    u32 i;
    for (i = 0; i < n; i++) {
        if (b[i]) {
            if (flag) {
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x180, func_021D5440(a[i]), 0xffff0000);
            } else {
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x51, 0xffff0000);
            }
        }
    }
}
