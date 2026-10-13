/*
 * function: BTL_CLIENT_GetMoveAnimTarget
 * address:  0x021D2000
 * packet:   pkt_ov093_021D2000
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (filed for the blocker of BTL_CLIENT_StepPlayMoveAnim, lane S15).
 *
 * symbols:
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_CALC_GetCurseTargetKind  0x021D80A8  thumb  ov093
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern int BTL_CALC_GetCurseTargetKind(void *p);
extern u32 WAZA_TOOL_GetParam(u32 v, u32 n);

u32 BTL_CLIENT_GetMoveAnimTarget(u32 *p, u32 k, u8 b)
{
    u8 *r;

    if (k != 0xAE) {
        return WAZA_TOOL_GetParam(k, 0x1B);
    }
    r = BTL_SIDE_GetPokeAtPos((char *const *)p[1], b);
    if (r) {
        return BTL_CALC_GetCurseTargetKind(r);
    }
    return WAZA_TOOL_GetParam(k, 0x1B);
}
