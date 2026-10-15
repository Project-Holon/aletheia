/*
 * function: ZUKAN_TOROKU_GRAPHIC_CreateBg
 * address: 0x0220B260
 * packet: pkt_ov207_0220B260
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj00162.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020409B4(u32 index);
void ZUKAN_TOROKU_GRAPHIC_CreateBg(unsigned *p)
{
    void *r;
    p[11]=1;
    BG_SYS_ClearSlot(3);
    BG_SYS_SetVisibleLayer(1,3);
    BG_SYS_SetVisibleLayer(3,0);
    r=func_020490F4(159,((struct Obj00162 *)p)->f0);
    func_02049B68(r,7,0,0,32,((struct Obj00162 *)p)->f0);
    p[12]=func_02049740(r,17,1,2048,0,((struct Obj00162 *)p)->f0);
    func_020498F4(r,(int)39,(int)1,(u16)p[12],(int)1536,(int)0,(unsigned)(((struct Obj00162 *)p)->f0));
    ARC_TOOL_DeleteHandle(r);
    func_020409B4(1);
}
