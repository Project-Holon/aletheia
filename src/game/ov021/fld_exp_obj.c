/*
 * file:     fld_exp_obj.c
 * unit:     yes
 * function: func_021BE258, func_021BE288, func_021BE2A8, func_021BE2E0, func_021BE310, func_021BE418, func_021BE480, func_021BE4A4, func_021BE4B4, func_021BE4C4, func_021BE4F8, func_021BE580, func_021BE630, func_021BE674, func_021BE6B0, func_021BE6B4, func_021BE6B8, func_021BE6BC, func_021BE6CC, func_021BE6E8, func_021BE700, func_021BE748, func_021BE760, func_021BE89C, func_021BE8B8, func_021BE8D4, func_021BE92C, func_021BE9A0, func_021BE9F0, func_021BEA30, func_021BEA6C, func_021BEA9C, func_021BEACC, func_021BEAFC, func_021BEB38, func_021BEB78, func_021BEBA8, func_021BEBD8, func_021BEC24, func_021BEC54, func_021BEC84, func_021BECB4, func_021BECE4, func_021BED14, func_021BED44, func_021BED74, func_021BEDA4, func_021BEDD4, func_021BEE24
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
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02047790  0x02047790  arm
 *   func_020480E4  0x020480E4  arm
 *   func_02188D2C  0x02188D2C  thumb
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_02047A60  0x02047A60  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047910  0x02047910  arm
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 *   func_02047674  0x02047674  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02048010  0x02048010  arm
 *   func_02049238  0x02049238  arm
 *   func_02013FD8  0x02013FD8  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BF0E4  0x021BF0E4  thumb  ov021
 *   func_021BF518  0x021BF518  thumb  ov021
 *   func_021BEE74  0x021BEE74  thumb  ov021
 *   d_021D9F60  0x021D9F60  data
 *   d_021D9FF0     0x021D9FF0  data
 *   func_021BEEB4  0x021BEEB4  thumb  ov021
 *   func_021BEF08  0x021BEF08  thumb  ov021
 *   func_021BEF8C  0x021BEF8C  thumb  ov021
 *   func_021BF0A4  0x021BF0A4  thumb  ov021
 *   func_021BF130  0x021BF130  thumb  ov021
 *   func_021BF19C  0x021BF19C  thumb  ov021
 *   func_021BF348  0x021BF348  thumb  ov021
 *   func_021BF208  0x021BF208  thumb  ov021
 *   func_021BF3BC  0x021BF3BC  thumb  ov021
 *   func_021BF274  0x021BF274  thumb  ov021
 *   func_021BF430  0x021BF430  thumb  ov021
 *   func_021BF2E0  0x021BF2E0  thumb  ov021
 *   func_021BF4A4  0x021BF4A4  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 */
#include "../../matched/include/Obj12902.h"
#include "../../matched/include/Obj20141.h"
#include "../../matched/include/Obj12119.h"
#include "../../matched/include/Obj20142.h"
#include "../../matched/include/Obj20143.h"
#include "../../matched/include/Obj06057.h"
#include "../../matched/include/Obj09660.h"
#include "../../matched/include/Obj20144.h"
#include "../../matched/include/Obj12904.h"
#include "../../matched/include/Obj18259.h"
#include "../../matched/include/Obj18260.h"

struct Big;
struct Ctx;
struct Rec94;
struct Rec;
struct Arg;
struct AnmCtl;
struct P;
struct G3dSys;
struct Owner;
struct Desc;
struct Obj;
struct Obj00020;
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
} Ent_021BE258;

typedef struct {
    int n;
    Ent_021BE258 *e;
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
} Slot;

typedef struct P {
    int heap;
    void *util;
    Slot slots[4];
} P;

typedef struct {
    u8 pad[0xC];
    u16 fC;
    u16 pad2;
} SEnt;

typedef struct {
    u32 *arc;
    int f4;
    SEnt *ents;
    u16 n;
} Setup;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Ent_021BE8B8;

