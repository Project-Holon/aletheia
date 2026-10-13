/*
 * function: GFL_NET_WM_ICON_EasySetScreen
 * address:  0x02037118
 * packet:   pkt_020366C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Notifier fan-out.  The first call is told which of two kinds of event
 * this is by testing the first argument (`movs r5, r0` sets the flags and
 * saves the argument in one instruction, which is why the ternary costs
 * nothing), and the second call only happens when the handler slot at
 * +0x04 of the global at 0x021469C8 is populated; both of this function's
 * own arguments are forwarded to it, which is what spends r5 and r4.
 *
 * symbols:
 *   GFL_NET_WM_ICON_SetDefaultScreen  0x020371D8  arm
 *   GFL_NET_WM_ICON_SetScreen  0x02036EC8  arm
 *   g_021469C8     0x021469C8  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_WM_ICON_EasySetScreen.c \
 *       --func GFL_NET_WM_ICON_EasySetScreen --addr 0x02037118 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Notifier {
    u32   unk00;   /* 0x00 */
    void *handler; /* 0x04 */
};

extern struct Notifier g_021469C8;

extern void GFL_NET_WM_ICON_SetDefaultScreen(u32 kind);
struct Handler;
extern void GFL_NET_WM_ICON_SetScreen(struct Handler *p, u32 a, u32 b);

void GFL_NET_WM_ICON_EasySetScreen(u32 a, u32 b)
{
    GFL_NET_WM_ICON_SetDefaultScreen(a != 0 ? 1 : 2);

    if (g_021469C8.handler != 0)
        GFL_NET_WM_ICON_SetScreen(g_021469C8.handler, a, b);
}
