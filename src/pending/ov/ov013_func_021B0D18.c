/*
 * function: func_021B0D18
 * address: 0x021B0D18
 * packet: pkt_ov013_021B0D18
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * volatile: SQRTCNT polls at 021B0D90; SQRT result/parameter are hardware registers at 040002B4/040002B8.
 * residual: DIFF 544/544 bytes, 10 concrete bytes differ; all twelve relocations resolved. Only +012C/+0130/+0134 reset store/RMW scheduling differs.
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
    u8 f5;
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
    u32 f8;
    u32 fC;
    u16 f10;
    u8 f12;
    u8 pad13;
    u32 f14;
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
extern void func_021B1588(u8 *dst, short *src, u32 n);
extern void func_021B1688(u8 *dst, short *src, u32 n);
extern u8 func_02080D24(u32 x);

static inline void signal_reset(Frame *f,int *flag) { f->f5 |= 0x80; *flag=0; }

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
