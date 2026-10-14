/*
 * function: GSYNC_MENU_StateSaveStart
 * address: 0x021D5020
 * packet: pkt_ov123_021D5020
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MENU_UpdateMessageStream 0x021D4E7C thumb ov123
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   GSYNC_MENU_StateSaveFinish 0x021D4FEC thumb ov123
 */
#include "../include/Obj22939.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GSYNC_MENU_UpdateMessageStream(char *);
extern int GAME_DATA_SaveStart(int a0);
extern void GSYNC_MENU_ChangeState(char *,void *,int);
extern void GSYNC_MENU_StateSaveFinish(char *);
void GSYNC_MENU_StateSaveStart(char *p) { if(GSYNC_MENU_UpdateMessageStream(p)) { GAME_DATA_SaveStart((int)(((struct Obj22939 *)p)->f260)); GSYNC_MENU_ChangeState(p,GSYNC_MENU_StateSaveFinish,0x4fa); } }
