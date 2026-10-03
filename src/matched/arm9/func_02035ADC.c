/*
 * function: func_02035ADC
 * address:  0x02035ADC
 * packet:   pkt_02035ADC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035A70  0x02035A70  arm
 *   func_02035AA4  0x02035AA4  arm
 *
 * The hit-test table walk of the touchpanel.c family.  It scans an array of
 * four-byte records for the first one the point (x, y) falls inside, and
 * returns that record's index, or -1 when the table runs out.  Byte 0 of a
 * record is the shape tag: 0xFF ends the table, 0xFD skips the entry, 0xFE
 * selects the circle test at func_02035A70 and anything else the rectangle
 * test at func_02035AA4.
 *
 * THE DECLARATION IS THE WHOLE FUNCTION.  Written with a `u8 *` parameter
 * and the record address spelled `p + i * 4` (any of: a `rec` local at any
 * scope, `&p[i*4]`, a `u32 *` base with a cast, or the expression written
 * out at each call site), the body compiles to a 21-byte residue in the head
 * that no amount of statement shuffling moves.  The original computes the
 * record address with `add r0, r7, r4, lsl #2` AFTER both argument moves,
 * keeping the tag byte in r0 across the two compares; every pointer-arithmetic
 * spelling hoists the address above the compares instead, which pushes the
 * tag into r1 and rotates the rest.
 *
 * Declaring the record as a struct and indexing the array (`p[i].t`, with
 * `&p[i]` cast for the calls) is what reproduces it: the address becomes an
 * addressing-mode computation the scheduler is free to sink below the
 * compares rather than a value that has to be live across them.  This is the
 * "residue the permuter cannot move at all is usually in the declarations"
 * case: tools/permuter.py plateaus at 8 bytes out from every pointer-spelled
 * start (its best single mutation, `temp(tmp=p + (i * 4))`, is a loop-invariant
 * hoist that is not value-preserving here), and the struct declaration is
 * EXACT with no mutation at all.
 *
 * Supersedes the near miss recorded in docs/notes/pkt_02035ADC.c.txt, which
 * tried four pointer spellings and reached the same 21-byte head.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035ADC.c \
 *       --func func_02035ADC --addr 0x02035ADC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct R {
    u8 t;
    u8 a;
    u8 b;
    u8 c;
};

typedef signed int     s32;
extern u32 func_02035A70(u8 *p, s32 x, s32 y);
extern u32 func_02035AA4(u8 *p, u32 x, u32 y);

int func_02035ADC(struct R *p, u32 x, u32 y)
{
    int i = 0;

    while (p[i].t != 0xff) {
        if (p[i].t != 0xfd) {
            if (p[i].t == 0xfe) {
                if (func_02035A70((u8 *)&p[i], x, y) != 0) {
                    return i;
                }
            } else {
                if (func_02035AA4((u8 *)&p[i], x, y) != 0) {
                    return i;
                }
            }
        }
        i++;
    }
    return -1;
}
