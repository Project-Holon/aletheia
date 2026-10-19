/*
 * file:     game_event.c
 * unit:     yes
 * function: GAME_EVENT_Create, GAME_EVENT_RunFunc, GAME_EVENT_Delete, GAME_EVENT_Change, GAME_EVENT_ChangeEvent, GAME_EVENT_CallEvent, GAME_EVENT_Control, GAME_EVENT_IsRunning, GAME_EVENT_StartByCreator, GAME_EVENT_CallProcSeq, GAME_EVENT_CallProc, GAME_EVENT_OverlaySeq, GAME_EVENT_CreateOverlayEvent, GAME_EVENT_GetGameSystem, GAME_EVENT_GetWork, GAME_EVENT_GetSeq, GAME_EVENT_GetParent
 * address:  0x020122C0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from ica_anime.c, btl_setup.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   _GameEventFileName  0x020A727C  data
 *   GAMESYSTEM_CallProc 0x020120B4 thumb arm9
 *   GAMESYSTEM_GetProcStatus 0x020120F0 thumb arm9
 *   GAMESYSTEM_GetEvent 0x02012104 thumb arm9
 *   GAMESYSTEM_SetEvent 0x02012108 thumb arm9
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 */
#include "script_vm_types.h"
#include "vm_shared_types.h"
#include "ica_anime_shared_types.h"

/* Work of GAME_EVENT_CallProcSeq (GAME_EVENT_CallProc). */
struct ProcCallWork {
    u32   overlayId;
    void *procData;
    void *param;
};

/* Work of GAME_EVENT_OverlaySeq (GAME_EVENT_CreateOverlayEvent, 0x10 bytes). */
struct OverlayEventWork {
    u32   overlayId;
    struct GameEvent *event;
    u32   reserved[2];
};

extern u32 GFL_HEAP_Free(void *memory);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern int GF_OVERLAY_Load(int overlayId);

//P
extern void  GF_OVERLAY_Unload(s32 overlayId);

void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);

u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);

struct GameEvent *GAMESYSTEM_GetEvent(const struct GameSystem *gameSystem);

void GAMESYSTEM_SetEvent(struct GameSystem *gameSystem, struct GameEvent *event);

struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);

int GAME_EVENT_RunFunc(struct GameEvent *event);

void GAME_EVENT_Delete(struct GameEvent *event);

void GAME_EVENT_Change(struct GameEvent *event, GameEventFunc func, u32 workSize);

void GAME_EVENT_ChangeEvent(struct GameEvent *now, struct GameEvent *next);

void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);

int GAME_EVENT_Control(struct GameSystem *gameSystem);

int GAME_EVENT_IsRunning(struct GameSystem *gameSystem);

int GAME_EVENT_StartByCreator(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg);

int GAME_EVENT_CallProcSeq(struct GameEvent *event, u32 *seq, void *work);

void GAME_EVENT_CallProc(struct GameEvent *parent, u32 overlayId, void *procData, void *param);

int GAME_EVENT_OverlaySeq(struct GameEvent *event, u32 *seq, void *work);

struct GameEvent *GAME_EVENT_CreateOverlayEvent(struct GameSystem *gameSystem, u32 overlayId, GameEventCreatorFn creator, void *arg);

struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);

void *GAME_EVENT_GetWork(struct GameEvent *event);

u32 *GAME_EVENT_GetSeq(struct GameEvent *event);

struct GameEvent *GAME_EVENT_GetParent(struct GameEvent *event);

extern const char _GameEventFileName[];

/*
 * Constructor for a five-word descriptor: allocate the 0x14-byte header off
 * heap 4, fill it with the caller's two handles and a zeroed counter,
 * allocate the caller-sized payload off the same heap and hang it at +0xc,
 * and record the owner at +0x10.
 *
 * Both allocations go through GFL_HEAP_Alloc, whose last two arguments are
 * the file/line debug site pair (see src/matched/GFL_HEAP_Alloc.c).  The file
 * pointer is one pool word loaded twice, so it is a single ABS32 into the
 * packed string area and has to be declared as an extern pinned by address
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md), never as a
 * literal __FILE__.  The two line numbers, 55 and 59, are four apart but
 * each is its own `movs`: they are not consecutive arguments of one call,
 * so the add-chain form does not apply
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *
 * The owner pointer and the payload size arrive in r0 and r3 and are both
 * live across the first call, so r5 takes the owner and the size is spilled
 * to [sp,#4] rather than costing a sixth callee-saved register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_Create.c \
 *       --func GAME_EVENT_Create --addr 0x020122C0 --cc 1.1p1 --thumb
 */
struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize)
{
    struct GameEvent *event;

    event = GFL_HEAP_Alloc(4, sizeof(struct GameEvent), 1, _GameEventFileName, 55);
    event->parent = parent;
    event->func = func;
    event->seq = 0;
    event->work = GFL_HEAP_Alloc(4, workSize, 1, _GameEventFileName, 59);
    event->gameSystem = gameSystem;
    return event;
}

