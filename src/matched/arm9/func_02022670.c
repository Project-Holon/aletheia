/*
 * function: func_02022670
 * address:  0x02022670
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-screen finaliser, the mirror of the arming path in func_02022640: it
 * runs only while the screen is in state 1, its resolved sentinel value at
 * +0x24 is the pass-through 0x7FFF or zero, and the second handle at +0x2C is
 * still null.  It then closes the screen's window through the pointer at
 * +0x10, first the flush at 0x0202223C and then the release thunk at
 * 0x02022224.
 *
 * The +0x10 field is re-read for the second call rather than kept in a
 * register, because the first call can alias it; a cached local would drop
 * the second `ldr`.
 *
 * symbols:
 *   func_0202223C  0x0202223C  thumb
 *   func_02022224  0x02022224  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022670.c \
 *       --func func_02022670 --addr 0x02022670 --cc 1.1p1 --thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Screen {
    u8    pad00[0x10];
    void *f10;
    u8    pad14[0x10];
    u16   f24;
    u16   f26;
    u32   f28;
    void *f2C;
};

extern void func_0202223C(void *win, u32 color);
extern u32 func_02022224(void *win);

void func_02022670(struct Screen *s)
{
    if (s->f28 == 1 && (s->f24 == 0x7FFF || s->f24 == 0) && s->f2C == 0) {
        func_0202223C(s->f10, s->f24);
        func_02022224(s->f10);
    }
}
