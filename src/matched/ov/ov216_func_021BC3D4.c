/*
 * function: BEACON_DETAIL_GRA_DeleteTouchBar
 * address: 0x021BC3D4
 * packet: pkt_ov216_021BC3D4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 */
extern void TOUCHBAR_Delete(unsigned char *);
void BEACON_DETAIL_GRA_DeleteTouchBar(unsigned char *p){TOUCHBAR_Delete(p);}
