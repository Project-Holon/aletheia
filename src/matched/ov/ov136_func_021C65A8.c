/*
 * function: MB_SEQ_InitActorSystem
 * address:  0x021C65A8
 * packet:   pkt_ov136_021C65A8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetMainPlaneVisible   0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible   0x02043598  arm
 *   CLACT_InitSystem   0x0204A48C  arm
 *   CLACT_CreateUnit   0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer   0x0204B270  arm
 *   d_021C78E0 0x021C78E0 data a4
 *   d_021C7BA0 0x021C7BA0 data a4
 */
#include "../include/Obj23593.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 d_021C7BA0[];
extern const u8 d_021C78E0[];
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
void MB_SEQ_InitActorSystem(u8 *p)
{
    void *bank;

    CLACT_InitSystem((const struct Cfg *)d_021C7BA0, (u32)d_021C78E0, 0x66);
    bank = CLACT_CreateUnit(8, 0, 0x66);
    ((struct Obj23593 *)p)->f1EC = bank;
    CLACT_SetUnitDefaultRenderer(bank);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
