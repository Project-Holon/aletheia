/*
 * function: PMSIV_MENU_DeleteItems
 * address: 0x021BD0D4
 * packet: pkt_ov110_021BD0D4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj13787.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
void PMSIV_MENU_DeleteItems(u8 *p)
{
    int i;
    for(i=0;i<8;i++) CLACT_DeleteActor(*(void **)(p+i*4+0x70));
    CLACT_ReleaseCharacter(((struct Obj13787 *)p)->f14);
    CLACT_ReleaseCellAnim(((struct Obj13787 *)p)->f18);
}
