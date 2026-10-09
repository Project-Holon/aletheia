/*
 * file:     unit_021B0D18.c
 * unit:     yes
 * function: func_021B0D18, func_021B0F38, func_021B111C, func_021B11E8, func_021B12FC, func_021B133C, func_021B1398, func_021B1404
 * address:  0x021B0D18
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
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
 *   d_021B3CBC  0x021B3CBC  data  ov013  a4
 *   d_021B3AD0  0x021B3AD0  data  ov013  a1
 *   func_021B2FB0  0x021B2FB0  arm  ov013
 *   func_021B1720  0x021B1720  arm  ov013
 *   func_021B1790  0x021B1790  arm  ov013
 *   func_021B1B94  0x021B1B94  arm  ov013
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   func_02082D44  0x02082D44  arm
 *   func_021B1488  0x021B1488  arm  ov013
 *   func_021B1498  0x021B1498  arm  ov013
 *   func_021B14A8  0x021B14A8  arm  ov013
 *   func_021B043C  0x021B043C  arm  ov013
 *   func_021B1634  0x021B1634  arm  ov013
 *   func_021B16B4  0x021B16B4  arm  ov013
 *   func_021B14F8  0x021B14F8  arm  ov013
 *   func_021B1810  0x021B1810  arm  ov013
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   d_021B3ADA  0x021B3ADA  data  ov013  a1
 *   func_02177044  0x02177044  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021B4B98     0x021B4B98  data  a4
 *   g_021B4BA0     0x021B4BA0  data  a4
 */
#define reg_SQRTCNT     (*(volatile u16 *)0x040002B0)
#define reg_SQRT_RESULT (*(volatile u32 *)0x040002B4)
#define reg_SQRT_PARAM  (*(volatile u32 *)0x040002B8)
struct Pkt;
struct Src;
struct AdpcmState;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Frame_021B0D18 {
    u8 pad0[4];
    u8 f4;
    volatile u8 f5;
    u8 pad6[6];
    u8 data[0x460 - 0xc];
} Frame_021B0D18;

typedef struct Ctx42C0 {
    u8 pad0[0x8c0];
    int f8C0;
    u32 f8C4;
    struct Frame_021B0D18 *f8C8;
    u32 f8CC;
    int f8D0;
    int f8D4;
} Ctx42C0;

typedef enum { FlagClear=0, FlagSet=1 } Flag;

typedef struct Ctx3C84 {
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

typedef struct AdpcmHdr { short pred; u8 index; u8 zero; } AdpcmHdr;

typedef struct AdpcmState { short pred; u8 index; } AdpcmState;

typedef unsigned long long u64;

typedef struct {
    u32 f0;
    u8 f4;
    u8 f5;
    u16 f6;
    u32 f8;
    u8 data[1];
} Frame_021B0F38;

typedef struct {
    u8 pad0[0x24];
    int f24;
    u8 pad28[0x8];
    u32 f30;
    u32 f34;
    u32 f38;
    u8 pad3C[0x10];
    u32 f4C;
    u8 pad50[0x1c];
    u32 f6C;
    u8 pad70[0x94 - 0x70];
} Chan;

typedef struct {
    u8 a;
    u8 b;
} SizeEnt;

typedef struct Voice {
    u32 f0;
    struct Voice *prev;
    struct Voice *next;
    int fC;
    u8 f10;
    u8 f11;
    u8 pad12[2];
    u32 f14;
    u32 f18;
    u8 buf[0x45c - 0x1c];
    u32 f45C;
    u32 f460;
    u64 tick;
    u32 f46C;
    u32 f470;
    void *f474;
} Voice;

typedef struct Ctx60D8 {
    u8 f0;
    u8 pad1[0xf];
    int f10;
} Ctx60D8;

extern int func_021B3278(short *p, u32 n);
extern void func_021B3604(short *p, u32 n, u32 sq);
extern int func_021B3084(u32 x, u32 sq, u8 *z);
extern void func_021B04A8(AdpcmHdr *a, void *b, int n, AdpcmState *c, int mode);
extern void func_021B1588(unsigned char *dst, const short *src, unsigned int n);
extern void func_021B1688(u8 *dst, short *src, u32 n);
extern u8 func_02080D24(u32 x);
extern Voice *func_021B2FB0(void);
extern void func_021B1720(u32 x);
extern void func_021B1790(void);
extern int func_021B1B94(struct Src *s, struct Pkt *pkt);
extern void func_021B2FE4(Voice *v);
extern void func_02082D44(void *src, void *dst, u32 n);
extern Voice *func_021B1488(void);
extern int func_021B1498(unsigned int i);
extern Voice *func_021B14A8();
extern void func_021B043C(struct AdpcmState *hdr, void *dst, int n, int mode);
extern void func_021B1634(unsigned char *src, short *dst, unsigned int n);
extern void func_021B16B4(signed char *src, short *dst, unsigned int n, int fmt);
extern u32 func_021B14F8(Voice *n);
extern int func_021B1810(Voice *n, u32 idx);
extern int func_02087988(void);
extern void func_0208799C(int);
extern int func_02177044(unsigned char aid, void *buffer, int size);
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);
Frame_021B0D18 *func_021B0D18(void);
int func_021B0F38(u32 id, Frame_021B0F38 *hdr, u32 size, u64 tick);
int func_021B111C(void);
int func_021B11E8(void);
void func_021B12FC(void);
void func_021B133C(unsigned int n);
void func_021B1398(void);
int func_021B1404(Voice *n);
extern Ctx42C0 d_021B42C0;
extern Ctx3C84 d_021B3C84;
extern u32 d_021B3C24;
extern u8 d_021B3C94[];
extern Ctx60D8 d_021B60D8;
extern Chan d_021B3CBC[3];
extern SizeEnt d_021B3AD0[];
extern u8 d_021B3ADA[][3];
extern struct {
    Voice *head;
    Voice *tail;
} g_021B4B98;
extern int g_021B4BA0[3];




