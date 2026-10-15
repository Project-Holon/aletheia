/*
 * function: DEMO3D_CheckSkip
 * address: 0x021BDC88
 * packet: pkt_ov203_021BDC88
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   KEY_GetTrg 0x020362DC arm
 */
#include "../include/Obj14585.h"
#include "../include/Obj25305.h"
#include "../include/Obj25306.h"
extern unsigned WIPE_SYS_EndCheck(void);
extern unsigned KEY_GetTrg(void);
int DEMO3D_CheckSkip(char *p){if(((struct Obj25305 *)(*(char * *)&((struct Obj14585 *)p)->f4))->f14!=0||!WIPE_SYS_EndCheck())return 0;if(((struct Obj25306 *)(*(char * *)&((struct Obj14585 *)p)->f1C))->f14!=0){if(KEY_GetTrg()&0xcf3)return 1;}return 0;}
