/*
 * function: func_0200E460
 * address:  0x0200E460
 * packet:   pkt_0200E460
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

void func_0200E460(char *p, int idx, int v)
{
    unsigned short *q = (unsigned short *)(p + idx * 2);
    *q = *q + (unsigned short)v;
    if (*q > 0x270f)
        *q = 0x270f;
}
