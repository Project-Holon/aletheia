/*
 * function: FLDEFF_SPLASH_AddModel
 * address:  0x021C4BE0
 * packet:   pkt_ov021_021C4BE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Queues callback gSplashModelObjFuncs with a two-word argument block.
 *
 * symbols:
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   gSplashModelObjFuncs     0x021DAA18  data  ov021
 */

typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
} P2;

extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(void *a, void *fn, u32 c, u32 d, P2 *e, u32 f);
extern char gSplashModelObjFuncs[];

void FLDEFF_SPLASH_AddModel(void *a, u32 b)
{
    P2 t;

    t.a = FIELD_EFFECT_GetResource((u32)a, 0x11);
    t.b = b;
    FIELD_EFFECT_AddObject(a, gSplashModelObjFuncs, 0, 0, &t, 0);
}
