/*
 * function: func_021B9964
 * address:  0x021B9964
 * packet:   pkt_021B9964
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Tail call to func_021B9D58.
 *
 * symbols:
 *   func_021B9D58  0x021B9D58  thumb  ov068
 
 *
 * Blocker: the callee has no witness outside this range (unlabelled leaf, no label/sole-ref/matched entry); byte-correct otherwise.
*/

void func_021B9964(void)
{
    void func_021B9D58(void);
    func_021B9D58();
}
