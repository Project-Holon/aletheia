/*
 * function: func_021DD140
 * address: 0x021DD140
 * packet: pkt_ov119_021DD140
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8ADC 0x021D8ADC thumb ov119
 */
extern int func_021D8ADC(void *, int);
int func_021DD140(char *p)
{
    if (*(unsigned char *)(p + 0x11F1)) {
        if (func_021D8ADC(p, *(unsigned char *)(p + 0x11F1)))
            *(unsigned char *)(p + 0x11F1) = *(unsigned char *)(p + 0x11F1) - 1;
        else
            *(unsigned char *)(p + 0x11F1) = 0;
    }
    return *(unsigned char *)(p + 0x11F1) == 0;
}
