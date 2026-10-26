/*
 * file:     billboard_act.c
 * unit:     yes
 * function: BILLBOARD_ACT_Create, BILLBOARD_ACT_Delete, BILLBOARD_ACT_GetBoard, BILLBOARD_ACT_InitSlot, BILLBOARD_ACT_ResetPlayback, BILLBOARD_ACT_InitEntry, BILLBOARD_ACT_CreateSlots, BILLBOARD_ACT_AddSlot, BILLBOARD_ACT_DeleteSlots, BILLBOARD_ACT_DeleteSlot, BILLBOARD_ACT_GetSlotBoardId, BILLBOARD_ACT_CreateEntries, BILLBOARD_ACT_DeleteEntries, BILLBOARD_ACT_UpdateEntries, BILLBOARD_ACT_UpdateEntry, BILLBOARD_ACT_UploadSlotFrame, BILLBOARD_ACT_UploadSlotPalette, BILLBOARD_ACT_Draw, BILLBOARD_ACT_SetEntryFlags, BILLBOARD_ACT_GetEntryFlags, BILLBOARD_ACT_SetEntryEnabled, BILLBOARD_ACT_SetEntryCommands, BILLBOARD_ACT_SetEntryList, BILLBOARD_ACT_GetEntryList, BILLBOARD_ACT_SetEntryCursor, BILLBOARD_ACT_GetEntryCursor, BILLBOARD_ACT_SetEntryPaletteFromSlot, BILLBOARD_ACT_GetEntryElemId, BILLBOARD_ACT_GetEntrySlotIndex, BILLBOARD_ACT_GetEntryLastCommand, BILLBOARD_ACT_IsControlCommand, BILLBOARD_ACT_RunControlCommand, BILLBOARD_ACT_GetControlHandler, BILLBOARD_ACT_CmdEnd, BILLBOARD_ACT_CmdSetList, BILLBOARD_ACT_CmdLoop, BILLBOARD_ACT_CmdJump
 * address:  0x0204FE94
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from particle.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc     0x02030734  arm
 *   BILLBOARD_Create     0x0204EBD4  arm
 *   AREAMAN_Create     0x02033C00  arm
 *   sBillboardAct     0x020A7FB0  data
 *   gBillboardActTpl  0x020A155C  data  a4
 *   BILLBOARD_FreeElem  0x0204F5A8  arm
 *   BILLBOARD_Delete  0x0204ED24  arm
 *   AREAMAN_Delete  0x02033C9C  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   AREAMAN_Alloc  0x02033CA8  arm
 *   BILLBOARD_AddImage  0x0204EF58  arm
 *   BILLBOARD_TrimImageResource  0x0204F10C  arm
 *   BILLBOARD_DeleteImage  0x0204F150  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   AREAMAN_Free  0x0203422C  arm
 *   BILLBOARD_AddElem  0x0204F428  arm
 *   BILLBOARD_SetElemVisible  0x0204F720  arm
 *   BILLBOARD_SetElemCell  0x0204F66C  arm
 *   BILLBOARD_SetElemFlipS  0x0204F764  arm
 *   BILLBOARD_SetElemFlipT  0x0204F794  arm
 *   G3D_SYSTEM_GetTexDataAddr  0x020473D8  arm
 *   BILLBOARD_GetImageVramAddr  0x0204F2B4  arm
 *   BILLBOARD_CalcImageFrameRange  0x0204F344  arm
 *   G3D_SYSTEM_GetPlttDataAddr   0x020473EC  arm
 *   BILLBOARD_GetImagePlttVramOffset   0x0204F2CC  arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   BILLBOARD_GetElemVisible  0x0204F704  arm
 */
#include "billboard_act_shared_types.h"

#include "../types.h"

struct AreaMan;          /* index range pool (docs/families/areaman.h) */

struct BbBoard;          /* billboard board object, opaque in this file */

struct PayloadBlock;     /* reference-counted payload of a slot, opaque */

struct BbActSys;

struct BbActEntry;

/* ---- billboard_act ---- */

/*
 * Called by the board to move sprite data to VRAM: kind 0 is one texture
 * frame, kind 1 is the 0x20-byte palette.
 */
typedef u32 (*BbActUploadFn)(u32 kind, u32 dst, u32 src, u32 size);

#include "billboard_act_types.h"

/* 28-byte board setup block: the two counts, then fixed data from rodata. */
struct BbActBoardInit {
    u16 slotCount;
    u16 entryCount;
    u32 rest[6];
};

/* One image slot: the board image id and the loaded payload behind it. */
struct BbActSlot {
    u16 boardId;             /* 0xFFFF: unused */
    u16 pad02;
    struct G3dResource *payload; /* loaded resource behind the slot, 0 when none */
};

/* Request record for BILLBOARD_ACT_CreateSlots (create slots). */
/* Animation command: a frame index, two flip flags and one argument. */
struct BbActCmd {
    u16 frame : 14;          /* values 0x3FFC..0x3FFF are control commands */
    u16 flipX : 1;
    u16 flipY : 1;
    u16 arg;                 /* duration in frames; control commands use it as operand */
};

enum {
    BBACT_CMD_JUMP     = 0x3FFC,   /* cursor = arg */
    BBACT_CMD_LOOP     = 0x3FFD,   /* arg high byte: repeat count, low byte: target cursor */
    BBACT_CMD_SET_LIST = 0x3FFE,   /* listIndex = arg, restart */
    BBACT_CMD_END      = 0x3FFF    /* stop advancing */
};

