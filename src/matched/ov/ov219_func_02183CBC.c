/*
 * function: BEACON_DETAIL_WinActivate
 * address: 0x02183CBC
 * packet: pkt_ov219_02183CBC
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 */
#include "../include/Obj14775.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void APP_TASKMENU_WIN_SetActive(struct Obj*,u32);
extern void APP_TASKMENU_WIN_SetDecide(char*,int);
void BEACON_DETAIL_WinActivate(u8 *p,u32 i){if(*(void**)(p+i*4+0xc05c)){if(i==0){APP_TASKMENU_WIN_SetActive(*(struct Obj* *)&((struct Obj14775 *)p)->fC05C,1);return;}if(i==1)APP_TASKMENU_WIN_SetDecide(*(char* *)&((struct Obj14775 *)p)->fC060,1);}}
