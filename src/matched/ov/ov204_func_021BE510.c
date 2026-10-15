/*
 * function: func_021BE510
 * address: 0x021BE510
 * packet: pkt_ov204_021BE510
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_G3D_SetVanishFlag 0x021BF720 thumb ov204
 */
#include "../include/Obj25353.h"
typedef unsigned char  u8;
extern void INTRO_G3D_SetVanishFlag(u8 *p, int flag, u8 index);
int func_021BE510(char *p,int *state,int *q){INTRO_G3D_SetVanishFlag(((struct Obj25353 *)p)->f8,q[1],q[0]);return 1;}
