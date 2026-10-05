/*
 * function: func_021F3FBC
 * address:  0x021F3FBC
 * packet:   pkt_ov194_021F3FBC
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD5 lane14): still DIFF 10 (entry order: heap load after the a3 spill). Tried: u32 heap
 *   parameter (masks every u16 use, 328), house string.h memset (inlines the 8-byte clear, 384).
 *
 * 2026-10-04 (wD3 lane 15): DIFF, full draft, 748 vs 740 bytes (extra bytes only from the two residues below,
 * everything else matches incl. both jump tables, slots, calls, pool). Residue 1: the original loads the stack
 * argument heap (ldr r5,[sp,#0x94]) before the memset call; here it comes after (tried u32 heap = hp local).
 * Residue 2: mode 0/1 does ldr r0,[sp,#0x14]; b 0x021F404C, a jump into the mode 2 tail (movs r0,#1; str [sp,#0x1c])
 * (tail merge keeps the LATER store in the original, the EARLIER one here: try swapping the source order of the
 * case 2 and case 0/1 blocks or a shared store). Mode 2 test written as if (a2 >= 8) v1c = 1 else 0 (blo target right).
 * Offsets: o+0 Obj, +8 +0xC +0x10 handles, +0x24 +0x28 +0x2C +0x30 +0x34 +0x38 text part, 0x3C bytes cleared.
 *
 * 2026-10-05 (wD4 lane09): DIFF, 10 bytes (was 354), size now 740. Fixed: case 2 `v1c = (a2 >= 8) ? 1 : flagB;`
 * (the tail merge now keeps the case 2 store); heap is a u16 parameter used directly (no local, and the
 * u16 callee param gets it unmasked); case 1 falls through into case 2; case 5 written before case 4;
 * the flagA struct sets its zero fields explicitly after the memset (order +0x10, +0x12, +0x14, +0x11, +0xC);
 * the if/else sets idx (0x11/0x10) and r as the folded constants 0xC80/0x14C0 (tail merge gives the shared
 * lsls), then one func_02045EC0(s3, idx) call; func_0201C724 last param u32. Residue: only the entry,
 * original loads heap (ldr r5,[sp,#0x94]) before the memset args, compiled loads it after the a3 spill.
 * Tried: local `u16 heap = hp` after h20, `u32 heap = hp` first or after h20 (ldrh, worse), u8 heap param,
 * static inline wrapper for the memset, a3 copied to a local (first or last), a3 as int (12). a3 as u16 gives 8
 * bytes (the a3 spill moves up, heap load still late) but changes the parameter type, so it is not kept.
 *
 * note 2026-10-05 (wD6 lane10): still DIFF 10. heap is loaded with ldr (a u16 stack param in this
 *   compiler loads with ldrh elsewhere, for example ov194 021F1D58), so tried heap as u32 with every callee
 *   heap parameter u32 (func_021F51E4 too): same 10 bytes. Same family as 021F1E28 (entry move order).
 * note 2026-10-05 (wD7 lane05): still DIFF 10. Parameter types move the entry spill stores (the lever that
 *   closed 021F1E28): a2 u16 or u8 moves the a2 spill to the top (18); a3 u16 moves the a3 spill up (8,
 *   heap load still after it); a2 and a3 both u16 (18); a3 int (12, asrs); mode u16/u8 (10); heap s16 (752
 *   bytes), heap u8 (10). The heap load stays after the a3 spill in every spelling: the original emits the
 *   a3 spill after the stack parameter load, the build before it.
 * 2026-10-05 (wD9 lane19): still DIFF 10. Tried flagB declared first (before flagA): no change, the heap
 *   load stays after the a3 spill.
 * 2026-10-05 (wD9r lane13): still DIFF 10. Caller fact: ov194 021F1440 passes h (u16 args+4) as a2 and
 *   *(u16 *)(args + 6) as a3, so a2/a3 are u16 values at the source. a3 u16 alone: 8 bytes, but the a3 spill
 *   then moves to the top (before the h20 store) and the two `(a3 & 0xFF00) >> 8` become asrs (int promotion),
 *   so the original computes them unsigned. The heap load stays after the spills in every form.
 * 2026-10-05 (wD9r lane23): still DIFF 10. Tried: mode as u32 (10), a2 as int (11), o passed as void *
 *   and copied to a u8 * local (10). Caller check: ov194 021F1440 passes heap as the literal 0x1E in a plain
 *   stack slot, so the stack parameters are scalars (no by-value struct).
 * 2026-10-05 (wD9r lane43): still DIFF 10. Tried heap as a one-field by-value struct `struct { u16 v; }`
 *   (the caller stores the literal in a plain stack word): 692, heap is no longer register-allocated. Reading:
 *   ours keeps the heap load below the a3 spill store, as if the stack-parameter load may alias it; the
 *   original issues it before. No new source form found.
 * 2026-10-05 (wD9r lane56): DIFF 6 (was 10). a3 is now u16 (the caller passes a u16, see lane13) and the
 *   two byte extracts use an unsigned mask `(a3 & 0xFF00u) >> 8`, which keeps lsrs (the asrs came from int
 *   promotion). Residue: entry only, ours `str r3 a3` sits before the h20 store and the heap load after the
 *   o copy; the original has the heap load right after the h20 store and the a3 spill last. Also tried with
 *   a3 u16: heap u32/int with every callee heap u32 (10, a3 spill moves back late), heap u8 (6), a2 and a3
 *   both u16 (16); with a3 u32, memset prototype returning void * (no change), u32 local `heap = hp` after h20 (copy
 *   propagated, 10). Reading: loads do not pass earlier stores in this scheduler, so the original IR has the
 *   heap load before the a3 spill store; no source form found that orders them so.
 * 2026-10-05 (wD9r lane79): still DIFF 6. Tried a3 as s16 (6, same entry order as u16: a3 spill before h20),
 *   a3 as long and unsigned long (10, same as u32: a3 spill late but the heap load still after it). Reading:
 *   with a 32-bit a3 the only residue is the heap load sitting after the a3 spill; with any 16-bit a3 the a3
 *   spill also moves up. No new source form found.
 * 2026-10-05 (wD9r lane87): still DIFF 6. Tried the u16-heap-callee idiom (ov096 02187F00): house u16 heap
 *   parameters on func_020490F4, func_0204ACEC, func_0204AC18 (e and heap), func_0204A6C8 and func_0204B294 (g):
 *   6 with a3 u16, 10 with a3 u32, entry order unchanged (u16 d on func_0204AC18 adds a mask, 744). Also
 *   u16 locals `heap = hp; a3 = a3p;` after h20: copy propagated, 6. No new source form found.
 * 2026-10-05 (wD9r lane98): still DIFF 6. Tried a2 and a3 as one by-value struct `struct { u32 a2; u32 a3; }`
 *   (the adjacent slots 0x14/0x18 and the repeated a2 reloads suggested a memory object): 655, mwcc homes the struct
 *   with push {r0-r3} and shifts every slot, so a2/a3 are scalar parameters. No new source form found.
 * 2026-10-05 (wD9r lane104): still DIFF 6. Tried the short-parameter idiom (ov116 021D7D0C) on heap:
 *   `short heap` with every callee heap u32 (func_021F51E4 too) moves the a3 spill to its image place (after
 *   the o copy) but heap is then read with ldrsh at the first use, not ldr at entry (697); with the u16
 *   func_021F51E4 prototype, 752 bytes. The image loads heap with a word ldr and never truncates it, so heap is
 *   32-bit or u16, not short. No new source form found.
 * 2026-10-05 (wD9r lane111): still DIFF 6. Reading of the two variants: with u32 a3 the image and ours
 *   agree except the heap ldr, which in ours sits after `adds r4,r0` and the a3 spill; with u16 a3 the a3
 *   store becomes an entry home store (narrow register params are memory-homed by mwcc, confirmed on ov198
 *   0220C16C) and moves to the top, while the heap ldr stays after the o copy. So the heap ldr follows the
 *   o copy in our IR (param order), and the image has it before the memset argument setup. A u16 a3 is a
 *   home store, the image a3 store is a plain late spill, so the image a3 is 32-bit and the residue is the
 *   heap load position alone. No new source form found.
 * 2026-10-05 (wD9r lane127): still DIFF 6 (a3 u16 form kept). With u32 a3 the only residue is the heap ldr
 *   position (10). Tried a declared-initialized copy `u32 heap = hp;` (hp u32 parameter, u32 callees) placed
 *   right after h20 or first among the locals: the copy is propagated and the heap ldr stays after the o copy
 *   and the a3 spill (same 10). Source position of the heap copy has no effect; the ldr is placed by the
 *   parameter setup, not by a statement. Note: case 3 of the second switch reloads a3 from 0x18 twice in one
 *   block, the same in both builds. No new source form found.
 * 2026-10-05 (wD9r lane138): still DIFF 6. Tried: o as a typed struct with real fields (+0 obj, +8 chr,
 *   +0xC pal, +0x10 cell, +0x24..+0x38) in place of raw offsets: same 6, entry unchanged. With u32 a3, a
 *   local copy `u32 a3 = a3p;` declared last (after flagB) from a u32 or u16 parameter: propagated, 10 / 6.
 *   Matched callers of the same callee set (ov106 021B87B0, ov183 021DCBD8, ov177 021E7E3C) are not twins.
 *   Reading: the image order needs the heap load before the a3 spill store in the IR; no source form found.
 * 2026-10-05 (wD9r lane156): still DIFF 6. Reading with the narrow-local rule (ov097 021F6D70, ov198 0220C16C):
 *   the image heap ldr sits after the h20 and a2 stores and before the a3 spill, so in the original IR the
 *   heap load follows the local initialisers and precedes the a3 spill. Tried both as initialised copies in
 *   the declaration list after h20 (`u16 heap = hp; u32 a3 = a3p;`, u32 a3p, u16 hp): both copies are
 *   propagated, 10 bytes, entry order unchanged. No new source form found.
 * 2026-10-05 (wD9r lane163): still DIFF 6 (a3 u16 form kept). Tried: every heap callee u16 (adds
 *   func_0204AF28 and func_02043678 to the lane87 set) with a3 u16 (6) and u32 (10); heap s16 with every
 *   callee heap s16 (the ov168 idiom, 10/6); K&R definition (u16 heap gives a mask and pulls the ld to the
 *   top, u32 heap same as prototype); whole body as a static inline called by a wrapper (copies
 *   propagated); a2/a3 as a plain or volatile local struct initialised from the parameters (plain: same
 *   10; volatile: memory stores but the heap ld still sinks after the o copy); register on heap, a3, o
 *   and mode (10); flagB = 0 as a statement after the memset (hoisted back, same). Reading: the heap ld
 *   has no use in the entry block and mwcc always sinks it to just before the flagB init when the block
 *   holds the memset call (ov010 0216EAB0 does the same); in blocks without a call (ov029 021F2AEC, ov055
 *   021F42AC) the stack ld stays first. Only a dependent of the ld (K&R mask) moved it. No new source
 *   form found.
 * 2026-10-05 (wD9r lane176): still DIFF 6. New tries, all unchanged entry order (a3 spill before h20, heap ldr after the o copy):
 *   w24/h20 as one local struct `{u32 h; u32 w;} wh = {0x14,0x22}` (pool-loaded aggregate init, 744 bytes, worse);
 *   all of o, mode, a2, a3, heap const-qualified (6); only heap const (6); `u32 flagB; flagB = 0;` as the first
 *   statement before the memset (6). No entry-block use of heap exists in the image (memset takes o, 0, 0x3c only),
 *   so no real use was added; a dummy use would be a stand-in. Reading unchanged: the image order needs the heap load
 *   before the a3 spill store in the IR.
 * 2026-10-05 (wD9r lane181): still DIFF 6 (a3 u16 form kept). Idiom pass first (stack-parameter-load-sunk, u16-heap-with-u16-callees,
 *   later-parameters-width, stack-argument-copy, narrow-home-store, const-pointer-load idioms: all already covered above or
 *   not applicable). New measurements: (1) the heap ldr position follows the NARROWNESS of the entry locals. With a3 u32:
 *   flagA u16/u8 puts the ldr at the very top (18); h20 u16/u8/s16 puts it after the a2 spill but before h20's
 *   movs/str pair (8, residue = that pair sunk below the ldr); w24 u16 (11); w24+h20 u16 (11). Narrow locals sink their
 *   init pair below the ldr; u32 locals leave the ldr below the memset argument moves. The image needs the ldr below all
 *   three pairs and above the memset args, no spelling gives that. flagB u8/u16/int, flagA int, w24/h20 int: unchanged.
 *   (2) s1, s2 (and s4) u16 with u16 callee params: ldrh through add r6,sp,#0x80, 38 and 92 bytes (the image loads them
 *   as words). (3) typed pointer copy `w = o` after the memset (ov177 021E6118 idiom): propagated, 6. (4) memset
 *   prototype u8 fill or u16 length, narrow constant length local: unchanged.
 * 2026-10-05 (wD9r lane194): still DIFF 6 (a3 u16 form kept). Idioms read first: a-later-parameters-width-reorders-the-entry-spill-stores,
 *   a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue, a-narrow-spilled-parameter-keeps-its-reload-below-a-store,
 *   a-spilled-parameter-reload-scheduled-after-an-unrelated-store-is-a-narrow-parameter (all covered by earlier notes). New measurement,
 *   a table of all 384 combinations: a3 in {u16,u32} x flagA,w24,h20 each in {u32,u16} x every order of the three locals and every
 *   split point between "before the v40..h block" and "after it" (24 orders). Best per width combo (a3:flagA:w24:h20 -> bytes, always
 *   with flagA first and w24,h20 after the block, the draft order): u16:u32:u32:u32 6; u32:u32:u32:u16 8; u32:u32:u32:u32 10;
 *   u32:u32:u16:u32 11; u32:u32:u16:u16 11; u32:u16:u32:u32 17; u32:u16:u16:u16 18; u16:u32:u32:u16 22; u16 with flagA u16 23;
 *   u16:u32:u16:x 25. No other order of the three locals beats 12 in any combination (next best u16:u32:u32:u32 A|HW 12), so the draft
 *   order and widths are the optimum of the family. Struct form: the entry locals (and then all of v1c..flagA) as fields of one
 *   local struct (slots 0x1c..0x44 are one contiguous region in the image, no `add rX,sp,#N` points into it; the only address-taken
 *   locals are dim at 0x48 and st at 0x50): 45 bytes (three fields) and 46 (all eleven), the slots move (flagA lands at 0x28) so it
 *   is worse. Entry order unchanged in every case: heap ldr after the a3 spill.
 * 2026-10-05 (wD9r laneS3): still DIFF 6 (code is the committed form; a previous lane left only notes). Read the mwcc
 *   source reference (docs/SCHEDULER.md, PPC model, so only the shape of the rule transfers): the list scheduler picks by
 *   urgency, release count, height, then a fixed per-opcode byte (mr 0 < str/cmp 1 < add 2 < ldr 3 < li 4), earlier text
 *   wins ties; loads/stores order by memory edges (load -> later store, store -> later load). Test of that reading: the
 *   free instructions of the entry block (adds r4,r0 / str r3 / ldr r5 / movs r6) come out in exactly that byte order in
 *   ours (u32 a3 and u32 heap with u32 callees both give the same listing, 10 bytes), so ours has all four tied. The image
 *   order ldr, adds, str r3, movs r6 means its ldr has MORE height than the others, i.e. a successor edge, most likely a
 *   memory edge ldr -> `str r3,[sp,#0x18]`, so in the image IR the heap load precedes the a3 spill store (a2 spill and the
 *   three local stores precede the ldr in both). Probe (not a candidate): all a3 uses replaced by a constant (no a3 spill at
 *   all): the ldr still sinks below `adds r4,r0` (700 bytes), so the a3 store does not push the ldr down; the ldr simply has
 *   no height of its own, as lane163 measured with the K&R mask (a consumer pulls it up). So the image ldr has a successor
 *   in the entry block that our source lacks, and no real source construct that creates one was found: the only edges
 *   available are a consumer of heap (a stand-in) or a spill ordered by the front end. Idioms re-read: a-stack-argument-copy-
 *   after-the-register-spills-is-a-narrow-pass-through-parameter (copy-to-home form, ours is a register load: n/a),
 *   a-heap-id-passed-unnarrowed-to-both-s16-and-u16-callee-parameters-is-a-u8-parameter (u8 heap: 6, tried before).
 *   3 compiles.
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_020276A4  0x020276A4  thumb
 *   func_020276A8  0x020276A8  thumb
 *   func_020276AC  0x020276AC  thumb
 *   func_020276B0  0x020276B0  thumb
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_021F51E4  0x021F51E4  thumb ov194
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C724  0x0201C724  thumb
 *   d_021F5569     0x021F5569  data ov194
 */

