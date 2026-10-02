/*
 * function: func_021E1CA8
 * address: 0x021E1CA8
 * packet: pkt_ov119_021E1CA8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0E4C 0x021E0E4C thumb ov119
 */
extern void func_021E0E4C(void *);
void func_021E1CA8(char *p)
{
    char *q = p + 0x8C4;
    int i;
    for (i = 0; i < 3; i++) {
        func_021E0E4C(q + i * 0x14);
    }
}
