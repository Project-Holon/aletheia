/*
 * function: func_021C1F44
 * address:  0x021C1F44
 * packet:   pkt_021C1F44
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Calls 0x020307B0 when the first argument is non-zero.
 */


extern void func_020307B0(void *p);

void func_021C1F44(int a)
{
    if (a != 0)
        func_020307B0((void *)a);
}

