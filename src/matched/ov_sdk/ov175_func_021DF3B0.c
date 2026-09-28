/*
 * function: func_021DF3B0
 * address:  0x021DF3B0
 * packet:   pkt_021DF3B0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DFD18  0x021DFD18  arm
 *   func_021DF5E4  0x021DF5E4  arm
 *   func_021DF644  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *
 * Probe-then-post: ask the byte-read entry for the record, and when it came
 * back non-zero post the warning (func_021DF644(10, v)) against the value
 * func_021DF5E4 picked.  The record handle is the return value either way.
 */

typedef int s32;

extern s32 func_021DFD18(s32);
extern s32 func_021DF5E4(s32);
extern s32 func_021DF644(s32, s32);
extern void func_02059F54(s32, s32);

s32 func_021DF3B0(s32 a)
{
    s32 v = func_021DFD18(a);

    if (v != 0)
        func_02059F54(func_021DF5E4(v), func_021DF644(10, v));
    return v;
}
