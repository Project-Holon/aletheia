/*
 * file:     fld_exp_obj_p04.c
 * unit:     yes
 * function: func_021BE748, func_021BE760, func_021BE89C
 * address:  0x021BE748
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
 *   func_02047674  0x02047674  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02048010  0x02048010  arm
 *   func_02049238  0x02049238  arm
 *   func_02030734  0x02030734  arm
 *   func_021BE630  0x021BE630  thumb  ov021
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021BE4C4  0x021BE4C4  thumb  ov021
 *   func_02047790  0x02047790  arm
 *   d_021DE390     0x021DE390  data   a4
 *   func_02013FD8  0x02013FD8  thumb
 *   func_021BEA9C  0x021BEA9C  thumb  ov021
 */
#include "../../matched/include/Obj18259.h"
#include "../../matched/include/Obj18260.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

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
} Slot;

typedef struct {
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

extern int func_02047674(int p);
extern void *func_020490F4(u32 id, u32 heap);
extern u16 func_02048010(void *util, const Setup *setup, void *arc);
extern void func_02049238(void *arc);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void func_021BE630(int *p, int n, int heap);
extern void func_0207ADC4(Mtx33 *m);
extern void *func_021BE4C4(P *p, int i, int j);
extern int func_02047790(int *p, int i);
extern u8 func_02013FD8(u32 id);
extern u32 func_021BEA9C(int row, int col);
int func_021BE748(u32 a);
void func_021BE760(P *p, const Setup *b, u16 i);
int func_021BE89C(int a, u32 b);
extern int d_021DE390;


int func_021BE748(u32 a)
{
return ((*(u16 *)((u8 *)(((struct Obj18260 *)((u8 *)(func_02047674(((struct Obj18259 *)((u8 *)(a)))->fC))))->f8) + 4) << 12) - (1 << 12));
}


static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
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
