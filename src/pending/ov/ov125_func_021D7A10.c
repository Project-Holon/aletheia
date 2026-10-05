/*
 * function: func_021D7A10
 * address: 0x021D7A10
 * packet: pkt_ov125_021D7A10
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * note 2026-10-04 wD3 lane14: complete draft, 2 bytes differ (listing +CC,+D0): in the sz==-1 path the original stores and compares the callee result r0 (str r0,[sp]; cmp r0,r8) after mov r4,r0; ours uses r4. Tried tmp then sz order, sz assigned after check, common-tail store with tmp. The 4-byte hdr copy is written as byte copies through an unsigned char pointer (add r5,sp,#0 matches only that way).
 * symbols:
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D7808 0x021D7808 arm ov125
 *   func_021D89EC 0x021D89EC arm ov125
 *   func_021D891C 0x021D891C arm ov125
 *   func_021D7C7C 0x021D7C7C arm ov125
 *   func_021D7D30 0x021D7D30 arm ov125
 *   func_02092344 0x02092344 arm
 *   d_021D9E40 0x021D9E40 data a4
 */

/*
 * 2026-10-05 (wave D4 lane07): DIFF, unchanged 2 bytes (+CC/+D0, str/cmp use r4 instead of the call result r0). Tried (all identical output): chained `hdr = sz = f(id)`, `sz = hdr = f(id)`, `hdr = tmp = f(); sz = tmp`, `sz = tmp = f(); hdr = tmp`, assignment inside the if condition, tmp unsigned, callee returning unsigned, sz parameter unsigned, hdr stored first and compared through hdr then copied to sz (before or after the check). The same str r0/cmp r0 shape appears for the global store D(0x25c) = f(); if (D(0x25c) == -1) in this function, so the original probably compared a value the compiler did not merge with sz.
 */
/*
 * 2026-10-05 (wave D5 lane09): DIFF, 2 bytes unchanged. Reading: the original keeps the call result in
 *   r0 for the hdr store and the -1 compare and copies it to r4, so the result temp is NOT coalesced
 *   with sz (it is coalesced with r0); in every draft form it is coalesced with sz. Tried: hdr as a
 *   union {u8 b[4]; int i;} with member stores/compare (no address-of; worse, byte copy loses the
 *   add r5,sp,#0 pointer), a separate `size` local for both arms (identical). Next: find a use that
 *   makes the result temp interfere with sz (old sz live after the call).
 */
/*
 * 2026-10-05 (wave D6 lane02): DIFF, 2 bytes unchanged. Callee check: func_021D891C(int n) takes one
 *   argument (matched), so no hidden argument. Tried: the copy to sz after the -1 check (sz = tmp
 *   at the end of the else arm, identical), sz as the address-taken source of the 4-byte copy
 *   (h = &sz: the parameter goes to the stack, 365 bytes worse; hdr is a separate local at [sp]).
 *   Reading: the result temp is coalesced with sz in every form; the original coalesces it with r0.
 */
/*
 * 2026-10-05 (wave D7 lane07): DIFF, 2 bytes unchanged (+CC str, +D0 cmp use r4, image r0).
 *   Tried (all identical, 2 bytes): if/else polarity swapped (`if (sz == -1)` first: 54 bytes worse,
 *   so the then-arm is sz != -1); tmp declared in the inner block; tmp declared last; the call
 *   through a static inline helper (returning the value, or also storing hdr through a W4 pointer);
 *   the dead parameter x reused as the result temp; sz = f(id) with the check read through
 *   `hdr`. Comparing the result against the old sz (== -1 in that arm) makes the old sz
 *   live across the call: 380 bytes worse (frame changes). Reading: mwcc coalesces the call
 *   result with sz in every source form; the image keeps it in r0. No source lever found.
 */
