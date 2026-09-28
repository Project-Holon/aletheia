/*
 * function: func_021BDCA4
 * address:  0x021BDCA4
 * packet:   pkt_021BDCA4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Stores the mode at +0x38, arms +0x3C and hands the mode to every +0x70 handle.
 */


extern void func_0204B84C(int, int);

void func_021BDCA4(char *p, unsigned char v)
{
    unsigned char i;

    *(unsigned char *)(p + 0x38) = v;
    *(int *)(p + 0x3c) = 1;
    for (i = 0; i < *(unsigned char *)(p + 0x68); i++)
        func_0204B84C(*(int *)(p + i * 8 + 0x70), v);
}

