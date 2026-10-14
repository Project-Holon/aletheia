/*
 * function: BTLV_MCSS_SetBlinkMode
 * address:  0x021FF260
 * packet:   pkt_ov094_021FF260
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
 * Blocker: three unlabelled arm9 Thumb leaves (relocation wildcards, no witness):
 *   MCSS_SetMepachiFlag, MCSS_ResetMepachiFlag, MCSS_FlipMepachiFlag.  All the integrator's; verified C
 *   (one --thumb, no --region, EXACT each; +0x140 is a register-like word):
 *     struct R { unsigned int : 8; unsigned int f : 1; };
 *     void MCSS_SetMepachiFlag(void *p) { *(unsigned int *)((char *)p + 0x140) |= 0x100u; }
 *     void MCSS_ResetMepachiFlag(void *p) { *(unsigned int *)((char *)p + 0x140) &= ~0x100u; }
 *     void MCSS_FlipMepachiFlag(void *p) { ((struct R *)((char *)p + 0x140))->f ^= 1; }
 *   Re-run this file once layout/matched/arm9 shards for all three exist.
 *
 * symbols:
 *   MCSS_SetMepachiFlag  0x02015DB0  thumb
 *   MCSS_ResetMepachiFlag  0x02015DC0  thumb
 *   MCSS_FlipMepachiFlag  0x02015DD4  thumb
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 */
typedef struct {
    void *h;
    char pad04[0x48];
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry;
typedef struct {
    int pad00;
    void *obj;
    Entry e[14];
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void MCSS_SetMepachiFlag(void *p);
extern void MCSS_ResetMepachiFlag(void *p);
extern void MCSS_FlipMepachiFlag(void *p);

void BTLV_MCSS_SetBlinkMode(Work *w, int key, int mode)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    if (mode == 4) {
        MCSS_ResetMepachiFlag(w->e[idx].h);
        w->e[idx].f0 = 0;
    }
    if (w->e[idx].f0)
        return;
    if (mode == 2) {
        MCSS_FlipMepachiFlag(w->e[idx].h);
    } else if (mode == 1) {
        MCSS_SetMepachiFlag(w->e[idx].h);
    } else if (mode == 3) {
        MCSS_SetMepachiFlag(w->e[idx].h);
        w->e[idx].f0 = 1;
    } else {
        MCSS_ResetMepachiFlag(w->e[idx].h);
    }
}
