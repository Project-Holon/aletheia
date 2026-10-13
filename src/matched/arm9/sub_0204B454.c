/*
 * unit:     no
 * function: CLACT_GetActorSurfacePos
 * address:  0x0204B454
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetSurfaceOrigin  0x0204CF74  arm
 *   CLACT_GetActorPos   0x0204B53C  arm
 *
 * Read the actor's screen position back in the coordinate space named by
 * `space`: CLACT_GetSurfaceOrigin fills in that space's origin, src/matched/CLACT_GetActorPos.c
 * fills in the absolute position, and the difference is written back over the
 * caller's buffer in place.
 *
 * The scratch pair is the `r3` slot of the prologue push rather than an
 * explicit `sub sp`, which is what a single four-byte local costs here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorSurfacePos.c \
 *       --func CLACT_GetActorSurfacePos --addr 0x0204B454 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Pt {
    u16 x;
    u16 y;
};

struct PtS {
    s16 x;
    s16 y;
};

struct Actor {
    u8        pad_00[0x0c];
    struct Pt pos;
};

struct Obj;
extern void CLACT_GetSurfaceOrigin(struct Obj *actor, u32 space, u16 *out);
extern void CLACT_GetActorPos(const struct Actor *actor, struct Pt *out);

void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space)
{
    struct PtS origin;

    CLACT_GetSurfaceOrigin((struct Obj *)actor, space, (u16 *)&origin);
    CLACT_GetActorPos(actor, (struct Pt *)out);

    out->x = out->x - origin.x;
    out->y = out->y - origin.y;
}
