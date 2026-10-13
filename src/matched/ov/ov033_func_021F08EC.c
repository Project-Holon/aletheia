/*
 * function: DOWSING_DeleteParts
 * address: 0x021F08EC
 * packet: pkt_ov033_021F08EC
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
#include "../include/Obj09803.h"
#include "../include/Obj20476.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
void DOWSING_DeleteParts(char *p) { unsigned char i; char *q; for(i=0;i<4;i++) { q=p+i*12; CLACT_DeleteActor((struct Obj *)(((struct Obj09803 *)q)->f38)); if(i!=1) { CLACT_ReleaseCellAnim(((struct Obj09803 *)q)->f34); CLACT_ReleaseCharacter(((struct Obj09803 *)q)->f30); } } CLACT_ReleasePalette(((struct Obj20476 *)p)->f2C); }
