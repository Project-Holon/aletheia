/*
 * unit:     yes
 * function: func_021F253C, func_021F2544
 * address:  0x021F253C
 * packet:   pkt_021F253C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void func_021F253C(char *p, unsigned short v)
{
    *(unsigned short *)(p + 0x70) = v;
}

void func_021F2544(char *p)
{
    *(unsigned short *)(p + 0x70) = 0;
}
