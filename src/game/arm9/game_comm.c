/*
 * file:     game_comm.c
 * unit:     yes
 * function: GAME_COMM_Create, GAME_COMM_Delete, GAME_COMM_Update, GAME_COMM_CallHandler, GAME_COMM_CallKindNotify, GAME_COMM_Start, GAME_COMM_RequestExitNoCallback, GAME_COMM_RequestExit, GAME_COMM_GetKind, GAME_COMM_IsTransition, GAME_COMM_GetWork, GAME_COMM_GetGameData, GAME_COMM_GetLastKind, GAME_COMM_SetCounter, GAME_COMM_ClearCounter, GAME_COMM_GetCounter, GAME_COMM_SetSeqState, GAME_COMM_SetNotifyFlag, GAME_COMM_GetNotifyFlag, GAME_COMM_UpdatePlayerStatus, GAME_COMM_ClearPlayerStatus, GAME_COMM_PushInfoMessage, GAME_COMM_PopInfoMessage, GAME_COMM_ClearInfoMessages, GAME_COMM_PushPairMessage, GAME_COMM_PushPalaceMessage, GAME_COMM_PushPlayerMessage
 * address:  0x020261E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from game_comm.c, game_comm_tail.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAME_DATA_GetMyStatus   0x02012944  thumb
 *   STRBUF_Create   0x020457B0  arm
 *   MYSTATUS_NameToStrbuf   0x02008500  thumb
 *   g_020A74B0      0x020A74B0  data
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_COMM_KindTable     0x0209FB5C  data
 *   GAME_COMM_SetSeqState  0x02026490  thumb
 *   gGameCommHandlers  0x0209FB70  data
 *   MI_CpuFill8 0x02082BCC  arm
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_DATA_GetPlayerStatusById  0x02012950  thumb
 *   MYSTATUS_IsNameEmpty  0x020084BC  thumb
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 */
#include "cursor_move_shared_types.h"
#include "game_beacon_types.h"
#include "game_comm_shared_types.h"

struct VecSetItem {
    u32 reserved00;
    struct Strbuf *buf1;
    struct Strbuf *buf2;
};

struct VecSet {
    void *owner;
    u8 reserved04[0x38];
    struct VecSetItem items[6];
};

struct GameData;

struct Strbuf;

struct MyStatus;

/* Sequence of the running comm kind, at +0xC of GameComm. */
typedef struct GameCommSeq {
    u32 frameCount;     /* cleared by the state machine on a state change */
    u8  state;          /* 0 start, 1 wait, 2 run, 3 exit, 4 end, 5 finish */
    u8  changed;        /* set with every state change */
    u8  reserved[2];
} GameCommSeq;

/* Called with the start request argument, the start callback's result and a caller argument. */
typedef void (*GameCommNotifyFunc)(u32 param, void *work, u32 arg);

/* Callbacks of one comm kind, 0x1C bytes per entry; the table is indexed by
 * GameComm.kind (entry 0 unused). */
typedef struct GameCommKindFuncs {
    void *(*start)(GameCommSeq *seq, u32 param);
    u32 (*wait)(GameCommSeq *seq, u32 param, void *work);
    void (*run)(GameCommSeq *seq, u32 param, void *work);
    u32 (*exit)(GameCommSeq *seq, u32 param, void *work);
    u32 (*end)(GameCommSeq *seq, u32 param, void *work);
    GameCommNotifyFunc update;  /* 0x14: called by GAME_COMM_CallHandler */
    GameCommNotifyFunc notify;  /* 0x18 */
} GameCommKindFuncs;

/* Called when the comm kind has exited. */
typedef void (*GameCommExitFunc)(u32 arg0, u32 arg1);

/* What each connected player is doing, one entry per net id. */
typedef struct GameCommPlayerStatus {
    u16 zoneId;             /* 0x0 */
    u16 prevZoneId;         /* 0x2 */
    u8  fieldStatus;        /* 0x4 */
    u8  palaceNetId;        /* 0x5: net id of the player whose world this player is in */
    u8  prevPalaceNetId;    /* 0x6 */
    u8  reserved;
} GameCommPlayerStatus;

