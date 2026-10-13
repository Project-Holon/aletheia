/*
 * function: func_021BA050
 * address: 0x021BA050
 * packet: pkt_ov223_021BA050
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: named row and entry pointers preserve the load scheduling.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
#include "../include/Obj10980.h"
typedef unsigned char u8;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
void func_021BA050(char *p)
{
    u8 i,j;
    char *row,*entry;
    for(i=0;i<3;i++) {
        row=p+i*148;
        for(j=0;j<2;j++) {
            CLACT_DeleteActor(*(void **)(row+108+j*4));
            entry=row+j*12;
            CLACT_ReleaseCellAnim(((struct Obj10980 *)entry)->f5C);
            CLACT_ReleaseCharacter(((struct Obj10980 *)entry)->f54);
            if(j!=1) CLACT_ReleasePalette(((struct Obj10980 *)entry)->f58);
        }
    }
}