/*
 * 2026-10-05 (wave D8 lane08): DIFF, 2 bytes unchanged. Tried: one temp for both arms (`tmp = sz + 0x140` in
 *  the then-arm, `tmp = f(id)` in the else-arm, hdr stored from tmp in each arm, `sz = tmp` after the join):
 *  identical 2 bytes, the call result is still coalesced with the size register r4.
 */
/*
 * 2026-10-05 (wave D9r lane10): DIFF, 2 bytes unchanged. Tried: a static inline Load(&sz, &hdr, id) that stores the
 *  result through both pointers and returns it for the -1 test; `sz = f(id); hdr = sz; if (hdr == -1)`.
 *  Both identical (2 B). The result is still coalesced with sz.
 */
/*
 * 2026-10-05 (wD9r lane184): DIFF, 2 bytes unchanged. Idiom research (copy coalescing, call result in r0, dying-local
 *  register, parameter reassign, flag-after-call interference) found no form that keeps the else-arm result as its own
 *  web. Callers pass sz = -1 or a payload size, so then-arm sz + 0x140 and the callee (size + 0x140) are the same
 *  quantity. Tried (all identical 2 B): callee returning a one-value enum with an enum temp (compare against the enum
 *  constant); temp as `unsigned long`; `const int` parameter copied into a local sz; then-arm routed through tmp
 *  (`tmp = sz + 0x140; hdr = tmp; sz = tmp`). Only the long long temp (lane170) breaks the copy merge, and it is a
 *  stand-in, so this stays DIFF.
 */
/*
 * 2026-10-05 (wD9r lane189): DIFF, 2 bytes unchanged. Re-derived the flow from the listing: then-arm (sz != -1) is
 *  `addne r4,#0x140; strne r4,[sp]; bne join`, else-arm falls through into the call, hdr store and -1 test; no
 *  unconditional call and no check on the then-arm. Tried (real compiles): then-arm ends `goto join` with the else
 *  body straight-line after it (2 B); call as `hdr = (tmp = f(id))` inside the store, test on tmp, then
 *  `sz = hdr` (2 B); else-arm first (`if (sz == -1)`, 54 B). Idiom files read, see report.
 */
/*
 * 2026-10-05 (wD9r lane192): DIFF, 2 bytes unchanged. Listing check: [sp] is only read by the 4 byte copy (r5 = sp),
 *  its address is not passed to any callee, so no address-escape use makes sz a reload. Tried: result stored only
 *  through hdr, tested through hdr, `sz = hdr` after the -1 check (2 B). Per-arm and predication
 *  idioms read (see report): none gives a separate web for the else-arm result.
 */
/*
 * 2026-10-05 (wD9r lane205): DIFF, 2 bytes unchanged. Real compiles with the memcpy(p, &hdr, 4) draft: switch (tmp)
 *  { case -1: ... } for the -1 test (2 B); hdr the only variable written in the else arm (`hdr = f(id); if (hdr == -1)
 *  err; sz = hdr;`, also with the then-arm `sz += 0x140; hdr = sz`) (2 B); memcpy(p, &sz, 4) with sz address-taken and
 *  the call result written to sz, no hdr (365 B, parameter goes to the stack); hdr as `int hdr[1]` with memcpy(p, hdr, 4)
 *  (2 B); hdr written through a pointer local `int *ph = &hdr` (381 B). Idioms read: reassigning-a-parameter-keeps-its-
 *  register, a-value-returned-on-the-early-path-precolours-its-register-to-r0, a-result-computed-in-a-dying-local-takes-
 *  that-locals-register, a-flag-set-after-the-call-that-consumes-its-input-shares-that-inputs-register,
 *  address-of-a-register-parameter-is-a-push-of-all-four, a-missing-return-hands-back-the-parameter,
 *  two-long-lived-values-in-each-others-registers: none gives a separate web for the else-arm call result.
 */
