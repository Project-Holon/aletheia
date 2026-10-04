/*
 * unit:     no
 * function: sub_0204B454
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
 *   func_0204CF74  0x0204CF74  arm
 *   sub_0204B53C   0x0204B53C  arm
 *
 * Read the actor's screen position back in the coordinate space named by
 * `space`: func_0204CF74 fills in that space's origin, src/matched/sub_0204B53C.c
 * fills in the absolute position, and the difference is written back over the
 * caller's buffer in place.
 *
 * The scratch pair is the `r3` slot of the prologue push rather than an
 * explicit `sub sp`, which is what a single four-byte local costs here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B454.c \
 *       --func sub_0204B454 --addr 0x0204B454 --cc 1.1p1 --arm
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
extern void func_0204CF74(struct Obj *actor, u32 space, u16 *out);
extern void sub_0204B53C(const struct Actor *actor, struct Pt *out);

void sub_0204B454(struct Actor *actor, struct PtS *out, u32 space)
{
    struct PtS origin;

    func_0204CF74((struct Obj *)actor, space, (u16 *)&origin);
    sub_0204B53C(actor, (struct Pt *)out);

    out->x = out->x - origin.x;
    out->y = out->y - origin.y;
}
