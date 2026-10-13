/*
 * function: DWCi_HEAPlEnd
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
 *   gHeapWork     0x021DE684  data
 */

extern void func_02060C94(void *heap);
extern void *gHeapWork;

void DWCi_HEAPlEnd(void)
{
    func_02060C94(gHeapWork);
    gHeapWork = 0;
}
