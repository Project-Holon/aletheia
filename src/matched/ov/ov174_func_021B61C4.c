/*
 * function: func_021B61C4
 * address: 0x021B61C4
 * packet: pkt_ov174_021B61C4
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021B622A..0x021B622C is two zero alignment bytes.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021B6824 0x021B6824 thumb ov174
 *   func_021B6D00 0x021B6D00 thumb ov174
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021B6508 0x021B6508 thumb ov174
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00681.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Bank;
struct Node;
struct Obj;
extern void func_02030EAC(struct Node *n);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020307B0(void *p);
extern void func_021B6824(u8 *);
extern void func_021B6508(u8 *);
extern void func_021B6D00(unsigned char *unused, char *p);
void func_021B61C4(u8 *p)
{
    u8 i;
    func_02030EAC(((struct Obj00681 *)p)->f4);
    func_021B6824(p);
    for(i=0;i<((struct Obj00681 *)p)->f8;i++) if(*(void **)(p+28+i*4)) func_021B6D00(p,*(void **)(p+28+i*4));
    CLACT_DeleteActor(((struct Obj00681 *)p)->f54);
    CLACT_ReleasePalette((u32)(((struct Obj00681 *)p)->f44));
    CLACT_ReleaseCharacter((u32)(((struct Obj00681 *)p)->f48));
    CLACT_ReleaseCellAnim((u32)(((struct Obj00681 *)p)->f4C));
    CLACT_DeleteUnit(((struct Obj00681 *)p)->f50);
    ARC_TOOL_DeleteHandle(((struct Obj00681 *)p)->f18);
    func_021B6508(p);
    func_020307B0(((struct Obj00681 *)p)->f38);
}
