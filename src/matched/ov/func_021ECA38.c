/*
 * function: BOX2_SEQ_ResetActorTransform
 * address:  0x021ECA38
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorAffineMode  0x0204B570  arm  arm9
 *   CLACT_SetActorAffineOrigin  0x0204B588  arm  arm9
 *   CLACT_SetActorScale  0x0204B5AC  arm  arm9
 *
 * Program the two 0x1000 spans of the frame handle and zero its head.
 *
 * Blocker resolved: 0x0204B5AC was matched in arm9 (src/matched/
 * CLACT_SetActorScale.c, shard pkt_0204B5AC), so the call at +0022 attests as
 * `matched`.  Every concrete byte matches; the extent ran long because the
 * follower has no func_ label.
 */

typedef unsigned int   u32;
struct Actor;
struct Pt;
extern void CLACT_SetActorAffineOrigin(struct Actor *actor, const struct Pt *src);
struct Obj;
struct Pair;
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
void BOX2_SEQ_ResetActorTransform(int *p)
{
    struct { unsigned short a[2]; int b[2]; } s;
    s.a[0] = 0;
    s.a[1] = 0;
    CLACT_SetActorAffineOrigin((struct Actor *)(*p), (const struct Pt *)s.a);
    s.b[0] = 0x1000;
    s.b[1] = 0x1000;
    CLACT_SetActorScale((struct Obj *)(*p), (struct Pair *)s.b);
    CLACT_SetActorAffineMode((struct Actor *)(*p), 0);
}
