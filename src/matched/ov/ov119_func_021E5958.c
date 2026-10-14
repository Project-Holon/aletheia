/*
 * function: POKETRADE_2D_LoadMainPalette
 * address: 0x021E5958
 * packet: pkt_ov119_021E5958
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj10381.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
void POKETRADE_2D_LoadMainPalette(int p)
{
    void *a = func_020490F4(0x66, ((struct Obj10381 *)p)->f5F4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(a, (int)0x1d, (int)2, (int)0, (u16)(((struct Obj10381 *)p)->f86C), (int)0, (int)0, ((struct Obj10381 *)p)->f5F4);
    ARC_TOOL_DeleteHandle(a);
}
