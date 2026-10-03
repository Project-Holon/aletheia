/*
 * function: func_021F6F50
 * address: 0x021F6F50
 * packet: pkt_ov097_021F6F50
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A48C 0x0204A48C arm
 *   d_021F764C 0x021F764C data a4
 *   d_021F761C 0x021F761C data a4
 */
struct Cfg { unsigned w[7]; };
extern const struct Cfg d_021F764C;
extern const unsigned d_021F761C[];
extern void func_0204A48C(const struct Cfg *, unsigned, unsigned);
void func_021F6F50(void)
{
    struct Cfg c = d_021F764C;
    func_0204A48C(&c, (unsigned)d_021F761C, 0x71);
}
