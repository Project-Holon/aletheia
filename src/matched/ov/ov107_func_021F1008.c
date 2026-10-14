/*
 * function: MB_COMM_SYS_GetNetRunState
 * address:  0x021F1008
 * packet:   pkt_ov107_021F1008
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 */

extern int GFL_NET_GetRunState(void);
int MB_COMM_SYS_GetNetRunState(void *p) { return GFL_NET_GetRunState(); }
