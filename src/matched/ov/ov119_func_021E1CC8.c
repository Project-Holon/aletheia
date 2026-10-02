/*
 * function: func_021E1CC8
 * address: 0x021E1CC8
 * packet: pkt_ov119_021E1CC8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E0DA0 0x021E0DA0 thumb ov119
 */
extern void func_021E0DA0(void *);
void func_021E1CC8(char *p)
{
    char *q;
    int i = 0;
    q = p + 0x900;
    for (; i < 4; i++) {
        func_021E0DA0(q + i * 0x14);
    }
}
