/*
 * function: FLDMMDL_MOVE_GetDirAddGridX
 * address: 0x021641E8
 * packet: pkt_ov010_021641E8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * contract: ROM table at 0x02171480 holds {0,0,-1,1}. No caller
 * bounds assumption: unsigned32 address arithmetic preserves the image load.
 * symbols:
 *   d_02171480 0x02171480 data a4
 */

extern const int d_02171480[];
int FLDMMDL_MOVE_GetDirAddGridX(int a) { return (short)*(const int *)((unsigned)d_02171480+((unsigned)a<<2)); }
