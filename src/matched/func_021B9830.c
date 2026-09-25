/*
 * function: func_021B9830
 * address:  0x021B9830
 * packet:   pkt_021B9830
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047CFC  0x02047CFC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern int func_02047CFC(int, int, u16);

void func_021B9830(char *p)
{
    *(int *)(p + 0x28) = func_02047CFC(5, 4, *(u16 *)p);
    *(u16 *)(p + 0x3a) = 0;
}
