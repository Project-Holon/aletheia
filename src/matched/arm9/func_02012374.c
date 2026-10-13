/*
 * unit:     no
 * function: GAME_EVENT_CallEvent
 * address:  0x02012374
 * packet:   pkt_02012304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_SetEvent  0x02012108  thumb
 *
 * Publish the object through the caller's out parameter and tail-call the
 * setter on its +0x10 member, which stores `out` (still in r1) as that
 * context's current event at +0x18.  Eight bytes of code and the pool word the
 * tail call needs (docs/idioms/tail-call-is-a-pool-word-and-bx.md); the
 * pool word carries the Thumb bit, so the target is Thumb code and the
 * transfer is a plain `bx`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_CallEvent.c \
 *       --func GAME_EVENT_CallEvent --addr 0x02012374 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Evt {
    u8    pad_00[0x10];
    void *unk_10;
};

struct Ctx;
extern void GAMESYSTEM_SetEvent(struct Ctx *p, u32 v);

void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out)
{
    *out = evt;
    GAMESYSTEM_SetEvent(evt->unk_10, (u32)out);
}
