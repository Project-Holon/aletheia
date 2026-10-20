#ifndef OV020_FIELD_WFBC_DATA_LOCAL_TYPES_H
#define OV020_FIELD_WFBC_DATA_LOCAL_TYPES_H

#include "../types.h"
#include "../sdk_fx.h"

/* One resident of White Forest or Black City (0x18 bytes). */
typedef struct WfbcPerson {
    u8 isPresent : 4;
    u8 hasParent : 4;
    u8 npcId;
    u8 mood; /* 0..100 */
    union {
        u8 all;
        struct {
            u8 arrival : 1;
            u8 talked : 1; /* mood +3 on the next daily update */
            u8 gift : 1;   /* mood +10 on the next daily update */
            u8 unused : 5;
        } bits;
    } flags;
    u16 parentName[8];
    u32 parentId;
} WfbcPerson;

/* Whole WFBC save block (0x1E8 bytes): ten residents and ten back-list residents. */
typedef struct WfbcData {
    u16 isValid;
    u16 cityType;
    u32 playerId;
    WfbcPerson people[10];
    WfbcPerson backPeople[10];
} WfbcData;

/* Two counters read and written by the WFBC script commands. */
typedef struct WfbcDailyState {
    u16 counter;
    u16 value;
} WfbcDailyState;

/* Static NPC record loaded from archive 0x9A (0x30 bytes). */
typedef struct WfbcNpcRecord {
    u16 objCode;
    u8 pad02[2];
    u16 initialMoodType1;
    u16 initialMoodType0;
    u16 speciesIds[3];  /* Pokemon the person can bring along */
    u8 pad0E[2];
    u8 levels[3];       /* 0x10: level of each species */
    u8 pad13;
    u8 weights[3];      /* 0x14: draw weight of each species */
    u8 pad17;
    int queryValue; /* returned by script query 0 (meaning unknown) */
    u16 eventIds[4];
    u16 giftItemId;
    u16 giftChance; /* percent */
    u16 listEntryId;
    u16 listEntryParam;
    u16 weight;
    u16 blockRandRange; /* summed over the present people into the block random range (ov021 field_wfbc.c) */
} WfbcNpcRecord;

/* Open handle of the NPC archive (0x38 bytes): archive, loaded file index, loaded record. */
typedef struct WfbcNpcData {
    struct ArcHandle *arc;
    int fileId;
    WfbcNpcRecord record;
} WfbcNpcData;

/* Grid cell of a person or an item on the town map. */
typedef struct WfbcPosition {
    u8 x;
    u8 z;
} WfbcPosition;

/* Entry of the people list screen (8 bytes). */
typedef struct WfbcListEntry {
    u16 entryId;
    u8 pad02[2];
    int param;
} WfbcListEntry;

#include "../ov010/fldmmdl_types.h"

struct GameSystem;
struct Mmdl;
struct MsgBank;
struct Strbuf;
struct WordSet;
struct FieldMsgHandle;
struct FieldYesNoHandle;
struct FieldWfbc;
struct FieldWfbcPeople;

/* Work of the person-talk event (0x58 bytes). */
typedef struct WfbcTalkEvent {
    struct GameSystem *gameSystem;
    void *fieldSystem;
    u16 heapId;
    u8 pad0A[2];
    struct FieldMsgBg *msgBgSys;
    struct FieldTalkWin *msgHandle;
    struct FieldMenuFunc *yesNoHandle;
    struct MsgBank *msgData;
    struct WordSet *wordSet;
    struct Strbuf *msgBuf;
    struct Strbuf *tmpBuf;
    struct FieldWfbc *wfbcRuntime;
    struct FieldWfbcPeople *personRecord;
    struct Mmdl *personMmdl;
    struct VecFx32 playerPos;
    void *returnList;
    WfbcData *ownData;
    WfbcData *cityData;
    u16 personIndex;
    u16 yesState;
    u16 noState;
    u16 msgState;
    u8 answerYes;
    u8 askYesNo;
    u8 firstTalk;
    u8 pad57;
} WfbcTalkEvent;

#endif
