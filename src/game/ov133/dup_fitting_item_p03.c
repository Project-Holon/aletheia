/*
 * file:     dup_fitting_item_p03.c
 * unit:     yes
 * function: func_021B7458, func_021B7498, func_021B75E0, func_021B765C, func_021B7A18
 * address:  0x021B7458
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8FF4 0x021B8FF4 thumb ov133
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021BA1D8 0x021BA1D8 thumb ov133
 *   func_021BA0F8 0x021BA0F8 thumb ov133
 *   func_021F4D40 0x021F4D40 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   func_0204F5A8 0x0204F5A8 arm
 *   func_0204F150 0x0204F150 arm
 *   func_021B8A30 0x021B8A30 thumb ov133
 *   func_021B7A70 0x021B7A70 thumb ov133
 *   func_021B8AC8 0x021B8AC8 thumb ov133
 *   func_021B8FA8 0x021B8FA8 thumb ov133
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA210 0x021BA210 thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA244 0x021BA244 thumb ov133
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_020061E4 0x020061E4 thumb
 *   func_0204F638 0x0204F638 arm
 *   func_0204F684 0x0204F684 arm
 *   func_0204F720 0x0204F720 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _ffix 0x0209C494 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   d_021BA3E4 0x021BA3E4 data
 *   d_021BA3E8 0x021BA3E8 data
 *   func_021F4D74 0x021F4D74 thumb ov112
 */
#include "../../matched/include/Obj00777.h"
#include "../../matched/include/Obj00004.h"
#include "../../matched/include/Obj06496.h"

struct Manager0204F684;
struct Trip;
typedef signed short s16_021B7458;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short   s16_021B75E0;

typedef short s16_021B765C;

typedef struct {int x,y,z;} Vec;

typedef struct {int x,y;} Pair;

extern u32 func_02005728(u32 range);
extern int func_021B8FF4(int x, int y, int radius, float scale);
extern void *func_021BA184(char *p);
extern u32 func_021BA208(u8 *p);
extern void func_021BA1D8(u8 *p, u8 *q);
extern void func_021BA0F8(void *);
extern void func_0204F5A8(void *,unsigned int),func_0204F150(u8 *,int);
extern void func_021F4D40(u8 *p, u8 *e);
extern void func_021F4948(u8 *);
extern void func_021B8A30(u8 *);
extern void func_021B7A70(u8 *);
extern void func_021B8AC8(u8 *);
extern void func_021B8FA8(u8 *);
extern u32 func_021BA20C(u8 *p);
extern void func_021BA210(u8 *p, u32 v);
extern u32 func_021BA218(u8 *p);
extern void func_021BA21C(u8 *p, const u8 *src);
extern void func_021BA244(u8 *p, u32 v);
extern void func_021F4E8C(int, int, Vec *);
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
extern void func_021F4EB4(u32 unused, u32 p, s16_021B765C a, s16_021B765C b);
extern void func_021F4E6C(u8 *p, u8 *e, u32 value);
extern void func_020061E4(u32);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern void func_0204F684(struct Manager0204F684 *mgr, int idx, const s16_021B765C *p12, const s16_021B765C *p14);
extern void func_0204F720(void *p, u32 idx, u32 *flag);
extern void func_021F4D74(u8 *, u8 *, int, u16);
void func_021B7458(void *unused, int *p);
void func_021B7498(u8 *p);
void func_021B75E0(u8 *p);
void *func_021B765C(u8 *p, u16 base, s16_021B765C speed, u16 rx, u16 ry);
void func_021B7A18(u8 *p);
extern const s16_021B765C FX_SinCosTable_[];
extern u8 d_021BA3E4[], d_021BA3E8[];

void func_021B7458(void *unused, int *p)
{
    do {
        p[0] = func_02005728(240) + 8;
        p[1] = func_02005728(128) + 32;
    } while (func_021B8FF4((s16_021B7458)(p[0] - 128), (s16_021B7458)(p[1] - 80), 84, 0.739130437374115f) == 1);
}

