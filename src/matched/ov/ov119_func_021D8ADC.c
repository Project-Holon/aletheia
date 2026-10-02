/*
 * function: func_021D8ADC
 * address: 0x021D8ADC
 * packet: pkt_ov119_021D8ADC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
int func_021D8ADC(char *p)
{
    int r = 0;
    int v = *(int *)(p + 0x118c);
    if (v == 3 || v == 9)
        r = 1;
    return r;
}
