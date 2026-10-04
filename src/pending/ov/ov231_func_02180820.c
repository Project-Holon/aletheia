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