void func_021B7498(u8 *p)
{
    u8 *e,*next;
    int i;
    e=func_021BA184(((struct Obj00777 *)p)->f181C);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    e=func_021BA184(((struct Obj00777 *)p)->f1820);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    e=func_021BA184(((struct Obj00777 *)p)->f1824);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    e=func_021BA184(((struct Obj00777 *)p)->f1828);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    for(i=0;i<14;i++)func_0204F5A8(((struct Obj00777 *)p)->f188C,*(unsigned int *)(p+i*4+0x5c));
    func_0204F150(*(u8 * *)&((struct Obj00777 *)p)->f188C,((struct Obj00777 *)p)->f58);
    func_021F4D40((u8 *)(*(int *)&((struct Obj00777 *)p)->f1884),(u8 *)(((struct Obj00777 *)p)->f4C));
    func_0204F150(*(u8 * *)&((struct Obj00777 *)p)->f188C,((struct Obj00777 *)p)->f54);
    for(i=0;i<((struct Obj00777 *)p)->fA8;i++){
        func_0204F150(*(u8 **)(p+0x188c),*(int *)(p+i*20+0xb0));
        func_0204F150(*(u8 **)(p+0x188c),*(int *)(p+i*20+0xb4));
    }
    func_021BA0F8(((struct Obj00777 *)p)->f181C);func_021BA0F8(((struct Obj00777 *)p)->f1820);
    func_021BA0F8(((struct Obj00777 *)p)->f1824);func_021BA0F8(((struct Obj00777 *)p)->f1828);
    func_021F4948(*(u8 **)(p+0x1884));
}

void func_021B75E0(u8 *p)
{
    if (((struct Obj00004 *)p)->f98 == 1) func_021B8A30(p);
    else { func_021B7A70(p); func_021B8AC8(p); }
    func_021B8FA8(p);
    ++((struct Obj00004 *)p)->f94;
    if (((struct Obj00004 *)p)->f94 >= 90) {
        ((struct Obj00004 *)p)->f94 = 0;
        func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
    }
    if (((struct Obj00004 *)p)->f94 == 45)
        func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
}

static inline int GetTimer(u8 *p) { return *(u16 *)(p + 0x94); }

