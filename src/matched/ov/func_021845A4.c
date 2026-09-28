/*
 * function: func_021845A4
 * address:  0x021845A4
 * packet:   pkt_021845A4
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450C8  0x020450C8  arm
 *   func_02046788  0x02046788  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *
 * Addresses are Black-image addresses.
 */

extern int func_020450C8(int);
extern int func_02046788(int);
extern int func_0203F9B4(int);

void func_021845A4(int a)
{
    func_0203F9B4(func_02046788(func_020450C8(a)));
}
