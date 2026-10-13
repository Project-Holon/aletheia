/*
 * function: FLD_EXP_OBJ_AddUnit
 * address:  0x021BE310
 * packet:   pkt_ov021_021BE310
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_UTIL_AddUnitLoaded  0x02047F4C  arm
 *   func_02030734  0x02030734  arm
 *   FLD_EXP_OBJ_InitAnimeSet  0x021BE630  thumb  ov021
 *   func_0207ADC4  0x0207ADC4  arm
 *   FLD_EXP_OBJ_GetModelObject  0x021BE4C4  thumb  ov021
 *   G3D_SYSTEM_GetObjectAnime  0x02047790  arm
 *   sFldExpObjFileName     0x021DE390  data   a4
 *
 * The u16 slot index is what moves its home store (str r2, [sp, #0xc]) to
 * the front of the prologue; with k declared ahead of nd the loop counter
 * takes r4, the register the zero stores share.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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
    int f0;
    int f4;
    SEnt *ents;
    u16 n;
} Setup;

extern int sFldExpObjFileName;

extern u16 G3D_UTIL_AddUnitLoaded(void *util, const Setup *setup);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FLD_EXP_OBJ_InitAnimeSet(int *p, int n, int heap);
extern void func_0207ADC4(Mtx33 *m);
extern void *FLD_EXP_OBJ_GetModelObject(P *p, int i, int j);
extern int G3D_SYSTEM_GetObjectAnime(int *p, int i);

static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

void FLD_EXP_OBJ_AddUnit(P *p, Setup *b, u16 i)
{
    u16 id;
    u16 n;
    Node *nodes;
    u16 j;

    id = G3D_UTIL_AddUnitLoaded(p->util, b);
    n = b->n;
    p->slots[i].n = n;
    p->slots[i].active = 1;
    p->slots[i].id = id;
    nodes = func_02030734((u16)p->heap, n * sizeof(Node), 1, (const char *)&sFldExpObjFileName, 0x8b);
    p->slots[i].nodes = nodes;
    p->slots[i].grps = func_02030734((u16)p->heap, n * sizeof(Grp), 1, (const char *)&sFldExpObjFileName, 0x8e);
    for (j = 0; j < n; j++) {
        int k;
        Node *nd;
        void *h;
        Grp *g;

        FLD_EXP_OBJ_InitAnimeSet((int *)(&p->slots[i].grps[j]), b->ents[j].fC, p->heap);
        nd = &nodes[j];
        vset(&nd->s, 0x1000, 0x1000, 0x1000);
        func_0207ADC4(&nd->r);
        vset(&nd->t, 0, 0, 0);
        nd->f0 = 0;
        nd->f4 = 0;
        h = FLD_EXP_OBJ_GetModelObject(p, i, j);
        g = &p->slots[i].grps[j];
        for (k = 0; k < g->n; k++)
            g->e[k].fC = (void *)G3D_SYSTEM_GetObjectAnime(h, (u16)k);
    }
}
