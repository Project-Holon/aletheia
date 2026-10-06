/*
 * function: func_02164474
 * address:  0x02164474
 * packet:   pkt_ov010_02164474
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 func_02183DE4.
 *
 * symbols:
 *   func_0215E364  0x0215E364  thumb  ov010
 */

void func_0215E364(void *a);

void func_02164474(int a, int b)
{
    func_0215E364((void *)a);
}
