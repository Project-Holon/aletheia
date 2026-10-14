/*
 * function: GSYNC_STATE_StateSaveMainWait
 * address: 0x021D7430
 * packet: pkt_ov123_021D7430
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DISP_UpdateProgressPosition 0x021D66D0 thumb ov123
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_020056EC 0x020056EC thumb
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSendRequest 0x021D73D8 thumb ov123
 */
#include "../include/Obj05364.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GSYNC_DISP_UpdateProgressPosition(u8 *,int);
extern int GAME_DATA_SaveMain(u8 *p);
extern u32 func_020056EC(u32 range);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateSendRequest(char *p);
void GSYNC_STATE_StateSaveMainWait(u8 *p) { if(((struct Obj05364 *)p)->f70<100) ++((struct Obj05364 *)p)->f70; GSYNC_DISP_UpdateProgressPosition(*(u8 * *)&((struct Obj05364 *)p)->f14,((struct Obj05364 *)p)->f70); if(GAME_DATA_SaveMain(((struct Obj05364 *)p)->f2C)==1) { ((struct Obj05364 *)p)->f78=func_020056EC(190); GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateSendRequest,0x2e6); } }
