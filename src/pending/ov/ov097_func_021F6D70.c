/*
 * function: func_021F6D70
 * address:  0x021F6D70
 * packet:   pkt_ov097_021F6D70
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD9r lane95): still DIFF 25 B. New probes (each a real compile): (1) diagnostic only, w8 with its
 *   address passed to an extern call gives the image block-3 order exactly (stack stores, r3, then the w8
 *   load and add), so the image load has the alias class of an escaped local; but an escaped local always
 *   takes the top slot [sp,#0x40] at any declaration position (the image has 0x24) and the listing has no
 *   `add rX,sp` escape, so this is not the source. (2) w8 as a one-field struct or a union: memory slot 0x10,
 *   load still hoisted. (3) an inline reader `rd(&w8)`: promoted, 25. (4) u32 w8 with `(u8)w8` at both uses
 *   (CSE temp): slot 0x10, hoisted, 37. (5) the ov116 short-parameter lever: s16 w8 at all ten declaration
 *   positions (slot 0x10, hoisted, 37), s16 r7 with short w8 (39), 0201D304 declared returning
 *   s16/u16/signed char/int (25 each), an inline `sx(u8, short)` for the sum (59). Caller ov097 021F6A98
 *   passes only r0/r1, so w8 cannot be a short parameter. (6) diagnostic: dsi 1.1/1.2/1.2p1/1.3/1.6sp2 and
 *   -O4,s / -inline noauto / -opt nosched all give the same 25 B, so the residue is a source form.
 * 2026-10-05 (wD9r lane69): still DIFF 25 B. Probes: (s16)(r7 + 5) in place of the sum hoists the ALU chain to the
 *   top too, and a real memory load in the sum (`*(u8 *)(p + 0x30)`) stays below the stack stores, so the image
 *   treats w8 as a memory load, not a spill reload (same as ov116 021D7D0C, ov198 0220C16C). Tried: idx as
 *   u8/u16/s16 (narrow-parameter idiom, no change); w8 as a third u32/u8/int parameter (lowest slot, 36-37 B,
 *   reload still first); w8 as u8/u16/s16 local (37 B, same); the result through a u8- or u32-returning static
 *   inline (25/36 B); w8 written through an inlined out-pointer helper or `&w8` pointer local (still promoted);
 *   `x = r7 + w8` and `(s16)(w8 += r7)` as the argument (25 B); unprototyped 0201C724 (329 B). Open: a source
 *   form that keeps w8 in memory without volatile or an escaping address.
 * 2026-10-05 (wD9r lane50): still DIFF 25 B. Tried: the ov097 siblings' source shape (021F6B7C/021F6CE4:
 *   windows/dirty/mons/mi locals with the `windows = p; windows = p + 0x20;` double store, and a print_text
 *   static inline with int x for blocks 1 and 3): 330 B, the owner load moves above r7 and the block-3 chain is
 *   still hoisted; the block-1/3 calls through an inline with an s16/int/u32 x parameter (35/328/282 B, chain
 *   hoisted); a separate s16 x0 = r7 used in blocks 1 and 3 (25 B); `x3 = r7; x3 += w8;` (60 B); w8 as u8 (37 B,
 *   chain still first). The real-return-type lever that closed ov123 021D9D3C does not apply: lane26 already
 *   covered every void callee here.
 * 2026-10-05 (wD9r lane26): still DIFF 25 B. Tried: x3 = r7 + w8 as an s16 local assigned at the top right
 *   after r7 (same 25 B: mwcc sinks the add to the call, so the chain position is decided at the use); w8 = r7 + w8
 *   reassigned in block 3 or before t3 (97 B / 145 B, one slot fewer); int return types on 0201EFA4, 0201F250,
 *   02045808 and 0201C724, u8 return type on 0201D304 (324 B), void * return on 02045770: same 25 B or worse.
 * 2026-10-05 (wD9r lane12): still 25 B. Read together with ov198 0220C16C (same residue, 22 B): both images keep the
 *   reload of the u8-truncated 0201D304 result below the three outgoing stack stores, while the matched sibling
 *   ov198 0220D494 (untruncated w1) hoists it. Tried the 0201D304 result in a u32 block local w, then w8 = (u8)w: same 25.
 * 2026-10-05 (wD9 lane18): still DIFF 25 B. Tried: the whole block-3 call with f3 and y nested as
 *   arguments (94 B, 372 bytes); an s16 x3 = r7 + w8 local after the y call (25 B, chain still hoisted).
 * 2026-10-05 (wD8 lane07): still DIFF 25 B. Hypothesis: w8 is a memory variable, so its load may not move
 *   above the stack-argument stores. Test: w8 as a one-element array w8a[0] (slot moves to [sp,#0x10], the
 *   load is still hoisted first, 36 B). Not the answer. The chain stays early in every form so far; the image
 *   behaves as if the r7 + w8 value is a simple argument whose computation is emitted at the call.
 * 2026-10-05 (wave D6 lane 19): still DIFF, 13 lines in block 3. Tried: the 3rd arg through a
 *   static inline `rx(l, w)`; y nested as the call argument; an int/u32/s16 local x3 = r7 + w8
 *   before or after the y call. All keep the w8 reload first. The image behaves as if the arg
 *   chain is evaluated after the stack stores (as a simple variable would be in blocks 1 and 2).
 *
 * 2026-10-04 (wD3 lane 15): DIFF, 376 bytes (right size), 25 diff bytes, all in the third draw call (block 3). The
 * original loads p+0x10 and sets r3=0x20 first and computes r7+w8 (reload of w8 from [sp,#0x24], add, lsls/asrs) last;
 * this draft computes it first. Blocks 1 and 2 are exact, slots exact (f1,f2,x,f3,h declared at top in that order).
 * Tried: (s16)(r7+w8) inline, local x before or after the y call, w8+r7, callee param s16/u32/int.
 * Siblings with the same text-draw shape: ov198 func_0220D494, ov223 func_021BB18C.
 * 2026-10-05 (wD4 lane 08): DIFF, 376 bytes, 13 diff lines, all in the third draw call argument setup. Fixed the
 *   operand order: (s16)(r7 + w8) now gives adds r2,r7,r2 as in the original. Residue is scheduling only: the original
 *   emits the r2 computation (ldr r2,[sp,#0x24]; adds; lsls/asrs) after the stack stores and r3=0x20, the draft emits it
 *   first. Tried: plain r7 + w8 with no cast (same), reuse of the block-2 local x assigned before or after the y call
 *   (same), w8 as u8 (worse) or int (same), r7 as int with (u8) at the assignment (worse).
 * 2026-10-05 (wave D5 lane 08): DIFF, 25 bytes, unchanged. Tried: a static inline draw helper for the
 *   three blocks (worse, 203), volatile w8 (no change in the block-3 order), a new s16 local x3 = r7 + w8
 *   before or after the y call, plain r7 + w8, the 4th callee parameter as s16 (ov198 sibling
 *   prototype). The matched sibling ov198 func_0220D494 schedules its x + w1 chain early, as ours does;
 *   here the original evaluates the chain last, after the stack stores.
 *
 * 2026-10-05 (wD7 lane17): still DIFF 25 bytes. Reading: blocks 1 and 2 schedule the arg-3 value
 *   early; in block 3 the image keeps the w8 reload and add after the three stack stores, as a load
 *   the scheduler may not move above stores. Ours treats the w8 reload as a spill and hoists the chain.
 *   Tried: block-3 call through a static inline draw3(f, y, x, b, h) with x = r7 + w8 (same 25 B),
 *   (s16)(w8 + r7) (same), volatile w8 (380 B, the volatile reload still goes first). The image
 *   order (stack stores, r3, then r2 chain, then r0) looks like a simple arg-3 value in the IR.
 * symbols:
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_02045808  0x02045808  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *func_020457B0(u32 size, u32 heap);
extern void *func_02045EC0(void *bank, u32 index);
extern u32   func_02045770(u32 h);
extern void  func_02045808(void *a);
extern u32   func_0201D304(void *s, u32 a, u32 b);
extern void  func_0201C724(u32 a, u32 b, s16 c, u32 d, void *e, u32 f, u16 g);
extern u32   func_02017E1C(u32 mon, u32 id, u32 v);
extern void  func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  func_0201F250(u32 a, void *b, void *c);

void func_021F6D70(char *p, int idx)
{
    void *buf;
    void *t1;
    void *t2;
    void *t3;
    u32 w8;
    u8 r7;
    u32 f1;
    u32 f2;
    s16 x;
    u32 f3;
    u32 h;

    buf = func_020457B0(0x20, 0x8071);
    t1 = func_02045EC0(*(void **)(p + 0x14), 0xc);
    w8 = (u8)func_0201D304(t1, *(u32 *)(p + 0x10), 0);
    r7 = 0x5c - (w8 >> 1);
    {
        u32 y;
        f1 = *(u32 *)(p + 0x1c);
        y = func_02045770(*(u32 *)(p + 0x20 + idx * 8));
        func_0201C724(f1, y, (s16)r7, 0x20, t1, *(u32 *)(p + 0x10), 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t1);

    t2 = func_02045EC0(*(void **)(p + 0x14), 0xd);
    func_0201EFA4(*(u32 *)(p + 0x18), 0, func_02017E1C(*(u32 *)(p + 0xf8 + idx * 4), 0xa0, 0), 3, 0, 1);
    func_0201F250(*(u32 *)(p + 0x18), buf, t2);
    {
        u32 y;
        h = *(u32 *)(p + 0x10);
        x = r7 - func_0201D304(buf, h, 0);
        f2 = *(u32 *)(p + 0x1c);
        y = func_02045770(*(u32 *)(p + 0x20 + idx * 8));
        func_0201C724(f2, y, x, 0x20, buf, h, 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t2);

    t3 = func_02045EC0(*(void **)(p + 0x14), 0xd);
    func_0201EFA4(*(u32 *)(p + 0x18), 0, func_02017E1C(*(u32 *)(p + 0xf8 + idx * 4), 0xa1, 0), 3, 0, 1);
    func_0201F250(*(u32 *)(p + 0x18), buf, t3);
    {
        u32 y;
        f3 = *(u32 *)(p + 0x1c);
        y = func_02045770(*(u32 *)(p + 0x20 + idx * 8));
        func_0201C724(f3, y, (s16)(r7 + w8), 0x20, buf, *(u32 *)(p + 0x10), 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t3);
    func_02045808(buf);
}
