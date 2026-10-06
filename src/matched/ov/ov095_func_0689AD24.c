/*
 * function: func_0689AD24
 * address: 0x0689AD24
 * packet: pkt_ov095_0689AD24
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow the return.
 * symbols:
 *   func_0689AD3C 0x0689AD3C thumb ov095
 */
typedef unsigned char u8;
extern int func_0689AD3C(int, int, u8 *);
void func_0689AD24(u8 *p, int a, unsigned short b)
{
    p[1] = func_0689AD3C(a, b, p + 3);
    p[2] = 2;
}
