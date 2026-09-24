/*
 * function: func_02194DE4
 * address:  0x02194DE4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Appends a byte through the count at +8 of the object.
 *
 * symbols:

 */

void func_02194DE4(int *p, int v)
{
    int n = p[2];

    p[2] = n + 1;
    *(char *)(p[0] + n) = v;
}

