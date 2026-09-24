/*
 * function: func_021E8F50
 * address:  0x021E8F50
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Clear the pooled-offset word and return the argument.
 */


int func_021E8F50(char *p, int v)
{
    *(int *)(*(char **)(p + 0x2c) + 0xA194) = 0;
    return v;
}

