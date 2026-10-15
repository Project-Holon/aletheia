/*
 * function: Wf2dmapFriend_DeleteActors
 * address: 0x021C68C4
 * packet: pkt_ov128_021C68C4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 */
#include "../include/Obj00725.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCellAnim(u32);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_DeleteRenderer(u32);
extern void CLACT_ExitSystem(void);
void Wf2dmapFriend_DeleteActors(char *p)
{
    unsigned i;
    for(i=0;i<2;i++) CLACT_ReleaseCharacter(*(u32 *)(p+i*4+0x144));
    for(i=0;i<2;i++) CLACT_ReleasePalette(*(u32 *)(p+i*4+0x14c));
    for(i=0;i<2;i++) CLACT_ReleaseCellAnim(*(u32 *)(p+i*4+0x154));
    CLACT_DeleteUnit((struct Bank *)(((struct Obj00725 *)p)->f13C));
    CLACT_DeleteRenderer(((struct Obj00725 *)p)->f140);
    CLACT_DeleteUnit((struct Bank *)(((struct Obj00725 *)p)->f138));
    CLACT_ExitSystem();
}
