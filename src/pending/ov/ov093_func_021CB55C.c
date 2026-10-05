/*
 * function: func_021CB55C
 * address: 0x021CB55C
 * packet: pkt_ov093_021CB55C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * checks: 1 own D6B6C body and sqrt one-word interface rederived; unsigned
 *   float/helper call setup agrees; 2 CB5F0 full body refreshed, no twin;
 *   3 a unsigned-long compiles unchanged at 146/2; b/c narrow checks were
 *   previously consumed; 4 multiply-operand, accumulator and inline idioms
 *   read; 5 full idiom directory relisted and matched CB5F0 refreshed.
 * residual: 146/148 bytes, two trailing alignment bytes, 2 concrete bytes
 *   at +76/+7A: product result r2 instead of r1; 14/14 relocations resolve.
 * retry: wave76 R8, 4 compiles. Product operand reversal, unsigned sqrt
 *   temporary and inline Product helper each retain 146/2; stopped after
 *   three nonshrinking changes. Check 3 full-width long a retains 146/2.
 * permuter: once300 consumed wave75 R14; temp(FX32 conversion) and temp(sqrt)
 *   improved146/5 to146/2, emitted baseline and ported C were validated.
 *   Search not repeated; divisor scheduling variants146/8 and144/27 rejected.
 * proof: full unsigned word wrap, float conversions, sqrt call order and
 *   result clamp preserved. No volatile or fabricated input constraints.
 * note 2026-10-05 (wave P15 D5): residue unchanged at 2 bytes (+76 muls r2,r1,r2 vs
 *   original muls r1,r2,r1; +7A lsrs). Original puts Product in the root copy r1,
 *   draft in the squared value r2. Tried, same 2 bytes: operand order (value*value)*root,
 *   int root, t2 as separate statement, Product with value *= value or sq local,
 *   opt_lifetimes/opt_common_subs/scheduling/peephole off. Worse: compound tmp1 *= y*y
 *   (27 B), opt_propagation/opt_dead_assignments off (26 B), sqrt call inside the
 *   expression (5 B, r1/r2 colours swapped), Sq(x) helper for both blocks (28 B).
 *   Callee types checked: FX_Sqrt int, func_021D6B6C u32 (matched). Twin ov093_func_021CBB34
 *   has the same float conversion and FX_Sqrt but no product form.
 * symbols:
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0207C7B4  0x0207C7B4  arm
 *   func_021D6B6C  0x021D6B6C  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
extern int func_0207C7B4(int x);
extern u32 func_021D6B6C(void *p);
static inline u32 Product(u32 root, u32 value)
{
    return (root * (value * value)) >> 12;
}
u32 func_021CB55C(void *p, u32 a, u32 b, u32 c)
{
  int tmp;
  u32 tmp1;
  u32 r, lim;
  u32 x = (2 * c) + 10;
  u32 y = (c + b) + 10;
  u32 t1 = ((u32) (func_0207C7B4((int) ((x > 0) ? ((x * (1 << 12)) + 0.5f) : ((x * (1 << 12)) - 0.5f))) * (x * x))) >> 12;
  tmp = (int) ((y > 0) ? ((y * (1 << 12)) + 0.5f) : ((y * (1 << 12)) - 0.5f));
  tmp1 = func_0207C7B4(tmp);
  r = ((a * t1) / Product(tmp1, y)) + 1;
  lim = func_021D6B6C(p);
  if (r > lim)
    r = lim;
  return r;
}
