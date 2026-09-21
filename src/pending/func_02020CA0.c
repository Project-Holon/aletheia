/*
 * function: func_02020CA0
 * address:  0x02020CA0
 * packet:   pkt_02020A58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 *
 * symbols:
 *   func_02045730  0x02045730  arm
 *   func_02045770  0x02045770  arm
 *   func_0204169C  0x0204169C  arm
 *   func_02020A58  0x02020A58  thumb
 *   func_02020B5C  0x02020B5C  thumb
 *
 * Blocked at MATCH: every concrete byte is right, but the two THM_CALL
 * sites at +0x36 and +0x4e (func_02020A58 and func_02020B5C) have no
 * witness outside 0x02020CA0..0x02020CF6.  This function is the only
 * caller of either in the whole image, so neither `label` nor `matched`
 * can attest them until func_02020A58 / func_02020B5C are themselves
 * filed EXACT; --suggest-split cannot help, since the range is one
 * function.  Blocking evidence class: none available (needs a second
 * caller, or an EXACT manifest entry at 0x02020A58 / 0x02020B5C).
 *
 * Window-fill front end.  The window descriptor names a BG channel
 * (func_02045730, the +2 accessor) and carries the bitmap it draws into
 * (func_02045770, the +0xc handle).  func_0204169C says whether that
 * channel is 8bpp; the 4bpp path calls func_02020A58 and the 8bpp path
 * func_02020B5C, and the caller's tile offset is converted to a byte
 * offset by the depth: (t & 0x7ff) << 5 for 4bpp, (t & 0x3ff) << 6 for
 * 8bpp, i.e. 32 or 64 bytes per tile.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020CA0.c \
 *       --func func_02020CA0 --addr 0x02020CA0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8    func_02045730(void *win);
extern void *func_02045770(void *win);
extern u8    func_0204169C(int channel);
extern void  func_02020A58(void *bmp, u32 a, u32 b, u32 c, u32 off);
extern void  func_02020B5C(void *bmp, u32 a, u32 b, u32 c, u32 off);

void func_02020CA0(void *win, u32 a, u32 b, u32 c, u16 tile)
{
    int   channel;
    void *bmp;

    channel = func_02045730(win);
    bmp = func_02045770(win);

    if (func_0204169C(channel) == 0)
        func_02020A58(bmp, a, b, c, (u32)(tile << 21) >> 16);
    else
        func_02020B5C(bmp, a, b, c, (u32)(tile << 22) >> 16);
}
