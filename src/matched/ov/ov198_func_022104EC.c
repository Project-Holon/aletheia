/*
 * function: func_022104EC
 * address: 0x022104EC
 * packet: pkt_ov198_022104EC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FC6C 0x0203FC6C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_02212144 0x02212144 data a4
 *   d_02212174 0x02212174 data a4
 *   d_022121B4 0x022121B4 data a4
 *   d_02212154 0x02212154 data a4
 *   d_02212194 0x02212194 data a4
 */
#include "../include/Obj14568.h"
#include "../include/Obj25245.h"
#include "../include/Obj25246.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct BgVramReq {u32 unk00,unk04,unk08,unk0c;};
struct BgTemplate {
    u32 unk00,unk04,bufSize,unk0c;
    u8 unk10,unk11,unk12,unk13;
    u32 unk14;
    u8 unk18,unk19,unk1a,unk1b;
    u32 unk1c;
};
extern const struct BgVramReq d_02212144;
extern const struct BgTemplate d_02212174,d_022121B4,d_02212154,d_02212194;
extern void func_0203FC6C(const struct BgVramReq *,u32);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void BG_SYS_ClearSlot(u32);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_SetFlagField06(u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
void func_022104EC(u8 *p)
{
    struct BgVramReq req=d_02212144;
    struct BgTemplate cfg7,cfg6,cfg5,cfg4;
    func_0203FC6C(&req,1);
    cfg7=d_02212174;
    BG_SYS_InitBgLayer(7,&cfg7,0);
    cfg6=d_022121B4;
    BG_SYS_InitBgLayer(6,&cfg6,0);
    cfg5=d_02212154;
    BG_SYS_InitBgLayer(5,&cfg5,0);
    BG_SYS_ClearSlot(5);
    cfg4=d_02212194;
    BG_SYS_InitBgLayer(4,&cfg4,0);
    BG_SYS_ClearSlot(4);
    BG_SYS_InitRun(5,32,0,((struct Obj25245 *)(*(u8 * *)&((struct Obj14568 *)p)->f0))->f10);
    BG_SYS_InitRun(4,32,0,((struct Obj25246 *)(*(u8 * *)&((struct Obj14568 *)p)->f0))->f10);
    BG_SYS_SetFlagField06(5);
    BG_SYS_SetFlagField06(4);
    BG_SYS_SetSubPlaneVisible(15,1);
}
