/*
 * function: func_0204B324
 * address:  0x0204B324
 * packet:   pkt_0204B324
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   CLACT_InitActorRequest   0x0204CFA4  arm
 *   CLACT_CreateActorFull  0x0204D048  arm
 *
 * Same request-builder shape as CLACT_CreateActor: a 0x20-byte request is staged
 * on the stack from three of the singleton's parallel tables (0x40-byte
 * records at +0x10c, 0x18-byte records at +0x110, 0x14-byte records at
 * +0x114), then dispatched by CLACT_CreateActorFull, which is CLACT_CreateActorCore's
 * five-argument sibling.
 *
 * The last two arguments come back off the caller's own stack with `ldrh`,
 * which is what names those two u16; the fifth arrives with a plain `ldr`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204B324.c \
 *       --func func_0204B324 --addr 0x0204B324 --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RecC {
    u8 pad_00[0x40];
};

struct RecA {
    u8 pad_00[0x18];
};

struct RecB {
    u8  pad_00[8];
    u32 unk_08;
    u32 unk_0c;
    u8  pad_10[4];
};

struct Request {
    u8 b[0x20];
};

extern struct Mgr *g_ClactSystem;

struct Req;
extern void CLACT_InitActorRequest(struct Req *r, u16 a, u16 b, u32 c, u32 d, u32 e, u32 f);
struct Obj;
struct Req;
extern struct Obj *CLACT_CreateActorFull(void *owner, const struct Req *position,
                                void *request, u32 space, u16 heap);

struct Obj *func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g)
{
    struct Request req;

    CLACT_InitActorRequest((struct Req *)(&req), i, j, (u32)(&((struct RecC *)g_ClactSystem->owner_slots)[i]), (u32)(&g_ClactSystem->owner_slots2[j]),
                 g_ClactSystem->tb[k].unk_08, g_ClactSystem->tb[k].unk_0c);
    return CLACT_CreateActorFull((void *)owner, (const struct Req *)e, &req, f, g);
}
