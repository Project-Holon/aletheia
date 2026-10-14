/*
 * function: BTLV_EFFVM_SpriteCleanupTaskMain
 * address:  0x021FE9F0
 * packet:   pkt_ov094_021FE9F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the loop counter is an enum (keeps the `cmp r4,#8; bge` entry guard
 * and the unfolded (1<<12)>>1 rounding constants after it), see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 *
 * symbols:
 *   _ll_mul        0x0209C054  arm
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_SetSideScale  0x021FF134  thumb  ov094
 *   BTLV_MCSS_IsSpriteLoaded  0x021FFD9C  thumb  ov094
 *   BTLV_MCSS_GetSlotScale  0x021FF468  thumb  ov094
 *   BTLV_MCSS_StartScaleTween  0x021FF630  thumb  ov094
 */
typedef int fx32;
typedef long long fx64;
typedef struct { fx32 x, y, z; } VecFx32;

typedef enum { SLOT_0, SLOT_MAX = 8 } Slot;

extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_SetSideScale(char *p, int a, int b);
extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern int BTLV_MCSS_GetSlotScale(void *u, int i, int mode);
extern void BTLV_MCSS_StartScaleTween(char *w, int i, int kind, VecFx32 *q, int n, int f48, int f4c);

void BTLV_EFFVM_SpriteCleanupTaskMain(fx32 a, fx32 b, int n, int f48, int f4c)
{
    Slot i;
    VecFx32 v;
    fx32 s;
    fx32 t;

    BTLV_MCSS_SetSideScale((char *)BTLV_EFFECT_GetMcss(), a, b);
    for (i = 0; i < 8; i++) {
        if (BTLV_MCSS_IsSpriteLoaded((char *)BTLV_EFFECT_GetMcss(), i)) {
            s = BTLV_MCSS_GetSlotScale((void *)BTLV_EFFECT_GetMcss(), i, 1);
            if (i & 1)
                t = (fx32)(((fx64)s * b + ((fx64)(1 << 12) >> 1)) >> 12);
            else
                t = (fx32)(((fx64)s * a + ((fx64)(1 << 12) >> 1)) >> 12);
            v.x = t;
            v.y = t;
            v.z = 1 << 12;
            BTLV_MCSS_StartScaleTween((char *)BTLV_EFFECT_GetMcss(), i, 1, &v, n, f48, f4c);
        }
    }
}
