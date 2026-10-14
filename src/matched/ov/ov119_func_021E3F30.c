/*
 * function: POKETRADE_2D_LoadSubBackgroundGfx
 * address: 0x021E3F30
 * packet: pkt_ov119_021E3F30
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
#include "../include/Obj10379.h"
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
void POKETRADE_2D_LoadSubBackgroundGfx(char *p)
{
    void *v;
    v = func_020490F4(0x66, ((struct Obj10379 *)p)->f5F4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(v, 12, (int)4, (int)0, (unsigned short)(((struct Obj10379 *)p)->f870), (int)0, (int)0, (unsigned int)(((struct Obj10379 *)p)->f5F4));
    ARC_TOOL_DeleteHandle(v);
}
