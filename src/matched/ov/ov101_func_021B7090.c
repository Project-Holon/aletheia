/*
 * function: IRC_COMPATIBLE_FindHighestSetBit
 * address: 0x021B7090
 * packet: pkt_ov101_021B7090
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
unsigned IRC_COMPATIBLE_FindHighestSetBit(unsigned bits, unsigned n) { unsigned i = n - 1; while (i) { if ((bits >> i) & 1) break; i--; } return i; }
