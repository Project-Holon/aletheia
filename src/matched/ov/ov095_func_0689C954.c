/*
 * function: BTL_ID_IsAbilitySkillSwapBlocked
 * address: 0x0689C954
 * packet: pkt_ov095_0689C954
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_ID_IsMultitypeAbility 0x0689C974 thumb ov095
 *   BTL_ID_IsInList 0x0689C888 thumb ov095
 *   gSkillSwapBlockedAbilities 0x0689E2A4 data a2
 */

extern int BTL_ID_IsMultitypeAbility(int a);
extern int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
extern unsigned short gSkillSwapBlockedAbilities[];
int BTL_ID_IsAbilitySkillSwapBlocked(unsigned a)
{
    if (BTL_ID_IsMultitypeAbility(a)) return 1;
    return BTL_ID_IsInList(a, gSkillSwapBlockedAbilities, 3);
}
