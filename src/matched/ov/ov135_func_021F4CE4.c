/*
 * function: func_021F4CE4
 * address: 0x021F4CE4
 * packet: pkt_ov135_021F4CE4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 */
#include "../include/Obj00045.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct TaskMenu;
struct TaskMenuState;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
void func_021F4CE4(char *p) { if(((struct Obj00045 *)p)->fE08) { APP_TASKMENU_CloseMenu(((struct Obj00045 *)p)->fE08); ((struct Obj00045 *)p)->fE08=0; } if(((struct Obj00045 *)p)->fE04) { APP_TASKMENU_RES_Delete(((struct Obj00045 *)p)->fE04); ((struct Obj00045 *)p)->fE04=0; } }
