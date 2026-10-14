/*
 * function: GSYNC_STATE_StateFreeExtraSaveBuffer
 * address: 0x021D768C
 * packet: pkt_ov123_021D768C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateCleanupDownload 0x021D751C thumb ov123
 */
#include "../include/Obj08111.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateCleanupDownload(int a);
void GSYNC_STATE_StateFreeExtraSaveBuffer(u8 *p) { p[166]=0; func_020307B0(((struct Obj08111 *)p)->f3C); p[174]=0; ((struct Obj08111 *)p)->f3C=0; GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateCleanupDownload,0x360); }
