/*
 * function: func_021F0AC8
 * address: 0x021F0AC8
 * packet: pkt_ov029_021F0AC8
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
extern void func_02082BCC(void *, int, int);
void func_021F0AC8(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 8);
    p[6] = a;
    p[7] = b;
}
