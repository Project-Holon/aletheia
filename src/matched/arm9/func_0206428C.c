/*
 * function: func_0206428C
 * address:  0x0206428C
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Binds one cell-bank row to an animation object: stores the row pointer at
 * +0x34, writes the "no cell bound" sentinel -1 at +0x38, opens the SRT block
 * at +0x3c through NNSi_G2dSrtcInitControl and finishes with the object's own two-call
 * tail.  The sibling of func_020642C8, which does the same fixups after an
 * eight-argument forward.
 *
 * PIN ../2.0/sp2: the "kept constants" tell in its allocation form.  The image
 * materialises the sentinel into r2 and stores it SECOND, between the +0x34
 * store and the `add r0, r5, #0x3c` argument setup -- `str r2,[r5,#0x34]` at
 * 0x02064298 / `mvn r2,#0` at 0x0206429C / `add r0,r5,#0x3c` / `mov r1,#1` /
 * `str r2,[r5,#0x38]` at 0x020642A8.  1.1p1 -O4,p allocates the -1 into r3
 * instead and sinks its store below the whole argument setup, giving
 * `mvn r3,#0` / `add r0,r5,#0x3c` / `mov r1,#1` / `str r2,[r5,#0x34]` /
 * `str r3,[r5,#0x38]`: the same 60 bytes, 17 concrete out.  An earlier lane
 * measured `0xffffffffu`, `(u32)-1` and a named `u32` local for the sentinel
 * and every one allocates r3 the same way (docs/notes/pkt_02064178.c.txt).
 * Under the pin this SAME C is 60 bytes, 0 mismatches, all three sites label.
 *
 * symbols:
 *   NNSi_G2dSrtcInitControl  0x02064140  arm
 *   func_02062F38  0x02062F38  arm
 *   func_0206434C  0x0206434C  arm
 */
#include "../include/Obj11539.h"
typedef unsigned int   u32;
struct O02064140;
extern void NNSi_G2dSrtcInitControl(struct O02064140 *o, u32 a);
extern int func_02062F38(int a0);
extern void func_0206434C(char *self, int v);

void func_0206428C(char *self, int a1, char *c)
{
    *(char * *)&((struct Obj11539 *)self)->f34 = c;
    ((struct Obj11539 *)self)->f38 = -1;
    NNSi_G2dSrtcInitControl((struct O02064140 *)(self + 0x3c), 1);
    func_02062F38((int)self);
    func_0206434C(self, a1);
}
