/*
 * function: MUSICAL_MCSS_FreeMon
 * address: 0x021F6888
 * packet: pkt_ov112_021F6888
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03760.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
void MUSICAL_MCSS_FreeMon(char *p) {if(((struct Obj03760 *)p)->f4)func_020307B0(((struct Obj03760 *)p)->f4);if(((struct Obj03760 *)p)->f8)func_020307B0(((struct Obj03760 *)p)->f8);if(((struct Obj03760 *)p)->fC)func_020307B0(((struct Obj03760 *)p)->fC);if(((struct Obj03760 *)p)->f10)func_020307B0(((struct Obj03760 *)p)->f10);func_020307B0(p);}
