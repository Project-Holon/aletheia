/*
 * function: GTSNEGO_MSG_SetIdleAnim
 * address: 0x021D74B0
 * packet: pkt_ov120_021D74B0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGtsnegoIdleAnimTable 0x021D8AB0 data a4
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj03259.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Table { u32 a[16]; } Table;
extern const Table gGtsnegoIdleAnimTable;
extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern void func_02041B6C(u32);
void GTSNEGO_MSG_SetIdleAnim(u8 *p,int n)
{
    Table a=gGtsnegoIdleAnimTable;
    void *t=func_020490F4(144,((struct Obj03259 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t,15,0,0,(u16)(((struct Obj03259 *)p)->f4),0,0,((struct Obj03259 *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    CLACT_SetActorAutoAnim(((struct Obj03259 *)p)->f130,0);
    CLACT_SetActorAnimSeq(((struct Obj03259 *)p)->f130,a.a[n]+11);
    CLACT_SetActorAnimIndex((int)(((struct Obj03259 *)p)->f130),4);
    CLACT_SetActorAnimSeq(((struct Obj03259 *)p)->f12C,28);
    func_02041B6C(0);
    ((struct Obj03259 *)p)->f110=0;
    ((struct Obj03259 *)p)->f114=0;
}