/* One queued information message (two player names and a message id). */
typedef struct GameCommInfoQueueEntry {
    u16 messageId;              /* 0x0 */
    u8  netId;                  /* 0x2 */
    u8  used : 1;               /* 0x3 */
    u8  firstSex : 1;
    u8  secondSex : 1;
    u8  reserved : 5;
    struct Strbuf *name[2];     /* 0x4 */
} GameCommInfoQueueEntry;

typedef struct GameCommInfoQueue {
    GameCommInfoQueueEntry entry[6];    /* 0x00 */
    u8 readIndex;                       /* 0x48: advanced when the writer overruns it */
    u8 writeIndex;                      /* 0x49 */
} GameCommInfoQueue;

/* A popped message, as the message window wants it. */
typedef struct GameCommInfoMessage {
    struct Strbuf *name[2];     /* 0x0 */
    u8  wordSetIndex[2];        /* 0x8 */
    u8  sex[2];                 /* 0xA */
    u16 messageId;              /* 0xC */
    u8  reserved[2];
} GameCommInfoMessage;

typedef struct GameComm {
    struct GameData *gameData;  /* 0x00 */
    u8  exitRequest : 1;        /* 0x04: exit asked before the kind runs */
    u8  exitPending : 1;        /*       exit asked while the kind ends */
    u8  notifyFlag : 1;
    u8  reservedBits : 5;
    u8  kind;                   /* 0x05: index into the kind table, 0 = idle */
    u8  lastKind;               /* 0x06 */
    u8  reserved;
    u32 counter;                /* 0x08 */
    GameCommSeq seq;            /* 0x0C */
    u32 param;                  /* 0x14: the start request argument */
    void *work;                 /* 0x18: the start callback's result */
    u32 exitArg;                /* 0x1C */
    GameCommExitFunc exitFunc;  /* 0x20 */
    GameCommPlayerStatus playerStatus[3];   /* 0x24 */
    GameCommInfoQueue infoQueue;            /* 0x3C */
} GameComm;

/* the finish arm clears its fields through an enum-typed zero */
typedef enum { Z0 } E;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern void MYSTATUS_NameToStrbuf(const struct MyStatus *status, struct Strbuf *dst);

extern void STRBUF_Delete(struct Strbuf *vec);

extern u32 GFL_HEAP_Free(void *p);

void GAME_COMM_SetSeqState(GameCommSeq *seq, u32 state);

extern u32 g_020A74B0[];

extern const GameCommKindFuncs GAME_COMM_KindTable[];

struct VecSet *GAME_COMM_Create(u32 heapId, void *gameData);

void GAME_COMM_Delete(struct VecSet *obj);

void GAME_COMM_Update(GameComm *p);

/*
 * Allocate the 0x88-byte sprite for gameData (tag 0xe0), keep gameData as its first word,
 * then attach six sub-buffers: each starts at +0x3c with a 0xc stride, gets
 * two 8-byte allocations out of the heapId heap and registers both with the
 * resource handle GAME_DATA_GetMyStatus returned for gameData.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_COMM_Create.c \
 *       --func GAME_COMM_Create --addr 0x020261E4 --cc 1.1p1 --thumb
 */
struct VecSet *GAME_COMM_Create(u32 heapId, void *gameData)
{
    int i;
    struct VecSet *p;
    struct VecSetItem *base;
    struct VecSetItem *e;
    struct MyStatus *q;

    p = (struct VecSet *)GFL_HEAP_Alloc(heapId, 0x88, 1, (const char *)g_020A74B0, 0xe0);
    p->owner = gameData;
    q = GAME_DATA_GetMyStatus(gameData);
    base = p->items;
    for (i = 0; i < 6; i++) {
        e = base + i;
        e->buf1 = STRBUF_Create(8, heapId);
        e->buf2 = STRBUF_Create(8, heapId);
        MYSTATUS_NameToStrbuf(q, e->buf1);
        MYSTATUS_NameToStrbuf(q, e->buf2);
    }
    return p;
}

