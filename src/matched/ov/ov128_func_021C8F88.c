/*
 * function: func_021C8F88
 * address: 0x021C8F88
 * packet: pkt_ov128_021C8F88
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wave P5 lane T2): written from the listing, 460 bytes, same size, same
 *   instruction stream. Only residue: the loop counter i and the text buffer are in swapped
 *   callee-saved registers (original text r4, i/const 10 r5; build text r5, i/10 r4), 38 bytes
 *   of register operands plus entry-prologue order. Spill slots match (w1, buf2, gfx, pal, n
 *   declared in that order). Tried: six per-function pragmas (opt_lifetimes, opt_propagation,
 *   opt_common_subs, opt_dead_assignments, scheduling, peephole; none helps, opt_propagation
 *   is worse), decl order of i/x/t/text, do-while loop, i assigned before pal, ctx fields read
 *   inline in the loop (worse), int n. 17 compiles used.
 *   Struct: p is two 8-byte windows (desc at +0, +8), p+0x10 = archive handle, p+0x14 = out ptr;
 *   q+4 holds the save object; ctx+4 bank, +8 archive, +0x34 / +0x17c gfx args. Friend code
 *   screen: u64 key, 12 digits (u64 /10, %10), gap of 8 after every 4th digit.
 *   All callee prototypes already match the arity of the call sites.
 *   recoup 2026-10-05 (lane R20): lever 2 closed the entry-prologue part: heap as u16 here AND
 *   in func_020457B0 / func_02049EF4 prototypes (38 -> 22 B, the str r3 spill now comes first).
 *   Remaining 22 B: pure colour swap, classes {10, i} and {2, text} swapped (orig r5/r4, build r4/r5).
 *   Tried, no change: u8 heap, text/i decl order, w1 inline, x decl order, long i/x/n, six pragmas
 *   (propagation worse), pal/gfx swap 28, t before call 98, w1 late 39, u32/u8 i 146/130, i<13 24.
 *   Twin search: grep func_0205994C / func_021CA4B4 / func_02045AFC in src/matched/ov: no loop twin.
 *   Idioms checked: two-long-lived-values-in-each-others-registers (no applicable form),
 *   a-long-index-colours-apart-from-an-int (22), a-colour-swap-...-opt-lifetimes-off (22),
 *   a-loop-counter-zero-before-an-offset-assignment (n/a).
 *   final push 2026-10-05 G5L9 (40 compiles, all 22 B, same pure swap): the (u16) cast on the
 *   third blit argument is dropped (callee takes u16; same bytes, now plain). Tried, no change:
 *   block-scoped t/x/i, declarations at the point of use, u8* text, key decl first/last, i/x
 *   first, func_02045AFC u16 value, func_021C63AC with u8 fourth parameter, func_02045738 as u8
 *   (same bytes) with n u32/int/u8, named constants ten/two (int, u8; with opt_propagation off 449 B),
 *   constants as locals in both orders, text/buf2/key as declaration initialisers (30 B, only slot
 *   order moves), inline put()/blit() helpers, struct view of p (two windows), i++ as body statement
 *   (while, for with empty step; i++ before key= is 27 B), pragma pairs (lifetimes+common_subs,
 *   lifetimes+dead_assignments, common_subs+dead_assignments, lifetimes+peephole,
 *   lifetimes+scheduling, common_subs+peephole, dead_assignments+peephole). Reading of mwcc
 *   Coloring.c: nodes with degree >= K are pushed by lowest spill_cost/degree, popped last-first and
 *   take the lowest free colour. Both colourings are legal; in the build i is coloured before text
 *   (i takes r4, then text r5, v10 shares r4 with i, v2 shares r5 with text); the original colours
 *   text first. So the lever is i's cost/degree versus text's, not a declaration order. No human
 *   source form found that lowers i's cost or raises text's without changing the code.
 *   Matched-assembly search: halfword copy loops with a counter (asm/overlays, asm/arm9): only
 *   ov021 021CFB1C, ov093 021D54F4 (leaf copies) share the counter shape; neither shows the rule.
 *   pass 2 2026-10-06 P2L33 (35 compiles): EXACT in --lang c99 and --lang c. The text buffer is
 *   held as a u32 handle (the type func_021B6AE4 takes for its string argument, as the sibling
 *   ov128 021C9FC8 passes a u32 field), with (void *) at the pointer callees. A u32 local and a
 *   pointer local colour differently; with the u32 handle text takes r4 before the held constant
 *   10 and the loop counter, as in the original. Tried before this, no change: a local
 *   u16 digit array with an initialiser, explicit copy loops, inline helpers, statement order,
 *   prototype widths, loop/strength/unroll pragmas, a non-const table.
 * symbols:
 *   func_021C63AC 0x021C63AC thumb ov128
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 *   func_020457B0 0x020457B0 arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 *   func_0205994C 0x0205994C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045738 0x02045738 arm
 *   func_0204581C 0x0204581C arm
 *   func_02045AFC 0x02045AFC arm
 *   func_02045808 0x02045808 arm
 *   func_02049EF4 0x02049EF4 arm
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   d_021CA674 0x021CA674 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { u16 v[10]; } Tbl;
extern const Tbl d_021CA674;
extern void func_021C63AC(void *, u32 *, u32, u32, u8, u8, u8, u8, u32, u8);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void func_021CA4B4(char *p);
struct BigObj;
struct DWCstAccUserData;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_0201283C(const struct BigObj *p);
extern void *func_02009860(void *p);
extern unsigned long long func_0205994C(struct DWCstAccUserData *userdata);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u8 func_02045738(struct Descriptor *p);
extern void func_0204581C(struct U16Vec *vec);
extern void func_02045AFC(struct U16Vec *vec, u16 value);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02049EF4(void *arc, u32 id, u32 comp, void **out, u16 heap);
static inline u8 *second(u8 *p)
{
    return p + 8;
}
void func_021C8F88(u8 *p, u8 *q, u8 *ctx, u16 heap)
{
    u8 *w1;
    void *buf2;
    u32 gfx;
    u32 pal;
    u32 n;
    u32 text;
    u64 key;
    Tbl t;
    int x;
    int i;
    func_021C63AC(ctx, (u32 *)p, 3, 2, 10, 0x1e, 8, 10, 1, 0);
    func_021C63AC(ctx, (u32 *)(p + 8), 3, 9, 6, 0xe, 2, 10, 0xf1, 0);
    text = (u32)func_020457B0(0xc0, heap);
    buf2 = func_020457B0(0x80, heap);
    key = func_0205994C(func_02009860((void *)func_0201283C(*(void **)(q + 4))));
    if (key != 0) {
        func_02045CAC(*(void **)(ctx + 4), 0x35, (void *)text);
        func_021B6AE4(p, (void *)(*(u32 *)(ctx + 0x34)), 4, 0, text, *(u32 *)(ctx + 0x17c), 0x440, 0);
        func_021CA4B4(*(char **)p);
        pal = *(u32 *)(ctx + 0x17c);
        gfx = *(u32 *)(ctx + 0x34);
        t = d_021CA674;
        x = 0;
        n = func_02045738(*(void **)(p + 8));
        w1 = second(p);
        for (i = 1; i <= 12; i++) {
            func_0204581C((void *)text);
            func_02045AFC((void *)text, t.v[key % 10]);
            func_021B6AE4(w1, (void *)gfx, (n - i) * 8 - x + 1, 0, text, pal, 0x3c40, 0);
            if (i % 4 == 0)
                x += 8;
            key = key / 10;
        }
        func_021CA4B4(*(char **)(p + 8));
    } else {
        func_02045CAC(*(void **)(ctx + 4), 0x36, (void *)text);
        func_021B6AE4(p, (void *)(*(u32 *)(ctx + 0x34)), 4, 0, text, *(u32 *)(ctx + 0x17c), 0x440, 0);
        func_021CA4B4(*(char **)p);
    }
    func_02045808((void *)text);
    func_02045808(buf2);
    *(void **)(p + 0x10) = func_02049EF4(*(void **)(ctx + 8), 6, 0, (void **)(p + 0x14), heap);
}
