/*
 * function: INTRO_CMD_CmdClearSlotAnimFinished
 * address: 0x021BE54C
 * packet: pkt_ov204_021BE54C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   INTRO_G3D_ClearSlotAnimFinished 0x021BF788 thumb ov204
 */
#include "../include/Obj25357.h"
typedef unsigned char  u8;
extern void INTRO_G3D_ClearSlotAnimFinished(u8 *p, u8 index);
int INTRO_CMD_CmdClearSlotAnimFinished(char *p,int *state,unsigned *q){INTRO_G3D_ClearSlotAnimFinished((u8 *)(*(char * *)&((struct Obj25357 *)p)->f8),q[0]);return 1;}
