/*
 * function: BTLV_MCSS_StartRotateTween
 * address:  0x021FF730
 * packet:   pkt_ov094_021FF730
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
 *   MCSS_GetRotate  0x02015CF8  thumb
 *   BTLV_EFFECT_GetBitMask  0x021F935C  thumb  ov094
 *   BTLV_MCSS_CreateTweenTask  0x0220074C  thumb  ov094
 *   BTLV_MCSS_RotateTweenTaskMain  0x02200C0C  thumb  ov094
 *   BTLV_MCSS_RotateTweenTaskEnd  0x02200C98  thumb  ov094
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *
 * Byte-correct; MATCH blocked on one unlabelled ARM9 Thumb leaf (the integrator's; no
 * witness outside the range): MCSS_GetRotate (copies three words from +0xF8).
 * Verified C (match.py one, no --region, --thumb, EXACT):
 *   typedef unsigned int u32;
 *   void MCSS_GetRotate(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0xF8);
 *       out[1] = *(u32 *)((char *)p + 0xFC);
 *       out[2] = *(u32 *)((char *)p + 0x100);
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
extern void MCSS_GetRotate(void *p, u32 *out);
extern int BTLV_EFFECT_GetBitMask(int x);
extern void BTLV_MCSS_CreateTweenTask(Work *w, int i, int kind, VecFx32 *p, VecFx32 *q, int n,
                          int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50);
extern void BTLV_MCSS_RotateTweenTaskMain(void);
extern void BTLV_MCSS_RotateTweenTaskEnd(void *p);

void BTLV_MCSS_StartRotateTween(Work *w, int i, int kind, VecFx32 *q, int n, int f48, int f4c)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, i);
    VecFx32 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetRotate(w->e[idx].h, (u32 *)(&cur));
    w->cnt[3][i]++;
    BTLV_MCSS_CreateTweenTask(w, i, kind, &cur, q, n, f48, f4c, (void *)BTLV_MCSS_RotateTweenTaskMain, BTLV_MCSS_RotateTweenTaskEnd, 1, w->cnt[3][i]);
    w->mask[1] |= BTLV_EFFECT_GetBitMask(i);
}
