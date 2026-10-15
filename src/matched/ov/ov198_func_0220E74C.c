/*
 * function: B_PLIST_DRAW_DeleteActors
 * address: 0x0220E74C
 * packet: pkt_ov198_0220E74C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   B_APP_TOOL_DeleteActors 0x0220AFC4 thumb ov196
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj14559.h"
typedef unsigned char  u8;
struct Bank;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void B_APP_TOOL_DeleteActors(u8 *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
void B_PLIST_DRAW_DeleteActors(char *p)
{
    unsigned i;
    for(i=0;i<41;i++) CLACT_DeleteActor(*(void **)(p+i*4+0x1ebc));
    B_APP_TOOL_DeleteActors(((struct Obj14559 *)p)->f2188);
    for(i=0;i<26;i++) CLACT_ReleaseCharacter((u32)(*(void **)(p+i*4+0x24a4)));
    for(i=0;i<6;i++) CLACT_ReleasePalette((u32)(*(void **)(p+i*4+0x250c)));
    for(i=0;i<6;i++) CLACT_ReleaseCellAnim((u32)(*(void **)(p+i*4+0x2524)));
    CLACT_DeleteUnit(((struct Obj14559 *)p)->f1EB8);
}