/* One billboard instance (0x28 bytes) with its animation playback state. */
struct BbActEntry {
    u32 elemId;                    /* 0x00: board element id, 0xFFFF: free */
    u16 slotIndex;                 /* 0x04 */
    u16 pad06;
    struct BbActCmd **cmdLists;    /* 0x08: array of command lists */
    u16 listCount;                 /* 0x0C */
    u16 listIndex;                 /* 0x0E: list being played */
    u16 cursor;                    /* 0x10: next command in the list */
    u16 waitFrames;                /* 0x12 */
    u16 loopCount;                 /* 0x14 */
    u16 pad16;
    u32 enabled;                   /* 0x18: playback runs only when nonzero */
    u16 lastCommand;               /* 0x1C: frame field of the last command read */
    u16 pad1E;
    BbActEntryHook hook;           /* 0x20: called every update when set */
    void *hookArg;                 /* 0x24 */
};

/* Creation record for one entry (0x24 bytes). */
/* The billboard_act system object (0x24 bytes). */
struct BbActSys {
    u16 heapId;                    /* 0x00 */
    u16 pad02;
    struct BbBoard *board;         /* 0x04 */
    BbActUploadFn uploadFn;        /* 0x08 */
    struct BbActSlot *slots;       /* 0x0C */
    u16 slotCount;                 /* 0x10 */
    u16 pad12;
    struct AreaMan *slotPool;      /* 0x14 */
    struct BbActEntry *entries;    /* 0x18 */
    u16 entryCount;                /* 0x1C */
    u16 pad1E;
    struct AreaMan *entryPool;     /* 0x20 */
};

typedef int (*BbActControlFn)(struct BbActEntry *entry, struct BbActCmd *cmd);

#include "nns_g3d_anm_calc_types.h"
#include "nns_g3d_anm_types.h"
#include "../sdk_nnsfnd.h"
#include "gfl_heap_wrap.h"

#ifdef __MWERKS__
extern void *BILLBOARD_Create(u8 *src, u32 heap);
#else
#include "billboard.h"
#endif

#ifdef __MWERKS__
extern struct AreaMan *AREAMAN_Create(u32 size, u32 heapId);
#else
#include "areaman.h"
#endif

#ifdef __MWERKS__
extern u16  BILLBOARD_AddImage(struct BbBoard *board, u32 resource, u32 format, u32 sizeS, u8 sizeT, u8 paletteId); /* original prototype; the definition differs in argument sign, argument width, pointer or integer, pointer type, return type */
#endif
struct G3dResource;

#include "g3d_system.h"

#ifdef __MWERKS__
extern int AREAMAN_Free(struct AreaMan *pool, u32 start, s32 count); /* original prototype; the definition differs in return type */
extern s32  BILLBOARD_AddElem(struct BbBoard *board, u32 boardId, s16 width, s16 height, const VecFx32 *pos, u8 layer, u32 color, u32 mode); /* original prototype; the definition differs in argument sign, argument width, pointer or integer, pointer type, return type */
extern int BILLBOARD_SetElemVisible(struct BbBoard *board, u32 elemId, const u32 *flags); /* original prototype; the definition differs in argument sign, argument width, pointer or integer, pointer type, return type */
extern u32 BILLBOARD_GetImagePlttVramOffset(struct BbBoard *board, u16 boardId, u32 *palDst); /* original prototype; the definition differs in argument sign, argument width, pointer or integer, pointer type, return type */
#endif
struct LightSlot;
struct Camera;
struct G3dCamera;


struct BbActSys *BILLBOARD_ACT_Create(u16 slotCount, u16 entryCount, BbActUploadFn uploadFn, int heapId);

void BILLBOARD_ACT_Delete(struct BbActSys *sys);

struct BbBoard *BILLBOARD_ACT_GetBoard(struct BbActSys *sys);

void BILLBOARD_ACT_InitSlot(struct BbActSlot *slot);

void BILLBOARD_ACT_ResetPlayback(struct BbActEntry *entry);

void BILLBOARD_ACT_InitEntry(struct BbActEntry *entry);

u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *sys, const struct BbActRec *recs, u32 count);

u32 BILLBOARD_ACT_AddSlot(struct BbActSys *sys, u32 boardId, struct G3dResource *payload);

void BILLBOARD_ACT_DeleteSlots(struct BbActSys *sys, u32 first, u32 count);

int BILLBOARD_ACT_DeleteSlot(struct BbActSys *sys, u32 slot);

u16 BILLBOARD_ACT_GetSlotBoardId(struct BbActSys *sys, int slotIndex);

u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *sys, u16 baseSlot, const struct BbActDesc *descs, u32 count, u32 mode);

void BILLBOARD_ACT_DeleteEntries(struct BbActSys *sys, u16 first, u32 count);

void BILLBOARD_ACT_UpdateEntries(struct BbActSys *sys);

void BILLBOARD_ACT_UpdateEntry(struct BbActSys *sys, struct BbActEntry *entry);

void BILLBOARD_ACT_UploadSlotFrame(struct BbActSys *sys, struct BbActSlot *slot, u32 frame);

u32 BILLBOARD_ACT_UploadSlotPalette(struct BbActSys *sys, struct BbActSlot *slot);

void BILLBOARD_ACT_Draw(struct BbActSys *sys, void *camera, void *light);

int BILLBOARD_ACT_SetEntryFlags(struct BbActSys *sys, int entryIndex, u32 flags);

int BILLBOARD_ACT_GetEntryFlags(struct BbActSys *sys, u16 entryIndex);

void BILLBOARD_ACT_SetEntryEnabled(struct BbActSys *sys, int entryIndex, u32 enabled);

void BILLBOARD_ACT_SetEntryCommands(struct BbActSys *sys, int entryIndex, struct BbActCmd **cmdLists, u16 listCount);

void BILLBOARD_ACT_SetEntryList(struct BbActSys *sys, int entryIndex, u32 listIndex);

u16 BILLBOARD_ACT_GetEntryList(struct BbActSys *sys, int entryIndex);

void BILLBOARD_ACT_SetEntryCursor(struct BbActSys *sys, int entryIndex, u32 cursor);

u16 BILLBOARD_ACT_GetEntryCursor(struct BbActSys *sys, int entryIndex);

