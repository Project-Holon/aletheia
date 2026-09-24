/*
 * function: func_021BDC80
 * address:  0x021BDC80
 * packet:   pkt_021BDC80
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Returns one of three words selected by +0x10, or -1.
 */


int func_021BDC80(char *p)
{
    switch (*(int *)(p + 0x10)) {
    case 0:
        return *(int *)(p + 0x44);
    case 1:
        return *(int *)(p + 0x50);
    case 2:
        return *(int *)(p + 0x5c);
    }
    return -1;
}

