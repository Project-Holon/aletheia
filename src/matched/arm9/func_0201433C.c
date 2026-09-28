/*
 * function: func_0201433C
 * address:  0x0201433C
 * packet:   pkt_02014314
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern unsigned char *func_02014388(char *a0, unsigned int a1);

void func_0201433C(char *a0, int a1)
{
    unsigned char *p = func_02014388(a0, a1);

    if (p != 0)
        *p &= 0xff ^ (1 << (a1 % 8));
}
