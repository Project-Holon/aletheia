/*
 * file:     net_state_p34.c
 * unit:     yes
 * function: func_0203D798, func_0203D7B0
 * address:  0x0203D798
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469E0  0x021469E0  data
 *   func_0203C8E8  0x0203C8E8  arm
 */
typedef unsigned char u8;

struct Singleton {
    u8    pad_00[8];
    void *unk_08;
};

extern void func_0203C8E8(u8 v);
void *func_0203D798(void);
void func_0203D7B0(u8 a0);
extern struct Singleton g_021469E0;


/*
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
void *func_0203D798(void)
{
    if (g_021469E0.unk_08 == 0) {
        return 0;
    }
    return g_021469E0.unk_08;
}


/*
 *           prologue is `ldr r1, [pc, #0xc]` and saves no lr, so disasm.py
 *           emitted no func_ label there (the unlabelled-leaf idiom) and
 *           evidence().labels has no entry.  sole-ref/code therefore refuses
 *           it, veneer_at() does not recognise it, and the pool word under
 *           test is the only reference to it in the image, so `literal` and
 *           `label` both discard their only witness.  All 12 bytes are
 *           correct.  It becomes EXACT the moment 0x0203C8E8 is seeded into
 *           layout/function_starts.txt (the integrator's file) or a second
 *           referrer is decompiled.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_0203D7B0.c \
 *       --func func_0203D7B0 --addr 0x0203D7B0 --cc 1.1p1 --arm
 */
void func_0203D7B0(u8 a0)
{
    func_0203C8E8(a0);
}
