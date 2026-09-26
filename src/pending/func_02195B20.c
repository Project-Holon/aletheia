/*
 * function: func_02195B20
 * address:  0x02195B20
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * Blocker: 0x02198020 is an unlabelled ARM target in ov009/ov021 (ov009's
 *   listing emits it as a .word run, ov021's as Thumb code), so `label` and
 *   `sole-ref/code` both refuse the ABS32 site.  Witness class: label /
 *   sole-ref/code.
 *
 * symbols:
 *   func_02198020  0x02198020  arm
 */

extern void func_02198020(void);

void func_02195B20(void)
{
    func_02198020();
}
