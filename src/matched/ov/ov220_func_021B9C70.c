/*
 * function: func_021B9C70
 * address: 0x021B9C70
 * packet: pkt_ov220_021B9C70
 * region: ov220
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
#include "../include/Obj01297.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
void func_021B9C70(unsigned char *p)
{
    unsigned char i;
    if(p[0x84]) {
        for(i=0;i<p[0x84];i++) CLACT_DeleteActor(*(struct Obj **)(p+0x94+4*i));
        CLACT_ReleaseCellAnim(((struct Obj01297 *)p)->f90);
        CLACT_ReleaseCharacter(((struct Obj01297 *)p)->f88);
        CLACT_ReleasePalette(((struct Obj01297 *)p)->f8C);
    }
}
