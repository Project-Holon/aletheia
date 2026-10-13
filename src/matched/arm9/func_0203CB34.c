/*
 * function: GFL_NET_SetupHeaps
 * address:  0x0203CB34
 * packet:   pkt_0203CB34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_WM_ICON_EasyEnd  0x020370C8  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SetupHeaps.c \
 *       --func GFL_NET_SetupHeaps --addr 0x0203CB34 --cc 1.1p1 --arm
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern void func_0203064C(u32 a, u32 b, u32 c);
extern void func_020371AC(unsigned short a, unsigned int b);
extern void GFL_NET_WM_ICON_EasyEnd(void);
extern int func_0200F17C(u32 sel);
extern void func_0200F234(u32 a);

void GFL_NET_SetupHeaps(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = (u32 *)func_0200F17C(1);
    u32 v = a;

    if (p != 0)
        ((void (*)(u32, u32))p[0])(a, b);

    func_0200F234(1);

    if (c != d) {
        *(u16 *)0x021469E0 = (u16)d;
        func_0203064C(c, d, 0x9E80);
    }

    func_020371AC(0, 0);
    GFL_NET_WM_ICON_EasyEnd();
}
