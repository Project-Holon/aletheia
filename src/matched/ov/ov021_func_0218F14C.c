/*
 * function: func_0218F14C
 * address:  0x0218F14C
 * packet:   pkt_ov021_0218F14C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0218F114  0x0218F114  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09465.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
extern void func_0218F114(char *arg0, char *arg1);

void func_0218F14C(u8 *p, u32 a, u32 b)
{
    u32 r;
    if (((struct Obj09465 *)p)->fEA != a) {
        r = (u32)func_0204A380((void *)(((struct Obj09465 *)p)->f8), a, 0, (u16)((b & 0x7fff) | 0x8000));
        func_0218F114((char *)p, (char *)r);
        func_020307B0((void *)r);
        ((struct Obj09465 *)p)->fEA = a;
    }
}
