/*
 * function: ZUKAN_DETAIL_TOUCHBAR_FreeAnimBuffer
 * address:  0x021BE128
 * packet:   pkt_ov208_021BE128
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj14652.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Pltt {
    u32 pad0[3];
    u8 *data;
};

extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(void *src, void *dst, u32 size);
extern u32 func_020307B0(void *p);

void ZUKAN_DETAIL_TOUCHBAR_FreeAnimBuffer(u8 *p)
{
    struct Ov208Pltt *pltt;
    u32 file;
    u8 *data;

    file = (u32)ARC_UTIL_LoadPaletteBlockFromArchive(0x9f, 3, (u32)(&pltt), ((struct Obj14652 *)p)->f0);
    data = pltt->data;
    MI_CpuCopy8(data + 0x20, p + 0xb6, 0x20);
    MI_CpuCopy8(data + 0x60, p + 0xd6, 0x20);
    func_020307B0((void *)file);
    ((struct Obj14652 *)p)->f118 = 0;
}
