/*
 * function: func_021DF458
 * address:  0x021DF458
 * packet:   pkt_021DF458
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DFE14  0x021DFE14  arm
 *   func_021DF5E4  0x021DF5E4  arm
 *   func_021DF644  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *
 * Sibling of func_021DF3B0 against the func_021DFE14 probe, with warning code
 * 0xd instead of 0xa.
 */

typedef int s32;

extern s32 func_021DFE14(s32);
extern s32 func_021DF5E4(s32);
extern s32 func_021DF644(s32, s32);
extern void func_02059F54(s32, s32);

s32 func_021DF458(s32 a)
{
    s32 v = func_021DFE14(a);

    if (v != 0)
        func_02059F54(func_021DF5E4(v), func_021DF644(0xd, v));
    return v;
}
