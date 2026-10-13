/*
 * function: VS_MULTI_LIST_StartWipeOut
 * address: 0x021F67F0
 * packet: pkt_ov097_021F67F0
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj21991.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
int VS_MULTI_LIST_StartWipeOut(u8 *p, int value) { WIPE_SYS_Start(0,0,0,0,6,1,0x71); ((struct Obj21991 *)p)->f118=value; return 2; }
