/*
 * function: func_0203D798
 * address:  0x0203D798
 * packet:   pkt_0203D798
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_021469E0  0x021469E0  data
 *
 * Accessor for the +8 handle of the singleton at 0x021469E0, with the null
 * case spelled out.  The `moveq r0, #0` is a no-op on the value it guards,
 * so it is only there because the source writes the null return
 * explicitly; a plain `return g->unk_08;` loses the `cmp` and the `moveq`
 * and is eight bytes short.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203D7C8 because the
 * follower at 0x0203D7B0 has no label.  It is not a byte difference; the
 * follower is a pair of eight-byte ARM long-branch veneers (0x0203D7B0 ->
 * 0x0203C8E8 and 0x0203D7BC -> 0x0203C900), which save no lr and so are
 * invisible to disasm.py.  Both want seeding into
 * layout/function_starts.txt, which is the integrator's file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D798.c \
 *       --func func_0203D798 --addr 0x0203D798 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct Singleton {
    u8    pad_00[8];
    void *unk_08;
};

extern struct Singleton g_021469E0;

void *func_0203D798(void)
{
    if (g_021469E0.unk_08 == 0) {
        return 0;
    }
    return g_021469E0.unk_08;
}
