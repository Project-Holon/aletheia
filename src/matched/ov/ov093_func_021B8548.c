/*
 * function: BTL_MAIN_MarkClientsDisconnected
 * address: 0x021B8548
 * packet: pkt_ov093_021B8548
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CLIENT_MarkCommandIssued 0x021CD914 thumb ov093
 */
typedef unsigned char  u8;
extern void BTL_CLIENT_MarkCommandIssued(u8 *p);
void BTL_MAIN_MarkClientsDisconnected(unsigned char *p) { unsigned int i; for(i=0;i<4;i++) { void *q; q=*(void **)(p+0x10+i*4); if (q) BTL_CLIENT_MarkCommandIssued(q); } }
