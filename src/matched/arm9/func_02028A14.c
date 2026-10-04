/*
 * function: func_02028A14
 * address:  0x02028A14
 * packet:   pkt_020289F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020A7518  0x020A7518  data
 *   g_020A7554  0x020A7554  data
 */
#include "../include/Obj11294.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct T {
    u32 pad00;
    u32 f04;
};

extern void func_02028D54(int a0);
extern void func_02029F4C(void *p);
struct Fader;
extern void func_0202878C(struct Fader *s);
extern u32  g_020A7554[];
extern u32  g_020A7518[];

void func_02028A14(struct T *p)
{
    func_02028D54((int)p);
    ((void (*)(struct T *))g_020A7554[p->f04])(p);
    ((void (*)(struct T *))g_020A7518[p->f04])(p);
    func_02029F4C(((struct Obj11294 *)p)->fA8);
    func_0202878C(((struct Obj11294 *)p)->fA4);
}
