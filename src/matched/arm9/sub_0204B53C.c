/*
 * unit:     no
 * function: CLACT_GetActorPos
 * address:  0x0204B53C
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The read side of src/matched/CLACT_SetActorPos.c: copy the actor's screen
 * position pair out of +0x0c/+0x0e, field by field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorPos.c \
 *       --func CLACT_GetActorPos --addr 0x0204B53C --cc 1.1p1 --arm
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

void CLACT_GetActorPos(const struct Actor *actor, struct Pt *out)
{
    out->x = actor->pos.x;
    out->y = actor->pos.y;
}
