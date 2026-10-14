/*
 * function: BTLV_MCSS_SetSpriteWorkFlagForRule
 * address:  0x0220055C
 * packet:   pkt_ov094_0220055C
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
 * symbols:
 *   MCSS_SetWorkFlag  0x02016394  thumb
 *   BTLV_EFFECT_GetMode  0x021F8710  thumb  ov094
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *
 * blocker: unlabelled arm9 Thumb leaf MCSS_SetWorkFlag (the integrator's; no witness outside
 *   0220055C..022005C2). Every concrete byte matches (MATCH*, the extent's 2 extra bytes
 *   are the pad); only the final bl relocation stays wildcarded.
 *   Verified C (match.py one, --thumb, no --region, dsi/1.1p1 -O4,p), EXACT, 28 bytes:
 *
 *     typedef struct { char pad[0x140]; unsigned int lo : 30; unsigned int f : 1;
 *                      unsigned int hi : 1; } S;
 *     void MCSS_SetWorkFlag(S *s, int f)        // 0x02016394
 *     {
 *         s->f = f;
 *     }
 *
 * lever: each arm of the result switch writes `f = 1` out in its own inner switch
 *   (`switch (key) { case 3: case 4: f = 1; break; }`), so the case-1 copy is
 *   cross-jumped into a `b` after threading and the key == 3 beq keeps pointing at it
 *   (a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md); a
 *   shared `set:` label lets the beq be threaded straight to `f = 1` (2 bytes out), and
 *   `key == 3 || key == 4` folds to a range test.
 */
typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern int BTLV_EFFECT_GetMode(void);
extern void MCSS_SetWorkFlag(void *h, int flag);

void BTLV_MCSS_SetSpriteWorkFlagForRule(Work *w, int key, int mode)
{
    int f = 0;
    int i;

    i = BTLV_MCSS_FindSpriteIndex((char *)w, key);
    if (i == -1)
        return;
    if (w->e[i].h == 0)
        return;
    if (mode == 1) {
        switch (BTLV_EFFECT_GetMode()) {
        case 0:
        case 3:
            break;
        case 1:
            switch (key) {
            case 3:
            case 4:
                f = 1;
                break;
            }
            break;
        case 2:
            switch (key) {
            case 2:
            case 5:
            case 6:
                f = 1;
                break;
            }
            break;
        }
    }
    MCSS_SetWorkFlag(w->e[i].h, f);
}