/*
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
 */
Frame_021B0D18 *func_021B0D18(void)
{
    u8 *p;
    Frame_021B0D18 *f;
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

    f = (Frame_021B0D18 *)((u8 *)&d_021B42C0 + ((d_021B42C0.f8C0 & 1) ? 0 : 0x460));
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
    d_021B42C0.f8CC = d_021B3C84.f4 & ~(1 << d_021B60D8.f0);
    d_021B42C0.f8D4 = func_02080D24(d_021B42C0.f8CC) - 1;
    if (d_021B42C0.f8D4 > 7)
        return 0;
    d_021B42C0.f8D0 = 0;
    return f;
}




/*
 * The last two arguments are one u64 (an OS tick, stored to v+0x464):
 * split across r3 and the stack, which is what pulls the high word into a
 * register at entry.
 */
int func_021B0F38(u32 id, Frame_021B0F38 *hdr, u32 size, u64 tick)
{
    Voice *v;
    Chan *ch;
    int mode;
    u32 i;
    u8 *dst;

    ch = 0;
    if (d_021B3C84.f20 == 0)
        return 0;

    for (i = 0; i < 3; i++) {
        if (id == d_021B3CBC[i].f38) {
            ch = &d_021B3CBC[i];
            break;
        }
    }
    if (ch == 0)
        return 0;

    if (hdr->f4 == 0x41) {
        ch->f30 = hdr->f6;
        ch->f4C = 0;
        ch->f6C = 1;
        return 0;
    }
    if (hdr->f4 != 0x40)
        return 0;

    mode = hdr->f5 & 0x7f;
    ch->f24 = mode;
    if (mode >= 5)
        return 0;
    if (size != d_021B3AD0[mode].a * 0x44 + d_021B3AD0[mode].b + 0xc)
        return 0;
    if ((d_021B3C84.f4 & (id != 0 ? 1 << id : 1)) == 0)
        return 0;

    if ((v = func_021B2FB0()) == 0) {
        func_021B1720(ch->f34);
        func_021B133C(ch->f34);
        if ((v = func_021B2FB0()) == 0) {
            func_021B1790();
            func_021B1398();
            v = func_021B2FB0();
        }
        if (v == 0)
            return 0;
    }

    dst = &v->buf[sizeof(v->buf)] - (size - 0xc);
    func_02082D44(hdr->data, dst, size - 0xc);
    v->f11 = ch->f34;
    v->fC = mode;
    v->f474 = dst;
    v->f14 = size - 0xc;
    v->tick = tick;
    v->f10 = id;
    v->f45C = hdr->f5 & 0x80;
    v->f460 = hdr->f8;
    v->f18 = hdr->f6;
    if (func_021B1B94((struct Src *)ch, (struct Pkt *)v) == 0) {
        func_021B2FE4(v);
        return 0;
    }
    func_021B1404(v);
    return 1;
}




