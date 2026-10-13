/*
 * function: FIELD_STATUS_SubProcEvent
 * address:  0x02014628
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The shared tail of the three working cases sits INSIDE case 0's arm (a
 * label a later arm jumps back to is what makes 0x02014658 fall out of case 0
 * with no branch) and the default arm's `return 0` is reached by a `goto`
 * rather than copied, which is what puts the single `movs r0, #0` epilogue at
 * 0x02014692.  `u32 a0 = p[0];` before the switch is load-bearing: without it
 * each arm reloads p[0] and the whole dispatch shifts.
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateSubProcNoFadeEvent  0x02014728  thumb
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *FIELD_STATUS_CreateSubProcNoFadeEvent(char *a0, int a1, int a2, int a3, int a4);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

u32 FIELD_STATUS_SubProcEvent(void *obj, u32 *mode, u32 *p)
{
    u32 a0 = p[0];
    void *r;

    switch (*mode) {
    case 0:
        r = (void *)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)a0, p[1], 0, 0);
    tail:
        GAME_EVENT_CallEvent(obj, r);
        (*mode)++;
        goto ret0;
    case 1:
        r = (void *)FIELD_STATUS_CreateSubProcNoFadeEvent((char *)a0, p[1], p[2], p[3], p[4]);
        goto tail;
    case 2:
        r = (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)a0, p[1], 0, 0, 1, 0, 0);
        goto tail;
    case 3:
        return 1;
    default:
    ret0:
        return 0;
    }
}
