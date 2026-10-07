/*
 * file:     fld_exp_obj_p01.c
 * unit:     yes
 * function: func_021BE258, func_021BE288, func_021BE2A8, func_021BE2E0, func_021BE310, func_021BE418
 * address:  0x021BE258
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
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   d_021D9E74  0x021D9E74  data
 *   d_021DE390  0x021DE390  data
 *   func_02030734  0x02030734  arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02047E54  0x02047E54  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02047F4C  0x02047F4C  arm
 *   func_021BE630  0x021BE630  thumb  ov021
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021BE4C4  0x021BE4C4  thumb  ov021
 *   func_02047790  0x02047790  arm
 *   func_020480E4  0x020480E4  arm
 */
#include "../../matched/include/Obj12902.h"
#include "../../matched/include/Obj20141.h"

struct Big;
struct Ctx;
struct Rec94;
struct Rec;
typedef void (*Handler)(void *p);

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u32 heap;
    void *obj;
    unsigned char rest[0x40];
} Obj_021BE2A8;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
} Slot_021BE2E0;

typedef struct {
    u32 f00;
    u32 f04;
    Slot_021BE2E0 slots[4];
} Obj_021BE2E0;

typedef struct { int x, y, z; } Vec;

typedef struct { int m[9]; } Mtx33;

typedef struct {
    u8 f0, f1, f2, f3;
    int f4;
    int f8;
    void *fC;
} Ent;

typedef struct {
    int n;
    Ent *e;
} Grp;

typedef struct {
    int f0;
    int f4;
    Vec t;
    Vec s;
    Mtx33 r;
} Node;

typedef struct {
    int active;
    Node *nodes;
    Grp *grps;
    u16 id;
    u16 n;
} Slot_021BE310;

typedef struct {
    int heap;
    void *util;
    Slot_021BE310 slots[4];
} P;

typedef struct {
    u8 pad[0xC];
    u16 fC;
    u16 pad2;
} SEnt;

typedef struct {
    int f0;
    int f4;
    SEnt *ents;
    u16 n;
} Setup;

extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 func_0200B3AC(struct Rec94 *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *func_02047CFC(u16, u16, u16);
extern void func_02047E54(struct Rec *p);
extern u32 func_020307B0(void *p);
extern u16 func_02047F4C(void *util, const Setup *setup);
extern void func_021BE630(int *p, int n, int heap);
extern void func_0207ADC4(Mtx33 *m);
extern void *func_021BE4C4(P *p, int i, int j);
extern int func_02047790(int *p, int i);
extern void func_020480E4(struct Ctx *c, u32 i);
void func_021BE258(void *p);
int func_021BE288(u8 *a, int b);
Obj_021BE2A8 *func_021BE2A8(u32 a, u32 b, u32 heap);
void func_021BE2E0(Obj_021BE2E0 *o);
void func_021BE310(P *p, Setup *b, u16 i);
void func_021BE418(u8 *p, u16 i);
extern Handler d_021D9E74[];
extern int d_021DE390;


void func_021BE258(void *p)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(p))));
    if (i != -1 && d_021D9E74[i] != 0)
        d_021D9E74[i](p);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE288(u8 *a, int b)
{
if (b == func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80((void *)a))))) {
    return 1;
}
return 0;
}


Obj_021BE2A8 *func_021BE2A8(u32 a, u32 b, u32 heap)
{
    Obj_021BE2A8 *o = func_02030734((u16)heap, sizeof(Obj_021BE2A8), 1, (const char *)&d_021DE390, 0x4c);

    o->obj = func_02047CFC(a, b, heap);
    o->heap = heap;
    return o;
}


void func_021BE2E0(Obj_021BE2E0 *o)
{
    u16 i;

    for (i = 0; i < 4; i++) {
        if (o->slots[i].f00 != 0) {
            func_021BE418((u8 *)o, i);
        }
    }
    func_02047E54((struct Rec *)o->f04);
    func_020307B0(o);
}


static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}


/*
 * The u16 slot index is what moves its home store (str r2, [sp, #0xc]) to
 * the front of the prologue; with k declared ahead of nd the loop counter
 * takes r4, the register the zero stores share.
 */
void func_021BE310(P *p, Setup *b, u16 i)
{
    u16 id;
    u16 n;
    Node *nodes;
    u16 j;

    id = func_02047F4C(p->util, b);
    n = b->n;
    p->slots[i].n = n;
    p->slots[i].active = 1;
    p->slots[i].id = id;
    nodes = func_02030734((u16)p->heap, n * sizeof(Node), 1, (const char *)&d_021DE390, 0x8b);
    p->slots[i].nodes = nodes;
    p->slots[i].grps = func_02030734((u16)p->heap, n * sizeof(Grp), 1, (const char *)&d_021DE390, 0x8e);
    for (j = 0; j < n; j++) {
        int k;
        Node *nd;
        void *h;
        Grp *g;

        func_021BE630((int *)(&p->slots[i].grps[j]), b->ents[j].fC, p->heap);
        nd = &nodes[j];
        vset(&nd->s, 0x1000, 0x1000, 0x1000);
        func_0207ADC4(&nd->r);
        vset(&nd->t, 0, 0, 0);
        nd->f0 = 0;
        nd->f4 = 0;
        h = func_021BE4C4(p, i, j);
        g = &p->slots[i].grps[j];
        for (k = 0; k < g->n; k++)
            g->e[k].fC = (void *)func_02047790(h, (u16)k);
    }
}


/*
 * The listing extent (172) runs on into unlabelled leaves 0x021BE480,
 * 0x021BE4A4 and 0x021BE4B4; the function itself is 102 bytes.
 * Three spellings together give the image's frame: i is a u16 parameter
 * (spilled to [sp] at entry and reloaded for the i < 4 test), the slot and
 * entry offsets are `i << 4` (one CSE kept in r7 to the final store), and
 * the tail recomputes `(u32)i * 16` from the spilled i, which the compiler
 * does not merge with the `<< 4` value. slot is assigned p first, then
 * p + 8: both stores to its stack slot survive.
 */
void func_021BE418(u8 *p, u16 i)
{
    u8 *slot = p;
    u16 k;
    u8 *e;

    slot = p + 8;
    if (*(u32 *)(slot + (i << 4)) != 0 && i < 4) {
        e = p + (i << 4);
        for (k = 0; k < ((struct Obj12902 *)e)->f16; k++)
            func_020307B0(*(u8 **)(*(u8 * *)&((struct Obj12902 *)e)->f10 + k * 8 + 4));
        func_020307B0(*(void **)(p + 0x10 + (u32)i * 16));
        func_020307B0(*(void **)(p + 0xC + (u32)i * 16));
        func_020480E4((struct Ctx *)(((struct Obj20141 *)p)->f4), *(u16 *)(p + 0x14 + (u32)i * 16));
        *(u32 *)(slot + (i << 4)) = 0;
    }
}
