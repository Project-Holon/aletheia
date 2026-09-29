/*
 * function: func_021BD704
 * address:  0x021BD704
 * packet:   pkt_ov016_021BD704
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskLoad (libdwcutil.TWL.HYB.a headline.o)
 *
 * symbols:
 *   func_020862F0  0x020862F0  arm
 *   GX_LoadBG1Scr  0x0207EA00  arm
 *   func_021D7724  0x021D7724  arm  ov016
 *   g_021DE554     0x021DE554  data
 */

extern void func_020862F0(void *addr, unsigned long n);
extern void GX_LoadBG1Scr(void *src, unsigned long off, unsigned long sz);
extern void func_021D7724(int kind, void *task);
extern unsigned short *g_021DE554;

void func_021BD704(void *task)
{
    func_020862F0(g_021DE554, 0xC0);
    GX_LoadBG1Scr(g_021DE554, 0, 0xC0);
    func_021D7724(1, task);
}