int BILLBOARD_ACT_SetEntryPaletteFromSlot(struct BbActSys *sys, int entryIndex, int srcSlot);

int BILLBOARD_ACT_GetEntryElemId(struct BbActSys *sys, u16 entryIndex);

u32 BILLBOARD_ACT_GetEntrySlotIndex(struct BbActSys *sys, u32 entryIndex);

u32 BILLBOARD_ACT_GetEntryLastCommand(struct BbActSys *sys, int entryIndex, u16 *lastCommand);

int BILLBOARD_ACT_IsControlCommand(struct BbActCmd *cmd);

int BILLBOARD_ACT_RunControlCommand(struct BbActEntry *entry, struct BbActCmd *cmd);

BbActControlFn BILLBOARD_ACT_GetControlHandler(u32 id);

int BILLBOARD_ACT_CmdEnd(struct BbActEntry *entry, struct BbActCmd *cmd);

int BILLBOARD_ACT_CmdSetList(struct BbActEntry *entry, struct BbActCmd *cmd);

int BILLBOARD_ACT_CmdLoop(struct BbActEntry *entry, struct BbActCmd *cmd);

int BILLBOARD_ACT_CmdJump(struct BbActEntry *entry, struct BbActCmd *cmd);

extern const char sBillboardAct[];

extern const struct BbActBoardInit gBillboardActTpl;

/*
 * The billboard_act.c system constructor, and the function that NAMES the
 * family: its __FILE__ word at 0x0204FFF4 is 0x020A7FB0, and
 * layout/file_anchors.txt fixes the string there as "billboard_act.c" (the NUL
 * of "billboard.c" at 0x020A7FAF is what pins its start).  Three allocations,
 * at source lines 94, 119 and 123, monotone in address -- the second,
 * independent check that this is one original translation unit.
 *
 * Allocate the 0x24-byte system object, stamp in the caller's heap id, the
 * two counts and the upload callback, build the sub-board by copying a 28-byte
 * template out of rodata onto the stack and overwriting its first two
 * halfwords with the two counts, then allocate the two parallel arrays (the
 * slotCount * 8 slot array and the entryCount * 0x28 entry array) with their two
 * index pools, and finally run the per-element initialisers over both.
 *
 * Three shapes are load-bearing:
 *
 *   - The 28-byte template is ONE aggregate assignment from a rodata object
 *     into a `struct BbActBoardInit` LOCAL, which mwcc expands to a 16-byte ldm/stm
 *     pair with write-back plus a 12-byte pair without, reusing the bases the
 *     write-back left in sl and sb (the same expansion as the sibling
 *     constructor BILLBOARD_Create, src/matched/BILLBOARD_Create.c).  A byte array
 *     or a memcpy compiles to a copy loop instead.
 *   - The two counts are patched into the first two fields of the local,
 *     re-reading sys->slotCount and sys->entryCount rather than reusing the
 *     incoming parameters: the image issues `ldrh r2, [r6, #0x10]` and
 *     `ldrh r2, [r6, #0x1c]` between the stm and the call, which the
 *     parameters would not produce.
 *   - Both element loops use SEPARATE counters (`i` and `j`) and re-read
 *     their bound from the object at the bottom of the loop; the compare is
 *     signed (`blt`) on the promoted u16, so the counters are plain `int`.
 *
 * The template at 0x020A155C is attested `sole-ref` (its only referrer image
 * wide is this function's own pool word at 0x0204FFF8); the file string is
 * attested `string`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_Create.c \
 *       --func BILLBOARD_ACT_Create --addr 0x0204FE94 --cc 1.1p1 --arm
 *   EXACT, 360 bytes, 10 relocation sites, all resolved.
 */
struct BbActSys *BILLBOARD_ACT_Create(u16 slotCount, u16 entryCount, BbActUploadFn uploadFn, int heapId)
{
    const char *file = sBillboardAct;
    struct BbActSys *sys;
    struct BbActBoardInit init;
    int i;
    int j;

    sys = GFL_HEAP_Alloc(heapId, sizeof(*sys), 1, file, 94);
    sys->heapId = (u16)heapId;
    sys->uploadFn = uploadFn;
    sys->slotCount = slotCount;
    sys->entryCount = entryCount;

    init = gBillboardActTpl;
    init.slotCount = sys->slotCount;
    init.entryCount = sys->entryCount;
    sys->board = BILLBOARD_Create((u8 *)(&init), heapId);

    sys->slots = GFL_HEAP_Alloc(heapId, sys->slotCount * sizeof(*sys->slots), 1, file, 119);
    sys->slotPool = AREAMAN_Create(sys->slotCount, heapId);
    sys->entries = GFL_HEAP_Alloc(heapId, sys->entryCount * sizeof(*sys->entries), 1, file, 123);
    sys->entryPool = AREAMAN_Create(sys->entryCount, heapId);

    for (i = 0; i < sys->slotCount; i++) {
        BILLBOARD_ACT_InitSlot(&sys->slots[i]);
    }
    for (j = 0; j < sys->entryCount; j++) {
        BILLBOARD_ACT_InitEntry(&sys->entries[j]);
    }
    return sys;
}

/*
 * billboard_act.c teardown.  The two-byte residue of the earlier notes
 * (the loaded entry word landing in r0 instead of r1) was the callee's
 * arity: BILLBOARD_FreeElem takes TWO arguments, and the second is the entry's
 * first word, which the image loads straight into r1 for the compare and
 * then passes on.  EXACT* because the unlabelled 8-byte getter at
 * 0x02050080 (`ldr r0,[r0,#4]; bx lr`, blx'd from ov021) follows the pool.
 */
