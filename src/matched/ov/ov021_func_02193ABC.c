/*
 * function: func_02193ABC
 * address:  0x02193ABC
 * packet:   pkt_ov021_02193ABC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 *   func_021938F4  0x021938F4  thumb  ov021
 *   func_0218E17C  0x0218E17C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj19614.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_021938F4(unsigned char *p);
extern void func_0218E17C(u32 *p, u32 v);
extern u32 func_020307B0(void *p);

void func_02193ABC(char *p, int a, int b)
{
    u16 *h;

    h = func_0204A380((void *)(((struct Obj19614 *)p)->f10), 0x24, 0, (u16)((b & 0x7fff) | 0x8000));
    func_0218E17C((u32 *)a, h[func_021938F4((unsigned char *)p)]);
    func_020307B0(h);
}
