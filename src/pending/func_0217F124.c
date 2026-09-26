/*
 * function: func_0217F124
 * address:  0x0217F124
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
 * Blocker: 0x020964F4 is an unlabelled ARM9 defaulting thunk
 *   (`ldr ip,[pc,#8]; mov r1,#0; mov r2,#0xa; bx ip` -> 0x020963F8); the
 *   arm9 listing emits it as a .word run, so `label` and `sole-ref/code`
 *   both refuse the ABS32 site.  Witness class: label / sole-ref/code.
 *
 * symbols:
 *   func_020964F4  0x020964F4  arm
 */

extern void func_020964F4(void);

void func_0217F124(void)
{
    func_020964F4();
}
