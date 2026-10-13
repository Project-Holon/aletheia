/*
 * function: sub_02030678
 * address:  0x02030678
 * packet:   pkt_02030608
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_RegisterBlockHeapImpl  0x0202FE68  arm
 *   sub_02030524  0x02030524  arm
 *   sub_020306A0  0x020306A0  arm
 *
 * The same guard-then-forward shape as sub_0203064C beside it, over the other
 * binder: if 0x0202FE68 already accounted for the pair the function returns,
 * otherwise the work goes to 0x020306A0 with a fresh object in front of it.
 * Here the middle argument is a constant zero rather than a forwarded
 * parameter, and only the third parameter survives the call, which is why it
 * is the one copied into r4.
 *
 * The result of 0x02030524 is spelled inline as the first argument rather
 * than bound to a local: r1 and r2 are set after the call and r0 is never
 * touched
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030678.c \
 *       --func sub_02030678 --addr 0x02030678 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern int   GFL_HEAP_RegisterBlockHeapImpl(void *a, u32 b, u32 c);
typedef unsigned short u16;
extern u16 sub_02030524(void);
extern void  sub_020306A0(void *obj, void *a, u32 b);

void sub_02030678(void *a, u32 b, u32 c)
{
    if (GFL_HEAP_RegisterBlockHeapImpl(a, b, c) != 0) {
        return;
    }
    sub_020306A0((void *)sub_02030524(), 0, c);
}
