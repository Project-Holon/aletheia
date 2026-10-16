/*
 * function: BEACON_DETAIL_WinUpdate
 * address: 0x02183CEC
 * packet: pkt_ov219_02183CEC
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 */
#include "../include/Obj08450.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void APP_TASKMENU_WIN_Update(u8*);
void BEACON_DETAIL_WinUpdate(u8 *p){if(*(u8* *)&((struct Obj08450 *)p)->fC05C)APP_TASKMENU_WIN_Update(*(u8* *)&((struct Obj08450 *)p)->fC05C);if(*(u8* *)&((struct Obj08450 *)p)->fC060)APP_TASKMENU_WIN_Update(*(u8* *)&((struct Obj08450 *)p)->fC060);}
