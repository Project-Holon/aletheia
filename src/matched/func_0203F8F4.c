/*
 * unit:     no
 * function: func_0203F8F4
 * address:  0x0203F8F4
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   g_020A7E5C     0x020A7E5C  data
 *   sub_02030734   0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02033C00  0x02033C00  arm
 *
 * TU: bg_sys.c.
 *
 * Constructor for the background system: one 0x1d0-byte allocation, zeroed,
 * with two 0x1000-byte scratch buffers and three parallel eight-entry
 * tables at +0x170, +0x190 and +0x1b0.  Every access after the first goes
 * through a fresh load of the global, because each call in between may
 * write it; only the `func_02082BCC` argument is forwarded from the
 * allocator's return value, since nothing has been called since the store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F8F4.c \
 *       --func func_0203F8F4 --addr 0x0203F8F4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct BgSys {
    u16   heapId;
    u8    pad_02[2];
    u16   unk_04;
    u16   unk_06;
    u8    pad_08[0x160];
    void *unk_168;
    void *unk_16c;
    u32   unk_170[8];
    u32   unk_190[8];
    u32   unk_1b0[8];
};

extern struct BgSys *g_02146A44;
extern char g_020A7E5C[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void  func_02082BCC(void *dst, u32 value, u32 size);
extern void *func_02033C00(u32 size, u32 heapId);

void func_0203F8F4(u16 heapId)
{
    s32 i;

    g_02146A44 = sub_02030734(heapId, 0x1d0, 0, g_020A7E5C, 134);
    func_02082BCC(g_02146A44, 0, 0x1d0);
    g_02146A44->heapId = heapId;
    g_02146A44->unk_04 = 0;
    g_02146A44->unk_06 = 0;
    g_02146A44->unk_168 = func_02033C00(0x1000, heapId);
    g_02146A44->unk_16c = func_02033C00(0x1000, heapId);

    for (i = 0; i < 8; i++) {
        g_02146A44->unk_170[i] = 0;
        g_02146A44->unk_190[i] = 0;
        g_02146A44->unk_1b0[i] = 0;
    }
}
