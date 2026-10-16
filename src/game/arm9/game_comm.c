/*
 * file:     game_comm.c
 * unit:     yes
 * function: CURSOR_MOVE_CreateVecSet, CURSOR_MOVE_DeleteVecSet, GAME_COMM_Update, GAME_COMM_CallHandler
 * address:  0x020261E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from cursor_move.c, game_comm.c by tools/splitfile.py.
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
 */
#include "cursor_move_shared_types.h"

struct VecSetItem {
    u32 reserved00;
    void *buf1;
    void *buf2;
};

struct VecSet {
    void *owner;
    u8 reserved04[0x38];
    struct VecSetItem items[6];
};

struct U16Vec;

struct CursorCommSeq
{
  u32 frameCount;
  u8 state;
  u8 changed;
  u8 reserved06;
  u8 reserved07;
};

struct CursorComm
{
  u32 reserved00;
  u8 exitRequest : 1;
  u8 notifyFlag : 1;
  u8 exitPending : 1;
  u8 reserved3 : 5;
  u8 kind;
  u8 lastKind;
  u8 reserved07;
  u32 counter;
  struct CursorCommSeq seq;
  u32 param;
  u32 work;
  u32 exitArg;
  void (*exitFunc)(u32, u32);
};

struct CursorCommKindFuncs
{
  u32 (*start)(struct CursorCommSeq *, u32);
  u32 (*wait)(struct CursorCommSeq *, u32, u32);
  void (*run)(struct CursorCommSeq *, u32, u32);
  u32 (*stop)(struct CursorCommSeq *, u32, u32);
  u32 (*end)(struct CursorCommSeq *, u32, u32);
  u32 reserved14;
  u32 reserved18;
};

/* the finish arm clears its fields through an enum-typed zero */
typedef enum { Z0 } E;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u8 *GAME_DATA_GetMyStatus(void *a0);

extern struct U16Vec *STRBUF_Create(u32 a0, u32 a1);

extern void MYSTATUS_NameToStrbuf(void *a0, void *a1);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 GFL_HEAP_Free(void *p);

extern void GAME_COMM_SetSeqState(void *obj, u32 value);

extern u32 g_020A74B0[];

extern struct CursorCommKindFuncs GAME_COMM_KindTable[];

struct VecSet *CURSOR_MOVE_CreateVecSet(u32 a0, void *a1);

void CURSOR_MOVE_DeleteVecSet(struct VecSet *obj);

void GAME_COMM_Update(struct CursorComm *p);

/*
 * Allocate the 0x88-byte sprite for a1 (tag 0xe0), keep a1 as its first word,
 * then attach six sub-buffers: each starts at +0x3c with a 0xc stride, gets
 * two 8-byte allocations out of the a0 heap and registers both with the
 * resource handle GAME_DATA_GetMyStatus returned for a1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CURSOR_MOVE_CreateVecSet.c \
 *       --func CURSOR_MOVE_CreateVecSet --addr 0x020261E4 --cc 1.1p1 --thumb
 */
struct VecSet *CURSOR_MOVE_CreateVecSet(u32 a0, void *a1)
{
    int i;
    struct VecSet *p;
    struct VecSetItem *base;
    struct VecSetItem *e;
    u8 *q;

    p = (struct VecSet *)GFL_HEAP_Alloc(a0, 0x88, 1, (const char *)g_020A74B0, 0xe0);
    p->owner = a1;
    q = GAME_DATA_GetMyStatus(a1);
    base = p->items;
    for (i = 0; i < 6; i++) {
        e = base + i;
        e->buf1 = STRBUF_Create(8, a0);
        e->buf2 = STRBUF_Create(8, a0);
        MYSTATUS_NameToStrbuf(q, e->buf1);
        MYSTATUS_NameToStrbuf(q, e->buf2);
    }
    return p;
}

void CURSOR_MOVE_DeleteVecSet(struct VecSet *obj)
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
void GAME_COMM_Update(struct CursorComm *p)
{
  struct CursorCommSeq *sub;
  struct CursorCommKindFuncs *rec;
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
      if (rec->stop != 0)
    {
      if (rec->stop(sub, p->param, p->work) == 1)
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
      void (*cb)(u32, u32);
      u32 a;
      u32 b;
      E z;
      z = Z0;
      cb = p->exitFunc;
      a = p->exitArg;
      b = p->notifyFlag;
      p->work = z;
      p->kind = z;
      p->exitFunc = 0;
      p->exitArg = z;
      p->notifyFlag = 0;
      if (cb != 0)
        cb(a, b);
      break;
    }

  }

}

typedef struct GameCommEntry {
    u8  pad0[4];
    u8  reserved4;
    u8  kind;
    u8  pad6[0xA];
    u8  mode;
    u8  pad11[3];
    u32 param0;
    u32 param1;
} GameCommEntry;

typedef void (*GameCommHandler)(u32 param0, u32 param1, u32 arg);

extern u8 gGameCommHandlers[];

void GAME_COMM_CallHandler(GameCommEntry *entry, u32 arg)
{
    if (entry->mode != 5) {
        GameCommHandler handler = *(GameCommHandler *)(gGameCommHandlers + entry->kind * 0x1C);

        if (handler != 0) {
            handler(entry->param0, entry->param1, arg);
        }
    }
}
