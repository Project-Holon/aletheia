/*
 * function: GTSNEGO_DISP_ShowListMessage
 * address: 0x021D51D4
 * packet: pkt_ov120_021D51D4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: The caller has no halfword truncation before GTSNEGO_MSG_PrintWindow;
 * widen its copied u16 argument to int. Explicit calls in both branches
 * hoist the shared p+64 load; a ternary places it after the selection.
 * symbols:
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_OpenExitMenu 0x021D5188 thumb ov120
 */
#include "../include/Obj10389.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n); extern void GTSNEGO_DISP_SetStateCallback(int,void (*)(int),int); extern void GTSNEGO_DISP_OpenExitMenu(int);
void GTSNEGO_DISP_ShowListMessage(u8 *p) { if (((struct Obj10389 *)p)->f148==-1) GTSNEGO_MSG_PrintWindow(*(u8 * *)&((struct Obj10389 *)p)->f40,45); else GTSNEGO_MSG_PrintWindow(*(u8 * *)&((struct Obj10389 *)p)->f40,31); GTSNEGO_DISP_SetStateCallback((int)p,GTSNEGO_DISP_OpenExitMenu,0x646); }
