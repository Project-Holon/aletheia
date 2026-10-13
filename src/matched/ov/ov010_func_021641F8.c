/*
 * function: FLDMMDL_MOVE_GetDirAddGridZ
 * address: 0x021641F8
 * packet: pkt_ov010_021641F8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * contract: ROM table at 0x02171470 holds {-1,1,0,0}. No caller
 * bounds assumption: unsigned32 address arithmetic preserves the image load.
 * symbols:
 *   d_02171470 0x02171470 data a4
 */

extern const int d_02171470[];
int FLDMMDL_MOVE_GetDirAddGridZ(int a) { return (short)*(const int *)((unsigned)d_02171470+((unsigned)a<<2)); }
