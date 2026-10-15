/*
 * function: HALL_OF_FAME_ExitGraphicsSystem
 * address: 0x021B621C
 * packet: pkt_ov180_021B621C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 */
extern void BG_SYS_Delete(void);
void HALL_OF_FAME_ExitGraphicsSystem(void) { BG_SYS_Delete(); }
