/*
 * function: MB_COMM_SYS_IsSyncDone
 * address:  0x021F1040
 * packet:   pkt_ov107_021F1040
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int MB_COMM_SYS_IsSyncDone(int *p) { return p[1] == 5; }
