/*
 * function: func_021A4F58
 * address:  0x021A4F58
 * packet:   pkt_ov021_021A4F58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: only r0/r1 swap around the v.y -= 0x8000 (original keeps v.y
 * in r0 and the constant in r1). Compare order, decl order, compound forms tried.
 * 2026-10-01 (wave A2): also inert: v.y = v.y - 0x8000, += -0x8000, -0x8000 + v.y,
 * early return, (v.y -= 0x8000) < lim, <= in the clamp, y local, enum step local,
 * inline SubY helper, const Vec in the callee prototypes, void *h, u8 *p, int *p,
 * long fields/lim. Pointer-to-v (pv->y) and lim > v.y are worse.
 * 2026-10-02 (wave A2 relaunch): also inert (still the same 5 B): const on all
 * callee Vec params, u32 *const p / const h, const int lim copy, int/const/early
 * step local (0x8000 as d), 0x8000u, (int)0x8000u, 0x8000L, float FX32 forms,
 * ~0x7FFF, 0xFFFF8000 add, 0x10000/2, split -0x4000 -0x4000, int v[3] array,
 * int-returning callee prototypes, all 6 declaration orders, y/l copy locals in
 * the outer test only, int y = v.y - 0x8000 then v.y = y, inline helpers (whole
 * clamp, Step(y), Sub(a,b), Chk(y,lim), Get(h,v,lim), 021A56C0-style Chk), bool
 * flag local, !(v.y <= lim), goto forms, do{}while(0), unsigned field/lim casts.
 * Worse: struct {lim; v} local, y local carried through (loads flip order),
 * v.y - lim < 0, switch, Lower(&v.y) helper.
 * Finding: with the outer test removed (one block), MWCC biases the subs result
 * to the loaded value (ldr r1; subs r1, r1, r0) like the original. Across the
 * ble block boundary it biases to the materialised constant instead, so the
 * original's load and subtract likely sit in one block in a form not yet found
 * (the sole such pattern in ov021.s; the ov018 0217C820 `v.x -= 0x8000` match
 * shows the constant-biased form too).
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 */

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A4F58;

u32 func_021A3960(u32 x);
void func_0216D88C(u32 h, Vec021A4F58 *v);
void func_02163E58(u32 h, Vec021A4F58 *v, int *lim);
void func_0216D570(u32 h);
void func_0216D89C(u32 h, Vec021A4F58 *v);

void func_021A4F58(u32 *p)
{
    u32 h = func_021A3960(p[3]);
    Vec021A4F58 v;
    int lim;

    func_0216D88C(h, &v);
    func_02163E58(h, &v, &lim);
    if (v.y > lim) {
        v.y -= 0x8000;
        if (v.y < lim) {
            v.y = lim;
            func_0216D570(h);
            p[7] = 1;
        }
        func_0216D89C(h, &v);
        p[0] = 7;
    }
}
