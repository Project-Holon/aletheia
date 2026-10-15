/*
 * function: DWC_AddMatchKeyInt
 * address:  0x0216C8DC
 * packet:   pkt_ov009_0216C8DC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC_AddMatchKeyInt (dwc_match.o): resolve/create the match-key slot at
 * 0x021AAA40 (12-byte stride: f0 key id, f1 flag, f2 u16, f4 string ptr,
 * f8 int), free the old string, strdup the new one and record the int.
 *
 * BLOCKER (codegen only, size correct at 296): the whole body is logically
 * right but mwcc allocates the three parameters differently -- original
 * keeps a0=r7, a1=r6, a2=r5 with the index in r4 and rematerialises a zero
 * into r2; this front end hoists a zero into r4 and maps a0=r8, a1=r7,
 * a2=r6 with the index in r5.  Every branch target and constant is right;
 * only the register file assignment differs.  Not a witness problem.
 *
 * lane W7 (2026-09-30): applied the unsigned guard the U22 note identified
 * (`(unsigned)a0 >= 0x64u`); the image's first key test is now the image word
 * (`blo`), but the +1 register roll from the hoisted zero is unchanged: still
 * 296/296 with 134 concrete bytes differing and 13/13 relocations resolved.
 * Measured and rejected this wave: computed-zero spellings (a2^a2, a2&0),
 * a separate `key` local, an i-through-pointer local, f4 through a char*,
 * and a global const zero (304 B / 158).  The hoisted `mov r4,#0` (global-CSE
 * of the shared f1/f2 zero into a callee-saved register) remains the sole
 * blocker and is a 1.1p1 allocator behaviour.  Note for the human: the twin
 * 0x0216CA04 lane (T5/U10) pinned this DWC object family to ../2.0/base, where
 * the image allocates index->r4 with no hoisted zero; this lane is bound to
 * dsi/1.1p1 per the wave brief, so the row stays DIFF here.
 *
 * lane U22 (2026-09-30): one CONCRETE byte is wrong in the draft, not just
 * registers.  The image's first key test is +0020 `cmp r7,#0x64; blo` --
 * cond 0x3 (unsigned LO, word 0F 00 00 3A) -- while the parked `a0 >= 0x64`
 * on a signed int emits cond 0xB (`blt`, word 0F 00 00 BA).  Spelling the
 * guard `(unsigned)a0 >= 0x64u` produces the image's word, so the original
 * keys off an unsigned comparison.  The rest is the +1 register roll: ours
 * materialises a shared zero into the callee-saved r4 at +0014 (the image
 * rematerialises `mov r2,#0` at the stores) and that live zero pushes
 * keyID->r8, keyString->r7, valueSrc->r6 with index->r5, against the image's
 * r7/r6/r5 with index->r4.  Measured and not moving the roll: u8 return and
 * u8 params, int* valueSrc, inline indexing (`g[a0-0x64]`), unsigned index,
 * `(u8)0`/`(u16)0` typed zero stores, swap of the two zero stores, zero
 * stores before the f0 store, decl order.  The hoisted zero is the only
 * thing standing between the draft and EXACT on this row and its twin
 * 0x0216CA04.
 *
 * lane W8 (2026-09-30): re-confirmed under dsi/1.1p1.  This is exactly the
 * documented front-end wall of docs/idioms/a-repeated-small-constant-takes-a-
 * callee-saved-register.md: the shared `0` (the `return 0` at +005C and the
 * f1/f2 stores) is pooled into callee-saved r4 at +0014, crossing two calls,
 * which steals the first callee-saved slot and shifts every register +1.  The
 * idiom's own correction says the only known lever is a 2.0 pin.  Measured
 * this wave and no effect on the roll: an enum-typed zero for the stores
 * (docs/idioms/an-enum-typed-zero-keeps-its-own-web-where-a-u32-zero-is-
 * folded.md), assigned both immediately before the stores and first at entry.
 * Cross-check (informational, lead from the twin): under ../2.0/base the whole
 * allocation matches the image (index->r4, no pooled zero) but the size is 300
 * vs 296 -- the twin's one-redundant-copy tail residue (49 concrete) -- so no
 * in-tree compiler reaches EXACT and the row is parked for the object's front
 * end, not a source shape.
 *
 * lane W8b (2026-10-01): re-verified under dsi/1.1p1: identical 296/296, 134
 * concrete, 13/13 relocs.  Re-read the zero idioms; all the named-local zero
 * idioms (a-zero-stored-passed-and-returned-is-a-named-local,
 * a-returned-zero-keeps-r0-out-of-the-rotation,
 * a-repeated-constant-pools-only-within-one-block...) move the benchmark in
 * the opposite direction -- they force a pooled named zero -- and none
 * suppresses 1.1p1's callee-saved hoist.  The image rematerialises `mov r2,#0`
 * (stores) and `mov r0,#0` (returns); 1.1p1 alone pools them into r4.  Wall
 * unchanged.
 *
 * lane W8c (2026-10-01): re-verified under dsi/1.1p1, 296/296, 134 concrete,
 * 13/13 relocs.  Measured this wave and still no effect on the +1 roll: a
 * chained store `f1 = f2 = 0` (300 B / 239 concrete -- worse) and a
 * `do { f0/f1/f2 stores } while (0)` block fence (296 B / 134 -- unchanged).
 * The shared zero at +0014 is 1.1p1 global-CSE across the strcmp call
 * into callee-saved r4; the image rematerialises `mov r2,#0` at the stores and
 * `mov r0,#0` per return.  Confirmed wall.
 *
 * 2026-10-01 (lane02): 134 -> 132 B. Body retyped from DWARF (u8 keyID and
 *   return, int *valueSrc, strcmp(keyString-field, keyString) and
 *   DWC_Free(4, ptr) with their real second arguments). The pooled zero is
 *   still the whole residue. Measured: dropping one zero store still pools,
 *   dropping both stops it (the returns alone never pool); int return and
 *   split NULL guards do not help.
 *
 * 2026-10-01 (w3 lane17): 132 B, unchanged. Mechanism measured: 1.1p1 hoists
 *   the zero to entry when 5 blocks use it (null, strcmp, get-fail and
 *   alloc-fail returns plus the stores) and at least one use is not a return
 *   value; changing any one of the four returns to a non-zero closes every register
 *   (1 B left, the constant), so the residue is exactly this count. The vendor
 *   .debug_line (dwc_match.o) puts one statement per line exactly as this
 *   body (573 guard+return, 579 strcmp test, 583 return, 590/591 get-fail,
 *   595-598 stores, 609 return), so no zero is missing from the source.
 *   Flat: stGameMatchKeys as the object's file static (it is LOCAL in its own
 *   .bss), house string.h with strcmp, enum-typed callee params, static
 *   GetNewMatchKey, || then/else swap, merged get-fail test after the join,
 *   int index from the call, empty DWC_Printf, 12 opt pragmas, all dsi pins.
 *   A goto to one shared `return 0` or an enum local returned at alloc-fail
 *   removes the hoist but changes other bytes. Twin 0216CA04 has the same count.
 *
 * 2026-10-01 (w4): 132 B, unchanged. The hoist is a pure block count, not
 *   very-busy/PRE: with get-fail returning keyID (no zero on that path) plus
 *   one extra zero block elsewhere it still hoists; the zero need not be in
 *   entry (null guard returning 1 + 5 other blocks hoists); extra non-zero
 *   blocks or removing any call do not change it. No late fold exists on 1.1p1:
 *   `return keyID` / `(keyID = f()) == 0` / `keyID >> 8` / `(u8)NULL` /
 *   `keyID > 0xff` either fold early (still hoist) or leave popeq/real ops
 *   (`return keyID` = everything EXACT except the image's moveq r0,#0, 4 B).
 *   const params, optimizer pragmas (common_subs, propagation, lifetimes,
 *   loop_invariants, dead_*, peephole, scheduling, levels) do not close it.
 *   Vendor .debug_line confirms five literal zero sites (573, 583, 591,
 *   597/598, 609), so 1.1p1 needs four; residue is a front-end count rule.
 *
 * symbols:
 *   g_021AAA40     0x021AAA40  data  ov009
 *   DWCi_GetNewMatchKey  0x02173AD8  arm  ov009
 *   strcmp  0x020948E0  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   strlen  0x0209477C  arm
 *   func_0205A16C  0x0205A16C  arm
 *   strcpy  0x02094798  arm
 *   DWCi_StopMatch  0x0216EB68  arm  ov009
 *   func_0219D158  0x0219D158  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstGameMatchKeyData {
    u8 keyID;
    u8 isStr;
    u16 pad;
    char *keyString;
    void *value;
};

extern struct DWCstGameMatchKeyData g_021AAA40[154];

extern int strcmp(const char *s1, const char *s2);
extern u8 DWCi_GetNewMatchKey(void);
extern void func_0205A1B0(int name, void *ptr, u32 size);
extern int strlen(const u8 *s);
extern void *func_0205A16C(int name, u32 size);
extern void DWCi_StopMatch(int error, int errorCode);
extern char *strcpy(char *dst, const char *src);
extern void func_0219D158(int keyid, char *key);

u8 DWC_AddMatchKeyInt(u8 keyID, char *keyString, int *valueSrc)
{
    int index;

    if (keyString == 0 || valueSrc == 0)
        return 0;
    if (keyID >= 0x64 && g_021AAA40[keyID - 0x64].keyID != 0) {
        if (g_021AAA40[keyID - 0x64].keyString != 0 && strcmp(g_021AAA40[keyID - 0x64].keyString, keyString) != 0)
            return 0;
    } else {
        keyID = DWCi_GetNewMatchKey();
        if (keyID == 0)
            return 0;
    }
    index = keyID - 0x64;
    g_021AAA40[index].keyID = keyID;
    g_021AAA40[index].isStr = 0;
    g_021AAA40[index].pad = 0;
    if (g_021AAA40[index].keyString != 0)
        func_0205A1B0(4, g_021AAA40[index].keyString, 0);
    g_021AAA40[index].keyString = func_0205A16C(4, strlen((const u8 *)keyString) + 1);
    if (g_021AAA40[index].keyString == 0) {
        DWCi_StopMatch(9, -80001);
        return 0;
    }
    strcpy(g_021AAA40[index].keyString, keyString);
    g_021AAA40[index].value = valueSrc;
    func_0219D158(keyID, g_021AAA40[index].keyString);
    return keyID;
}
