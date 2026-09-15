/*
 * unit:     no
 * function: sub_0204B4EC
 * address:  0x0204B4EC
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
 *   sub_0204B560   0x0204B560  arm
 *
 * The read side of src/matched/sub_0204B49C.c: one axis of the actor's
 * position, expressed in the coordinate space named by `space`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B4EC.c \
 *       --func sub_0204B4EC --addr 0x0204B4EC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef signed short  s16;
typedef unsigned int  u32;

struct PtS {
    s16 x;
    s16 y;
};

struct Actor {
    u8 pad_00[0x0c];
    u8 pad_0c[4];
};

extern void func_0204CF74(struct Actor *actor, u32 space, struct PtS *out);
extern s16  sub_0204B560(const struct Actor *actor, u32 axis);

s16 sub_0204B4EC(struct Actor *actor, u32 space, u32 axis)
{
    struct PtS origin;
    s16        v;
    s16        o;

    func_0204CF74(actor, space, &origin);
    v = sub_0204B560(actor, axis);

    if (axis == 0) {
        o = origin.x;
    } else {
        o = origin.y;
    }

    return v - o;
}
