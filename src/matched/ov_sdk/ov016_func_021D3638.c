/*
 * function: func_021D3638
 * address:  0x021D3638
 * packet:   pkt_ov016_021D3638
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * closed 2026-10-01 (ov SDK wave 4): the tail is `switch (call) { case 0:
 *   return 0; default: return 1; }`. Vendor .debug_line puts moveq on its own
 *   line (2567) and movne on 2570, i.e. two return statements; a two-return
 *   switch is the only 1.1p1 shape whose if-converted select writes r0 in both
 *   arms (if/else, ternary, goto, local forms all coalesce the result onto a
 *   constant register). The history below is superseded.
 *
 * blocker:  5 concrete bytes (2 instructions), correct size 120/120.  The
 *           vendor object dwc_mov_wh.o is .comment 4.0.0.1025, for which no
 *           tools/mwccarm build maps (1.1p1 is 1024); every emitted instruction
 *           matches except the if-converted boolean select at +0068, where the
 *           object writes the result into r0 (`moveq r0,r5; movne r0,r4`) and
 *           1.1p1 coalesces it into the r5 zero constant (`movne r5,r4; mov
 *           r0,r5`).  Both orderings are reachable only by flipping the 0/1
 *           constant registers.  The function has no local in the vendor DWARF,
 *           so it is a direct return; ~30 spellings re-tried this pass, and a
 *           400-candidate permuter run found no single mutation that improves it.
 *
 * w9_nm: still 5 B. Also tried: the ternary with no local, one/zero locals selected by a ternary, result from a local then a ternary, early return of r or 1.
 *
 * sdk:      DWCi_MOV_WH_Initialize (libdwcutil.TWL.HYB.a(dwc_mov_wh.o))
 *
 * w6_nm tried: goto-spelled exits with a shared return label (both senses),
 * a result local via goto, unsigned char return/callee types: register roles unchanged.
 *
 * w8_nm: `int r = 0; ... if (call) r = 1; return r;` puts 0 in r5 and 1 in r4 as
 * in the object (15 B -> 5 B). Left: the object returns with `moveq r0,r5;
 * movne r0,r4`, this compile with `movne r5,r4; mov r0,r5`. The result local is
 * not in the DWARF. Tried: `? 1 : 0`, `!!`, `!= 0`, if/else returns in both
 * senses, r = 1 then clear, if/else assignment, the call result in a local,
 * cc 1.1, 1.2, 1.2p1, 1.3.
 *
 * T6: still 5 B - the select's destination register. Object `moveq r0,r5 /
 * movne r0,r4`; this build `movne r5,r4 / mov r0,r5` (the result coalesces
 * into the r5 zero constant). 14 spellings re-run: if/return without else in
 * both senses, if/else returns, `r = c ? 1 : 0;` at declaration and after the
 * stores, `(c != 0)`, one/zero locals, `if (c) r = 1; else r = 0;` - every one
 * either flips the constant assignment to r4=0/r5=1 or keeps the result in
 * r5. Only `int r = 0; if (c) r = 1; return r;` keeps the object's r5=0/r4=1
 * ordering, and that is the shape whose result coalesces. A sweep over all
 * nine pins x seven flag sets x inline/ipa variants is D5 in every cell.
 * U26: 8 further tail spellings (bare ternary, assignment-ternary, `!= 0`, `!!`, if/else in both
 * senses, braced single-arm if, do/while(0), temp local, `return c ? 1 : r` with r == 0) - every
 * one either flips the constants (0 to r4, 1 to r5, 15 B out) or keeps the result coalesced into
 * r5 with the copy to r0 (5 B out).  The 2-instruction residue is the if-converted select's
 * destination register, not a statement shape.
 *
 * wave8: confirmed the residue is the if-converted select's DESTINATION
 * register, not a statement shape.  This pass (20+ spellings: direct `? 1 : 0`
 * and `? B_TRUE : B_FALSE` returns, if/else returns and assignments in both arm
 * orders and both senses, enum-constant ternary and enum-typed locals, u8/int
 * return types, `static`, `int r = f(); r = r ? 1 : 0;` dying-local, `!= 0`,
 * `!!`) all land in one of two classes: keep r5=0/r4=1 and coalesce the select
 * into r5 with the trailing `mov r0,r5` (5 B), or flip the constants (0->r4,
 * 1->r5, 15 B).  Only `int r = 0; if (c) r = 1; return r;` keeps the object's
 * r5=0/r4=1 colouring, and that is the shape whose result coalesces.  The
 * vendor build writes both predicated moves straight into r0
 * (`moveq r0,r5; movne r0,r4`); 1.1p1 coalesces the result onto the live zero
 * constant.  No C-level lever moves it.  See
 * docs/idioms/an-if-converted-selects-destination-register-is-the-front-ends.md
 *
 * w8 (this lane): 3 further tail spellings, all the same two classes.  A
 * `switch (call) { case 0: r = 0; break; default: r = 1; }` emitted the exact
 * 5-B coalesced form as the committed shape, and `r = call ? 1 : r;` (r == 0
 * false arm) flipped the constants to r4=0/r5=1 for 15 B.  No new lever.
 *
 * 2026-10-01 (ov SDK wave 2): wh_trace/wh are now the object's two .bss statics
 *   (wh_trace +0, wh +4) instead of one extern struct: inert, still 5 B. Also inert:
 *   the callee as a TU static with a body (IPA-visible); ternary and if-return
 *   tails re-measured with the statics (15 B).
 *
 * 2026-10-01 (w3 lane19): still 5 B. Vendor .o has no aligned section (no
 *   asm-mode lever); re-measured `return call ? 1 : 0` (coalesces onto the 1
 *   register instead, 15 B). No new lever.
 *
 * symbols:
 *   DWCi_MOV_WH_StateInInitialize    0x021D36D0  arm  ov016
 *   wh_trace                         0x021DE660  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u32 f0;
    u16 f4;
    u8 pad0[0x48 - 6];
    u32 f48;
    u32 f4c;
    u16 f50;
    u16 f52;
    u32 f54;
    u8 pad1[0x12a0 - 0x58];
    u32 f12a0;
    u32 f12a4;
} Wh;

static void *wh_trace = 0;
static Wh *wh = 0;
extern int DWCi_MOV_WH_StateInInitialize(void);

int func_021D3638(void)
{
    wh->f12a4 = 0;
    wh->f12a0 = 0;
    wh->f48 = 0;
    wh->f50 = 0;
    wh->f52 = 1;
    wh->f54 = 0;
    wh->f0 = 0;
    wh->f4 = 0;
    wh->f4c = 0;
    switch (DWCi_MOV_WH_StateInInitialize())
    {
    case 0:
        return 0;
    default:
        return 1;
    }
}
