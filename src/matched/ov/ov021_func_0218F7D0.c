/*
 * function: func_0218F7D0
 * address:  0x0218F7D0
 * packet:   pkt_ov021_0218F7D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218F18C  0x0218F18C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02371.h"
#include "../include/Obj07420.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 a, b, c; } V3;

extern void func_0218F18C(u8 *s, u8 *d);

void func_0218F7D0(u8 *s, u8 *d)
{
    *(V3 *)(d + 0) = *(V3 *)(s + 0x24);
    func_0218F18C(s, d + 0xc);
    ((struct Obj07420 *)d)->f24 = ((struct Obj02371 *)s)->f78;
    ((struct Obj07420 *)d)->f26 = ((struct Obj02371 *)s)->f7A;
    ((struct Obj07420 *)d)->f28 = ((struct Obj02371 *)s)->f7C;
    ((struct Obj07420 *)d)->f2C = ((struct Obj02371 *)s)->f80;
    *(V3 *)(d + 0x18) = *(V3 *)(s + 0x60);
}
