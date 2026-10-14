/*
 * function: WORLDTRADE_TITLE_LoadMainBgSwap
 * address: 0x02200AB4
 * packet: pkt_ov135_02200AB4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 */
#include "../include/Obj00137.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *, u32, u32, u32, u32, u32, u32, u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void WORLDTRADE_TITLE_LoadMainBgSwap(u8 *p)
{
    void *h;
    if (((struct Obj00137 *)p)->f12E0 == 1 && ((struct Obj00137 *)p)->f12E4 == 0) {
        h = func_020490F4(0x60, 0x48);
        ARC_UTIL_UploadPaletteFromHandle(h, 4, 4, 0x160, 0x160, 0xa0, 0x48);
        func_02049658(h, 0xe, 5, 0, 0x1c00, 0, 0x48);
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(h, 0x21, 5, 0, 0, 0, 0, 0x48);
        ARC_TOOL_DeleteHandle(h);
        func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    }
}
