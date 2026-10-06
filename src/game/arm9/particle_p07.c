/*
 * file:     particle_p07.c
 * unit:     yes
 * function: func_02050A00, func_02050A58, func_02050A70, func_02050B14, func_02050B80, func_02050BE8
 * address:  0x02050A00
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146A84     0x02146A84  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02030734   0x02030734  arm
 *   g_02146A88      0x02146A88  data
 *   pkt_02050A70_File 0x020A7FC0  data
 */
typedef unsigned short u16;

struct Ent_02050A00 {
    u16 pad00[8];
    u16 f10;
    u16 f12;
    u16 f14;
};

struct Cmd {
    u16 f00;
    u16 f02;
};

struct Ent_02050A58 {
    u16 pad00[8];
    u16 f10;
    u16 f12;
};

typedef unsigned int u32;

typedef struct Slot_02050A70 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 active : 1;             /* bit 0 of +0x0C */
    u32 torn   : 1;             /* bit 1 of +0x0C */
    u32 kill   : 1;             /* bit 2 of +0x0C */
    u32        : 29;
} Slot_02050A70;

typedef struct Slot_02050B14 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
} Slot_02050B14;

typedef unsigned char u8;

struct Ctx {
    u32  words[16];     /* 0x00 */
    u32  f40;           /* 0x40 */
    u32  f44;           /* 0x44 */
};

