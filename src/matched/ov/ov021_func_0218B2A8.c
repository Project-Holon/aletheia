/*
 * function: func_0218B2A8
 * address:  0x0218B2A8
 * packet:   pkt_ov021_0218B2A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C9C  0x02188C9C  thumb
 *   func_02014134  0x02014134  thumb
 *   func_02012878  0x02012878  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04982.h"

typedef unsigned short u16;
typedef signed short   s16;

typedef unsigned char  u8;
extern u16 func_02188C9C(u8 *p);
extern void func_02014134(int *buf, int a, int b, int c, int d, int e, int f, int g);
extern void func_02012878(void *a, int *buf);

void func_0218B2A8(char *p, int s, u16 *v)
{
    int buf[7];

    func_02014134(buf, func_02188C9C(((struct Obj04982 *)p)->f14), (s16)s, 0, 0, v[0], v[3], (s16)v[2]);
    func_02012878(((struct Obj04982 *)p)->f8, buf);
}
