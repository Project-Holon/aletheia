/*
 * function: BTLV_MCSS_SetVanishMode
 * address:  0x021FF374
 * packet:   pkt_ov094_021FF374
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
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   MCSS_GetVanishFlag  0x02015E94  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_FlipVanishFlag  0x02015EC4  thumb
 *
 * Byte-correct; MATCH blocked on two unlabelled ARM9 Thumb leaves (the integrator's;
 * no witness outside the range): MCSS_GetVanishFlag and MCSS_FlipVanishFlag. Verified C
 * (match.py one, no --region, --thumb, EXACT), both over
 *   typedef struct { char pad[0x140]; unsigned int lo : 11; unsigned int b : 1;
 *                    unsigned int hi : 20; } R;
 *   int  MCSS_GetVanishFlag(R *p) { return p->b; }
 *   void MCSS_FlipVanishFlag(R *p) { p->b = p->b ^ 1; }   (`!p->b` is DIFF)
 * (MCSS_SetVanishFlag/EB0 set/clear the same bit, already matched.)
 */
typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 5;    /* 0x4c */
    unsigned int f5 : 1;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern int MCSS_GetVanishFlag(void *h);
extern void MCSS_SetVanishFlag(void *h);
extern void MCSS_ResetVanishFlag(void *h);
extern void MCSS_FlipVanishFlag(void *h);

void BTLV_MCSS_SetVanishMode(Work *w, int key, int kind)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    switch (kind) {
    case 2:
        MCSS_FlipVanishFlag(w->e[idx].h);
        break;
    case 1:
        MCSS_SetVanishFlag(w->e[idx].h);
        break;
    case 0:
        MCSS_ResetVanishFlag(w->e[idx].h);
        break;
    case 3:
        if (MCSS_GetVanishFlag(w->e[idx].h))
            w->e[idx].f5 = 1;
        MCSS_SetVanishFlag(w->e[idx].h);
        break;
    case 4:
        if (w->e[idx].f5)
            w->e[idx].f5 = 0;
        else
            MCSS_ResetVanishFlag(w->e[idx].h);
        break;
    }
}
