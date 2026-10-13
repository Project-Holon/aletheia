/*
 * function: C_GEAR_LoadFrameGraphics
 * address: 0x021F15FC
 * packet: pkt_ov029_021F15FC
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 */
#include "../include/Obj13046.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
void C_GEAR_LoadFrameGraphics(char *p, int flag)
{
    if (flag == 0)
        ARC_UTIL_UploadBgPaletteAddFromHandle((void *)(((struct Obj13046 *)p)->f24), 1, 5, 0, (u16)((struct Obj13046 *)p)->f14, 0, 0, 0x70);
}
