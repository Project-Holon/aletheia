/*
 * function: func_0200E0B0
 * address:  0x0200E0B0
 * packet:   pkt_0200E0B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail-calls func_020071CC(p, 0x3d).
 *
 * symbols:
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_020071CC  0x020071CC  thumb
 */

extern void *func_020071CC(void *p, int n);

void *func_0200E0B0(void *p)
{
    return func_020071CC(p, 0x3d);
}
