/*
 * function: BTL_ID_IsAbilityTraceBlocked
 * address: 0x0689C944
 * packet: pkt_ov095_0689C944
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ID_IsAbilityRolePlayBlocked 0x0689C91C thumb ov095
 */

extern int BTL_ID_IsAbilityRolePlayBlocked(unsigned a);
int BTL_ID_IsAbilityTraceBlocked(unsigned a)
{
    if (a == 25) return 0;
    return BTL_ID_IsAbilityRolePlayBlocked(a);
}
