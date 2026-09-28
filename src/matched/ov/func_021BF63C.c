/*
 * function: func_021BF63C
 * address:  0x021BF63C
 * packet:   pkt_021BF63C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Frees the 0x14-byte record at the index held in +0x98.
 */


extern void func_0204B6F4(int, int, int);

void func_021BF63C(int unused, char *p)
{
    int i = *(int *)(p + 0x98);

    if (i == 6)
        return;
    func_0204B6F4(*(int *)(p + i * 0x14 + 0x1c), 0, 0);
    *(int *)(p + 0x10c) = 0;
}

