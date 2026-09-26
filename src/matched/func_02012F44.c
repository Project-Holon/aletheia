/*
 * function: func_02012F44
 * address:  0x02012F44
 * packet:   pkt_02012F44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail-calls func_020071CC(*(void **)p, 0x2a).
 *
 * symbols:
 *   func_02012F44  0x02012F44  thumb
 *   func_020071CC  0x020071CC  thumb
 */

extern void func_020071CC(void *p, int n);

void func_02012F44(void *p)
{
    func_020071CC(*(void **)p, 0x2a);
}
