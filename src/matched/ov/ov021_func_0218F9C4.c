/*
 * function: func_0218F9C4
 * address:  0x0218F9C4
 * packet:   pkt_ov021_0218F9C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218F780  0x0218F780  thumb  ov021
 *   func_0218FB1C  0x0218FB1C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01653.h"
#include "../include/Obj05980.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[12]; } B48;
typedef struct { u32 w[6]; } B24;

extern void func_0218E13C(u8 *p, u32 v);
extern void func_0218F780(u8 *p, u8 *q);
extern void func_0218FB1C(u8 *p);

void func_0218F9C4(u8 *p, u8 *src, u16 v)
{
    u8 *q;
    if (p) {
        q = p + 0xf0;
        if (((struct Obj05980 *)q)->f98 != 0 && v != 0) {
            func_0218E13C(p, 0);
            func_0218F780(p, q + 0x34);
            *(B48 *)(q + 0x64) = *(B48 *)(q + 4);
            ((struct Obj05980 *)q)->f96 = 0;
            ((struct Obj05980 *)q)->f94 = v;
            *(B24 *)(q + 0xa0) = *(B24 *)src;
            ((struct Obj01653 *)p)->f1AC = (void *)func_0218FB1C;
            ((struct Obj05980 *)q)->fB8 = 0;
            ((struct Obj05980 *)q)->f9C = 1;
        }
    }
}
