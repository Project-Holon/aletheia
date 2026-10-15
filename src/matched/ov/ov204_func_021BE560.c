/*
 * function: INTRO_CMD_CmdMoveSlot
 * address: 0x021BE560
 * packet: pkt_ov204_021BE560
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   INTRO_G3D_MoveSlot 0x021BF804 thumb ov204
 */
#include "../include/Obj25359.h"
extern int INTRO_G3D_MoveSlot(char *p, unsigned int i, int step, int limit);
int INTRO_CMD_CmdMoveSlot(char *p,int *state,int *q){return INTRO_G3D_MoveSlot(*(char * *)&((struct Obj25359 *)p)->f8,(unsigned char)q[0],q[1],q[2]);}
