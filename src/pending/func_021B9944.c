/*
 * function: func_021B9944
 * address:  0x021B9944
 * packet:   pkt_021B9944
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Tail call to func_021BA018 with the pointer advanced by 0x7c.
 *
 * symbols:
 *   func_021BA018  0x021BA018  thumb  ov068
 
 *
 * Blocker: the callee has no witness outside this range (unlabelled leaf, no label/sole-ref/matched entry); byte-correct otherwise.
*/

void func_021B9944(void *p)
{
    void func_021BA018(void *);
    func_021BA018((char *)p + 0x7c);
}
