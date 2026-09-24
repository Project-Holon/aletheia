/*
 * function: func_021BC6C8
 * address:  0x021BC6C8
 * packet:   pkt_021BC6C8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * True when the word at +0x10, less two, is 0 or 1.
 */


int func_021BC6C8(char *p)
{
    unsigned int v = *(unsigned int *)(p + 0x10);

    v -= 2;
    return v <= 1;
}

