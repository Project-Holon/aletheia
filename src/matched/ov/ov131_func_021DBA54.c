/*
 * function: P_STA_SKILL_GetSlotPos
 * address: 0x021DBA54
 * packet: pkt_ov131_021DBA54
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_SKILL_SlotTilePos 0x021DC2B8 data
 *   d_021DC2B9 0x021DC2B9 data
 */
extern unsigned char P_STA_SKILL_SlotTilePos[];
extern unsigned char d_021DC2B9[];
void P_STA_SKILL_GetSlotPos(unsigned char *p, unsigned short *o) {
 o[0] = P_STA_SKILL_SlotTilePos[*p * 2] << 3;
 o[1] = d_021DC2B9[*p * 2] << 3;
}
