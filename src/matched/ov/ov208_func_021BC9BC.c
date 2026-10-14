/*
 * function: ZUKAN_DETAIL_COMMON_LoadBgPaletteRange
 * address:  0x021BC9BC
 * packet:   pkt_ov208_021BC9BC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049740  0x02049740  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   func_020413B0  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void func_02041B6C(u32 bit);

u32 ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs, u32 arc,
                        u32 chr, u32 scr, u32 cell, u32 chrOfs)
{
    void *h;
    u32 type;

    type = 0;
    if (layer >= 4)
        type = 4;
    h = func_020490F4(arc, heap);
    if (skip == 0)
        ARC_UTIL_UploadPaletteFromHandle(h, chr, type, palOfs << 5, pal << 5, count << 5, heap);
    if (skip == 0)
        chrOfs = func_02049740(h, scr, layer, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, cell, layer, 0, (u16)chrOfs, 0, 0, heap);
    func_020413B0(layer, 0, 0, 0x20, 0x18, pal);
    ARC_TOOL_DeleteHandle(h);
    func_02041B6C(layer);
    return chrOfs;
}
