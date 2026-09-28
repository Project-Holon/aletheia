/*
 * unit:     yes
 * function: func_021B6E00, func_021B6E0C, func_021B6E18
 * address:  0x021B6E00
 * packet:   pkt_ov071_021B6E00
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two bounded constant selectors and a constant return.
 */

int func_021B6E00(unsigned int x)
{
    return x <= 1 ? 0x32 : 0x12;
}

int func_021B6E0C(unsigned int x)
{
    return x <= 1 ? 0x42 : 0x22;
}

int func_021B6E18(void)
{
    return 3;
}
