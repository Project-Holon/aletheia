/*
 * function: ov208_func_021BC9BC
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
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02049238  0x02049238  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049BDC(void *h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u16 heap);
extern u32  func_02049740(void *h, u32 id, u32 layer, u32 ofs, u32 size, u32 heap);
extern void func_02049990(void *h, u32 id, u32 layer, u32 ofs, u32 chrOfs, u32 a5, u32 a6,
                          u32 heap);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(void *h);
extern void func_02041B6C(int layer);

u32 ov208_func_021BC9BC(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs, u32 arc,
                        u32 chr, u32 scr, u32 cell, u32 chrOfs)
{
    void *h;
    u32 type;

    type = 0;
    if (layer >= 4)
        type = 4;
    h = func_020490F4(arc, heap);
    if (skip == 0)
        func_02049BDC(h, chr, type, palOfs << 5, pal << 5, count << 5, heap);
    if (skip == 0)
        chrOfs = func_02049740(h, scr, layer, 0, 0, heap);
    func_02049990(h, cell, layer, 0, (u16)chrOfs, 0, 0, heap);
    func_020413B0(layer, 0, 0, 0x20, 0x18, pal);
    func_02049238(h);
    func_02041B6C(layer);
    return chrOfs;
}
