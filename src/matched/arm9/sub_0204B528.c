/*
 * unit:     no
 * function: CLACT_SetActorPos
 * address:  0x0204B528
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Store the actor's screen position pair at +0x0c/+0x0e.  Copied field by
 * field rather than as a four-byte aggregate: a struct assignment of this
 * size would be one `ldr`/`str` pair
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), and the original spells
 * out two halfword moves instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorPos.c \
 *       --func CLACT_SetActorPos --addr 0x0204B528 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct Pt {
    u16 x;
    u16 y;
};

struct Actor {
    u8        pad_00[0x0c];
    struct Pt pos;
};

void CLACT_SetActorPos(struct Actor *actor, const struct Pt *src)
{
    actor->pos.x = src->x;
    actor->pos.y = src->y;
}
