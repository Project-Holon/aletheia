/*
 * function: BTL_ID_IsAbilityRolePlayBlocked, BTL_ID_IsAbilityEntrainmentBlocked
 * address: 0x0689C91C
 * packet: pkt_ov095_0689C91C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   BTL_ID_IsMultitypeAbility 0x0689C974 thumb ov095
 *   BTL_ID_IsInList 0x0689C888 thumb ov095
 *   BTL_ID_IsAbilityTraceBlocked 0x0689C944 thumb ov095
 *   gRolePlayBlockedAbilities 0x0689E2E6 data a2
 */

extern int BTL_ID_IsMultitypeAbility(int a);
extern int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
extern int BTL_ID_IsAbilityTraceBlocked(unsigned a);
extern unsigned short gRolePlayBlockedAbilities[];
int BTL_ID_IsAbilityRolePlayBlocked(unsigned a)
{
    if (BTL_ID_IsMultitypeAbility(a)) return 1;
    return BTL_ID_IsInList(a, gRolePlayBlockedAbilities, 8);
}
int BTL_ID_IsAbilityEntrainmentBlocked(unsigned a) { return BTL_ID_IsAbilityTraceBlocked(a); }
