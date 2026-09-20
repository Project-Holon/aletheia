/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_020470D0
 * address:  0x020470D0
 * packet:   pkt_020470D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * 176 bytes, 0x020470D0..0x02047180, one function, every concrete byte
 * reproduced (0 differing bytes of 176) -- the diff is empty apart from the
 * two wildcarded call fields.
 *
 * Blocked on the `label` class at two addresses, both of which are in
 * ANOTHER PACKET (the pair lives in pkt_0206A12C and above, which this lane
 * does not own):
 *
 *   +0x40  bl func_0206A0C4   the reader, called (p, &x, &y)
 *   +0x8C  bl func_0206A17C   reached only through the callback below
 *
 * Neither address is matched, parked or labelled outside this range, so both
 * sites stay wildcarded.  Nothing in this C changes when they are filed.
 *
 * Two spellings in here are worth keeping:
 *
 *  - The two "is this bit set" locals are spelled as an int initialised to 0
 *    and set to 1 in the body, NOT as `f = (x & 1) != 0`.  The boolean form
 *    makes mwcc emit a movne/moveq pair per local and loses the original's
 *    `movs r5, #0 / movs r6, r5` up front; the explicit init keeps them.
 *  - The closing callback takes func_0206A17C's RETURN value as its
 *    argument: `(*(void (**)(u32))0x020A814C)(func_0206A17C(r))`.  Spelled as
 *    a bare `(...)()` call mwcc uses r0 for the loaded pointer and blx r0;
 *    the original loads into r1 and blx r1 precisely because r0 is already
 *    holding the argument.  Passing the call's result is what forces r1.
 *
 * The three callbacks are called through globals at 0x020A8144 and
 * 0x020A814C, written as numeric casts so the pool word stays a plain
 * literal rather than a relocation.
 */

typedef unsigned int   u32;
typedef unsigned short u16;
typedef unsigned char  u8;

extern u8   *func_0206E964(u32 h);
extern void  func_0206A0C4(u8 *p, u32 *a, u32 *b);
extern u32   func_0206A17C(u8 *p);

int func_020470D0(u32 *p)
{
    u8  *r;
    int  f1;
    int  f2;
    u32  x;
    u32  y;

    r = func_0206E964(p[1]);
    f1 = 0;
    f2 = 0;
    if (*(u16 *)(r + 0x10) & 1)
        f1 = 1;
    if (*(u16 *)(r + 0x20) & 1)
        f2 = 1;
    func_0206A0C4(r, &x, &y);
    if (f1)
        (*(void (**)(u32))0x020A8144)(x);
    if (f2)
        (*(void (**)(u32))0x020A8144)(y);
    if ((*(u16 *)(r + 0x32) & 1) != 0 && *(u16 *)(r + 0x30) != 0)
        (*(void (**)(u32))0x020A814C)(func_0206A17C(r));
    return 1;
}
