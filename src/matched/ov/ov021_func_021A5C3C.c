/*
 * function: func_021A5C3C
 * address:  0x021A5C3C
 * packet:   pkt_ov021_021A5C3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A5CA4  0x021A5CA4  thumb  ov021
 *   func_021A5D04  0x021A5D04  thumb  ov021
 *   func_021A5DD8  0x021A5DD8  thumb  ov021
 *   func_021A5E28  0x021A5E28  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04234.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern int func_021A5CA4(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern int func_021A5D04(void *a, void *b, int c, int d, int e, int f);
extern int func_021A5DD8(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern int func_021A5E28(void *a, void *b, int c, int d, int e, int f);

int func_021A5C3C(u8 *p, u32 b, u32 c, u32 d, u32 e)
{
    int sw = ((struct Obj04234 *)p)->f0;
    int r = 0;
    void *a = ((struct Obj04234 *)p)->f1C;

    switch (sw) {
    case 0:
        r = func_021A5CA4(p, a, b, c, d, e);
        break;
    case 1:
        r = func_021A5D04(p, a, b, c, d, e);
        break;
    case 2:
        r = func_021A5DD8(p, a, b, c, d, e);
        break;
    case 3:
        r = func_021A5E28(p, a, b, c, d, e);
        break;
    }
    return r;
}
