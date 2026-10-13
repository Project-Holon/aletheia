/*
 * unit: yes
 * function: BTLV_SCD_OnSlideInDone, BTLV_SCD_OnSlideOutStart
 * address: 0x06899D2C
 * packet: pkt_ov095_06899D2C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: veneer follower unit; function_starts seeds 06899D2C, 06899D30.
 * symbols:
 *   BTLV_SCD_Nop 0x06899D38 thumb ov095
 */
extern void BTLV_SCD_Nop(void);
void BTLV_SCD_OnSlideInDone(void) {}
void BTLV_SCD_OnSlideOutStart(void) { BTLV_SCD_Nop(); }
