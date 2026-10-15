/*
 * function: DUP_FITTING_ExitPoseMode
 * address: 0x021B987C
 * packet: pkt_ov133_021B987C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   DUP_FITTING_SetTextMon 0x021B9C90 thumb ov133
 */
#include "../include/Obj00228.h"
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v); extern void DUP_FITTING_SetTextMon(unsigned char *);
void DUP_FITTING_ExitPoseMode(unsigned char *p) {((struct Obj00228 *)p)->f183C=0;((struct Obj00228 *)p)->fC=1;CLACT_SetActorDrawEnable(((struct Obj00228 *)p)->f1854,0);DUP_FITTING_SetTextMon(p);}
