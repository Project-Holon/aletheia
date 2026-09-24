/*
 * function: func_021BD868
 * address:  0x021BD868
 * packet:   pkt_021BD868
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * True when the halfword at +0x28 equals the word at +8.
 */


int func_021BD868(char *p)
{
    return *(unsigned int *)(p + 8) == *(unsigned short *)(p + 0x28);
}

