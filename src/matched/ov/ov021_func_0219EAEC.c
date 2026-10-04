/*
 * function: func_0219EAEC
 * address:  0x0219EAEC
 * packet:   pkt_ov021_0219EAEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_0216D89C  0x0216D89C  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07482.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_021B7EE4(void *p, void *r);
extern void func_021B8028(void *p, void *out);
extern void func_0216D89C(u32, void *);

void func_0219EAEC(u8 *p, u32 a)
{
    u8 buf[12];
    if (p[6] != 2) {
        func_021B7EE4(((struct Obj07482 *)p)->f0, p + 4);
        func_021B8028(((struct Obj07482 *)p)->f0, buf);
        func_0216D89C(a, buf);
    }
}
