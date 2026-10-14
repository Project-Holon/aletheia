/*
 * function: GSYNC_MENU_StateSaveFinish
 * address: 0x021D4FEC
 * packet: pkt_ov123_021D4FEC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   GSYNC_MENU_DeleteMessageWindow 0x021D4E64 thumb ov123
 *   GSYNC_MENU_SetPaletteFade 0x021D4D40 thumb ov123
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   GSYNC_MENU_StateStartFadeOut 0x021D4440 thumb ov123
 */
#include "../include/Obj00273.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GAME_DATA_SaveMain(u8 *p);
extern void GSYNC_MENU_DeleteMessageWindow(u8 *p);
extern void GSYNC_MENU_SetPaletteFade(char *,int);
extern void GSYNC_MENU_ChangeState(char *,void *,int);
extern void GSYNC_MENU_StateStartFadeOut(void *);
void GSYNC_MENU_StateSaveFinish(char *p) { if(GAME_DATA_SaveMain(((struct Obj00273 *)p)->f260)==2) { GSYNC_MENU_DeleteMessageWindow((u8 *)p); GSYNC_MENU_SetPaletteFade(p,0); GSYNC_MENU_ChangeState(p,GSYNC_MENU_StateStartFadeOut,0x4ea); } }
