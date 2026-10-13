/*
 * function: DELIVERY_BEACON_TryComplete
 * address: 0x02157910
 * packet: pkt_ov010_02157910
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 22 bytes of code followed by 2-byte alignment padding.
 * symbols:
 *   DELIVERY_BEACON_HasAllPieces 0x02157724 thumb ov010
 *   DELIVERY_BEACON_DecodePieces 0x02157818 thumb ov010
 */
typedef unsigned char u8;
extern int DELIVERY_BEACON_HasAllPieces(u8 *);
extern void DELIVERY_BEACON_DecodePieces(u8 *);
int DELIVERY_BEACON_TryComplete(u8 *p) { int r; r = DELIVERY_BEACON_HasAllPieces(p); if (r) DELIVERY_BEACON_DecodePieces(p); return r; }
