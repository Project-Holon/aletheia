/*
 * function: func_021D63A8
 * address:  0x021D63A8
 * packet:   pkt_ov016_021D63A8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HEAPlEnd (libdwcutil.TWL.HYB.a heap.o)
 *
 * symbols:
 *   func_02060C94  0x02060C94  arm
 *   g_021DE684     0x021DE684  data
 */

extern void func_02060C94(void *heap);
extern void *g_021DE684;

void func_021D63A8(void)
{
    func_02060C94(g_021DE684);
    g_021DE684 = 0;
}
