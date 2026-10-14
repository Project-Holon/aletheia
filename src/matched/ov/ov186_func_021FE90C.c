/*
 * function: BR_FADE_StepFadeBgA
 * address: 0x021FE90C
 * packet: pkt_ov186_021FE90C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *
 * Three-state fade task.  start/end are assigned only for p[2] == 0 or 1:
 * the original passes callee-saved r5 and entry r2 unset on any other
 * value, exactly what C locals left unassigned on that path give
 * (docs/idioms/switch-arms-tail-merge.md).  The earlier DIFF note
 * initialised them to 16/0 and could not lose the extra moves.
 */
typedef unsigned int u32;
typedef signed int s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
int BR_FADE_StepFadeBgA(u32 *p, u32 *state)
{
    u32 mask;
    s32 start, end;
    switch (*state) {
    case 0:
        mask = 0;
        if (p[1] & 1) mask |= 1;
        if (p[1] & 2) mask |= 2;
        if (p[2] == 0) {
            start = 16;
            end = 0;
        } else if (p[2] == 1) {
            start = 0;
            end = 16;
        }
        FADE_Start(mask, start, end, p[6]);
        *state = 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) *state = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}
