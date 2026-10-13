/*
 * function: func_021F5E38
 * address: 0x021F5E38
 * packet: pkt_ov215_021F5E38
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
#include "../include/Obj10938.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
void func_021F5E38(void *unused, char *p)
{
    u8 i;
    for (i = 0; i < 6; i++) CLACT_DeleteActor(*(void **)(p + i * 4 + 0x38));
    CLACT_ReleaseCellAnim(((struct Obj10938 *)p)->f34);
    CLACT_ReleaseCharacter(((struct Obj10938 *)p)->f2C);
    CLACT_ReleasePalette(((struct Obj10938 *)p)->f30);
}
