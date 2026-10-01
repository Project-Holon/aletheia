/*
 * function: func_0216C8DC
 * address:  0x0216C8DC
 * packet:   pkt_0216C8DC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF   (parked; not EXACT/MATCH)
 * blocker:  dsi/1.1p1 pools the shared `0` (return 0 + f1/f2 stores) into
 *           callee-saved r4 at +0014, rolling every register +1 (134 concrete,
 *           296/296).  Documented front-end wall; no source lever reached it.
 *           ../2.0/base fixes the allocation but leaves a 4-byte tail residue.
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
 * symbols:
 *   g_021AAA40     0x021AAA40  data  ov009
 *   func_02173AD8  0x02173AD8  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0205A16C  0x0205A16C  arm
 *   func_02094798  0x02094798  arm
 *   func_0216EB68  0x0216EB68  arm  ov009
 *   func_0219D158  0x0219D158  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Key {
    u8  f0;
    u8  f1;
    u16 f2;
    u32 f4;
    u32 f8;
};

extern struct Key g_021AAA40[];
extern int  func_02173AD8(void);
extern int  func_020948E0(u32 p);
extern void func_0205A1B0(int a0);
extern int  func_0209477C(char *s);
extern void *func_0205A16C(int a0, int a1);
extern void func_02094798(void *dst, char *src);
extern void func_0216EB68(int a0, int a1);
extern void func_0219D158(int a0, void *a1);

int func_0216C8DC(int a0, char *a1, int a2)
{
    int i;

    if (a1 == 0 || a2 == 0)
        return 0;

    if ((unsigned)a0 >= 0x64u && g_021AAA40[a0 - 0x64].f0 != 0) {
        if (g_021AAA40[a0 - 0x64].f4 != 0 &&
            func_020948E0(g_021AAA40[a0 - 0x64].f4) != 0)
            return 0;
    } else {
        a0 = func_02173AD8();
        if (a0 == 0)
            return 0;
    }

    i = a0 - 0x64;
    g_021AAA40[i].f0 = a0;
    g_021AAA40[i].f1 = 0;
    g_021AAA40[i].f2 = 0;
    if (g_021AAA40[i].f4 != 0)
        func_0205A1B0(4);
    g_021AAA40[i].f4 = (u32)func_0205A16C(4, func_0209477C(a1) + 1);
    if (g_021AAA40[i].f4 == 0) {
        func_0216EB68(9, (int)0xFFFEC77F);
        return 0;
    }
    func_02094798((void *)g_021AAA40[i].f4, a1);
    g_021AAA40[i].f8 = a2;
    func_0219D158(a0, (void *)g_021AAA40[i].f4);
    return a0;
}
