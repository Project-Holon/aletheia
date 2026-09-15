/*
 * function: func_0204BC94
 * address:  0x0204BC94
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Blocked at MATCH: all 68 concrete bytes are correct and the call to
 * func_02063078 resolves off the second call site in
 * src/matched/func_0204BCD8.c, but the two PC24 sites at +0x0028 and +0x003C
 * (the calls to func_0204BD3C) have no witness outside this range: those two
 * calls are the only branch references to 0x0204BD3C image wide.  No cut frees
 * them, and src/pending/func_0204BD3C.c cannot supply a `matched` entry
 * because it is itself capped at MATCH by func_02063138, a fan-in-1 extern.
 *
 * symbols:
 *   func_02063078  0x02063078  arm
 *   func_0204BD3C  0x0204BD3C  arm
 *
 * Bind both of a cell actor's 0x20-byte OAM sub-records to their hardware
 * spans: flush first, then the low record with span (base, count) and
 * selector 0, then the high record with (base2, count2) and selector 1.
 *
 * The fifth parameter is a u8: it arrives on the caller's stack and is read
 * back with `ldrb r2, [sp, #0x18]` past the six-register push, while the
 * third parameter reaches the same argument slot as a plain `mov`.  Widening
 * it to u32 would drop the `ldrb` to an `ldr`.
 *
 * The second sub-record is reached with `add r0, r7, #0x20`, the constant
 * subscript &o->w[1], not a running cursor.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204BC94.c \
 *       --func func_0204BC94 --addr 0x0204BC94 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u8  pad_00[0x1c];
    u32 bound;   /* 0x1c */
};

struct Obj {
    struct Sub w[2];
};

extern void func_02063078(void);
extern void func_0204BD3C(struct Sub *s, u32 base, u32 count, u32 which);

void func_0204BC94(struct Obj *o, u32 base, u32 count, u32 base2, u8 count2)
{
    func_02063078();
    func_0204BD3C(&o->w[0], base, count, 0);
    func_0204BD3C(&o->w[1], base2, count2, 1);
}
