/*
 * function: func_0216FD54
 * address: 0x0216FD54
 * packet: pkt_ov010_0216FD54
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 *
 * DIFF, 7 concrete bytes, 176/176 bytes, all 12 relocations resolved.
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
 * symbols:
 *   d_021726A0     0x021726A0  data  ov010
 *   func_02043678  0x02043678  arm
 *   func_0216FC74  0x0216FC74  thumb  ov010
 *   func_0216FCA0  0x0216FCA0  thumb  ov010
 *   func_020437D4  0x020437D4  arm
 *   func_0207F7A0  0x0207F7A0  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207F7FC  0x0207F7FC  arm
 *   func_0207F9B4  0x0207F9B4  arm
 *   func_020437AC  0x020437AC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 w;
    u8 pad[10];
} TE;

extern TE d_021726A0[];

extern void *func_02043678(u32 a, u32 b, u32 c, u16 d);
extern void func_0216FC74(u32 a, u16 b, u16 c, u16 d, void *e, void *f);
extern void func_0216FCA0(void *a, void *b);
extern void *func_020437D4(const void *p);
extern void func_0207F7A0(void);
extern void func_020862F0(void *p, int n);
extern void func_0207F7FC(void *p, int src, int n);
extern void func_0207F9B4(void);
extern void func_020437AC(void *p);

void func_0216FD54(char *a, u32 b, u16 c, u16 d, u16 e, u16 f)
{
    u32 h;
    u32 hi;
    u32 wi;
    void *buf;
    void *tmp;
    void *vram;
    int n;
    u32 off;
    u32 base;

    h = d_021726A0[*(u16 *)(a + 2)].w;
    hi = h >> 3;
    wi = (u32)d_021726A0[*(u16 *)a].w >> 3;
    tmp = func_02043678(wi, hi, 0x20, f);
    buf = func_02043678(wi, hi, 0x20, f);
    func_0216FC74(b, c, d, e, buf, *(void **)(a + 0x14));
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
