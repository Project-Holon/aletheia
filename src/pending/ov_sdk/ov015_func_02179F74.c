/*
 * function: func_02179F74
 * address:  0x02179F74
 * packet:   pkt_ov015_02179F74
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  8 bytes at +0024..+0030 in the final 0xFF/zero store block, a pure
 *           two-instruction colouring/scheduling swap. Object materialises the
 *           0xFF in r3 and the zero in r2 before the strb (mov r3,#0xff;
 *           ldr r0; mov r2,#0; strb r3,[r1,#1]; str r2,[r0,...] x3); 1.1p1 puts
 *           the 0xFF in r2, emits strb r2 first, then rematerialises mov r2,#0
 *           at +0030. The 64-bit-zero idiom
 *           (docs/idioms/a-64-bit-zero-store-picks-r2.md) is the only lever that
 *           moved it: writing g_0217ABA8[2..3] as one `unsigned long long` zero
 *           gets the zero into r2 and takes 11 B -> 8 B; the remaining bytes are
 *           the FF register (r3 vs r2) and the mov/strb order. Ruled out this
 *           wave: enum-typed zero (`typedef enum {Z0} E`) assigned first (11 B,
 *           folds); named u32 and named u64 zero locals with the u64 store (8 B,
 *           folds); zeros-before-FF with three separate stores (20 B); [4]=0
 *           first then FF then u64 (16 B, zero web splits into ip/r2). AST
 *           permuter (tools/permuter.py, --arm, anneal, 600 compiles, 485
 *           distinct) flat at 8 B; --explain shows the residue is one
 *           substitution r3 -> r2. Pin-invariant on 12 pins
 *           (docs/notes/lane_t20_ov107_ov015_ov175_residues.md): the front
 *           end's allocator, not a spelling. Prev-lane details retained below.
 *
 * w10_nm: the 64-bit idiom (docs/idioms/a-64-bit-zero-store-picks-r2.md) is the only lever that
 *           moved the residue: writing g_0217ABA8[2..3] as one `*(unsigned long long *) = 0`
 *           puts the zero in r2 (not r1) and drops the diff from 11 to 8 B. The remaining 8 B are
 *           a pure two-instruction swap: object has `mov r2,#0` at +002C then `strb r3` at +0030;
 *           1.1p1 has `strb r2` at +002C (0xFF still in r2) then `mov r2,#0` at +0030. So the zero
 *           web must overlap the strb (forcing 0xFF to r3) but the allocator rematerialises the
 *           constant at its first use, below the strb. Enum-typed zero (`typedef enum {Z0} E`),
 *           enum-typed store targets and assigning the zero first all still fold to the same
 *           11 B. Blocked on making the zero non-rematerialisable without a call/callee-save.
 *
 * w9_nm: still 11 B: locals ff/zero (top or block), chained zero stores, -1 for 0xFF, stores before or after: the object materialises 0xff in r3 and 0 in r2 before the first store (strb then three str); the compile builds 0xff first in r2.
 *
 * w8_nm tried: all 24 orders of the four stores, each with and without the
 * DWARF local `size` for the IRCi_Read result: none under 11 B.
 * symbols:
 *   func_0217A60C  0x0217A60C  arm  ov015
 *   func_0217A7AC  0x0217A7AC  arm  ov015
 *   func_02179F48  0x02179F48  arm  ov015
 *   func_0217A594  0x0217A594  arm  ov015
 *   g_0217ABD8     0x0217ABD8  data
 *   g_0217AAB0     0x0217AAB0  data
 *   g_0217ABA8     0x0217ABA8  data
 */

extern void func_0217A60C(void);
extern unsigned char func_0217A7AC(unsigned char *buf);
extern void func_02179F48(void);
extern void func_0217A594(unsigned char id);
extern unsigned char g_0217ABD8[184];
extern unsigned char g_0217AAB0[2];
extern int g_0217ABA8[5];

void func_02179F74(unsigned char unitId)
{
    func_0217A60C();
    func_0217A7AC(g_0217ABD8);
    func_02179F48();
    func_0217A594(unitId);
    g_0217AAB0[1] = 0xFF;
    g_0217ABA8[4] = 0;
    *(unsigned long long *)&g_0217ABA8[2] = 0;
}
