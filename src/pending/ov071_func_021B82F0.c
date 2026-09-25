/*
 * function: ov071_func_021B82F0
 * address:  0x021B82F0
 * packet:   pkt_ov071_021B82F0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Tail call to func_021B70B8((char *)p + 0x34).  Address also resident in
 * ov021; region-qualified packet id.
 *
 * symbols:
 *   func_021B70B8  0x021B70B8  thumb  ov071
 
 *
 * Blocker: the callee has no witness outside this range (unlabelled leaf, no label/sole-ref/matched entry); byte-correct otherwise.
*/

void func_021B82F0(void *p)
{
    void func_021B70B8(void *);
    func_021B70B8((char *)p + 0x34);
}
