/*
 * function: func_021FF304
 * address:  0x021FF304
 * packet:   pkt_ov094_021FF304
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * Blocker: two unlabelled arm9 Thumb leaves (relocation wildcards, no witness):
 *   MCSS_SetAnmStopFlagAlways (0x02015E28) and MCSS_ResetAnmStopFlagAlways (0x02015E70).  Both are the integrator's;
 *   verified C (one --thumb, no --region, EXACT each):
 *     struct R { unsigned int : 9; unsigned int f : 2; };
 *     void MCSS_SetAnmStopFlagAlways(void *p) { ((struct R *)((char *)p + 0x140))->f |= 2; }
 *     void MCSS_ResetAnmStopFlagAlways(void *p) { ((struct R *)((char *)p + 0x140))->f &= ~2u; }
 *   Re-run this file once layout/matched/arm9 shards for both exist.
 *
 * symbols:
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetAnmStopFlagAlways  0x02015E28  thumb
 *   MCSS_ResetAnmStopFlagAlways  0x02015E70  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 */
typedef struct {
    void *h;
    char pad[0x58];
} Entry;
typedef struct {
    int pad00;
    void *obj;
    Entry e[14];
} Work;

extern int func_022019F4(char *p, int key);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_SetAnmStopFlagAlways(void *p);
extern void MCSS_ResetAnmStopFlagAlways(void *p);
extern void MCSS_ResetAnmStopFlag(void *p);

void func_021FF304(Work *w, int key, int mode)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    if (mode == 1)
        MCSS_SetAnmStopFlag(w->e[idx].h);
    else if (mode == 2)
        MCSS_SetAnmStopFlagAlways(w->e[idx].h);
    else if (mode == 3)
        MCSS_ResetAnmStopFlagAlways(w->e[idx].h);
    else
        MCSS_ResetAnmStopFlag(w->e[idx].h);
}
