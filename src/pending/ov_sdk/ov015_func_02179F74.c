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
 * blocker:  11 bytes (6 sites) at +0024..+003C, all in the final FF/zero store block. The object
 *           materialises both immediates before the first store (mov r3,#0xff; ldr r0,&ABA8;
 *           mov r2,#0; strb r3,[r1,#1]; str r2,[r0,...] x3) and colours 0xFF->r3, 0->r2; 1.1p1
 *           sinks the zero past the strb, reuses the dead r1 for it, and builds 0xFF in r2.
 *           Ruled out this wave: w10 permuter (seed 1, budget 300, hill) flat at 11 B; v1 chained
 *           zero stores 13 B; v2 FF-store-last 24 B; v3 reorder+FF-first 14 B; plus the 24 store
 *           permutations already recorded below (all 80 B/6 sites). Pin-invariant on 12 pins
 *           (docs/notes/lane_t20_ov107_ov015_ov175_residues.md), so it is the front end's
 *           scheduler, not a spelling.
 *
 * w9_nm: still 11 B: locals ff/zero (top or block), chained zero stores, -1 for 0xFF, stores before or after: the object materialises 0xff in r3 and 0 in r2 before the first store (strb then three str); the compile builds 0xff first in r2.
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
 * w8_nm tried: all 24 orders of the four stores, each with and without the
 * DWARF local `size` for the IRCi_Read result: none under 11 B.
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
    g_0217ABA8[2] = 0;
    g_0217ABA8[3] = 0;
}
