/*
 * function: func_0218E6F0
 * address:  0x0218E6F0
 * packet:   pkt_ov021_0218E6F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of func_0218E6A4 with mode 0 and the other matrix pair.
 *
 * symbols:
 *   func_0207CA00  0x0207CA00  arm
 *   func_0218E674  0x0218E674  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01848.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_0207CA00(void *a, void *b, void *c);
typedef unsigned int   u32;
extern void func_0218E674(u8 *a, u32 b);

void func_0218E6F0(u8 *a)
{
    u8 tmp[12];

    if (((struct Obj01848 *)a)->f14 == 0) {
        ((struct Obj01848 *)a)->f7A = ((struct Obj01848 *)a)->f7A + 0x8000;
        ((struct Obj01848 *)a)->f78 = ((struct Obj01848 *)a)->f78 + 0x8000;
    } else {
        func_0207CA00(a + 0x48, a + 0x3C, tmp);
        func_0218E674(a, (u32)tmp);
    }
}
