/*
 * function: TOWNMAP_MapAddScroll
 * address: 0x021BA6A8
 * packet: pkt_ov072_021BA6A8
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TOWNMAP_MapSetScroll 0x021BA638 thumb ov072
 */
#include "../include/Obj02126.h"
extern void TOWNMAP_MapSetScroll(void *p, int *in);
void TOWNMAP_MapAddScroll(char *p, const int *in) { ((struct Obj02126 *)p)->f10 = in[0] + ((struct Obj02126 *)p)->f10; ((struct Obj02126 *)p)->f14 = ((struct Obj02126 *)p)->f14 + in[1]; TOWNMAP_MapSetScroll(p,(int *)(p+16)); }
