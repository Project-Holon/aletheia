/*
 * function: FLDEFF_ENCOUNT_FreeResources
 * address:  0x021ADA1C
 * packet:   pkt_ov021_021ADA1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDEFF_ENCOUNT_DeleteDrawSet  0x021AD8A4  thumb  ov021
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 */
typedef unsigned char u8;

typedef struct Q {
    int f0;
    int f4;
    int f8[4];
    int f18[28];
    u8 n;
    u8 cnt : 3;
} Q;

struct W;
struct Z;
extern void FLDEFF_ENCOUNT_DeleteDrawSet(struct Z *z, struct W *w);
typedef unsigned int   u32;
struct Tagged;
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);

void FLDEFF_ENCOUNT_FreeResources(Q *a)
{
    int i;

    for (i = 0; i < a->cnt; i++) {
        FLDEFF_ENCOUNT_DeleteDrawSet((struct Z *)((char *)a + 0x28 + i * 0x18), (struct W *)a);
    }
    for (i = 0; i < a->n * a->cnt; i++) {
        G3D_SYSTEM_DeleteResource((struct Tagged *)a->f18[i]);
    }
    for (i = 0; i < a->cnt; i++) {
        G3D_SYSTEM_FreeVramTexture((u32 *)a->f8[i]);
        G3D_SYSTEM_DeleteResource((struct Tagged *)a->f8[i]);
    }
}
