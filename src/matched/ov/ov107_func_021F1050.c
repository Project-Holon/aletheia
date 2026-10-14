/*
 * function: MB_COMM_SYS_IsLoginDone
 * address:  0x021F1050
 * packet:   pkt_ov107_021F1050
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int MB_COMM_SYS_IsLoginDone(int *p) { return p[1] >= 6; }
