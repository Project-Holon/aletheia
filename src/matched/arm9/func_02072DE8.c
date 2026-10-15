/*
 * function: NNS_SndPlayerCreateHeap
 * address:  0x02072DE8
 * packet:   pkt_02072DE8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNSi_SndPlayerHeapDisposeCallback  0x02073710  arm
 *   gSndPlayers     0x0214E464  data
 *   NNS_SndHeapAlloc  0x0207482C  arm
 *   NNS_SndHeapCreate  0x020746E8  arm
 *   NNS_FndAppendListObject  0x020604AC  arm
 *
 * Allocate a node through NNS_SndHeapAlloc with NNSi_SndPlayerHeapDisposeCallback as its destructor,
 * seed three fields, load it from `src`, and on success link it into the
 * per-index list at gSndPlayers[idx].f0c.  Either failure returns 0.
 *
 * ARGUMENT ORDER of the allocator is (a, src + 0x14, destructor, 0, 0): the
 * image does `mov r0, r1` at 0x02072DF8 and loads the pool word into r2 at
 * 0x02072E00, so the FUNCTION POINTER is the third argument and the buffer the
 * second, not the other way round.  Swapped, the whole prologue permutes.
 *
 * The table stride is 0x24 (`mov r1, #0x24` / `mla r2, r6, r1, r2` at
 * 0x02072E50/54) with the list head at +0x0c, the same gSndPlayers layout
 * docs/notes/pkt_02073624.c.txt settled for NNSi_SndPlayerHeapDisposeCallback: the padding to 0x24
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

typedef unsigned char u8; typedef unsigned int u32; typedef signed int s32;

struct Node { u8 p00[8]; u32 f08; u32 f0c; u32 f10; u8 f14; };
struct Slot { u8 p00[0xc]; u8 f0c; u8 p0d[0x24 - 0x0d]; };

struct A;
extern void NNSi_SndPlayerHeapDisposeCallback(struct A *a);
extern struct Slot gSndPlayers[];

extern u32 NNS_SndHeapAlloc(u32 *a, u32 b, u32 c, u32 d, u32 e);
extern u32 NNS_SndHeapCreate(u32 off, u32 size);
extern void NNS_FndAppendListObject(void *list, void *node);

u32 NNS_SndPlayerCreateHeap(int idx, u32 a, void *src)
{
    struct Node *n;
    u32 r;

    n = (struct Node *)NNS_SndHeapAlloc((u32 *)a, (u32)((char *)src + 0x14), (u32)NNSi_SndPlayerHeapDisposeCallback, 0, 0);
    if (n == 0) {
        return 0;
    }
    n->f0c = 0;
    n->f10 = idx;
    n->f08 = 0;
    r = NNS_SndHeapCreate((u32)(&n->f14), (u32)src);
    if (r == 0) {
        return 0;
    }
    n->f08 = r;
    NNS_FndAppendListObject(&gSndPlayers[idx].f0c, n);
    return 1;
}
