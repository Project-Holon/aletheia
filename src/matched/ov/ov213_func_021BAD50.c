/*
 * function: COMM_BTL_DEMO_GRAPHIC_TickDisplay
 * address: 0x021BAD50
 * packet: pkt_ov213_021BAD50
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Update 0x020419E4 arm
 */
extern void BG_SYS_Update(void);
void COMM_BTL_DEMO_GRAPHIC_TickDisplay(void *a0){BG_SYS_Update();}
