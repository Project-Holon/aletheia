/*
 * function: DELIVERY_BEACON_RunStep
 * address: 0x02157928
 * packet: pkt_ov010_02157928
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void DELIVERY_BEACON_RunStep(u8 *p) { (*(void (**)(u8 *))(p + 0x31bc))(p); }