void GAME_COMM_Delete(struct VecSet *obj)
{
    struct VecSetItem *items = obj->items;
    int i;

    for (i = 0; i < 6; i++) {
        STRBUF_Delete(items[i].buf1);
        STRBUF_Delete(items[i].buf2);
    }
    GFL_HEAP_Free(obj);
}

/*
 * game_comm.c: the per-frame request state machine.  The request kind
 * (+5) selects a 0x1C-byte record of callbacks in the table at 0x0209FB5C
 * (GAME_COMM_CallHandler and GAME_COMM_CallKindNotify read its words at +0x14 and +0x18); the
 * state byte of the 8-byte sub-object at +0xC is the dense switch.
 *
 * Closed 2026-09-24 (wave 21, lane E) after the DIFF 10 recorded in
 * docs/notes/pkt_0202627C.c.txt.  The lever is the finish arm's zero typed
 * as an enum (`E z = Z0` assigned first, then cb, a, b read in that order):
 * with -enum int an enum value is not constant-propagated the way a u32
 * zero is, so the zero keeps its own web (r2, shared with the bics mask)
 * and the callback takes r5 as in the image.  A u32 zero in the same
 * position is 13 out; see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/GAME_COMM_Update.c \
 *       --func GAME_COMM_Update --addr 0x0202627C --cc 1.1p1 --thumb
 */
void GAME_COMM_Update(GameComm *p)
{
  GameCommSeq *sub;
  const GameCommKindFuncs *rec;
  if ((p == 0) || (p->kind == 0))
    return;
  sub = &p->seq;
  rec = &GAME_COMM_KindTable[p->kind];
  if (sub->changed == 1)
  {
    sub->frameCount = 0;
    sub->changed = 0;
  }
  switch (sub->state)
  {
    case 0:
      if (rec->start != 0)
      p->work = rec->start(sub, p->param);
      p->lastKind = p->kind;
      p->counter = 0;
      GAME_COMM_SetSeqState(sub, 1);
      break;

    case 1:
      if ((rec->wait == 0) || (rec->wait(sub, p->param, p->work) == 1))
      GAME_COMM_SetSeqState(sub, 2);
      break;

    case 2:
      if (p->exitRequest == 1)
    {
      p->exitRequest = 0;
      GAME_COMM_SetSeqState(&p->seq, 3);
      break;
    }
      rec->run(sub, p->param, p->work);
      break;

    case 3:
      if (rec->exit != 0)
    {
      if (rec->exit(sub, p->param, p->work) == 1)
        GAME_COMM_SetSeqState(sub, 4);
    }
    else
    {
      GAME_COMM_SetSeqState(sub, 4);
    }
      break;

    case 4:
      if ((rec->end != 0) && (rec->end(sub, p->param, p->work) != 1))
      break;
      GAME_COMM_SetSeqState(sub, 5);

    case 5:
    {
      GameCommExitFunc cb;
      u32 a;
      u32 b;
      E z;
      z = Z0;
      cb = p->exitFunc;
      a = p->exitArg;
      b = p->exitPending;
      p->work = (void *)z;
      p->kind = z;
      p->exitFunc = 0;
      p->exitArg = z;
      p->exitPending = 0;
      if (cb != 0)
        cb(a, b);
      break;
    }

  }

}

extern u8 gGameCommHandlers[];

void GAME_COMM_CallHandler(GameComm *comm, u32 arg)
{
    if (comm->seq.state != 5) {
        GameCommNotifyFunc handler = *(GameCommNotifyFunc *)(gGameCommHandlers + comm->kind * 0x1C);

        if (handler != 0) {
            handler(comm->param, comm->work, arg);
        }
    }
}

/* The comm request object of the game system: start, exit, player status and info message queue. */
extern void MI_CpuFill8(void *dst, u8 value, u32 size);

extern u8 GAME_DATA_GetOwnNetId(const struct GameData *gameData);

extern struct MyStatus *GAME_DATA_GetPlayerStatusById(struct GameData *gameData, u32 netId);

extern int MYSTATUS_IsNameEmpty(const struct MyStatus *status);

extern u32 MYSTATUS_GetOutfitVariant(const struct MyStatus *status);

void GAME_COMM_CallKindNotify(GameComm *comm, u32 arg);

