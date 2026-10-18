/*
 * function: GTSNEGO_DISP_OnMenuCallback
 * address: 0x021D4C98
 * packet: pkt_ov120_021D4C98
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   UI_SetInputMode 0x020355D8 arm
 */
#include "../include/Obj10388.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GTSNEGO_DISP_SetCursorState(u8 *,void *,u32); extern void UI_SetInputMode(int);
void GTSNEGO_DISP_OnMenuCallback(void *p,int n,u8 *s) { if (n==0 && ((struct Obj10388 *)s)->f4) { GTSNEGO_DISP_SetCursorState(*(u8 * *)&((struct Obj10388 *)s)->f3C,((struct Obj10388 *)s)->f34,9); UI_SetInputMode(1); if ((*(int (**)(void *,void *))(s+4))(p,s)==0) return; } }
