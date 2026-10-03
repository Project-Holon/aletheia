/*
 * function: func_02036BD4
 * address:  0x02036BD4
 * packet:   pkt_020366C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TU: wm_icon.c.  The __FILE__ pointer at 0x020A79F0 reads "wm_icon.c"
 * (line 100 here), which names the whole 0x020366C0-0x020371AC block: the
 * wireless-connection icon.
 *
 * Nine parameters, four in registers and five on the stack, and the first
 * one is never read: every caller passes 0 there.  When the caller hands in
 * a null block, a fresh 0x14-byte one is allocated on the heap named by the
 * low 15 bits of the second argument with bit 15 forced on.  The two
 * halfwords at +0x04 / +0x06 take the caller's values unless the override
 * pair in the global at 0x021469C8 is armed, in which case the whole `if`
 * body is predicated rather than branched.
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   func_02036D64   0x02036D64  arm
 *   func_02036F24   0x02036F24  arm
 *   wm_icon_File    0x020A79F0  data
 *   g_021469C8      0x021469C8  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036BD4.c \
 *       --func func_02036BD4 --addr 0x02036BD4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Handler {
    u32 unk00;      /* 0x00 */
    u16 unk04;      /* 0x04 */
    u16 unk06;      /* 0x06 */
    u8  pad08[4];   /* 0x08 */
    u8  unk0c;      /* 0x0c */
    u8  kind;       /* 0x0d */
    u8  busy;       /* 0x0e */
    u8  unk0f;      /* 0x0f */
    u32 unk10;      /* 0x10 */
};

struct Notifier {
    u16 unk00;                /* 0x00 */
    u16 unk02 : 14;           /* 0x02, bits 0-13 */
    u16 mode  : 2;            /* 0x02, bits 14-15 */
    struct Handler *handler;  /* 0x04 */
};

extern struct Notifier g_021469C8;
extern const char wm_icon_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32  func_02036D64(struct Handler *h, u32 a);
extern void func_02036F24(int a0, int b, int c);

struct Handler *func_02036BD4(u32 unused, u32 b, u32 c, u32 d, u32 e,
                              struct Handler *h, u32 kind, u32 busy,
                              u32 unk00)
{
    if (h == 0)
        h = func_02030734((u16)(((u16)b & 0x7fff) | 0x8000), 0x14, 0,
                          wm_icon_File, 100);

    h->unk04 = c;
    h->unk06 = d;

    if (g_021469C8.unk00 != 0) {
        h->unk04 = g_021469C8.unk00;
        h->unk06 = g_021469C8.unk02;
    }

    h->unk00 = unk00;
    h->unk0c = e;
    h->busy  = busy;
    h->kind  = kind;
    h->unk0f = 0;
    h->unk10 = 0x7000000;

    func_02036F24(func_02036D64(h, 0x7000000), h->unk0c, (u16)b);
    return h;
}