/*
 * 2026-10-05 (wD9r lane210): DIFF, 2 bytes unchanged. Checked all seven matched callers: every one passes sz = -1 and a
 *  `const void *` local for buf, so the callers give no type for sz beyond int. Instruction-by-instruction register use
 *  compare against the image: only +CC (str) and +D0 (cmp) differ, every later read is r4 in both, so no later
 *  operation is missing. Tried: dead store between the copy and its use
 *  (docs/idioms/a-dead-store-between-a-temp-and-its-use-blocks-copy-propagation.md) as `sz = tmp; sz = 0; sz = tmp;`
 *  (2 B) and the same on hdr (`hdr = tmp; hdr = 0; hdr = tmp; sz = tmp`: 440 B, 199 differ). The coalesce is made by the
 *  allocator on the sz web, not by propagation of a store, so a dead store does not split it.
 */
/*
 * 2026-10-05 (wD9r laneS7): DIFF, 2 bytes unchanged. The working draft was intact (memcpy form, 2 B), kept. mwcc source
 *  (SpillCode_CoalesceCopies, CanCoalesce): a virtual copy `mov sz, tmp` is removed unless the two webs interfere or one
 *  is outside the coalesce window (objects numbered before Registers_BeginCoalesceWindow are never merged with another
 *  virtual). Interference needs sz live at a non-copy def of tmp, i.e. sz live across the call, but the image has no
 *  later use of the old sz (cmp r4,r8 is the last, then-arm redefines r4 in place). The copy-propagation pass (not in
 *  the public source) is what rewrites the tmp uses to sz in our output. Tried: `int tmp = f(id);` as a declaration
 *  with initialiser in the else block (decl-with-initializer ranks a web differently in the casebook): identical 2 B.
 *  No natural non-copy conversion found; only the long long temp (lane170) splits it.
 */
typedef struct { int w[0x138 / 4]; } Blob;
/*
 * 2026-10-05 (wave D9 lane16): DIFF, 2 bytes unchanged. Reading only: the image uses the call result r0 for the
 *  hdr store and the -1 compare the same way as the earlier `D(0x25c) = f(id); if (D(0x25c) == -1)`, so the
 *  else-arm value was probably never a named local before the check. All forms of that (store to hdr, compare
 *  hdr, copy to sz) are listed above as tried and give identical output. New tests: D(0x260) = x written in each
 *  arm (221 B worse, the store is not merged up); result stored only into hdr, compared through hdr, and
 *  `sz = hdr` at the end of the else arm (identical 2 B).
 */
/*
 * 2026-10-05 (wD9r lane46): DIFF, 2 bytes unchanged. Tried: hdr as a plain int local (address taken only for the
 *  byte copy) instead of the W4 struct: identical 2 B. Reading: the image pattern (mov r4,r0; then uses of r0)
 *  needs the call result to interfere with sz; no source form tried so far makes it do that.
 */
/*
 * 2026-10-05 (wD9r lane59): DIFF, 2 bytes unchanged. Tried: the call result and tmp as `long` (a non-int type,
 *  to block the copy coalesce) and sz as a `long` parameter: identical 2 B. hdr written in both arms with no sz
 *  update and `sz = hdr` once after the join: 209 B worse (reload from the stack). Reading: the else-arm
 *  call result must interfere with sz to stay in r0; no natural use found that makes it interfere.
 */
/*
 * 2026-10-05 (wD9r lane80): DIFF, 2 bytes unchanged in the draft. Tried: both -1 error paths through one shared
 *  `err:` label (goto from the D(0x25c) check): 416 B, the error blocks merge and the base register changes, so the
 *  image has two separate error copies. Reading: func_021D891C (matched) returns size + 0x140, so the then-arm
 *  `sz + 0x140` and the else-arm call give the same quantity; the call result still coalesces with sz.
 */