void GAME_COMM_Start(GameComm *comm, u32 kind, u32 param);

void GAME_COMM_RequestExitNoCallback(GameComm *comm);

void GAME_COMM_RequestExit(GameComm *comm, GameCommExitFunc exitFunc, u32 exitArg);

u32 GAME_COMM_GetKind(const GameComm *comm);

u32 GAME_COMM_IsTransition(const GameComm *comm);

void *GAME_COMM_GetWork(const GameComm *comm);

struct GameData *GAME_COMM_GetGameData(const GameComm *comm);

u32 GAME_COMM_GetLastKind(const GameComm *comm);

void GAME_COMM_SetCounter(GameComm *comm, u32 value);

void GAME_COMM_ClearCounter(GameComm *comm);

u32 GAME_COMM_GetCounter(const GameComm *comm);

void GAME_COMM_SetNotifyFlag(GameComm *comm, u32 flag);

u32 GAME_COMM_GetNotifyFlag(const GameComm *comm);

void GAME_COMM_UpdatePlayerStatus(GameComm *comm, int netId, u16 zoneId, u8 palaceNetId, u32 fieldStatus, int quiet);

void GAME_COMM_ClearPlayerStatus(GameComm *comm);

void GAME_COMM_PushInfoMessage(GameComm *comm, u32 netId0, u32 netId1, u32 messageId);

int GAME_COMM_PopInfoMessage(GameComm *comm, GameCommInfoMessage *message);

void GAME_COMM_ClearInfoMessages(GameComm *comm);

void GAME_COMM_PushPairMessage(GameComm *comm, u32 netId0, u32 netId1);

void GAME_COMM_PushPalaceMessage(GameComm *comm, u32 netId, u32 palaceNetId);

void GAME_COMM_PushPlayerMessage(GameComm *comm, u32 netId);

/*
 * Parked: every concrete byte is right; the only unresolved site is the
 * data table base 0x0209FB74, whose word has no witness outside this range
 * (`literal` has nothing to stand on, and no branch anywhere names it).
 */
