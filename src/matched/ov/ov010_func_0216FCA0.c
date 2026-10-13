/*
 * function: func_0216FCA0
 * address: 0x0216FCA0
 * packet: pkt_ov010_0216FCA0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * DIFF, 12 concrete bytes, 180/180 bytes, all 9 relocations resolved.
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
 * Callee types checked: func_020437DC/E4 u16, BMP_GetTileBytes u8 (BMP_GetTileBytes.c),
 * func_020437D4 returns a pointer (ov208 callers); all as declared here.
 * No tile-order twin (grep BMP_GetTileBytes, func_020437E4+func_020437DC in src/matched/ov).
 * Idioms read: div-and-mod-are-two-calls, a-self-recompute-pins-an-operand-before-the-other-side-calls,
 * a-field-captured-before-a-named-divider-stays-live-across-the-call,
 * binding-a-modulo-result-to-a-local-moves-the-add-destination,
 * a-byte-count-local-preserves-word-spills-and-reloads,
 * a-spilled-value-below-the-cse-temps-is-an-inline-expression-not-a-named-local.
 *
 * final push 2026-10-05 G6L2 (about 38 compiles, 3 rounds): 24 -> 12 B. The lsls #13 / lsrs #16
 * pair is the u16 truncation of x / 8: w, h, t are u16 locals (w = f() / 8, t = d / 8) and d is
 * a u8 local (the callee returns u8). Narrow locals take the lowest spill slots: the four spill
 * slots now match the original (d 4, w 8, total 0xc, stride 0x10). With >> 3 instead of / 8 the
 * w and d slots swap (19 B).
 * Residue (12 B): the original calls i / s FIRST (quotient into r4) and i % s second (remainder
 * into r7); we emit the remainder first, and the tail copy of (q % 8) goes into r2 where we copy t.
 * Call order follows source order only when q is a named statement before r; every such form
 * (named q with named or inline r, s named inside or before the loop, block-scope locals,
 * declaration orders, opt_propagation/opt_lifetimes/scheduling off) emitted the quotient first
 * but kept the stride in r7 and spilled the remainder (182 B, about 95 B off). All-inline index
 * in any term order (q%8 first, r%t first, w*q/8 first) and a named q%8 term keep remainder first.
 * Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register,
 * opt-propagation-off-with-named-locals-pins-argument-constants-against-stack-stores,
 * div-and-mod-are-two-calls, binding-a-modulo-result-to-a-local-moves-the-add-destination.
 * Matched twin for callee types: ov121 021DA338 (u16, u16, u8).
 *
 * symbols:
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   BMP_GetTileBytes  0x02043994  arm
 *   func_020437D4  0x020437D4  arm
 *   _s32_div_f     0x0209C0A4  arm
 *
 * pass 2 2026-10-06 P2L24: EXACT (c99 and c). Fix: q = i / s as a named statement before r = i % s
 * (quotient call first, as the original) together with (q / 8) * w instead of w * (q / 8): the operand
 * order of that product decides which value the allocator spills, and with it the named-q form keeps
 * the stride spilled. The unused `total` local is dropped (the loop bound is the inline product).
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct Bmp;
extern u16 func_020437DC(const struct Bmp *bmp);
struct Bmp;
extern u16 func_020437E4(const struct Bmp *bmp);
extern u8 BMP_GetTileBytes(struct Bmp *b);
extern void *func_020437D4(const struct Bmp *bmp);
extern int _s32_div_f(int a, int b);
void func_0216FCA0(void *a, void *b)
{
  u8 *src;
  u8 *dst;
  u16 w;
  u16 h;
  u8 d;
  u16 t;
  int i;
  int r;
  int q;
  w = func_020437DC(a) / 8;
  h = func_020437E4(a) / 8;
  d = BMP_GetTileBytes(a);
  t = d / 8;
  src = func_020437D4(a);
  dst = func_020437D4(b);
  for (i = 0; i < ((w * h) * d); i++)
  {
    q = i / (w * t);
    r = i % (w * t);
    dst[i] = src[((r / t) + (q / 8) * w) * d + (q % 8) * t + r % t];
  }
}
