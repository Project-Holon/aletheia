/*
 * function: func_0220B990
 * address:  0x0220B990
 * packet:   pkt_0220B990
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0220B094 0x0220B094 thumb ov196
 *
 * blocker: 0x0220B094 is an unlabelled leaf (no func_ label in ov187/
 *   ov196/ov207, the three windows that hold it), so neither label nor
 *   sole-ref/code can attest the tail-call pool word; byte-correct.
 */

extern int func_0220B094(void *, int);

int func_0220B990(char *a)
{
    return func_0220B094(a + 0x28, *(int *)(a + 0x59c));
}