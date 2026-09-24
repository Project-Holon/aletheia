/*
 * function: func_021C7908
 * address:  0x021C7908
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021CF248  0x021CF248  data
 *   g_021D3C20  0x021D3C20  data
 *   g_021D3B9C  0x021D3B9C  data
 *   g_021CF7AC  0x021CF7AC  data
 *
 *
 * Flushes the 0x021D3C20 block and clears the +0x20 word of the 0x021D3B9C block.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 g_021D3C20[];
extern u8 g_021D3B9C[];
extern void func_02086004(void *);

int func_021C7908(void)
{
    func_02086004(g_021D3C20);
    *(u32 *)(g_021D3B9C + 0x20) = 0;
    return 1;
}
