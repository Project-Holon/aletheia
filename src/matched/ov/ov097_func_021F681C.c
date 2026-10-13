/*
 * function: VS_MULTI_LIST_EnterWaitState
 * address: 0x021F681C
 * packet: pkt_ov097_021F681C
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 */
#include "../include/Obj00111.h"
typedef unsigned char u8;
typedef unsigned int u32;
int VS_MULTI_LIST_EnterWaitState(u8 *p, int count, int result) { ((struct Obj00111 *)p)->f11C = count; ((struct Obj00111 *)p)->f114 = result; return 3; }
