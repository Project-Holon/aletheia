/*
 * function: func_02021464
 * address:  0x02021464
 * packet:   pkt_02021464
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Palette-animation tick pump.  g_02146788 is the same state block
 * func_02021444 resets; unk_04, unk_0c and tick are 4-aligned u64 fields
 * (docs/idioms/long-long-aligns-to-four.md).  The divisor 0x01FF6210 is the
 * OS tick-to-unit scale applied after a <<6, through _ll_udiv
 * (docs/idioms/runtime-helper-reloc.md).
 *
 * The last four bytes were the arm order: the equal case is written first
 * so the `bne` reaches the OS_GetTick arm
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021464.c \
 *       --func func_02021464 --addr 0x02021464 --cc 1.1p1 --thumb
 *
 * symbols:
 *   g_02146788  0x02146788  data
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv    0x0209C00C  arm
 */

typedef unsigned char      u8;
typedef unsigned int       u32;
typedef unsigned long long u64;

struct PalAnmState {
    u32 unk_00;
    u64 unk_04;
    u64 unk_0c;
    u64 tick;
};

extern struct PalAnmState g_02146788;
extern u64 OS_GetTick(void);
extern u32 func_02012FBC(u8 *p, u32 x);

void func_02021464(u8 *p)
{
    u64 t;
    u64 v;

    if (g_02146788.unk_00 == 0) {
        return;
    }
    t = OS_GetTick();
    if (t < g_02146788.unk_04) {
        t = t + g_02146788.unk_04;
    } else {
        g_02146788.unk_04 = t;
    }
    v = ((t - g_02146788.tick) << 6) / 0x01FF6210;
    if (g_02146788.unk_0c >= v) {
        return;
    }
    func_02012FBC(p, (u32)(v - g_02146788.unk_0c));
    if (g_02146788.unk_04 == t) {
        g_02146788.unk_0c = v;
    } else {
        t = OS_GetTick();
        g_02146788.tick = t;
        g_02146788.unk_0c = (t << 6) / 0x01FF6210;
        g_02146788.unk_04 = t;
    }
}
