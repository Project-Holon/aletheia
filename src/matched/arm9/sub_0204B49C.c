/*
 * function: sub_0204B49C
 * address:  0x0204B49C
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204CF74  0x0204CF74  arm
 *   sub_0204B550   0x0204B550  arm
 *
 * The write side of src/matched/sub_0204B4EC.c: set one axis of the actor's
 * position, given in the coordinate space named by `space`.
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 76/80 for four waves,
 * docs/notes/sub_0204B49C.c.txt): the origin is added to the s16 parameter
 * by COMPOUND assignment in each arm, `value += origin.x;`. The image keeps
 * the narrowed sum in the parameter's home register r6 and copies it into r1
 * for the call; `value = value + origin.x` (or a fresh local, or one
 * expression) lets 1.1p1 narrow straight into r1 and elide the copy, four
 * bytes short.
 */

typedef unsigned char u8;
typedef signed short  s16;
typedef unsigned int  u32;
struct PtS { s16 x; s16 y; };
struct Actor { u8 pad_00[0x10]; };
struct Obj;
extern void func_0204CF74(struct Obj *actor, u32 space, unsigned short *out);
extern void sub_0204B550(struct Actor *actor, s16 value, u32 axis);

void sub_0204B49C(struct Actor *actor, s16 value, u32 space, u32 axis)
{
    struct PtS origin;

    func_0204CF74((struct Obj *)actor, space, (unsigned short *)&origin);

    if (axis == 0) {
        value += origin.x;
    } else {
        value += origin.y;
    }

    sub_0204B550(actor, value, axis);
}
