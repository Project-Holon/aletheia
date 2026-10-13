/*
 * function: func_02205100
 * address: 0x02205100
 * packet: pkt_ov195_02205100
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
#include "../include/Obj04593.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
void func_02205100(void *unused,char *p) {u8 i;if(((struct Obj04593 *)p)->f60){for(i=0;i<6;i++)CLACT_DeleteActor((struct Obj *)(*(u32 *)(p+0x48+i*4)));CLACT_ReleaseCellAnim(((struct Obj04593 *)p)->f44);CLACT_ReleaseCharacter(((struct Obj04593 *)p)->f3C);CLACT_ReleasePalette(((struct Obj04593 *)p)->f40);((struct Obj04593 *)p)->f60=0;}}
