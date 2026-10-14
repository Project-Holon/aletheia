/*
 * function: BTLV_MCSS_SwapSprites
 * address:  0x021FF7B0
 * packet:   pkt_ov094_021FF7B0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_GetGauge  0x021F86B4  thumb  ov094
 *   BTLV_MCSS_SetVanishMode  0x021FF374  thumb  ov094
 *   BTLV_MCSS_StartPositionTween  0x021FF4C0  thumb  ov094
 *   BTLV_MCSS_IsSpriteLoaded  0x021FFD9C  thumb  ov094
 *   BTLV_MCSS_CalcSlotPosition  0x022018A8  thumb  ov094
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   BTLV_GAUGE_HideSlot  0x022089BC  thumb  ov094
 */
typedef struct {
    int x, y, z;
} Vec3;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x44];
    int key;                /* 0x48 */
    unsigned int pad4c : 6; /* 0x4c */
    unsigned int f6 : 1;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern void BTLV_MCSS_CalcSlotPosition(Work *w, Vec3 *out, int key);
extern void BTLV_MCSS_StartPositionTween(Work *w, int key, int a, Vec3 *v, int b, int c, int d);
extern int BTLV_EFFECT_GetGauge(void);
extern void BTLV_GAUGE_HideSlot(char *p, int i);
extern void BTLV_MCSS_SetVanishMode(Work *w, int key, int kind);

void BTLV_MCSS_SwapSprites(Work *w, int a, int b)
{
    int keys[2];
    int idx[2];
    Vec3 v;
    int i;

    keys[0] = a;
    keys[1] = b;
    for (i = 0; i < 2; i++) {
        idx[i] = BTLV_MCSS_FindSpriteIndex((char *)w, keys[i]);
        if (BTLV_MCSS_IsSpriteLoaded((char *)w, keys[i])) {
            BTLV_MCSS_CalcSlotPosition(w, &v, keys[i ^ 1]);
            BTLV_MCSS_StartPositionTween(w, keys[i], 0, &v, 0, 0, 0);
            BTLV_GAUGE_HideSlot((char *)BTLV_EFFECT_GetGauge(), keys[i]);
            if (w->e[idx[i]].f6) {
                w->e[idx[i]].f6 = 0;
                BTLV_MCSS_SetVanishMode(w, keys[i], 0);
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (idx[i] != -1)
            w->e[idx[i]].key = keys[i ^ 1];
    }
}
