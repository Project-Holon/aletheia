/*
 * function: func_021609E8
 * address:  0x021609E8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Length of the text up to the first period or terminator.
 */

int func_021609E8(const char *p)
{
    const char *start = p;

    while (*p != '.' && *p != 0)
        p++;
    return (int)(p - start);
}
