/*
 * function: func_021C6FA0
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
 *   func_0204B3DC  0x0204B3DC  arm
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
extern void func_0204B3DC(struct Obj *p, u32 v);

typedef struct {
    u8 pad0[0x98];
    void *anim[1];
} Work;

void func_021C6FA0(Work *p, int idx, u8 a, u8 b)
{
    CLACT_SetActorAnimSeq(p->anim[idx], a);
    CLACT_RestartActorAnim(p->anim[idx]);
    func_0204B3DC(p->anim[idx], b);
}
