/*
 * unit:     no
 * function: func_0203D34C
 * address:  0x0203D34C
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SetTimeout  0x0203D24C  arm
 *   GFL_NET_WM_ICON_EasySetScreen  0x02037118  arm
 *   GFL_NET_RestartByNetType  0x0203D2CC  arm
 *
 * TU: net.c.
 *
 * Three-call sequence: stamp the (0xf0, 0) pair into the state block, run
 * the transfer at 0x02037118 with this function's own two arguments, then
 * kick the state machine at 0x0203D2CC.  Both arguments have to outlive the
 * first call, which is what spends r5/r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D34C.c \
 *       --func func_0203D34C --addr 0x0203D34C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_NET_SetTimeout(u16 a, u16 b);
extern void GFL_NET_WM_ICON_EasySetScreen(u32 a, u32 b);
extern void GFL_NET_RestartByNetType(void);

void func_0203D34C(u32 a, u32 b)
{
    GFL_NET_SetTimeout(0xf0, 0);
    GFL_NET_WM_ICON_EasySetScreen(a, b);
    GFL_NET_RestartByNetType();
}
