/*
 * function: func_0206B6A4
 * address:  0x0206B6A4
 * packet:   pkt_0206AF08
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_02148DB0      0x02148DB0  data
 *   func_02082A7C   0x02082A7C  arm
 *   func_0206B63C   0x0206B63C  arm
 *   func_0206B4A0   0x0206B4A0  arm
 *
 * Promote-first callee of src/pending/func_02047C8C.c (parks lane 2).
 * Release the object's three eight-byte sub-blocks when the +0x10 flag is
 * up, then run the one-at-a-time teardown through the stash pointer at
 * 0x02148DB0, recording this frame's own work area in it while the call is
 * in flight.
 *
 * Blocked at MATCH with all 220 concrete bytes right: five unresolved sites,
 * three calls to 0x0206B63C and two to 0x0206B4A0, each of which has no
 * witness outside 0x0206B6A4..0x0206B780 - the only branches in the image to
 * either address are these calls.  Filing 0x0206B63C (104 B) and 0x0206B4A0
 * (400 B) as EXACT entries promotes this file and then
 * src/pending/func_02047C8C.c with no change to the C.  (0x0206B63C's own
 * `cmp r1, #0 / popeq` prologue confirms the two-argument call below.)
 *
 * Shape notes, each measured:
 *   - the 2.0 front end: dsi/1.1p1 gives 224 bytes and 1.2 228 for the same
 *     C; 2.0/sp2 gives the original's 220;
 *   - `if (g != 0) {...} else {...}` in that order (the original's `beq`
 *     jumps into the stash arm, and the fall-through arm is the source order);
 *   - the three cleanup calls take TWO arguments, `(block, p->f08)`: the
 *     guard's loaded value is still sitting in r1 at the call and the
 *     original never reloads it.  Passing one argument costs six bytes here
 *     (`ldr r0,[r4,#8] / cmp r0,#0` against the original's r1).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206B6A4.c \
 *       --func func_0206B6A4 --addr 0x0206B6A4 --cc ../2.0/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj0206B6A4 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
};

extern u32 g_02148DB0;

extern void func_02082A7C(u32 val, void *dst, u32 len);
extern void func_0206B63C(void *p, u32 v);
extern void func_0206B4A0(void *a, void *b);

void func_0206B6A4(struct Obj0206B6A4 *p)
{
    u8 work[0x188];

    if ((p->f00 & 0x10) == 0x10) {
        func_02082A7C(0, (char *)p + 0x3c, 8);
        func_02082A7C(0, (char *)p + 0x44, 8);
        func_02082A7C(0, (char *)p + 0x4c, 8);
        if (p->f08 != 0)
            func_0206B63C((char *)p + 0x3c, p->f08);
        if (p->f10 != 0)
            func_0206B63C((char *)p + 0x44, p->f10);
        if (p->f18 != 0)
            func_0206B63C((char *)p + 0x4c, p->f18);
        p->f00 &= ~0x10;
    }
    if (g_02148DB0 != 0) {
        func_0206B4A0((void *)g_02148DB0, p);
    } else {
        g_02148DB0 = (u32)work;
        func_0206B4A0(work, p);
        g_02148DB0 = 0;
    }
}
