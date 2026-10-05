/*
 * function: func_0220DA6C
 * address:  0x0220DA6C
 * packet:   pkt_ov198_0220DA6C
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD8 lane05): still DIFF 160. Reading: image slots are in declaration order (msg 0x30 .. half 0x18), so t
 *   and half are spilled in the first round; ours spills rec only in a later round (slot 0xc) and b instead of half.
 *   Tried: t and half both u8 (both lowest slots, as the image order allows): 424 B, 280 differ, p moves to r5.
 * 2026-10-04 (wave D3 lane 20): 384 of 408 bytes, 209 bytes differ. Structure is complete and
 * the prologue up to the first call group matches except register colours: the original has
 * p in r4, the 0x1F70 pool constant in r5, idx in r6, base (p+4) in r7; this draft swaps them.
 * Original frame is sub sp #0x34 with push r4-r7 (no r3): slots sp+0x30 msg, 0x2c off, 0x28 o,
 * 0x24 rec, 0x20 vec, 0x1c t, 0x18 half, 0x14/0x10/0xc one window temp per call arm. The two
 * arm calls tail-merge. half = (u8)(x / 2) is signed int math (lsrs 31; adds). Bitfield struct
 * R gives the lsls 24; lsrs 31 tests (u8 shift form gave asrs/tst). Locals w1..w3 for the
 * window temp gave 420 bytes (too big); removed. Next: find the declaration order that gives
 * these slots and r4=p.
 *
 * 2026-10-05 (wave D4 lane 10): still DIFF, draft code unchanged (209 bytes). Tried the sibling 0220D494
 *   shape (EXACT this wave): struct P fields, per-arm `ctxN = P->f1EAC` locals (the original spills ctx to
 *   0x14/0x10/0xc, one slot per call), `a = 0; b = 0; if (msg2) {...}`: 269-278 bytes, frame 0x38 + push r3.
 *   A `k = 0x1EAC` offset local for the tail is propagated (no change). Residue is colouring: original
 *   p r4, 0x1F70/0x1EAC in r5, idx/msg2 r6, base/b r7, t and half spilled; ours spills a and the 0x1EAC base.
 * 2026-10-05 (wD5 lane10, later): 192 bytes (compiled 420 of 408). func_02045770 now runs INSIDE put (as in the
 *   EXACT sibling 0220C8F0): p r4, idx/msg2 r6, base r7 and the 0x1F70 constant r5 now match the original up to +0xBC.
 *   Residue: a/b colours swapped (ours a r7, b r5), the 0x1EAC constant spills to an extra slot [sp,#0x30] (orig keeps it
 *   in r5), half is converted to short at the first put (orig passes it unconverted from slot 0x18), rec slot 0xc.
 *   Tried: u8 half (235), int x param with (short) casts in the arms (236, push r3), b before a (no change).
 * 2026-10-05 (wD6 lane07): 160 bytes (was 192), compiled 412 of 408. New: `b = a;` in the msg2 == 0 arm (the original
 *   `adds r7,r5,#0` copies a), which keeps the 0x1EAC base in r5 for the tail as in the original. Residue: b spills
 *   to [sp,#0x1c] and half takes r7 (original: b r7, t at 0x1c, half at 0x18 passed unconverted to the first put);
 *   rec spills to [sp,#0xc] (original 0x24). Tried on top: u8 half (first put then passes half unconverted as in the
 *   original, but a spills and the frame grows to 0x38: 280), short half (280), u32 put x with a (short) cast in the
 *   arms (279), half computed in each arm (289), msg2/a/b declared first or after vec (279).
 * 2026-10-05 (wD7 lane10): still DIFF (160). The original passes half to the first put with no s16 conversion and
 *   is 4 bytes shorter than ours (412 vs 408): the conversion is the only size difference. Tried: half, t, a, b all
 *   u8 with literal `b = 0` and a literal 0 third argument (280, frame 0x38); the same with an int put x and a
 *   (short) cast in the arms (277); int half with an int put x and (short) in the arms (279: half now spills and is
 *   passed unconverted as in the original, but p r5, b r6, t r7, and the 0x1EAC constant spills); font read inside
 *   put (no change); half as a CSE of `(u8)((w * 8 - t - a - b) / 2)` written at both uses with a w local (167:
 *   mwcc shares the /2, not the u8 value). Open: a source where half is known to fit in s16 while b keeps r7.
 * 2026-10-05 (wD9 lane20): still DIFF 160. `b = 0;` in the msg2 == 0 arm gives the same code as `b = a;` (mwcc copies
 *   the zero already in r5), so the natural form is used now. Finding: a u8 half still gets lsls/asrs at the first put
 *   when the put x parameter is short, so the original first call has an int (or u32) x and only the second x is
 *   narrowed. Tried: half declared after b (160); u8 half with an int put x and the short x callee prototype (160);
 *   int-x helper for the first put only, short-x put in the arms, int or u8 half (279/278, frame 0x38 + push r3, the
 *   0x1EAC constant spills). Open: the same split without the extra spill.
 * 2026-10-05 (wD9r lane13): still DIFF 160. Tried: no put helper, sibling 0220D494 shape (ctx1..ctx3 locals,
 *   direct func_0201C724 calls, (short) cast only on the second x): 279, p moves to r5. Finding: `short half`
 *   (with the short-x put) passes half to the first call unconverted from its slot, as in the original, and
 *   spills half; but then `a` spills (0x1c) instead of t, t takes r7, b r6, msg2 r4, p r5, and the 0x1EAC
 *   constant spills to an extra slot 0x34 (frame 0x38, push r3): 280. short t/a/b on top and `b = a;` on top:
 *   no change (280). Open: short half with the original colouring (t spilled, a in r5, b in r7, rec spilled
 *   in the first round at 0x24).
 * 2026-10-05 (wD9r lane23): still DIFF 160. Tried: a struct array `struct PP { void *f0; struct R recs[]; }`
 *   (R 0x4c bytes, mon at +0) with `rec = &pp->recs[n]` and `pp->recs[n].mon`: rec now spills in the first round
 *   at 0x24 and t at 0x1c as in the image, but n*0x4c stays in r7 (no base/off split), msg moves to 0x2c, b
 *   spills to 0x18 and half takes r7 (178). The same records through a `struct R *base = p + 4` local give
 *   the draft code again (160). Int-x put with `(short)` at the second call: 279 (as D9). Open: a source
 *   that keeps base (p+4) in r7 and off spilled while rec spills in the first round.
 * 2026-10-05 (wD9r lane46): still DIFF 160. Tried: the real return type u8 for func_02045738 (37 matched callers):
 *   no change (160; also no change on the u8-half variants). p + 4 + off written without the base local: identical.
 *   Sibling shape from 0220C4DC/0220D6DC (u32 x callee prototype, direct calls, ctx1..ctx3 locals read before each
 *   call, explicit (short) only on the second x) with t/half as int/int (279), u8/u8 (280), int/u8 (280); the same
 *   with the inline put and u32 x (279/280). Finding: in every form where half reaches the first call with no
 *   conversion, t takes a register and the 0x1EAC constant spills (frame 0x38, push r3); with the conversion,
 *   t spills and b spills instead of half. Open: the source that spills t and half together and keeps b and the
 *   constant in r7/r5.
 * 2026-10-05 (wD9r lane59): still DIFF 160. Tried: `a = 0;` moved into the msg2 == 0 arm with a literal 0 third
 *   argument (the image's r5 = 0 before the first width call is mwcc's block constant, not a separate a = 0):
 *   identical code (160), so this is the natural form but not the lever. The 0x1F74 flag through a struct field
 *   or `p[0x1F74]`: identical (160). Flag store and free written in each msg2 arm (to keep r5 = 0x1EAC as the
 *   base for +0xc4/+0xc8 as in the image): no cross-jump, 444 B, 272. Direct calls with ONE reused ctx local
 *   (the D6DC sibling shape) and t/half/a/b int (279), t/half u8 (280), all four u8 (275): every direct form
 *   moves p to r5, spills a (u8 slot 0x18) instead of t and spills the 0x1EAC constant (frame 0x38, push r3).
 * 2026-10-05 (wD9r lane80): still DIFF 160. Tried: `b = 0;` before the first width call with only `b = 8` in the
 *   msg2 arm (b now lives longer, as a test of whether a longer b range moves the spill to half): 420 B, 261 differ.
 *   Int-x helper for both puts with an explicit (short) on the second x and a short-x callee prototype: 424 B, 234.
 *   Reading: in the image b keeps r7 (the dead base register) for its whole range and half (shorter range) is
 *   spilled; every source form so far spills the longer-lived b. Open: a use or type that raises b's spill cost.
 * 2026-10-05 (wD9r lane88): still DIFF 160. Reading: the image slot order (msg 0x30, off, o, rec, vec, t, half 0x18,
 *   then win temps 0x14/0x10/0xc) is the declaration order, so the image spilled exactly {msg..half} in one round and
 *   kept msg2, a, b, base in registers; ours spills b instead of half and rec in a later round. Tried: half assigned
 *   inside the first put argument (`put(..., half = (u8)(...), ...)`): short-x put 416 B, 231; int-x put with
 *   (short) on the second x 428 B, 287. Open: a source that makes b costlier to spill than half.
 * symbols:
 *   func_022110D4  0x022110D4  thumb  ov198
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02045738  0x02045738  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   d_02211B68     0x02211B68  data  ov198  a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct R {
    u8 pad[0x16];
    u8 a0 : 7;
    u8 a1 : 1;
    u8 b0 : 3;
    u8 b1 : 4;
    u8 b2 : 1;
};
struct U16Vec;
struct WordSet;
struct MsgBank;

extern int func_022110D4(u8 *, int);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(void *vec);
extern u32 func_0201D304(void *, u32, u32);
extern int func_02045738(void *);
extern u32 func_02045770(void *);
extern void func_0201C724(void *, u32, u32, u32, void *, u32, u16);
extern u32 d_02211B68[];

static inline void put(void *win, void *sel, short x, u32 y, void *h, u32 fc, u16 color)
{
    func_0201C724(win, func_02045770(sel), x, y, h, fc, color);
}

void func_0220DA6C(u8 *p, u32 idx)
{
    void *msg;
    u32 off;
    void *o;
    struct R *rec;
    void *vec;
    int t;
    int half;
    void *msg2;
    int a;
    int b;
    u8 *base;
    int n;

    o = *(void **)(p + 0x1F70);
    n = func_022110D4(p, idx);
    base = p + 4;
    off = n * 0x4c;
    rec = (struct R *)(base + off);
    vec = func_020457B0(12, *(u16 *)(*(u8 **)p + 0x10));
    msg = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), d_02211B68[idx]);
    func_0201EEF4(*(struct WordSet **)(p + 0x1EA4), 0, *(void **)(base + off));
    msg2 = 0;
    func_0201F250(*(struct WordSet **)(p + 0x1EA4), vec, msg);
    func_02045808(msg);
    if (!rec->a1 && !rec->b2) {
        if (rec->b0 == 0) {
            msg2 = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x16);
        } else if (rec->b0 == 1) {
            msg2 = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x17);
        }
    }
    a = 0;
    t = (u8)func_0201D304(vec, *(u32 *)(*(u8 **)p + 0xc), 0);
    if (msg2 == 0) {
        b = 0;
    } else {
        a = (u8)func_0201D304(msg2, *(u32 *)(*(u8 **)p + 0xc), a);
        b = 8;
    }
    half = (u8)((func_02045738(o) * 8 - t - a - b) / 2);
    put(*(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), half, 7, vec,
        *(u32 *)(*(u8 **)p + 0xc), 0x3DC0);
    *(u8 *)(p + 0x1F74) = 1;
    func_02045808(vec);
    if (msg2 != 0) {
        if (rec->b0 == 0) {
            put(*(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), b + (half + t), 8, msg2,
                *(u32 *)(*(u8 **)p + 0xc), 0x2960);
        } else {
            put(*(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), b + (half + t), 8, msg2,
                *(u32 *)(*(u8 **)p + 0xc), 0x31A0);
        }
        *(u8 *)(p + 0x1F74) = 1;
        func_02045808(msg2);
    }
}
