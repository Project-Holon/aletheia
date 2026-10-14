/*
 * function: GSYNC_DISP_Exit
 * address: 0x021D5E8C
 * packet: pkt_ov123_021D5E8C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DISP_DeleteMainActor 0x021D63E4 thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02040588 0x02040588 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 */
#include "../include/Obj04499.h"
typedef unsigned char u8;
typedef enum { C0 = 0 } Counter;
extern unsigned char ov_id[];
extern void GSYNC_DISP_DeleteMainActor(u8 *);
extern unsigned int func_020307B0(void *p);
typedef unsigned int   u32;
struct Bank;
struct Node;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203F9B4(void);
extern void func_02034A5C(int);
void GSYNC_DISP_Exit(u8 *p)
{
    Counter i;
    GSYNC_DISP_DeleteMainActor(p);
    func_020307B0(((struct Obj04499 *)p)->f1C);
    CLACT_DeleteActor(((struct Obj04499 *)p)->fB4);
    CLACT_DeleteActor(((struct Obj04499 *)p)->fB8);
    i=0;
    do { if(*(void **)(p+i*4+0x20)) CLACT_ReleasePalette((u32)(*(void **)(p+i*4+0x20))); i++; } while(i<6);
    for(;i<13;i++) if(*(void **)(p+i*4+0x20)) CLACT_ReleaseCharacter((u32)(*(void **)(p+i*4+0x20)));
    for(;i<20;i++) if(*(void **)(p+i*4+0x20)) CLACT_ReleaseCellAnim((u32)(*(void **)(p+i*4+0x20)));
    if(((struct Obj04499 *)p)->f14) func_02030EAC(((struct Obj04499 *)p)->f14);
    func_02030EAC(((struct Obj04499 *)p)->f10);
    CLACT_DeleteUnit(((struct Obj04499 *)p)->fC);
    CLACT_ExitSystem();
    func_02040DA8(1,1,0); func_02040DA8(6,1,0);
    func_020403F4(5); func_020403F4(4);
    func_02040588(5,0); func_0203F9B4(); func_020307B0(p);
    func_02034A5C((int)ov_id);
}
