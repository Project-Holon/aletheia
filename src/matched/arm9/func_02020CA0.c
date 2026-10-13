/*
 * function: BMP_MENULIST_ShiftWindow
 * address:  0x02020CA0
 * packet:   pkt_02020A58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   func_0204169C  0x0204169C  arm
 *   BMP_MENULIST_ShiftChars4bpp  0x02020A58  thumb
 *   BMP_MENULIST_ShiftChars8bpp  0x02020B5C  thumb
 *
 * UNBLOCKED 2026-09-21: the two THM_CALL sites at +0x36 and +0x4e now
 * attest `matched` off src/matched/BMP_MENULIST_ShiftChars4bpp.c and the newly filed
 * src/matched/BMP_MENULIST_ShiftChars8bpp.c.  All 5 relocation sites resolve and the
 * verdict is EXACT*; promoted from src/pending/ unchanged apart from
 * this header.  EXACT* only because 0x02020CF8 has no label.
 *
 * Window-fill front end.  The window descriptor names a BG channel
 * (BMP_WIN_GetBgLayer, the +2 accessor) and carries the bitmap it draws into
 * (BMP_WIN_GetBmp, the +0xc handle).  func_0204169C says whether that
 * channel is 8bpp; the 4bpp path calls BMP_MENULIST_ShiftChars4bpp and the 8bpp path
 * BMP_MENULIST_ShiftChars8bpp, and the caller's tile offset is converted to a byte
 * offset by the depth: (t & 0x7ff) << 5 for 4bpp, (t & 0x3ff) << 6 for
 * 8bpp, i.e. 32 or 64 bytes per tile.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_ShiftWindow.c \
 *       --func BMP_MENULIST_ShiftWindow --addr 0x02020CA0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u8 func_0204169C(int channel);
extern void  BMP_MENULIST_ShiftChars4bpp(void *bmp, u32 a, u32 b, u32 c, u32 off);
extern void  BMP_MENULIST_ShiftChars8bpp(void *bmp, u32 a, u32 b, u32 c, u32 off);

void BMP_MENULIST_ShiftWindow(void *win, u32 a, u32 b, u32 c, u16 tile)
{
    int   channel;
    void *bmp;

    channel = BMP_WIN_GetBgLayer(win);
    bmp = BMP_WIN_GetBmp(win);

    if (func_0204169C(channel) == 0)
        BMP_MENULIST_ShiftChars4bpp(bmp, a, b, c, (u32)(tile << 21) >> 16);
    else
        BMP_MENULIST_ShiftChars8bpp(bmp, a, b, c, (u32)(tile << 22) >> 16);
}