/*
 * 2026-10-05 (user decision): the field re-read in the loop (for (n = F; t >= n * K; n = F)) is accepted as a real source quirk.
 * note (2026-10-04, wave D3 lane 08): DIFF, same length as the target. Body matches
 *   instruction for instruction except two spots. (1) Prologue order: the target stores
 *   r1 (base) to [sp] before the 0x181C pool load and stores r3 before idx; ours
 *   loads the pool first. (2) At +0x13C the target does "str r1,[sp,#8]; ldr r1,[sp,#8];
 *   muls" (the u16 at p+0xA8 is a spilled value reloaded for 0x1249*n); ours multiplies
 *   r1 before the store, which shifts all later code by 2 bytes. Tried for (2): n as int
 *   (slot moves to 0xC), lim local vs loop-condition multiply, if+do-while guard,
 *   n*0x1249 vs 0x1249*n, no n at all (field re-read so the compiler CSEs the load;
 *   spill slot right but still no reload). Keys that closed big residues: the local
 *   constants h = 0x8000 and sh = 0xC0000 (the target computes h>>1, h>>3, h>>4, h<<1,
 *   sh>>9 at run time, so they are variables, not literals); sx = tp[0]*rx and
 *   sy = tp[1]*ry operand order; cur = old = f() store order; offy written with "* -8";
 *   case a < h>>1 passes h>>3 directly (not sc) so it is not tail-merged.
 * 2026-10-05 (wave D4 lane 01): DIFF, residue unchanged. Tried: `lim = (n = ...) * 0x1249`; `int idx = 0`
 *   at the declaration; an offset local o = 0x181C for the first access and for p + (o + 0x18) in the first
 *   0x1834 lines (no change: the pool load still schedules first); base as int or u32 (moves the base
 *   store, never to +0004). In the original, base, rx, idx and n are all stored at their definition and
 *   reloaded before use (spill everywhere); ours keeps the value in the register and the scheduler sinks the
 *   store. A fifth live value in the original (more register pressure) is the likely cause; not found.
 * 2026-10-05 (wave D5 lane 04): DIFF, residue unchanged (prologue store order and the n store/reload at
 *   +013C). Tried: n as a block-local u16 in the do body; `lim = (n = field) * 0x1249`; the multiply in the
 *   loop condition `while (t >= (lim = n * 0x1249))` and `while (t >= n * 0x1249) t -= n * 0x1249`; a
 *   static inline wrap(t, n) helper for the second loop; `idx = 0` after the first call (worse); volatile n
 *   as a probe (not a fix: changes the frame, still no reload). The listing has real back edges, so both
 *   while loops are real. The reload means the multiply reads n's home, not the ldrh temp: find what
 *   blocks copy propagation of `n = field` in the original.
 * 2026-10-05 (wave D6 lane 09): DIFF, residue unchanged. Finding: the same str/ldr pair appears in our
 *   build for cur at +0x198 (str r0,[sp,#0x10]; ldr r1,[sp,#0x10]) because cur has two definitions
 *   (cur = old and cur = table), so copy propagation does not replace it. The n reload at +0x13C thus
 *   says that n also has a second definition (or is otherwise not copy-propagated) in the original.
 *   Tried: `u16 n = 0` initialiser (no change), `lim = n; lim *= 0x1249` (no change), the second loop
 *   with the field re-read in the condition and body plus n kept for k (no change). Next: find where a
 *   second def of n can sit without a store in the listing (sp+8 is only written at +0x13C).
 * 2026-10-05 (wave D7 lane 04): DIFF, residue unchanged (533 bytes: prologue store order and the n
 *   reload at +013C). Tried: a second def of n in the prologue (`n = field; lim = 0x1249 * n;`, no change:
 *   n is still copy-propagated in the loop). Reading: in the original the three entry stores (base [sp],
 *   rx [sp,#4], idx [sp,#0x2c]) all stay above the first p+0x181C load, as if they were memory-variable
 *   stores that may alias it; ours sinks the rx store below the load. n at [sp,#8] behaves the same way
 *   (store then reload). So base, rx, idx and n look like memory-resident variables in the original,
 *   not allocator spills; the source cause is still not found.
 * 2026-10-05 (wD9 lane08): DIFF, residue unchanged. Tried: n as u32 (same as int: slots for n and ry
 *   swap, multiply still reads the ldrh temp). Note: ry is also copied to a stack home ([sp,#0xC]) at the
 *   loop guard, so base, rx, ry, idx and n all have stack homes; the prologue stores stay above the
 *   first p+0x181C load in the original only.
 * 2026-10-05 (wave D8 lane 02): DIFF, residue unchanged (533 bytes). Tried: n as int (536; the slots
 *   for n and ry swap, 8 and 0xC, and the multiply still reads the ldrh temp, no reload). The
 *   original pattern (store at the definition, reload at every use, entry stores above the first
 *   load) is spill-everywhere for base, rx, idx and n; no source shape found yet that blocks the
 *   copy propagation of n = field into the multiply.
 * 2026-10-05 (wD9r lane02): DIFF, residue unchanged (533 bytes). Tried: n defined inside the first loop
 *   (`while (t < 0) { n = field; t += n * 0x1249; }`, 646, worse); the 0x1249 factor as a local
 *   `unit = 0x1249` for `lim = n * unit` (533, no change); n read through a static inline getter (533,
 *   no change). Reading: the prologue and the loop wrap use the same shape (ldrh, pool K, copy, muls), and
 *   the image reloads n at the multiply, so the multiply reads n after a block boundary or n is not a
 *   single-def copy there; no source form found.
 * 2026-10-05 (wD9r lane20): DIFF, residue unchanged (533 bytes). New tries, each compiled: the whole body
 *   as a static inline called from a wrapper (544, slots move, prologue order unchanged); sx, sy, old,
 *   cur, spr, t, k, n and tp declared in the do-body block (533, no change). Probe: dsi/1.1 to 1.6sp2
 *   all give 533, so the residue is source, not compiler build. Reading: the same shape as ov116
 *   021D7D0C (store at the def, reload at the use, entry stores held above the first load) means the
 *   image keeps base, rx, idx and n as memory variables, not register-allocator spills; no source
 *   form found that does this without address-taking.
 * 2026-10-05 (wD9r lane42): DIFF, 533 -> 521 bytes. The prologue store order is fixed: the callers
 *   (021B7A70, 021B7CFC, 021B8930) declare (u8 *, u16, s16, int, u16) and pass 72, 48 for rx, ry, so
 *   speed is s16 and rx is a narrow parameter like ry (u16; s16 gives the same code). A narrow rx pins
 *   its home store above the first p+0x181C load (docs/idioms/a-narrow-parameter-pins-its-home-store-
 *   to-the-front-of-the-prologue.md). The only residue left is the n store/reload at +013C (all later
 *   bytes are the 2-byte shift). Probe: a second reaching def of n before the k compare (`if (t == 5)
 *   n = 3;`, not a fix) gives the image's str/ldr/muls exactly, so in the image n has a second
 *   definition that reaches the multiply or the k compare. A def that does not reach (prologue
 *   `n = field; lim = 0x1249 * n;`, a dead `n = 0` at the loop end) changes nothing. Also tried, all 521:
 *   `while (t >= (n = field) * 0x1249) t -= n * 0x1249;`, `while (t >= (lim = (n = field) * 0x1249))`,
 *   `while (t >= (lim = n * 0x1249))`, `while (t >= n * 0x1249) t -= n * 0x1249;`, an explicit if guard
 *   plus do-while, n read through a struct field `((Hdr *)p)->n` (also in the first loop).
 *   More (all compiled): `lim = 0x1249; lim *= n;` after `n = field` (520: str moves above the muls,
 *   still no reload, muls r1,r2,r1); `lim = 0x1249` before `n = field` (525); a `for (;;)` with break
 *   (605); n as a 6th function parameter (probe only, 56 B: parameters are not copy-propagated, the
 *   reload appears at [sp,#0x6c]); reusing the speed parameter for n (612/888). Inline helpers for the
 *   tail (wrap loop, if, k, cur pick) with n as a helper parameter: with `u8 *cur = old;` inside the
 *   helper (668) the image's `str r1,[sp,#8]; ldr r1,[sp,#8]; muls` appears, but the helper adds a
 *   `ldr [sp,#0x14]; str [sp,#0x10]` copy for cur after the t loop (the image stores cur at the call,
 *   +010A); with cur passed by pointer (`u8 **pcur`, 521) or with two returns (663) n is propagated
 *   again. Reading: the image's n is a copy that mwcc does not propagate (a parameter-like variable),
 *   and something sits between `n = field` and the multiply in the IR without code of its own.
 * 2026-10-05 (wD9r lane86): DIFF, residue unchanged (521 bytes, only the n str/ldr at +013C). New
 *   tries, each compiled, all 521 unless noted: k and the second wrap in an inline helper called before
 *   the condition (the divide is not sunk into the if); `t = Wrap(t, n)` inline helper with an int
 *   return; the whole f(e)..pick segment as an inline helper returning cur (523, old/cur stores swap);
 *   `GetCount(p, &n)` inline out-parameter; `register u16 n`; block-local `const u16 n`; `int unit =
 *   0x1249` at the top used in one, two or all three places; the wrap on a copy `f = t`; n reused for the
 *   (u16)(0x6E00 - a) and (u16)(0x78E0 - a) temps; the frame index written into n (`if (k >= n) n = k -
 *   n; else n = k;`, both orders); `lim = field * 0x1249` with `n = field` after the wrap; the n def
 *   behind a goto label; `for (n = field; t >= n * 0x1249; )`; `int speed` reused for n (888).
 *   Findings: (1) n = field written in both arms of `if (t < 0) { while (t < 0) ...; n = field; } else n
 *   = field;` gets cross-jumped into one tail and gives the reload, but the inner while keeps a redundant
 *   `cmp r0,#0; bge` (635), and the reload sits in the join block (str before the pool load, the image
 *   has the pool load first); with a do-while in the arm (630) the arm's n is CSE'd with the loop's
 *   hoisted load. (2) An intervening statement that needs a register between `n = field` and the
 *   multiply (a memory store, a spilled-local copy) also gives the reload; a store of a callee-saved
 *   value (`cur = spr`), a register copy, or a constant assignment does not. (3) A reaching second def
 *   after the wrap (`if (t == 5) n = 3;`, probe) reproduces the image's exact order (pool load, str,
 *   ldr, muls), so the image's n most likely has a second reaching def or is parameter-like; no natural
 *   codeless form found.
 * 2026-10-05 (wD9r lane116): DIFF, residue unchanged (521 bytes, only the n str/ldr at +013C). Twin
 *   search: 0x1249 appears only in ov133 021B6100 (frame pick as `m = F * 0x1249; if (t >= m) x = (t - m)
 *   / 0x1249; else ...`, no n local) and 021B6F00 (init); no matched copy of this routine. New tries
 *   (F = the u16 at p+0xA8), each compiled: n as a one-field local struct (521, scalarised); `while (t <
 *   0) { n = F; t += n * 0x1249; } n = F;` (964/635: the +0134 block is now byte-exact, str/ldr/muls in the
 *   image order, but hoisting the loop assignment adds a re-test `cmp r0,#0; bge` after the preheader);
 *   the same with `(n = F)` in the loop expression and as a for loop (635); `if (t < 0) { n = F; do ...
 *   while }` and `if (t < 0) do { n = F; ... } while` (521); `if (t < 0) { n = F; while ... }` (635,
 *   re-test); `n = F` before the first loop (631, CSE); if/else arms with a for(;;)+break or do-while
 *   loop and `n = F` in both arms (630, 632: CSE with the hoisted load); n re-read (`n = F`) inside the
 *   condition block before or after k, or only there with `lim = F * 0x1249` (521, CSE'd away); no n and
 *   F read at the k compare (521); a later def that reads n (`n += k` or `n = k - n` with a use after,
 *   562/563, no reload); `else n = 3` after the k compare (no reload). Probes (not fixes): moving the
 *   loop-top `sc = 0` (store to the address-taken sc) between `n = F` and the multiply gives the image's
 *   str/ldr/muls (115 bytes left, all from the moved strh), so any memory store there blocks the load
 *   forwarding into the multiply; a def of n inside the condition block before k (`if (t == 5) n = 3;`)
 *   also gives it, a def after the k compare does not. Open: a codeless memory kill or a codeless
 *   second def between +0138 and +0184; none of the image's stores fits.
 */
