/*
 * function: func_02175EE8
 * address: 0x02175EE8
 * packet: pkt_ov011_02175EE8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two alignment bytes at 02175EFA before EFC.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
extern void func_02082BCC(void *, int, int);
void func_02175EE8(u8 *p)
{
    func_02082BCC(p, 0, 0x14);
    p[0x10] = 4;
}
