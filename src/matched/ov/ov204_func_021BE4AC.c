/*
 * function: func_021BE4AC
 * address: 0x021BE4AC
 * packet: pkt_ov204_021BE4AC
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_MSG_DrawWindowBorder 0x021BF2D4 thumb ov204
 */
#include "../include/Obj25352.h"
typedef unsigned char  u8;
extern void INTRO_MSG_DrawWindowBorder(u8 *p);
int func_021BE4AC(char *p,int *state,int *q){INTRO_MSG_DrawWindowBorder((u8 *)(*(char * *)&((struct Obj25352 *)p)->f18));return 1;}
