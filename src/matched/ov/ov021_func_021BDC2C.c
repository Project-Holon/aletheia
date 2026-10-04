/*
 * function: func_021BDC2C
 * address:  0x021BDC2C
 * packet:   pkt_ov021_021BDC2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05065.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Evt;
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);

void func_021BDC2C(u32 *ctx, u32 a)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj05065 *)p)->f4;
    u32 y = ((struct Obj05065 *)p)->fC;

    if (((struct Obj05065 *)p)->f40 != 0)
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, 3, 0, 0, p[0x44], p[0x45]));
    else
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, ((struct Obj05065 *)p)->f3C, 0, 1, 0, 0));
}
