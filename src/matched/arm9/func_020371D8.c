/*
 * function: GFL_NET_WM_ICON_SetDefaultScreen
 * address:  0x020371D8
 * packet:   pkt_020371AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Setter for the two-bit mode field in the top of the halfword at +0x02 of
 * the global at 0x021469C8.  The `lsl #0x1e` plus the `lsr #16` shifter
 * operand on the `orr` is the bitfield insert, and the `bic` of 0xc000 is
 * the field's own mask.  The `lsl #0x10 / lsr #0x10` pair above it is an
 * explicit `(u16)` cast on the stored value: declaring the parameter `u16`
 * instead drops the pair entirely (the insert already masks), so the cast
 * has to be written out.  See
 * docs/idioms/an-explicit-narrowing-cast-into-a-bitfield-is-not-folded.md.
 *
 * symbols:
 *   g_021469C8  0x021469C8  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_WM_ICON_SetDefaultScreen.c \
 *       --func GFL_NET_WM_ICON_SetDefaultScreen --addr 0x020371D8 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Notifier {
    u16   unk00;      /* 0x00 */
    u16   unk02 : 14; /* 0x02, bits 0-13 */
    u16   mode  : 2;  /* 0x02, bits 14-15 */
    void *handler;    /* 0x04 */
};

extern struct Notifier g_021469C8;

void GFL_NET_WM_ICON_SetDefaultScreen(u32 mode)
{
    g_021469C8.mode = (u16)mode;
}
