/*
 * function: CTVT_CALL_ReleaseGraphics
 * address: 0x021BDB5C
 * packet: pkt_ov172_021BDB5C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021BDBC2.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj14310.h"
typedef unsigned int u32;
typedef unsigned char u8;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void ARC_TOOL_DeleteHandle(u32);
void CTVT_CALL_ReleaseGraphics(u8 *p)
{
    u8 i;
    CLACT_DeleteActor((struct Obj *)(((struct Obj14310 *)p)->f1B0));
    for (i = 0; i < 4; i++) CLACT_ReleasePalette(*(u32 *)(p + i * 4 + 0x180));
    for (i = 4; i < 8; i++) CLACT_ReleaseCharacter(*(u32 *)(p + i * 4 + 0x180));
    for (i = 8; i < 11; i++) CLACT_ReleaseCellAnim(*(u32 *)(p + i * 4 + 0x180));
    ARC_TOOL_DeleteHandle(((struct Obj14310 *)p)->f17C);
}