typedef struct {
    u32 v[6][6];
} Table;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Work;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; } X;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Work_021BEBA8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Ent_021BEBA8;

typedef struct {
    void *x0;
    u32 x4;
    u32 x8;
    u32 xc;
} Work_021BECB4;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Work_021BECE4;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Work_021BED44;

extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 func_0200B3AC(struct Rec94 *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *func_02047CFC(u16, u16, u16);
extern void func_02047E54(struct Rec *p);
extern u32 func_020307B0(void *p);
extern u16 func_02047F4C(void *util, const Setup *setup);
extern void func_0207ADC4(Mtx33 *m);
extern int func_02047790(int *p, int i);
extern void func_020480E4(struct Ctx *c, u32 i);
extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_02048A18(u8 *a0, int i);
extern u16 func_02048A00(void *a0, int i);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern void func_02047A60(void *a0, struct Arg *a1);
extern int func_02047910(void *h, int k, int v);
extern int func_020478B8(void *h, int k, int v);
extern u32 func_0204784C(struct AnmCtl *c, u32 idx, s32 *frame);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern int func_020477D4(struct Owner *owner, u32 index);
extern int func_02047674(int p);
extern void *func_020490F4(u32 id, u32 heap);
extern u16 func_02048010(void *util, const Setup *setup, void *arc);
extern void func_02049238(void *arc);
extern u8 func_02013FD8(u32 id);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_021BF0E4(u32 p0, int *st, u8 *q);
int func_021BF518(int a, int *s, int *q);
int func_021BEE74(u32 p0, int *st, u8 *q);
int func_021BEEB4(u32 p0, int *st, u8 *q);
extern int func_021BEF08(u32 p0, int *st, u8 *q);
extern int func_021BEF8C(u32 p0, int *st, u8 *q);
int func_021BF0A4(u32 p0, int *st, u8 *q);
int func_021BF130(u32 p0, int *st, u8 *q);
int func_021BF19C(u32 p0, int *st, u8 *q);
extern int func_021BF348(u32 p0, int *st, u8 *q);
int func_021BF208(u32 p0, int *st, u8 *q);
extern int func_021BF3BC(int a, int *s, int *q);
extern int func_021BF274(u32 p0, int *st, u8 *q);
extern int func_021BF430(int a, int *s, int *q);
int func_021BF2E0(u32 p0, int *st, u8 *q);
int func_021BF4A4(int a, int *s, int *q);
extern void *func_02188CB4(struct Obj00020 *p);
extern u16 func_021A3050(u8 *p);
void func_021BE258(void *p);
int func_021BE288(u8 *a, int b);
Obj_021BE2A8 *func_021BE2A8(u32 a, u32 b, u32 heap);
void func_021BE2E0(Obj_021BE2E0 *o);
void func_021BE310(P *p, Setup *b, u16 i);
void func_021BE418(u8 *p, u16 i);
int func_021BE480(char *p, unsigned i, int j);
void func_021BE4A4(char *p, int i, int j, int v);
void func_021BE4B4(char *p, int i, int j, int v);
void *func_021BE4C4(P *o, u32 i, int delta);
void func_021BE4F8(char *p);
void func_021BE580(P *p);
void func_021BE630(int *p, int n, int heap);
void *func_021BE674(char *base, int i, unsigned int j, int k);
void func_021BE6B0(unsigned char *p, int v);
u8 func_021BE6B4(u8 *p);
void func_021BE6B8(unsigned char *p, int v);
int func_021BE6BC(int *p);
void func_021BE6CC(int a, int b, int c, int d, int e);
int func_021BE6E8(int a, int b, int c, int d);
void func_021BE700(void *p, int i, int j, int k, int flag);
int func_021BE748(u32 a);
void func_021BE760(P *p, const Setup *b, u16 i);
int func_021BE89C(int a, u32 b);
int func_021BE8B8(int a, int b);
int func_021BE8D4(void *a, int b, int sel, int d);
int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
void *func_021BE9A0(void *p, int a1, int a2, int a3, int a4, int a5);
void *func_021BE9F0(void *p, int a1, int a2, int a3, int a4);
u32 func_021BEA30(u32 a, u32 b, u32 c, u32 d);
int func_021BEA6C(int x);
u32 func_021BEA9C(int row, int col);
u32 func_021BEACC(int a, int b);
void *func_021BEAFC(int a, int b, int c, int d);
void *func_021BEB38(void *p, int a1, int a2, int a3, int a4);
u32 func_021BEB78(u32 a, u32 b);
void *func_021BEBA8(int a, int b);
void *func_021BEBD8(void *p, int a1, int a2, int a3);
int func_021BEC24(int a, int b);
int func_021BEC54(int a, int b);
void *func_021BEC84(void *a, u32 b);
void *func_021BECB4(void *p, u32 b);
void *func_021BECE4(int a, int b);
u32 func_021BED14(u32 a, u32 b);
void *func_021BED44(int a, int b);
int func_021BED74(int a, int b);
int func_021BEDA4(int a, int b);
int func_021BEDD4(void *a, int b);
void func_021BEE24(void *a, void *b);
extern Handler d_021D9E74[];
extern int d_021DE390;
extern const Table d_021D9F60;
extern const Table d_021D9FF0;








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








/*
 * Unlabelled leaf in ov021, immediately after func_021BE418's epilogue
 * (0x021BE47C) and before the next traced function at 0x021BE4A4; it saves
 * nothing, so disasm.py prints it inside the pool/.word run.  It is the
 * blocker target of ov010's func_0216C280 (pkt_0216C280), reached across the
 * ov010/ov021 overlay pair.  Element lookup: stride 0x10, null when the +8
 * slot is zero or the index is out of range, else base + index*0x44 + 8.
 */
int func_021BE480(char *p, unsigned i, int j)
{
    char *e = p + i * 0x10;

    if (((struct Obj12119 *)e)->f8 == 0)
        return 0;
    if (i >= 4)
        return 0;
    return ((struct Obj12119 *)e)->fC + j * 0x44 + 8;
}








void func_021BE4A4(char *p, int i, int j, int v)
{
    char *e = p + i * 0x10;

    *(int *)(*(char * *)&((struct Obj20142 *)e)->fC + j * 0x44) = v;
}








void func_021BE4B4(char *p, int i, int j, int v)
{
    char *e = p + i * 0x10;

    *(int *)(*(char * *)&((struct Obj20143 *)e)->fC + j * 0x44 + 4) = v;
}







void *func_021BE4C4(P *o, u32 i, int delta)
{
    int v;

    if (o->slots[i].active == 0) {
        return 0;
    }
    if (i >= 4) {
        return 0;
    }
    v = func_020489F4((u8 *)o->util, o->slots[i].id);
    return (void *)func_02048A18((u8 *)o->util, (u16)(v + delta));
}







void func_021BE4F8(char *p)
{
    u8 i;
    u8 j;
    int base;
    int n;
    char *e;
    char *ent;

    for (i = 0; i < 4; i++) {
        e = p + i * 16;
        if (((struct Obj06057 *)e)->f8 == 1) {
            base = func_020489F4(((struct Obj09660 *)p)->f4, ((struct Obj06057 *)e)->f14);
            n = func_02048A00(((struct Obj09660 *)p)->f4, ((struct Obj06057 *)e)->f14);
            for (j = 0; j < n; j++) {
                if (*(int *)(*(char * *)&((struct Obj06057 *)e)->fC + j * 0x44 + 4) == 0) {
                    void *r = (void *)func_02048A18(((struct Obj09660 *)p)->f4, (u16)(base + j));
                    ent = *(char * *)&((struct Obj06057 *)e)->fC + j * 0x44;
                    if (((struct Obj20144 *)ent)->f0 != 0) {
                        func_02047AC8(r, (struct Arg *)(ent + 8));
                    } else {
                        func_02047A60(r, (struct Arg *)(ent + 8));
                    }
                }
            }
        }
    }
}






void func_021BE580(P *p)
{
    u8 i;
    u8 j;
    u8 k;
    int m;
    u16 n;
    void *h;
    Ent_021BE258 *e;

    for (i = 0; i < 4; i++) {
        if (p->slots[i].active == 1) {
            n = func_02048A00(p->util, p->slots[i].id);
            for (j = 0; j < n; j++) {
                h = func_021BE4C4(p, i, j);
                m = p->slots[i].grps[j].n;
                for (k = 0; k < m; k++) {
                    e = &p->slots[i].grps[j].e[k];
                    if (e->f2 != 0 && e->f0 == 0) {
                        if (e->f1 != 0)
                            e->f8 = func_02047910(h, k, e->f4);
                        else
                            e->f8 = func_020478B8(h, k, e->f4);
                    }
                }
            }
        }
    }
}







void func_021BE630(int *p, int n, int heap)
{
    u8 *e = (u8 *)func_02030734((u16)heap, n << 4, 1, (const char *)&d_021DE390, 0x19D);
    int i;

    p[1] = (int)e;
    p[0] = n;
    for (i = 0; i < n; i++) {
        e[i * 16] = 0;
        e[i * 16 + 1] = 1;
        e[i * 16 + 2] = 0;
        *(int *)(e + i * 16 + 4) = 0x1000;
    }
}







void *func_021BE674(char *base, int i, unsigned int j, int k)
{
    char *e = base + i * 16;
    struct S {
        int n;
        char *arr;
    };
    char *arr;

    if (((struct Obj12904 *)e)->f8 == 0) {
        return 0;
    }
    if (j >= ((struct Obj12904 *)e)->f16) {
        return 0;
    }
    arr = (*(struct S **)(e + 0x10))[j].arr;
    if (k >= (*(struct S **)(e + 0x10))[j].n) {
        return 0;
    }
    return arr + k * 16;
}






void func_021BE6B0(unsigned char *p, int v)
{
    p[0] = v;
}







u8 func_021BE6B4(u8 *p)
{
    return *p;
}






/*
 * Unlabelled leaf: strb r1, [r0, #1].
 */
void func_021BE6B8(unsigned char *p, int v)
{
    p[1] = v;
}






int func_021BE6BC(int *p)
{
    return p[2] == 0;
}





void func_021BE6CC(int a, int b, int c, int d, int e)
{
    int t = e;

    func_0204784C(func_021BE4C4((struct P *)a, b, c), d, &t);
}





int func_021BE6E8(int a, int b, int c, int d)
{
    int t;

    func_02047828(func_021BE4C4((struct P *)a, b, c), d, &t);
    return t;
}





void func_021BE700(void *p, int i, int j, int k, int flag)
{
    void *r6 = func_021BE4C4(p, i, j);
    u8 *e = func_021BE674(p, i, j, k);

    if (e == 0) {
        return;
    }
    if (flag != 0) {
        if (e[2] != 0) {
            return;
        }
        func_020477A4(r6, k);
    } else {
        if (e[2] == 0) {
            return;
        }
        func_020477D4(r6, k);
    }
    e[2] = flag;
}






int func_021BE748(u32 a)
{
return ((*(u16 *)((u8 *)(((struct Obj18260 *)((u8 *)(func_02047674(((struct Obj18259 *)((u8 *)(a)))->fC))))->f8) + 4) << 12) - (1 << 12));
}






/*
 * note:     twin of func_021BE310, opening its own archive for the setup call. Needs both
 *           the twin's `u16 i` and `const Setup *b`: int i swaps i's home store and the
 *           nd->f4 store (12 bytes), u16 i alone loads b->arc before p->heap (18 bytes).
 */
void func_021BE760(P *p, const Setup *b, u16 i)
{
    void *arc;
    u16 id;
    u16 n;
    Node *nodes;
    u16 j;

    arc = func_020490F4(*b->arc, (u16)(((u16)p->heap & 0x7FFF) | 0x8000));
    id = func_02048010(p->util, b, arc);
    func_02049238(arc);
    n = b->n;
    p->slots[i].n = n;
    p->slots[i].active = 1;
    p->slots[i].id = id;
    nodes = func_02030734((u16)p->heap, n * sizeof(Node), 1, (const char *)&d_021DE390, 0x23E);
    p->slots[i].nodes = nodes;
    p->slots[i].grps = func_02030734((u16)p->heap, n * sizeof(Grp), 1, (const char *)&d_021DE390, 0x241);
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
 * Addresses are Black-image addresses.
 */
int func_021BE89C(int a, u32 b)
{
    return func_021BEA9C(func_02013FD8(a), func_02013FD8(b));
}





int func_021BE8B8(int a, int b)
{
    int x = func_02013FD8(a);
    return func_021BEACC(x, func_02013FD8(b));
}





int func_021BE8D4(void *a, int b, int sel, int d)
{
    switch (sel) {
    default:
        return func_021BEB78((u32)a, b);
    case 0:
    case 1:
    case 3:
        return (int)func_021BEAFC((int)a, b, sel, d);
    case 4:
        return func_021BEC24((int)a, b);
    case 5:
        return func_021BEC54((int)a, b);
    case 6:
        return (int)func_021BECB4(a, b);
    case 7:
        return func_021BED14((u32)a, b);
    case 8:
        return func_021BED74((int)a, b);
    case 9:
        return func_021BEDD4(a, b);
    }
}





int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g)
{
    switch (sel) {
    default:
        return (int)func_021BEBA8((int)a, b);
    case 0:
    case 1:
        return (int)func_021BEB38(a, b, sel, d, e);
    case 3:
        return (int)func_021BEBD8(a, b, f, g);
    case 5:
        return (int)func_021BEC84(a, b);
    case 6:
        return (int)func_021BECE4((int)a, b);
    case 7:
        return (int)func_021BED44((int)a, b);
    case 8:
        return func_021BEDA4((int)a, b);
    case 9:
        func_021BEE24(a, (void *)b);
        break;
    }
}





/*
 * Allocator with callback, then link-node field setup with two byte fields and
 * two trailing stack arguments.
 */
void *func_021BE9A0(void *p, int a1, int a2, int a3, int a4, int a5)
{
    void *r0v = func_020122C0(p, 0, func_021BF0E4, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = 3;
    ((u8 *)r4)[0x20] = a2;
    ((u8 *)r4)[0x21] = a3;
    r4[3] = (int)func_021BEA6C(r4[2]);
    r4[9] = a4;
    r4[10] = a5;
    return r0v;
}





/*
 * Allocator with callback, then link-node field setup; returns the allocator
 * result.
 */
void *func_021BE9F0(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021BF518, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = a2;
    r4[5] = a3;
    r4[3] = (int)func_021BEA6C(a2);
    r4[4] = a4;
    return r0v;
}





u32 func_021BEA30(u32 a, u32 b, u32 c, u32 d)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BEE74, 0x2c);
    Ent_021BE8B8 *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = c;
    e->f14 = d;
    e->fC = func_021BEA6C(c);
    return h;
}