/*
 * The three sample converters are passed q->fC as a fourth argument: the
 * original keeps the format in r3 across the argument set-up of all three
 * calls, which only a live fourth argument reproduces (a plain local or
 * the bare field lands in r0).
 */
int func_021B111C(void)
{
    Voice *v;
    int i;
    int n;
    u32 id;
    int irq;
    Voice *q;
    int fmt;

    v = func_021B1488();
    if (v == 0)
        return 0;

    irq = func_02087988();
    id = v->f11;
    n = func_021B1498(id);
    for (i = 0; i < n; i++) {
        q = func_021B14A8(id);
        fmt = q->fC;
        if (fmt >= 2)
            func_021B043C(q->f474, q->buf, q->f14, fmt);
        else if (fmt == 1)
            func_021B1634(q->f474, (short int *)q->buf, q->f14);
        else
            func_021B16B4(q->f474, (short int *)q->buf, q->f14, fmt);
        q->f474 = q->buf;
        func_021B14F8(q);
        if (func_021B1810(q, q->f11) < 0)
            func_021B2FE4(q);
    }
    func_0208799C(irq);
    return n;
}




static inline u32 clz32(u32 x)
{
    asm { clz x, x }
    return x;
}




int func_021B11E8(void)
{
    int i;
    int count;
    u32 mask;
    u32 z;

    if (d_021B3C84.f20 == 0)
        return 1;

    if (d_021B42C0.f8C8 == 0) {
        d_021B42C0.f8C8 = func_021B0D18();
        if (d_021B42C0.f8C8 != 0 && d_021B3C84.f18 != 0)
            return 0;
        return 1;
    }

    count = 1;
    if (d_021B60D8.f10 == 2)
        count = d_021B3ADA[d_021B42C0.f8D4][d_021B42C0.f8D0++];

    for (i = 0; i < count; i++) {
        mask = d_021B42C0.f8CC;
        z = clz32(mask);
        if (z == 32)
            break;
        d_021B42C0.f8CC = mask & ~(0x80000000 >> z);
        func_02177044((u8)(31 - z), d_021B42C0.f8C8, d_021B3C84.fC);
        if (d_021B42C0.f8CC == 0) {
            d_021B42C0.f8C0++;
            d_021B42C0.f8C8 = 0;
            d_021B42C0.f8CC = 0;
            break;
        }
    }
    return 1;
}





void func_021B12FC(void)
{
    int s;
    int i;

    s = OS_DisableInterrupts();
    g_021B4B98.tail = 0;
    g_021B4B98.head = 0;
    for (i = 0; i < 3; i++) {
        g_021B4BA0[i] = 0;
    }
    OS_RestoreInterrupts(s);
}





void func_021B133C(unsigned int n)
{
    int s;
    Voice *p;

    s = OS_DisableInterrupts();
    while ((p = func_021B14A8(n)) != 0) {
        func_021B14F8(p);
        func_021B2FE4(p);
    }
    g_021B4BA0[n] = 0;
    OS_RestoreInterrupts(s);
}




void func_021B1398(void)
{
    int s;
    int i;
    Voice *p;
    Voice *q;

    s = OS_DisableInterrupts();
    p = g_021B4B98.head;
    while (p != 0) {
        q = p;
        p = p->next;
        func_021B2FE4(q);
    }
    g_021B4B98.head = 0;
    g_021B4B98.tail = 0;
    for (i = 0; i < 3; i++) {
        g_021B4BA0[i] = 0;
    }
    OS_RestoreInterrupts(s);
}



int func_021B1404(Voice *n)
{
    int s;

    s = OS_DisableInterrupts();
    if (g_021B4B98.head == 0) {
        g_021B4B98.head = n;
        n->prev = 0;
        g_021B4B98.head->next = 0;
        g_021B4B98.tail = g_021B4B98.head;
    } else {
        n->prev = g_021B4B98.tail;
        n->next = 0;
        g_021B4B98.tail->next = n;
        g_021B4B98.tail = n;
    }
    g_021B4BA0[n->f11]++;
    OS_RestoreInterrupts(s);
    return g_021B4BA0[n->f11];
}
