/*
 * function: func_02193D08
 * address:  0x02193D08
 * packet:   pkt_ov021_02193D08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int func_02193D08(unsigned char *p)
{
    int count = 0;
    int i;
    unsigned char *q = *(unsigned char **)(p + 4);

    if (q != 0) {
        for (i = 0; i < 10; i++) {
            if (*(unsigned short *)(q + i * 0x50) != 0)
                count++;
        }
    }
    return count;
}
