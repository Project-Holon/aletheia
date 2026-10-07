/*
 * file:     trcard_sys_p10.c
 * unit:     yes
 * function: func_0216FC74, func_0216FCA0, func_0216FD54, func_0216FE04, func_0216FE2C
 * address:  0x0216FC74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216FC50 0x0216FC50 thumb ov010
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_02043994  0x02043994  arm
 *   func_020437D4  0x020437D4  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021726A0     0x021726A0  data  ov010
 *   func_02043678  0x02043678  arm
 *   func_0207F7A0  0x0207F7A0  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207F7FC  0x0207F7FC  arm
 *   func_0207F9B4  0x0207F9B4  arm
 *   func_020437AC  0x020437AC  arm
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 */
#include "../../matched/include/Obj12410.h"

struct Bmp;
struct Obj020437AC;
typedef signed short s16;

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u16 w;
    u8 pad[10];
} TE;

struct Rec {
    u8 x;
    u8 y;
    u8 pad[10];
};

struct Pos {
    u8 pad[0x0c];
    u16 x;
    u16 y;
};

extern void func_0216FC50(void *);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u8 func_02043994(struct Bmp *b);
extern void *func_020437D4(const struct Bmp *bmp);
extern int _s32_div_f(int a, int b);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_0207F7A0(void);
extern void func_020862F0(void *p, int n);
extern void func_0207F7FC(void *p, int src, int n);
extern void func_0207F9B4(void);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_0207FA0C(void);
extern void func_0207FA40(void *,u32,u32);
extern void func_0207FADC(void);
void func_0216FC74(void *a, u16 b, u16 c, u16 d, void *e, void *f);
void func_0216FCA0(void *a, void *b);
void func_0216FD54(char *a, u32 b, u16 c, u16 d, u16 e, u16 f);
void func_0216FE04(char *p,void *q);
int func_0216FE2C(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags);
extern TE d_021726A0[];

void func_0216FC74(void *a, u16 b, u16 c, u16 d, void *e, void *f) { func_0216FC50(e); func_0201C7D0(e,b,c,a,f,d); }

/*
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
 * Callee types checked: func_020437DC/E4 u16, func_02043994 u8 (sub_02043994.c),
 * func_020437D4 returns a pointer (ov208 callers); all as declared here.
 * No tile-order twin (grep func_02043994, func_020437E4+func_020437DC in src/matched/ov).
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
 * pass 2 2026-10-06 P2L24: EXACT (c99 and c). Fix: q = i / s as a named statement before r = i % s
 * (quotient call first, as the original) together with (q / 8) * w instead of w * (q / 8): the operand
 * order of that product decides which value the allocator spills, and with it the named-q form keeps
 * the stride spilled. The unused `total` local is dropped (the loop bound is the inline product).
 */
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
  d = func_02043994(a);
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


