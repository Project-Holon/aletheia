/*
 * function: GTSNEGO_DISP_EndList
 * address: 0x021D5208
 * packet: pkt_ov120_021D5208
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   GTSNEGO_MSG_TeardownTileRows 0x021D6D94 thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_ShowPartySelect 0x021D588C thumb ov120
 */
#include "../include/Obj22831.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02040588(unsigned char which, unsigned char enable); extern void GTSNEGO_MSG_TeardownTileRows(u8 *); extern void GTSNEGO_DISP_SetStateCallback(int,void (*)(int),int); extern void GTSNEGO_DISP_ShowPartySelect(int);
void GTSNEGO_DISP_EndList(u8 *p) { func_02040588(4,0); GTSNEGO_MSG_TeardownTileRows(*(u8 * *)&((struct Obj22831 *)p)->f3C); GTSNEGO_DISP_SetStateCallback((int)p,GTSNEGO_DISP_ShowPartySelect,0x64e); }
