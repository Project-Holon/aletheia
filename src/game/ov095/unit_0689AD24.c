/*
 * file:     unit_0689AD24.c
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
 *   BTL_MAIN_DecodeMessageCode  0x021B8778  thumb
 */
typedef unsigned char u8;
extern int BTL_MAIN_DecodeMessageCode(int, int, u8 *);
void func_0689AD24(u8 *p, int a, unsigned short b)
{
    p[1] = BTL_MAIN_DecodeMessageCode(a, b, p + 3);
    p[2] = 2;
}
