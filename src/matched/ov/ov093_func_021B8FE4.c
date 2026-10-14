/*
 * function: BTL_MAIN_IsOwnClientSecondTeam
 * address: 0x021B8FE4
 * packet: pkt_ov093_021B8FE4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_IsSecondTeamClient 0x021B8FC0 thumb ov093
 * Leaf: sole unresolved overlay blocker of ov094 BTLV_EFFECT_CreateSetupFromBattleMain.
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern unsigned char BTL_MAIN_IsSecondTeamClient(unsigned char *p, unsigned int k);
u8 BTL_MAIN_IsOwnClientSecondTeam(u8 *p)
{
    return BTL_MAIN_IsSecondTeamClient(p, p[0x46c]);
}
