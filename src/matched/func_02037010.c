/*
 * function: func_02037010
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
 * a nine-argument call to func_02036BD4 (four in registers, five on the
 * stack, which is what the 0x14-byte frame is for).  The two arms differ
 * only in the last four arguments: when a block already exists its three
 * carried fields are read out first and the old block is released by
 * func_020370C8, otherwise the mode bitfield at +0x02 is passed instead and
 * the last two arguments are the constants 0 and 3.
 *
 * The re-read of +0x04 for the sixth argument lands after the call to
 * func_020370C8, so it is a fresh load of the global, not the `h` that was
 * tested.
 *
 * symbols:
 *   func_02036FD8  0x02036FD8  arm
 *   func_020370C8  0x020370C8  arm
 *   func_02036BD4  0x02036BD4  arm
 *   g_021469C8     0x021469C8  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037010.c \
 *       --func func_02037010 --addr 0x02037010 --cc 1.1p1 --arm
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

extern void func_02036FD8(void);
extern void func_020370C8(struct Handler *h);
extern struct Handler *func_02036BD4(u32 a, u32 b, u32 c, u32 d, u32 e,
                                     struct Handler *f, u32 g, u32 h, u32 i);

void func_02037010(u32 a, u32 b, u32 c, u32 d)
{
    struct Handler *h;

    func_02036FD8();

    h = g_021469C8.handler;

    if (h != 0) {
        u8  kind;
        u32 unk00;
        u8  busy;

        busy  = h->busy;
        kind  = h->kind;
        unk00 = h->unk00;

        func_020370C8(h);

        g_021469C8.handler = func_02036BD4(0, d, a, b, c,
                                           g_021469C8.handler,
                                           kind, busy, unk00);
    } else {
        g_021469C8.handler = func_02036BD4(0, d, a, b, c,
                                           h, g_021469C8.mode, 0, 3);
    }
}
