/*
 * file:     nns_snd_player_3.c
 * unit:     yes
 * function: func_02072DE8, func_02072E7C, func_02072E8C
 * address:  0x02072DE8
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02073710  0x02073710  arm
 *   g_0214E464     0x0214E464  data
 *   func_0207482C  0x0207482C  arm
 *   func_020746E8  0x020746E8  arm
 *   func_020604AC  0x020604AC  arm
 *   func_02073438  0x02073438  arm
 *   func_02073484  0x02073484  arm
 */
struct Obj_02073438;
typedef unsigned char u8; typedef unsigned int u32; typedef signed int s32;

struct Node { u8 p00[8]; u32 f08; u32 f0c; u32 f10; u8 f14; };
struct Slot { u8 p00[0xc]; u8 f0c; u8 p0d[0x24 - 0x0d]; };

struct A;
extern void func_02073710(struct A *a);
extern struct Slot g_0214E464[];

extern u32 func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_020746E8(u32 off, u32 size);
extern void func_020604AC(void *list, void *node);

/*
 * Allocate a node through func_0207482C with func_02073710 as its destructor,
 * seed three fields, load it from `src`, and on success link it into the
 * per-index list at g_0214E464[idx].f0c.  Either failure returns 0.
 *
 * ARGUMENT ORDER of the allocator is (a, src + 0x14, destructor, 0, 0): the
 * image does `mov r0, r1` at 0x02072DF8 and loads the pool word into r2 at
 * 0x02072E00, so the FUNCTION POINTER is the third argument and the buffer the
 * second, not the other way round.  Swapped, the whole prologue permutes.
 *
 * The table stride is 0x24 (`mov r1, #0x24` / `mla r2, r6, r1, r2` at
 * 0x02072E50/54) with the list head at +0x0c, the same g_0214E464 layout
 * docs/notes/pkt_02073624.c.txt settled for func_02073710: the padding to 0x24
 * has to be written out or the offset folds into the multiply.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md).  The image
 * materialises the zeros SEPARATELY -- `mov r3, #0` at 0x02072DFC for the
 * allocator's stacked fifth argument, `mov r2, #0` at 0x02072E20 for the f0c/f08
 * pair, and a fresh `moveq r0, #0` at each of the two failure exits (0x02072E18,
 * 0x02072E44) -- and keeps a bare four-register `push {r3, r4, r5, r6, lr}`
 * (`78 40 2d e9`) with an explicit `sub sp, sp, #4` / `add sp, sp, #4` frame.
 * 1.1p1 -O4,p CSEs all four into one hoisted `mov r5, #0`, which costs a fifth
 * callee-saved register (`push {r3, r4, r5, r6, r7, lr}`, idx displaced to r7),
 * lets it fold the stack adjust into the pushes, and drops the two `addeq sp`
 * instructions: 132 bytes against the original's 148, 101 concrete bytes out.
 * Under the pin the same C is 148 bytes, 0 mismatches.
 */
u32 func_02072DE8(int idx, u32 a, void *src)
{
    struct Node *n;
    u32 r;

    n = (struct Node *)func_0207482C((u32 *)a, (u32)((char *)src + 0x14), (u32)func_02073710, 0, 0);
    if (n == 0) {
        return 0;
    }
    n->f0c = 0;
    n->f10 = idx;
    n->f08 = 0;
    r = func_020746E8((u32)(&n->f14), (u32)src);
    if (r == 0) {
        return 0;
    }
    n->f08 = r;
    func_020604AC(&g_0214E464[idx].f0c, n);
    return 1;
}

extern void func_02073438(struct Obj_02073438 *p, int fadeFrame);
extern void func_02073484(void *p, unsigned char v);
void func_02072E7C(void **r0, int fadeFrame);
void func_02072E8C(void **r0, unsigned char v);


/*
 * HEADER CORRECTED 2026-09-21 (pkt_02072DE8 lane), C unchanged.  The block read
 * `compiler: 1.1p1` / `status: EXACT`, and was neither: under the DEFAULT 1.1p1
 * this source is DIFF at the same 16 bytes (the pool-load-order difference
 * docs/FRONTEND-PINS.md already records for this pair), and under the
 * ../2.0/sp2 pin that same table row names for it, it is MATCH, not EXACT.
 * Both fields now say what match.py actually prints.
 *
 * Blocked at MATCH, evidence class: none available for the sole ABS32 site at
 * +0x0C.  The tail-call target func_02073438 is named by exactly one pool word
 * anywhere in the image -- this function's own, at 0x02072E88 -- so `literal`
 * has no outside witness, `label` does not apply to a pool word, and no
 * `matched` entry covers the address.  A split cannot help: the function is
 * three instructions and the pool word is one of them.
 */
void func_02072E7C(void **r0, int fadeFrame)
{
    func_02073438(*r0, fadeFrame);
}


/*
 * HEADER CORRECTED 2026-09-21 (pkt_02072DE8 lane), C unchanged.  The block read
 * `compiler: 1.1p1` / `status: EXACT`, and was neither: under the DEFAULT 1.1p1
 * this source is DIFF at the same 16 bytes (the pool-load-order difference
 * docs/FRONTEND-PINS.md already records for this pair), and under the
 * ../2.0/sp2 pin that same table row names for it, it is MATCH, not EXACT.
 * Both fields now say what match.py actually prints.
 *
 * Blocked at MATCH, evidence class: none available for the sole ABS32 site at
 * +0x0C.  The tail-call target func_02073484 is named by exactly one pool word
 * anywhere in the image -- this function's own, at 0x02072E98 -- so `literal`
 * has no outside witness, `label` does not apply to a pool word, and no
 * `matched` entry covers the address.  A split cannot help: the function is
 * three instructions and the pool word is one of them.
 */
void func_02072E8C(void **r0, unsigned char v)
{
    func_02073484(*r0, v);
}
