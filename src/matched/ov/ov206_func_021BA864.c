/*
 * function: func_021BA864
 * address:  0x021BA864
 * packet:   pkt_021BA864
 * region:   ov206
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02041EE4 0x02041EE4 arm
 */

extern void func_02041EE4(int, int, int);

void func_021BA864(int unused, char *p)
{
    if (*(unsigned char *)(p + 0x39) & 1)
    {
        func_02041EE4(*(unsigned char *)(p + 0x4e), 1, 1);
    }
    *(unsigned char *)(p + 0x38) = 0;
    *(unsigned char *)(p + 0x39) = 0;
}
