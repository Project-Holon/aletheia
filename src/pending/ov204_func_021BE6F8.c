/*
 * function: func_021BE6F8
 * address:  0x021BE6F8
 * packet:   pkt_021BE6F8
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021BD39C 0x021BD39C thumb ov204
 *
 * blocker: 0x021BD39C is an unlabelled leaf (no func_ label anywhere), so
 *   neither label nor sole-ref/code can attest the bl site; byte-correct
 *   otherwise.
 */

extern void func_021BD39C(int);

int func_021BE6F8(char *a)
{
    func_021BD39C(*(int *)(a + 0xa4));
    return 1;
}