int func_021BEA6C(int x)
{
    switch (x) {
    case 0:
    default:
        return 3;
    case 1:
        return 12;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 2;
    }
}





u32 func_021BEA9C(int row, int col)
{
    Table t = d_021D9F60;

    return t.v[row][col];
}





u32 func_021BEACC(int a, int b)
{
    Table t = d_021D9FF0;

    return t.v[a][b];
}





void *func_021BEAFC(int a, int b, int c, int d)
{
    void *t = func_020122C0((void *)a, 0, func_021BEE74, 0x2c);
    Work *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = c;
    w->f14 = d;
    w->fC = func_021BEA6C(c);
    return t;
}





void *func_021BEB38(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021BEEB4, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = a2;
    r4[5] = a3;
    r4[3] = (int)func_021BEA6C(a2);
    r4[6] = a4;
    return r0v;
}




u32 func_021BEB78(u32 a, u32 b)
{
    u32 h = (u32)func_020122C0((void *)a, 0, func_021BEF08, 0x2c);
    X *x = func_020124E8((struct Obj *)h);
    x->f0 = a;
    x->f4 = b;
    x->f8 = 2;
    x->fC = func_021BEA6C(2);
    return h;
}



void *func_021BEBA8(int a, int b)
{
    void *t = func_020122C0((void *)a, 0, func_021BEF8C, 0x2c);
    Work_021BEBA8 *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = 2;
    w->fC = func_021BEA6C(2);
    return t;
}



