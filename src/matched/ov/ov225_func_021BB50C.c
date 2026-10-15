/*
 * function: MANUAL_COMMON_DeleteDialogWindows
 * address: 0x021BB50C
 * packet: pkt_ov225_021BB50C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 */
#include "../include/Obj14809.h"
#include "../include/Obj26253.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct PrintSys;
struct TaskMenuState;
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void APP_TASKMENU_WIN_Delete(u8 *);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void BG_SYS_SetFlagField06(u32);
void MANUAL_COMMON_DeleteDialogWindows(char *p) { u8 i; PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26253 *)(*(char * *)&((struct Obj14809 *)p)->f4))->f14); for(i=0;i<2;i++) APP_TASKMENU_WIN_Delete(*(u8 **)(p+i*4+12)); APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct Obj14809 *)p)->f8); BG_SYS_SetFlagField06(5); }
