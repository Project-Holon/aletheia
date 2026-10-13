/*
 * function: P_STA_SKILL_GetSlotTouchRect
 * address: 0x021DBA14
 * packet: pkt_ov131_021DBA14
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_SKILL_SlotTilePos 0x021DC2B8 data a1
 */
typedef unsigned char u8;
extern const u8 P_STA_SKILL_SlotTilePos[][2];
void P_STA_SKILL_GetSlotTouchRect(u8 *a,u8 *b) {
    if (*a<5) {
        b[0]=P_STA_SKILL_SlotTilePos[*a][1]*8;
        b[1]=b[0]+32;
        b[2]=P_STA_SKILL_SlotTilePos[*a][0]*8;
        b[3]=b[2]+136;
    } else { b[0]=0;b[1]=0;b[2]=0;b[3]=0; }
}
