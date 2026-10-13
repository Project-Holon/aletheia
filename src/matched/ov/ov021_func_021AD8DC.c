/*
 * function: FLDEFF_ENCOUNT_LoadKind0Models
 * address:  0x021AD8DC
 * packet:   pkt_ov021_021AD8DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetModelBaseOffset  0x021ABE28  thumb  ov021
 *   FLDEFF_ENCOUNT_BuildDrawSet  0x021AD82C  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Desc {
    u8 n;
    u8 lo : 3;
    u8 mid : 3;
    u8 b6 : 1;
    u8 b7 : 1;
    u16 pad2;
    u16 h4;
    u16 h6;
} Desc;

typedef struct P {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
} P;

typedef unsigned int   u32;
extern u8 FIELD_EFFECT_GetModelBaseOffset(u8 *p);
struct A;
struct B;
extern void FLDEFF_ENCOUNT_BuildDrawSet(struct A *a, struct B *b, int c);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern int G3D_SYSTEM_TransVramTexture(int *self);

void FLDEFF_ENCOUNT_LoadKind0Models(P *a, Desc *d, int c)
{
    int r7;

    r7 = FIELD_EFFECT_GetModelBaseOffset((u8 *)a->f0);
    G3D_SYSTEM_TransVramTexture((int *)(a->f8 = (int)G3D_SYSTEM_CreateResourceArcHandle(c, d->h4 + r7)));
    a->f18 = (int)G3D_SYSTEM_CreateResourceArcHandle(c, d->h6 + r7);
    FLDEFF_ENCOUNT_BuildDrawSet((struct A *)((char *)a + 0x28), (struct B *)a, 0);
    r7 += d->mid;
    G3D_SYSTEM_TransVramTexture((int *)(a->fc = (int)G3D_SYSTEM_CreateResourceArcHandle(c, d->h4 + r7)));
    a->f1c = (int)G3D_SYSTEM_CreateResourceArcHandle(c, d->h6 + r7);
    FLDEFF_ENCOUNT_BuildDrawSet((struct A *)((char *)a + 0x40), (struct B *)a, 1);
    G3D_SYSTEM_TransVramTexture((int *)(a->f10 = (int)G3D_SYSTEM_CreateResourceArcHandle(c, d->h4)));
    a->f20 = (int)G3D_SYSTEM_CreateResourceArcHandle(c, d->h6);
    FLDEFF_ENCOUNT_BuildDrawSet((struct A *)((char *)a + 0x58), (struct B *)a, 2);
}
