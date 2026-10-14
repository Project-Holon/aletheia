/*
 * function: BTLV_MCSS_ApplySlotScale
 * address:  0x022006B4
 * packet:   pkt_ov094_022006B4
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
 *   MCSS_SetScale  0x02015CAC  thumb
 *   MCSS_SetOfsScale  0x02015D30  thumb
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   BTLV_MCSS_CalcSlotScale  0x02201934  thumb  ov094
 *
 * MATCH: bytes identical; blocked on 0x02015D30, an unlabelled ARM9 Thumb
 * leaf (stores a VecFx32 at +0x104, beside the matched MCSS_SetScale) with no
 * witness. Filing that ARM9 leaf closes this.
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
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work;

typedef struct {
    fx32 x, y, z;
} VecFx32;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern int BTLV_MCSS_CalcSlotScale(Work *w, int i, int mode);
extern void MCSS_SetScale(void *p, u32 *src);
extern void MCSS_SetOfsScale(void *p, u32 *src);

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

void BTLV_MCSS_ApplySlotScale(Work *w, int i)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, i);
    fx32 v;
    VecFx32 s;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    v = BTLV_MCSS_CalcSlotScale(w, i, w->e[idx].flip);
    if (i & 1)
        v = FX_Mul(v, w->scaleOdd);
    else
        v = FX_Mul(v, w->scaleEven);
    s.x = v;
    s.y = v;
    s.z = 0x1000;
    MCSS_SetScale(w->e[idx].h, (u32 *)(&s));
    v = BTLV_MCSS_CalcSlotScale(w, i, 0);
    s.x = v;
    s.y = v;
    s.z = 0x1000;
    MCSS_SetOfsScale(w->e[idx].h, (u32 *)(&s));
}