void BILLBOARD_ACT_Delete(struct BbActSys *sys)
{
    int i;

    for (i = 0; i < sys->entryCount; i++) {
        if (sys->entries[i].elemId != 0xFFFF) {
            BILLBOARD_FreeElem(sys->board, sys->entries[i].elemId);
        }
    }
    AREAMAN_Delete(sys->entryPool);
    GFL_HEAP_Free(sys->entries);
    AREAMAN_Delete(sys->slotPool);
    GFL_HEAP_Free(sys->slots);
    BILLBOARD_Delete(sys->board);
    GFL_HEAP_Free(sys);
}

/*
 * The disassembly puts a function label on this getter's final `bx lr`; nothing
 * calls that address and the bytes are this function's own return, so it is not
 * a separate function.
 */
struct BbBoard *BILLBOARD_ACT_GetBoard(struct BbActSys *sys)
{
    return sys->board;
}

void BILLBOARD_ACT_InitSlot(struct BbActSlot *slot)
{
    slot->boardId = 0xFFFF;
    slot->payload = 0;
}

void BILLBOARD_ACT_ResetPlayback(struct BbActEntry *entry)
{
    entry->cursor = 0;
    entry->waitFrames = 0;
    entry->loopCount = 0;
    entry->lastCommand = 0;
}

/*
 * Second of the three 0x0204F6xx-series object initialisers; the eight bytes
 * of literal pool at 0x020500EC (0x0000FFFF) are this function's own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_InitEntry.c \
 *       --func BILLBOARD_ACT_InitEntry --addr 0x020500B8 --cc 1.1p1 --arm
 */
void BILLBOARD_ACT_InitEntry(struct BbActEntry *entry)
{
    entry->elemId = 0xFFFF;
    entry->cmdLists = 0;
    entry->listCount = 0;
    entry->listIndex = 0;
    BILLBOARD_ACT_ResetPlayback(entry);
    entry->enabled = 0;
    entry->hook = 0;
    entry->hookArg = 0;
}

/*
 * billboard_act.c: take n slot indices from the pool at +0x14 and fill one
 * slot record per request (0: board slot, 1: board slot plus BILLBOARD_TrimImageResource,
 * 2: an external payload word with the 0xFFFF sentinel id).  The 28-byte
 * scheduling wall of the earlier notes was the missing `const` on the
 * request array (its byte loads then batch ahead of the outgoing-argument
 * stores, and case 2's payload load hoists above the sentinel store); with
 * it the plain subscript sys->slots[base + i] and literal zeros are exact.
 */
u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *sys, const struct BbActRec *recs, u32 count)
{
    int base;
    u32 i;

    base = AREAMAN_Alloc(sys->slotPool, count);
    for (i = 0; i < count; i++) {
        const struct BbActRec *rec = &recs[i];
        u16 id;
        switch (rec->kind) {
        case 0:
#ifdef __MWERKS__
            sys->slots[base + i].boardId = BILLBOARD_AddImage(sys->board, rec->resource, rec->format, rec->sizeS, rec->sizeT, rec->paletteId);
#else
            sys->slots[base + i].boardId = BILLBOARD_AddImage(sys->board, (struct G3dResource *)rec->resource, rec->format, rec->sizeS, rec->sizeT, rec->paletteId);
#endif
            sys->slots[base + i].payload = 0;
            break;
        case 1:
#ifdef __MWERKS__
            id = BILLBOARD_AddImage(sys->board, rec->resource, rec->format, rec->sizeS, rec->sizeT, rec->paletteId);
#else
            id = BILLBOARD_AddImage(sys->board, (struct G3dResource *)rec->resource, rec->format, rec->sizeS, rec->sizeT, rec->paletteId);
#endif
            BILLBOARD_TrimImageResource(sys->board, id);
            sys->slots[base + i].boardId = id;
            sys->slots[base + i].payload = 0;
            break;
        case 2:
            sys->slots[base + i].boardId = 0xFFFF;
            sys->slots[base + i].payload = (struct G3dResource *)rec->resource;
            break;
        }
    }
    return base;
}

/*
 * Appends one {u16, u32} record (8 bytes, id in the low half) to the array
 * the caller's object keeps at +12, at the slot AREAMAN_Alloc hands back for
 * the pool at +20; the return is the slot narrowed to u16.
 *
 * The four bytes that cost three attempts are the first store's register
 * pairing: the pointer form `*(u16 *)(*(u32 *)((char *)p + 12) + idx * 8)`
 * compiles the same two instructions as the original but allocates them the
 * other way round (`ldr r1,[r6,#12]; lsl r2,r0,#3; strh r5,[r1,r2]` against
 * the original's r2/r1), a whole-function DIFF at +001C.  Written as an
 * array subscript on an 8-byte struct element,
 * `((struct BbActSlot *)*(u32 *)((char *)p + 12))[idx].h`, it comes out EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_AddSlot.c \
 *       --func BILLBOARD_ACT_AddSlot --addr 0x02050238 --cc 1.1p1 --arm
 *   EXACT, 64 bytes, 1 relocation site, resolved [label].
 */
u32 BILLBOARD_ACT_AddSlot(struct BbActSys *sys, u32 boardId, struct G3dResource *payload)
{
    int index = AREAMAN_Alloc(sys->slotPool, 1);

    sys->slots[index].boardId = boardId;
    sys->slots[index].payload = payload;
    return (u16)index;
}

/*
 * billboard_act.c: release `count` slot records from `first`: the board
 * record through BILLBOARD_DeleteImage(board, id) when the id is live, the payload
 * through G3D_SYSTEM_DeleteResource when nonzero, then reset the record and return the
 * index range to the pool.  BILLBOARD_DeleteImage takes TWO arguments (the loaded
 * id is the r1 the image compares); the rest is plain subscripts.
 */
