/*
 * unit:     no
 * function: CLACT_CreateActorCore
 * address:  0x0204CFDC
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetFreeActor  0x0204C8E4  arm
 *   CLACT_InitAnimCtl  0x0204D0C4  arm
 *   CLACT_ApplyActorInit  0x0204CED8  arm
 *   CLACT_ApplyActorResources  0x0204CF40  arm
 *   CLACT_LinkActor  0x0204C98C  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Allocate one object out of the owner's pool, back-link it, initialise its
 * embedded sub-object at +0x68 from the request, apply the two field
 * groups, register it with the owner and enable it.
 *
 * Five of the six callees want the object pointer and two want the owner,
 * so both are pinned for the whole body; that is what forces the
 * five-callee-saved push.  The fifth argument is only read once, straight
 * out of this function's own stack slot at [sp, #0x18] (five pushed
 * registers plus lr above it), and never spilled.
 *
 * Was parked at MATCH.  Three of the six sites name functions whose only
 * branch site image-wide is the one here, so each needed its own EXACT
 * entry to act as a `matched` witness; all three now have one and the C in
 * this file is unchanged.
 *
 *   0x0204C8E4, the allocator, is src/matched/CLACT_GetFreeActor.c.  Its own
 *     blocker was the GF_ASSERT expression string, folded onto the
 *     file-name symbol
 *     (docs/idioms/an-assert-expression-string-rides-the-file-name-symbol.md).
 *   0x0204D0C4, the sub-object initialiser, is src/matched/CLACT_InitAnimCtl.c.
 *     Its handler table 0x020A13DC is row 6 of the array based at
 *     0x020A1394, not a symbol of its own.
 *   0x0204CF40 is src/matched/CLACT_ApplyActorResources.c, which unstuck once
 *     0x0204B728 landed (one `const` on a struct assignment's source).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_CreateActorCore.c \
 *       --func CLACT_CreateActorCore --addr 0x0204CFDC --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub {
    u8 unk_00[1];
};

struct Obj {
    u8          pad_00[8];
    void       *owner;
    u8          pad_0c[0x5c];
    struct Sub  unk_68;
};

struct Req {
    u8 unk_00[1];
};

struct Owner;
extern struct Obj *CLACT_GetFreeActor(struct Owner *ow);
extern void CLACT_InitAnimCtl(struct Sub *s, void *c, u32 e);
extern void CLACT_ApplyActorInit(struct Obj *o, const struct Req *r, u32 space);
extern void CLACT_ApplyActorResources(struct Obj *o, const struct Req *r);
extern void CLACT_LinkActor(void *owner, struct Obj *o);
extern void CLACT_SetActorDrawEnable(struct Obj *o, u32 enable);

struct Obj *CLACT_CreateActorCore(void *owner, const struct Req *r, void *c, u32 space, u16 e)
{
    struct Obj *o = CLACT_GetFreeActor(owner);

    o->owner = owner;
    CLACT_InitAnimCtl(&o->unk_68, c, e);
    CLACT_ApplyActorInit(o, r, space);
    CLACT_ApplyActorResources(o, c);
    CLACT_LinkActor(owner, o);
    CLACT_SetActorDrawEnable(o, 1);
    return o;
}
