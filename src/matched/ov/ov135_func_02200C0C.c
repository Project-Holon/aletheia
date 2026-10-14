/*
 * function: WORLDTRADE_SERVER_Init
 * address: 0x02200C0C
 * packet: pkt_ov135_02200C0C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_SERVER_CreateStrings 0x02200EB0 thumb ov135
 *   WORLDTRADE_SERVER_SetupBgPlanes 0x02200CCC thumb ov135
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   func_02040588 0x02040588 arm
 *   WORLDTRADE_SERVER_LoadBgGraphics 0x02200DD0 thumb ov135
 *   WORLDTRADE_SERVER_CreateWindows 0x02200E48 thumb ov135
 *   WORLDTRADE_SUBLCD_SetSlotActorPositions 0x021FFD44 thumb ov135
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
 */
#include "../include/Obj10593.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WORLDTRADE_SERVER_CreateStrings(u8 *);
extern void WORLDTRADE_SERVER_SetupBgPlanes(void);
extern void WORLDTRADE_TITLE_ScrollBg(u8 *,u32,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void WORLDTRADE_SERVER_LoadBgGraphics(u8 *);
extern void WORLDTRADE_SERVER_CreateWindows(u8 *);
extern void WORLDTRADE_SUBLCD_SetSlotActorPositions(char *p);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void WORLDTRADE_ENTER_RestartNetTimeout(u8 *);
int WORLDTRADE_SERVER_Init(u8 *p) { WORLDTRADE_SERVER_CreateStrings(p); WORLDTRADE_SERVER_SetupBgPlanes(); WORLDTRADE_TITLE_ScrollBg(p,0,0); if(((struct Obj10593 *)p)->f20==11) { func_02040588(4,0); func_02040588(6,0); } WORLDTRADE_SERVER_LoadBgGraphics(p); WORLDTRADE_SERVER_CreateWindows(p); WORLDTRADE_SUBLCD_SetSlotActorPositions((char *)p); WIPE_SYS_Start((void *)3,1,1,0,6,1,72); WORLDTRADE_ENTER_RestartNetTimeout(p); ((struct Obj10593 *)p)->f28=0; ((struct Obj10593 *)p)->f12E4=0; return 1; }
