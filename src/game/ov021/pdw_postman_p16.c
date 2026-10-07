/*
 * file:     pdw_postman_p16.c
 * unit:     yes
 * function: func_021B86A4, func_021B87BC, func_021B87C8, func_021B87D8, func_021B87FC, func_021B8820
 * address:  0x021B86A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8514  0x021B8514  thumb
 *   func_021B93D4  0x021B93D4  thumb
 *   func_021B9434  0x021B9434  thumb
 *   func_021B9404  0x021B9404  thumb
 *   func_021B9278  0x021B9278  thumb
 *   func_021B9280  0x021B9280  thumb
 *   func_021B8674  0x021B8674  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082D44  0x02082D44  arm
 *   d_021D9A0C     0x021D9A0C  data  a4
 */
#include "../../matched/include/Obj02659.h"
#include "../../matched/include/G_Elem.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 b[0x24];
} Elem;

typedef struct {
    u16 h0;
    u16 h2;
    u16 n4;
    u16 n6;
    u16 n8;
    u16 na;
    u16 nc;
    u16 he;
    u8 pad10[8];
    Elem *p18;
    Elem *p1c;
    void **p20;
    void **p24;
    void **p28;
} Table;

u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag);
int func_021B93D4(int dir);
int func_021B9434(int dir);
int func_021B9404(int dir);
int func_021B9278(const u32 *p, u32 b, u8 *t);
int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
int func_021B8674(u8 *p, u32 *q, u32 v);
extern void func_02082BCC();
extern void func_02082D44(u32 a, u32 b, u32 c);
void func_021B86A4(u8 *t, const u32 *q, int *out1, int *out2, u16 *a5, u32 a6);
void func_021B87BC(u32 a);
void func_021B87C8(u32 a, u32 b);
u8 *func_021B87D8(u8 *p, u32 idx);
u8 *func_021B87FC(u8 *p, u32 idx);
Elem *func_021B8820(Table *t, u16 i);
extern struct Elem d_021D9A0C;


/*
 * Scores three neighbouring cells (row from func_021B87D8, then one
 * func_021B8514 lookup per direction) against the start cell q.
 * q is read through a const pointer: with a plain `u32 *q` the outgoing
 * flag store `str r6, [sp]` lands before `adds r2, r5` in the first two
 * func_021B8514 calls (8 bytes).  Declaration order of row/best1 sets their
 * stack slots (best1 at sp+0xc, row at sp+0x10).
 *
 * Addresses are Black-image addresses.
 */
void func_021B86A4(u8 *t, const u32 *q, int *out1, int *out2, u16 *a5, u32 a6)
{
    u32 *row;
    int best1;
    u32 *res1;
    u32 *res2;
    u32 *res3;
    int best2;
    int m;
    int r;

    best1 = 0;
    row = (u32 *)func_021B87D8(t, q[0]);
    res1 = (u32 *)func_021B8514((u8 *)row, func_021B93D4(q[2]), t, a5, 1);
    res2 = (u32 *)func_021B8514((u8 *)row, func_021B9434(q[2]), t, a5, 1);
    res3 = (u32 *)func_021B8514((u8 *)row, func_021B9404(q[2]), t, a5, 1);
    best2 = func_021B9280((u8 *)q, 0, func_021B9278(q, a6, t), t);
    if (res1) {
        m = func_021B9278(res1, a6, t);
        r = func_021B9280((u8 *)res1, m, m, t);
        if (r > best2)
            best2 = r;
    }
    if (res2) {
        m = func_021B9278(res2, a6, t);
        if (func_021B8674(t, res2, (u32)row))
            r = func_021B9280((u8 *)res2, 0, m, t);
        else
            r = func_021B9280((u8 *)res2, m, m, t);
        if (r > best1)
            best1 = r;
    }
    if (res3) {
        m = func_021B9278(res3, a6, t);
        if (func_021B8674(t, res3, (u32)row))
            r = func_021B9280((u8 *)res3, 0, m, t);
        else
            r = func_021B9280((u8 *)res3, m, m, t);
        if (r > best1)
            best1 = r;
    }
    *out1 = best1;
    *out2 = best2;
}


void func_021B87BC(u32 a)
{
    func_02082BCC(a, 0, 48);
}


void func_021B87C8(u32 a, u32 b)
{
    func_02082D44(b, a, 0x30);
}


/*
 * Addresses are Black-image addresses.
 */
u8 *func_021B87D8(u8 *p, u32 idx)
{
    if (((struct Obj02659 *)p)->f0 > idx)
        return *(u8 * *)&((struct Obj02659 *)p)->f10 + idx * 0x70;
    if (idx == 0xFFFF)
        return 0;
    return *(u8 * *)&((struct Obj02659 *)p)->f10;
}


u8 *func_021B87FC(u8 *p, u32 idx)
{
    if (((struct Obj02659 *)p)->f2 > idx)
        return *(u8 * *)&((struct Obj02659 *)p)->f14 + idx * 0x48;
    if (idx == 0xFFFF)
        return 0;
    return *(u8 * *)&((struct Obj02659 *)p)->f14;
}


Elem *func_021B8820(Table *t, u16 i)
{
    if (t->n4 > i) {
        return &t->p18[i];
    }
    if (i == 0xFFFF) {
        return 0;
    }
    return ((Elem *)&d_021D9A0C);
}
