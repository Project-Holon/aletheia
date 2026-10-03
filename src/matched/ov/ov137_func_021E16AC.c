/*
 * function: func_021E16AC
 * address: 0x021E16AC
 * packet: pkt_ov137_021E16AC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02082BCC(void *, int, unsigned);
char *func_021E16AC(char *p)
{
    func_02082BCC(p + 0xb8, 0, 32);
    return p + 0xb8;
}
