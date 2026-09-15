/*
 * unit:     no
 * function: sub_0204B53C
 * address:  0x0204B53C
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The read side of src/matched/sub_0204B528.c: copy the actor's screen
 * position pair out of +0x0c/+0x0e, field by field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B53C.c \
 *       --func sub_0204B53C --addr 0x0204B53C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Pt {
    u16 x;
    u16 y;
};

struct Actor {
    u8        pad_00[0x0c];
    struct Pt pos;
};

void sub_0204B53C(const struct Actor *actor, struct Pt *out)
{
    out->x = actor->pos.x;
    out->y = actor->pos.y;
}
