/*
 * function: func_021BDCDC
 * address:  0x021BDCDC
 * packet:   pkt_021BDC14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   (none)

 * BLOCKED.  MATCH: the call at +0x10 targets 0204047C, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */


extern void func_0204047C(int, int);

void func_021BDCDC(int unused, char *p)
{
    if (*(int *)(p + 0x3c) != 0) {
        func_0204047C(1, *(unsigned char *)(p + 0x38));
        *(int *)(p + 0x3c) = 0;
    }
}