/*
 * 2026-10-05 (wave D8 lane08): still DIFF 10. Tried: u32 parameter hp with a u16 local `heap = hp`
 *  declared first (692, worse); hp u32/int/u16 with a u32 or u16 local after h20 (328 to 698, worse). The heap
 *  local forms all break the u16 callee arguments; only the plain u16 parameter keeps the body exact.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_02082BCC(void *p, int v, u32 n);
extern u32  func_020275E4(void);
extern u32  func_020276A4(void);
extern u32  func_020276A8(void);
extern u32  func_020276AC(u32 a);
extern u32  func_020276B0(u32 a);
extern u32  func_0201BC3C(void);
extern u32  func_0201BABC(u32 a, u32 b, u32 c, u32 d);
extern u32  func_0201BC40(void);
extern u32  func_0201BCB4(void);
extern u32  func_0201BB5C(u32 a, u32 b, u32 c, u32 d);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_0204ACEC(void *h, u32 a, int b, int c, u32 heap);
extern void *func_0204AC18(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 heap);
extern void *func_0204AF28(void *h, u32 a, u32 b, u32 heap);
extern void *func_0204A6C8(void *h, u32 a, u32 b, u32 c, u32 heap);
extern void func_02049238(void *h);
extern void *func_0204B294(void *a, void *b, void *c, void *d, const void *e, u16 f, u32 g);
extern void func_0204B92C(void *o, int v);
extern void func_0204B878(void *o, u16 v);
extern void func_0204B6F4(void *o, u32 a, u32 b);
extern void func_021F51E4(void *dst, u32 arc, u32 member, u32 index, u16 width, u16 height, int pos, int mode, u16 heap);
extern void *func_02043678(u32 a, u32 b, u32 c, u32 heap);
extern void *func_020255A0(u32 a, const void *b);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_02043B5C(void *buf, u8 v);
extern void func_0201C724(u32 a, void *b, s16 c, u32 d, void *e, u32 f, u32 g);
extern const u8 d_021F5569[];

typedef struct { u16 w; u16 h; u32 pad; } Dim8;

void func_021F3FBC(u8 *o, int mode, u32 a2, u16 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap)
{
    u32 flagA = 0;
    u32 v40;
    u32 v3c;
    u32 v38;
    u32 v34;
    u32 v30;
    u32 v2c;
    void *h;
    u32 w24 = 0x22;
    u32 h20 = 0x14;
    u32 v1c;
    u32 flagB = 0;

    func_02082BCC(o, 0, 0x3c);
    v2c = 0;
    switch (mode) {
    case 0:
    case 1:
        v40 = func_020275E4();
        v3c = func_020276A4();
        v38 = func_020276A8();
        v34 = func_020276AC(2);
        v30 = func_020276B0(2);
        v1c = a2;
        break;
    case 2:
        v40 = 0x20;
        v3c = flagB;
        v2c = d_021F5569[a2];
        v38 = a2 + 0x31;
        v34 = 0x41;
        v30 = 0x42;
        v1c = (a2 >= 8) ? 1 : flagB;
        break;
    case 3:
        flagA = 1;
        v1c = (a3 & 0xFF00u) >> 8;
        if (v1c == 2) {
            flagA = 0;
        }
        v40 = 7;
        v3c = func_0201BC3C();
        v38 = func_0201BABC(a2, (u8)a3, v1c, 0);
        v34 = func_0201BC40();
        v30 = func_0201BCB4();
        w24 = 0x1e;
        h20 = 0x14;
        flagB = 1;
        break;
    case 4:
    case 5:
        v40 = 0x76;
        v3c = 9;
        v38 = 8;
        v34 = 7;
        v30 = 6;
        v2c = 1;
        break;
    }
    h = func_020490F4(v40, heap);
    if (flagB != 0) {
        *(void **)(o + 8) = func_0204ACEC(h, v3c, 0, 0x40, heap);
    } else {
        *(void **)(o + 8) = func_0204AC18(h, v3c, 0, 0x40, v2c, 1, heap);
    }
    *(void **)(o + 0x10) = func_0204AF28(h, v34, v30, heap);
    flagB = 0;
    *(void **)(o + 0xC) = func_0204A6C8(h, v38, 0, 0, heap);
    func_02049238(h);
    {
        Dim8 dim;
        func_02082BCC(&dim, 0, 8);
        dim.w = w24;
        dim.h = h20;
        *(void **)o = func_0204B294((void *)s0, *(void **)(o + 0xC), *(void **)(o + 8), *(void **)(o + 0x10), &dim, flagB, heap);
    }
    func_0204B92C(*(void **)o, 1);
    switch (mode) {
    case 0:
        if (a2 == 0) {
            func_021F51E4(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
        } else {
            func_021F51E4(*(void **)o, 0x31, 9, 3, 4, 4, 0, 0, heap);
        }
        break;
    case 1:
        func_021F51E4(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
    case 2:
        func_0204B6F4(*(void **)o, 0, 1);
        break;
    case 3:
        func_0204B878(*(void **)o, 1);
        func_0204B6F4(*(void **)o, func_0201BB5C(a2, (u8)a3, (a3 & 0xFF00u) >> 8, flagB), flagB);
        break;
    case 5:
        func_0204B878(*(void **)o, 5);
        func_0204B6F4(*(void **)o, flagB, 1);
        break;
    case 4:
        func_0204B878(*(void **)o, 2);
        func_0204B6F4(*(void **)o, flagB, 1);
        break;
    }
    if (flagA != 0) {
        void *h2;
        u32 r;
        u32 idx;
        u8 st[0x18];
        h2 = func_020490F4(0x17, heap);
        *(void **)(o + 0x30) = func_02043678(2, 2, 0x20, heap);
        *(void **)(o + 0x24) = func_0204ACEC(h2, 5, 0, 0xA0, heap);
        func_02049238(h2);
        func_02082BCC(st, 0, 0x18);
        *(void **)(st + 0) = *(void **)(o + 0x30);
        *(u16 *)(st + 4) = 0x2e;
        *(u16 *)(st + 6) = 0x14;
        *(void **)(st + 8) = *(void **)(o + 0x24);
        *(u8 *)(st + 0x10) = 0;
        *(u16 *)(st + 0x12) = 0;
        *(u32 *)(st + 0x14) = 0;
        *(u8 *)(st + 0x11) = 0;
        *(u32 *)(st + 0xC) = 0;
        *(void **)(o + 0x2C) = func_020255A0(s4, st);
        if (v1c == 1) {
            idx = 0x11;
            r = 0xC80;
        } else {
            idx = 0x10;
            r = 0x14C0;
        }
        *(void **)(o + 0x28) = func_02045EC0(s3, idx);
        func_02043B5C(*(void **)(o + 0x30), 0);
        func_0201C724(s2, *(void **)(o + 0x30), 0, 0, *(void **)(o + 0x28), s1, r);
        *(u32 *)(o + 0x38) = s2;
        *(u32 *)(o + 0x34) = 1;
    }
}
