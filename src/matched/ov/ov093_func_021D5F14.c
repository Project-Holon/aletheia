/*
 * function: func_021D5F14
 * address: 0x021D5F14
 * packet: pkt_ov093_021D5F14
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5BDC 0x021D5BDC thumb ov093
 */
typedef unsigned char u8;
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *, unsigned int);
u8 func_021D5F14(struct UtilWork *p)
{
    u8 n;
    n = *((u8 *)p + 0x142);
    if (func_021D5BDC(p, 9)) {
        n += 2;
        if (n > 4) n = 4;
    }
    return n;
}
