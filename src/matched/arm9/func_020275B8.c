/*
 * function: BEACON_STATUS_SetViewTop
 * address:  0x020275B8
 * packet:   pkt_020275B8
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

void BEACON_STATUS_SetViewTop(char *p, int v) { p[0xb0e] = v; }
