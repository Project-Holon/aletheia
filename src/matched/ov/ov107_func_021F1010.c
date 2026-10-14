/*
 * function: MB_COMM_SYS_IsNetSessionNull
 * address:  0x021F1010
 * packet:   pkt_ov107_021F1010
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 */

extern int GFL_NET_IsSessionNull(void);
int MB_COMM_SYS_IsNetSessionNull(void *p) { return GFL_NET_IsSessionNull(); }
