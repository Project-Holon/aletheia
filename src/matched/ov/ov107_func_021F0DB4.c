/*
 * function: func_021F0DB4
 * address: 0x021F0DB4
 * packet: pkt_ov107_021F0DB4
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6EAC 0x021F6EAC data a4
 *   func_020307B0 0x020307B0 arm
 *   func_0203D7FC 0x0203D7FC arm
 */
extern void *d_021F6EAC[];
extern void func_020307B0(void *);extern void func_0203D7FC(void *);
void func_021F0DB4(void) {if(d_021F6EAC[0]) {func_020307B0(d_021F6EAC[0]);d_021F6EAC[0]=0;}if(d_021F6EAC[1]) {func_0203D7FC(d_021F6EAC[1]);d_021F6EAC[1]=0;}}
