/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x020271F8
 * packet:   pkt_020271F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GAME_BEACON_SetPokeGet, GAME_BEACON_WritePokeGet, GAME_BEACON_SetSpecialPokeGet, GAME_BEACON_WriteSpecialPokeGet,
 *           GAME_BEACON_SetPokeLevelUp, GAME_BEACON_WritePokeLevelUp, GAME_BEACON_SetPokeEvolution, GAME_BEACON_WritePokeEvolution,
 *           GAME_BEACON_SetPlayTime, GAME_BEACON_WritePlayTime, GAME_BEACON_SetItemUse, GAME_BEACON_WriteItemUse
 *
 * symbols:
 *   GAME_BEACON_Work        0x02146940  data
 *   GAME_BEACON_CheckActionPriority    0x02027060  thumb
 *   GAME_BEACON_RequestSend    0x02026FB8  thumb
 *   GAME_BEACON_CopyStrbufCodes   0x020270AC  thumb
 *   GAME_BEACON_ResetDetails   0x0202744C  thumb
 *
 * Six checker/trampoline pairs, one per numeric event id (0xe, 0xf, 0x10,
 * 0x11, 0x14, 0x23), all working the same event-queue object obtained as
 * `GAME_BEACON_Work + 4`. Every checker has the same shape: ask
 * `GAME_BEACON_CheckActionPriority(id)` (a priority gate against the object's current mode,
 * not itself in this packet) whether the id is allowed to run right now,
 * and if so, forward the caller's argument(s) into the queue object
 * through the matching trampoline and then hand the queue object to
 * `GAME_BEACON_RequestSend` (the dispatcher, also outside this packet). The queue
 * object is re-read from `GAME_BEACON_Work` between the trampoline call and the
 * dispatch call rather than kept in a register, because the compiler
 * cannot see across those two calls that the global does not change: this
 * is only reproduced by declaring `GAME_BEACON_Work` `volatile`, which is exactly
 * the case docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md
 * records.
 *
 * The trampolines write the event id to +0x30 of the queue object and, in
 * four of the six (0xe, 0xf, 0x14, 0x23), a single 16-bit argument to
 * +0x32 or +0x34 before tail-calling the shared `GAME_BEACON_ResetDetails`, which
 * marks the object "pending" independently of which id was just set. The
 * 0x10 trampoline instead tail-calls `GAME_BEACON_CopyStrbufCodes(value, dst+0x34)`
 * directly, skipping `GAME_BEACON_ResetDetails`; GAME_BEACON_SetPokeEvolution/GAME_BEACON_WritePokeEvolution (id 0x11)
 * takes two arguments and does both: it stores the first at +0x32,
 * forwards the second to `GAME_BEACON_CopyStrbufCodes(b, dst+0x34)`, and then also
 * calls `GAME_BEACON_ResetDetails`. `GAME_BEACON_CopyStrbufCodes` and `GAME_BEACON_RequestSend` are themselves
 * open in this packet's neighbour pkt_02026250, so they are left as
 * unresolved externs here and attest through the whole-image `label`
 * class, since both are called from more places than just this unit.
 *
 * All twelve functions, 356 bytes, one contiguous run with no gap: the
 * trampoline of one pair ends exactly where the checker of the next
 * begins. 31 of 31 relocations resolve (`local` for the intra-file calls,
 * `label` for GAME_BEACON_CheckActionPriority/GAME_BEACON_RequestSend/GAME_BEACON_CopyStrbufCodes/GAME_BEACON_ResetDetails, and
 * `literal` for GAME_BEACON_Work, which is loaded from the pool at least 26 times
 * elsewhere in the ARM9 image).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020271F8.c \
 *       --addr 0x020271F8 --thumb
 */
#include "../include/Obj00121.h"
#include "../include/Obj17252.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 id);
extern void * const volatile GAME_BEACON_Work;
extern void GAME_BEACON_RequestSend(void *queue);
extern void GAME_BEACON_CopyStrbufCodes(void *vec, u16 *dest);
extern void GAME_BEACON_ResetDetails(void *dst);

static void GAME_BEACON_WritePokeGet(void *dst, u16 value);

void GAME_BEACON_SetPokeGet(u16 value)
{
    if (GAME_BEACON_CheckActionPriority(0xe)) {
        void *queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_WritePokeGet(queue, value);
        queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_RequestSend(queue);
    }
}

static void GAME_BEACON_WritePokeGet(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0xe;
    ((struct Obj00121 *)dst)->f32 = value;
    GAME_BEACON_ResetDetails(dst);
}

static void GAME_BEACON_WriteSpecialPokeGet(void *dst, u16 value);

void GAME_BEACON_SetSpecialPokeGet(u16 value)
{
    if (GAME_BEACON_CheckActionPriority(0xf)) {
        void *queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_WriteSpecialPokeGet(queue, value);
        queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_RequestSend(queue);
    }
}

static void GAME_BEACON_WriteSpecialPokeGet(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0xf;
    ((struct Obj00121 *)dst)->f32 = value;
    GAME_BEACON_ResetDetails(dst);
}

static void GAME_BEACON_WritePokeLevelUp(void *dst, u16 value);

void GAME_BEACON_SetPokeLevelUp(u16 value)
{
    if (GAME_BEACON_CheckActionPriority(0x10)) {
        void *queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_WritePokeLevelUp(queue, value);
        queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_RequestSend(queue);
    }
}

static void GAME_BEACON_WritePokeLevelUp(void *dst, u16 value)
{
    ((struct Obj17252 *)dst)->f30 = 0x10;
    GAME_BEACON_CopyStrbufCodes((void *)value, (u16 *)((char *)dst + 0x34));
}

static void GAME_BEACON_WritePokeEvolution(void *dst, u16 a, u16 b);

void GAME_BEACON_SetPokeEvolution(u16 a, u16 b)
{
    if (GAME_BEACON_CheckActionPriority(0x11)) {
        void *queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_WritePokeEvolution(queue, a, b);
        queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_RequestSend(queue);
    }
}

static void GAME_BEACON_WritePokeEvolution(void *dst, u16 a, u16 b)
{
    ((struct Obj00121 *)dst)->f30 = 0x11;
    ((struct Obj00121 *)dst)->f32 = a;
    GAME_BEACON_CopyStrbufCodes((void *)b, (u16 *)((char *)dst + 0x34));
    GAME_BEACON_ResetDetails(dst);
}

static void GAME_BEACON_WritePlayTime(void *dst, u16 value);

void GAME_BEACON_SetPlayTime(u16 value)
{
    if (GAME_BEACON_CheckActionPriority(0x14)) {
        void *queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_WritePlayTime(queue, value);
        queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_RequestSend(queue);
    }
}

static void GAME_BEACON_WritePlayTime(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0x14;
    ((struct Obj00121 *)dst)->f34 = value;
    GAME_BEACON_ResetDetails(dst);
}

static void GAME_BEACON_WriteItemUse(void *dst, u16 value);

void GAME_BEACON_SetItemUse(u16 value)
{
    if (GAME_BEACON_CheckActionPriority(0x23)) {
        void *queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_WriteItemUse(queue, value);
        queue = (char *)GAME_BEACON_Work + 4;
        GAME_BEACON_RequestSend(queue);
    }
}

static void GAME_BEACON_WriteItemUse(void *dst, u16 value)
{
    ((struct Obj00121 *)dst)->f30 = 0x23;
    ((struct Obj00121 *)dst)->f34 = value;
    GAME_BEACON_ResetDetails(dst);
}