void *func_021B765C(u8 *p, u16 base, s16_021B765C speed, u16 rx, u16 ry)
{
    Vec v;
    Vec w;
    Pair pos;
    s16_021B765C sc;
    int idx;
    u16 rot;
    int offx;
    int offy;
    int sx;
    int sy;
    u8 *old;
    u8 *cur;
    u16 a;
    u8 *e;
    u8 *spr;
    int t;
    u16 k;
    int lim;
    u16 n;
    const s16_021B765C *tp;
    u32 h = 0x8000;
    int sh = 0xC0000;

    idx = 0;
    e = func_021BA184((char *)(*(u8 **)(p + 0x181C)));
    *(int *)(p + 0x1834) += speed;
    if (*(int *)(p + 0x1834) < 0)
        *(int *)(p + 0x1834) += *(u16 *)(p + 0xA8) * 0x1249;
    lim = 0x1249 * *(u16 *)(p + 0xA8);
    if (*(int *)(p + 0x1834) >= lim)
        *(int *)(p + 0x1834) -= lim;
    rot = *(u16 *)(p + 0x1838);
    offx = (FX_SinCosTable_[0] - FX_SinCosTable_[(rot >> 4) * 2]) << 3;
    offy = FX_SinCosTable_[1] - 0x8008 - FX_SinCosTable_[(rot >> 4) * 2 + 1] * -8;
    if (speed > 0x9C4 || speed < -0x9C4) {
        if (*(u16 *)(p + 0x18C2) == 0) {
            *(u16 *)(p + 0x18C2) = 30;
            func_020061E4(0x624);
        }
    }
    if (e == 0)
        goto end;
    do {
        a = (u16)((base + (idx << 16) / 14) % 0x10000);
        sc = 0;
        spr = (u8 *)func_021BA218(e);
        tp = &FX_SinCosTable_[(a >> 4) * 2];
        sx = tp[0] * rx + 0x80000;
        sy = tp[1] * ry + 0x50000;
        cur = old = (u8 *)func_021BA20C(e);
        t = *(int *)(p + 0x1834) + (a + 0x8000) % 0x10000;
        while (t < 0)
            t += *(u16 *)(p + 0xA8) * 0x1249;
        for (n = *(u16 *)(p + 0xA8); t >= n * 0x1249; n = *(u16 *)(p + 0xA8))
            t -= n * 0x1249;
        if (*(int *)(p + 0x98) == 0 || *(u32 *)(p + 0x9C) > (u32)((0x18000 - a) % 0x10000)) {
            k = (u16)((t + 0x924) / 0x1249);
            if (k >= n)
                k = (u16)(k - n);
            cur = *(u8 **)(p + k * 4 + 0x1434);
            func_021BA210(e, (u32)cur);
            if (*(u16 *)old != *(u16 *)cur && e == *(u8 **)(p + 0x38))
                *(u8 **)(p + 0x38) = 0;
        }
        if (a >= h)
            a = (u16)((h << 1) - a);
        pos.x = (int)((float)sx / 4096.0f);
        pos.y = (int)((float)sy / 4096.0f);
        v.x = sx + offx;
        v.y = sy + offy;
        v.z = (h - a) + 0x14000;
        func_021F4E8C(*(int *)(p + 0x1884), (int)spr, &v);
        func_021F4ED4(*(int *)(p + 0x1884), (int)spr, rot);
        func_021BA21C(e, (const u8 *)(&pos));
        if (a < (h >> 1)) {
            sc = h >> 3;
            func_021F4EB4(*(int *)(p + 0x1884), (int)spr, h >> 3, h >> 3);
            func_021F4E6C((u8 *)(*(int *)(p + 0x1884)), (u8 *)((int)spr), 1);
            func_021BA244(e, h >> 3);
        } else if (a < 0x6E00) {
            sc = ((u16)(0x6E00 - a) << 11) / 0x2E00 + (h >> 4);
            func_021F4EB4(*(int *)(p + 0x1884), (int)spr, sc, sc);
            func_021F4E6C((u8 *)(*(int *)(p + 0x1884)), (u8 *)((int)spr), 1);
            func_021BA244(e, sc);
        } else if (a < 0x78E0) {
            sc = ((u16)(0x78E0 - a) << 11) / 0xAE0;
            func_021F4EB4(*(int *)(p + 0x1884), (int)spr, sc, sc);
            func_021F4E6C((u8 *)(*(int *)(p + 0x1884)), (u8 *)((int)spr), 1);
            func_021BA244(e, sc);
        } else {
            func_021F4E6C((u8 *)(*(int *)(p + 0x1884)), (u8 *)((int)spr), 0);
            func_021BA244(e, 0);
            sc = 0;
        }
        if (*(int *)(cur + 0x10) == 1 && GetTimer(p) < 45) {
            w.x = v.x / 16;
            w.y = (sh - (v.y + 0x8000)) / 16;
            w.z = v.z + (sh >> 9);
            func_0204F638((u8 *)(*(int *)(p + 0x188C)), *(int *)(p + idx * 4 + 0x5C), (struct Trip *)(&w));
            func_0204F684((struct Manager0204F684 *)(*(int *)(p + 0x188C)), *(int *)(p + idx * 4 + 0x5C), &sc, &sc);
            func_0204F720((void *)(*(int *)(p + 0x188C)), *(int *)(p + idx * 4 + 0x5C), (u32 *)d_021BA3E8);
        } else {
            func_0204F720((void *)(*(int *)(p + 0x188C)), *(int *)(p + idx * 4 + 0x5C), (u32 *)d_021BA3E4);
        }
        e = (u8 *)func_021BA208(e);
        idx++;
    } while (e != 0);
end:
    return func_021BA184((char *)(*(u8 **)(p + 0x181C)));
}

void func_021B7A18(u8 *p)
{
    u8 *e = func_021BA184(((struct Obj00004 *)p)->f181C);
    u8 *q;
    u8 *s;
    while (e) {
        q = (u8 *)func_021BA20C(e);
        s = (u8 *)func_021BA218(e);
        if (((struct Obj06496 *)q)->fC == 1)
            func_021F4D74(*(u8 **)(p + 0x1884), s, ((struct Obj06496 *)q)->f0, ((struct Obj06496 *)q)->f8);
        else
            func_021F4D74(*(u8 * *)&((struct Obj00004 *)p)->f1884, s, ((struct Obj06496 *)q)->f0, ((struct Obj06496 *)q)->f4);
        e = (u8 *)func_021BA208(e);
    }
}