void BILLBOARD_ACT_DeleteSlots(struct BbActSys *sys, u32 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++) {
        if (sys->slots[first + i].boardId != 0xFFFF) {
            BILLBOARD_DeleteImage(sys->board, sys->slots[first + i].boardId);
        }
        if (sys->slots[first + i].payload != 0) {
            G3D_SYSTEM_DeleteResource(sys->slots[first + i].payload);
        }
        BILLBOARD_ACT_InitSlot(&sys->slots[first + i]);
    }
    AREAMAN_Free(sys->slotPool, first, count);
}

int BILLBOARD_ACT_DeleteSlot(struct BbActSys *sys, u32 slot)
{
    BILLBOARD_ACT_InitSlot(&sys->slots[slot]);
#ifdef __MWERKS__
    return AREAMAN_Free(sys->slotPool, slot, 1);
#else
    /* the definition returns void; the DS caller returns whatever r0 holds */
    AREAMAN_Free(sys->slotPool, slot, 1);
    return 0;
#endif
}

u16 BILLBOARD_ACT_GetSlotBoardId(struct BbActSys *sys, int slotIndex)
{
    return sys->slots[slotIndex].boardId;
}

/*
 * billboard_act.c: take `count` consecutive entry indices from the pool at
 * +0x20 and build one board element per 0x24-byte descriptor through
 * BILLBOARD_AddElem, returning the first index (0xFFFF when the pool is full).
 * Levers, all measured: the descriptor array is `const` (its field loads
 * then move above the entry stores, 62 -> 15 bytes); the element id is a
 * named local passed on to BILLBOARD_SetElemVisible rather than re-read; the caller's
 * view of BILLBOARD_AddElem takes s16 v12/v14 (ldrsh, no narrowing); all five
 * locals at function scope in the order p, e, idx, i, r (loop-scoped e/p
 * swap the i and p registers).
 */
u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *sys, u16 baseSlot, const struct BbActDesc *descs, u32 count, u32 mode)
{
    const struct BbActDesc *desc;
    struct BbActEntry *entry;
    int first;
    u32 i;
    s32 elemId;

    first = AREAMAN_Alloc(sys->entryPool, count);
    if (first == -1) {
        return 0xFFFF;
    }
    for (i = 0; i < count; i++) {
        entry = &sys->entries[first + i];
        desc = &descs[i];

        BILLBOARD_ACT_InitEntry(entry);
        entry->slotIndex = baseSlot + desc->slot;
        elemId = BILLBOARD_AddElem(sys->board, sys->slots[entry->slotIndex].boardId, desc->width, desc->height, &desc->pos, desc->layer, desc->color, mode);
        entry->elemId = elemId;
        entry->hook = desc->hook;
        entry->hookArg = desc->hookArg;
        BILLBOARD_SetElemVisible(sys->board, elemId, &desc->flags);
        entry->lastCommand = 0x3FFF;
    }
    return first;
}

/*
 * billboard_act.c: release `count` entries from `first` and give the index
 * range back to the pool.  The earlier 2-byte floor (add operand order) and
 * the hand-copied stride came from writing the address arithmetic by hand;
 * the source is plain subscripts, sys->entries[first + i], in a for loop.
 */
void BILLBOARD_ACT_DeleteEntries(struct BbActSys *sys, u16 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++) {
        BILLBOARD_FreeElem(sys->board, sys->entries[first + i].elemId);
        BILLBOARD_ACT_InitEntry(&sys->entries[first + i]);
    }
    AREAMAN_Free(sys->entryPool, first, count);
}