/*
 * 2026-10-05 (wD9r lane88): DIFF, 2 bytes unchanged. Callee prototypes checked against the matched definitions
 *  (func_021D891C int(int), func_021D89EC int(int), func_021D7C7C void(int), func_021D7D30 returns its tail call):
 *  no mismatch that matters here. Tried: one `tmp` local reused for both -1 checks (D(0x25c) = tmp and the else-arm
 *  result, so tmp has two definitions and cannot be propagated); else-arm as `else if ((hdr = sz = f(id))
 *  == -1)`; result stored only to hdr, tested as tmp, `sz = hdr` last. All identical (2 B, str/cmp on r4).
 */
/*
 * 2026-10-05 (wD9r lane100): DIFF, 2 bytes unchanged in the draft. Twin search: no other function in src/matched or
 *  asm/overlays has the addne #0x140 / sz - 0x140 shape (only ov125 itself), so no twin to copy. Tried: the -1 error
 *  block as a static inline check helper `chk(v)` (sets D(0x13c)=9, D(0x250)=2, returns 0/1), called with sz, with the
 *  chained `hdr = sz = f(id)`, and a `chk2(&hdr, v)` that also stores hdr: all 456 B, 211 differ (the helper
 *  return merges badly; the call result is still coalesced with r4).
 */
/*
 * 2026-10-05 (wD9r lane119): DIFF, 2 bytes unchanged. Reading: our output also has `mov r4, r0` after the call;
 *  only the store and compare read r4 instead of r0, so the result temp is coalesced with sz and the copy is the
 *  call-result move. Tried the zero-valued-local add (docs/idioms/a-self-move-after-a-call-is-an-add-of-a-zero-valued-local.md)
 *  to stop the coalesce: `sz = tmp + z` with the existing z set to 0 at the top, and `sz = tmp + pad` /
 *  `sz = pad + tmp` with a fresh zero local (set at the top or in the else arm). All identical (2 B): in ARM the
 *  zero add folds before coalescing.
 */
/*
 * 2026-10-05 (wD9r lane133): DIFF, 2 bytes unchanged. Tried: `register int tmp;` (the storage class can change
 *  coalescing in some front ends): identical 2 B. Reading: the image shape (copy to r4 first, then str/cmp on r0)
 *  is what a phi copy placed at the end of the else block and scheduled up would give; every C form tried names
 *  one size variable in both arms, so mwcc coalesces the result into it. A ternary join would need the -1 check
 *  on the then-arm too, which the image does not have.
 */
/*
 * 2026-10-05 (wD9r lane149): DIFF, 2 bytes unchanged. Tried the join-copy reading: two size variables, one per arm
 *  (n1 = sz + 0x140 / n2 = f(id), each stored to hdr, merged into `size` at the end of each arm, `sz = size` after the
 *  join); `size = sz` copied first and used in both arms; the else arm ends `sz = hdr`; the call inside the
 *  else-if condition with the copy in a final else; the result held in the later pointer variable p, and in z. All
 *  identical 2 B: ours emits `mov r4, r0` then str/cmp on r4, so the result temp is still merged with the size.
 */
/*
 * 2026-10-05 (wD9r lane160): DIFF, 2 bytes unchanged. Tried the narrow-type levers of this wave: `unsigned short id`
 *  parameter (the id is only stored as a halfword): identical 2 B; the result temp and the callee return as unsigned
 *  int compared with 0xFFFFFFFF: identical; sz assigned from the call and the check read through `hdr`:
 *  identical; the check as `tmp + 1 == 0`: 472 B (the -1 constant in r8 is lost). The call result still coalesces
 *  with sz (r4).
 */
/*
 * 2026-10-05 (wD9r lane196): DIFF, 2 bytes unchanged. New finding: the 4-byte header copy is `memcpy(p, &hdr, 4)` with the
 *  house string.h (mwcc inlines it as the ldrb/strb x4 pair block with `add r5,sp,#0`), and hdr is a plain int. The draft
 *  now uses that instead of the unsigned char byte copy (same 444 B, same 2 B residue). Tried (real compiles): union
 *  {int; W4} hdr with a struct member copy `*(W4 *)p = hdr.w` (148 B); hdr as the single value written in both arms with
 *  `sz = hdr` after the join (209 B); sz derived from the stored header, `p = f(hdr)`, `D(0x254) = hdr` (236 B, sz
 *  reloaded); sz - 0x140 read back from the destination `*(int *)q` (108 B); `sz = f(id); hdr = sz` (2 B); `sz = hdr`
 *  after the -1 check (2 B). The call result still coalesces with sz.
 */
