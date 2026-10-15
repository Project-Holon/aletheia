/*
 * function: INTRO_CMD_CmdUpdateAnimFrame
 * address: 0x021BE970
 * packet: pkt_ov204_021BE970
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_G3D_UpdateAnimFrame 0x021BFBA0 thumb ov204
 */
#include "../include/Obj25376.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int INTRO_G3D_UpdateAnimFrame(int *p);
int INTRO_CMD_CmdUpdateAnimFrame(u8*p){if(INTRO_G3D_UpdateAnimFrame((int *)(*(char* *)&((struct Obj25376 *)p)->fC)))return 1;return 0;}
