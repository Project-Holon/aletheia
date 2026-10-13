/*
 * function: ov208_func_021C08E8
 * address:  0x021C08E8
 * packet:   pkt_ov208_021C08E8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049740  0x02049740  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj14653.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *h);

void ov208_func_021C08E8(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(0x9f, *heap);
    ARC_UTIL_UploadPaletteFromHandle(h, 2, 4, 0, 0, 0x100, *heap);
    ((struct Obj14653 *)p)->f68 = func_02049740(h, 12, 7, 0, 0, *heap);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 0x26, 7, 0, (u16)((struct Obj14653 *)p)->f68, 0, 0, *heap);
    ARC_TOOL_DeleteHandle(h);
}
