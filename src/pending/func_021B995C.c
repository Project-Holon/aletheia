/*
 * function: func_021B995C
 * address:  0x021B995C
 * packet:   pkt_021B995C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Tail call to func_021B9BFC.
 *
 * symbols:
 *   func_021B9BFC  0x021B9BFC  thumb  ov068
 
 *
 * Blocker: the callee has no witness outside this range (unlabelled leaf, no label/sole-ref/matched entry); byte-correct otherwise.
*/

void func_021B995C(void)
{
    void func_021B9BFC(void);
    func_021B9BFC();
}
