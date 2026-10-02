/*
 * function: func_02175BCC
 * address: 0x02175BCC
 * packet: pkt_ov011_02175BCC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled return.
 * symbols:
 *   func_02175DA8 0x02175DA8 thumb ov011
 */
typedef unsigned char u8;
extern int func_02175DA8(u8 *p);
u8 *func_02175BCC(u8 *p)
{
    if (func_02175DA8(p) == 0) p = 0;
    else p += 0xAC;
    return p;
}
