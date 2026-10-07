/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, func_0215444C
 * address:  0x021542C0
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0200AEE8  0x0200AEE8  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_02013790  0x02013790  thumb
 *   func_020137C0  0x020137C0  thumb
 *   func_02013864  0x02013864  thumb
 *   func_02013894  0x02013894  thumb
 *   func_02013980  0x02013980  thumb
 *   func_02013160  0x02013160  thumb
 *   func_0201A2A8  0x0201A2A8  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012950 0x02012950 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_0201A948 0x0201A948 thumb
 *   func_02013128 0x02013128 thumb
 */
#include "../../matched/include/Obj01027.h"
#include "../../matched/include/Obj18627.h"
#include "../../matched/include/Obj12251.h"

struct Ctx;
struct Reg;
struct ZoneData;
struct Entry;
struct Party;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
struct Link;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed int     s32;

typedef unsigned short u16;

typedef struct Sub_021542C0 {
    u32 f00[5];
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  pad20[0x28];
    u8  f48;
} Sub_021542C0;

typedef struct {
    int f0, f4, f8;
    unsigned char fc;
    int f10; void *f14;
    unsigned char f18;
    void *f1c; int f20, f24;
} Sub_0215444C;

typedef struct {
    int pad[5];
    int t14[2];
    int f1c;
} R;

typedef struct {
    char pad[0x20];
    Sub_0215444C s;
    char pad2[0x5c - 0x48];
    const R *r;
    char pad3[0x168 - 0x60];
    void *f168;
} O;

extern void *func_020120F4(const struct Ctx *p);
extern void func_0200AEE8(struct Reg *p, u32 id, s32 value);
extern struct Entry *func_020399A8(void);
extern void func_02013790(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_020137C0(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013864(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013894(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013980(struct ZoneData *o, u32 heap);
extern void func_02013160(u8 *o, void *a1, u32 a2);
extern void func_0201A2A8(void *a0, void *a1);
extern void *func_02012F2C(int *p);
u32 func_0203D1A4(struct Link *p);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
const void *func_020084F4(const void *p);
u8 func_02008550(const struct Sub0200852CObj *obj);
void func_0201A948(struct Party *p);
void func_02013128(void *p, void *src, int i);
void func_021542C0(char *obj, int idx);
void func_0215444C(O *a, void *b);
void func_021544BC(O *a);


void func_021542C0(char *obj, int idx)
{
    u32 h;
    u8 flag;
    int v;

    h = (u32)func_020120F4((const struct Ctx *)(((struct Obj01027 *)obj)->f4));
    flag = (*(Sub_021542C0 * *)&((struct Obj01027 *)obj)->f5C)->f48;
    if (flag)
        func_0200AEE8((struct Reg *)((*(Sub_021542C0 * *)&((struct Obj01027 *)obj)->f5C)->f1c), 0xd, 1);
    else
        func_0200AEE8((struct Reg *)((*(Sub_021542C0 * *)&((struct Obj01027 *)obj)->f5C)->f1c), 0xd, 0);

    switch (idx) {
    case 8:
        v = 1;
        if (flag)
            v = 3;
        break;
    case 7:
        v = 0;
        if (flag)
            v = 2;
        break;
    case 10:
        v = 5;
        if (flag)
            v = 7;
        break;
    case 9:
        v = 4;
        if (flag)
            v = 6;
        break;
    case 12:
        v = 9;
        if (flag)
            v = 0xb;
        break;
    case 11:
        v = 8;
        if (flag)
            v = 0xa;
        break;
    case 14:
        v = 0xd;
        if (flag)
            v = 0xf;
        break;
    case 13:
        v = 0xc;
        if (flag)
            v = 0xe;
        break;
    }
    ((struct Obj01027 *)obj)->f144 = v;
    ((struct Obj01027 *)obj)->f148 = 0;

    switch (idx) {
    case 7:
    case 8:
        func_02013790(*(u32 *)&((struct Obj01027 *)obj)->fDC, h, (u32)func_020399A8(), 1, 4);
        break;
    case 9:
    case 10:
        func_020137C0(*(u32 *)&((struct Obj01027 *)obj)->fDC, h, (u32)func_020399A8(), 1, 4);
        break;
    case 11:
    case 12:
        func_02013864(*(u32 *)&((struct Obj01027 *)obj)->fDC, h, (u32)func_020399A8(), 1, 4);
        break;
    case 13:
    case 14:
        func_02013894(*(u32 *)&((struct Obj01027 *)obj)->fDC, h, (u32)func_020399A8(), 1, 4);
        break;
    }
    func_02013980((struct ZoneData *)(*(u32 *)&((struct Obj01027 *)obj)->fDC), 1);
    func_02013160((u8 *)(*(u32 *)&((struct Obj01027 *)obj)->fDC), (void *)((*(Sub_021542C0 * *)&((struct Obj01027 *)obj)->f5C)->f1c), 4);
    func_0201A2A8((void *)((*(Sub_021542C0 * *)&((struct Obj01027 *)obj)->f5C)->f1c), (void *)((*(Sub_021542C0 * *)&((struct Obj01027 *)obj)->f5C)->f14));
    func_0201A2A8((void *)((*(Sub_021542C0 * *)&((struct Obj01027 *)obj)->f5C)->f1c), (void *)((*(Sub_021542C0 * *)&((struct Obj01027 *)obj)->f5C)->f18));
    ((struct Obj18627 *)(*(char * *)&((struct Obj01027 *)obj)->fDC))->f6C = (u32)func_02012F2C(func_020120F4((const struct Ctx *)(((struct Obj01027 *)obj)->f4)));
}


/*
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
 */
void func_0215444C(O *a, void *b)
{
    int x, y;
    void *t;
    Sub_0215444C *q;

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
