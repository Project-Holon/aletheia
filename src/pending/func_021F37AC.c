/*
 * function: func_021F37AC
 * address:  0x021F37AC
 * packet:   pkt_021F37AC
 * region:   ov064
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Two-call wrapper.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb
 *   func_021BE580  0x021BE580  thumb
 
 *
 * Blocker: the callee has no witness outside this range (unlabelled leaf, no label/sole-ref/matched entry); byte-correct otherwise.
*/

void func_021F37AC(void)
{
    void func_02188D2C(void);
    void func_021BE580(void);
    func_02188D2C();
    func_021BE580();
}
