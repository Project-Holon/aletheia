/*
 * function: func_020642C8
 * address:  0x020642C8
 * packet:   pkt_02064178
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The eight-argument forwarder into func_02066890 (four in registers, four
 * on the stack at [sp]..[sp,#0xc], re-read from the caller's own stacked
 * arguments at [sp,#0x28]..[sp,#0x3c]), followed by the object fixups.
 *
 * Two levers, both needed, both `volatile`:
 *   1. The image stores self+0x38 TWICE, at 0x02064318 and again at
 *      0x02064328, with the self+0x34 store between them.  Written as plain
 *      assignments mwcc drops the first and the function is 128 bytes
 *      against 132, 64 concrete out.  Marking that field `volatile` is what
 *      keeps both stores.
 *   2. With only (1), the self+0x34 store sinks below the `add r0, r7, #0x3c`
 *      / `mov r1, #1` argument setup for func_02064140 (11 concrete bytes at
 *      the right size).  Marking that field `volatile` too pins it above
 *      them, matching 0x0206431C.
 * Both are plain field stores in the real source; `volatile` here is standing
 * in for whatever ordering the original had, and is the spelling that
 * reproduces the bytes.
 *
 * Byte-correct: 132 bytes, 0 concrete mismatches, under the DEFAULT 1.1p1
 * (no pin needed; ../2.0/sp2 also gives 132/0 with the same C).
 *
 * Blocked on: `label`.  Three of the four PC24 sites resolve, but func_02066890
 * has no branch anywhere in the image outside this function's own `bl` at
 * 0x02064314, and no matched entry, so the site stays wildcarded and the file
 * caps at MATCH.  It promotes as soon as 0x02066890 or a second caller of it
 * is filed.
 *
 * symbols:
 *   func_02066890  0x02066890  arm
 *   func_02064140  0x02064140  arm
 *   func_02062F38  0x02062F38  arm
 *   func_0206434C  0x0206434C  arm
 */

typedef unsigned int u32;
extern void func_02066890(u32 idx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02064140(char *p, int v);
extern void func_02062F38(char *self);
extern void func_0206434C(char *self, int v);

void func_020642C8(char *self, int a1, char *c, int d,
                   int e, int f, int g, int h, int i, int j)
{
    func_02066890(d, e, f, g, *(int *)*(int **)(c + 0xc), h, i, j);
    *(volatile int *)(self + 0x38) = d;
    *(char *volatile *)(self + 0x34) = c;
    *(volatile int *)(self + 0x38) = d;
    func_02064140(self + 0x3c, 1);
    func_02062F38(self);
    func_0206434C(self, a1);
}
