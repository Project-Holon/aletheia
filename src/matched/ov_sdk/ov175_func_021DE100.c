/*
 * function: func_021DE100
 * address:  0x021DE100
 * packet:   pkt_021DE100
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02182AC0  0x02182AC0  arm
 *   func_02182CF0  0x02182CF0  arm
 *   g_021E3A8C     0x021E3A8C  data
 *   g_021E3B4C     0x021E3B4C  data
 *   g_021E3B54     0x021E3B54  data
 *
 * Forward the +0x08 block's first two words to the two ov009 record readers,
 * both keyed on the +0x18 handle.
 */

typedef unsigned int u32;

extern u32 g_021E3A8C[];
extern u32 g_021E3B4C[];
extern u32 g_021E3B54[];
extern void func_02182AC0(u32, u32 *, u32 *, u32);
extern void func_02182CF0(u32, u32 *, u32 *, u32);

int func_021DE100(char *p)
{
    u32 *q = *(u32 **)(p + 8);

    func_02182AC0(*(u32 *)(p + 0x18), g_021E3A8C, g_021E3B4C, q[0]);
    func_02182CF0(*(u32 *)(p + 0x18), g_021E3A8C, g_021E3B54, q[1]);
    return 0;
}
