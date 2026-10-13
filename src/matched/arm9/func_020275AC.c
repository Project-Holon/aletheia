/*
 * function: BEACON_STATUS_GetViewTop
 * address:  0x020275AC
 * packet:   pkt_020275AC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf. Filed as the relocation witness for ov032 (wave D2).
 */
typedef unsigned char u8;
typedef unsigned int u32;

u8 BEACON_STATUS_GetViewTop(u8 *p) { return p[0xb0e]; }
