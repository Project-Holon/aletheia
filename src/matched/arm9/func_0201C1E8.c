/*
 * function: WAZA_TOOL_GetDamageType
 * address:  0x0201C1E8
 * packet:   pkt_0201C1E8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with argument 2. Filed as the witness for ov094 BTLV_EFFECT_StartDamageTintTask.
 *
 * symbols:
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 */

extern int WAZA_TOOL_GetParam(int, int);

int WAZA_TOOL_GetDamageType(int a)
{
    return WAZA_TOOL_GetParam(a, 2);
}
