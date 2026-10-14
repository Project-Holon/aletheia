/*
 * function: GSYNC_STATE_StateExtraSaveMainSecond
 * address: 0x021D76B8
 * packet: pkt_ov123_021D76B8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_PartSaveMain 0x02012E7C thumb
 *   func_0200734C 0x0200734C thumb
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateFreeExtraSaveBuffer 0x021D768C thumb ov123
 */
#include "../include/Obj13987.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern int GAME_DATA_PartSaveMain(char *p, int a1);
struct Sub02007324Ctrl;
extern void func_0200734C(struct Sub02007324Ctrl *ctrl,u32 id);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateFreeExtraSaveBuffer(u8 *);
void GSYNC_STATE_StateExtraSaveMainSecond(char *p) { int v; v=(int)GAME_DATA_GetSaveControl((struct Big *)(((struct Obj13987 *)p)->f2C)); if(GAME_DATA_PartSaveMain((char *)(((struct Obj13987 *)p)->f2C),7)==2) { func_0200734C((struct Sub02007324Ctrl *)v,7); GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateFreeExtraSaveBuffer,0x36a); } }
