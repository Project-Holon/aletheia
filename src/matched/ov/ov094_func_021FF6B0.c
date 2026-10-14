/*
 * function: BTLV_MCSS_StartDrawScaleTween
 * address:  0x021FF6B0
 * packet:   pkt_ov094_021FF6B0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * symbols:
 *   MCSS_GetShadowScale  0x02015CC4  thumb
 *   BTLV_EFFECT_GetBitMask  0x021F935C  thumb  ov094
 *   BTLV_MCSS_CreateTweenTask  0x0220074C  thumb  ov094
 *   BTLV_MCSS_DrawScaleTweenTaskMain  0x02200B48  thumb  ov094
 *   BTLV_MCSS_DrawScaleTweenTaskEnd  0x02200BD4  thumb  ov094
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *
 * Byte-correct; MATCH blocked on one unlabelled ARM9 Thumb leaf (the integrator's; no
 * witness outside the range): MCSS_GetShadowScale (copies three words from +0x128).
 * Verified C (match.py one, no --region, --thumb, EXACT):
 *   typedef unsigned int u32;
 *   void MCSS_GetShadowScale(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x128);
 *       out[1] = *(u32 *)((char *)p + 0x12C);
 *       out[2] = *(u32 *)((char *)p + 0x130);
 *   }
 * Twin of matched BTLV_MCSS_StartScaleTween.
 */
typedef unsigned char u8;
typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad510[0x518 - 0x510];
    int mask[4];            /* 0x518 */
    char pad528[0x550 - 0x528];
    u8 cnt[4][14];          /* 0x550 */
} Work;

typedef unsigned int   u32;
extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void MCSS_GetShadowScale(void *p, u32 *out);
extern int BTLV_EFFECT_GetBitMask(int x);
extern void BTLV_MCSS_CreateTweenTask(Work *w, int i, int kind, VecFx32 *p, VecFx32 *q, int n,
                          int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50);
extern void BTLV_MCSS_DrawScaleTweenTaskMain(void);
extern void BTLV_MCSS_DrawScaleTweenTaskEnd(void *p);

void BTLV_MCSS_StartDrawScaleTween(Work *w, int i, int kind, VecFx32 *q, int n, int f48, int f4c)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, i);
    VecFx32 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetShadowScale(w->e[idx].h, (u32 *)(&cur));
    w->cnt[2][i]++;
    BTLV_MCSS_CreateTweenTask(w, i, kind, &cur, q, n, f48, f4c, (void *)BTLV_MCSS_DrawScaleTweenTaskMain, BTLV_MCSS_DrawScaleTweenTaskEnd, 0, w->cnt[2][i]);
    w->mask[3] |= BTLV_EFFECT_GetBitMask(i);
}
