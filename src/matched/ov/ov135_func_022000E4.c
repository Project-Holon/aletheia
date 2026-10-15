/*
 * function: WORLDTRADE_TITLE_ExitBgPlanes
 * address: 0x022000E4
 * packet: pkt_ov135_022000E4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 */
#include "../include/Obj00287.h"
extern void BG_SYS_FreeLayerBuf(unsigned);
void WORLDTRADE_TITLE_ExitBgPlanes(char *p) {if(((struct Obj00287 *)p)->f12E0==1 && ((struct Obj00287 *)p)->f12E4==0) {((struct Obj00287 *)p)->f12E0=0;BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(4);BG_SYS_FreeLayerBuf(7);}}