/*
 * EXACT in --lang c99 and --lang c, 176/176 bytes, all 12 relocations resolved.
 * recoup 2026-10-05 (lane C1, ~27 compiles): the older draft (docs/notes) was 110 B off at 172 B.
 * Fixes: hi and wi are plain u32 with an unsigned shift, no u16 or enum (no lsls/lsrs pairs),
 * the area is signed (int)(wi * h) / 8 with h the raw table halfword, and n is an int (a u32 n
 * lets mwcc sink the divide chain below func_0207F7A0; int n keeps it before the call as the
 * original does). Table const, order of wi/hi loads, n position, int/u16 h, callee u32 params,
 * and the six per-function pragmas (on the earlier form) did not help.
 * Residue: (1) entry spills: the original stores r2, r3, r1 with the table index load between;
 * ours stores r1, r2, r3 and loads the u16 argument f before the h spill. (2) base (a+0xc) is
 * loaded early into r4 and off into r5 in the original; ours loads base after the chain into r5
 * and off into r4, so the final add is r5,r4 instead of r4,r5.
 *
 * final push 2026-10-05 G5L10 (40 compiles, 3 rounds): 23 -> 7 B. Fixes: (1) c and d are u16
 * here and u16 in func_0216FC74 (the caller func_0216FAB4 declares them u16): the entry
 * spills come out r2, r3, r1 as in the original; b is u32 (FAB4 passes u32). (2) the tail
 * mirrors the matched sibling func_0216FE04 (u32 b,a; a = base field first, then b = (u16)field*8):
 * base is read BEFORE off and declared AFTER it (u32 off; u32 base;), which gives the base load
 * right after the offset load and the final add r4,r5.
 * Residue (7 B): the original loads the heap halfword f (add r3,sp,#0x38; ldrh r3,[r3,#4])
 * after the wi index load (ldrh r0,[r5]) and after the h spill and lsrs; ours hoists it above
 * the h spill. Tried without effect: const a, struct view of a, inline alloc helper, u16 heap
 * local, *(u16 *)&f, w local, wi/hi inline or reordered (wi before hi or h declared last
 * moves spill slots, 154 B), u32 heap callee param (117 B), five opt_ pragmas, peephole off.
 * pass 2 2026-10-06 P2L15 (40 compiles, 3 rounds, no change to the form, still 7 B): cause found.
 * The image's heap load waits for `str h` because that store goes to a memory OBJECT; a spill
 * store never blocks a stack-parameter load. Diagnostic `func_020437AC(&h)` puts the f load at
 * +0x20 exactly; `&vram, &buf, &h` with declarations vram, buf, h also gives the image frame
 * (h 0x14, buf 0x18, vram 0x1c), so the original keeps h, buf and vram in memory. Every memory
 * form tried (aggregate {h,buf,vram} with an address use, value temp, wi first, u32 c/d, u16 b)
 * also flips the entry (str r1,[sp,#8] first, index in r1). Forms that do not keep h in memory:
 * inline out-pointer helper, hp = &h, unused &w, union, one-member struct/array, nested blocks
 * (all folded or scalarised). optimization_level 1 shows the f load is textually last.
 * pass 3 2026-10-06 P3L08 (3 compiles): EXACT. h is a u16 local (the table halfword) and
 * hi = (u32)h >> 3 keeps lsrs. mwcc keeps the u16 stack parameter f load behind the spill
 * store of a narrow local, but hoists it above the spill of a u32 local (docs/idioms
 * a-u16-stack-parameter-passed-to-a-u16-callee-stays-behind-a-spill-store.md, sub_0201B2B0
 * pidHigh; a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md for the (u32) widen).
 * The earlier u16 h try (154 B) used h >> 3, which promotes to int and gives asrs.
 */
void func_0216FD54(char *a, u32 b, u16 c, u16 d, u16 e, u16 f)
{
    u16 h;
    u32 hi;
    u32 wi;
    void *buf;
    void *tmp;
    void *vram;
    int n;
    u32 off;
    u32 base;

    h = d_021726A0[*(u16 *)(a + 2)].w;
    hi = (u32)h >> 3;
    wi = (u32)d_021726A0[*(u16 *)a].w >> 3;
    tmp = func_02043678(wi, hi, 0x20, f);
    buf = func_02043678(wi, hi, 0x20, f);
    func_0216FC74((void *)b, c, d, e, buf, *(void **)(a + 0x14));
    func_0216FCA0(buf, tmp);
    vram = func_020437D4(tmp);
    base = *(u32 *)(a + 0xc);
    off = (u16)*(int *)(a + 4) << 3;
    n = ((int)(wi * h) / 8) << 5;
    func_0207F7A0();
    func_020862F0(vram, n);
    func_0207F7FC(vram, base + off, n);
    func_0207F9B4();
    func_020437AC(buf);
    func_020437AC(tmp);
}

void func_0216FE04(char *p,void *q) { u32 b,a; a=((struct Obj12410 *)p)->f10; b=(u16)((struct Obj12410 *)p)->f8*8; func_0207FA0C(); func_020862F0(q,32); func_0207FA40(q,a+b,32); func_0207FADC(); }


/*
 * Classifies table entry idx (12-byte records) against a position:
 * 0 = inside, 1 = within three steps on one axis, 2 = out of reach or
 * locked. 0xFF marks an unused record; 0xFE records are gated by a bit
 * (idx - 0x21) of the 16-bit mask at flags.
 */
int func_0216FE2C(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags)
{
    int x;
    int y;
    int m;

    x = tbl[idx].x;
    if (x == 0xff)
        return 2;
    if (x == 0xfe) {
        m = flags[0] | (flags[1] << 8);
        if (m & (1 << (idx - 0x21)))
            return 0;
        return 2;
    }
    if (x <= pos->x) {
        y = tbl[idx].y;
        if (y <= pos->y)
            return 0;
        if (y - pos->y <= 3)
            return 1;
    } else {
        y = tbl[idx].y;
        if (y <= pos->y) {
            if (x <= pos->x)
                return 0;
            if (x - pos->x <= 3)
                return 1;
        }
    }
    return 2;
}
