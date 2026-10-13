/*
 * function: DELIVERY_BEACON_HasAllPieces
 * address: 0x02157724
 * packet: pkt_ov010_02157724
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 58-byte body followed by 2-byte alignment padding.
 * lever: enum bound preserves the entry guard; declare index before bound.
 */
typedef unsigned char u8;
typedef enum { INDEX_ZERO = 0 } Index;
int DELIVERY_BEACON_HasAllPieces(u8 *p) { int i; Index n; n = p[0xd9]; if (n == 0) return 0; for (i = 0; i < n; i++) { if (n != p[i * 100 + 0xd9]) return 0; } return 1; }
