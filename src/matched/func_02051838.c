/*
 * function: func_02051838
 * address:  0x02051838
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The three-word vector at the object's +0x28..+0x30 is rebuilt from the
 * caller's three words at q[0..2] plus the three inner words at the block the
 * object's own pointer field at +0x20 names.  Frame is 8 bytes: push {r4, lr}
 * and no stack slots.
 *
 * The inner pointer is re-read from p+0x20 before each of the three sums
 * (`ldr r1, [lr]` three times in the original), so the source spells the
 * dereference out per statement rather than binding it to a local; binding it
 * to one local compiles the block in twelve fewer bytes with everything in
 * different registers.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051838.c \
 *       --func func_02051838 --addr 0x02051838 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct S51838 {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 w12;
};

void func_02051838(char *p, u32 *q)
{
    *(u32 *)(p + 0x28) = q[0] + *(u32 *)(*(u32 *)(p + 0x20) + 4);
    *(u32 *)(p + 0x2c) = q[1] + *(u32 *)(*(u32 *)(p + 0x20) + 8);
    *(u32 *)(p + 0x30) = q[2] + *(u32 *)(*(u32 *)(p + 0x20) + 12);
}
