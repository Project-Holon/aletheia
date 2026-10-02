/*
 * function: func_021E707C
 * address: 0x021E707C
 * packet: pkt_ov119_021E707C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E7058 0x021E7058 thumb ov119
 */
extern void func_021E7058(void *p);

int func_021E707C(void *p)
{
    if (*((unsigned char *)p + 0x11f5)) {
        func_021E7058(p);
        return 0;
    }
    return 1;
}
