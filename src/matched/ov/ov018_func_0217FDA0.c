/*
 * function: func_0217FDA0
 * address: 0x0217FDA0
 * packet: pkt_ov018_0217FDA0
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum local keeps the distinct full-word spill of f; its narrowed
 * byte value remains live in r1 and is forwarded to func_0217F5F0.
 * symbols:
 *   func_02167A14 0x02167A14 thumb ov010
 *   func_0217F5F0 0x0217F5F0 thumb ov018
 *   func_020120F4 0x020120F4 thumb
 *   func_021583EC 0x021583EC thumb ov010
 *   func_02008494 0x02008494 thumb
 *   func_02175B14 0x02175B14 thumb ov011
 *   func_02175B34 0x02175B34 thumb ov011
 *   func_02082D44 0x02082D44 arm
 *   func_0217F2B4 0x0217F2B4 thumb ov018
 *   func_02174E14 0x02174E14 thumb ov011
 *   func_02175368 0x02175368 thumb ov011
 */
#include "../include/Obj00566.h"
#include "../include/Obj03562.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Ctx;
struct Work;
u32 func_02167A14(struct Work *w, int i);
int func_0217F5F0(u8 *a, int b);
void *func_020120F4(const struct Ctx *p);
int func_021583EC(void *a0, int a1);
void func_02008494(void *src, void *dst);
int func_02175B14(u8 *a);
u8 *func_02175B34(u8 *p);
void func_02082D44(void *src, void *dst, int n);
void func_0217F2B4(void *a, int b);
void func_02174E14(u8 *a, int b);
void func_02175368(u8 *a);

void func_0217FDA0(int a, u8 *b, u8 *c, int d, int e, int f, u16 g)
{
    enum Local { LOCAL_ZERO } loc;

    ((struct Obj03562 *)c)->f0 = g;
    ((struct Obj03562 *)c)->f4 = e;
    loc = f;
    ((struct Obj03562 *)c)->f8 = func_02167A14((struct Work *)(((struct Obj00566 *)b)->f8), loc);
    ((struct Obj03562 *)c)->fC = d;
    c[0x40] = (u8)f;
    c[0x42] = func_0217F5F0(b, (u8)f);
    func_02008494((void *)func_021583EC(func_020120F4((const struct Ctx *)a), loc), c + 0x78);
    if (func_02175B14(b + 0x1ac) == 1) {
        func_02082D44(func_02175B34(b + 0x1ac), c + 0x44, 0x34);
    }
    func_0217F2B4(c + 0x10, a);
    func_02174E14(b, 1);
    func_02175368(b);
    b[0x93f] = b[0x93f] & ~0x30;
}
