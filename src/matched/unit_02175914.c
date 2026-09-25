/*
 * unit:     yes
 * function: func_02175914, func_02175920, func_0217592C
 * address:  0x02175914
 * packet:   pkt_02175914
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three one-byte flag setters at fixed offsets.
 */

void func_02175914(int a, int b)
{
    *(unsigned char *)(a + b + 0x194) = 1;
}

void func_02175920(int a)
{
    *(unsigned char *)(a + 0x19a) = 1;
}

void func_0217592C(int a)
{
    *(unsigned char *)(a + 0x19b) = 1;
}
