/*
 * function: BTL_MAIN_IsMultiMode
 * address: 0x021B86C8
 * packet: pkt_ov093_021B86C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: final two zero bytes are alignment padding before the next labelled function.
 */
int BTL_MAIN_IsMultiMode(unsigned char **p) { if ((*p)[0x22]) return 1; return 0; }
