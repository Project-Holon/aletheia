/*
 * function: func_02180820
 * address:  0x02180820
 * packet:   pkt_ov231_02180820
 * region:   ov231
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04): DIFF. Logic and all calls/relocations resolve; residue is the two ms-wait loops. Original hoists 0x40 (r7) and zero (r4) out of the loop and builds 1000 (movs 0xfa; lsls #2) after the first _ull_mul; ours hoists the 1000 constant instead (movs r7,#0xfa). Tried a single *64000-style expression (folds to one mul) and a static inline ms() with m=t*64; m*=1000. Data externs d_02180A20 (struct {int; u8 *f4; u8 *f8}), d_02180A30 (u8), d_02180A00 (u16) assumed from pool words.
 *
 * 2026-10-05 (wD5 lane20): tried u64 k = 64 as a function local and as a file-level static const u64 k, with m = diff * k; m = m * 1000 as separate statements inside a do/while: still strength-reduced to lsls/lsrs #6 shifts. The 64 is not kept as a run-time _ull_mul operand by any local or static form tried.
 * symbols:
 *   _ull_mul  0x0209C054  arm
 *   _ll_udiv  0x0209C00C  arm
 *   func_020870D0  0x020870D0  arm
 *   func_02075E9C  0x02075E9C  arm
 *   func_02084DF4  0x02084DF4  arm
 *   func_02084E2C  0x02084E2C  arm
 *   func_02075EAC  0x02075EAC  arm
 *   func_02180904  0x02180904  thumb  ov231
 *   func_02180914  0x02180914  thumb  ov231
 *   func_02180924  0x02180924  thumb  ov231
 *   func_02180984  0x02180984  thumb  ov231
 *   d_02180A20  0x02180A20  data  a4
 *   d_02180A30  0x02180A30  data  a1
 *   d_02180A00  0x02180A00  data  a2
 *
 * note 2026-10-05 (wD4 lane13): tried a u64 k = 64 local (in the inline helper, as a u32 and as an int, and in the function body with t * k * 1000 / 33514): all fold the 64 into 64000 or into shifts (208-224 bytes, 62-167 bytes differ). The constant-in-a-local lever does not keep the 64 as a run-time _ull_mul operand for u64 arithmetic.
 */

/*
 * 2026-10-04 (wave D2 lane05): DIFF, no change in verdict. New finding: the original calls _ull_mul for the *64 step (r2=0x40 held in r7, high word r4=0 hoisted), so 64 is not a visible power-of-two literal when the multiply is emitted; ours turns *64 into lsls/lsrs #6 shifts (224 vs 228 bytes). Every literal form folds: t*64*1000, (64*t)*1000, t*k*1000 with k a u64 local all become one *64000 mul or shifts (siblings ov231_func_02180924/02180984 use *64000). Needs a non-foldable 64 (an inline helper with a real u64 parameter was tried as `static inline u64 mul(u64 t, u64 k)`: same 224 bytes).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef struct {
    int f0;
    u8 *f4;
    u8 *f8;
} Buf;
extern Buf d_02180A20;
extern u8 d_02180A30;
extern u16 d_02180A00;
extern u64 func_020870D0(void);
extern void func_02075E9C(u16 a);
extern void func_02084DF4(u16 a);
extern void func_02084E2C(u16 a);
extern void func_02075EAC(u16 a);
extern void func_02180904(void);
extern void func_02180914(u16 v);
extern u8 func_02180924(Buf *b);
extern void func_02180984(Buf *b);

static inline u64 ms(u64 t)
{
    u64 m = t * 64;
    m *= 1000;
    return m / 33514;
}

u8 func_02180820(void)
{
    u8 result;
    u64 start;

    d_02180A20.f4 = &d_02180A30;
    d_02180A20.f8 = &result;
    d_02180A30 = 8;
    func_02075E9C(d_02180A00);
    func_02084DF4(d_02180A00);
    start = func_020870D0();
    while (ms(func_020870D0() - start) < 60)
        ;
    func_02180904();
    func_02180914(0x42);
    result = func_02180924(&d_02180A20);
    start = func_020870D0();
    while (ms(func_020870D0() - start) < 60)
        ;
    func_02180914(2);
    func_02180984(&d_02180A20);
    func_02180904();
    func_02084E2C(d_02180A00);
    func_02075EAC(d_02180A00);
    return result;
}
