/*
 * function: func_021FBC1C
 * address:  0x021FBC1C
 * packet:   pkt_021FBC1C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9660  0x021F9660  thumb  ov135
 *   g_022033FC  0x022033FC  data  ov135

 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0x19/0x15 code from the table.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_0204B98C(u32 v);
extern void func_0204B3DC(u32 v, u32 k);
extern void func_021F9660(u8 *p, u32 k);
extern void func_0201F868(u32 v);
extern u8 g_022033FC[];

int func_021FBC1C(u8 *p)
{
    if (func_0204B98C(*(u32 *)(p + 8)) != 0) {
        return -1;
    }
    func_0204B3DC(*(u32 *)(p + 8), 0);
    func_0204B3DC(*(u32 *)(p + 0xc), 0);
    func_0204B3DC(*(u32 *)(p + 0x10), 0);
    func_021F9660(p, 0x3);
    func_0201F868(*(u32 *)(p + 0x30));
    *(u32 *)(p + 0x48) = (*(s32 *)(g_022033FC + *(s16 *)(p + 0x38) * 8) != 1) ? 0x19 : 0x15;
    return -1;
}
