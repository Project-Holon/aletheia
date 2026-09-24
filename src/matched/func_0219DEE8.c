/*
 * function: func_0219DEE8
 * address:  0x0219DEE8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Appends the byte while the count at +0x54 is under 0x28.
 *
 * symbols:

 */

void func_0219DEE8(char *p, int v)
{
    int n = *(int *)(p + 0x54);

    if (n < 0x28) {
        *(int *)(p + 0x54) = n + 1;
        *(char *)(p + 0x2c + n) = v;
    }
}

