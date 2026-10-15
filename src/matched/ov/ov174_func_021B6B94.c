/*
 * function: LOCAL_TVT_SYS_TickTimer
 * address: 0x021B6B94
 * packet: pkt_ov174_021B6B94
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj08268.h"
int LOCAL_TVT_SYS_TickTimer(char *p) {unsigned char threshold=*(unsigned short *)(*(char * *)&((struct Obj08268 *)p)->f40+((struct Obj08268 *)p)->f89*4+2);++*(unsigned short *)&((struct Obj08268 *)p)->f8A;if(*(unsigned short *)&((struct Obj08268 *)p)->f8A>threshold) return 1;return 0;}