void *func_021BEBD8(void *p, int a1, int a2, int a3)
{
    void *r0v = func_020122C0(p, 0, func_021BF0A4, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = 3;
    ((u8 *)r4)[0x20] = a2;
    ((u8 *)r4)[0x21] = a3;
    r4[3] = (int)func_021BEA6C(r4[2]);
    r4[9] = 0;
    r4[10] = 0;
    return r0v;
}



int func_021BEC24(int a, int b)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BF130, 0x2c);
    Ent_021BEBA8 *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 4;
    e->fC = func_021BEA6C(4);
    return h;
}



int func_021BEC54(int a, int b)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BF19C, 0x2c);
    Ent_021BEBA8 *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 5;
    e->fC = func_021BEA6C(5);
    return h;
}



void *func_021BEC84(void *a, u32 b)
{
    void *t = func_020122C0(a, 0, func_021BF348, 0x2c);
    u32 *w = func_020124E8(t);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = 5;
    w[3] = (u32)func_021BEA6C(5);
    return t;
}



void *func_021BECB4(void *p, u32 b)
{
    void *task = func_020122C0(p, 0, func_021BF208, 0x2C);
    Work_021BECB4 *w = func_020124E8(task);

    w->x0 = p;
    w->x4 = b;
    w->x8 = 6;
    w->xc = func_021BEA6C(6);
    return task;
}



