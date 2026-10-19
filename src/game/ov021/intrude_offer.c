/*
 * file:     intrude_offer.c
 * unit:     yes
 * function: INTRUDE_FindOfferSlotAt, INTRUDE_TakeOfferSlot, INTRUDE_GetNextOfferSpot, INTRUDE_OfferEventMain, INTRUDE_StartOfferEvent
 * address:  0x021CFAC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): cut from enceff.c at 021CFAC0..021CFC4B: the INTRUDE_ offer slot module (prefix run of five functions, its own table gIntrudeOfferTilePositions 0x021DB834, no statics shared with the neighbours).
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   gIntrudeOfferTilePositions  0x021DB834  data  a4
 *   SCRIPT_SYS_ChangeScriptEvent  0x021587B0  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   STRBUF_SetStringN  0x02045994  arm
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 */
#include "enceff_shared_types.h"
#include "scrcmd_otid_shared_types.h"
#include "intrude_offer_shared_types.h"

typedef signed short s16;

struct Strbuf;

/* A gift left by an Entralink visitor, shown at a map spot (0x14 bytes). */
typedef struct IntrudeOfferSlot {
    u16 senderName[8];  /* 0x00 */
    u16 offerId;        /* 0x10: 0 for an empty slot */
    u8 spotIndex;       /* 0x12: row of the spot table */
    u8 reserved13;
} IntrudeOfferSlot;

#define INTRUDE_OFFER_SLOT_COUNT 20

typedef struct IntrudeOfferLog {
    u8 header[0x10];
    IntrudeOfferSlot slot[INTRUDE_OFFER_SLOT_COUNT];
} IntrudeOfferLog;

/* Where an offer waits: tile position and zone (8 bytes per row). */
typedef struct IntrudeOfferSpot {
    s16 x;
    s16 y;
    s16 z;
    u16 zoneId;
} IntrudeOfferSpot;

extern void *GAME_EVENT_GetWork(struct GameEvent *event);

extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, void *parent, void *func, u32 workSize);

extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
struct IntrudeSave;

extern struct IntrudeSave *INTRUDE_GetFromSave(struct SaveControl *saveControl);

extern void *SCRIPT_SYS_ChangeScriptEvent(void *event, unsigned short scriptId, void *target, int reserved);

extern int SCRIPT_WORK_SetParams(struct ScriptWork *scriptWork, int scriptParam0, int scriptParam1, int scriptParam2, u16 scriptParam3);

extern void *SCRIPT_WORK_GetWordSet(struct ScriptWork *scriptWork);

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_SetStringN(struct Strbuf *dest, const u16 *src, u32 length);

extern void STRBUF_Delete(struct Strbuf *str);

extern void WORDSET_SetSlotTag(struct WordSet *wordSet, u32 index, const struct Strbuf *src, u32 a, u32 b, u32 c);

extern const IntrudeOfferSpot gIntrudeOfferTilePositions[];

int INTRUDE_FindOfferSlotAt(IntrudeOfferLog *log, int zoneId, int x, int y, int z);

void INTRUDE_TakeOfferSlot(IntrudeOfferLog *log, int index, IntrudeOfferSlot *dest);

const IntrudeOfferSpot *INTRUDE_GetNextOfferSpot(IntrudeOfferLog *log, int *index);

int INTRUDE_OfferEventMain(struct GameEvent *event, u32 seq, const IntrudeOfferSlot *offer);

struct GameEvent *INTRUDE_StartOfferEvent(struct GameSystem *gameSystem, u32 heapId, int slotIndex);

/*
 * Searches the offer slots for one that waits at this zone and tile (the
 * height may be off by one). Returns the slot index, or 0xff.
 */
int INTRUDE_FindOfferSlotAt(IntrudeOfferLog *log, int zoneId, int x, int y, int z)
{
    int i;
    IntrudeOfferSlot *slot = log->slot;

    for (i = 0; i < INTRUDE_OFFER_SLOT_COUNT; i++, slot++) {
        const IntrudeOfferSpot *spot;
        if (slot->offerId == 0) {
            return 0xff;
        }
        spot = &gIntrudeOfferTilePositions[slot->spotIndex];
        if (spot->zoneId == zoneId && spot->x == x && spot->z == z && spot->y - 1 <= y && y <= spot->y + 1) {
            return i;
        }
    }
    return 0xff;
}

/* Copies offer slot i out and shifts the later slots down by one. */
void INTRUDE_TakeOfferSlot(IntrudeOfferLog *log, int index, IntrudeOfferSlot *dest)
{
    *dest = log->slot[index];
    for (index++; index < INTRUDE_OFFER_SLOT_COUNT; index++) {
        log->slot[index - 1] = log->slot[index];
    }
    log->slot[INTRUDE_OFFER_SLOT_COUNT - 1].offerId = 0;
}

/* Walks the slots from *index to the next used one and returns its spot row. */
const IntrudeOfferSpot *INTRUDE_GetNextOfferSpot(IntrudeOfferLog *log, int *index)
{
    int i = *index;

    if (i < INTRUDE_OFFER_SLOT_COUNT) {
        do {
            if (log->slot[i].offerId != 0) {
                const IntrudeOfferSpot *spot = &gIntrudeOfferTilePositions[log->slot[i].spotIndex];
                (*index)++;
                return spot;
            }
            i = ++*index;
        } while (i < INTRUDE_OFFER_SLOT_COUNT);
    }
    return 0;
}

/*
 * Event task: starts the offer script with the offer id as parameter and
 * registers the sender's name in word 3.
 */
int INTRUDE_OfferEventMain(struct GameEvent *event, u32 seq, const IntrudeOfferSlot *offer)
{
    IntrudeOfferSlot copy = *offer;
    struct ScriptWork *scriptWork;
    struct WordSet *wordSet;
    struct Strbuf *name;

    scriptWork = SCRIPT_SYS_ChangeScriptEvent(event, 0x0AFC, 0, 0x15);
    SCRIPT_WORK_SetParams(scriptWork, copy.offerId, 0, 0, 0);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    name = STRBUF_Create(8, 0x15);
    STRBUF_SetStringN(name, (const u16 *)&copy, 8);
    WORDSET_SetSlotTag(wordSet, 3, name, 1, 1, 2);
    STRBUF_Delete(name);
    return 0;
}

/* Takes offer slot slotIndex out of the log and starts the event task that shows it. */
struct GameEvent *INTRUDE_StartOfferEvent(struct GameSystem *gameSystem, u32 heapId, int slotIndex)
{
    struct GameEvent *taskEvent = GAME_EVENT_Create(gameSystem, 0, INTRUDE_OfferEventMain, 0x14);
    IntrudeOfferSlot *offer = GAME_EVENT_GetWork(taskEvent);

    INTRUDE_TakeOfferSlot((struct IntrudeOfferLog *)INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))), slotIndex, offer);
    return taskEvent;
}
