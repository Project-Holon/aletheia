/*
 * function: ArraySort
 * address:  0x021843C8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on three fields of the object and the second argument.
 *
 * symbols:
 *   qsort  0x0209455C  arm  arm9

 */

extern void qsort(int a, int b, int c, int d);

void ArraySort(int *p, int b)
{
    qsort(p[5], p[0], p[2], b);
}

