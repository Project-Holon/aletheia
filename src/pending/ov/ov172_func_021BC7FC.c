/*
 * function: func_021BC7FC
 * address:  0x021BC7FC
 * packet:   pkt_ov172_021BC7FC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD9r laneS2): still DIFF 2 bytes (+016C). The draft left by the stopped lane held only notes (code equals
 *   HEAD, 908 B, 2 B diff); kept. Read the mwcc reference (inspiredrobot/mwcc, a PowerPC GC build): its docs list the
 *   copy/constant propagation passes and the allocator but give no rule for which source constructs stay unfolded
 *   or for ARM rematerialisation, so no construct could be derived from it. Re-read the listing: found=1 at +0968 is
 *   a hoisted movs whose store (+0972) follows the unseen store (+096E) and the +0x14 add; diff=1 at +097C and the
 *   list[3] arm each re-issue movs #1 (r0 was clobbered), so the 1 behind them is a rematerialised single-def vreg,
 *   not a user variable. Every form that gives such a vreg (see the notes above) is folded to the literal or reloads.
 *   No new compile run; no untried justified hypothesis remained. Residue unchanged.
 * 2026-10-05 (wD9r lane206): still DIFF 2 bytes (+016C). Scanned every constant 1 in the original: only loop 1's
 *   hoisted `movs r2,#1` (preheader, store of unseen), match = 1 at +013A, diff/refresh 1 (all after +016C). The
 *   function is void; changed/refresh are 0 at entry (two separate movs #0). No single-def 1 variable exists
 *   between the k head and +016C except loop 1's hoisted constant. Tried (new): one = 1 before loop 1, used as the
 *   loop-1 store value and as found = one (10 B, folded to the literal, no CSE with the preheader constant);
 *   found = (ok != 0), ((int)mode >= 5), (p != 0), (j < 16), (list != 0): each emits a real compare (+12 to +16 B).
 *   Residue unchanged.
 * 2026-10-05 (wD9r lane199): still DIFF 2 bytes (+016C). Re-derived slot sp+0x10 from the listing: it is only match
 *   (movs/str #1 at +013C, str 0 at +014C, one ldr at +015A for cmp #1, no other access anywhere). So the image
 *   movs r0,#1 at +016C is NOT a reload of match's slot; the found store copies a separate single-def constant-1
 *   vreg, and match (two defs) can never be it. Tried (new, from the match side): found = (match == 1) (920 B, 581 out);
 *   found = match written before the unseen store (904 B, 543 out); found = 1 and match = 1 set together at the k
 *   head with found = 0 on the mismatch break and no copy (908 B, 54 out). Residue unchanged.
 * 2026-10-05 (wD9r lane193): still DIFF 2 bytes (+016C). Tried constant-1 sources the front end might not fold, all
 *   at `found = X` after the unseen store: found = (kind >= 0), (e[0] >= 0), (m >= 0), (mode >= 0) with unsigned
 *   operands (10 B each, folded to the literal); static inline Ok(v) with an if and both paths returning 1 (10 B);
 *   static inline Hit(v) { r = 0; if (v == 1) r = 1; return r; } (581 B out, 920 B); function-scope static const
 *   table element kT[1] read directly (798 B out) and through a const int local (875 B out); local struct
 *   {0, 1} field (898 B out). Residue unchanged.
 * 2026-10-05 (wD9r lane187): still DIFF 2 bytes (+016C). Reading: matched ov021 0219F990 has `ok = 1 ... ff = ok` and
 *   compiles the copy as `adds r7,r4,#0` (a two-def register variable is not folded), so a copy of a spilled
 *   two-def variable is a reload, never movs. Tried (new): found assigned in the if condition,
 *   `if ((found = match) == 1)` (544 B out, 904 B); found = match placed before the if (544 B out);
 *   u32 match with found = match (2 B, same residue); `on` set to 1 at two places (j top and k head), found = on
 *   (10 B, two defs of the same constant still fold); hit = 1 then found = hit (10 B, folded). Searched src/matched
 *   for `x = ok/match/same` copy forms: only ov021 0219F990 and sub_02018E34 (register cases). Residue unchanged.
 * 2026-10-05 (wD9r lane183): still DIFF 2 bytes (+016C). Reading: the original reload of a spilled vreg whose only
 *   definition is constant 1 is rematerialised as movs at register allocation, while the pre-RA schedule keeps the
 *   found store after the unseen store (the reload is a load with latency). So the copy source is a single-def,
 *   not-folded constant vreg; match has two defs (1 and 0) and cannot be it. Idioms read in full: the
 *   remat/zero-register, constant-compared-from-a-register, narrow-flag, dead-store, s8-local reload, spilled-local-twice
 *   and logical-store-order files (list in report). New tries: found = (match != 0) and !!match (920 B, 581 B out);
 *   found = ok != 0 (924 B); uninitialised `on` set to 1 in both kind arms, found = on (916 B, spilled, 748 out);
 *   match declared in the k-block (20 B out); match declared before found (38 B out). Residue unchanged.
 * 2026-10-05 (wD9r lane172): still DIFF 2 bytes (+016C). Reading: post-RA the stores keep their pre-RA
 *   order (stack and [r7,r1] stores are not reordered), only the movs/ldr is hoisted. So the image found
 *   store is a copy found = V placed after the unseen store pre-RA, with V a spilled single-def 1 that the
 *   RA rematerialises; with the literal, found = 1 is placed above the unseen store pre-RA. Tried (new):
 *   _Bool found with literal (18 B), _Bool match with literal (10 B) and with found = match (8 B);
 *   match as the m-loop control (for (m = 0; match == 1 && m < 6; m++), both orders, 647-648 B);
 *   act = active loaded into a local, if (act == 1), found = act (615 B); match = on = 1 chained at the
 *   k head with literal found (10 B, no copy); volatile match (59 / 52 B, memory slot at sp+0x38, found
 *   store still first); probes with a memory store of 1 before the mode read, at the j head, and at the
 *   k head (all keep the found store above the unseen store, so value numbering of the 1 is not
 *   dominator-scoped in this build). Residue unchanged.
 * 2026-10-05 (wD9r lane162): still DIFF 2 bytes (+016C). Reading: value numbering for constants is
 *   dominator-scoped, not EBB-local: a probe memory store of 1 in the k-loop head (before the mac loop) makes
 *   the literal found = 1 a copy of that 1, and its store then stays after the unseen store; a dead local
 *   store (match = 1 before the unseen store) does not. But the copy form puts movs #1 late (just before the
 *   store), while the image hoists it to +016C like a reload, so the image looks like a reload of a spilled
 *   1-only variable that is rematerialised. Tried (new): match as u8, u16, signed char, short with literal
 *   found = 1 (10 B each); static inline Claim helpers that widen: u8 return of 1 with the unseen clear
 *   inside (by slot pointer and by list, k), int return of a u8 parameter v = 1, void helper storing 1
 *   through int *found (10 B each, all propagated to the literal); u8 found recheck (18 B: stores in source
 *   order, movs not hoisted, kind-arm order flips, slots unchanged). Residue unchanged.
 * 2026-10-05 (wD9r lane140): still DIFF 2 bytes (+016C). Reading: a literal found = 1 is folded by
 *   constant propagation before value numbering (found = match = 1, ok = 1 then found = ok, found = ok = 1
 *   all give the literal, 10 B); store-to-load forwarding works (found = unseen + 1 gives r3+1, 10 B, not
 *   folded). So the copy source needs a 1 operand that value numbering sees, and none is in the image EBB.
 *   Tried: match as u32 or u8 with literal found = 1 (10 B each); if (match) / if (match != 0) (12 B,
 *   compare changes); always-true nested ifs: if (match == 1) found = 1 (548), if (active == 1) found = 1
 *   (552), if (k < 15) found = 1 (542), none folded; found = (unseen == 0) and !unseen after the clear
 *   (577); found and diff declared in the j-loop body (59-60 B, slot shifts, +016C unchanged); first-loop
 *   store as int or struct field with found int or u32 (10 B, no global CSE with its hoisted 1); file
 *   static const kOne (10 B, folded), file static int kOne (537). Residue unchanged.
 * 2026-10-05 (wD9r lane129): still DIFF 2 bytes (+016C). Rechecked: every other byte matches, so no logic
 *   error elsewhere. Reading: with int found the found = 0 in the kind arm is a value-numbered copy of r3 and
 *   is placed after diff = 1; the image found = 1 behaves the same way (late copy, its movs #1 hoisted), so
 *   the source of the copy is a 1-valued vreg that the front end did not fold. Tried: found = slots[k].active
 *   before or after the unseen store and raw *(u32 *)(e + 0x1e4) before it (542-619 B); found as u8, u16,
 *   short, char, signed char with found = 1 (18 B each: stores keep source order, movs is not hoisted);
 *   volatile found (770 B, memory locals go to the top of the frame, so found is not a memory local); an
 *   uninitialised int on with on = 1 at the j loop top or before the mode read and found = on (10 B, folded,
 *   per docs/idioms/a-constant-compared-from-a-register-is-a-variable-assigned-in-another-arm.md), on = 1
 *   in the first loop (842 B, spilled, not rematerialised; also not semantically safe). Residue unchanged.
 * 2026-10-05 (wD9r lane110): still DIFF 2 bytes (+016C). Tested the inline-helper idea (ov123 021D5AC0):
 *   whole matched-slot block as a static inline returning a helper-local found (60 B: the helper local takes
 *   the lowest slot sp+8 and its literal 1 store is still scheduled above the unseen store); mac compare as a
 *   static inline with a flag local, called as `if (same() == 1)` with found = 1 (28 B) and as match = same()
 *   with found = match (20 B, helper flag at sp+8, +016C unchanged); mac compare helper with early returns
 *   (579-593 B, the match slot disappears, so the image flag is a real function local); unseen clear inside a
 *   helper that returns its int parameter, found = claim(list, k, 1) (10 B, parameter propagated); identity
 *   helper on(1) / on(match) (10 / 2 B). Block-constant idiom with literal found = 1: kind arm in image order
 *   diff, found, slot (18 B) or slot, diff, found (18 B); second arm diff first (14 B). With found = 1 above
 *   the unseen store, value numbering shares r7 = 1 between diff and refresh, not the image. Residue unchanged.
 * 2026-10-05 (wD9r lane97): still DIFF 2 bytes (+016C). Reading: the 0 for found = 0 in the kind arm is a copy of
 *   the temp r3 made by the unseen = 0 store (value numbering), so the original found store at +0176 is a copy
 *   found = T with T a constant-1 vreg rematerialised early; no store of 1 precedes it in the extended block, so T
 *   may be a constant 1 hoisted out of the k loop (match = 1, found = 1, diff = 1 all remat as movs #1). No
 *   source form found that makes mwcc hoist it. Tried: found, diff, refresh, changed and buf as one local struct
 *   (all memory, 854 B: the spilled-vreg movs/str pairs at entry disappear, so they are not memory locals);
 *   plain u8 found with found = 1 (18 B: def stays in source order, no early movs); const int on = 1 with
 *   found = on (propagated, 10 B); diff = 1 before found = 0 with literal found (18 B, diff reloads found).
 *   Also checked: no matched twin (func_0203CF3C/func_02177B80 users are unrelated); func_021BD0A4 really
 *   returns func_02009D50's int (matched file declares void), prototype already int here.
 * 2026-10-05 (wD9r lane85): still DIFF 2 bytes (+016C). Reading: the image looks like found = T with T a
 *   compiler temp of value 1 (def movs r0,#1 early, copy plus spill store late), not a user variable: with
 *   diff = 1 written before found = 0 in the kind arm (18 B) value numbering makes diff = 1 reuse found
 *   (ldr r0,[sp,#0x28] at +0180), so a user variable holding 1 reloads, it is not rematerialised. Tried:
 *   diff = 1 before found = 0 in one or both arms (18, 22 B), that order with found or diff as u8/u16/u32/
 *   short/char (18-22 B), found = 1 above the unseen store (542 B: 1 then gets r7 as block constant),
 *   found = diff = 0, diff = found = 0, diff = 0 before found = 0 at the loop top (10-12 B). Residue unchanged.
 * 2026-10-05 (wD9r lane68): still DIFF 2 bytes (+016C). New tries, all from the narrow-flag idiom
 *   (docs/idioms/a-narrow-flag-local-is-spilled-not-constant-propagated.md): u8 found with found = 1 (18 B: the
 *   movs #1 and its store both move below the unseen store, and found = 0 moves above diff = 1 in the kind
 *   arm); u8 found with found = match (538); u8 match with int found = match (8 B: the reload of match moves
 *   below the unseen store, the original has movs r0,#1 above movs r3,#0); u8 match and u8 found (14);
 *   u8 diff with found = 1 (10). Also the mac compare as a static inline SameMac returning an int flag
 *   (20 B, spill slots of match and slot swap). Residue unchanged.
 * 2026-10-05 (wD9r lane58): still DIFF 2 bytes (+016C). Reading: the image is a found = X copy whose source X
 *   is a 1-valued vreg rematerialised early (movs r0,#1 hoisted by the post-RA scheduler, the copy store left
 *   after the unseen store, as with the reload of match today). Tried: found as a real memory object, written
 *   through int *pf = &found (26 B: frame grows to 0x40 and the store is still scheduled first, so a memory
 *   found is not the answer); found = IsTrue() (static inline returning 1, 10 B, propagated); found returned by
 *   a static inline that clears unseen and returns 1 (10 B). The copy source is still unknown.
 * 2026-10-05 (wD9r lane39): still DIFF 2 bytes (+016C). Reading: with literal found = 1 the pre-RA scheduler
 *   moves the found store above the unseen store (stack slot and list store are independent); the original
 *   keeps it below, as if found were a memory (address-taken) variable aliased by the list store. Tried: &found
 *   taken through an unused pointer (10), found = 1 through a static inline setter taking &found (10, the
 *   inliner promotes found back to a register), found = 1 before the struct unseen store (542). No call in the
 *   listing takes &found, so a real address-taken form was not found.
 * 2026-10-05 (wD9r lane32): still DIFF 2 bytes (+016C). Tried: found = (kind == slots[k].kind) with the
 *   arm test on kind or on found (568-578 B); found used as the match flag itself, no match local (565);
 *   found = slots[k].active and raw *(u32 *)(e + 0x1e4) (543, adds a load). Residue unchanged.
 * 2026-10-05 (wD9r lane19): still DIFF 2 bytes (+016C). Reading: found = 1 then found = 0 in the kind
 *   mismatch arm looks like an if/else on the kind. Tried: if (kind == slots[k].kind) found = 1; else { found = 0;
 *   diff = 1; ... } (542 B, code grows by 4 bytes, the 1 store moves into the arm). Residue unchanged.
 * 2026-10-05 (wD9r lane01): still DIFF 2 bytes (+016C). Reading: in the image the found store is a copy
 *   placed after the unseen store whose source vreg is rematerialised as movs #1 (a spilled vreg whose only
 *   def is 1), the same way the 0 for found = 0 at +0184 is the block constant r3. Re-ran found = 1 (10 bytes,
 *   spill store right after the movs) to confirm. No source form with a 1-only variable that copy propagation
 *   keeps was found; not retried: the forms listed below.
 * 2026-10-05 (wD9 lane07): still DIFF 2 bytes (+016C). Reading: the original movs r0,#1 is a def whose
 *   store waits for the unseen store, so either found = V with V a spilled vreg that only holds 1 (remat at the
 *   reload point) or found is a memory object that the scheduler orders after pointer stores. Tried: found and
 *   diff as an int fl[2] array (scalar-replaced, slots move to sp+8/sp+0xc, 53 bytes, +016C unchanged).
 * 2026-10-05 (wD8 lane10): still DIFF 2 bytes. Tried found |= 1 (543), found = k < 15 (577), found = m == 6
 *   (574), all as late-folded 1 sources: worse. Residue unchanged at +016C.
 *
 * symbols:
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021B8108  0x021B8108  thumb  ov172
 *   func_0203CF10  0x0203CF10  arm
 *   func_0203CF3C  0x0203CF3C  arm
 *   func_02177B80  0x02177B80  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_021B85D0  0x021B85D0  thumb  ov172
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_021BD0A4  0x021BD0A4  thumb  ov172
 *   func_02082D44  0x02082D44  arm
 *   func_021BCB88  0x021BCB88  thumb  ov172
 *   func_021BCEF8  0x021BCEF8  thumb  ov172
 *
 * Peer list refresh: marks every active slot as unseen, scans the 16 wireless
 * peers, matches each peer MAC against the 15 slots (kind 0x20 or 3), adds new
 * peers to a free slot and to the first free row, then drops slots that were
 * not seen, compacts the rows, and refreshes the list.
 *
 * 2026-10-04 (wave D3 lane 02): DIFF, 2 bytes. The only residue is at +016C:
 * the original has movs r0,#1 for found = 1 at the match, stored after the
 * slot+0x1e8 store. With the literal found = 1 the compiler stores found
 * before the slot store (10 bytes). With found = match (this file) the order
 * is right but the value comes from ldr r0,[sp,#0x10]. Tried: found = 1 before
 * the store, before the row computation, found++, int store type, a temp for
 * row[0x1fc], volatile found, found and diff in one local struct. All worse
 * or the same.
 * 2026-10-05 (wave D4 lane 03): DIFF, still 2 bytes (+016C movs r0,#1 vs ldr r0,[sp,#0x10]),
 * but the stand-in casts are gone. The slots are now a real struct (struct Slot, 0x24 bytes at
 * list+0x1e4) used for the match-block and new-slot-arm accesses, and slot is a u8 local (the
 * listing keeps it in the lowest spill slot sp+0xc); together these give the original recomputed
 * list + k*0x24 and slot*0x24 without (u32)k / (int)slot. found = 1 literal: 10 bytes (store
 * scheduled above the unseen store). Tried: found = 1 before the unseen store, a Slot pointer
 * local for the match block (both 540+ bytes), a constant local on = 1 (10 bytes).
 * 2026-10-05 (wave D5 lane 12): DIFF, still 2 bytes. Reading: the original movs r0,#1 sits
 * where our ldr of match sits, and the found store stays after str r3,[r7,r1] and adds r1,#0x14,
 * so found was defined late from a value that was in r0 early (a copy of a variable that the
 * allocator rematerialises as 1), not a literal (a literal store follows its movs at once).
 * Tried: u32 found = 1 (5 lines), found = 1 before the unseen store with the raw e+0x1e8 store
 * (276), found = (match == 1) (314), found = !diff (folds to the literal, 5 lines).
 * 2026-10-05 (wave D6 lane 12): DIFF, still 2 bytes. Reading: with the literal the movs r0,#1 is already at
 *   +016C as in the original; only the found store moves above the unseen store. So the original store had a late
 *   operand at scheduling time (a copy of a variable that was later rematerialised as 1). Tried: `int one = 1;` at
 *   function top with found = one (propagated, 10 bytes), the same with an enum-typed one (10 bytes), found as an
 *   enum-typed local with found = 1 (10 bytes), found = 1 before the struct unseen store (542 bytes).
 * 2026-10-05 (wave D7 lane 11): DIFF, still 2 bytes. Reading: the original store of found waits for the
 *   unseen store (str r3,[r7,r1]) although its movs r0,#1 is ready at +016C, as if found were a memory
 *   variable ordered after that store. Tried: kind field read into a local before found = 1 (10 bytes, the
 *   store still follows its movs), found and diff as one local struct with found = 1 (scalar-replaced,
 *   60 bytes, slots shift), a static inline wrapper is not applicable. Residue unchanged: +016C.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct Info {
    u8 pad0[2];
    u8 b2_0 : 1;
    u8 b2_1 : 5;
    u8 b2_6 : 2;
    u8 pad3[8];
    u8 bB_0 : 7;
    u8 bB_7 : 1;
    u32 w4dummy;
};

struct Rec {
    u8 pad0[4];
    u32 f4;
    u8 pad8[3];
    u8 bB_0 : 7;
    u8 bB_7 : 1;
    u32 fC_0 : 17;
    u32 fC_17 : 10;
    u32 fC_27 : 5;
    u8 pad10[0x10];
    u8 f20;
    u8 f21_0 : 1;
    u8 f21_1 : 1;
    u8 f21_2 : 6;
};

struct Bits2 {
    u8 b0 : 1;
    u8 b1 : 5;
    u8 b6 : 2;
};

extern u32 func_021BDFE4(void *p);
extern int func_021B8108(void *ctx, u32 p);
extern u32 func_0203CF10(u32 a);
extern void *func_0203CF3C(u32 a);
extern u8 func_02177B80(int i);
extern u32 func_020084F4(void *p);
extern u8 func_02008550(void *p);
extern u32 func_02008530(void *p);
extern void func_02087C6C(void *p);
extern int func_021B85D0(unsigned char *p, unsigned char *q);
extern u32 func_02013D5C(u32 id);
extern u32 func_02013D9C(u32 id);
extern int func_021BD0A4(void *ctx, u8 *list, u32 a, u32 b, u32 c);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_021BCB88(void *ctx, u8 *list);
extern void func_021BCEF8(void *ctx, u8 *list);

struct Slot {
    u32 active;
    u32 unseen;
    u32 f8;
    u8 padC[8];
    u8 *buf;
    u8 kind;
    u8 mac[6];
    u8 pad1f;
    u8 row;
    u8 pad21[3];
};
struct List {
    u8 pad[0x1e4];
    struct Slot slots[15];
};

void func_021BC7FC(void *ctx, u8 *list)
{
    int changed;
    int refresh;
    int found;
    int diff;
    struct Rec *p;
    u32 kind;
    u32 a;
    u32 c;
    int match;
    u8 slot;
    int j;
    int i;
    u8 k;
    u8 m;
    u8 r;
    u8 *e;
    u8 *row;
    u8 *mac;
    u32 mode;
    int ok;
    u32 b;
    u8 buf[8];
    u8 q;

    changed = 0;
    refresh = 0;
    if (!func_021B8108(ctx, func_021BDFE4(ctx)))
        return;
    for (i = 0; i < 15; i++) {
        e = list + i * 0x24;
        if (*(u32 *)(e + 0x1e4) == 1)
            *(u32 *)(e + 0x1e8) = 1;
    }
    mode = *(u32 *)(list + 8);
    if (mode != 7 && mode != 9 && mode != 10 && (int)mode >= 5) {
        for (j = 0; j < 16; j++) {
            found = 0;
            diff = 0;
            p = (struct Rec *)func_0203CF10(j);
            if (p == 0)
                continue;
            slot = 0xff;
            mac = func_0203CF3C(j);
            kind = func_02177B80(j);
            if (kind == 3 && ((struct Bits2 *)((u8 *)p + 2))->b1 != 2)
                continue;
            ok = 0;
            if (kind == 0x20) {
                a = func_020084F4(p);
                b = func_02008550(p);
                c = func_02008530(p);
                func_02087C6C(buf);
                if (p->f21_1 == 0 || func_021B85D0((u8 *)p, buf) == 1)
                    ok = func_021BD0A4(ctx, list, a, c, b);
            } else if (func_02013D5C((u16)p->fC_17) == 0 && func_02013D9C((u16)p->fC_17) == 0) {
                ok = func_021BD0A4(ctx, list, (u32)((u8 *)p + 0x1a), p->f4, p->bB_7);
            }
            if (ok == 0)
                continue;
            for (k = 0; k < 15; k++) {
                e = list + k * 0x24;
                if (*(u32 *)(e + 0x1e4) == 1) {
                    match = 1;
                    for (m = 0; m < 6; m++) {
                        if (mac[m] != e[m + 0x1fd]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match == 1) {
                        ((struct List *)list)->slots[k].unseen = 0;
                        found = match;
                        if (kind != ((struct List *)list)->slots[k].kind) {
                            found = 0;
                            diff = 1;
                            slot = k;
                            for (m = 0; m < 3; m++) {
                                if (k == list[m]) {
                                    list[m] = 0xff;
                                    refresh = 1;
                                }
                            }
                            if (list[3] == k) {
                                list[3] = 0xff;
                                refresh = 1;
                            }
                        }
                        if (kind == 0x20 && (*(u8 **)(e + 0x1f8))[0x20] != p->f20) {
                            found = 0;
                            diff = 1;
                            slot = k;
                        }
                        break;
                    }
                } else if (slot == 0xff) {
                    slot = k;
                }
            }
            if (found != 0 || slot == 0xff)
                continue;
            e = list + slot * 0x24;
            *(u32 *)(e + 0x1e4) = 1;
            *(u32 *)(e + 0x1e8) = 0;
            *(u32 *)(e + 0x1ec) = 0;
            for (m = 0; m < 6; m++)
                e[m + 0x1fd] = mac[m];
            if (kind == 0x20) {
                ((struct List *)list)->slots[slot].kind = 0x20;
                func_02082D44(p, ((struct List *)list)->slots[slot].buf, 0x34);
            } else {
                ((struct List *)list)->slots[slot].kind = 3;
                func_02082D44(p, ((struct List *)list)->slots[slot].buf, 0x64);
            }
            if (diff == 0) {
                for (r = 0; r < 15; r++) {
                    row = list + r * 0x1c;
                    if (row[0x58] == 0xff) {
                        row[0x58] = slot;
                        e[0x204] = r;
                        *(u32 *)(row + 0x40) = 1;
                        break;
                    }
                }
            } else {
                *(u32 *)(list + e[0x204] * 0x1c + 0x40) = 1;
            }
            changed = 1;
        }
    }
    for (i = 0; i < 15; i++) {
        e = list + i * 0x24;
        if (*(u32 *)(e + 0x1e4) == 1 && *(u32 *)(e + 0x1e8) == 1) {
            q = e[0x204];
            for (; q < 14; q++) {
                row = list + q * 0x1c;
                if (row[0x74] == 0xff)
                    break;
                row[0x58] = row[0x74];
                list[row[0x58] * 0x24 + 0x204] = q;
                *(u32 *)(row + 0x40) = 1;
            }
            row = list + q * 0x1c;
            row[0x58] = 0xff;
            *(u32 *)(row + 0x40) = 1;
            e[0x204] = 0xff;
            *(u32 *)(e + 0x1e4) = 0;
            for (m = 0; m < 3; m++) {
                if (i == list[m]) {
                    list[m] = 0xff;
                    refresh = 1;
                }
            }
            if (list[3] == i) {
                list[3] = 0xff;
                refresh = 1;
            }
            i--;
            changed = 1;
        }
    }
    if (changed == 1) {
        func_021BCB88(ctx, list);
        refresh = 1;
        *(u32 *)(list + 0xc) = 1;
    }
    if (refresh == 1 && *(u32 *)(list + 8) == 5)
        func_021BCEF8(ctx, list);
}
