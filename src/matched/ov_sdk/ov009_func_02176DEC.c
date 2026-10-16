/*
 * function: DWC_IsSendableReliable
 * address:  0x02176DEC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call that supplies the second argument 1.
 *
 * symbols:
 *   DWCi_IsSendableReliable  0x02176DFC  arm
 */

extern int DWCi_IsSendableReliable(int aid, int type);

int DWC_IsSendableReliable(int a)
{
    return DWCi_IsSendableReliable(a, 1);
}

