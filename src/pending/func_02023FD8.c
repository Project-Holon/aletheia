/*
 * function: func_02023FD8
 * address:  0x02023FD8
 * packet:   pkt_02023F98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * blocker:  +000C THM_CALL func_02023E0C : 02023E0C (thumb) has no witness
 *           outside 02023FD8..02024004; the only two branches to it in the
 *           image are these two
 *
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * All 44 concrete bytes (30 of code, then three literal words) reproduce
 * exactly.  The listing extent is 108 because the next labelled start in
 * asm/arm9/src/008_02021014.s is 0x02024044; the 64 bytes between are the
 * unlabelled function at 0x02024004 and its pool, so the entry also carries
 * the `*` of a listing-extent mismatch.  The worklist size is 32 code bytes.
 *
 * Two guards on a global struct: the word at +0x3C first, then the word at
 * +0x1C, each calling func_02023E0C with a global address when it is set.
 *
 * The pool is THREE words and the first and third hold the same address
 * 0x021468FC.  mwccarm emits a pool word per source symbol, so a source that
 * reached the same object through one name would have CSEd the two loads into
 * one slot and one register (which is what the obvious spelling does: it
 * compares the field in r1 and reuses r0 for the call argument, 40 bytes).
 * The original loads the base twice, from two slots, so it is written here
 * with two names for the one address, g_021468FC for the field base and
 * g2_021468FC for the second call's argument.  That is the whole difference
 * between DIFF and MATCH here; both declarations are the same claim and both
 * are attested `literal` from outside (x6 from 0x02023F5C and friends).
 *
 * It cannot reach EXACT while func_02023E0C is unfiled: 0x02023E0C is
 * labelled in the listings but every branch to it image-wide is one of these
 * two, so the `label` class has no witness outside the compared range.  It
 * closes the day 0x02023E0C gets a manifest entry (a large function outside
 * the 0-64 byte band, so not this lane's work), and that also releases
 * src/pending/func_020052EC.c, whose first site names this address.
 *
 * symbols:
 *   g_021468FC    0x021468FC  data
 *   g2_021468FC   0x021468FC  data
 *   g_0214691C    0x0214691C  data
 *   func_02023E0C 0x02023E0C  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02023FD8.c \
 *       --func func_02023FD8 --addr 0x02023FD8 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 g_021468FC[];
extern u8 g2_021468FC[];
extern u8 g_0214691C[];

extern void func_02023E0C(void *p);

void func_02023FD8(void)
{
    if (*(u32 *)(g_021468FC + 0x3c) != 0) {
        func_02023E0C(g_0214691C);
    }
    if (*(u32 *)(g_021468FC + 0x1c) != 0) {
        func_02023E0C(g2_021468FC);
    }
}
