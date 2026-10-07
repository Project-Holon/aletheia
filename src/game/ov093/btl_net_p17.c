/*
 * file:     btl_net_p17.c
 * unit:     yes
 * function: func_021D5208, func_021D5244, func_021D52B4
 * address:  0x021D5208
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C158 0x0201C158 thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017F00  0x02017F00  thumb
 */
#include "../../matched/include/Obj03696.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S { u16 f00; u8 f02; u8 f03; u8 f04; u8 lo : 4; u8 hi : 4; };

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Ent {
    u16 id;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 lo5:4;
    u8 hi5:4;
};

extern u32 func_0201C158(u32, u32);
extern u32 func_02017E1C(void *h, u32 k, u32 z);
extern u8 func_02017F00(void *h);
void func_021D5208(struct S *p, u32 a, u32 b);
int func_021D5244(struct Ent *e, void *h, u8 k);
void func_021D52B4(u8 *p, void *h, u32 flag);

void func_021D5208(struct S *p, u32 a, u32 b)
{
    p->f00 = a;
    p->lo = 0;
    p->hi = 0;
    if (a != 0) p->f03 = func_0201C158(a, 0);
    else p->f03 = 0;
    if (b != 0 && p->f03 > b) p->f03 = b;
    p->f02 = p->f03;
}


int func_021D5244(struct Ent *e, void *h, u8 k)
{
    int r = 1;
    u16 v = func_02017E1C(h, k + 0x36, 0);
    if (e->id != v) {
        e->lo5 = 0;
        e->hi5 = 0;
    }
    e->id = v;
    if (e->id != 0) {
        e->b2 = func_02017E1C(h, k + 0x3a, 0);
        e->b3 = func_02017E1C(h, k + 0x42, 0);
        e->b4 = func_02017E1C(h, k + 0x3e, 0);
    } else {
        r = 0;
        e->b2 = 0;
        e->b3 = 0;
        e->b4 = 0;
    }
    return r;
}


void func_021D52B4(u8 *p, void *h, u32 flag)
{
    if (flag) {
        p[0xf8] = func_02017E1C(h, 0xae, 0);
        p[0xf9] = func_02017E1C(h, 0xaf, 0);
    }
    p[0xfa] = func_02017F00(h);
    ((struct Obj03696 *)p)->fEE = func_02017E1C(h, 0xa2, 0);
    ((struct Obj03696 *)p)->fF0 = func_02017E1C(h, 0xa3, 0);
    ((struct Obj03696 *)p)->fF2 = func_02017E1C(h, 0xa5, 0);
    ((struct Obj03696 *)p)->fF4 = func_02017E1C(h, 0xa6, 0);
    ((struct Obj03696 *)p)->fF6 = func_02017E1C(h, 0xa4, 0);
}
