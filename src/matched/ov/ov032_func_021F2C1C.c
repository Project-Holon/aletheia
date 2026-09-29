/*
 * function: func_021F2C1C
 * address:  0x021F2C1C
 * packet:   pkt_ov032_021F2C1C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2C1C 0x021F2C1C thumb
 *   func_02028590 0x02028590 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 */

extern unsigned func_02028590(int, int, int, unsigned);
extern unsigned func_02027F60(unsigned, unsigned, unsigned, unsigned, unsigned);
extern unsigned func_02045EC0(unsigned, unsigned);

void func_021F2C1C(char *p)
{
    int i;
    int z;

    z = 0;
    *(unsigned *)(p + 0xbc) = func_02028590(9, 0, 1, *(unsigned short *)(p + 0x98));
    *(unsigned *)(p + 0xb8) = func_02027F60(4, 0xe, *(unsigned *)(p + 0xb0), *(unsigned *)(p + 0xb4), *(unsigned short *)(p + 0x98));
    i = 0;
    do {
        *(unsigned *)(p + i * 16 + 0xc4) = func_02045EC0(*(unsigned *)(p + 0x114), i + 0xc);
        *(unsigned short *)(p + i * 16 + 0xc8) = 0x39e3;
        *(int *)(p + i * 16 + 0xcc) = z;
        *(int *)(p + i * 16 + 0xc0) = z;
        i++;
    } while (i < 3);
    z = 0;
    i = 0;
    do {
        *(unsigned *)(p + i * 16 + 0xf4) = func_02045EC0(*(unsigned *)(p + 0x114), i + 0xf);
        *(unsigned short *)(p + i * 16 + 0xf8) = 0x39e3;
        *(int *)(p + i * 16 + 0xfc) = z;
        *(int *)(p + i * 16 + 0xf0) = z;
        i++;
    } while (i < 2);
}
