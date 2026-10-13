/*
 * function: GFL_NET_WM_ICON_EasyStart
 * address:  0x02037010
 * packet:   pkt_020366C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Rebuild the handler block held at +0x04 of the global at 0x021469C8 with
 * a nine-argument call to GFL_NET_WM_ICON_Create (four in registers, five on the
 * stack, which is what the 0x14-byte frame is for).  The two arms differ
 * only in the last four arguments: when a block already exists its three
 * carried fields are read out first and the old block is released by
 * GFL_NET_WM_ICON_EasyEnd, otherwise the mode bitfield at +0x02 is passed instead and
 * the last two arguments are the constants 0 and 3.
 *
 * The re-read of +0x04 for the sixth argument lands after the call to
 * GFL_NET_WM_ICON_EasyEnd, so it is a fresh load of the global, not the `h` that was
 * tested.
 *
 * symbols:
 *   GFL_NET_WM_ICON_ClearOam  0x02036FD8  arm
 *   GFL_NET_WM_ICON_EasyEnd  0x020370C8  arm
 *   GFL_NET_WM_ICON_Create  0x02036BD4  arm
 *   g_021469C8     0x021469C8  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_WM_ICON_EasyStart.c \
 *       --func GFL_NET_WM_ICON_EasyStart --addr 0x02037010 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Handler {
    u32 unk00;     /* 0x00 */
    u8  pad04[9];  /* 0x04 */
    u8  kind;      /* 0x0d */
    u8  busy;      /* 0x0e */
};

struct Notifier {
    u16 unk00;                /* 0x00 */
    u16 unk02 : 14;           /* 0x02, bits 0-13 */
    u16 mode  : 2;            /* 0x02, bits 14-15 */
    struct Handler *handler;  /* 0x04 */
};

extern struct Notifier g_021469C8;

extern int GFL_NET_WM_ICON_ClearOam(void);
extern void GFL_NET_WM_ICON_EasyEnd(void);
extern struct Handler *GFL_NET_WM_ICON_Create(u32 a, u32 b, u32 c, u32 d, u32 e,
                                     struct Handler *f, u32 g, u32 h, u32 i);

void GFL_NET_WM_ICON_EasyStart(u32 a, u32 b, u32 c, u32 d)
{
    struct Handler *h;

    GFL_NET_WM_ICON_ClearOam();

    h = g_021469C8.handler;

    if (h != 0) {
        u8  kind;
        u32 unk00;
        u8  busy;

        busy  = h->busy;
        kind  = h->kind;
        unk00 = h->unk00;

        GFL_NET_WM_ICON_EasyEnd();

        g_021469C8.handler = GFL_NET_WM_ICON_Create(0, d, a, b, c,
                                           g_021469C8.handler,
                                           kind, busy, unk00);
    } else {
        g_021469C8.handler = GFL_NET_WM_ICON_Create(0, d, a, b, c,
                                           h, g_021469C8.mode, 0, 3);
    }
}
