/*
 * function: BTLV_SCD_SetTargetsAltKind1
 * address: 0x0689ACFC
 * packet: pkt_ov095_0689ACFC
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow the return.
 * symbols:
 *   func_0689AD14 0x0689AD14 thumb ov095
 */
typedef unsigned char u8;
extern int func_0689AD14(int, int, u8 *);
void BTLV_SCD_SetTargetsAltKind1(u8 *p, int a, unsigned short b)
{
    p[1] = func_0689AD14(a, b, p + 3);
    p[2] = 1;
}