void *func_021BECE4(int a, int b)
{
    void *t = func_020122C0((void *)a, 0, func_021BF3BC, 0x2c);
    Work_021BECE4 *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = 6;
    w->fC = func_021BEA6C(6);
    return t;
}


u32 func_021BED14(u32 a, u32 b)
{
    u32 h = (u32)func_020122C0((void *)a, 0, func_021BF274, 0x2c);
    X *x = func_020124E8((struct Obj *)h);
    x->f0 = a;
    x->f4 = b;
    x->f8 = 7;
    x->fC = func_021BEA6C(7);
    return h;
}



void *func_021BED44(int a, int b)
{
    void *t = func_020122C0((void *)a, 0, func_021BF430, 0x2c);
    Work_021BED44 *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = 7;
    w->fC = func_021BEA6C(7);
    return t;
}



int func_021BED74(int a, int b)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BF2E0, 0x2c);
    Ent_021BEBA8 *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 8;
    e->fC = func_021BEA6C(8);
    return h;
}



int func_021BEDA4(int a, int b)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BF4A4, 0x2c);
    Ent_021BEBA8 *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 8;
    e->fC = func_021BEA6C(8);
    return h;
}



int func_021BEDD4(void *a, int b)
{
    switch (func_021A3050(func_02188CB4((struct Obj00020 *)b))) {
    case 2:
    default:
        return func_021BED14((u32)a, b);
    case 3:
        return func_021BED74((int)a, b);
    case 0:
        return func_021BEC54((int)a, b);
    case 1:
        return (int)func_021BECB4(a, b);
    }
}



void func_021BEE24(void *a, void *b)
{
    switch (func_021A3050(func_02188CB4(b))) {
    case 2:
    default:
        func_021BED44((int)a, (int)b);
        break;
    case 3:
        func_021BEDA4((int)a, (int)b);
        break;
    case 0:
        func_021BEC84(a, (u32)b);
        break;
    case 1:
        func_021BECE4((int)a, (int)b);
        break;
    }
}
