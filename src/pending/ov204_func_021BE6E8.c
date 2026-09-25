/*
 * function: func_021BE6E8
 * address:  0x021BE6E8
 * packet:   pkt_021BE6E8
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021BD374 0x021BD374 thumb ov204
 *
 * blocker: 0x021BD374 is an unlabelled leaf (no func_ label anywhere), so
 *   neither label nor sole-ref/code can attest the bl site; byte-correct
 *   otherwise.
 */

extern void func_021BD374(int);

int func_021BE6E8(char *a)
{
    func_021BD374(*(int *)(a + 0xa4));
    return 1;
}
