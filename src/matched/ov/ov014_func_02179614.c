/*
 * function: WIH_GetBeaconSendCount
 * address: 0x02179614
 * packet: pkt_ov014_02179614
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 */
typedef unsigned char u8;
extern u8 *gWihWork;
unsigned short WIH_GetBeaconSendCount(void) { return *(unsigned short *)(gWihWork + 0x1EBA); }
