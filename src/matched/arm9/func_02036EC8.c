/*
 * function: GFL_NET_WM_ICON_SetScreen
 * address:  0x02036EC8
 * packet:   pkt_020366C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stamp the two status bytes at +0x0d / +0x0e of the handler block, then
 * feed the result of GFL_NET_WM_ICON_GetEngine straight into GFL_NET_WM_ICON_LoadGraphics.  The `mov
 * r1, #1` is shared between the store to +0x0e and the second argument of
 * the first call, which is why the constant is not rematerialised.  The
 * byte at +0x0c is loaded after the first call, so it is an argument
 * expression of the second call, not a value cached before it.
 *
 * symbols:
 *   GFL_NET_WM_ICON_GetEngine  0x02036D64  arm
 *   GFL_NET_WM_ICON_LoadGraphics  0x02036F24  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_WM_ICON_SetScreen.c \
 *       --func GFL_NET_WM_ICON_SetScreen --addr 0x02036EC8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Handler {
    u8 unk00[0x0c]; /* 0x00 */
    u8 unk0c;       /* 0x0c */
    u8 kind;        /* 0x0d */
    u8 busy;        /* 0x0e */
};

extern u32 GFL_NET_WM_ICON_GetEngine(u8 *p);
extern void GFL_NET_WM_ICON_LoadGraphics(int a0, int b, int c);

void GFL_NET_WM_ICON_SetScreen(struct Handler *p, u32 a, u32 b)
{
    p->kind = (a != 0) ? 1 : 2;
    p->busy = 1;

    GFL_NET_WM_ICON_LoadGraphics(GFL_NET_WM_ICON_GetEngine((u8 *)p), p->unk0c, b);
}
