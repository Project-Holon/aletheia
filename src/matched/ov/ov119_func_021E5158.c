/*
 * function: func_021E5158
 * address:  0x021E5158
 * packet:   pkt_021E5158
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * Signed remainder by 12.  The MSL divide helper returns the quotient in r0
 * and the remainder in r1, so `x % 12` moves r1 down to r0.
 */

typedef int s32;

extern s32 _s32_div_f(s32 num, s32 den);

s32 func_021E5158(s32 x)
{
    return x % 12;
}
