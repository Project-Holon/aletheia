/*
 * function: MB_PARENT_SYS_FreeBuffers
 * address: 0x021F0DB4
 * packet: pkt_ov107_021F0DB4
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gMbParentSys 0x021F6EAC data a4
 *   func_020307B0 0x020307B0 arm
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 */
extern void *gMbParentSys[];
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);extern void GFL_NET_FreeAligned(void *);
void MB_PARENT_SYS_FreeBuffers(void) {if(gMbParentSys[0]) {func_020307B0(gMbParentSys[0]);gMbParentSys[0]=0;}if(gMbParentSys[1]) {GFL_NET_FreeAligned(gMbParentSys[1]);gMbParentSys[1]=0;}}
