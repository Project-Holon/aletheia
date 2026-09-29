/*
 * function: func_02187D30
 * address:  0x02187D30
 * packet:   pkt_ov020_02187D30
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned int u32;

int func_02187D30(char *p)
{
    if (*(u32 *)(p + 0x1c) < *(u32 *)(p + 0x18))
        return 1;
    return 0;
}
