/*
 * function: GTSNEGO_MSG_CreateIdleUi
 * address: 0x021D7550
 * packet: pkt_ov120_021D7550
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02041B6C 0x02041B6C arm
 *   GTSNEGO_MSG_CreateIdleActors 0x021D73D8 thumb ov120
 */
#include "../include/Obj00625.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02041B6C(u32);
extern void GTSNEGO_MSG_CreateIdleActors(u8 *);
void GTSNEGO_MSG_CreateIdleUi(u8 *p)
{
    void *t=func_020490F4(144,((struct Obj00625 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t,14,2,0,(u16)(((struct Obj00625 *)p)->f4),0,0,((struct Obj00625 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t,13,0,0,(u16)(((struct Obj00625 *)p)->f4),0,0,((struct Obj00625 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t,16,3,0,(u16)(((struct Obj00625 *)p)->f4),0,0,((struct Obj00625 *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    GTSNEGO_MSG_CreateIdleActors(p);
    func_02041B6C(2); func_02041B6C(0); func_02041B6C(3);
    ((struct Obj00625 *)p)->f110=0;
    ((struct Obj00625 *)p)->f114=1;
}
