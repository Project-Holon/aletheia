/*
 * file:     nns_snd_waveout_6.c
 * unit:     yes
 * function: func_02072AA0, func_02072BDC
 * address:  0x02072AA0
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02089660  0x02089660  arm
 *   func_020894B4  0x020894B4  arm
 *   func_02089D40  0x02089D40  arm
 *   _ll_udiv       0x0209C00C  arm
 *   func_020894DC  0x020894DC  arm
 */
typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct {
    u32 f0;
    int f4;
    u32 f8;
    u32 fC;
    u32 f10;
} Obj;

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 unk08;
} Slot02072BDC;

extern void func_02089660(int chNo, int format, const void *dataaddr, int loop, int loopStart, int loopLen, int volume, int shift, int timer, int pan);
extern void func_020894B4(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
extern u32  func_02089D40(void);
extern void func_020894DC(u32 chan, u32 a, u32 b, u32 c);
int func_02072AA0(Obj *s, int fmt, void *data, int loop, int start, int end, int rate, int vol, int freq, int e);
void func_02072BDC(Slot02072BDC *s);


/*
 * Starts one channel.  The ten-argument signature is not guessed: the single
 * caller src/matched/unit_020067E0.c (PM_VOICE_StartChannels) already spells the call
 *
 *   func_02072AA0(e->unk14, 0, e->unk10, 0, 0, e->unk08, e->unk0C,
 *                 PM_VOICE_ScaleVolume(e->unk1C), e->unk20, e->unk28)
 *
 * which fixes the four register arguments and the six stack words at
 * [sp+0x38] .. [sp+0x4c] (0x20 of push plus the 0x18 frame).  `rate` (arg7)
 * is read twice -- once as the first divisor and once at the end as the value
 * latched into s->f4, which is exactly what NNS_SndWaveOutSetSpeed later divides by.
 *
 * The period is the chained 64-bit division of src/matched/unit_020067E0.c and
 * src/matched/NNS_SndWaveOutSetSpeed.c: dividend 0x7FD87F8000 (low word 0xD87F8000 in
 * the pool at 0x02072BD4, high word 0x7F as `mov r1, #0x7f`), two `int`
 * divisors each widened by the `asr r3, r2, #0x1f` in front of its call, and
 * the same `if (t < 0x10) ... else if (t > 0xFFFF) ...` exclusive clamp
 * against the 0xFFFF pool word at 0x02072BD8.
 *
 * TWO STRUCTURAL TELLS, both measured:
 *
 *   1. The three format arms are a `switch` WITH AN EXPLICIT EMPTY `default`,
 *      not an if/else chain.  An if/else chain (and a switch with no default)
 *      lets the front end if-convert the last arm into the compare chain --
 *      `cmp r8, #2 / ldreq r1, [sp,#0x38] / ...` where the image has
 *      `beq #0x2072af8 / b #0x2072b08`.  The default arm is what forces the
 *      merge-point branch to exist, and it is 231 concrete bytes of residue.
 *      See docs/idioms/empty-switch-arms-are-what-make-the-table.md for the
 *      neighbouring case; here it is the default rather than a low case that
 *      is load-bearing, and the dispatch stays a compare chain because the
 *      arms are not dense enough for a table.
 *      Each arm is a shift, not a division: `asr r4, r1, #2` with no rounding
 *      correction rules out `start / 4` on a signed int.
 *
 *   2. THE `../2.0/sp2` PIN.  With the switch shape settled, dsi/1.1p1 is
 *      still 300 bytes against the image's 316 and holds both the literal 0
 *      and the literal 1 in callee-saved registers across the two calls
 *      (`mov r5, #0` then `str r5, [sp,#0xc]` / `str r5, [sb,#0xc]`, and
 *      `mov r4, #1` then `str r4, [sb,#8]` / `mov r0, r4`), where the image
 *      rematerialises each one at its use (`mov r1, #0` / `mov r2, r1` /
 *      `mov r3, r1`, and three separate `mov r0, #1`).  ../1.2/sp2 is 328
 *      bytes.  This is the "kept constants" tell of docs/FRONTEND-PINS.md,
 *      the same pin and the same family as the cluster neighbours
 *      src/matched/func_02072BDC.c and src/matched/func_02072D20.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072AA0.c \
 *       --func func_02072AA0 --addr 0x02072AA0 --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 316 = original 316, 5 of 5 sites resolved
 */
int func_02072AA0(Obj *s, int fmt, void *data, int loop,
                  int start, int end, int rate, int vol, int freq, int e)
{
    int a;
    int b;
    u64 t;

    switch (fmt) {
    case 0:
        a = start >> 2;
        b = (end >> 2) - a;
        break;
    case 1:
        a = start >> 1;
        b = (end >> 1) - a;
        break;
    case 2:
        a = start >> 3;
        b = (end >> 3) - a;
        break;
    default:
        break;
    }
    t = 0x7FD87F8000ULL / rate / freq;
    if (t < 0x10) {
        t = 0x10;
    } else if (t > 0xFFFF) {
        t = 0xFFFF;
    }
    func_02089660(s->f0, fmt, data, loop != 0 ? 1 : 2,
                  a, b, vol, 0, (u32)t, e);
    func_020894B4(1 << s->f0, 0, 0, 0);
    s->f8 = 1;
    s->fC = 0;
    s->f10 = func_02089D40();
    s->f4 = rate;
    return 1;
}


/*
 * Guards on the slot's +8 word, then calls func_020894DC(1 << s->unk00, 0, 0, 0)
 * and clears the guard.
 *
 * Built by the 2.0 front end, on the "kept constants" tell: the image
 * materialises both the shift operand and the three zero arguments as
 * immediates (`mov r2, #1` / `mov r1, #0` / `lsl r0, r2, r0` / `mov r2, r1` /
 * `mov r3, r1`) and keeps the object in r4 with a two-register push.  dsi/1.1p1
 * rematerialises the zero from the pool into a callee-saved register, moves the
 * object to r5 and grows the push to {r3, r4, r5, lr} -- 23 concrete bytes of
 * diff, and the same residue ../1.2/sp2 gives 39 bytes of.  ../2.0/sp2
 * reproduces the image byte for byte.  Same tell and family as
 * src/matched/func_02074A6C.c and src/pending/func_0206B6A4.c.
 *
 * Evidence recorded in docs/notes/pkt_02072A44.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072BDC.c \
 *       --func func_02072BDC --addr 0x02072BDC --arm --cc ../2.0/sp2
 */
void func_02072BDC(Slot02072BDC *s)
{
    if (s->unk08 == 0) {
        return;
    }
    func_020894DC(1 << s->unk00, 0, 0, 0);
    s->unk08 = 0;
}
