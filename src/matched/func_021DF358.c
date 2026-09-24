/*
 * function: func_021DF358
 * address:  0x021DF358
 * packet:   pkt_021DF358
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DFD24  0x021DFD24  arm
 *   func_021DF644  0x021DF644  arm
 *   func_02059F54  0x02059F54  arm
 *
 * Eight-argument form of the func_021DF3B0 post shape: the four register
 * arguments are forwarded, and the stack arguments become (a4, a5->f18, a5,
 * a6) on the outgoing frame.  Same warning post and same returned handle.
 */

typedef int s32;

extern s32 func_021DFD24(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_021DF644(s32, s32);
extern void func_02059F54(s32, s32);

s32 func_021DF358(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, char *a5, s32 a6)
{
    s32 v = func_021DFD24(a0, a1, a2, a3, a4, *(s32 *)(a5 + 0x18), (s32)a5, a6);

    if (v != 0)
        func_02059F54(8, func_021DF644(10, v));
    return v;
}
