/*
 * function: func_021C11F0
 * address: 0x021C11F0
 * packet: pkt_ov093_021C11F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 *
 * 2026-10-05 (Q10, pengy share, user-approved): full body written from the listing, 704 B, 48 bytes differ
 * (all frame/order residue, no logic difference). Locals in slot order: sum, v28 (u8), cnt, cnt2, cnt3, then the
 * second loop index. Callee arrays are one pool word each (B=021F3B20 also has a second name for the +0xC read,
 * a duplicate pool word); 021C4104 takes sa/sb as separate stack args (no struct temp, which grew the frame);
 * 021C1198 takes an int (a char prototype adds asrs); a7 is a one-bit field struct (lsls/lsrs #0x1f).
 * Residue 1: the second-loop index is at [sp+0x1c] and the loop-C i*4 temp at [sp+0x14]; the image has them
 * the other way round (index 0x14, temp 0x1c). Residue 2: at the 021C5798 call the image loads r3 (array A)
 * before the flag shift and cnt3 into r2 last; at the 5840/59C4 calls `str r6,[sp]` comes first. Tried: declaration
 * orders, a separate index per loop, reusing i (worse, 53 B), u8 flag (extra lsls/lsrs), u32 flag (hoists B into r6),
 * all six per-function pragmas (lifetimes, dead_assignments, peephole, scheduling: 48 B unchanged; propagation 70;
 * common_subs 572). Idioms checked: function-scope-versus-block-scope-decides-spill-slot-order (declaration moves: no change),
 * a-separate-index-local-per-loop-reorders-spill-slots (no change), a-byte-count-local-preserves-word-spills-and-reloads
 * (u8 v28 closed 345 -> 48 B, as u8-returning callee idiom), a-stack-parameter-spilled-to-its-home-slot (n/a).
 *
 * 2026-10-05 (Q10b, pengy share, user-approved): 47 B differ. Fixed: the last loop's byte argument is
 * d_021F3B20[k] (pool word 3B20, as the image), not d_021F3B23[k] (-1 B, pool offset now matches); the
 * d_021F3B38 relocation resolves once its symbols line drops the contested ov093 token (33 of 33 resolved).
 * Residue unchanged otherwise: slot swap (m index 0x14 / k temp 0x1c in the image) and the 5798/5840/59C4
 * argument order (cnt3 reload and `str r6,[sp]` sit below/above the other loads). Tried, no change or worse:
 * a7.f inline at all three calls (no flag local); cnt3 u8 / u16 with and without the (u8) cast; 5798/5840/59C4
 * count parameter u8 (same bytes); flag parameter u8 (398 B, extra masks) or u32 (same); u8 return on 021C0CE8
 * (413 B, drops the truncation); m declared first (59 B) or last (same); loop indexes declared in for-init (same);
 * a named `off = k*4` in loop C, and in both loops B and C (folded into a temp, same slots); one index for
 * loops B and C (same). Real callees: 021C5798 has only six parameters in its matched file, so the last two
 * stack stores (3B20, flag) are leftover arguments of the original call. Idioms checked also: a-reload-kept-below-
 * outgoing-stack-stores-is-a-narrow-local (u8 cnt3: no change), a-u16-accessor-result-held-in-a-u16-local-moves-the-
 * stack-argument-stores (u16 cnt3 and u8 count params: no change), a-redundant-second-assignment-keeps-an-offset-local-
 * out-of-the-temp-slots (needs a redundant statement, banned stand-in; not filed), an-argument-bound-through-an-inline-
 * wrapper (opposite direction), a-const-record-pointer / a-const-table-load (no const source here).
 *
 * 2026-10-05 (Q10c, pengy share, user-approved): still 47 B. Callee check: the original 021C5798 call sets r0-r3 plus
 * four stack words ([sp]..[sp,#0xc]), so the callee has 8 parameters; its matched file now declares the two extra
 * unused ones (u8 *unused1, int unused2) and stays EXACT in c99 and c. 021C5840 (r0-r3 + [sp]) and 021C59C4 (r0-r3 + [sp])
 * already match their 5-parameter definitions, so no change there. This draft already passed every argument in the
 * original order, so the real 8-parameter prototype (flag as int) gives identical bytes. Tried: flag as `a7 & 1` on a
 * u32 a7 (344 B, worse). Residue unchanged: slot swap (original: i*4 temp at 0x1c between cnt2 and cnt3, m index at
 * 0x14 last; ours: m 0x1c, temp 0x14) and the 5798/5840/59C4 argument order. Idioms checked: none new.
 * final push 2026-10-05 G7L9: still 47 B of 704 (3 research rounds, 40 compiles). Residue unchanged: (1) spill-slot order, image
 * ktemp(k*4) 0x1c > cnt3 0x18 > m 0x14, ours m 0x1c > cnt3 0x18 > ktemp 0x14 (slot order follows spill-candidate order, cost/degree);
 * (2) 5798/5840/59C4 argument setup: image stores the stack arguments first and reloads cnt3 after them, loads array A into r3
 * as the first filler; ours reloads cnt3 first and stores the flag last. Tried, all 47 B or worse: u8 flag local (391); function-scope
 * named `off = k*4` between cnt2 and cnt3 or declared last, used by byte-offset casts (47, still a temp); loop B2 index shared with m or
 * k (47); u8 cnt3 (47); u8 cnt3 with u8 count params on the three calls (47); callee pointer types from the matched files (47); opt_propagation
 * off alone (69, only loop guards) and with do-while plus explicit guards (47) plus a named array pointer or a copy of cnt3 before the
 * call (47); opt_lifetimes off with that form (47), opt_common_subs off (676 B); inline wrappers for the three calls (47); flag
 * computed before 1788 (68) or before the st[1] update (115); inline helper for loop C and loop B bodies (47); m declared before cnt3,
 * k before cnt3 (47); unprototyped callees 5798/5840/59C4 (57, moves cnt3 to 0x1c); u16 return on 021C0CE8 with u16 or int cnt3 (47);
 * local pointer alias for d_021F3B38 in loop C (47); m,k as u32 (61, unsigned compares), k alone (49), m alone (59); s16 m,k (712 B);
 * `cnt3 > m` and `m = m + 1` loop spellings (47); const on array externs needs const callee parameters (compile error, not filed).
 * Idioms read in full: of-two-equal-temps-the-later-born-one-gets-the-lower-register, opt-propagation-off-with-named-locals-pins-argument-
 * constants-against-stack-stores, a-const-record-pointer-moves-the-outgoing-stack-store-below-the-register-copies, a-const-table-load-moves-above-
 * the-outgoing-stack-store, a-table-load-kept-below-stack-argument-stores-is-a-non-const-extern, a-load-scheduled-above-an-unrelated-store-reads-
 * through-a-const-pointer, an-argument-bound-through-an-inline-wrapper, a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local,
 * a-narrow-spilled-parameter-keeps-its-reload-below-a-store, a-u16-accessor-result-held-in-a-u16-local, a-redundant-second-assignment-keeps-an-
 * offset-local-out-of-the-temp-slots, a-separate-index-local-per-loop, a-spilled-local-assigned-twice, local-declaration-order-is-stack-order,
 * u8-locals-to-u8-callee-parameters, a-byte-count-local-preserves-word-spills (all 47 B or inert here). Matched-assembly search: no other function
 * has `str rN,[sp]; ldr r1,[sp,#K]; ldr r2,[pc]`; the spilled-index loop pattern occurs in func_0200EA3C, ov094 022057CC, ov120 021D6328,
 * ov183 021DF428, ov194 021F513C (all matched, read: no shape that transfers). Facts for the next try: the six tables are one
 * 0x24-byte object at 0x021F3B20 (a[3], b[3], c[3] u16, d[3] u32, e[3] ptr); the +0xC read is d[0]. Source forms that move slot order
 * (unsigned m/k, unprototyped callees) permute all three slots, so a legit cost change exists but was not found.
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D5FC0  0x021D5FC0  thumb  ov093
 *   func_021C14B0  0x021C14B0  thumb  ov093
 *   func_021C14C0  0x021C14C0  thumb  ov093
 *   func_021C14D0  0x021C14D0  thumb  ov093
 *   func_021C0C38  0x021C0C38  thumb  ov093
 *   func_021C0CB4  0x021C0CB4  thumb  ov093
 *   func_021C0CE8  0x021C0CE8  thumb  ov093
 *   func_021C0D70  0x021C0D70  thumb  ov093
 *   func_021C1184  0x021C1184  thumb  ov093
 *   func_021C1194  0x021C1194  thumb  ov093
 *   func_021C1198  0x021C1198  thumb  ov093
 *   func_021C15E8  0x021C15E8  thumb  ov093
 *   func_021C16F8  0x021C16F8  thumb  ov093
 *   func_021C1788  0x021C1788  thumb  ov093
 *   func_021C1828  0x021C1828  thumb  ov093
 *   func_021C1880  0x021C1880  thumb  ov093
 *   func_021C1CCC  0x021C1CCC  thumb  ov093
 *   func_021C1DCC  0x021C1DCC  thumb  ov093
 *   func_021C4104  0x021C4104  thumb  ov093
 *   func_021C4218  0x021C4218  thumb  ov093
 *   func_021C4F64  0x021C4F64  thumb  ov093
 *   func_021C5798  0x021C5798  thumb  ov093
 *   func_021C5840  0x021C5840  thumb  ov093
 *   func_021C59C4  0x021C59C4  thumb  ov093
 *   d_021F3B2C  0x021F3B2C  data  ov093  a4
 *   d_021F3B20  0x021F3B20  data  ov093  a4
 *   d_021F3B38  0x021F3B38  data  a4
 *   d_021F3B26  0x021F3B26  data  ov093  a4
 *   d_021F3B23  0x021F3B23  data  ov093  a4
 *   d_021F3B20b 0x021F3B20  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Fl { u32 f : 1; };

extern u32 d_021F3B2C[];
extern u8 d_021F3B20[];
extern u8 *d_021F3B38[];
extern u16 d_021F3B26[];
extern u8 d_021F3B23[];
extern u32 d_021F3B20b[];

extern u8 func_021D5440(u8 *p);
extern int func_021D6D7C(u8 *c);
extern void func_021D5FC0(void *c, int v);
extern u8 func_021C14B0(void *p, int n);
extern void func_021C14C0(void *w, u8 *c, int h, int f);
extern void func_021C14D0(void *w, u8 *c, int d, int f);
extern int func_021C0C38(u8 *p, u8 *q, void *o1, void *o2, void *o3, void *o4);
extern int func_021C0CB4(u8 *p, u8 *q, void *out);
extern int func_021C0CE8(u8 *p, u8 *q, void *o1, void *o2, void *o3, void *o4, void *o5);
extern u32 func_021C0D70(u8 *q);
extern int func_021C1184(u8 *p);
extern u8 func_021C1194(u8 *p);
extern void func_021C1198(u8 *p, int x);
extern void func_021C15E8(u8 *p, u8 *a, u8 *b, u16 *c);
extern void func_021C16F8(u8 *p, u8 *a, int k);
extern void func_021C1788(u8 *p, u16 *x, u8 *a, u32 n, void *arr);
extern void func_021C1828(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w);
extern void func_021C1880(u8 *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1);
extern int func_021C1CCC(u8 *p, u16 *x, u8 *a, u8 *q);
extern void func_021C1DCC(u8 *p, u8 *q, u8 *a, u8 *b, u32 s);
extern int func_021C4104(u8 *p, u8 *q, u8 *c, u16 d, int sa, u8 sb, u16 *e);
extern void func_021C4218(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
extern void func_021C4F64(u8 *p, u8 *a);
extern void func_021C5798(u8 *p, u16 *a, u32 n, void *arr, void *ptrs, void *vals, void *w, int f);
extern void func_021C5840(u8 *p, u32 count, void *v, void *a, int flag);
extern void func_021C59C4(u8 *p, u32 n, void *a, void *b, int flag);

int func_021C11F0(u8 *p, u8 *x, u32 unused, u8 *y, u16 *e, u8 *st, u32 a6, struct Fl a7)
{
    int sum;
    u8 v28;
    int cnt;
    int cnt2;
    int cnt3;
    int h;
    int i;
    int j;
    int k;
    int flag;
    int m;
    int b;
    int d;

    v28 = func_021C14B0(p + 0x1AB8, func_021D5440(x));
    sum = func_021C0D70(y);
    cnt = (u8)func_021C0C38(p, y, d_021F3B38, d_021F3B26, d_021F3B2C, d_021F3B20);
    for (i = 0; i < cnt; i++) {
        if (func_021D6D7C(d_021F3B38[i])) {
            h = func_021C4104(p, x, d_021F3B38[i], d_021F3B26[i], d_021F3B2C[i], d_021F3B20[i], e);
            func_021C14C0(*(void **)(p + 0x860), d_021F3B38[i], h, 1);
            sum -= d_021F3B26[i] - h;
        }
    }
    if (func_021C1184(st)) {
        cnt2 = (u8)func_021C0CB4(p, y, d_021F3B38);
        for (j = 0; j < cnt2; j++)
            func_021C15E8(p, x, d_021F3B38[j], e);
    }
    st[1] = st[1] + 1;
    cnt3 = (u8)func_021C0CE8(p, y, d_021F3B38, d_021F3B26, d_021F3B2C, d_021F3B20, d_021F3B23);
    if (cnt3 == 0)
        return sum;
    func_021C1788(p, e, x, cnt3, d_021F3B38);
    flag = a7.f;
    func_021C5798(p, e, cnt3, d_021F3B2C, d_021F3B38, d_021F3B26, d_021F3B20, flag);
    if (func_021C1194(st) == 0)
        func_021C5840(p, cnt3, d_021F3B2C, d_021F3B38, flag);
    else
        func_021C1198(st, d_021F3B20b[3]);
    func_021C59C4(p, cnt3, d_021F3B38, d_021F3B20, flag);
    for (m = 0; m < cnt3; m++) {
        func_021C14D0(*(void **)(p + 0x860), d_021F3B38[m], d_021F3B26[m], 0);
        func_021C1828(p, v28, x, d_021F3B38[m], (u8 *)e, d_021F3B26[m]);
        func_021D5FC0(d_021F3B38[m], 2);
    }
    for (b = 0; b < cnt3; b++) {
        if (d_021F3B23[b])
            func_021C16F8(p, d_021F3B38[b], d_021F3B23[b]);
    }
    for (k = 0; k < cnt3; k++) {
        func_021C1CCC(p, e, x, d_021F3B38[k]);
        func_021C1DCC(p, (u8 *)e, x, d_021F3B38[k], d_021F3B26[k]);
        func_021C1880(p, (u8 *)e, x, d_021F3B38[k], d_021F3B26[k], 0);
        func_021C4218(p, x, d_021F3B38[k], (u8 *)e, d_021F3B2C[k], d_021F3B26[k], d_021F3B20[k], 0);
    }
    for (d = 0; d < cnt3; d++)
        func_021C4F64(p, d_021F3B38[d]);
    func_021C4F64(p, x);
    return sum;
}
