/*
 * function: func_021B0D18
 * address: 0x021B0D18
 * packet: pkt_ov013_021B0D18
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * volatile: SQRTCNT polls at 021B0D90; SQRT result/parameter are hardware registers at 040002B4/040002B8.
 * residual: none; EXACT 544/544 in --lang c99 and --lang c, all twelve relocations resolved.
 * evidence: fresh xor-zero dependency, comma reset expression and byte reset bitfield each tied 10. Signed reset flag and own MATH_CountPopulation u8 return correction also tied 10.
 * checks: 1 own matched 3278/3604/04A8/1688 and MATH_CountPopulation bodies read; 3084 original reads x/sq/byte-output pointer, arity 3; 2 no exact reset twin; 3 signed f8 and exact u8 SDK return compiled without change; 4 inline, commutative-operand and named-field idioms read; 5 full directory and fresh ov013 neighbours reread, no addressed stack aggregate; next hypothesis a reset helper using an independently evidenced enclosing record.
 * permuter: earlier budget-300 search consumed; not repeated. Prior inline reset, enum flag and signed x did not improve.
 * note 2026-10-05 (lane S2, wave P4): only the f8 reset block at +012C..+0134 differs. The original keeps
 *   ldrb; orr; strb; str r5 in source order, we put the zero store between ldrb and orr (the same shape
 *   for the f14 block at +0140 matches). Tried: inline helper replaced by plain statements, f8 as u32 and as
 *   void pointer, nested if instead of &&, reset stores in either source order (scheduler output unchanged),
 *   each of opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole off
 *   (all 10 bytes). No twin found. Header: status DIFF, 10 bytes.
 * recoup 2026-10-05 (lane R13): no loop counter here, so the ov013 021B0614 opt_lifetimes shape does not apply. Levers 1-2 no change
 *   (callee arities and widths already match matched callers). Lever 3/4/5: f8 block as nested if, store first, f5 = f5 | 0x80,
 *   byte temp, else-if with empty then, negated condition, f5 through a u8 pointer local: all 10 B. Pointer local for d_021B3C84
 *   (whole function 53 B, f8/f14 blocks only 362 B). Pragmas not repeated (header lists them). Residue unchanged: zero store
 *   scheduled before orr in the f8 block only.
 * final push 2026-10-05 G3L8 (32 compiles, 3 rounds): still DIFF 10 B. New facts: (1) scheduling off and peephole off do not change the
 *   order, so the f8 block is ordered before the scheduler (ldrb; str; orr; strb). (2) The order depends on the field offset of the reset
 *   store: fields at +0,+4,+8,+0xC of d_021B3C84 get the zero store between ldrb and orr; fields at +0x14,+0x18,+0x20,+0x24 keep source
 *   order; the f14 block is never wrong, also when written first. Removing the later f4/f10/f12 accesses does not change it. Tried without
 *   effect: else-if instead of &&, no && at all, raw-offset access, int f8, u32 w[4] array view, cast pointer view, early pointer local,
 *   f5 as ((u8 *)f)[5], Frame data[] start moved to +6, f as u32 arithmetic, Frame fr[2] view (changes the whole function), reversed
 *   && operand order, opt_dead_code / opt_strength_reduction / opt_loop_invariants off. No twin in the listings (orrne #0x80 hits in
 *   ov114, arm9 are stack or different shapes). Open idea: the original f8 store is not provably independent of the strb at f+5.
 * pass 2 2026-10-06 P2L22 (40 compiles, 3 rounds): still DIFF 10 B. New facts: the f8 store follows strb f5 only when mwcc
 *   cannot prove f and d_021B3C84+8 apart. f from an extern pointer or a pointer select (cond ? &d : &d + 0x460) gives the
 *   right order but a second base and addeq (479 B). Integer forms (u32 cast, off local, if/else, inline helper, u8 *buf with
 *   opt_propagation off) keep the points-to. In a sized struct, accesses at +0x10 and up are treated as may-alias, below
 *   0x10 as independent (also for a separate global); int[]/struct[] views make f14 independent too (20 B).
 *   AdpcmState member at +0x10 with &d_021B3C84.st as the call argument also gives 10 B (pool word folds to 021B3C94).
 *   Notes: scratchpad wD9r/p2_P2L22/research.md.
 * pass 3 2026-10-06 P3L11 (38 compiles, 3 rounds): still DIFF 10 B. New facts: (1) one TU struct at 3C84 holding
 *   the ctx and the 42C0 frames/counters, with `Ctx42C0 *w = &big.w` for the 42C0 side, puts both reset blocks in
 *   original order (frame and ctx in one object: unknown frame offset vs ctx+8 is a same-object alias), but the
 *   backend then drops the first `f8CC = f4` store and swaps str f8D4/cmp (72 B). Keeping that store needs the id
 *   load to alias (id inside the struct: 12 B, but d_021B60D8 is used by many other TUs and TU B's bss ends at
 *   4B98, so not plausible). (2) volatile flags, opt_pointer_analysis off (on segfaults the compiler),
 *   c99_alias_by_type, opt_scalarize/decomposeaggregates, scheduling off, static/defined globals, `f = 0` init,
 *   inline helpers under opt_propagation off, named `u32 *req`, 0F38 Frame layout: all 10 B or worse.
 *   Open lead: a frame pointer the ARM backend cannot trace, still emitted as add r8, r6, r0 from the shared pool.
 *   Notes: scratchpad wD9r/p3_P3L11/research.md.
 * pass 4 2026-10-06 P4L05: closed. The frame flag byte f5 and the two reset-request flags f8 and f14 of
 *   d_021B3C84 are volatile members. The request flags are set from other paths (021B0CD8 sets f8,
 *   021B0614 and 021B074C set f14) and f5 is the flag byte of the frame buffer that the wireless layer
 *   reads. Two volatile accesses keep their source order, so the f8 reset store stays after strb f5.
 *   Volatile on f8/f14 alone (P3L11 a1) or on f5 alone stays 10 B; both sides are needed.
 * symbols:
 *   d_021B42C0  0x021B42C0  data  ov013  a4
 *   d_021B3C84  0x021B3C84  data  ov013  a4
 *   d_021B3C24  0x021B3C24  data  ov013  a4
 *   d_021B3C94  0x021B3C94  data  ov013  a4
 *   d_021B60D8  0x021B60D8  data  ov013  a1
 *   func_021B3278  0x021B3278  arm  ov013
 *   func_021B3604  0x021B3604  arm  ov013
 *   func_021B3084  0x021B3084  arm  ov013
 *   func_021B04A8  0x021B04A8  arm  ov013
 *   func_021B1588  0x021B1588  arm  ov013
 *   func_021B1688  0x021B1688  arm  ov013
 *   func_02080D24  0x02080D24  arm

 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define reg_SQRTCNT     (*(volatile u16 *)0x040002B0)
#define reg_SQRT_RESULT (*(volatile u32 *)0x040002B4)
#define reg_SQRT_PARAM  (*(volatile u32 *)0x040002B8)

typedef struct {
    u8 pad0[4];
    u8 f4;
    volatile u8 f5;
    u8 pad6[6];
    u8 data[0x460 - 0xc];
} Frame;

typedef struct {
    u8 pad0[0x8c0];
    u32 f8C0;
    u32 f8C4;
    u32 f8C8;
    u32 f8CC;
    int f8D0;
    int f8D4;
} Ctx42C0;

typedef enum { FlagClear=0, FlagSet=1 } Flag;
typedef struct {
    u32 f0;
    u32 f4;
    volatile u32 f8;
    u32 fC;
    u16 f10;
    u8 f12;
    u8 pad13;
    volatile u32 f14;
    u32 f18;
    int f1C;
    u32 f20;
    u32 f24;
    int f28;
} Ctx3C84;

extern Ctx42C0 d_021B42C0;
extern Ctx3C84 d_021B3C84;
extern u32 d_021B3C24;
extern u8 d_021B3C94[];
extern u8 d_021B60D8;

typedef struct AdpcmHdr { short pred; u8 index; u8 zero; } AdpcmHdr;
typedef struct AdpcmState { short pred; u8 index; } AdpcmState;
extern int func_021B3278(short *p, u32 n);
extern void func_021B3604(short *p, u32 n, u32 sq);
extern int func_021B3084(u32 x, u32 sq, u8 *z);
extern void func_021B04A8(AdpcmHdr *a, void *b, int n, AdpcmState *c, int mode);
extern void func_021B1588(unsigned char *dst, const short *src, unsigned int n);
extern void func_021B1688(u8 *dst, short *src, u32 n);
extern u8 func_02080D24(u32 x);

Frame *func_021B0D18(void)
{
    u8 *p;
    Frame *f;
    int x;
    u32 sq;
    int mode;
    u32 diff;

    mode = d_021B3C84.f1C;
    diff = d_021B42C0.f8C4 - d_021B42C0.f8C0;
    if (diff > 1) {
        d_021B42C0.f8C0 = d_021B42C0.f8C4 - 1;
        diff = 1;
    }
    if (diff == 0)
        return 0;

    f = (Frame *)((u8 *)&d_021B42C0 + ((d_021B42C0.f8C0 & 1) ? 0 : 0x460));
    p = f->data;
    if (mode >= 2)
        p += 4;

    x = func_021B3278((short *)p, d_021B3C84.f24);
    reg_SQRTCNT = 0;
    reg_SQRT_PARAM = x;
    while (reg_SQRTCNT & 0x8000)
        ;
    sq = reg_SQRT_RESULT;

    if (d_021B3C84.f18 != 0)
        func_021B3604((short *)p, d_021B3C84.f24, sq);

    f->f5 = mode;
    if (d_021B3C24 != 0) {
        switch (d_021B3C84.f28 = func_021B3084(x, sq, 0)) {
        case 0:
            d_021B42C0.f8C0++;
            return 0;
        case 1:
            f->f5 |= 0x80;
            break;
        case 3:
            f->f4 = 0x41;
            break;
        }
    }
    if (d_021B3C24 == 0 && d_021B3C84.f8 != 0) {
        f->f5 |= 0x80;
        d_021B3C84.f8 = 0;
    }
    if (d_021B3C84.f14 != 0) {
        f->f5 |= 0x80;
        d_021B3C84.f14 = 0;
    }

    if (mode >= 2) {
        if (f->f5 & 0x80) {
            d_021B3C84.f10 = 0;
            d_021B3C84.f12 = 0;
        }
        func_021B04A8((AdpcmHdr *)(p - 4), p, d_021B3C84.f24 >> 1, (AdpcmState *)d_021B3C94, mode);
    } else if (mode == 1) {
        func_021B1588(p, (short *)p, d_021B3C84.f24 >> 1);
    } else if (mode == 0) {
        func_021B1688(p, (short *)p, d_021B3C84.f24 >> 1);
    }

    d_021B42C0.f8CC = d_021B3C84.f4;
    d_021B42C0.f8CC = d_021B3C84.f4 & ~(1 << d_021B60D8);
    d_021B42C0.f8D4 = func_02080D24(d_021B42C0.f8CC) - 1;
    if (d_021B42C0.f8D4 > 7)
        return 0;
    d_021B42C0.f8D0 = 0;
    return f;
}
