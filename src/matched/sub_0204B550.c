/*
 * unit:     no
 * function: sub_0204B550
 * address:  0x0204B550
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Write one axis of the actor's screen position: axis 0 is x at +0x0c, any
 * other value is y at +0x0e.  Both arms are a single store, so the compiler
 * if-converts the whole body to `strheq`/`strhne` and the function has no
 * branch at all.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B550.c \
 *       --func sub_0204B550 --addr 0x0204B550 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Pt {
    u16 x;
    u16 y;
};

struct Actor {
    u8        pad_00[0x0c];
    struct Pt pos;
};

void sub_0204B550(struct Actor *actor, u16 value, u32 axis)
{
    if (axis == 0) {
        actor->pos.x = value;
    } else {
        actor->pos.y = value;
    }
}