/*
 * 2026-10-05 (wD9r lane170): DIFF, 2 bytes unchanged in this draft. Found the mechanism and an EXACT form that
 *  is probably a stand-in. The image needs the call result as its own temp (coalesced with r0) and a separate
 *  copy into sz; mwcc merges a plain copy `sz = tmp` with tmp in every int, unsigned, long, pointer and struct-field
 *  form (all tried, 2 B). A real conversion is not merged: `long long v = func_021D891C(id); sz = (int)v;
 *  hdr = (int)v; if ((int)v == -1)` gives EXACT (444 B, saved as
 *  scratchpad wD9r/lane170_ov125_021D7A10_longlong.c). Not filed: a 64-bit temp for an int size has no basis in
 *  the listing (the high word is dead), so it is a type used only to block the copy merge. Also tried (identical
 *  2 B): a struct Hdr { int size; } local with `if ((hdr.size = f(id)) == -1)` then `sz = hdr.size`, the same with
 *  `sz = hdr.size` before the test, and `if ((sz = hdr.size = f(id)) == -1)`; func_021D891C declared returning the
 *  4-byte struct W4 (528 B, mwcc returns it through a hidden pointer). A scan of all overlay and arm9 listings finds
 *  this `bl; mov rN, r0; str/cmp r0` shape nowhere else, so the original likely used an unusual type or construct
 *  here. Next: look for a natural non-copy conversion between the result and sz (a different source type).
 */
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D7808(void);
extern int func_021D89EC(int);
extern int func_021D891C(int);
extern char *func_021D7C7C(int);
extern int func_021D7D30(void);
extern void *func_02092344(void *, const void *, unsigned);
extern char d_021D9E40[];
#include "../../matched/arm9_sdk/libc/string.h"
#define D(o) (*(int *)(d_021D9E40 + (o)))
int func_021D7A10(int id, void *buf, int x, int sz)
{
    int tmp;
    int hdr;
    char *p;
    char *q;
    int z;
    func_021D7CAC();
    switch (D(0x13c)) {
    case 0: case 2: case 3: case 4: case 5: case 6:
        func_021D7CC0();
        D(0x13c) = 9;
        D(0x250) = 1;
        return 0;
    case 7:
    case 8:
    case 9:
        func_021D7808();
        break;
    }
    func_021D7CC0();
    D(0x25c) = func_021D89EC(id);
    if (D(0x25c) == -1) {
        D(0x13c) = 9;
        D(0x250) = 2;
        return 0;
    }
    D(0x260) = x;
    if (sz != -1) {
        sz += 0x140;
        hdr = sz;
    } else {
        tmp = func_021D891C(id);
        sz = tmp;
        hdr = tmp;
        if (tmp == -1) {
            D(0x13c) = 9;
            D(0x250) = 2;
            return 0;
        }
    }
    p = func_021D7C7C(sz);
    D(0x258) = (int)p;
    if (p == 0) return 0;
    D(0x254) = sz;
    memcpy(p, &hdr, 4);
    q = *(char **)&D(0x258);
    *(unsigned short *)(q + 4) = id;
    *(Blob *)(q + 8) = *(Blob *)d_021D9E40;
    z = 0;
    *(unsigned short *)(q + 6) = z;
    func_02092344(q + 0x140, buf, sz - 0x140);
    D(0x13c) = 2;
    func_021D7CAC();
    if (func_021D7D30() == 0) {
        D(0x13c) = 9;
        D(0x250) = 6;
        func_021D7CC0();
        return z;
    }
    func_021D7CC0();
    return 1;
}
