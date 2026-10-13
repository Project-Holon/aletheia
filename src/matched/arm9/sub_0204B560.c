/*
 * unit:     no
 * function: CLACT_GetActorPosAxis
 * address:  0x0204B560
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The read side of src/matched/CLACT_SetActorPosAxis.c: one axis of the actor's screen
 * position, axis 0 being x at +0x0c.  Both arms are a single load, so the body
 * if-converts to `ldrsheq`/`ldrshne`.
 *
 * The `ldrsh` is the signedness tell
 * (docs/idioms/ldrsh-register-offset-is-signedness.md, here in its
 * immediate-offset form): the stored field itself is u16, since
 * src/matched/CLACT_GetActorPos.c reads the same two halfwords with plain `ldrh`,
 * so the sign extension belongs to this function's s16 return type and not to
 * the struct.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorPosAxis.c \
 *       --func CLACT_GetActorPosAxis --addr 0x0204B560 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Pt {
    u16 x;
    u16 y;
};

struct Actor {
    u8        pad_00[0x0c];
    struct Pt pos;
};

s16 CLACT_GetActorPosAxis(const struct Actor *actor, u32 axis)
{
    if (axis == 0) {
        return actor->pos.x;
    } else {
        return actor->pos.y;
    }
}
