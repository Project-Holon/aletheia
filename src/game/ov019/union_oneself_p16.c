/*
 * file:     union_oneself_p16.c
 * unit:     yes
 * function: func_0217FAF0, func_0217FB30, func_0217FB70
 * address:  0x0217FAF0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MTX_Identity33_  0x0207ADC4  arm
 *   func_0216DA30    0x0216DA30  thumb  ov010
 *   func_0217FA9C    0x0217FA9C  thumb  ov019
 *   d_0218071C       0x0218071C  data   ov019 a4
 *   func_0217FA54  0x0217FA54  thumb  ov019
 *   sub_020490F4   0x020490F4  arm
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   sub_02034714   0x02034714  arm
 *   func_02049238  0x02049238  arm
 *   d_02180814     0x02180814  data  ov019 a4
 */
#include "../../matched/include/Obj07393.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct B60 { u32 w[15]; };

struct E { u32 a, b, c, d; u16 h; };

extern void MTX_Identity33_(void *m);
extern int func_0216DA30(u32 a);
extern void func_0217FA9C(u32 *p, u32 *b);
extern void func_0217FA54(u32 *p);
extern void *sub_020490F4(u32 id, u32 heap);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void sub_02034714(const char *expr, u32 line, const char *file);
extern void func_02049238(void *h);
void func_0217FAF0(u32 *p);
struct E *func_0217FB30(struct E *p);
void func_0217FB70(char *p, u32 heap);
extern struct B60 d_0218071C;
extern u32 d_02180814[];


/*
 * Addresses are Black-image addresses.
 */
void func_0217FAF0(u32 *p)
{
    struct B60 b = d_0218071C;

    MTX_Identity33_(&b.w[6]);
    if (p[3] != 0 && func_0216DA30(p[0]) == 1) {
        func_0217FA9C(p, (u32 *)(&b));
    }
}


struct E *func_0217FB30(struct E *p)
{
    int i, best = 0;

    for (i = 0; i < 1; i++) {
        struct E *e = &p[i];
        if (e->d == 0) {
            return e;
        }
        if (e->h < p[best].h) {
            best = i;
        }
    }
    func_0217FA54((u32 *)(&p[best]));
    return &p[best];
}


/*
 * Sub-object constructor reached from func_0217F8C0 (called at +0x14 with
 * p+0x20).  Grabs a handle from sub_020490F4(0x59) -- the r1 "owner" word is a
 * leftover of the caller, so only r0 is set, the one-argument forwarding shape
 * -- then fills two fields from func_02046E24(h, index) and asserts each with
 * func_02046FF8; a zero result goes to sub_02034714 against d_02180814.
 *
 * Addresses are Black-image addresses.
 */
void func_0217FB70(char *p, u32 heap)
{
    void *h = sub_020490F4((u32)((void *)0x59), heap);

    *(u32 *)&((struct Obj07393 *)p)->fC8 = (u32)func_02046E24((u32)h, 0x16);
    *(u32 *)&((struct Obj07393 *)p)->fCC = (u32)func_02046E24((u32)h, 0x17);
    if (func_02046FF8(*(int * *)&((struct Obj07393 *)p)->fC8) == 0) {
        sub_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    if (func_02046FF8(*(int * *)&((struct Obj07393 *)p)->fCC) == 0) {
        sub_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    func_02049238(h);
}
