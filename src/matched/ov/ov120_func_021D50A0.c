/*
 * function: GTSNEGO_DISP_CreateExitTooltip
 * address: 0x021D50A0
 * packet: pkt_ov120_021D50A0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_CreateTooltip 0x021D7ECC thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_HandleListInput 0x021D5334 thumb ov120
 */
#include "../include/Obj13932.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GTSNEGO_MSG_CreateTooltip(char *,u16); extern void GTSNEGO_DISP_SetStateCallback(int,void (*)(int),int); extern void GTSNEGO_DISP_HandleListInput(int);
void GTSNEGO_DISP_CreateExitTooltip(u8 *p) { ((struct Obj13932 *)p)->f34=GTSNEGO_MSG_CreateTooltip(*(char * *)&((struct Obj13932 *)p)->f40,44); GTSNEGO_DISP_SetStateCallback((int)p,GTSNEGO_DISP_HandleListInput,0x5ff); }
