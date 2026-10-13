/*
 * function: func_021C5420
 * address: 0x021C5420
 * packet: pkt_ov136_021C5420
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   gClActorInitParam 0x020A1448 data a4
 *   d_021C77C4 0x021C77C4 data a4
 */
#include "../include/Obj06526.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 gClActorInitParam[],d_021C77C4[];
struct Bank;
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
typedef unsigned int   u32;
struct Bank;
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
void func_021C5420(u8 *p)
{
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(unsigned int)d_021C77C4,(u16)(((struct Obj06526 *)p)->f0));
    ((struct Obj06526 *)p)->fA0 = CLACT_CreateUnit(4,(int)0,(u16)(((struct Obj06526 *)p)->f0));
    CLACT_SetUnitDefaultRenderer(((struct Obj06526 *)p)->fA0);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
    GFL_NET_RestartWithDefaultTimeout((int)0,(u16)(((struct Obj06526 *)p)->f0));
}
