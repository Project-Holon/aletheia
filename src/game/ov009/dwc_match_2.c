/*
 * file:     dwc_match_2.c
 * function: DWCi_ProcessMatchSynPacketSub
 * address:  0x0216F008
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * symbols:
 *   func_0216EC84 0x0216EC84 arm
 */

extern void func_0216EC84(unsigned char aid, unsigned short type, unsigned char *data);

void DWCi_ProcessMatchSynPacketSub(unsigned char aid, unsigned short type, unsigned char *data)
{
    func_0216EC84(aid, type, data);
}
