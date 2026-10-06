/*
 * function: func_021DF420
 * address:  0x021DF420
 * packet:   pkt_021DF420
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DFE08  0x021DFE08  arm
 *   func_021DF5E4  0x021DF5E4  arm
 *   func_021DF644  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *
 * Sibling of func_021DF3B0 against the func_021DFE08 probe.
 */

typedef int s32;

extern s32 func_021DFE08(s32);
extern s32 func_021DF5E4(s32);
extern s32 func_021DF644(s32, s32);
extern void func_02059F54(s32, s32);

s32 func_021DF420(s32 a, int a1, int a2)
{
    s32 v = func_021DFE08(a);

    if (v != 0)
        func_02059F54(func_021DF5E4(v), func_021DF644(10, v));
    return v;
}
