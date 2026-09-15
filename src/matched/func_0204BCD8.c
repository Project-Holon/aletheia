/*
 * function: func_0204BCD8
 * address:  0x0204BCD8
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204BD18  0x0204BD18  arm
 *   func_0204BCF4  0x0204BCF4  arm
 *   func_02063078  0x02063078  arm
 *
 * Release both of a cell actor's 0x20-byte OAM sub-records and then flush the
 * hardware tables.  The pair-wise loops live in func_0204BD18 and
 * func_0204BCF4; this is only the ordering.
 *
 * The actor pointer is saved in r4 across the first call and restored for the
 * second; the third call takes no argument at all, so r0 still carries
 * func_0204BCF4's return value when it is made.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BCD8.c \
 *       --func func_0204BCD8 --addr 0x0204BCD8 --cc 1.1p1 --arm
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

extern void func_0204BD18(struct Obj *o);
extern void func_0204BCF4(struct Obj *o);
extern void func_02063078(void);

void func_0204BCD8(struct Obj *o)
{
    func_0204BD18(o);
    func_0204BCF4(o);
    func_02063078();
}
