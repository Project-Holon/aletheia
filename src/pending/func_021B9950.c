/*
 * function: func_021B9950
 * address:  0x021B9950
 * packet:   pkt_021B9950
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Tail call to func_021BA020 with the pointer advanced by 0x7c.
 *
 * symbols:
 *   func_021BA020  0x021BA020  thumb  ov068
 
 *
 * Blocker: the callee has no witness outside this range (unlabelled leaf, no label/sole-ref/matched entry); byte-correct otherwise.
*/

void func_021B9950(void *p)
{
    void func_021BA020(void *);
    func_021BA020((char *)p + 0x7c);
}
