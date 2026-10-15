/*
 * function: VIEWER_TEXT_SetActorAnim
 * address:  0x021C6FA0
 * packet:   pkt_ov111_021C6FA0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

typedef struct {
    u8 pad0[0x98];
    void *anim[1];
} Work;

void VIEWER_TEXT_SetActorAnim(Work *p, int idx, u8 a, u8 b)
{
    CLACT_SetActorAnimSeq(p->anim[idx], a);
    CLACT_RestartActorAnim(p->anim[idx]);
    CLACT_SetActorDrawEnable(p->anim[idx], b);
}
