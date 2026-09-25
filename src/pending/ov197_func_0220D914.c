/*
 * function: func_0220D914
 * address:  0x0220D914
 * packet:   pkt_0220D914
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02025D14 0x02025D14 thumb
 *
 * blocker: 0x02025D14 is an unlabelled ARM9 leaf (no func_ label, no SDK
 *   entry), so neither label nor sole-ref/code can attest the tail-call
 *   pool word; byte-correct.
 */

extern void func_02025D14(int);

void func_0220D914(char *a)
{
    func_02025D14(*(int *)(a + 0x144));
}