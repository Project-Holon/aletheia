/*
 * function: func_02175CF4
 * address: 0x02175CF4
 * packet: pkt_ov011_02175CF4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two alignment bytes at 02175D1E before D20.
 * note: Outer non-one guard returns the original byte, including values beyond boolean.
 * symbols:
 *   func_02175DA8 0x02175DA8 thumb ov011
 *   func_021756A4 0x021756A4 thumb ov011
 */
typedef unsigned char u8;
extern int func_02175DA8(u8 *);
extern u8 func_021756A4(char *);
int func_02175CF4(char *p, u8 *q)
{
    int v;
    v = q[0x1a4];
    if (v == 1) {
        if (func_02175DA8(q) == 1 && func_021756A4(p) == 1) return 1;
        return 0;
    }
    return v;
}
