/*
 * function: BMP_OAM_DeleteSys
 * address:  0x02025588
 * packet:   pkt_02025518
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   BMP_OAM_ReleaseModeSlots  0x02025B18  thumb
 */
#include "../include/Obj07093.h"

typedef unsigned int u32;

extern void ARC_TOOL_DeleteHandle(void *p);
struct Obj02025774;
extern void BMP_OAM_ReleaseModeSlots(struct Obj02025774 *p);
extern u32 func_020307B0(void *p);

void BMP_OAM_DeleteSys(void *p)
{
    ARC_TOOL_DeleteHandle(((struct Obj07093 *)p)->f8);
    BMP_OAM_ReleaseModeSlots(p);
    func_020307B0(p);
}