void GAME_COMM_CallKindNotify(GameComm *comm, u32 arg)
{
    if (comm->seq.state != 5) {
        GameCommNotifyFunc func = GAME_COMM_KindTable[comm->kind].notify;

        if (func != 0) {
            func(comm->param, comm->work, arg);
        }
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * game_comm.c, 0x020263D8..0x02026454: start a request, the unlabelled
 * forwarding leaf GAME_COMM_RequestExitNoCallback (GAME_COMM_RequestExit(p, 0, 0) as a pool-word tail
 * call), and the request update.  The byte at +4 of the comm object and of
 * its 8-byte sub-object at +0xC is a set of one-bit flags; every clear is a
 * `bics` and every set an `orrs`, which only bitfield stores give
 * (docs/families/game_comm.h).  GAME_COMM_Start clears bit 1 between its two
 * plain stores: f14, bit, f05 is the one order whose flag load lands after
 * the f14 store (the other two schedule the f05 store first).
 *
 * Integrator: seed 0x02026400 (unlabelled follower, member of this unit).
 */
void GAME_COMM_Start(GameComm *comm, u32 kind, u32 param)
{
    comm->param = param;
    comm->exitPending = 0;
    comm->kind = kind;
    comm->exitFunc = 0;
    comm->exitArg = 0;
    MI_CpuFill8(&comm->seq, 0, sizeof(GameCommSeq));
    GAME_COMM_ClearPlayerStatus(comm);
}

void GAME_COMM_RequestExitNoCallback(GameComm *comm)
{
    GAME_COMM_RequestExit(comm, 0, 0);
}

void GAME_COMM_RequestExit(GameComm *comm, GameCommExitFunc exitFunc, u32 exitArg)
{
    if (comm->seq.state == 2) {
        GAME_COMM_SetSeqState(&comm->seq, 3);
        comm->exitFunc = exitFunc;
        comm->exitArg = exitArg;
    } else if (comm->seq.state < 2) {
        comm->exitRequest = 1;
        comm->exitFunc = exitFunc;
        comm->exitArg = exitArg;
    } else {
        comm->exitPending = 1;
        if (comm->exitFunc == 0) {
            comm->exitFunc = exitFunc;
            comm->exitArg = exitArg;
        }
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           GAME_COMM_GetLastKind, GAME_COMM_SetCounter, GAME_COMM_ClearCounter, GAME_COMM_GetCounter
 *
 * Eight two-to-five-instruction accessors on one object, none of them
 * pushing a register: only the first is a real label in the generated
 * listing (a `func_starts` seed reached it some other way), and the other
 * seven print as `.word` runs between the two named functions this range
 * sits between, the same gap docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md describes.
 *
 * GAME_COMM_GetKind returns byte field +5 unconditionally: the original's
 * `bne`-around-a-redundant-`movs r0,#0` is what a plain `return v;`
 * compiles to when `v` is already known nonzero on one path, not a
 * guard. GAME_COMM_IsTransition is a genuine conjunction, `field5 != 0 &&
 * field0x10 != 2`, and only that phrasing (not two early-return `if`s)
 * produces the shared branch target both comparisons jump to
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 * The rest are plain word/byte getters and setters on fields +0x18, +0,
 * +6 and +8, one of them (GAME_COMM_ClearCounter) a "clear to zero" specialisation
 * of the setter that immediately follows it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02026454.c \
 *       --addr 0x02026454 --thumb
 */
u32 GAME_COMM_GetKind(const GameComm *comm)
{
    u8 kind = comm->kind;
    if (kind != 0) {
        return kind;
    }
    return 0;
}

u32 GAME_COMM_IsTransition(const GameComm *comm)
{
    if (comm->kind != 0 && comm->seq.state != 2) {
        return 1;
    }
    return 0;
}

void *GAME_COMM_GetWork(const GameComm *comm)
{
    return comm->work;
}

struct GameData *GAME_COMM_GetGameData(const GameComm *comm)
{
    return comm->gameData;
}

u32 GAME_COMM_GetLastKind(const GameComm *comm)
{
    return comm->lastKind;
}

void GAME_COMM_SetCounter(GameComm *comm, u32 value)
{
    comm->counter = value;
}

void GAME_COMM_ClearCounter(GameComm *comm)
{
    comm->counter = 0;
}

u32 GAME_COMM_GetCounter(const GameComm *comm)
{
    return comm->counter;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The labelled GAME_COMM_SetSeqState (8 bytes) is followed immediately by two more
 * unlabelled leaves reaching to the next real label at 0x020264B4, the
 * same shape as src/matched/unit_02026454.c just above it in the image.
 *
 * GAME_COMM_SetSeqState sets byte field +4 to its argument and unconditionally
 * sets byte field +5 to 1. GAME_COMM_SetNotifyFlag and GAME_COMM_GetNotifyFlag are a
 * setter/getter pair on bit 2 of field +4: the setter narrows its 32-bit
 * argument to a byte before taking bit 0 of it
 * (`u8 f = (u8)flag;` is what produces the `lsls #0x18`/`lsrs #0x18`
 * truncation pair, not a mask, per the halfword-narrowing case in
 * docs/MATCHING.md), and the getter's `lsls #0x1d`/`lsrs #0x1f` pair is a
 * bitfield extraction rather than a type conversion (32 - 0x1d is 3, not
 * 8/16/32), which only reproduces from an actual bitfield member
 * declaration: docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02026490.c \
 *       --addr 0x02026490 --thumb
 */
void GAME_COMM_SetSeqState(GameCommSeq *seq, u32 state)
{
    seq->state = state;
    seq->changed = 1;
}

void GAME_COMM_SetNotifyFlag(GameComm *comm, u32 flag)
{
    u8 value = (u8)flag;

    comm->notifyFlag = value;
}

u32 GAME_COMM_GetNotifyFlag(const GameComm *comm)
{
    return comm->notifyFlag;
}

void GAME_COMM_UpdatePlayerStatus(GameComm *comm, int netId, u16 zoneId, u8 palaceNetId, u32 fieldStatus, int quiet)
{
    GameCommPlayerStatus *status = &comm->playerStatus[netId];
    u16 oldZoneId;
    u8 oldPalaceNetId;

    status->fieldStatus = fieldStatus;
    oldZoneId = status->zoneId;
    if (oldZoneId == zoneId && status->palaceNetId == palaceNetId) {
        return;
    }
    if (oldZoneId != zoneId) {
        status->prevZoneId = oldZoneId;
        status->zoneId = zoneId;
    }
    oldPalaceNetId = status->palaceNetId;
    if (oldPalaceNetId == palaceNetId) {
        return;
    }
    status->prevPalaceNetId = oldPalaceNetId;
    status->palaceNetId = palaceNetId;
    if (!quiet) {
        GAME_COMM_PushPalaceMessage(comm, netId, palaceNetId);
    }
}

void GAME_COMM_ClearPlayerStatus(GameComm *comm)
{
    MI_CpuFill8(comm->playerStatus, 0, sizeof(comm->playerStatus));
}

/*
 * Push one message onto the six-entry info queue at +0x3c of the comm
 * object (GAME_COMM_Create creates it; 0xc bytes per entry, write index at
 * +0x85, read index at +0x84, which is pushed along when the writer
 * overruns it).  Each net id is resolved to a player status: the console's
 * own (GAME_DATA_GetMyStatus) when it equals the console's net id, otherwise the
 * by-id lookup (GAME_DATA_GetPlayerStatusById).  If either status is unusable
 * (MYSTATUS_IsNameEmpty == 1) nothing is written.
 */
void GAME_COMM_PushInfoMessage(GameComm *comm, u32 netId0, u32 netId1, u32 messageId)
{
    GameCommInfoQueue *queue;
    struct MyStatus *status0;
    struct MyStatus *status1;
    GameCommInfoQueueEntry *entry;

    queue = &comm->infoQueue;
    if (netId0 == GAME_DATA_GetOwnNetId(comm->gameData)) {
        status0 = GAME_DATA_GetMyStatus(comm->gameData);
    } else {
        status0 = GAME_DATA_GetPlayerStatusById(comm->gameData, netId0);
    }
    if (netId1 == GAME_DATA_GetOwnNetId(comm->gameData)) {
        status1 = GAME_DATA_GetMyStatus(comm->gameData);
    } else {
        status1 = GAME_DATA_GetPlayerStatusById(comm->gameData, netId1);
    }
    if (MYSTATUS_IsNameEmpty(status0) == 1) {
        return;
    }
    if (MYSTATUS_IsNameEmpty(status1) == 1) {
        return;
    }
    entry = &queue->entry[queue->writeIndex];
    if (entry->used == 1) {
        queue->readIndex = (u8)(queue->readIndex + 1);
    }
    entry->netId = (u8)netId0;
    entry->messageId = (u16)messageId;
    entry->used = 1;
    MYSTATUS_NameToStrbuf(status0, entry->name[0]);
    entry->firstSex = (u8)MYSTATUS_GetOutfitVariant(status0);
    MYSTATUS_NameToStrbuf(status1, entry->name[1]);
    entry->secondSex = (u8)MYSTATUS_GetOutfitVariant(status1);
    queue->writeIndex = (u8)(queue->writeIndex + 1);
    if (queue->writeIndex >= 6) {
        queue->writeIndex = 0;
    }
    if (queue->readIndex >= 6) {
        queue->readIndex = 0;
    }
}

/*
 * EXACT*: the listing extent runs 164 bytes because the follower at
 * 0x0202667E is an unlabelled leaf (`movs r0, r0` / `bx lr`) that saves
 * nothing, so `disasm.py` never labels it.  Byte coverage ends at +0x76.
 *
 * Counted eight-entry bank: pop the next live 12-byte record at
 * base + base[0x48] * 12, publish it as the caller's 0x10-byte snapshot,
 * clear its live flag and advance the cursor with a wrap at six.
 *
 * The publish order is not the source order: the whole-word load of +0x04
 * lands before the `out[8] = 0` store, so the C has to store the word first
 * and the byte second to let the scheduler hoist the load into the store's
 * shadow.  Written with `out[8] = 0` first, the compiled order flips and
 * nine bytes differ.
 */
int GAME_COMM_PopInfoMessage(GameComm *comm, GameCommInfoMessage *message)
{
    GameCommInfoQueue *queue = &comm->infoQueue;
    GameCommInfoQueueEntry *entry = &queue->entry[queue->readIndex];

    if (entry->used == 0) {
        return 0;
    }
    MI_CpuFill8(message, 0, sizeof(GameCommInfoMessage));
    message->name[0] = entry->name[0];
    message->wordSetIndex[0] = 0;
    message->sex[0] = entry->firstSex;
    message->name[1] = entry->name[1];
    message->wordSetIndex[1] = 1;
    message->sex[1] = entry->secondSex;
    message->messageId = entry->messageId;
    entry->used = 0;
    queue->readIndex = queue->readIndex + 1;
    if (queue->readIndex >= 6) {
        queue->readIndex = 0;
    }
    return 1;
}

/*
 * Clears bit 0 of six 12-byte entries at +0x3F and the bytes at +0x85 and +0x84.
 * Caller: ov011 0x021731C8.
 */
void GAME_COMM_ClearInfoMessages(GameComm *comm)
{
    int i;
    for (i = 0; i < 6; i++) {
        comm->infoQueue.entry[i].used = 0;
    }
    comm->infoQueue.writeIndex = 0;
    comm->infoQueue.readIndex = 0;
}

/*
 * A thin wrapper over `GAME_COMM_PushInfoMessage` (258 bytes, still open), forwarding
 * its three arguments unchanged and appending a fourth: 0x27 when the
 * second and third arguments are equal, 0x26 otherwise. The `? :` form,
 * not an `if`/`else` writing the call twice, is what reproduces the
 * single shared `lsls`/`lsrs #0x10` that narrows the chosen constant to
 * the callee's 16-bit fourth parameter after the branch instead of in
 * each arm.
 *
 * `GAME_COMM_PushInfoMessage`'s only three callers in the whole ARM9 image are this
 * function and its two siblings GAME_COMM_PushPalaceMessage and GAME_COMM_PushPlayerMessage
 * (src/matched/GAME_COMM_PushPalaceMessage.c, src/matched/GAME_COMM_PushPlayerMessage.c). Keeping each
 * in its own translation unit is what gives the other two's calls
 * standing as outside evidence for this one; compiled together as a
 * single unit the three calls would attest only each other and the whole
 * range would cap at MATCH (docs/MATCHING.md, "the pairwise case across
 * two files").
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_COMM_PushPairMessage.c \
 *       --func GAME_COMM_PushPairMessage --addr 0x020266AC --cc 1.1p1 --thumb
 */
void GAME_COMM_PushPairMessage(GameComm *comm, u32 netId0, u32 netId1)
{
    GAME_COMM_PushInfoMessage(comm, netId0, netId1, (u16)((netId0 == netId1) ? 0x27 : 0x26));
}

/*
 * The same wrapper shape as src/matched/GAME_COMM_PushPairMessage.c, with the constant
 * pair 0x1e/0x1d in place of 0x27/0x26. See that file's header for why it
 * is kept in its own translation unit rather than merged with its two
 * siblings.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_COMM_PushPalaceMessage.c \
 *       --func GAME_COMM_PushPalaceMessage --addr 0x020266C0 --cc 1.1p1 --thumb
 */
void GAME_COMM_PushPalaceMessage(GameComm *comm, u32 netId, u32 palaceNetId)
{
    GAME_COMM_PushInfoMessage(comm, netId, palaceNetId, (u16)((netId == palaceNetId) ? 0x1e : 0x1d));
}

/*
 * The simplest of the three GAME_COMM_PushInfoMessage wrappers: forwards its first
 * argument, repeats its second as both the second and third callee
 * argument, and appends the literal 0x1f. See
 * src/matched/GAME_COMM_PushPairMessage.c's header for why the three are kept as
 * separate files rather than one unit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_COMM_PushPlayerMessage.c \
 *       --func GAME_COMM_PushPlayerMessage --addr 0x020266D4 --cc 1.1p1 --thumb
 */
void GAME_COMM_PushPlayerMessage(GameComm *comm, u32 netId)
{
    GAME_COMM_PushInfoMessage(comm, netId, netId, 0x1f);
}