extern u32  OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 s);
void func_02050A70(void);
void func_02050B14(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02051504(void);
extern int func_02051534(void);
extern int func_02051574(void);
void func_02050B80(u32 heap);
void func_02050BE8(void);
extern Slot_02050A70 *g_02146A84;
extern struct Ctx *g_02146A88;
extern const char pkt_02050A70_File[];



/*
 * The third arm of the handler table func_02050984 dispatches through (see
 * src/pending/func_02050984.c).  88 bytes, a leaf: the command halfword at
 * c->f02 packs two bytes, a repeat count in the high half and a value in the
 * low half.  While the entry's repeat counter at +0x14 is below the count,
 * store the value at +0x10 and bump the counter; once it reaches the count,
 * reset the counter and advance +0x10 by one instead.  +0x12 is zeroed on
 * both paths.  Returns 0 (the "command consumed, keep going" verdict the
 * dispatcher in func_02050944 tests).
 *
 * The comparison is SIGNED (`bge`), so both sides are promoted `int`s and the
 * counter is compared as an int, not as an unsigned halfword.
 *
 * Two shapes are load-bearing, both worth 8 bytes each:
 *
 *   - The high byte must land in a `u8` LOCAL, not be written inline in the
 *     comparison.  `if (n < ((v & 0xff00) >> 8 & 0xff))` lets mwcc fold the
 *     shift into the compare's shifter operand (`cmp r2, r1, asr #8`) and drop
 *     the redundant `and #0xff` entirely, losing the original's separate
 *     `asr r1,r1,#8` / `and r1,r1,#0xff` pair (80 bytes, 56 out).
 *   - The LOW byte must be extracted into its own local BEFORE the `if`, not
 *     spelled `v & 0xff` at its single use inside the taken arm.  The original
 *     issues `and r3, r3, #0xff` above the `bge`; written at the use it lands
 *     after it, which is the last 8 bytes (88 bytes, 8 out).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050A00.c \
 *       --func func_02050A00 --addr 0x02050A00 --cc 1.1p1 --arm
 */
int func_02050A00(struct Ent_02050A00 *e, struct Cmd *c)
{
    int v = c->f02;
    int n = e->f14;
    unsigned char hi = (unsigned char)((v & 0xff00) >> 8);
    unsigned char lo = (unsigned char)v;

    if (n < hi) {
        e->f10 = lo;
        e->f12 = 0;
        e->f14 = (u16)(n + 1);
    } else {
        int cur = e->f10;
        e->f14 = 0;
        e->f12 = 0;
        e->f10 = (u16)(cur + 1);
    }
    return 0;
}


/*
 * The fourth arm of the handler table func_02050984 dispatches through (its
 * pool word at 0x02050980-ish; see src/pending/func_02050984.c).  Twenty
 * bytes, a leaf: it loads the command's second halfword (`c->f02`), zeroes the
 * entry's +0x12 counter, stores the halfword at +0x10 and returns 0.
 *
 * The zero is materialised once and reused for both the +0x12 store and the
 * return (`mov r1,#0 ... mov r0,r1`), which is what a single `0` constant
 * shared between the store and the `return 0;` produces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050A58.c \
 *       --func func_02050A58 --addr 0x02050A58 --cc 1.1p1 --arm
 */
int func_02050A58(struct Ent_02050A58 *e, struct Cmd *c)
{
    u16 v = c->f02;

    e->f12 = 0;
    e->f10 = v;
    return 0;
}


/*
 *           02050A70..02050B14 - BOTH unresolved sites are the `bl` to it,
 *           and this function holds the only two branches to 0x02050B14 in
 *           the whole image, so `label` has nothing to point at and no cut
 *           frees it.  It closes only when 0x02050B14 itself has a shard
 *           entry, and that body is the one-register allocator residue
 *           written up in docs/notes/pkt_02050A70.c.txt (44 differing bytes,
 *           no source reaches it).  Chain row.
 *
 *           All 164 concrete bytes reproduce, including the third site
 *           (g_02146A84, literal x5).  The counter is `int`, not `u32`: the
 *           loop's back edge is `blt`.
 *
 * Sweep the four 16-byte slots of the global bank at 0x02146A84 and retire
 * the ones whose state bits say so: a slot whose bit 0 of +0x0C is set has it
 * cleared, and if it is still busy (bits 11.. of +0x08) its teardown routine
 * runs and the "torn down" bit (bit 1) is set; a slot whose bit 2 is set has
 * it cleared and the teardown routine runs.  The bank pointer is re-read
 * after every store (`ldr r0, [r5]`), which is what the repeated reads say:
 * the store can alias the global itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02050A70.c \
 *       --func func_02050A70 --addr 0x02050A70 --cc 1.1p1 --arm
 */
void func_02050A70(void)
{
    int i;

    if (g_02146A84 == 0)
        return;

    for (i = 0; i < 4; i++) {
        if (g_02146A84[i].active) {
            g_02146A84[i].active = 0;
            if (g_02146A84[i].unk08 >> 11) {
                func_02050B14(i);
                g_02146A84[i].torn = 1;
            }
        }
        if (g_02146A84[i].kill) {
            g_02146A84[i].kill = 0;
            func_02050B14(i);
        }
    }
}


/*
 * CLOSES the two-wave wall written up at the top of docs/notes/pkt_02050A70.c.txt
 * (44 differing bytes, diagnosed there as a one-register allocator shift with
 * "no source shape that reaches it").  The diagnosis was wrong: the residue was
 * a WRONG RECORD STRIDE, not an allocation tie.  The note's reconstruction read
 * the field as `g_02146A84[idx].unk_08` over 16-byte records but spelled the
 * index arithmetic so that the compiler emitted a multiply; the image emits
 * `add r1, r3, r4, lsl #4` -- a shift, because 16 is a power of two -- and
 * `mul r2, r4, r1` ONLY for the SECOND, independent 12-byte stride of the I/O
 * register address (0x040000B8 + idx * 12).  Declaring the record struct as
 * four plain u32 words (16 bytes) and subscripting it normally gives the shift,
 * and every register then falls out identical: the whole 44-byte residue was
 * downstream of that one address computation.
 *
 * Read the 3D engine's per-engine configuration word out of the slot bank and
 * repack it into the display register at 0x040000B8 + idx*12: dest bit 30 from
 * source bit 1, dest bit 26 from source bit 5, dest 23:24 from source 7:8,
 * dest 21:22 from source 9:10 and dest 0:20 from source 11:31, under an
 * interrupt-disabled critical section.
 *
 * The OR-chain ORDER is load-bearing and is the note's one surviving finding:
 * the bit-30 term is written FIRST and the bit-26 term SECOND, because the
 * compiler fully materialises the second operand of a commutative chain
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md)
 * and the image materialises the bit-26 term (`lsl #0x1a; lsr #0x1f; lsl #0x1a`)
 * while folding the other three placements into the ORs' shifter operands.
 * Written in descending destination order the four extracts come out mirrored.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050B14.c \
 *       --func func_02050B14 --addr 0x02050B14 --cc 1.1p1 --arm
 *   EXACT, 108 bytes, 3 relocation sites, all resolved.
 */
void func_02050B14(u32 idx)
{
    u32 s = OS_DisableInterrupts();
    u32 v = g_02146A84[idx].unk08;

    *(volatile u32 *)(0x040000B8 + idx * 12) =
        ((v << 30) >> 31) << 30 |
        ((v << 26) >> 31) << 26 |
        ((v << 23) >> 30) << 23 |
        ((v << 21) >> 30) << 21 |
        (v >> 11);

    OS_RestoreInterrupts(s);
}



/*
 * Allocate the 0x48-byte singleton on the caller's heap and publish it at
 * 0x02146A88, zero its first sixteen words, then clear the two trailing word
 * fields at +0x40 and +0x44.
 *
 * The heap id is the incoming r0, untouched: the allocator's first argument is
 * the parameter, and its third (the clear flag, 0) is CSE'd off the loop
 * counter's own zero, which is why no `mov r0` appears and r4 is zeroed before
 * the call.
 *
 * The global is a pointer VARIABLE, and both the zero loop and the two field
 * stores re-dereference it: a store through the pointer could overwrite the
 * pointer itself, so only `g[i] = 0` inside the loop and `g->f40`/`g->f44`
 * afterwards reproduce the four separate loads of the global.
 */
void func_02050B80(u32 heap)
{
    int i = 0;

    g_02146A88 = func_02030734(heap, 0x48, i, pkt_02050A70_File, 190);

    for (i = 0; i < 16; i++) {
        ((u32 *)g_02146A88)[i] = 0;
    }

    g_02146A88->f40 = 0;
    g_02146A88->f44 = 0;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050BE8.c \
 *       --func func_02050BE8 --addr 0x02050BE8 --cc 1.1p1 --arm
 */
void func_02050BE8(void)
{
    if (func_02051504() == 0)
        return;
    func_02051534();
    func_02051574();
}
