/*
 * function: SCRCMD_PROC_FLD_InitShopCells
 * address:  0x021B3F00
 * packet:   pkt_ov021_021B3F00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   func_0204B22C  0x0204B22C  arm
 *   SCRCMD_PROC_FLD_LoadCursorResources  0x021B3C78  thumb  ov021
 *   SCRCMD_PROC_FLD_LoadIconResources  0x021B3CFC  thumb  ov021
 *   SCRCMD_PROC_FLD_CreateShopActors  0x021B3DEC  thumb  ov021
 */
#include "../include/Obj00037.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void SCRCMD_PROC_FLD_LoadCursorResources(char *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void SCRCMD_PROC_FLD_LoadIconResources(char *w);
extern void SCRCMD_PROC_FLD_CreateShopActors(char *w);

void SCRCMD_PROC_FLD_InitShopCells(u8 *w)
{
    ((struct Obj00037 *)w)->f1BC = (u32)CLACT_CreateUnit(5, 1, ((struct Obj00037 *)w)->f4);
    func_0204B22C((struct Bank *)(((struct Obj00037 *)w)->f1BC), 1);
    SCRCMD_PROC_FLD_LoadCursorResources((char *)w);
    ((struct Obj00037 *)w)->f1F8 = func_020490F4(0x19, ((struct Obj00037 *)w)->f4);
    SCRCMD_PROC_FLD_LoadIconResources((char *)w);
    SCRCMD_PROC_FLD_CreateShopActors((char *)w);
}
