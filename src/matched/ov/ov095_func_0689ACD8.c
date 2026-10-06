/*
 * function: func_0689ACD8
 * address: 0x0689ACD8
 * packet: pkt_ov095_0689ACD8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow the return.
 * symbols:
 *   func_0689ACEC 0x0689ACEC thumb ov095
 */
typedef unsigned char u8;
extern int func_0689ACEC(int, int, u8 *);
void func_0689ACD8(u8 *p, int a, unsigned short b)
{
    p[0] = func_0689ACEC(a, b, p + 3);
}
