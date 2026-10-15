/*
 * function: GTSNEGO_DISP_SelectParty
 * address: 0x021D593C
 * packet: pkt_ov120_021D593C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_SetCursorAnimSeq 0x021D6A9C thumb ov120
 *   GTSNEGO_DISP_GetTouchbar 0x021D6988 thumb ov120
 *   TOUCHBAR_SetAllButtonsVisible 0x021B64D0 thumb ov067
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj13933.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GTSNEGO_MSG_SetCursorAnimSeq(u8 *p, u32 n); extern u8 *GTSNEGO_DISP_GetTouchbar(void *); extern void TOUCHBAR_SetAllButtonsVisible(u8 *,u32); extern void GFL_USE_PlaySeDefaultVolume(int);
int GTSNEGO_DISP_SelectParty(u8 *p,int n) { if (GTSNEGO_MSG_SetCursorAnimSeq(((struct Obj13933 *)p)->f3C,n)) { TOUCHBAR_SetAllButtonsVisible(GTSNEGO_DISP_GetTouchbar(((struct Obj13933 *)p)->f3C),0); GFL_USE_PlaySeDefaultVolume(1356); return n; } return 9; }
