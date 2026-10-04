/*
 * function: func_021DEFDC
 * address:  0x021DEFDC
 * packet:   pkt_021DEFDC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DFA6C  0x021DFA6C  arm
 *   func_021DF644  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *   g_021E4D08     0x021E4D08  data
 *
 * Same post shape as the func_021DF3B0 triplet, driven by the head of the
 * 0x021E4D08 control block instead of an incoming handle.
 */

typedef int s32;
typedef unsigned int u32;

extern int func_021DFA6C(int *p);
extern s32 func_021DF644(s32, s32);
extern void func_02059F54(s32, s32);
extern u32 g_021E4D08[];

s32 func_021DEFDC(void)
{
    s32 v = func_021DFA6C((int *)g_021E4D08[1]);

    if (v != 0)
        func_02059F54(8, func_021DF644(4, v));
    return v;
}
