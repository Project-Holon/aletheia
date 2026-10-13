/*
 * function: POKELIST_StartSwapAnimation
 * address: 0x021B9968
 * packet: pkt_ov091_021B9968
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00009.h"
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
void POKELIST_StartSwapAnimation(unsigned char *p) { p[12]=5; p[14]=3; p[260]=0; GFL_USE_PlaySeDefaultVolume(0x641); CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00009 *)p)->f1D8,0); CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00009 *)p)->f1DC,0); }
