/*
 * function: func_021C658C
 * address: 0x021C658C
 * packet: pkt_ov128_021C658C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * calls: 021C6698 receives live r0=0x180 although its own body ignores it;
 *   021CA0BC heap is widened because this caller has no truncation.
 * volatile: hardware register stores at 021C65A6 and 021C65A8
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   func_020490F4 0x020490F4 arm
 *   func_021C6698 0x021C6698 thumb ov128
 *   func_021C66A8 0x021C66A8 thumb ov128
 *   func_021C67A8 0x021C67A8 thumb ov128
 *   func_021C692C 0x021C692C thumb ov128
 *   func_021C69C4 0x021C69C4 thumb ov128
 *   func_021C6CB0 0x021C6CB0 thumb ov128
 *   func_021C6A84 0x021C6A84 thumb ov128
 *   func_021CA0BC 0x021CA0BC thumb ov128
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
#include "../include/Obj03812.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_021C6698(void *);
extern void func_021C66A8(char *p, int heap);
extern void func_021C67A8(char *p, int heap);
extern void func_021C692C(u8 *p, int heap);
extern void func_021C69C4(void *,void *,int);
extern void func_021C6CB0(char *p, int heap);
extern void func_021C6A84(void *,int);
extern void func_021CA0BC(void *,int);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void func_021C658C(char *p,void *q,int heap)
{
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050=0; *(volatile u16 *)0x04001050=0;
    GXx_SetMasterBrightness_((void *)0x0400006c,-16); GXx_SetMasterBrightness_((void *)0x0400106c,-16);
    BG_SYS_SetLcdSwap(0);
    ((struct Obj03812 *)p)->f8=func_020490F4(63,heap); ((struct Obj03812 *)p)->f180=heap;
    func_021C6698((void *)0x180);
    func_021C66A8(p,heap); func_021C67A8(p,heap); func_021C692C((u8 *)p,heap);
    func_021C69C4(p,q,heap); func_021C6CB0(p,heap); func_021C6A84(p,heap); func_021CA0BC(p,heap);
    GFL_NET_RestartWithDefaultTimeout(1,52); BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
}
