/*
 * function: GTSNEGO_DISP_Teardown
 * address: 0x021D4FD0
 * packet: pkt_ov120_021D4FD0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_Teardown 0x021D761C thumb ov120
 *   GTSNEGO_MSG_DeleteAll 0x021D883C thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_ShowSubPlanes 0x021D4FC0 thumb ov120
 */
#include "../include/Obj13930.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GTSNEGO_MSG_Teardown(u8 *); extern void GTSNEGO_MSG_DeleteAll(char *); extern void GTSNEGO_DISP_SetStateCallback(int,void (*)(int),int); extern void GTSNEGO_DISP_ShowSubPlanes(int);
void GTSNEGO_DISP_Teardown(u8 *p) { GTSNEGO_MSG_Teardown(*(u8 * *)&((struct Obj13930 *)p)->f3C); GTSNEGO_MSG_DeleteAll(*(char * *)&((struct Obj13930 *)p)->f40); GTSNEGO_DISP_SetStateCallback((int)p,GTSNEGO_DISP_ShowSubPlanes,0x5c5); }
