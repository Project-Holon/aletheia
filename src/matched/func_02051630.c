/*
 * function: func_02051630
 * address:  0x02051630
 * packet:   pkt_02051630
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Dereference the first argument and tail-call func_0205250C with the loaded
 * pointer.  Unlabelled ARM leaf in the ARM9 listing; matched so its overlay
 * callers get a `matched` witness.
 *
 * symbols:
 *   func_0205250C  0x0205250C  arm
 */

extern void func_0205250C(void *p, void *q);

void func_02051630(void **p, void *q)
{
    func_0205250C(*p, q);
}
