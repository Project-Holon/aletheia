/*
 * function: WIFI_BSUBWAY_GRAPHIC_Draw
 * address: 0x021D839C
 * packet: pkt_ov116_021D839C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Update 0x020419E4 arm
 */
extern void BG_SYS_Update(void *);
void WIFI_BSUBWAY_GRAPHIC_Draw(void *p) { BG_SYS_Update(p); }
