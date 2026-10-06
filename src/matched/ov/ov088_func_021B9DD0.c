/*
 * function: func_021B9DD0
 * address:  0x021B9DD0
 * packet:   pkt_ov088_021B9DD0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020489F4  0x020489F4  arm
 *   func_020115C0  0x020115C0  thumb
 *   func_02011B8C  0x02011B8C  thumb
 *   func_02048AD0  0x02048AD0  arm
 *   func_02047964  0x02047964  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02048A18  0x02048A18  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02047970  0x02047970  arm
 *   func_02047910  0x02047910  arm
 *   d_021BD538     0x021BD538  data  ov088  a4
 */
#include "../include/Obj03674.h"

typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct IcaAnime;
struct Light;
extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_020115C0(struct IcaAnime *p, s32 v);
extern void func_02011B8C(void *, void *);
extern void func_02048AD0(struct Light *l);
extern void func_02047964(void);
extern void func_020479D8(void);
extern u32 func_02048A18(u8 *a0, int i);
struct Arg;
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_02047970(void);
extern int func_02047910(void *a, int idx, int amount);
extern char d_021BD538[];

void func_021B9DD0(int *p)
{
    int base;
    unsigned i;
    void *h;
    base = func_020489F4((void *)p[0], ((struct Obj03674 *)p)->f4);
    func_020115C0((void *)p[3], 0x1000);
    func_02011B8C((void *)p[4], (void *)p[3]);
    func_02048AD0((void *)p[4]);
    func_02047964();
    func_020479D8();
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((void *)p[0], (unsigned short)(base + i));
        func_02047A60(h, (struct Arg *)d_021BD538);
    }
    func_02047970();
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((void *)p[0], (unsigned short)(base + i));
        func_02047910(h, 0, 0x1000);
        if (i == 0)
            func_02047910(h, 1, 0x1000);
    }
}
