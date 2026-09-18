/*
 * function: func_02047CE4
 * address:  0x02047CE4
 * packet:   pkt_020479D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A5C  0x02146A5C  data
 *
 * An unlabelled ARM leaf that follows func_02047C8C's pool word: it clears
 * the two counters at +4 and +8 of the global at 0x02146A5C (the same global
 * func_02046A94 indexes through, whose first word is the context pointer).
 * One `mov r1, #0` feeds both stores.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047CE4.c \
 *       --func func_02047CE4 --addr 0x02047CE4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct G02146A5C {
    void *obj;          /* +0x00 */
    u32   f4;           /* +0x04 */
    u32   f8;           /* +0x08 */
};

extern struct G02146A5C g_02146A5C;

void func_02047CE4(void)
{
    g_02146A5C.f4 = 0;
    g_02146A5C.f8 = 0;
}
