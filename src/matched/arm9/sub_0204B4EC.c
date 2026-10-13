/*
 * unit:     no
 * function: CLACT_GetActorSurfacePosAxis
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
 *   CLACT_GetSurfaceOrigin  0x0204CF74  arm
 *   CLACT_GetActorPosAxis   0x0204B560  arm
 *
 * The read side of src/matched/CLACT_SetActorSurfacePosAxis.c: one axis of the actor's
 * position, expressed in the coordinate space named by `space`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorSurfacePosAxis.c \
 *       --func CLACT_GetActorSurfacePosAxis --addr 0x0204B4EC --cc 1.1p1 --arm
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

struct Obj;
extern void CLACT_GetSurfaceOrigin(struct Obj *actor, unsigned int space, unsigned short *out);
extern s16  CLACT_GetActorPosAxis(const struct Actor *actor, u32 axis);

s16 CLACT_GetActorSurfacePosAxis(struct Actor *actor, u32 space, u32 axis)
{
    struct PtS origin;
    s16        v;
    s16        o;

    CLACT_GetSurfaceOrigin((struct Obj *)actor, space, (unsigned short *)&origin);
    v = CLACT_GetActorPosAxis(actor, axis);

    if (axis == 0) {
        o = origin.x;
    } else {
        o = origin.y;
    }

    return v - o;
}
