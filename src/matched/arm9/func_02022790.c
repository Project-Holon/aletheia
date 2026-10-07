/*
 * function: func_02022790
 * address:  0x02022790
 * packet:   pkt_02022790
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020222A8  0x020222A8  thumb
 *   func_020238B4  0x020238B4  thumb
 *   func_0202390C  0x0202390C  thumb
 *   d_0209F574     0x0209F574  data
 *   g_020A73D0     0x020A73D0  data
 *
 * wipe.c (docs/families/wipe.h): one of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC.  Each installs a rodata
 * word table (0x0209F568..0x0209F574, four u32 words, NOT ARM code: the
 * old headers declared them as arm functions, which is why they had no
 * witness) into one slot of the wipe state at 0x020A73D0, then hands that
 * slot to func_020238B4.  Declared as data, the table address is attested
 * sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022790.c  *       --func func_02022790 --addr 0x02022790 --thumb --cc 1.1p1
 */

#include "../include/G_020A73D0.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct T {
    u8  pad00[0xc];
    u32 f0c;
    u8  pad10[0x14];
    u16 f24;
    u8  pad26[2];
    u32 f28;
    u32 f2c;
};

extern void func_020222A8(u32 v);
struct Task;
extern void func_020238B4(struct Task *t, u32 a1);
extern u32 func_0202390C(struct Task *t);
extern const u32 d_0209F574[];
extern struct G_020A73D0 g_020A73D0;

void func_02022790(struct T *p)
{
    if (p->f0c == 0) {
        g_020A73D0.f20 = (u32)d_0209F574;
        func_020222A8(p->f24);
        func_020238B4((struct Task *)p, (u32)(&g_020A73D0.f20));
        p->f28 = 1;
        p->f2c = 0;
    } else {
        func_0202390C((struct Task *)p);
    }
}
