/*
 * function: func_021BDCDC
 * address:  0x021BDCDC
 * packet:   pkt_021BDC14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Runs the +0x3C object to completion and clears it.
 */


extern void func_0204047C(int, int);

void func_021BDCDC(int unused, char *p)
{
    if (*(int *)(p + 0x3c) != 0) {
        func_0204047C(1, *(unsigned char *)(p + 0x38));
        *(int *)(p + 0x3c) = 0;
    }
}

