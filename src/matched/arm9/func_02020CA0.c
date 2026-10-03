/*
 * function: func_02020CA0
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
 *   func_02045730  0x02045730  arm
 *   func_02045770  0x02045770  arm
 *   func_0204169C  0x0204169C  arm
 *   func_02020A58  0x02020A58  thumb
 *   func_02020B5C  0x02020B5C  thumb
 *
 * UNBLOCKED 2026-09-21: the two THM_CALL sites at +0x36 and +0x4e now
 * attest `matched` off src/matched/func_02020A58.c and the newly filed
 * src/matched/func_02020B5C.c.  All 5 relocation sites resolve and the
 * verdict is EXACT*; promoted from src/pending/ unchanged apart from
 * this header.  EXACT* only because 0x02020CF8 has no label.
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

struct Descriptor;
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
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
