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
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GFL_NET_WM_ICON_SetDefaultPos  0x020371AC  arm
 *   NET_DEVICE_TABLE_Select  0x0200F17C  thumb
 *   NET_DEVICE_TABLE_Reset  0x0200F234  thumb
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

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void GFL_NET_WM_ICON_SetDefaultPos(unsigned short a, unsigned int b);
extern void GFL_NET_WM_ICON_EasyEnd(void);
extern int NET_DEVICE_TABLE_Select(u32 sel);
extern void NET_DEVICE_TABLE_Reset(u32 a);

void GFL_NET_SetupHeaps(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p = (u32 *)NET_DEVICE_TABLE_Select(1);
    u32 v = a;

    if (p != 0)
        ((void (*)(u32, u32))p[0])(a, b);

    NET_DEVICE_TABLE_Reset(1);

    if (c != d) {
        *(u16 *)0x021469E0 = (u16)d;
        GFL_HEAP_CreateChildHeap(c, d, 0x9E80);
    }

    GFL_NET_WM_ICON_SetDefaultPos(0, 0);
    GFL_NET_WM_ICON_EasyEnd();
}
