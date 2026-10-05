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
 * 2026-10-05 (wave D4 lane07): DIFF, unchanged 2 bytes (+CC/+D0, str/cmp use r4 instead of the call result r0). Tried (all identical output): chained `*(int *)&hdr = sz = f(id)`, `sz = *(int *)&hdr = f(id)`, `hdr = tmp = f(); sz = tmp`, `sz = tmp = f(); hdr = tmp`, assignment inside the if condition, tmp unsigned, callee returning unsigned, sz parameter unsigned, hdr stored first and compared through hdr then copied to sz (before or after the check). The same str r0/cmp r0 shape appears for the global store D(0x25c) = f(); if (D(0x25c) == -1) in this function, so the original probably compared a value the compiler did not merge with sz.
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
 *   `*(int *)&hdr`. Comparing the result against the old sz (== -1 in that arm) makes the old sz
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
 *  result through both pointers and returns it for the -1 test; `sz = f(id); hdr = sz; if (*(int *)&hdr == -1)`.
 *  Both identical (2 B). The result is still coalesced with sz.
 */
typedef struct { int w[0x138 / 4]; } Blob;
/*
 * 2026-10-05 (wave D9 lane16): DIFF, 2 bytes unchanged. Reading only: the image uses the call result r0 for the
 *  hdr store and the -1 compare the same way as the earlier `D(0x25c) = f(id); if (D(0x25c) == -1)`, so the
 *  else-arm value was probably never a named local before the check. All forms of that (store to hdr, compare
 *  hdr, copy to sz) are listed above as tried and give identical output. New tests: D(0x260) = x written in each
 *  arm (221 B worse, the store is not merged up); result stored only into hdr, compared through hdr, and
 *  `sz = *(int *)&hdr` at the end of the else arm (identical 2 B).
 */
/*
 * 2026-10-05 (wD9r lane46): DIFF, 2 bytes unchanged. Tried: hdr as a plain int local (address taken only for the
 *  byte copy) instead of the W4 struct: identical 2 B. Reading: the image pattern (mov r4,r0; then uses of r0)
 *  needs the call result to interfere with sz; no source form tried so far makes it do that.
 */
/*
 * 2026-10-05 (wD9r lane59): DIFF, 2 bytes unchanged. Tried: the call result and tmp as `long` (a non-int type,
 *  to block the copy coalesce) and sz as a `long` parameter: identical 2 B. hdr written in both arms with no sz
 *  update and `sz = *(int *)&hdr` once after the join: 209 B worse (reload from the stack). Reading: the else-arm
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
 *  result, so tmp has two definitions and cannot be propagated); else-arm as `else if ((*(int *)&hdr = sz = f(id))
 *  == -1)`; result stored only to hdr, tested as tmp, `sz = *(int *)&hdr` last. All identical (2 B, str/cmp on r4).
 */
typedef struct { unsigned char b[4]; } W4;
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D7808(void);
extern int func_021D89EC(int);
extern int func_021D891C(int);
extern char *func_021D7C7C(int);
extern int func_021D7D30(void);
extern void *func_02092344(void *, const void *, unsigned);
extern char d_021D9E40[];
static inline void cp4(W4 *d, const W4 *s) { *d = *s; }
#define D(o) (*(int *)(d_021D9E40 + (o)))
int func_021D7A10(int id, void *buf, int x, int sz)
{
    int tmp;
    W4 hdr;
    char *p;
    char *q;
    unsigned char *h;
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
        *(int *)&hdr = sz;
    } else {
        tmp = func_021D891C(id);
        sz = tmp;
        *(int *)&hdr = tmp;
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
    h = (unsigned char *)&hdr;
    p[0] = h[0]; p[1] = h[1]; p[2] = h[2]; p[3] = h[3];
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
