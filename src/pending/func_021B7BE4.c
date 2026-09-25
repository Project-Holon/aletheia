/*
 * function: func_021B7BE4
 * address:  0x021B7BE4
 * packet:   pkt_021B7BE4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Tail call to func_021B70B8((char *)p + 0x24).
 *
 * symbols:
 *   func_021B70B8  0x021B70B8  thumb  ov071
 
 *
 * Blocker: the callee has no witness outside this range (unlabelled leaf, no label/sole-ref/matched entry); byte-correct otherwise.
*/

void func_021B7BE4(void *p)
{
    void func_021B70B8(void *);
    func_021B70B8((char *)p + 0x24);
}
