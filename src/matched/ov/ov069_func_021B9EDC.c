/*
 * function: BSUBWAY_RECORD_LIST_StateFadeOutStart
 * address: 0x021B9EDC
 * packet: pkt_ov069_021B9EDC
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding before next labelled function.
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj20657.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
int BSUBWAY_RECORD_LIST_StateFadeOutStart(u8 *p) { WIPE_SYS_Start(0,0,0,0,16,1,128); ((struct Obj20657 *)p)->f158=4; return 1; }
