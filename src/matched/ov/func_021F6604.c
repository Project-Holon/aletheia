/*
 * function: func_021F6604
 * address:  0x021F6604
 * packet:   pkt_021F6604
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02202840  0x02202840  thumb  ov135

 * When the build query answers 0 and either probe is set, release the +0xdd0 word and roll the state.
 */
#include "../include/Obj09227.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_02202840(u8 *p);
extern u32 func_020362DC(void);
extern u32 func_02035C60(void);
extern void func_0201F7A8(void *desc, u32 kind);

int func_021F6604(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (func_020362DC() != 0 || func_02035C60() != 0) {
            func_0201F7A8((void *)(((struct Obj09227 *)p)->fDD0), 0);
            ((struct Obj09227 *)p)->f28 = ((struct Obj09227 *)p)->f2C;
        }
    }
    return 2;
}
