/*
 * function: func_02213684
 * address: 0x02213684
 * packet: pkt_ov199_02213684
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
void func_02213684(const unsigned char *p, unsigned char *a, unsigned char *b)
{
    int i, index;
    int side, flags;
    flags = p[0x21];
    *a = 0;
    *b = 0;
    side = flags & 1;
    for (i = 0; i <= 1; i++) {
        if ((i & 1) == side) {
            if (side != 0)
                index = (i & 2) + 1;
            else
                index = i & 2;
            *a = *(unsigned int *)(p + 0xe0 + index * 4);
        } else {
            if (side != 0)
                index = i & 2;
            else
                index = (i & 2) + 1;
            *b = *(unsigned int *)(p + 0xe0 + index * 4);
        }
    }
}
