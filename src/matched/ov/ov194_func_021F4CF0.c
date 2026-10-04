/*
 * function: func_021F4CF0
 * address:  0x021F4CF0
 * packet:   pkt_021F4CF0
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24928.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(u8 *, u32, u32);

void func_021F4CF0(u8 *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj24928 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}

