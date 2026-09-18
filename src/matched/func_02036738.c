/*
 * unit:     no
 * function: func_02036738
 * address:  0x02036738
 * packet:   pkt_020366C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void func_02036738(char *q, int v)
{
    *(char *)*(char **)q = (char)v;
    *(char **)q = *(char **)q + 1;
    *(unsigned short *)(q + 4) = *(unsigned short *)(q + 4) - 1;
}

