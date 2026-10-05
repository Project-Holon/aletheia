/*
 * function: func_021BE210
 * address: 0x021BE210
 * packet: pkt_ov172_021BE210
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-05, wD4 lane17): still DIFF, 159 bytes, 212 vs 208. Tried k as int, declaration order of all locals reversed: no change. Listing facts: original frame has 4 slots (idx [sp], h [sp+4], v as (x<<24) [sp+8], rc at sp+0xC); idx is spilled and k lives in r7, v is spilled. Ours keeps idx in r7, spills k, keeps v in r7. Needs a way to make idx the spilled value.
 * 2026-10-05 (wD5 lane20): 159 -> 36 bytes (the residue is one load placement plus a 2 byte shift). Levers: `k = idx;` written BEFORE `if (a[8] == 3) return;` (the original loads r7 from the idx spill before the compare; this makes idx the spilled value and k the r7 value, prologue now matches), and `u32 xk = rc.xv.b[k]; rc.x = xk + (v >> 1);` (loads xv[k] before the v shift). Residue: ours reloads idx (`ldr r2,[sp]`) for the third call (func_021B8B94) hoisted above the xv/yv byte copies; the original reloads it right before the call like the first two. Tried: operand swap in rc.x, u32 k as the parameter with idx a copy (65 bytes, k in r6).
 * 2026-10-05 (wD6 lane12): still DIFF, 36 bytes (one instruction placement). The move of idx into r2 for the third
 *   call is scheduled before register allocation and hoisted into the stall after the first ldrb of the xv copy; the
 *   original keeps it after `ldr r1,[r5,r4]`. Tried: element-wise byte copies, memcpy with the house string.h (212
 *   bytes), the stores through a `struct Pt *` local, xv/yv as separate locals, idx copied into a one-field local
 *   struct (scalar-replaced, same), idx as a one-field struct parameter (push {r0-r3}, worse), a goto label between
 *   the copies and the call (removed), *(volatile u32 *)&idx at the third call (worse).
 * 2026-10-05 (wave D7 lane 11): still DIFF, 36 bytes. Tried: the third call plus func_02008510 as a static
 *   inline helper get_h(a, idx) (same 36 bytes). Reading: the original treats the [sp] reload like a memory
 *   load that the rc byte stores may alias (it never passes them), so idx may be a real memory local in the
 *   original; no legal source reason for that was found (address-taking idx is a stand-in).
 * symbols:
 *   func_021BE05C 0x021BE05C thumb ov172
 *   func_021B8BA4 0x021B8BA4 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B8B94 0x021B8B94 thumb ov172
 *   func_02008510 0x02008510 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045808 0x02045808 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   d_021C7048 0x021C7048 data ov172
 *   d_021C704C 0x021C704C data ov172
 *
 * note 2026-10-04 (wD2 lane18): DIFF, 159 bytes differ (212 vs 208 compiled). Logic derived from
 * the listing: mode=f05C(a); a->8==3 returns; k = idx, or idx?3:2 when mode==1; both checks
 * (8BA4, 8B8C) must return 1; rc = {x,y,yv[4],xv[4]} with xv/yv byte-copied from the two pool
 * data words; x = xv[k] + ((u8)0201D304(h,a[0x1C8],0) >> 1), y = yv[k]; then 0204B404(a[0x1B0],&rc,0),
 * 0204B3DC(..,1), 0204B9A0. Residue: the original spills idx to [sp] at entry and keeps k in r7
 * (frame 0x18, r3 pushed); ours keeps idx in r7 and spills k. Tried: ternary form of k, k declared
 * last, *(u32 *)&idx at the calls (forces a varargs-style arg push, worse). Data words 021C7048/
 * 021C704C have no witness (integrator data hint needed).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Q { u8 b[4]; };
struct Pt { u16 x; u16 y; struct Q yv; struct Q xv; };
extern int func_021BE05C(void *p);
extern u32 func_021B8BA4(int unused, char *base, int i);
extern u32 func_021B8B8C(int unused, char *base, int i);
extern char *func_021B8B94(int unused, char *base, int i);
extern void *func_02008510(void *a, int tag);
extern u32 func_0201D304(void *s, u32 a, u32 b);
extern void func_02045808(void *);
extern void func_0204B404(void *, void *, u32);
extern void func_0204B3DC(void *, u32);
extern void func_0204B9A0(void *);
extern const struct Q d_021C7048;
extern const struct Q d_021C704C;
void func_021BE210(char *a, u32 idx)
{
    struct Pt rc;
    void *h;
    u32 v;
    int mode;
    u32 k;
    mode = func_021BE05C(a);
    k = idx;
    if (*(int *)(a + 8) == 3) return;
    if (mode == 1) k = (k == 0) ? 2 : 3;
    if (func_021B8BA4((int)a, *(char **)(a + 0x1E4), idx) != 1) return;
    if (func_021B8B8C((int)a, *(char **)(a + 0x1E4), idx) != 1) return;
    rc.xv = d_021C704C;
    rc.yv = d_021C7048;
    h = func_02008510(func_021B8B94((int)a, *(char **)(a + 0x1E4), idx), *(u16 *)a);
    v = (u8)func_0201D304(h, *(u32 *)(a + 0x1C8), 0);
    func_02045808(h);
    { u32 xk = rc.xv.b[k]; rc.x = xk + (v >> 1); }
    rc.y = rc.yv.b[k];
    func_0204B404(*(void **)(a + 0x1B0), &rc, 0);
    func_0204B3DC(*(void **)(a + 0x1B0), 1);
    func_0204B9A0(*(void **)(a + 0x1B0));
}
