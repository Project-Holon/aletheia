/*
 * function: BTLV_MCSS_StartScaleTween
 * address:  0x021FF630
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_GetScale  0x02015C94  thumb
 *   BTLV_EFFECT_GetBitMask  0x021F935C  thumb  ov094
 *   BTLV_MCSS_CreateTweenTask  0x0220074C  thumb  ov094
 *   BTLV_MCSS_ScaleTweenTaskMain  0x02200A84  thumb  ov094
 *   BTLV_MCSS_ScaleTweenTaskEnd  0x02200B10  thumb  ov094
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 */
typedef unsigned int u32;
typedef int fx32;
typedef long long s64;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad514[0x520 - 0x008 - 14 * 0x5c];
    int mask;               /* 0x520 */
    char pad524[0x534 - 0x524];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
    char pad540[0x55e - 0x540];
    unsigned char cnt[14];  /* 0x55e */
} Work;

typedef unsigned char u8;

typedef struct {
    fx32 x, y, z;
} VecFx32;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void MCSS_GetScale(void *p, u32 *out);
extern int BTLV_EFFECT_GetBitMask(int x);
extern void BTLV_MCSS_CreateTweenTask(Work *w, int i, int kind, VecFx32 *p, VecFx32 *q, int n,
                          int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50);
extern void BTLV_MCSS_ScaleTweenTaskMain(void);
extern void BTLV_MCSS_ScaleTweenTaskEnd(void *p);

void BTLV_MCSS_StartScaleTween(Work *w, int i, int kind, VecFx32 *q, int n, int f48, int f4c)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, i);
    VecFx32 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetScale(w->e[idx].h, (u32 *)(&cur));
    w->cnt[i]++;
    BTLV_MCSS_CreateTweenTask(w, i, kind, &cur, q, n, f48, f4c, (void *)BTLV_MCSS_ScaleTweenTaskMain, BTLV_MCSS_ScaleTweenTaskEnd, 0, w->cnt[i]);
    w->mask |= BTLV_EFFECT_GetBitMask(i);
}
