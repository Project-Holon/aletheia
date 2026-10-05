/*
 * function: func_021BDE98
 * address: 0x021BDE98
 * packet: pkt_ov093_021BDE98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-05, wave D9r lane P5): first source for this function. DIFF, 12 bytes
 *   (6 halfwords) from EXACT, size 1184 equals the listing extent. Residue: at 021BDEFE..021BDF1C the
 *   original puts `adds r7, r6, #0` (copy of the move id into the second callee-saved register)
 *   right after `ldr r0, [r0]`, before the select-field shifts, and stores the zero flag
 *   (`str r1, [sp, #0x28]`) after the select store. The draft sinks the copy to just before
 *   the first func_021D62C4 call and hoists the flag store. Everything else matches, including frame
 *   0x4c and all spill slots.
 *   Closed by: CD4B0 call written through a static inline wrapper (arguments evaluated last to first,
 *   docs/idioms/an-inline-wrappers-arguments-are-evaluated-last-to-first.md), func_021D5778 declared u8 with a u8 local
 *   (drops the reload hoist above the outgoing store at the three func_021C07AC calls).
 *   Tried without effect on the residue: id2 assigned before/after sel, flag and o.c0
 *   (after sel makes act live in r7, 1000+ bytes off), id2 declared before id, id2 as int
 *   (1196 B), const on func_021C07AC pointer parameter, void return of func_021C07AC, inline wrapper
 *   for func_021C07AC, six per-function pragmas (lifetimes, propagation, common_subs,
 *   dead_assignments, scheduling, peephole: no change or worse). 25 compiles used.
 *   Structure notes: the move id is bits 7..22 of *act, select bits 4..6. func_021D5C08 is read first
 *   and again near the end. Callees 021BE338..021BE398 are linker veneers.
 * note (2026-10-05, lane P5b): still DIFF, same 12 bytes. func_021BE550 fixed: its matched definition now
 *   takes a fourth (unused) parameter, because the original caller loads r3 above the branch and the
 *   4-argument call is needed for that hoist (3 arguments: 267 bytes off); definition is EXACT in c99 and c.
 *   New tries on the copy/flag residue (all worse): id2 = id before the pr call or chained
 *   `id2 = id = act->full.move` (colour flip, id in r7, 61 B); id2 = id after sel or between sel and flag,
 *   `Action w = *act` local with the copy between load and shifts, `id2 = act->full.move` second read
 *   (act moves into r7, id2 spilled, about 1000 B); dropping the else-branch `id2 = id` (same 12 B residue).
 *   Reading: all uses before the found branch use r6, so r7 = r6 is an early statement the compiler
 *   leaves late; a form that keeps it early without moving act into r7 is still unknown. 11 compiles.
 * note (2026-10-05, recoup lane R15): still DIFF, same 12 B (copy + flag store swapped). Levers 1 to 7 on
 *   the residue, 20 compiles, none better. 1 callee decls: all callees match their matched definitions (no change).
 *   2/3 declaration order: id2 first, between m and id, last (all 12 B); spill slots already equal. 4 statement
 *   position: id2 = id after flag, after sel, after o.c0, flag before/after o.c0, `o.c0 = flag = 0`,
 *   flag = 0 before the first CD chk call or before the prev call, `int flag = 0` at the declaration (all 12 B, or
 *   about 1000 B / 1188 B when id2 follows sel: the act->w reload CSE changes and the frame shifts). 6 const Action
 *   *act (with const callee prototypes) and `Action *const act`: 12 B. u32 flag: 12 B; int sel: 8 B larger.
 *   Reading: in the original the scheduler fills the ldr [act] latency slot with the copy and sinks the flag store
 *   below the select store; ours does the reverse and puts the copy right before the first bl. Ordering the
 *   source statements does not change that tie. 7 pragmas: header lists all six as tried, not repeated.
 *   Idioms checked: a-pool-word-order-residue-is-a-list-scheduler-tie (same class, no C shape),
 *   a-flag-set-after-the-call-that-consumes-its-input-shares-that-inputs-register (no change),
 *   a-dead-store-between-a-temp-and-its-use-blocks-copy-propagation (not applicable, would drop the copy),
 *   a-const-record-pointer-moves-the-outgoing-stack-store-below-the-register-copies and
 *   a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer (const act: 12 B).
 * symbols:
 *   func_021D5C08 0x021D5C08 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_021BE518 0x021BE518 thumb ov093
 *   func_021BDE48 0x021BDE48 thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
 *   func_021BE924 0x021BE924 thumb ov093
 *   func_021C001C 0x021C001C thumb ov093
 *   func_021C62D8 0x021C62D8 thumb ov093
 *   func_021C5604 0x021C5604 thumb ov093
 *   func_021C64B4 0x021C64B4 thumb ov093
 *   func_021CA7F4 0x021CA7F4 thumb ov093
 *   func_021C07AC 0x021C07AC thumb ov093
 *   func_021C0450 0x021C0450 thumb ov093
 *   func_021BEBD8 0x021BEBD8 thumb ov093
 *   func_021BE3A8 0x021BE3A8 thumb ov093
 *   func_021BE338 0x021BE338 thumb ov093
 *   func_021BE348 0x021BE348 thumb ov093
 *   func_021BE358 0x021BE358 thumb ov093
 *   func_021BE368 0x021BE368 thumb ov093
 *   func_021BE378 0x021BE378 thumb ov093
 *   func_021BE388 0x021BE388 thumb ov093
 *   func_021BE398 0x021BE398 thumb ov093
 *   func_021BE66C 0x021BE66C thumb ov093
 *   func_021BE620 0x021BE620 thumb ov093
 *   func_021C6458 0x021C6458 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C8810 0x021C8810 thumb ov093
 *   func_021C5620 0x021C5620 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021C024C 0x021C024C thumb ov093
 *   func_021BE7E4 0x021BE7E4 thumb ov093
 *   func_021BE6EC 0x021BE6EC thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021BEAB4 0x021BEAB4 thumb ov093
 *   func_021BE550 0x021BE550 thumb ov093
 *   func_021BEC58 0x021BEC58 thumb ov093
 *   func_021D6744 0x021D6744 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021C0780 0x021C0780 thumb ov093
 *   func_021BFE60 0x021BFE60 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021BFF60 0x021BFF60 thumb ov093
 *   func_021BE994 0x021BE994 thumb ov093
 *   func_021E0394 0x021E0394 thumb ov093
 *   func_021BE400 0x021BE400 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    u32 w;
} Action;
struct Out { u8 c0; u8 pad; u16 c2; u8 c4; };
struct Cell { u32 w[5]; };
extern u32 func_021D5C08(void *);
extern void func_021BD1E0(void *);
extern void func_021BE518(void *);
extern u16 func_021BDE48(void *, Action *);
extern int func_021D80BC(void *, int, void *, u16);
extern void func_021D82D0(Action *, u32, u32);
extern u8 func_021D5778(void *, u16);
extern int func_021D62C4(void *, int);
extern int func_021E02DC(u8 *, u16, u32);
extern void func_021BE924(u8 *, u8 *, u32);
extern int func_021C001C(u8 *, u8 *, u16, u16);
extern int func_021C62D8(u8 *, u8 *, u32, u32, u16 *);
extern void func_021C5604(u8 *, u8 *, int);
extern void func_021C64B4(u8 *, u16, u8 *, void *);
extern int func_021CA7F4(u8 *, u8 *, u16, const u8 *, void *);
extern int func_021C07AC(u8 *, u8 *, u32, u32, int);
extern void func_021C0450(u8 *, u8 *, u16, int);
extern void func_021BEBD8(u8 *, u8 *, int, int);
extern int func_021BE3A8(u8 *, u8 *, u16 *);
extern void func_021BE338(void *);
extern void func_021BE348(void *);
extern u32 func_021BE358(void *);
extern void func_021BE368(void *);
extern void func_021BE378(void *, void *);
extern void func_021BE388(void *, u32);
extern void func_021BE398(void *, u16, u32, u32);
extern void func_021BE66C(u8 *, u8 *, void *, int);
extern void func_021BE620(u8 *, u8 *, void *);
extern int func_021C6458(u8 *, u8 *, u32, u32, u8 *);
extern int func_021C99A0(u8 *, u8 *);
extern void func_021C8810(u8 *);
extern void func_021C5620(u8 *, u8 *, int, void *);
extern int func_021D5FC0(void *, u32);
extern int func_021C024C(u8 *, u8 *, u32);
extern int func_021BE7E4(u8 *, u8 *, u32, u32, u8 *);
extern int func_021BE6EC(u8 *, u8 *, u16, u32);
extern u8 func_021D5440(void *);
extern int func_021BEAB4(u8 *, u8 *, int, int, u8 *);
extern void func_021BE550(u8 *, u8 *, u16, void *);
extern u8 func_021BEC58(u8 *, u8 *, u16, void *);
extern void func_021D6744(u8 *, u8, int, u8, u16, u16);
extern void func_021CD4B0(void *, volatile u32, ...);
extern u8 func_021D69AC(u8 *, int);
extern void func_021C0780(u8 *, u8 *, int, u8);
extern void func_021BFE60(u8 *, u8 *);
extern int func_021D5BB0(void *, u32);
extern void func_021BFF60(u8 *, u8 *, int);
extern void func_021BE994(u8 *, u8 *, u32, u32);
extern void func_021E0394(u8 *, int);
extern void func_021BE400(u8 *, u16);

static inline void ev18(void *w, u32 x, u32 s, u32 c, u32 b, u32 i2, u32 i1)
{
    func_021CD4B0(w, 0x18, x, s, c, b, i2, i1);
}

#define F(o) (*(u8 **)(p + (o)))

void func_021BDE98(u8 *p, u8 *a, Action *act, u32 key)
{
    int k;
    u8 sel;
    u32 prev;
    int chk1, chk2;
    int found;
    int flag;
    u8 pr;
    u16 m;
    u16 id;
    u16 id2;
    struct Out o;

    prev = func_021D5C08(a);
    func_021BD1E0(F(0x4a8));
    func_021BE518(F(0x4b0));
    o.c2 = 0;
    o.c4 = 6;
    m = func_021BDE48(a, act);
    if (m != 0) {
        func_021D82D0(act, m, func_021D80BC(*(void **)(p + 4), *(int *)(p + 8), a, m));
    }
    id = act->full.move;
    pr = func_021D5778(a, id);
    id2 = id;
    sel = (u8)act->full.select;
    flag = 0;
    o.c0 = 0;
    chk1 = (u8)func_021D62C4(a, 0x19);
    chk2 = (u8)func_021D62C4(a, 0x1a);
    func_021E02DC(a, id, key);
    func_021BE924(p, a, id);
    if (func_021C001C(p, a, id, (u8)((chk1 != 0 || chk2 != 0) ? 1 : flag)) != 0) goto end;
    if (func_021C62D8(p, a, id, sel, &o.c2) == 0) {
        func_021C5604(p, a, id);
        func_021C64B4(p, id, a, F(0x1ab4));
        func_021CA7F4(p, a, sel, F(0x1ab4), F(0x850));
        func_021C07AC(p, a, id, pr, (int)F(0x850));
        flag = 1;
        func_021C0450(p, a, id, 0x1a);
        goto end;
    }
    found = (u8)((o.c2 != 0) ? 1 : 0);
    if (found) {
        func_021C5604(p, a, id);
        func_021BEBD8(p, a, id, sel);
        func_021E02DC(a, o.c2, key);
        id2 = o.c2;
        sel = o.c4;
    } else {
        id2 = id;
    }
    func_021C64B4(p, id, a, F(0x1ab4));
    if (found) {
        func_021C64B4(p, id2, a, F(0x1ab0));
        ((u32 *)F(0x1ab0))[4] |= 4;
        ((u16 *)F(0x1ab0))[1] = id;
        if (func_021BE3A8(p, a, (u16 *)F(0x1ab0)) != 0) {
            func_021C07AC(p, a, id, pr, (int)F(0x850));
            flag = 1;
            goto end;
        }
    } else {
        *(struct Cell *)F(0x1ab0) = *(struct Cell *)F(0x1ab4);
    }
    func_021BE338(F(0x850));
    func_021BE348(F(0x854));
    func_021CA7F4(p, a, sel, F(0x1ab0), F(0x850));
    {
        u32 v = (u8)func_021BE358(F(0x850));
        func_021BE368(F(0x850));
        func_021BE378(F(0x850), F(0x854));
        func_021BE388(F(0x854), v);
    }
    if (chk1 == 0 && chk2 == 0 && pr != 4) {
        func_021C07AC(p, a, id, pr, (int)F(0x850));
        flag = 1;
    }
    {
        k = 0x1ab4;
        func_021BE66C(p, a, *(void **)(p + k), 0x22);
        func_021BE620(p, a, *(void **)(p + k - 4));
        if (func_021C6458(p, a, id, id2, p + k + 0x30) != 0) {
            func_021C99A0(p, p + k + 0x30);
            k += 0x30;
            func_021C8810(p + k);
        } else {
            func_021C5604(p, a, id2);
        }
    }
    *(u16 *)(p + 0x1f74) = id2;
    if (func_021D62C4(a, 0x22) != 0) {
        func_021C5620(p, a, 0x22, 0);
        func_021D5FC0(a, 0xe);
    }
    if (func_021C024C(p, a, id2) == 0
        && func_021BE7E4(p, a, id2, sel, (u8 *)&o) == 0
        && func_021BE6EC(p, a, id2, sel) == 0) {
        func_021BE398(p + 0x1c, id2, *(u32 *)(p + 0x10), func_021D5440(a));
        func_021BE66C(p, a, F(0x1ab0), 0x23);
        if (func_021BEAB4(p, a, id2, *(int *)(p + 0x854), F(0x4ac)) != 0) {
            func_021BE550(p, a, id2, F(0x854));
        } else {
            o.c0 = func_021BEC58(p, a, id2, F(0x854));
        }
    }
end:
    func_021D5FC0(a, 3);
    if (flag != 0 || chk1 != 0 || id2 == 0xa5) {
        func_021D6744(a, sel, o.c0, F(0x1ab0)[6], id2, id);
        ev18(*(void **)(p + 0xc), func_021D5440(a), sel, o.c0, F(0x1ab0)[6], id2, id);
    } else if (func_021D69AC(a, 3) != 0) {
        func_021C0780(p, a, 3, 0);
    }
    if (prev != 0x10 && func_021D5C08(a) != 0x10) func_021BFE60(p, a);
    if (func_021D5BB0(a, 0xb) != 0) {
        func_021CD4B0(*(void **)(p + 0xc), 0x31, func_021D5440(a), 0);
        func_021BFF60(p, a, 0);
    }
    func_021BE994(p, a, id2, o.c0);
    if (o.c2 != 0) func_021E0394(a, o.c2);
    func_021E0394(a, id);
    func_021BE400(p, id2);
}
