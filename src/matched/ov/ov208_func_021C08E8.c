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
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049BDC(u32 h, u32 id, u32 type, u32 ofs, u32 src, u32 size, u32 heap);
extern u32  func_02049740(u32 h, u32 id, u32 layer, u32 ofs, u32 size, u32 heap);
extern void func_02049990(u32 h, u32 id, u32 layer, u32 ofs, u32 chrOfs, u32 a5, u32 a6, u32 heap);
extern void func_02049238(u32 h);

void ov208_func_021C08E8(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(0x9f, *heap);
    func_02049BDC(h, 2, 4, 0, 0, 0x100, *heap);
    *(u32 *)(p + 0x68) = func_02049740(h, 12, 7, 0, 0, *heap);
    func_02049990(h, 0x26, 7, 0, (u16)*(u32 *)(p + 0x68), 0, 0, *heap);
    func_02049238(h);
}
