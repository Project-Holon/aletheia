/*
 * function: EVENT_APPEAR_CreateFadeIn
 * address:  0x021BF898
 * packet:   pkt_ov021_021BF898
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn 0x021BE92C thumb ov021
 *   EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback 0x021BE9A0 thumb ov021
 *   EVENT_APPEAR_OnScoreboardEnd 0x021BF8DC thumb ov021
 */

typedef unsigned char u8;

extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback(void *p, int a1, int a2, int a3, int a4, int a5);
extern void EVENT_APPEAR_OnScoreboardEnd(u8 *);

void *EVENT_APPEAR_CreateFadeIn(int *q)
{
    int c = q[23];
    int a = q[0];
    int b = q[1];

    if (c != 0) {
        return EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback((void *)a, b, (u8)q[24], (u8)q[25], (int)EVENT_APPEAR_OnScoreboardEnd, (int)q);
    }
    return (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)a, b, 1, 1, 1, 0, 0);
}
