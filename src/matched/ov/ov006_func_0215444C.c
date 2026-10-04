/*
 * function: func_0215444C, func_021544BC
 * unit: yes
 * address: 0x0215444C
 * packet: pkt_ov006_0215444C
 * region: ov006
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * size: 136
 *
 * The lead is 110 bytes, followed by two padding bytes and the 24-byte
 * func_021544BC thunk. function_starts: 0x021544BC.
 * func_020084F4 is the bx-lr identity: the original retains the pointer
 * returned by func_02012950 in r0 across two loads, passes it to the
 * identity, and stores the unchanged result. Its prior (void) extern
 * dropped the live input and caused an 18-byte scheduling residue.
 * func_0203D1A4 explicitly returns only eight bits; the caller consumes
 * those bits without truncation. Indexed record reads retain modular
 * unsigned address arithmetic without assuming an index domain.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012950 0x02012950 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_0201A948 0x0201A948 thumb
 *   func_02013128 0x02013128 thumb
 */
#include "../include/Obj12251.h"
typedef struct {
    int f0, f4, f8;
    unsigned char fc;
    int f10; void *f14;
    unsigned char f18;
    void *f1c; int f20, f24;
} Sub;
typedef struct {
    int pad[5];
    int t14[2];
    int f1c;
} R;
typedef struct {
    char pad[0x20];
    Sub s;
    char pad2[0x5c - 0x48];
    const R *r;
    char pad3[0x168 - 0x60];
    void *f168;
} O;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Entry;
struct Party;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
struct Entry *func_020399A8(void);
struct Link;
u32 func_0203D1A4(struct Link *p);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void *func_020084F4(void *p);
u8 func_02008550(const struct Sub0200852CObj *obj);
void func_0201A948(struct Party *p);
void func_02013128(void *p, void *src, int i);

void func_0215444C(O *a, void *b)
{
    int x, y;
    void *t;
    Sub *q;

    x = func_0203D1A4((struct Link *)func_020399A8());
    y = 1 - x;
    t = func_02012950(b, y);
    a->s.f0 = a->r->f1c;
    q = &a->s;
    q->f4 = *(int *)((unsigned int)a->r + 0x14 + 4 * (unsigned int)x);
    q->f8 = (int)func_020084F4(t);
    q->fc = func_02008550(t);
    q->f10 = *(int *)((unsigned int)a->r + 0x14 + 4 * (unsigned int)y);
    q->f14 = b;
    q->f18 = 0;
    func_0201A948(a->f168);
    q->f1c = a->f168;
    q->f20 = a->r->t14[0];
    q->f24 = a->r->t14[1];
}

void func_021544BC(O *a)
{
    func_02013128(((struct Obj12251 *)((unsigned int)a))->fDC, a->f168, 0);
}
