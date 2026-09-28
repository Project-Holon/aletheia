/*
 * function: func_0202B174
 * address:  0x0202B174
 * packet:   pkt_0202AF74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   _s32_to_double  0x0209B750  arm
 *   func_0209AC04   0x0209AC04  arm
 *   _d2s            0x0209C508  arm
 */
typedef int s32;
typedef unsigned int u32;

extern double _s32_to_double(s32 v);
extern double func_0209AC04(double a, double b);
extern s32    _d2s(double d);

s32 func_0202B174(u32 *a0)
{
    return _d2s(func_0209AC04(8.0, _s32_to_double((s32)(a0[3] << 4))));
}
