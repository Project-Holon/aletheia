/*
 * Previously parked at MATCH: the `bl` to 0x020358A0 had no outside witness.
 * Closed 2026-09-22 (family wave 5) when 0x020358A0 was itself decompiled to
 * EXACT in src/matched/TOUCHPANEL_MainSys.c; that manifest entry is now the
 * witness and the site resolves on class `matched`.
 *
 * function: TOUCHPANEL_Main
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
 *   TOUCHPANEL_MainSys  0x020358A0  arm
 *
 * Two calls in a row: the first one's result is the second one's argument,
 * handed over in r0 with nothing in between.  Nothing else: no stack frame,
 * no locals.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TOUCHPANEL_Main.c \
 *       --func TOUCHPANEL_Main --addr 0x02035A60 --cc 1.1p1 --arm
 */

struct UiCtx;
extern struct UiCtx *func_02035224(void);
struct Tp;
extern void TOUCHPANEL_MainSys(struct Tp *ctx);

void TOUCHPANEL_Main(void)
{
    TOUCHPANEL_MainSys((struct Tp *)func_02035224());
}
