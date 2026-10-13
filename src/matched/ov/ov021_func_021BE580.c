/*
 * function: FLD_EXP_OBJ_UpdateAnimes
 * address:  0x021BE580
 * packet:   pkt_ov021_021BE580
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_02048A00 returns u16 and the count local is u16: with that pair the
 * count spills to the lowest slot (sp+4) below the j*8 CSE temp and i.  An
 * int count, or a u16 count fed by an int return (extra lsl/lsr), shifts the
 * three slots.
 *
 * symbols:
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   func_02048A00  0x02048A00  arm
 *   FLD_EXP_OBJ_GetModelObject  0x021BE4C4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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
    int active;
    void *nodes;
    Grp *grps;
    u16 id;
    u16 n;
} Slot;

typedef struct {
    int heap;
    void *util;
    Slot slots[4];
} P;

extern u16 func_02048A00(void *util, u16 id);
extern void *FLD_EXP_OBJ_GetModelObject(P *p, int i, int j);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *h, int k, int v);
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *h, int k, int v);

void FLD_EXP_OBJ_UpdateAnimes(P *p)
{
    u8 i;
    u8 j;
    u8 k;
    int m;
    u16 n;
    void *h;
    Ent *e;

    for (i = 0; i < 4; i++) {
        if (p->slots[i].active == 1) {
            n = func_02048A00(p->util, p->slots[i].id);
            for (j = 0; j < n; j++) {
                h = FLD_EXP_OBJ_GetModelObject(p, i, j);
                m = p->slots[i].grps[j].n;
                for (k = 0; k < m; k++) {
                    e = &p->slots[i].grps[j].e[k];
                    if (e->f2 != 0 && e->f0 == 0) {
                        if (e->f1 != 0)
                            e->f8 = G3D_SYSTEM_LoopObjectAnimeFrame(h, k, e->f4);
                        else
                            e->f8 = G3D_SYSTEM_IncObjectAnimeFrame(h, k, e->f4);
                    }
                }
            }
        }
    }
}