/*
 * Virtual call: the target is the object's own word at +4, the first argument is
 * the object, the second is the object + 8, the third is the object's word at
 * +0xc.  The call is a register `blx r3`, so there is no relocation to attest
 * and the file is EXACT up to the two bytes of section padding after the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_RunFunc.c \
 *       --func GAME_EVENT_RunFunc --addr 0x02012304 --cc 1.1p1 --thumb
 */
int GAME_EVENT_RunFunc(struct GameEvent *event)
{
    return event->func(event, &event->seq, event->work);
}

void GAME_EVENT_Delete(struct GameEvent *event)
{
    void *work = event->work;
    if (work) GFL_HEAP_Free(work);
    GFL_HEAP_Free(event);
}

void GAME_EVENT_Change(struct GameEvent *event, GameEventFunc func, u32 workSize)
{
    void *work;
    event->seq = 0;
    work = event->work;
    event->func = func;
    if (work)
        GFL_HEAP_Free(work);
    event->work = GFL_HEAP_Alloc(4, workSize, 1, _GameEventFileName, 0x60);
}

/*
 * Reads the object's +0x10 word into a register first, then copies its +0 word
 * out through the caller's pointer and hands that same value to
 * GAME_EVENT_Delete, then passes the +0x10 word and the pointer to GAMESYSTEM_SetEvent.
 * Order matters: the +0x10 load is hoisted above the store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_ChangeEvent.c \
 *       --func GAME_EVENT_ChangeEvent --addr 0x0201235C --cc 1.1p1 --thumb
 */
void GAME_EVENT_ChangeEvent(struct GameEvent *now, struct GameEvent *next)
{
    struct GameSystem *gameSystem = now->gameSystem;
    struct GameEvent *parent = now->parent;

    next->parent = parent;
    GAME_EVENT_Delete(now);
    GAMESYSTEM_SetEvent(gameSystem, next);
}

/*
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
void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child)
{
    child->parent = parent;
    GAMESYSTEM_SetEvent(parent->gameSystem, child);
}

/*
 * game_event.c: run the event queue until it drains, stalls or finishes.
 * The dangling `cmp r0, #0x21` followed by an unconditional branch back to
 * the loop head is a SWITCH whose case 0x21 lands where the default does:
 * the compare chain keeps the compare and drops the branch.  An if chain
 * (docs/notes/pkt_02012380.c.txt, 38 out) never emits it.
 */
int GAME_EVENT_Control(struct GameSystem *gameSystem)
{
    struct GameEvent *event;
    struct GameEvent *parent;

    for (;;) {
        event = GAMESYSTEM_GetEvent(gameSystem);
        if (event == 0)
            return 0;
        switch (GAME_EVENT_RunFunc(event)) {
        case 0:
            return 0;
        case 1:
            parent = GAME_EVENT_GetParent(event);
            GAME_EVENT_Delete(event);
            GAMESYSTEM_SetEvent(gameSystem, parent);
            if (parent == 0)
                return 1;
            break;
        case 0x21:
            break;
        }
    }
}

int GAME_EVENT_IsRunning(struct GameSystem *gameSystem)
{
    if (GAMESYSTEM_GetEvent(gameSystem) != 0) {
        return 1;
    }
    return 0;
}

/*
 * The packet's driver: reject when GAMESYSTEM_GetEvent says the object is busy,
 * reject a null callback, run the callback with the object and the second
 * argument, reject a zero result, hand a non-zero result to GAMESYSTEM_SetEvent and
 * report 1.
 *
 * The two spellings differ by four bytes of layout.  Written with the
 * "invert the guard" shape
 *
 *     if (GAMESYSTEM_GetEvent(o) != 0) return 0;
 *     if (fn == 0) return 0;
 *     r = fn(o, a2);
 *     if (r != 0) { GAMESYSTEM_SetEvent(o, r); return 1; }
 *     return 0;
 *
 * mwccarm lays the two `movs r0, #0; pop` arms inline and falls through into
 * the success arm, which is what the original does.  Swapping the last pair to
 * `if (r == 0) return 0; else { ... return 1; }` makes it test `bne` and move
 * the success arm out of line (+0x24 onward), and a `goto fail` spelling
 * reproduces only 44 of the 52 bytes: the goto drops the `adds r1, r0, #0`
 * copy that keeps the callback result live for GAMESYSTEM_SetEvent and reorders the
 * callback call.  The reachable spelling is the plain one.
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_StartByCreator.c \
 *       --func GAME_EVENT_StartByCreator --addr 0x020123D8 --cc 1.1p1 --thumb
 */
