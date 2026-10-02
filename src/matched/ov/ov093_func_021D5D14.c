/*
 * function: func_021D5D14
 * address: 0x021D5D14
 * packet: pkt_ov093_021D5D14
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * evidence: 021D5CB4 unconditionally writes both outputs before its switch.
 * symbols:
 *   func_021D5CB4 0x021D5CB4 thumb ov093
 */
typedef signed char s8;
typedef unsigned char u8;
extern s8 *func_021D5CB4(s8 *, int, u8 *, u8 *);
int func_021D5D14(s8 *p, int i, int sign)
{
    s8 a;
    s8 b;
    s8 *v;
    v = func_021D5CB4(p, i, (u8 *)&a, (u8 *)&b);
    if (sign > 0) return *v < b;
    else return *v > a;
}
