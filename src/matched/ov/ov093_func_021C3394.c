/*
 * function: func_021C3394
 * address:  0x021C3394
 * packet:   pkt_ov093_021C3394
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);

int func_021C3394(u8 *p, u8 *q, int r)
{
    if (func_021D62C4((struct Unk021D62A8 *)q, 15) != 0) {
        if (r != 0) {
            func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 887, func_021D5440(q), 0xffff0000);
            p[0x78A] |= 0x20;
        }
        return 1;
    }
    return 0;
}
