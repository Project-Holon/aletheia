/*
 * unit:     no
 * function: PALANM_StartTimer
 * address:  0x02021444
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146788  0x02146788  data
 *   OS_GetTick  0x020870D0  arm
 *
 * Reset the palette-animation module state block and stamp it with the
 * current tick.  The same global's first word is the one PALANM_StopTimer
 * clears, so the block is a struct starting at 0x02146788, not five
 * unrelated globals.
 *
 * The tick is a `u64` field at +0x14: OS_GetTick returns the pair in r0:r1
 * and both halves are stored with plain word stores at +0x14 and +0x18,
 * which is a 4-aligned `long long`
 * (docs/idioms/long-long-aligns-to-four.md), not two `u32`s assigned from a
 * split helper.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_StartTimer.c \
 *       --func PALANM_StartTimer --addr 0x02021444 --cc 1.1p1 --thumb
 */

typedef unsigned int       u32;
typedef unsigned long long u64;

struct PalAnmState {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u64 tick;
};

extern struct PalAnmState g_02146788;

extern u64 OS_GetTick(void);

void PALANM_StartTimer(void)
{
    g_02146788.unk_00 = 1;
    g_02146788.unk_04 = 0;
    g_02146788.unk_08 = 0;
    g_02146788.unk_0c = 0;
    g_02146788.unk_10 = 0;
    g_02146788.tick = OS_GetTick();
}
