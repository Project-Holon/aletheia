/*
 * function: MB_COMM_SYS_WmEndCallback
 * address: 0x021EFC10
 * packet: pkt_ov107_021EFC10
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gMbParentUi 0x021F6EA0 data ov107 a4
 */
extern int gMbParentUi[];
int MB_COMM_SYS_WmEndCallback(void) { gMbParentUi[2]=1; return 1; }
