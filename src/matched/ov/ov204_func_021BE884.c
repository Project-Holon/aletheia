/*
 * function: func_021BE884
 * address: 0x021BE884
 * packet: pkt_ov204_021BE884
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_G3D_UpdateIntro 0x021BFA40 thumb ov204
 */
#include "../include/Obj25374.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int INTRO_G3D_UpdateIntro(char*);
int func_021BE884(u8*p){if(INTRO_G3D_UpdateIntro(*(char* *)&((struct Obj25374 *)p)->fC))return 1;return 0;}
