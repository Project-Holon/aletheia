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
