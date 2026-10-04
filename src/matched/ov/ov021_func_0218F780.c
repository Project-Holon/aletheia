/*
 * function: func_0218F780
 * address:  0x0218F780
 * packet:   pkt_ov021_0218F780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02371.h"
#include "../include/Obj07419.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 a, b, c; } V3;

void func_0218F780(u8 *s, u8 *d)
{
    *(V3 *)(d + 0)    = *(V3 *)(s + 0x24);
    *(V3 *)(d + 0xc)  = *(V3 *)(s + 0x48);
    ((struct Obj07419 *)d)->f24 = ((struct Obj02371 *)s)->f78;
    ((struct Obj07419 *)d)->f26 = ((struct Obj02371 *)s)->f7A;
    ((struct Obj07419 *)d)->f28 = ((struct Obj02371 *)s)->f7C;
    ((struct Obj07419 *)d)->f2C = ((struct Obj02371 *)s)->f80;
    *(V3 *)(d + 0x18) = *(V3 *)(s + 0x60);
}