/*
 * Tick every live entry of sys->entries (0x28 bytes each): for each index
 * below the live count sys->entryCount, skip the entry whose first word is the
 * sentinel 0xFFFF, otherwise call its per-entry hook (a function pointer at
 * +0x20, taking the owner, the index and the entry's +0x24 word) when one is
 * installed, then hand the entry to BILLBOARD_ACT_UpdateEntry.
 *
 * Two shapes are load-bearing:
 *
 *   - The live count is re-read from sys->entryCount at the BOTTOM of the loop
 *     (`ldrh r0, [r5, #0x1c]` at +0x60) as well as at the top, because the
 *     hook and BILLBOARD_ACT_UpdateEntry may both change it.  Caching it in a local gives
 *     one load and a different loop shape.
 *   - The count is a u16 but the comparison is SIGNED (`blt`, and `pople` on
 *     the entry guard), so the index is a plain `int` and the count is
 *     promoted, not an unsigned compare.
 *
 * The 0xFFFF sentinel lives in the pool at 0x0205054C rather than as an
 * immediate, which is why r7 is loaded once before the loop.
 *
 * UNBLOCKED 2026-09-21: BILLBOARD_ACT_UpdateEntry was filed EXACT
 * (src/matched/BILLBOARD_ACT_UpdateEntry.c, shard arm9/pkt_02050340.json), so the single
 * relocation site, the `bl` at +0x5C, is now attested `matched` and this file
 * verifies EXACT unchanged.  No C was altered to promote it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_UpdateEntries.c \
 *       --func BILLBOARD_ACT_UpdateEntries --addr 0x020504D8 --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void BILLBOARD_ACT_UpdateEntries(struct BbActSys *sys)
{
    int i = 0;
    int n = sys->entryCount;

    if (n <= 0) {
        return;
    }
    do {
            struct BbActEntry *entry = &sys->entries[i];

            if (entry->elemId != 0xFFFF) {
                if (entry->hook != 0) {
                    entry->hook(sys, i, entry->hookArg);
                }
                BILLBOARD_ACT_UpdateEntry(sys, entry);
            }
        i++;
    } while (i < sys->entryCount);
}

void BILLBOARD_ACT_UpdateEntry(struct BbActSys *sys, struct BbActEntry *entry)
{
    struct BbActCmd *cmd;
    u32  flipXValue;
    u32  flipYValue;
    u16  frame;
    u16  duration;
    struct BbActSlot *slot;

    if (entry->cmdLists == 0 || entry->enabled == 0) {
        return;
    }
    if (entry->waitFrames != 0) {
        entry->waitFrames = entry->waitFrames - 1;
        return;
    }

    cmd = &entry->cmdLists[entry->listIndex][entry->cursor];
    while (BILLBOARD_ACT_IsControlCommand(cmd)) {
        if (BILLBOARD_ACT_RunControlCommand(entry, cmd)) {
            return;
        }
        cmd = &entry->cmdLists[entry->listIndex][entry->cursor];
    }

    entry->cursor = entry->cursor + 1;
    frame = cmd->frame;
    duration = cmd->arg;

#ifdef __MWERKS__
    slot = (struct BbActSlot *)((entry->slotIndex << 3) + (uptr)sys->slots);
#else
    slot = &sys->slots[entry->slotIndex];
#endif
    if (slot->payload != 0) {
        BILLBOARD_ACT_UploadSlotFrame(sys, slot, frame);
    } else {
        BILLBOARD_SetElemCell(sys->board, entry->elemId, &frame);
    }

    if (cmd->flipX) {
        flipXValue = 1;
    } else {
        flipXValue = 0;
    }
    if (cmd->flipY) {
        flipYValue = 1;
    } else {
        flipYValue = 0;
    }

    BILLBOARD_SetElemFlipS(sys->board, entry->elemId, &flipXValue);
    BILLBOARD_SetElemFlipT(sys->board, entry->elemId, &flipYValue);

    if (duration != 0) {
        duration = duration - 1;
    }
    entry->waitFrames = duration;
}

void BILLBOARD_ACT_UploadSlotFrame(struct BbActSys *sys, struct BbActSlot *slot, u32 frame)
{
    u32 texDst;
    u32 frameOffset;
    u32 frameSize;
    u32 payloadBase;
    u32 zero;

    payloadBase = (uptr)G3D_SYSTEM_GetTexDataAddr(slot->payload);
    BILLBOARD_GetImageVramAddr(sys->board, slot->boardId, (s32 *)(&texDst));
    zero = 0;
    BILLBOARD_CalcImageFrameRange(sys->board, slot->boardId, frame, (s32 *)(&frameOffset), (s32 *)(&frameSize), zero);
    if (sys->uploadFn != 0) {
        sys->uploadFn(zero, texDst, payloadBase + frameOffset, frameSize);
    }
}

/*
 * An 88-byte ARM function in the 0x02050000 block.  It reads a record index
 * out of the object at +4, resolves it through G3D_SYSTEM_GetPlttDataAddr, then calls
 * BILLBOARD_GetImagePlttVramOffset with the object's word at +4, the halfword at q[0] and a
 * stack scratch slot; when the hook pointer at p+8 is non-null it calls the
 * hook with the scratch value and the resolved record.  The null case returns
 * the BILLBOARD_GetImagePlttVramOffset result, which is why the `cmp ip, #0` sits after the
 * second call with r0 still live.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_UploadSlotPalette.c \
 *       --func BILLBOARD_ACT_UploadSlotPalette --addr 0x02050738 --cc 1.1p1 --arm
 */
u32 BILLBOARD_ACT_UploadSlotPalette(struct BbActSys *sys, struct BbActSlot *slot)
{
    u32 paletteSrc = (uptr)G3D_SYSTEM_GetPlttDataAddr(slot->payload);
    u32 paletteDst;
    u32 result = BILLBOARD_GetImagePlttVramOffset(sys->board, slot->boardId, &paletteDst);
    BbActUploadFn uploadFn = sys->uploadFn;

    if (uploadFn == 0)
        return result;
    return uploadFn(1, paletteDst, paletteSrc, 0x20);
}

/*
 * Draws the system's board. The camera and light arguments are unused here (fieldmap.c passes
 * them); the bytes equal DWCi_LSTlPopFront in libdwcutil, which once made the SDK scan class it
 * as that list function.
 */
void BILLBOARD_ACT_Draw(struct BbActSys *sys, void *camera, void *light)
{
    BILLBOARD_Draw(sys->board, camera, light);
}

/*
 * The listing labels this function at 0x020507A4, not 0x020507A0: disasm.py
 * only auto-labels a prologue that saves lr, so the four bytes at 0x020507A0
 * that home the four argument registers (`push {r0,r1,r2,r3}`, the tell for
 * an address-taken register parameter,
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md) are
 * printed as a stray `.word` and the label lands on the `push {r3, lr}` four
 * bytes later.  The real entry is 0x020507A0 and the function is 48 bytes,
 * not the worklist's 44; verified from 0x020507A0, where the extent runs to
 * the next label at 0x020507D0.
 *
 * The third parameter is not a pointer but a scalar whose address is taken
 * (`&x`, compiled as the home slot).  Written as `u8 *buf` it compiles to 32
 * bytes; as `u8 buf[16]`, 32; only `&x` on a scalar reproduces the home push.
 *
 * Reads element `idx` of a 40-byte record array hanging off p+24 and hands it,
 * together with p's own word at +4 and the caller's buffer address, to
 * BILLBOARD_SetElemVisible.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryFlags.c \
 *       --func BILLBOARD_ACT_SetEntryFlags --addr 0x020507A0 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_SetEntryFlags(struct BbActSys *sys, int entryIndex, u32 flags)
{
#ifdef __MWERKS__
    return BILLBOARD_SetElemVisible(sys->board,
                         sys->entries[entryIndex].elemId,
                         &flags);
#else
    /* the definition returns void; the DS caller returns whatever r0 holds */
    BILLBOARD_SetElemVisible(sys->board, sys->entries[entryIndex].elemId, &flags);
    return 0;
#endif
}

/*
 * Leaf witness for ov021 0x021BBF10 / 0x021BC138 (lane wA1-12).
 */
int BILLBOARD_ACT_GetEntryFlags(struct BbActSys *sys, u16 entryIndex)
{
    return BILLBOARD_GetElemVisible(sys->board, sys->entries[entryIndex].elemId);
}

