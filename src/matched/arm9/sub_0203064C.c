/*
 * unit:     no
 * function: GFL_HEAP_CreateChildHeap
 * address:  0x0203064C
 * packet:   pkt_02030608
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Previously capped at MATCH: nothing outside this range branches to
 * 0x0202FDC4, so the PC24 at +0x0C had no witness of any class and no cut
 * reached it.  src/matched/GFL_HEAP_CreateChildHeapImpl.c now reproduces that function's own
 * byte range, so the site resolves `matched` and this file is EXACT with the
 * C unchanged.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeapImpl  0x0202FDC4  arm
 *   sub_02030524  0x02030524  arm
 *   GFL_HEAP_FatalError  0x020306A0  arm
 *
 * Guard, then forward.  If the test at 0x0202FDC4 says the pair is already
 * accounted for the function returns without doing anything; otherwise the
 * work is handed to 0x020306A0 with a fresh object from 0x02030524 in front
 * of the two parameters.
 *
 * The result of 0x02030524 is spelled inline as the first argument rather
 * than bound to a local: the original sets r1 and r2 after the call, from
 * the two callee-saved copies of the parameters, and never touches r0, which
 * is what an unnamed call result in argument position looks like
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_CreateChildHeap.c \
 *       --func GFL_HEAP_CreateChildHeap --addr 0x0203064C --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern int   GFL_HEAP_CreateChildHeapImpl(u32 a, u32 b, u32 c);
extern u16   sub_02030524(void);
extern void  GFL_HEAP_FatalError(void *obj, void *a, u32 b);

void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c)
{
    if (GFL_HEAP_CreateChildHeapImpl(a, b, c) != 0) {
        return;
    }
    GFL_HEAP_FatalError((void *)sub_02030524(), (void *)a, b);
}
