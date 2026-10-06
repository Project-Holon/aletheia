/*
 * function: func_0218A878
 * address:  0x0218A878
 * packet:   pkt_ov021_0218A878
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When flag field 0x10 is set and func_021A2FA4 does not report 9, forwards
 * the object to ov018 func_0217B4D8; returns 0 otherwise.
 *
 * symbols:
 *   func_0217B4D8  0x0217B4D8  thumb ov018
 *   func_02013D5C  0x02013D5C  thumb
 *   func_021A2FA4  0x021A2FA4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04981.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_02013D5C(u32 id);
extern u16 func_021A2FA4(u8 *p, u32 a1);
extern void *func_0217B4D8(void *a, void *b, void *c, int *d, u16 e, int f);

void *func_0218A878(u8 *p, void *a, void *b)
{
    int r;

    if (func_02013D5C(((struct Obj04981 *)p)->f10) == 0)
        return 0;
    r = func_021A2FA4(((struct Obj04981 *)p)->f18, ((struct Obj04981 *)p)->f2C);
    if (r == 9)
        return 0;
    return func_0217B4D8(a, b, ((struct Obj04981 *)p)->f18, *(int * *)&((struct Obj04981 *)p)->f34, ((struct Obj04981 *)p)->f24, r);
}