int GAME_EVENT_StartByCreator(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg)
{
    struct GameEvent *event;

    if (GAMESYSTEM_GetEvent(gameSystem) != 0)
        return 0;
    if (creator == 0)
        return 0;
    event = creator(gameSystem, arg);
    if (event != 0) {
        GAMESYSTEM_SetEvent(gameSystem, event);
        return 1;
    }
    return 0;
}

/*
 * A three-state driver.  GAME_EVENT_GetGameSystem's result is bound before the switch and
 * is still live in r0 at the case-0 call, which is why the two loads of the
 * state go to r1 (not r0) and the callee's argument registers are r1, r2, r3
 * with r0 carrying the earlier call's result.  Both arms leave through the
 * shared `return 0` tail, so neither may be written as a `return`: writing
 * `return 0` in case 0 makes mwccarm duplicate `movs r0, #0` inline instead of
 * branching to +0x34, and the function comes out six bytes long with the last
 * two arms shifted.  `!= 0` / `== 0` in case 1 makes no difference.
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_CallProcSeq.c \
 *       --func GAME_EVENT_CallProcSeq --addr 0x0201240C --cc 1.1p1 --thumb
 */
int GAME_EVENT_CallProcSeq(struct GameEvent *event, u32 *seq, void *work)
{
    struct ProcCallWork *call = work;
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);

    switch (*seq) {
    case 0:
        GAMESYSTEM_CallProc(gameSystem, call->overlayId, call->procData, call->param);
        *seq = *seq + 1;
        break;
    case 1:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            return 1;
        break;
    }
    return 0;
}

/*
 * Promoted from src/pending/ in the second 0-64 byte band pass (lane 1).  It
 * sat at MATCH on the pool word at +0x2C, which holds 0x0201240D - the state
 * machine at 0x0201240C with its Thumb bit, handed to GAME_EVENT_Create as a
 * callback.  That word is the only one in the image naming 0x0201240D, and no
 * branch reaches 0x0201240C from outside this range either, so the site needed
 * 0x0201240C to be an EXACT entry of its own; now that it is, the site
 * resolves through the `matched` class and this file needs no change.
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_CallProc.c \
 *       --func GAME_EVENT_CallProc --addr 0x02012444 --cc 1.1p1 --thumb
 */
void GAME_EVENT_CallProc(struct GameEvent *parent, u32 overlayId, void *procData, void *param)
{
    struct GameEvent *event;
    struct ProcCallWork *call;

    event = GAME_EVENT_Create(parent->gameSystem, 0, GAME_EVENT_CallProcSeq, sizeof(struct ProcCallWork));
    call = GAME_EVENT_GetWork(event);
    call->overlayId = overlayId;
    call->procData = procData;
    call->param = param;
    GAME_EVENT_CallEvent(parent, event);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_OverlaySeq.c \
 *       --func GAME_EVENT_OverlaySeq --addr 0x02012474 --cc 1.1p1 --thumb
 */
int GAME_EVENT_OverlaySeq(struct GameEvent *event, u32 *seq, void *work)
{
    struct OverlayEventWork *overlay = work;

    GAME_EVENT_GetGameSystem(event);
    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, overlay->event);
        (*seq)++;
        break;
    case 1:
        GF_OVERLAY_Unload((int)overlay->overlayId);
        return 1;
    }
    return 0;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_EVENT_CreateOverlayEvent.c \
 *       --func GAME_EVENT_CreateOverlayEvent --addr 0x020124AC --cc 1.1p1 --thumb
 */
struct GameEvent *GAME_EVENT_CreateOverlayEvent(struct GameSystem *gameSystem, u32 overlayId, GameEventCreatorFn creator, void *arg)
{
    struct GameEvent *event;
    struct OverlayEventWork *overlay;

    event = GAME_EVENT_Create(gameSystem, 0, GAME_EVENT_OverlaySeq, sizeof(struct OverlayEventWork));
    overlay = GAME_EVENT_GetWork(event);
    overlay->overlayId = overlayId;
    GF_OVERLAY_Load(overlayId);
    overlay->event = creator(gameSystem, arg);
    return event;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Four two-byte leaf accessors in a row on the same object.  None of them
 * saves lr, so disasm.py labels none of them and the whole run prints as a
 * `.byte` blob between two pools; they are only reachable by sweeping
 * addresses.  GAME_EVENT_GetSeq returns the address of the embedded sub-object
 * at +8 rather than a stored pointer.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020124E4.c \
 *       --addr 0x020124E4 --thumb
 */
struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event)
{
    return event->gameSystem;
}

void *GAME_EVENT_GetWork(struct GameEvent *event)
{
    return event->work;
}

u32 *GAME_EVENT_GetSeq(struct GameEvent *event)
{
    return &event->seq;
}

struct GameEvent *GAME_EVENT_GetParent(struct GameEvent *event)
{
    return event->parent;
}
