/*
 * function: func_021DF3E8
 * address:  0x021DF3E8
 * packet:   pkt_021DF3E8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DFDFC  0x021DFDFC  arm
 *   func_021DF5E4  0x021DF5E4  arm
 *   func_021DF644  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *
 * Sibling of func_021DF3B0 against the func_021DFDFC probe: post
 * func_021DF644(10, v) against func_021DF5E4(v) when the probe reports.
 */

typedef int s32;

extern s32 func_021DFDFC(s32);
extern s32 func_021DF5E4(s32);
extern s32 func_021DF644(s32, s32);
extern void func_02059F54(s32, s32);

s32 func_021DF3E8(s32 a)
{
    s32 v = func_021DFDFC(a);

    if (v != 0)
        func_02059F54(func_021DF5E4(v), func_021DF644(10, v));
    return v;
}