void BILLBOARD_ACT_SetEntryEnabled(struct BbActSys *sys, int entryIndex, u32 enabled)
{
    struct BbActEntry *entry = &sys->entries[entryIndex];
    entry->enabled = enabled;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryCommands.c \
 *       --func BILLBOARD_ACT_SetEntryCommands --addr 0x02050804 --cc 1.1p1 --arm
 */
void BILLBOARD_ACT_SetEntryCommands(struct BbActSys *sys, int entryIndex, struct BbActCmd **cmdLists, u16 listCount)
{
    struct BbActEntry *entry = &sys->entries[entryIndex];

    entry->cmdLists = cmdLists;
    entry->listCount = listCount;
    entry->listIndex = 0;
    BILLBOARD_ACT_ResetPlayback(entry);
}

void BILLBOARD_ACT_SetEntryList(struct BbActSys *sys, int entryIndex, u32 listIndex)
{
    struct BbActEntry *entry = &sys->entries[entryIndex];
    entry->listIndex = listIndex;
    BILLBOARD_ACT_ResetPlayback(entry);
}

/*
 * Leaf witness for ov021 0x0219F058 and siblings (lane wA1-06).
 */
u16 BILLBOARD_ACT_GetEntryList(struct BbActSys *sys, int entryIndex)
{
    return sys->entries[entryIndex].listIndex;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryCursor.c \
 *       --func BILLBOARD_ACT_SetEntryCursor --addr 0x0205085C --cc 1.1p1 --arm
 */
void BILLBOARD_ACT_SetEntryCursor(struct BbActSys *sys, int entryIndex, u32 cursor)
{
    struct BbActEntry *entry = &sys->entries[entryIndex];

    BILLBOARD_ACT_ResetPlayback(entry);
    entry->cursor = cursor;
}

u16 BILLBOARD_ACT_GetEntryCursor(struct BbActSys *sys, int entryIndex)
{
    return sys->entries[entryIndex].cursor;
}

/*
 * PROMOTED from src/pending/BILLBOARD_ACT_SetEntryPaletteFromSlot.c: it was parked at MATCH because
 * the only branch in the image to 0x02050738 is the one inside this function.
 * 0x02050738 (88 bytes, pkt_02050340) is now matched, so the site resolves by
 * the `matched` class with no change to the C.  The file's packet id is
 * corrected from pkt_02050340 to pkt_02050894, which is the packet the
 * worklist gives 0x02050894.
 *
 * Moves one word between two parallel record arrays of the object: the index
 * is read out of the 40-byte record table at p+24, the value out of the
 * 8-byte-pair array at p+12, the value is stored back into the record the
 * index names, and the record is handed to BILLBOARD_ACT_UploadSlotPalette.
 *
 * The listing's extent runs 140 bytes because the follower at 0x020508C4 is an
 * unlabelled leaf accessor (no prologue that saves lr).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryPaletteFromSlot.c \
 *       --func BILLBOARD_ACT_SetEntryPaletteFromSlot --addr 0x02050894 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_SetEntryPaletteFromSlot(struct BbActSys *sys, int entryIndex, int srcSlot)
{
    struct BbActSlot *slots = sys->slots;
    struct BbActEntry *entries = sys->entries;
    u16 dstSlot = entries[entryIndex].slotIndex;
    struct G3dResource *payload = slots[srcSlot].payload;

    slots[dstSlot].payload = payload;
    return BILLBOARD_ACT_UploadSlotPalette(sys, &slots[dstSlot]);
}

int BILLBOARD_ACT_GetEntryElemId(struct BbActSys *sys, u16 entryIndex)
{
    return sys->entries[entryIndex].elemId;
}

u32 BILLBOARD_ACT_GetEntrySlotIndex(struct BbActSys *sys, u32 entryIndex)
{
    return sys->entries[entryIndex].slotIndex;
}

u32 BILLBOARD_ACT_GetEntryLastCommand(struct BbActSys *sys, int entryIndex, u16 *lastCommand)
{
    u16 value = sys->entries[entryIndex].lastCommand;
    *lastCommand = value;
    /* true for BBACT_CMD_JUMP..BBACT_CMD_END; the range test must stay in this form */
    return (u16)(value + 4 + 0xC000) <= 3;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_IsControlCommand.c \
 *       --func BILLBOARD_ACT_IsControlCommand --addr 0x02050920 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_IsControlCommand(struct BbActCmd *cmd)
{
    return BILLBOARD_ACT_GetControlHandler(cmd->frame) != 0;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_RunControlCommand.c \
 *       --func BILLBOARD_ACT_RunControlCommand --addr 0x02050944 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_RunControlCommand(struct BbActEntry *entry, struct BbActCmd *cmd)
{
    BbActControlFn handler;

    handler = BILLBOARD_ACT_GetControlHandler(cmd->frame);
    entry->lastCommand = cmd->frame;
    return handler(entry, cmd);
}

/*
 * PROMOTED from src/pending/BILLBOARD_ACT_GetControlHandler.c 2026-09-21 (wave 4, billboard_act).
 * The C is UNCHANGED: it was parked at MATCH* because three of its four ABS32
 * pool words -- 0x020509E0, 0x02050A00 and 0x02050A58 -- each had exactly one
 * mention image wide, the pool word inside this very function, so neither
 * `label` nor `literal` reached them.  All three handlers are now filed EXACT
 * (src/matched/BILLBOARD_ACT_CmdEnd.c, BILLBOARD_ACT_CmdLoop.c, BILLBOARD_ACT_CmdJump.c, shard
 * arm9/pkt_02050984.json), so every site resolves by the `matched` class and
 * this file verifies EXACT* with no edit to the body.
 *
 * EXACT*, not EXACT: the listing's extent runs 100 bytes because the follower
 * at 0x020509E0 is reached only through this function's own pool word and has
 * no prologue that saves lr, so disasm.py does not label it.  Report
 * 0x020509E0 as a seed for layout/function_starts.txt; it is never a byte
 * difference.
 *
 * The switch normalises the id with two subtracts and no `mov` of the base,
 * which is the whole reason the case labels read 0x3FFC..0x3FFF: the image
 * subtracts 0x3FC and then 0x3C00, i.e. 0x3FFC, and spelling the cases
 * 0x43FC..0x43FF makes the second subtract `#0x4000` and the four case arms
 * come out in the wrong order.  Writing the cases in DESCENDING source order
 * is what reproduces the image's arm order (case 0x3FFF's arm nearest the
 * table); ascending order puts case 0x3FFC's arm there and differs in four
 * branch instructions.
 *
 * `return <function address>;` is the shape: each arm is `ldr r0, [pc, #n];
 * bx lr` and the fall-through is `mov r0, #0; bx lr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_GetControlHandler.c \
 *       --func BILLBOARD_ACT_GetControlHandler --addr 0x02050984 --cc 1.1p1 --arm
 */
BbActControlFn BILLBOARD_ACT_GetControlHandler(u32 id)
{
    switch (id) {
    case BBACT_CMD_END:      return BILLBOARD_ACT_CmdEnd;
    case BBACT_CMD_SET_LIST: return BILLBOARD_ACT_CmdSetList;
    case BBACT_CMD_LOOP:     return BILLBOARD_ACT_CmdLoop;
    case BBACT_CMD_JUMP:     return BILLBOARD_ACT_CmdJump;
    }
    return 0;
}

/*
 * The second arm of the four-entry handler table BILLBOARD_ACT_GetControlHandler dispatches
 * through (its pool word at 0x020509D0).  Eight bytes, a leaf that returns the
 * nonzero constant the dispatch caller tests, and one of the pool words that
 * keeps src/pending/BILLBOARD_ACT_GetControlHandler.c wildcarded until it has an EXACT entry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_CmdEnd.c \
 *       --func BILLBOARD_ACT_CmdEnd --addr 0x020509E0 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_CmdEnd(struct BbActEntry *entry, struct BbActCmd *cmd)
{
    return 1;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_CmdSetList.c \
 *       --func BILLBOARD_ACT_CmdSetList --addr 0x020509E8 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_CmdSetList(struct BbActEntry *entry, struct BbActCmd *cmd)
{
    entry->listIndex = cmd->arg;
    BILLBOARD_ACT_ResetPlayback(entry);
    return 0;
}

/*
 * The third arm of the handler table BILLBOARD_ACT_GetControlHandler dispatches through (see
 * src/pending/BILLBOARD_ACT_GetControlHandler.c).  88 bytes, a leaf: the command halfword at
 * cmd->arg packs two bytes, a repeat count in the high half and a value in the
 * low half.  While the entry's repeat counter at +0x14 is below the count,
 * store the value at +0x10 and bump the counter; once it reaches the count,
 * reset the counter and advance +0x10 by one instead.  +0x12 is zeroed on
 * both paths.  Returns 0 (the "command consumed, keep going" verdict the
 * dispatcher in BILLBOARD_ACT_RunControlCommand tests).
 *
 * The comparison is SIGNED (`bge`), so both sides are promoted `int`s and the
 * counter is compared as an int, not as an unsigned halfword.
 *
 * Two shapes are load-bearing, both worth 8 bytes each:
 *
 *   - The high byte must land in a `u8` LOCAL, not be written inline in the
 *     comparison.  `if (n < ((v & 0xff00) >> 8 & 0xff))` lets mwcc fold the
 *     shift into the compare's shifter operand (`cmp r2, r1, asr #8`) and drop
 *     the redundant `and #0xff` entirely, losing the original's separate
 *     `asr r1,r1,#8` / `and r1,r1,#0xff` pair (80 bytes, 56 out).
 *   - The LOW byte must be extracted into its own local BEFORE the `if`, not
 *     spelled `v & 0xff` at its single use inside the taken arm.  The original
 *     issues `and r3, r3, #0xff` above the `bge`; written at the use it lands
 *     after it, which is the last 8 bytes (88 bytes, 8 out).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_CmdLoop.c \
 *       --func BILLBOARD_ACT_CmdLoop --addr 0x02050A00 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_CmdLoop(struct BbActEntry *entry, struct BbActCmd *cmd)
{
    int operand = cmd->arg;
    int count = entry->loopCount;
    unsigned char repeats = (unsigned char)((operand & 0xff00) >> 8);
    unsigned char target = (unsigned char)operand;

    if (count < repeats) {
        entry->cursor = target;
        entry->waitFrames = 0;
        entry->loopCount = (u16)(count + 1);
    } else {
        int cursor = entry->cursor;
        entry->loopCount = 0;
        entry->waitFrames = 0;
        entry->cursor = (u16)(cursor + 1);
    }
    return 0;
}

/*
 * The fourth arm of the handler table BILLBOARD_ACT_GetControlHandler dispatches through (its
 * pool word at 0x02050980-ish; see src/pending/BILLBOARD_ACT_GetControlHandler.c).  Twenty
 * bytes, a leaf: it loads the command's second halfword (`cmd->arg`), zeroes the
 * entry's +0x12 counter, stores the halfword at +0x10 and returns 0.
 *
 * The zero is materialised once and reused for both the +0x12 store and the
 * return (`mov r1,#0 ... mov r0,r1`), which is what a single `0` constant
 * shared between the store and the `return 0;` produces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_CmdJump.c \
 *       --func BILLBOARD_ACT_CmdJump --addr 0x02050A58 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_CmdJump(struct BbActEntry *entry, struct BbActCmd *cmd)
{
    u16 target = cmd->arg;

    entry->waitFrames = 0;
    entry->cursor = target;
    return 0;
}
