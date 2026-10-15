/*
 * function: P_STA_SKILL_GetNatureStatColor
 * address: 0x021DB6D0
 * packet: pkt_ov131_021DB6D0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetNatureModifier 0x02019B44 thumb
 */
typedef signed char s8;
typedef unsigned int u32;
extern s8 POKE_TOOL_GetNatureModifier(u32 a, u32 n);
int P_STA_SKILL_GetNatureStatColor(u32 a, u32 b, unsigned char c, u32 d) {
 switch (POKE_TOOL_GetNatureModifier(c, d)) {
 case 1: return 0x3d20;
 case -1: return 0x3d40;
 case 0:
 default: return 0x3c40;
 }
}
