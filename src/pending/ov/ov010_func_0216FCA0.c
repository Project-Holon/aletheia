/*
 * function: func_0216FCA0
 * address: 0x0216FCA0
 * packet: pkt_ov010_0216FCA0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 *
 * DIFF, 24 concrete bytes, 180/180 bytes, all 9 relocations resolved.
 * Tile-order copy: w, h in 8-pixel units, d = depth byte, t = (d<<13)>>16;
 * dst[i] = src[(r/t + w*(q/8))*d + (q%8)*t + r%t] with s = w*t, q = i/s, r = i%s.
 * recoup 2026-10-05 (lane B2, 21 compiles): the old draft (docs/notes) had the
 * right logic. Division calls are CSE'd by mwcc (equal calls merge at the first
 * use), so the old tmp/q/pad locals were unnecessary. Clean form with r named and
 * the quotient written inline twice gives the hoisted stride spilled (as the
 * original) and the original register colours, 24 B off. Residue: the original
 * calls i/s FIRST (quotient into r4) then i%s (remainder into r7); mwcc emits the
 * remainder first, and the four spill slots (w, d, total, stride) come out in
 * reverse order of the original (orig 8,4,0xc,0x10; ours 0x10,0xc,4,8).
 * Tried and worse: named q (97 B, stride no longer hoisted, i/q colours swap),
 * all-inline with quotient term leftmost (24 B, same) or rightmost (81 B),
 * named q plus inline r (97 B), q named plus one inline quotient (73 B), s named
 * in loop (127 B), total as loop bound (124 B), w/h/t as plain /8 (166 B: the
 * original keeps the lsls 13 / lsrs 16 pair), pragmas scheduling,
 * opt_propagation, opt_lifetimes off (24, 27, 24 B).
 * Callee types checked: func_020437DC/E4 u16, func_02043994 u8 (sub_02043994.c),
 * func_020437D4 returns a pointer (ov208 callers); all as declared here.
 * No matched twin (grep func_02043994, func_020437E4+func_020437DC in src/matched/ov).
 * Idioms read: div-and-mod-are-two-calls, a-self-recompute-pins-an-operand-before-the-other-side-calls,
 * a-field-captured-before-a-named-divider-stays-live-across-the-call,
 * binding-a-modulo-result-to-a-local-moves-the-add-destination,
 * a-byte-count-local-preserves-word-spills-and-reloads,
 * a-spilled-value-below-the-cse-temps-is-an-inline-expression-not-a-named-local.
 *
 * symbols:
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_02043994  0x02043994  arm
 *   func_020437D4  0x020437D4  arm
 *   _s32_div_f     0x0209C0A4  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u16 func_020437DC(const void *p);
extern u16 func_020437E4(const void *p);
extern u8 func_02043994(void *p);
extern u8 *func_020437D4(const void *p);
extern int _s32_div_f(int a, int b);
void func_0216FCA0(void *a, void *b)
{
  u8 *src;
  u8 *dst;
  int total;
  int w;
  int d;
  int h;
  int t;
  int i;
  int r;
  w = ((u32) (func_020437DC(a) << 13)) >> 16;
  h = ((u32) (func_020437E4(a) << 13)) >> 16;
  d = func_02043994(a);
  t = ((u32) (d << 13)) >> 16;
  src = func_020437D4(a);
  dst = func_020437D4(b);
  total = (w * h) * d;
  for (i = 0; i < ((w * h) * d); i++)
  {
    r = i % (w * t);
    dst[i] = src[((r / t) + w * ((i / (w * t)) / 8)) * d + ((i / (w * t)) % 8) * t + r % t];
  }
}
