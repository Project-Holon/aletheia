/*
 * function: BTL_ABILITY_AbsorbCheckMoveType
 * address: 0x021DA8A8
 * packet: pkt_ov093_021DA8A8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);

int BTL_ABILITY_AbsorbCheckMoveType(int a, int b, int c)
{
    if (b == BTL_EVENT_GetVar(4) && b != BTL_EVENT_GetVar(3) && c == BTL_EVENT_GetVar(0x16))
        return BTL_EVENT_OverwriteVar(0x40, 1);
    return 0;
}
