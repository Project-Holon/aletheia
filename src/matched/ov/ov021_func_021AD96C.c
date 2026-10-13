/*
 * function: FLDEFF_ENCOUNT_LoadModels
 * address:  0x021AD96C
 * packet:   pkt_ov021_021AD96C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetModelBaseOffset  0x021ABE28  thumb  ov021
 *   FIELD_EFFECT_GetModelBaseOffsetAlt  0x021ABE2C  thumb  ov021
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
    u16 tab[1];
} Desc;

typedef struct P {
    int f0;
    int f4;
    int f8[4];
    int f18[1];
} P;

typedef unsigned int   u32;
extern u8 FIELD_EFFECT_GetModelBaseOffset(u8 *p);
extern u8 FIELD_EFFECT_GetModelBaseOffsetAlt(u8 *p);
struct A;
struct B;
extern void FLDEFF_ENCOUNT_BuildDrawSet(struct A *a, struct B *b, int c);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern int G3D_SYSTEM_TransVramTexture(int *self);

void FLDEFF_ENCOUNT_LoadModels(P *a, Desc *d, int c)
{
    int base;
    int i;
    int j;
    int t;

    base = 0;
    if (d->b6) {
        base = FIELD_EFFECT_GetModelBaseOffset((u8 *)a->f0);
    } else if (d->b7) {
        base = FIELD_EFFECT_GetModelBaseOffsetAlt((u8 *)a->f0);
    }
    for (i = 0; i < d->lo; i++) {
        t = base + i * d->mid;
        a->f8[i] = (int)G3D_SYSTEM_CreateResourceArcHandle(c, d->h4 + t);
        G3D_SYSTEM_TransVramTexture((int *)a->f8[i]);
        for (j = 0; j < d->n; j++) {
            a->f18[i * d->n + j] = (int)G3D_SYSTEM_CreateResourceArcHandle(c, t + d->tab[j]);
        }
        FLDEFF_ENCOUNT_BuildDrawSet((struct A *)((char *)a + 0x28 + i * 0x18), (struct B *)a, (u8)i);
    }
}
