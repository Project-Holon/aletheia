/*
 * function: DOWSING_LoadBackground
 * address:  0x021F0760
 * packet:   pkt_ov033_021F0760
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02049740 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj13072.h"

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(unsigned);

void DOWSING_LoadBackground(char *p)
{
    unsigned h = ((struct Obj13072 *)p)->f2;
    void *a = func_020490F4(0xC3, h);
    unsigned b;
    ARC_UTIL_UploadPaletteFromHandle(a, 0, 4, 0, 0, 0x40, h);
    b = func_02049740(a, 2, 7, 0, 0, h);
    ARC_UTIL_UploadBgPaletteAddFromHandle(a, 7, 7, 0, (unsigned short)b, 0, 0, h);
    ARC_TOOL_DeleteHandle(a);
    BG_SYS_FillTileMap(7, 0, 0, 0x20, 0x18, 1);
    func_02041B6C(7);
    ((struct Obj13072 *)p)->f10 = b;
}
