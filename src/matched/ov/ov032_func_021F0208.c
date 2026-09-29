/*
 * function: func_021F0208
 * address:  0x021F0208
 * packet:   pkt_ov032_021F0208
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02021FD8  0x02021FD8  thumb
 *   func_021D3294  0x021D3294  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02021FD8(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021D3294(u32 p, u32 a, u32 b, u32 c, u32 d);

void func_021F0208(u8 *p, int flag)
{
    if (flag) {
        func_02021FD8(*(u32 *)(p + 0xac), 1, 0, 0xe0, 6, 0);
        func_02021FD8(*(u32 *)(p + 0xac), 3, 0, 0xe0, 6, 0);
        func_021D3294(*(u32 *)(p + 0x10), 5, 0x1e, 0xa, 6);
    } else {
        func_02021FD8(*(u32 *)(p + 0xac), 1, 0, 0xe0, 0, 0);
        func_02021FD8(*(u32 *)(p + 0xac), 3, 0, 0xe0, 0, 0);
        func_021D3294(*(u32 *)(p + 0x10), 4, 0x1e, 0xd, 3);
    }
}
