/*
 * function: SND_GetPlayerStatus
 * address:  0x0208A054
 * packet:   pkt_0208A054
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A 40-byte accessor over the singleton whose pointer lives at g_02152FA0.
 * It hands the object's +4 field ADDRESS, together with a size of 4, to
 * func_020862B8, then RE-READS the singleton pointer and returns the +4 word
 * that call has just filled in.
 *
 * The re-read is load-bearing and is what keeps the base pointer in the
 * callee-saved r4: the image loads g_02152FA0's word once into r4 before the
 * call and dereferences r4 again afterwards (`ldr r0, [r4]` at 0x0208A06C),
 * rather than caching the object pointer itself.  Written as one cached
 * object pointer the second `ldr r0, [r4]` disappears.
 *
 * This is the second of the two callees that unblock
 * src/pending/func_020731E0.c: the `bl` at 0x020731E4 inside that file is
 * the only branch to this address anywhere in the image, so `label` cannot
 * attest it from there and only a `matched` entry here can.
 *
 * symbols:
 *   func_020862B8  0x020862B8  arm
 *   g_02152FA0     0x02152FA0  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SND_GetPlayerStatus.c \
 *       --func SND_GetPlayerStatus --addr 0x0208A054 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj {
    u32 f00;
    u32 f04;
};

extern struct Obj *g_02152FA0;
extern void func_020862B8(void *p, u32 n);

u32 SND_GetPlayerStatus(void)
{
    func_020862B8(&g_02152FA0->f04, 4);
    return g_02152FA0->f04;
}
