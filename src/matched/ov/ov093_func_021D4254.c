/*
 * function: BTL_NET_Exit
 * address: 0x021D4254
 * packet: pkt_ov093_021D4254
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   BTL_NET_FreeRecvBuffers 0x021D4A6C thumb ov093
 *   func_020307B0 0x020307B0 arm
 */
extern void *gBtlNet;
extern void BTL_NET_FreeRecvBuffers(void);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void BTL_NET_Exit(void) { if(gBtlNet) { BTL_NET_FreeRecvBuffers(); func_020307B0(gBtlNet); } }
