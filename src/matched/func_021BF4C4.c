/*
 * function: func_021BF4C4
 * address:  0x021BF4C4
 * packet:   pkt_021BF4C4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Releases each of the six 0x14-byte element handles against a parallel table and clears its +0x2C slot.
 */


extern void func_0204B3DC(int, int);
extern void func_0204B878(int, int);

void func_021BF4C4(int unused, char *q, int c, int *tbl)
{
    unsigned char i;

    for (i = 0; i < 6; i++) {
        func_0204B3DC(*(int *)(q + i * 0x14 + 0x1c), tbl[i]);
        *(int *)(q + i * 0x14 + 0x2c) = 0;
        func_0204B878(*(int *)(q + i * 0x14 + 0x1c), *(unsigned short *)(q + i * 0x14 + 0x24));
    }
    *(int *)(q + 0x94) = 6;
}

