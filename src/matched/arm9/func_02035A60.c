/*
 * Previously parked at MATCH: the `bl` to 0x020358A0 had no outside witness.
 * Closed 2026-09-22 (family wave 5) when 0x020358A0 was itself decompiled to
 * EXACT in src/matched/func_020358A0.c; that manifest entry is now the
 * witness and the site resolves on class `matched`.
 *
 * function: func_02035A60
 * address:  0x02035A60
 * packet:   pkt_02035760
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224  0x02035224  arm
 *   func_020358A0  0x020358A0  arm
 *
 * Two calls in a row, the second one's result returned through the shared
 * `pop {r3, pc}`.  Nothing else: no stack frame, no locals.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035A60.c \
 *       --func func_02035A60 --addr 0x02035A60 --cc 1.1p1 --arm
 */

extern void func_02035224(void);
extern void func_020358A0(void);

void func_02035A60(void)
{
    func_02035224();
    func_020358A0();
}
