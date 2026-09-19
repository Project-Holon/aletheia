/*
 * function: func_020618E4
 * address:  0x020618E4
 * packet:   pkt_020618E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  +0018 PC24 func_0207FBBC           -> unresolved: 0207FBBC (arm, from name) has no witness outside 020618E4..02061908
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * PARKED AT MATCH: every concrete byte is right; the PC24 at +0x0018 is
 * wildcarded because 0x0207FBBC (GX_LoadClearImageColor) has exactly one
 * branch reference image wide and it is that call, so no cut of a
 * one-function range frees it.  Blocking evidence class: label/matched, no
 * outside witness -- the SDK table names the address but attest() has no
 * class that trusts a table alone.  It unsticks when the callee has its own
 * EXACT entry or a second caller.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020618E4.c \
 *       --func func_020618E4 --addr 0x020618E4 --arm --cc 1.1p1
 */

typedef unsigned int u32;

extern void func_0207FB2C(void);
extern void func_0207FBBC(u32 a, u32 c);
extern void func_0207FCE4(void);

void func_020618E4(u32 a, u32 b, u32 c)
{
    func_0207FB2C();
    func_0207FBBC(a, c);
    func_0207FCE4();
}
