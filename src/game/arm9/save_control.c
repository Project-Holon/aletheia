/*
 * file:     save_control.c
 * unit:     yes
 * function: SAVE_CONTROL_Create, func_02007084, func_020070A4, SAVE_CONTROL_Reload, SAVE_CONTROL_StartSave, SAVE_CONTROL_MainSave, SAVE_CONTROL_CancelSave, SAVE_CONTROL_GetWrittenSize, SAVE_CONTROL_GetBlock, SAVE_CONTROL_GetWorkArea, SAVE_CONTROL_IsNewGame, func_020071E8, func_020071EC, func_020071F0, func_02007210, func_02007214, func_02007218, func_0200721C, func_02007220, func_02007230, func_0200723C, SAVE_CONTROL_ReadRecordFromFlash, SAVE_CONTROL_LoadExtraSave, SAVE_CONTROL_DeleteExtraSave, SAVE_CONTROL_LoadExtraSaveWithBuffer, SAVE_CONTROL_CreateExtraSaveWithBuffer, SAVE_CONTROL_DeleteExtraSaveBuffered, SAVE_CONTROL_BeginExtraSaveWrite, SAVE_CONTROL_StepExtraSaveWrite, SAVE_CONTROL_GetExtraSaveRecord, SAVE_CONTROL_EraseExtraSave, func_02007428, func_02007464, func_020074CC, func_020074D8, func_0200752C, BOX_SAVEDATA_SetPokemon, BOX_SAVEDATA_SwapPokemon, BOX_SAVEDATA_ClearPokemon, BOX_SAVEDATA_GetCurrentBox, BOX_SAVEDATA_GetUsableBoxCount, BOX_SAVEDATA_UnlockBoxes, BOX_SAVEDATA_FindFreeSlot, BOX_SAVEDATA_CountFreeSlots, func_020077B8, func_0200780C, func_0200781C, func_02007838, BOX_SAVEDATA_GetBoxName, BOX_SAVEDATA_SetBoxName, BOX_SAVEDATA_CountPokemonInBox, BOX_SAVEDATA_CountNonEggPokemonInBox, BOX_SAVEDATA_CountPokemon, BOX_SAVEDATA_CountNonEggPokemon, BOX_SAVEDATA_GetPokemonValue, BOX_SAVEDATA_GetPokemon, BOX_SAVEDATA_SetFlags, BOX_SAVEDATA_CheckFlags, BOX_SAVEDATA_GetBoxPageSize, BOX_SAVEDATA_CreateWordHolder, BOX_SAVEDATA_Delete, BOX_SAVEDATA_ClearBoxPage, BOX_SAVEDATA_GetBoxDataSize, BOX_SAVEDATA_GetBoxPokemon, PERAPVOICE_GetSize, PERAPVOICE_Init, PERAPVOICE_Create, PERAPVOICE_GetFromSave, PERAPVOICE_IsRecorded, PERAPVOICE_ClearRecorded, PERAPVOICE_SetRecorded, PERAPVOICE_GetSamples, PERAPVOICE_Unpack, PERAPVOICE_Pack, PERAPVOICE_Copy, PERAPVOICE_ClearIfNoChatot, PERAPVOICE_GetVoiceKind, MYITEM_SAVEDATA_GetSize, MYITEM_SAVEDATA_Init, MYITEM_SAVEDATA_CopyPocket, MYITEM_SAVEDATA_GetPocket, MYITEM_SAVEDATA_GetPocketOfItem, MYITEM_SAVEDATA_FindAddSlot, MYITEM_SAVEDATA_FindAddSlotForItem, MYITEM_SAVEDATA_CanAddItem, MYITEM_SAVEDATA_AddItem, MYITEM_SAVEDATA_FindRemoveSlot, MYITEM_SAVEDATA_FindItemSlot, MYITEM_SAVEDATA_RemoveItem, MYITEM_SAVEDATA_HasItem, MYITEM_SAVEDATA_CountUsedSlots, MYITEM_SAVEDATA_CountUsedSlotsInPocket, MYITEM_SAVEDATA_GetItemQuantity, MYITEM_SAVEDATA_SwapSlots, MYITEM_SAVEDATA_MoveLastUsedToFront, MYITEM_SAVEDATA_ClearEmptyQuantities, MYITEM_SAVEDATA_CompactPocket, MYITEM_SAVEDATA_SortPocketById, MYITEM_SAVEDATA_SortPocketByItemOrder, MYITEM_SAVEDATA_CompactAllPockets, MYITEM_SAVEDATA_GetSlot, MYITEM_SAVEDATA_GetMaxStack, MYITEM_SAVEDATA_CreateBagCursor, MYITEM_SAVEDATA_GetFieldPocketCursor, MYITEM_SAVEDATA_GetLastFieldPocket, MYITEM_SAVEDATA_SetFieldPocketCursor, MYITEM_SAVEDATA_SetLastFieldPocket, MYITEM_SAVEDATA_GetBattlePocketCursor, MYITEM_SAVEDATA_GetLastBattleItem, MYITEM_SAVEDATA_GetLastBattleItemPocket, MYITEM_SAVEDATA_SetBattlePocketCursors, MYITEM_SAVEDATA_SetLastBattleItem
 * address:  0x02006F20
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GF_OVERLAY_Load   0x02034AC4  arm
 *   GF_OVERLAY_Unload   0x02034A5C  arm
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   BACKUP_SYSTEM_Create   0x0203192C  arm
 *   BACKUP_SYSTEM_Load   0x02031AE0  arm
 *   BACKUP_SYSTEM_ClearWork   0x020319C0  arm
 *   SAVEDATA_PanicFail   0x02034714  arm
 *   SAVE_OUTSIDE_Load   0x021DFC20  thumb  ov228
 *   SAVE_OUTSIDE_IsLoaded   0x021DFE90  thumb  ov228
 *   SAVE_OUTSIDE_IsCorrupt   0x021DFE98  thumb  ov228
 *   SAVE_OUTSIDE_Free   0x021DFDB8  thumb  ov228
 *   SYSTEM_DATA_IsActive    0x02008754  thumb
 *   SYSTEM_DATA_IsMarked    0x02008784  thumb
 *   sub_0200725C    0x0200725C  thumb
 *   SAVE_CONTROL_DeleteExtraSave    0x020072A4  thumb
 *   sub_0200A5F8    0x0200A5F8  thumb
 *   sub_0200A7EC    0x0200A7EC  thumb
 *   ov228_id        0x000000E4  data
 *   _SaveControlFileName  0x020A7054  data
 *   _pSaveControl  0x02146168  data
 *   _MainSaveDesc  0x0209D938  data
 *   _EmptyString  0x020A7064  data
 *   GFL_HEAP_Free       0x020307B0  arm
 *   BACKUP_SYSTEM_Delete       0x0203195C  arm
 *   MUSICAL_SAVE_GetFromSave  0x0200A5F8  thumb
 *   MUSICAL_SAVE_SetHasDistData  0x0200A7EC  thumb
 *   func_02008784  0x02008784  thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   SAVE_CONTROL_DeleteExtraSave  0x020072A4  thumb
 *   func_020087C0  0x020087C0  thumb
 *   func_02007428  0x02007428  thumb
 *   BACKUP_SYSTEM_MainSave  0x02031BB4  arm
 *   func_02008754  0x02008754  thumb
 *   BACKUP_SYSTEM_GetWrittenSize 0x02031E68 arm
 *   BACKUP_SYSTEM_GetRecordWork  0x020319A4  arm
 *   BACKUP_SYSTEM_GetWork  0x02031994  arm
 *   BACKUP_SYSTEM_Erase    0x020319F0  arm
 *   BACKUP_SYSTEM_GetDiffSize  0x020319E4  arm
 *   BACKUP_SYSTEM_ReadRecordFromFlash  0x020334E8  arm
 *   _ExtraSaveDescs  0x0209D950  data
 *   func_020087D4        0x020087D4  thumb
 *   BACKUP_SYSTEM_LoadLinked        0x02031DC0  arm
 *   BACKUP_SYSTEM_CreateWithWork        0x02031948  arm
 *   func_020087A8  0x020087A8  thumb
 *   BACKUP_SYSTEM_InitLinkedSave  0x02031C10  arm
 *   BACKUP_SYSTEM_MainLinkedSave  0x02031C30  arm
 *   BACKUP_SYSTEM_WriteFlash  0x02033478  arm
 *   _BoxEmptyString  0x020A7068  data
 *   SAVE_CONTROL_GetBlock       0x020071CC  thumb
 *   BOX_SAVEDATA_GetBoxPokemon       0x02007AF4  thumb
 *   POKE_TOOL_GetBoxValue       0x02017E88  thumb
 *   POKE_TOOL_RecoverBoxAllPP       0x020181A0  thumb
 *   MSGDATA_CreateFromArchive      0x02045B38  arm
 *   MSGDATA_Delete      0x02045C04  arm
 *   MSGDATA_ReadUnits      0x02045F5C  arm
 *   BOX_SAVEDATA_GetHeader       0x020074CC  thumb
 *   POKE_TOOL_ClearBoxParam  0x02017550  thumb
 *   STRBUF_SetString      0x02045924  arm
 *   STRBUF_ToChars      0x02045A38  arm
 *   _BoxSavedataFileName  0x020A706C  data
 *   _PerapVoiceFileName  0x020A707C  data
 *   func_02082A7C      0x02082A7C  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   PERAPVOICE_IsRecorded   0x02007B50  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   FILE_UTIL_Get_0FE4  0x02020FE4  thumb
 *   FILE_UTIL_Check1288  0x02021288  thumb
 *   FILE_UTIL_GetId  0x0202130C  thumb
 *   _MyItemSavedataFileName  0x020A708C  data
 *   BACKUP_SYSTEM_StartSave  0x02031B8C  arm
 *   BACKUP_SYSTEM_CancelSave  0x02031C04  arm
 *   SYSTEM_DATA_SetActive  0x02008764  thumb
 *   SYSTEM_DATA_ClearActive  0x02008774  thumb
 *   SYSTEM_DATA_SetMark  0x020087A8  thumb
 *   SYSTEM_DATA_ClearMark  0x020087C0  thumb
 *   SYSTEM_DATA_GetWordSlot  0x020087D4  thumb
 */
#include "btl_setup_types.h"

/*
 * save_control.c: the SaveControl object (the game's save manager) and,
 * after it in the same byte range, three block files that the image keeps
 * adjacent: box_savedata.c (PC boxes), perapvoice.c (Chatot recording) and
 * myitem_savedata.c (the bag).  The cuts are listed in the lane's cuts.tsv.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;

#define NULL ((void *)0)

struct BackupSaveData;   /* backup_system.c: one flash save area (main or extra) */
struct SaveOutside;      /* ov228 save_outside.c: the small save outside the main area */
struct MsgData;
struct Strbuf;
struct PokeParty;
struct Pokemon;
struct MusicalSave;

/*
 * Result of BACKUP_SYSTEM_Load (BACKUP_SYSTEM_Load / BACKUP_SYSTEM_LoadLinked).
 * 1 and 2 leave data in the work area; 2 means a copy had to be recovered.
 */
#define SAVE_LOAD_NO_DATA 0
#define SAVE_LOAD_OK 1
#define SAVE_LOAD_RECOVERED 2
#define SAVE_LOAD_BROKEN 3
#define SAVE_LOAD_NO_FLASH 4

/* Bits of SaveControl.loadFlags. */
#define SAVE_FLAG_RECOVERED 0x1
#define SAVE_FLAG_BROKEN 0x2
#define SAVE_FLAG_EXTRA_SHIFT 2 /* bit (slot + 2): extra save slot failed to load */
#define SAVE_FLAG_OUTSIDE_BROKEN 0x800

/* Extra saves: nine separate flash save areas linked to the main save by a counter. */
typedef enum {
    EXTRA_SAVE_BATTLE_REC_0,
    EXTRA_SAVE_BATTLE_REC_1,
    EXTRA_SAVE_BATTLE_REC_2,
    EXTRA_SAVE_BATTLE_REC_3,
    EXTRA_SAVE_CGEAR_SKIN,
    EXTRA_SAVE_TRIAL_HOUSE,
    EXTRA_SAVE_MUSICAL_DIST,
    EXTRA_SAVE_DREAM_WORLD,
    EXTRA_SAVE_FIELD_RECORD,
    EXTRA_SAVE_MAX
} ExtraSaveSlot;

/* Descriptor of one save area (table of save blocks); 0x18 bytes each. */
struct SaveAreaDesc {
    u8 data[0x18];
};

/* 0x38 bytes, allocated by SAVE_CONTROL_Create, one global instance. */
struct SaveControl {
    u8 isNewGame;           /* 00: 1 until a save was loaded or written */
    u8 hasFlashSave;        /* 01: 1 when the flash holds a usable save */
    u8 loadNotClean;        /* 02: 1 unless the main save loaded without recovery */
    u8 wasActiveBeforeSave; /* 03: SystemData.active as it was before StartSave */
    u8 outsideSaveLoaded;   /* 04: the outside save was read */
    u8 outsideSaveBroken;   /* 05: both outside copies are damaged */
    u8 pad06[6];
    u32 loadFlags;                                  /* 0C: SAVE_FLAG_* */
    struct BackupSaveData *mainSave;                /* 10 */
    struct BackupSaveData *extraSaves[EXTRA_SAVE_MAX]; /* 14: open extra saves, 0 when closed */
};

/* PC boxes. */
#define MAX_BOXES 0x18
#define BOX_CAPACITY 30
#define BOX_CURRENT (-1) /* box argument meaning the current box */
#define BOX_EXPAND_STEP 8

/* One stored Pokemon, 0x88 bytes (4-aligned so that a copy is an ldm/stm loop). */
struct BoxPokemon {
    u32 personality;
    u16 flags;
    u16 checksum;
    u8 blocks[0x80];
};

struct BoxName {
    u16 chars[0x14];
};

/* Box block header (block id 0), 0x3DE bytes; the 30 Pokemon of each box are blocks 1..24. */
struct BoxSaveHeader {
    u32 currentBox;
    struct BoxName names[MAX_BOXES];
    u8 wallpaper[MAX_BOXES];
    u8 flags;
    u8 usableBoxCount; /* 8, 16 or 24 */
};

/* Chatot recording block, 0x3EC bytes. */
struct PerapVoice {
    u32 isRecorded;
    u8 samples[1000]; /* two signed 4 bit samples per byte */
};

#define PERAP_PACKED_BYTES 1000
#define PERAP_UNPACKED_BYTES (PERAP_PACKED_BYTES * 8)
#define PERAP_UNPACKED_SIZE 0x1FF4

/* Bag. */
struct BagSlot {
    u16 itemId;
    u16 quantity;
};

#define BAG_POCKET_ITEMS 0
#define BAG_POCKET_MEDICINE 1
#define BAG_POCKET_TMHM 2
#define BAG_POCKET_BERRIES 3
#define BAG_POCKET_KEY_ITEMS 4

#define BAG_ITEMS_COUNT 0x136
#define BAG_KEY_ITEMS_COUNT 0x53
#define BAG_TMHM_COUNT 0x6D
#define BAG_MEDICINE_COUNT 0x30
#define BAG_BERRIES_COUNT 0x40

#define BAG_STACK_MAX 999

/* Box Pokemon parameter ids. */
#define MON_DATA_SPECIES 5
#define MON_DATA_IS_EGG 0x4C
#define MON_DATA_EXISTS 0xA9 /* nonzero when the slot holds a Pokemon */
#define SPECIES_CHATOT 0x1B9

/* Remembered bag cursor, 0x2C bytes. */
struct BagCursor {
    s16 fieldPocketPosition[5]; /* 00 */
    s16 fieldPocketScroll[5];   /* 0A */
    u16 lastFieldPocket;      /* 14 */
    u16 pad16;                /* 16: not accessed */
    s16 battlePocketPosition[4]; /* 18 */
    s16 battlePocketScroll[4];   /* 20 */
    u16 lastBattleItem;       /* 28 */
    u16 lastBattleItemPocket; /* 2A */
};

/* The bag block as the pocket arrays lay out in it (0x9C0 bytes). */
struct MyItem {
    struct BagSlot items[BAG_ITEMS_COUNT];         /* 000 */
    struct BagSlot keyItems[BAG_KEY_ITEMS_COUNT];  /* 4D8 */
    struct BagSlot tmhm[BAG_TMHM_COUNT];           /* 624 */
    struct BagSlot medicine[BAG_MEDICINE_COUNT];   /* 7D8 */
    struct BagSlot berries[BAG_BERRIES_COUNT];     /* 898 */
    u8 reserved[0x28];                             /* 998 */
};

/* Callees in other files, under their current names. */
extern int GF_OVERLAY_Load(int overlayId);
extern void GF_OVERLAY_Unload(int overlayId);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *memory);
extern void SAVEDATA_PanicFail(const char *file, u32 line, const char *message);
extern void func_02082A7C(u32 value, void *dest, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern struct BackupSaveData *BACKUP_SYSTEM_Create(const struct SaveAreaDesc *desc, u32 heapId);
extern struct BackupSaveData *BACKUP_SYSTEM_CreateWithWork(const struct SaveAreaDesc *desc, u32 heapId,
                                            void *work, u32 workSize, u32 initMode);
extern void BACKUP_SYSTEM_Delete(struct BackupSaveData *backup);
extern void *BACKUP_SYSTEM_GetWork(struct BackupSaveData *backup, u32 *size);
extern void *BACKUP_SYSTEM_GetRecordWork(struct BackupSaveData *backup, u32 recordId);
extern void BACKUP_SYSTEM_ClearWork(struct BackupSaveData *backup);
extern void *BACKUP_SYSTEM_GetDiffSize(struct BackupSaveData *backup);
extern int BACKUP_SYSTEM_Erase(struct BackupSaveData *backup, u32 heapId);
extern int BACKUP_SYSTEM_Load(struct BackupSaveData *backup, u32 heapId);
extern int BACKUP_SYSTEM_StartSave(struct BackupSaveData *backup);
extern int BACKUP_SYSTEM_MainSave(struct BackupSaveData *backup);
extern void BACKUP_SYSTEM_CancelSave(struct BackupSaveData *backup);
extern void BACKUP_SYSTEM_InitLinkedSave(struct BackupSaveData *mainSave, struct BackupSaveData *extraSave, u32 *linkCount);
extern int BACKUP_SYSTEM_MainLinkedSave(struct BackupSaveData *mainSave, struct BackupSaveData *extraSave);
extern int BACKUP_SYSTEM_LoadLinked(struct BackupSaveData *backup, u32 heapId, u32 linkCount);
extern u32 BACKUP_SYSTEM_GetWrittenSize(struct BackupSaveData *backup);
extern void BACKUP_SYSTEM_WriteFlash(u32 flashAddr, const void *src, u32 size);
extern int BACKUP_SYSTEM_ReadRecordFromFlash(struct BackupSaveData *backup, u32 recordId, u32 areaIndex, u32 dest, u32 size);

extern void *SAVE_OUTSIDE_Load(u32 heapId);
extern u8 SAVE_OUTSIDE_IsLoaded(struct SaveOutside *outside);
extern int SAVE_OUTSIDE_IsCorrupt(struct SaveOutside *outside);
extern void SAVE_OUTSIDE_Free(struct SaveOutside *outside);

extern u8 SYSTEM_DATA_IsActive(struct SaveControl *save);
extern void SYSTEM_DATA_SetActive(struct SaveControl *save);
extern void SYSTEM_DATA_ClearActive(struct SaveControl *save);
extern int SYSTEM_DATA_IsMarked(struct SaveControl *save, u32 slot);
extern void SYSTEM_DATA_SetMark(struct SaveControl *save, u32 slot);
extern void SYSTEM_DATA_ClearMark(struct SaveControl *save, u32 slot);
extern u32 *SYSTEM_DATA_GetWordSlot(struct SaveControl *save, u32 slot);
extern struct MusicalSave *MUSICAL_SAVE_GetFromSave(struct SaveControl *save);
extern void MUSICAL_SAVE_SetHasDistData(struct MusicalSave *musical, u8 hasDistData);

extern u32 POKE_TOOL_GetBoxValue(struct BoxPokemon *mon, u32 field, u32 arg);
extern void POKE_TOOL_ClearBoxParam(struct BoxPokemon *mon);
extern void POKE_TOOL_RecoverBoxAllPP(struct BoxPokemon *mon);
extern u32 POKE_TOOL_GetPartyValue(struct Pokemon *mon, u32 field, u32 arg);
extern u32 POKEPARTY_GetCount(struct PokeParty *party);
extern struct Pokemon *POKEPARTY_GetMember(struct PokeParty *party, u32 index);
extern struct MsgData *MSGDATA_CreateFromArchive(u32 resident, u32 archiveId, u32 fileId, u32 heapId);
extern void MSGDATA_Delete(struct MsgData *msg);
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 index, u16 *dest, u32 maxLen);
extern void STRBUF_SetString(struct Strbuf *dest, const u16 *src);
extern void STRBUF_ToChars(const struct Strbuf *src, u16 *dest, u32 length);
extern u32 FILE_UTIL_Get_0FE4(u32 itemId, u32 param, u32 heapId);
extern u32 FILE_UTIL_Check1288(u32 itemId);
extern u32 FILE_UTIL_GetId(u32 itemId);

/* Data: symbols at fixed addresses (see the symbols block above). */
extern u8 ov228_id[]; /* absolute symbol: overlay id 228, see the note at the constructor */
extern struct SaveControl *_pSaveControl;
extern struct SaveAreaDesc _MainSaveDesc;        /* 0x0209D938 */
extern struct SaveAreaDesc _ExtraSaveDescs[];    /* 0x0209D950, follows _MainSaveDesc */
extern const char _SaveControlFileName[];        /* "save_control.c" */
extern const char _EmptyString[];                /* assert text of the first file, empty */
extern const char _BoxEmptyString[];             /* assert text of box_savedata.c, empty */
extern const char _BoxSavedataFileName[];
extern const char _PerapVoiceFileName[];
extern const char _MyItemSavedataFileName[];

/* Own functions that are used before their definition. */
void SAVE_CONTROL_EraseOutsideSave(void);
void BOX_SAVEDATA_InitHeader(struct BoxSaveHeader *header);
struct BoxSaveHeader *BOX_SAVEDATA_GetHeader(struct GameData *gameData);
int BOX_SAVEDATA_AddPokemonToBox(struct GameData *gameData, u32 box, const struct BoxPokemon *mon);
void BOX_SAVEDATA_Init(struct BoxSaveHeader *header);
struct BoxPokemon *BOX_SAVEDATA_GetBoxPokemon(struct GameData *gameData, u32 box);
void PERAPVOICE_Init(struct PerapVoice *voice);
void PERAPVOICE_ClearRecorded(struct PerapVoice *voice);
u32 PERAPVOICE_IsRecorded(struct PerapVoice *voice);
int BOX_SAVEDATA_CountPokemonInBox(struct GameData *gameData, u32 box);
int BOX_SAVEDATA_CountNonEggPokemonInBox(struct GameData *gameData, u32 box);
u32 MYITEM_SAVEDATA_GetPocket(struct MyItem *bag, u32 pocket, struct BagSlot **slots, u32 *count);
u32 MYITEM_SAVEDATA_GetPocketOfItem(struct MyItem *bag, u32 itemId, struct BagSlot **slots, u32 *count, u16 heapId);
struct BagSlot *MYITEM_SAVEDATA_FindAddSlot(struct BagSlot *slots, u32 count, u16 itemId, u16 quantity, u16 maxQuantity);
struct BagSlot *MYITEM_SAVEDATA_FindAddSlotForItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);
struct BagSlot *MYITEM_SAVEDATA_FindRemoveSlot(struct BagSlot *slots, u32 count, u16 itemId, u16 quantity);
struct BagSlot *MYITEM_SAVEDATA_FindItemSlot(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);
u32 MYITEM_SAVEDATA_CountUsedSlots(const struct BagSlot *slots, u32 count);
void MYITEM_SAVEDATA_SwapSlots(struct BagSlot *a, struct BagSlot *b);
void MYITEM_SAVEDATA_MoveLastUsedToFront(struct BagSlot *slots, u32 count);
void MYITEM_SAVEDATA_ClearEmptyQuantities(struct BagSlot *slots, u32 count);
void MYITEM_SAVEDATA_CompactPocket(struct BagSlot *slots, u32 count);
void MYITEM_SAVEDATA_SortPocketById(struct BagSlot *slots, u32 count);
void MYITEM_SAVEDATA_SortPocketByItemOrder(struct BagSlot *slots, u32 count);


u32 SAVE_CONTROL_LoadExtraSave(struct SaveControl *saveControl, u32 slot, u8 heapId);
void SAVE_CONTROL_DeleteExtraSave(struct SaveControl *saveControl, u32 slot);

/*
 * The constructor of "save_control.c" (the file name string at 0x020A7054 is
 * the one this passes to the debug allocator, line 0x58).  It loads the
 * overlay that holds the outside save reader (ov228), reads two bytes out of
 * it, allocates the 0x38 byte control block into the global at 0x02146168,
 * loads the main save and then opens the nine extra saves that the system
 * data marks as present.
 *
 * ov228_id is an absolute linker symbol, not the integer 228: written as a
 * literal it compiles `movs r0, #0xe4` with no pool word, where the original
 * has `ldr r0, [pc, #0x148]` over a pool word 0x000000E4.  See
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * Both dispatches are dense PC-relative halfword tables over five cases, so
 * every low case label exists in the source even where the arm is empty;
 * see docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *
 * The bytes closed in three steps: the switch value tested as
 * (u32)(r - 1) <= 1 before SYSTEM_DATA_IsActive; an enum loop counter over the nine
 * slots, which keeps the image's unfolded `cmp r4, #9` guard; and the loop
 * written as `i = 0; if (i < MAX) { flags = &...; do { ... i++; } while ... }`,
 * which puts the flags pointer after the guard where the image computes it.
 * A `for` with the pointer assigned inside the body keeps a second top test.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_CONTROL_Create.c \
 *       --func SAVE_CONTROL_Create --addr 0x02006F20 --cc 1.1p1 --thumb
 */
struct SaveControl *SAVE_CONTROL_Create(int heapId)
{
    struct SaveControl *saveControl;
    struct SaveOutside *outsideSave;
    u8 outsideLoaded;
    int outsideBroken;
    int loadResult;
    int extraResult;
    ExtraSaveSlot slot;
    u32 *loadFlags;

    GF_OVERLAY_Load((int)ov228_id);
    outsideSave = SAVE_OUTSIDE_Load(heapId);
    outsideLoaded = SAVE_OUTSIDE_IsLoaded(outsideSave);
    outsideBroken = SAVE_OUTSIDE_IsCorrupt(outsideSave);
    SAVE_OUTSIDE_Free(outsideSave);
    GF_OVERLAY_Unload((int)ov228_id);
    saveControl = (struct SaveControl *)GFL_HEAP_Alloc(heapId, 0x38, 1, _SaveControlFileName, 0x58);
    _pSaveControl = saveControl;
    saveControl->isNewGame = 1;
    saveControl->loadNotClean = 1;
    saveControl->hasFlashSave = 0;
    saveControl->outsideSaveLoaded = outsideLoaded;
    saveControl->outsideSaveBroken = outsideBroken;
    saveControl->mainSave = BACKUP_SYSTEM_Create(&_MainSaveDesc, heapId);
    loadResult = BACKUP_SYSTEM_Load(saveControl->mainSave, 1);
    if ((u32)(loadResult - 1) <= 1 && SYSTEM_DATA_IsActive(saveControl) == 1)
        loadResult = SAVE_LOAD_NO_DATA;
    saveControl->loadFlags = 0;
    if (outsideBroken == 1)
        saveControl->loadFlags |= SAVE_FLAG_OUTSIDE_BROKEN;
    switch (loadResult) {
    case SAVE_LOAD_OK:
        saveControl->loadNotClean = 0;
    case SAVE_LOAD_RECOVERED:
        saveControl->isNewGame = 0;
        saveControl->hasFlashSave = 1;
        if (loadResult == SAVE_LOAD_RECOVERED)
            saveControl->loadFlags |= SAVE_FLAG_RECOVERED;
        slot = 0;
        if (slot < EXTRA_SAVE_MAX) {
            loadFlags = &saveControl->loadFlags;
            do {
                if (SYSTEM_DATA_IsMarked(saveControl, slot) == 1) {
                    extraResult = SAVE_CONTROL_LoadExtraSave(saveControl, slot, 1);
                    SAVE_CONTROL_DeleteExtraSave(saveControl, slot);
                    switch (extraResult) {
                    case SAVE_LOAD_OK:
                    case SAVE_LOAD_RECOVERED:
                        if (slot == EXTRA_SAVE_MUSICAL_DIST)
                            MUSICAL_SAVE_SetHasDistData(MUSICAL_SAVE_GetFromSave(saveControl), 1);
                        break;
                    case SAVE_LOAD_NO_DATA:
                    case SAVE_LOAD_BROKEN:
                    case SAVE_LOAD_NO_FLASH:
                        *loadFlags |= 1 << (slot + SAVE_FLAG_EXTRA_SHIFT);
                        if (slot == EXTRA_SAVE_MUSICAL_DIST)
                            MUSICAL_SAVE_SetHasDistData(MUSICAL_SAVE_GetFromSave(saveControl), 0);
                        break;
                    }
                } else if (slot == EXTRA_SAVE_MUSICAL_DIST) {
                    MUSICAL_SAVE_SetHasDistData(MUSICAL_SAVE_GetFromSave(saveControl), 0);
                }
                slot++;
            } while (slot < EXTRA_SAVE_MAX);
        }
        break;
    case SAVE_LOAD_BROKEN:
        saveControl->loadFlags |= SAVE_FLAG_BROKEN;
    case SAVE_LOAD_NO_DATA:
    case SAVE_LOAD_NO_FLASH:
        BACKUP_SYSTEM_ClearWork(saveControl->mainSave);
        break;
    default:
        SAVEDATA_PanicFail(_EmptyString, 0, _EmptyString);
        break;
    }
    return saveControl;
}


/*
 * Teardown of the one global: a pointer at 0x02146168 to the control block.
 *
 * 0x020A7064 is the empty string, not a file name.  "save_control.c" ends
 * with its NUL at 0x020A7062 and the next twelve bytes are NUL up to
 * "box_savedata.c" at 0x020A706C, so the assertion helper at 0x02034714 is
 * being passed an empty message here and at six further sites in the same
 * original file.  The accessor below loads the global twice out of one pool
 * word, once for the assertion and once for the result.
 */
void SAVE_CONTROL_Delete(void)
{
    if (_pSaveControl != 0) {
        BACKUP_SYSTEM_Delete(_pSaveControl->mainSave);
        GFL_HEAP_Free(_pSaveControl);
        _pSaveControl = 0;
    }
}


struct SaveControl *SAVE_CONTROL_Get(void)
{
    if (_pSaveControl == 0) {
        SAVEDATA_PanicFail(_EmptyString, 0, _EmptyString);
    }
    return _pSaveControl;
}


/*
 * Reload the main save after the extra saves were touched: when it loads
 * (result 1 or 2) the control block is marked as holding a flash save, the
 * musical distribution flag is cleared, extra save slot 6 is checked again,
 * and every slot whose failure bit is set is unmarked in the system data.
 * EXACT* (the 136-byte extent includes the 2-byte pad).  Two levers closed
 * the 35-byte near miss: the bit loop's counter is an enum, which keeps the
 * `cmp r4, #9; bge` entry guard
 * (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md), and the
 * early exit is `goto end` onto the one `return`, so the branch lands on the
 * shared `adds r0, r7, #0` instead of straight on the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_CONTROL_Reload.c \
 *       --func SAVE_CONTROL_Reload --addr 0x020070C8 --thumb --cc 1.1p1
 */
int SAVE_CONTROL_Reload(struct SaveControl *saveControl)
{
    int loadResult = BACKUP_SYSTEM_Load(saveControl->mainSave, 1);
    struct MusicalSave *musical;
    ExtraSaveSlot slot;

    if (loadResult != SAVE_LOAD_OK && loadResult != SAVE_LOAD_RECOVERED) {
        goto end;
    }
    {
        saveControl->hasFlashSave = 1;
        musical = MUSICAL_SAVE_GetFromSave(saveControl);
        MUSICAL_SAVE_SetHasDistData(musical, 0);
        if (SYSTEM_DATA_IsMarked(saveControl, EXTRA_SAVE_MUSICAL_DIST) == 1) {
            int extraResult = SAVE_CONTROL_LoadExtraSave(saveControl, EXTRA_SAVE_MUSICAL_DIST, 1);

            SAVE_CONTROL_DeleteExtraSave(saveControl, EXTRA_SAVE_MUSICAL_DIST);
            if (extraResult != SAVE_LOAD_OK && extraResult != SAVE_LOAD_RECOVERED)
                goto bits;
            MUSICAL_SAVE_SetHasDistData(musical, 1);
        }
bits:
        if (saveControl->loadFlags != 0) {
            for (slot = 0; slot < 9; slot++) {
                if (saveControl->loadFlags & (1 << (slot + SAVE_FLAG_EXTRA_SHIFT)))
                    SYSTEM_DATA_ClearMark(saveControl, slot);
            }
        }
    }
end:
    return loadResult;
}


/*
 * Start a save: remember the system data "active" flag and clear it, then
 * start the main save sequence.  The caller passes GameData.saveControl.
 */
int SAVE_CONTROL_StartSave(struct SaveControl *saveControl)
{
    int wasActive;

    wasActive = SYSTEM_DATA_IsActive(saveControl);
    saveControl->wasActiveBeforeSave = wasActive;
    SYSTEM_DATA_ClearActive(saveControl);
    return BACKUP_SYSTEM_StartSave(saveControl->mainSave);
}


/*
 * One step of the save sequence.  The two byte flags at +4 and +5 (outside
 * save loaded / broken) are one `||` (the first arms the early return, the
 * second skips it), while the pair at the end is a genuine `&&` - so only the
 * first guard shares its exit.  The early arm erases the outside save and
 * returns the zero it just stored into both flags, which is why the
 * `movs r0, #0` is not duplicated into a third register.  When the main save
 * finishes (result 2) with the system data inactive, the control block is
 * marked as holding a flash save.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_CONTROL_MainSave.c \
 *       --func SAVE_CONTROL_MainSave --addr 0x02007168 --cc 1.1p1 --thumb
 */
u32 SAVE_CONTROL_MainSave(struct SaveControl *saveControl)
{
    u32 saveResult;

    if (saveControl->outsideSaveLoaded == 1 || saveControl->outsideSaveBroken == 1) {
        SAVE_CONTROL_EraseOutsideSave();
        saveControl->outsideSaveLoaded = 0;
        saveControl->outsideSaveBroken = 0;
        return 0;
    }
    saveResult = BACKUP_SYSTEM_MainSave(saveControl->mainSave);
    if (saveResult == 2 && SYSTEM_DATA_IsActive(saveControl) == 0) {
        saveControl->isNewGame = 0;
        saveControl->hasFlashSave = 1;
    }
    return saveResult;
}


/* Cancel the running save and restore the system data "active" flag. */
int SAVE_CONTROL_CancelSave(struct SaveControl *saveControl)
{
    BACKUP_SYSTEM_CancelSave(saveControl->mainSave);
    if ((unsigned int)saveControl->wasActiveBeforeSave == (unsigned int)1) {
        SYSTEM_DATA_SetActive(saveControl);
    } else {
        return saveControl->wasActiveBeforeSave;
    }
}


/*
 * Thumb tail-call stub: loads the main save pointer and tail-calls
 * BACKUP_SYSTEM_GetWrittenSize (written size).  Witness leaf for ov034 REPORT_UpdateSaveAnim.
 */
u32 SAVE_CONTROL_GetWrittenSize(struct SaveControl *saveControl)
{
    return BACKUP_SYSTEM_GetWrittenSize(saveControl->mainSave);
}


/*
 * The block lookup every save accessor in this region goes through: a tail
 * call that returns the record for a block id out of the main save's work
 * area.  It is a file of its own for an evidence reason: the twelve bytes on
 * either side (0x020071C0 and 0x020071D8) are the same shape and tail-call
 * ARM addresses that carry no label, so neither can be attested at any cut.
 * See docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 */
void *SAVE_CONTROL_GetBlock(struct SaveControl *saveControl, u32 blockId)
{
    return BACKUP_SYSTEM_GetRecordWork(saveControl->mainSave, blockId);
}


/* Unlabelled Thumb tail-call thunk: size and address of the main save work area. */
void *SAVE_CONTROL_GetWorkArea(struct SaveControl *saveControl, u32 *size)
{
    return BACKUP_SYSTEM_GetWork(saveControl->mainSave, size);
}


/*
 * Accessors of the control block.  Eight of the eleven carry no label: they
 * are two and three instruction bodies ending in `bx lr` or a pool word and
 * a `bx` (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * SAVE_CONTROL_GetDiffSize tail-calls through 0x020319E4, which is a linker veneer and
 * not a function: the twelve bytes there are `ldr ip, [pc, #0]; bx ip` and a
 * pointer word.  The extern is declared at the veneer's address and marked
 * `arm` (docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md).
 */
u8 SAVE_CONTROL_IsNewGame(const struct SaveControl *saveControl)
{
    return saveControl->isNewGame;
}

u32 SAVE_CONTROL_GetLoadFlags(const struct SaveControl *saveControl)
{
    return saveControl->loadFlags;
}

u8 SAVE_CONTROL_HasFlashSave(const struct SaveControl *saveControl)
{
    return saveControl->hasFlashSave;
}

/* A new game with a flash save present: saving would overwrite that save. */
int SAVE_CONTROL_WouldOverwriteSave(struct SaveControl *saveControl)
{
    if (SAVE_CONTROL_IsNewGame(saveControl) == 1 && SAVE_CONTROL_HasFlashSave(saveControl) == 1) {
        return 1;
    }
    return 0;
}

u8 SAVE_CONTROL_GetOutsideSaveLoaded(const struct SaveControl *saveControl)
{
    return saveControl->outsideSaveLoaded;
}

void SAVE_CONTROL_SetOutsideSaveLoaded(struct SaveControl *saveControl, u8 outsideSaveLoaded)
{
    saveControl->outsideSaveLoaded = outsideSaveLoaded;
}

u8 SAVE_CONTROL_GetOutsideSaveBroken(const struct SaveControl *saveControl)
{
    return saveControl->outsideSaveBroken;
}

void SAVE_CONTROL_SetOutsideSaveBroken(struct SaveControl *saveControl, u8 outsideSaveBroken)
{
    saveControl->outsideSaveBroken = outsideSaveBroken;
}

/* Reset to a new game: mark it and clear the main save work area to defaults. */
void SAVE_CONTROL_ResetToNewGame(struct SaveControl *saveControl)
{
    saveControl->isNewGame = 1;
    saveControl->loadNotClean = 1;
    BACKUP_SYSTEM_ClearWork(saveControl->mainSave);
}

void *SAVE_CONTROL_EraseMainSave(struct SaveControl *saveControl)
{
    return (void *)BACKUP_SYSTEM_Erase(saveControl->mainSave, 1);
}

void *SAVE_CONTROL_GetDiffSize(struct SaveControl *saveControl)
{
    return BACKUP_SYSTEM_GetDiffSize(saveControl->mainSave);
}


/*
 * A five-argument forwarder: the fifth parameter is copied out of the
 * caller's frame into this function's own outgoing slot, so the small
 * `push {r3, lr}` + `sub sp, #4` pair is the callee's stack argument home
 * area, not saved state (see
 * docs/idioms/a-defaulting-wrapper-spends-one-zero-on-r3-and-the-stack-word.md
 * for the sibling shape).  Reads one record of the main save from flash.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_CONTROL_ReadRecordFromFlash.c \
 *       --func SAVE_CONTROL_ReadRecordFromFlash --addr 0x02007248 --cc 1.1p1 --thumb
 */
int SAVE_CONTROL_ReadRecordFromFlash(struct SaveControl *saveControl, u32 recordId, u32 areaIndex, u32 dest, u32 size)
{
    return BACKUP_SYSTEM_ReadRecordFromFlash(saveControl->mainSave, recordId, areaIndex, dest, size);
}


/*
 * Open extra save `slot` (one of nine save areas the control block tracks at
 * +0x14) and load it.  The area is created from the descriptor table, the
 * system data says whether the slot is marked present (SYSTEM_DATA_IsMarked), and on
 * success the area is loaded with the link counter that the system data keeps
 * for the slot (BACKUP_SYSTEM_LoadLinked), which only accepts the area when its footer
 * counter equals that value.
 *
 * Two findings closed this function and its sibling SAVE_CONTROL_LoadExtraSaveWithBuffer:
 *
 * 1. BACKUP_SYSTEM_LoadLinked's second and third arguments are (heapId, linkCount), not
 *    (linkCount, heapId).  The image names the order directly: heapId is
 *    loaded into r1 from its stack home and the SYSTEM_DATA_GetWordSlot result is
 *    dereferenced into r2.  Every statement reordering, temporary and pointer
 *    type variation leaves a flat 5-byte residue at exactly those two loads,
 *    because the residue is in the DECLARATION, not the body.
 *
 * 2. The heap parameter is u8, not u32.  With u32 the constant set-up sinks
 *    past the incoming spill (`str r2, [sp]` moves four halfwords later).
 *    Narrowing the PARAMETER is what closes it: a u32 parameter with a u8
 *    local copy, or a u8 in the callee prototype alone, both stay DIFF.  The
 *    matched callers spell the argument u32; that is a caller-side widening
 *    and does not contradict this.
 */
u32 SAVE_CONTROL_LoadExtraSave(struct SaveControl *saveControl, u32 slot, u8 heapId)
{
    saveControl->extraSaves[slot] = BACKUP_SYSTEM_Create(&_ExtraSaveDescs[slot], heapId);
    if (SYSTEM_DATA_IsMarked(saveControl, slot) == 0) {
        return 0;
    }
    BACKUP_SYSTEM_LoadLinked(saveControl->extraSaves[slot], heapId, *SYSTEM_DATA_GetWordSlot(saveControl, slot));
}


/*
 * Delete extra save `slot`: the slot is asserted open and then cleared.  The
 * assertion message is the empty string at 0x020A7064, the same one six other
 * functions of this original file pass.  SAVE_CONTROL_DeleteExtraSaveBuffered is the same function
 * again on the same slot array with its own pool word, which is what says
 * these are two entry points and not one.
 *
 * Near misses bracket this range (SAVE_CONTROL_LoadExtraSave and SAVE_CONTROL_LoadExtraSaveWithBuffer): both
 * reproduce every instruction, register and branch and differ only in where
 * the incoming third argument is spilled.  Thirty source shapes were tried
 * against each; they all land on the same two counts, so it is not a source
 * form question.
 */
void SAVE_CONTROL_DeleteExtraSave(struct SaveControl *saveControl, u32 slot)
{
    if (saveControl->extraSaves[slot] == 0) {
        SAVEDATA_PanicFail(_EmptyString, 0, _EmptyString);
    }
    BACKUP_SYSTEM_Delete(saveControl->extraSaves[slot]);
    saveControl->extraSaves[slot] = 0;
}


/* Like SAVE_CONTROL_LoadExtraSave, but the area works in the caller's buffer (initMode 1) and is loaded. */
u32 SAVE_CONTROL_LoadExtraSaveWithBuffer(struct SaveControl *saveControl, u32 slot, u8 heapId, void *work, u32 workSize)
{
    saveControl->extraSaves[slot] = BACKUP_SYSTEM_CreateWithWork(&_ExtraSaveDescs[slot], heapId, work, workSize, 1);
    if (SYSTEM_DATA_IsMarked(saveControl, slot) == 0) {
        return 0;
    }
    return (u32)BACKUP_SYSTEM_LoadLinked(saveControl->extraSaves[slot], heapId, *SYSTEM_DATA_GetWordSlot(saveControl, slot));
}


/*
 * Open extra save `slot` for writing in the caller's buffer (initMode 0),
 * without loading it, and a second copy of the delete.  The slot is written
 * once and never read back in SAVE_CONTROL_CreateExtraSaveWithBuffer, so the store is a plain
 * `str r0, [r1, #0x14]` rather than going through a +0x14 base register.
 * 0x0209D950 is the table of 0x18 byte area descriptors, indexed by slot.
 */
void SAVE_CONTROL_CreateExtraSaveWithBuffer(struct SaveControl *saveControl, u32 slot, u32 heapId, u32 work, u32 workSize)
{
    saveControl->extraSaves[slot] = BACKUP_SYSTEM_CreateWithWork(&_ExtraSaveDescs[slot], heapId, (void *)work, workSize, 0);
}

void SAVE_CONTROL_DeleteExtraSaveBuffered(struct SaveControl *saveControl, u32 slot)
{
    if (saveControl->extraSaves[slot] == 0) {
        SAVEDATA_PanicFail(_EmptyString, 0, _EmptyString);
    }
    BACKUP_SYSTEM_Delete(saveControl->extraSaves[slot]);
    saveControl->extraSaves[slot] = 0;
}


/*
 * Begin writing extra save `slot`: mark the slot present in the system data
 * (the zero test on the slot is an assertion that passes the same pointer as
 * argument 1 and argument 3, so the source named it twice), then initialise
 * the linked save with the main save, the slot's area and the slot's link
 * counter word.  The third argument is the pointer SYSTEM_DATA_GetWordSlot returns.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_CONTROL_BeginExtraSaveWrite.c \
 *       --func SAVE_CONTROL_BeginExtraSaveWrite --addr 0x02007374 --cc 1.1p1 --thumb
 */
void SAVE_CONTROL_BeginExtraSaveWrite(struct SaveControl *saveControl, u32 slot)
{
    struct BackupSaveData **extraSaves = saveControl->extraSaves;

    if (extraSaves[slot] == 0) {
        SAVEDATA_PanicFail(_EmptyString, 0, _EmptyString);
    }
    SYSTEM_DATA_SetMark(saveControl, slot);
    BACKUP_SYSTEM_InitLinkedSave(saveControl->mainSave, extraSaves[slot], SYSTEM_DATA_GetWordSlot(saveControl, slot));
}


/*
 * One step of writing extra save `slot`: assertion, then the linked save step
 * with the main save and the slot's area.  The shortest member of this
 * family.  Same double-named assertion pointer as SAVE_CONTROL_BeginExtraSaveWrite and
 * SAVE_CONTROL_EraseExtraSave.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_CONTROL_StepExtraSaveWrite.c \
 *       --func SAVE_CONTROL_StepExtraSaveWrite --addr 0x020073B0 --cc 1.1p1 --thumb
 */
int SAVE_CONTROL_StepExtraSaveWrite(struct SaveControl *saveControl, u32 slot)
{
    struct BackupSaveData **extraSaves = saveControl->extraSaves;

    if (extraSaves[slot] == 0) {
        SAVEDATA_PanicFail(_EmptyString, 0, _EmptyString);
    }
    return BACKUP_SYSTEM_MainLinkedSave(saveControl->mainSave, extraSaves[slot]);
}


/*
 * Record `recordId` of extra save `slot`: the slot is asserted open with the
 * empty string at 0x020A7064 and then handed to the ARM BACKUP_SYSTEM_GetRecordWork.
 */
void *SAVE_CONTROL_GetExtraSaveRecord(struct SaveControl *saveControl, u32 slot, u32 recordId)
{
    if (saveControl->extraSaves[slot] == 0) {
        SAVEDATA_PanicFail(_EmptyString, 0, _EmptyString);
    }
    return BACKUP_SYSTEM_GetRecordWork(saveControl->extraSaves[slot], recordId);
}


/*
 * Erase extra save `slot` (asserted open): the same twenty instructions as
 * SAVE_CONTROL_StepExtraSaveWrite against BACKUP_SYSTEM_Erase.  The table entry is read into r0
 * *after* the local is moved to r6, so the argument order at the call is
 * (area, heapId), not (heapId, area).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_CONTROL_EraseExtraSave.c \
 *       --func SAVE_CONTROL_EraseExtraSave --addr 0x02007400 --cc 1.1p1 --thumb
 */
void SAVE_CONTROL_EraseExtraSave(struct SaveControl *saveControl, u32 slot, u32 heapId)
{
    struct BackupSaveData **extraSaves = saveControl->extraSaves;

    if (extraSaves[slot] == 0) {
        SAVEDATA_PanicFail(_EmptyString, 0, _EmptyString);
    }
    BACKUP_SYSTEM_Erase(extraSaves[slot], heapId);
}


/*
 * The last function of "save_control.c": erase the outside save, two four
 * byte writes of zero to its two flash copies at 0x0007F800 and 0x0007FC00
 * through the ARM BACKUP_SYSTEM_WriteFlash.  Those two constants are plain integer pool
 * words with no relocation, so they are written as constants, and the zero is
 * one stack word whose address is passed to both calls.
 */
void SAVE_CONTROL_EraseOutsideSave(void)
{
    u32 zero = 0;

    BACKUP_SYSTEM_WriteFlash(0x7F800, &zero, 4);
    BACKUP_SYSTEM_WriteFlash(0x7FC00, &zero, 4);
}


/*
 * "box_savedata.c" starts here.  It starts at 0x02007454 and not at the
 * constructor: the pair 0x02007454 and 0x0200745C (the twelve bytes right
 * after the last function of "save_control.c") is the block file opening
 * idiom.  0x0200745C returns the header size, 0x3E0, and 0x02007464, the next
 * function, is the constructor that clears exactly that header.  The function
 * before them passes the empty string 0x020A7064 as its assertion message;
 * the first function of this file that names anything names 0x020A7068, the
 * empty string every assert of "box_savedata.c" passes.  So the seam is
 * between 0x02007428 and 0x02007454 and the two halves use different
 * assertion strings across it.
 *
 * The box functions take the GameData object: its first word is the
 * SaveControl pointer (BOX_SAVEDATA_GetHeader reads it).
 *
 * Details of the bytes:
 *
 *  - BOX_SAVEDATA_InitHeader seeds the 24 wallpaper bytes with a counter that wraps at
 *    sixteen, and the reset is `adds r4, r1, #0` off a register holding zero
 *    rather than a `movs`.  The counter is not a `u8`: a byte variable would
 *    carry a `lsls #24` / `lsrs #24` pair at the increment and there is none,
 *    so it is an unsigned `int` stored through a `u8` array.  The counter has
 *    to be cleared in the `for` initialiser alongside the index.
 *  - BOX_SAVEDATA_AddPokemonToBox copies a whole 0x88 byte Pokemon with an inline `ldm`/`stm`
 *    loop of seventeen iterations
 *    (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md); the struct
 *    has to be four-aligned, because a byte-aligned declaration turns the
 *    same assignment into a 0x88 iteration `ldrb`/`strb` loop.
 *  - BOX_SAVEDATA_AddPokemon walks the boxes from the current one and stops when it
 *    comes back to it, so the loop is a `do`/`while` with no guard, and the
 *    box count it reads on the way round is still live after the loop: the
 *    `cmp r1, #0x18` that follows compares the last value read inside it.
 *    Its declaration order is load bearing for the same reason: with the
 *    header pointer declared first it lands in r4 and the box index in r5,
 *    and the original has them the other way round.
 *  - the statement that bumps the box count by eight re-reads the field even
 *    though the value is in r1.  Only the compound form does that; see
 *    docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md.
 */
void BOX_SAVEDATA_Init(struct BoxSaveHeader *header)
{
    BOX_SAVEDATA_InitHeader(header);
}

u32 BOX_SAVEDATA_GetSize(void)
{
    return sizeof(struct BoxSaveHeader);
}


/* Empty the box block: wallpapers 0..15 repeating, default box names from the message archive. */
void BOX_SAVEDATA_InitHeader(struct BoxSaveHeader *header)
{
    struct MsgData *boxNames;
    u32 box;
    u32 wallpaper;

    for (box = 0, wallpaper = 0; box < MAX_BOXES; box++) {
        header->wallpaper[box] = wallpaper;
        wallpaper++;
        if (wallpaper >= 0x10) {
            wallpaper = 0;
        }
    }
    header->flags = 0;
    boxNames = MSGDATA_CreateFromArchive(0, 2, 9, 1);
    if (boxNames != 0) {
        for (box = 0; box < MAX_BOXES; box++) {
            MSGDATA_ReadUnits(boxNames, box + 6, header->names[box].chars, 0x14);
        }
        MSGDATA_Delete(boxNames);
    }
    header->currentBox = 0;
    header->usableBoxCount = 8;
}

struct BoxSaveHeader *BOX_SAVEDATA_GetHeader(struct GameData *gameData)
{
    return SAVE_CONTROL_GetBlock(gameData->saveControl, 0);
}

/* Put a Pokemon in the first free slot, starting at the current box; unlock 8 more boxes when full. */
int BOX_SAVEDATA_AddPokemon(struct GameData *gameData, const struct BoxPokemon *mon)
{
    u32 box;
    struct BoxSaveHeader *header;
    u8 usableBoxCount;

    header = BOX_SAVEDATA_GetHeader(gameData);
    box = header->currentBox;

    do {
        if (BOX_SAVEDATA_AddPokemonToBox(gameData, box, mon) != 0) {
            return 1;
        }
        box++;
        usableBoxCount = header->usableBoxCount;
        if (box >= usableBoxCount) {
            box = 0;
        }
    } while (box != header->currentBox);
    if (usableBoxCount != MAX_BOXES) {
        header->usableBoxCount += BOX_EXPAND_STEP;
        BOX_SAVEDATA_AddPokemonToBox(gameData, usableBoxCount, mon);
        return 1;
    }
    return 0;
}

/* Put a Pokemon in the first free slot of one box (BOX_CURRENT for the current box). */
int BOX_SAVEDATA_AddPokemonToBox(struct GameData *gameData, u32 box, const struct BoxPokemon *mon)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);
    u32 slot;

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    } else if (box >= header->usableBoxCount) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    for (slot = 0; slot < BOX_CAPACITY; slot++) {
        struct BoxPokemon *boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);

        if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_SPECIES, 0) == 0) {
            boxMons[slot] = *mon;
            POKE_TOOL_RecoverBoxAllPP(&boxMons[slot]);
            return 1;
        }
    }
    return 0;
}


/*
 * Writing one box slot and swapping two of them.  Both reach the slot array
 * through BOX_SAVEDATA_GetBoxPokemon and copy a whole 0x88 byte Pokemon with the inline
 * eight byte ldm/stm loop (0x11 iterations of two words).
 *
 * BOX_SAVEDATA_SetPokemon bounds the box index against the header byte at 0x3DD rather
 * than against the constant 0x18 the rest of the file uses, and that byte is
 * past every Thumb immediate, so it arrives as a pool word and a register
 * offset ldrb.  The failure arm passes 0x020A7068 twice to SAVEDATA_PanicFail,
 * the same empty string and the same three argument assert shape as
 * BOX_SAVEDATA_CountFreeSlotsInBox.
 *
 * BOX_SAVEDATA_SwapPokemon is the three assignment swap through a 0x88 byte stack
 * temporary, and its fifth argument arrives on the stack: `ldr r1, [sp,
 * #0xa0]` is 0x88 of locals plus the six saved registers, not a local.
 */
int BOX_SAVEDATA_SetPokemon(struct GameData *gameData, u32 box, u32 slot, const struct BoxPokemon *mon)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < header->usableBoxCount && slot < BOX_CAPACITY) {
        struct BoxPokemon *boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);

        boxMons[slot] = *mon;
        POKE_TOOL_RecoverBoxAllPP(&boxMons[slot]);
        return 1;
    }
    SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    return 0;
}

void BOX_SAVEDATA_SwapPokemon(struct GameData *gameData, u32 box1, u32 slot1, u32 box2, u32 slot2)
{
    struct BoxPokemon temp;
    struct BoxPokemon *boxMons1 = BOX_SAVEDATA_GetBoxPokemon(gameData, box1);
    struct BoxPokemon *boxMons2 = BOX_SAVEDATA_GetBoxPokemon(gameData, box2);

    temp = boxMons1[slot1];
    boxMons1[slot1] = boxMons2[slot2];
    boxMons2[slot2] = temp;
}


/*
 * The box accessors: BOX_SAVEDATA_GetHeader turns the GameData into the 0x3DE byte box
 * header, and BOX_SAVEDATA_GetBoxPokemon turns a box index into that box's array of thirty
 * 0x88 byte Pokemon.
 *
 * The header's usableBoxCount sits past every Thumb immediate, so it arrives
 * as a pool word and a register offset `ldrb`, and BOX_SAVEDATA_UnlockBoxes loads that
 * same pool word twice, once for the read-modify-write and once for the value
 * it returns.  The slot index is scaled by 0x88, which is not a power of two,
 * so it is a real `muls` with the constant materialised by `movs r1, #0x88`.
 */
void BOX_SAVEDATA_ClearPokemon(struct GameData *gameData, u32 box, u32 slot)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (slot < BOX_CAPACITY && box < MAX_BOXES) {
        POKE_TOOL_ClearBoxParam(&BOX_SAVEDATA_GetBoxPokemon(gameData, box)[slot]);
    }
}


u32 BOX_SAVEDATA_GetCurrentBox(struct GameData *gameData)
{
    return BOX_SAVEDATA_GetHeader(gameData)->currentBox;
}


u8 BOX_SAVEDATA_GetUsableBoxCount(struct GameData *gameData)
{
    return BOX_SAVEDATA_GetHeader(gameData)->usableBoxCount;
}


/* Unlock 8 more boxes unless all are usable; returns the new count. */
u8 BOX_SAVEDATA_UnlockBoxes(struct GameData *gameData)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (header->usableBoxCount != MAX_BOXES) {
        header->usableBoxCount += BOX_EXPAND_STEP;
    }
    return header->usableBoxCount;
}


/*
 * Given a box and a slot by reference, find the next free slot at or after
 * it, wrapping round the usable boxes, and write the answer back through the
 * two pointers; when every usable box is full, unlock 8 more boxes and answer
 * with the first slot of the first new box.  The field id MON_DATA_EXISTS
 * asked of an entry is the "is this entry empty" test, the same call the
 * counting functions use.
 *
 * Three things the shape says.  The box and slot are read out of the two
 * pointers once, before the outer loop, and are carried in registers: the
 * back edge lands on the BOX_SAVEDATA_GetBoxPokemon call and not on the loads, so a source
 * that re-read `*pBox` each time round would be a different function.  The
 * wrap comparison is signed (`blt`), so the index is an int even though the
 * bound is the unsigned byte in the header.  And that byte is loaded once for
 * the whole tail: the compiler keeps it live across the loop exit and uses
 * the same register for the `cmp #0x18` and for the value written back, so
 * only the increment reloads it.
 *
 * The four parameters and the header pointer are all spilled to the stack at
 * sp+0..sp+0xC.  That is register pressure with r4..r7 carrying the box, the
 * slot, the box array and the constant 0x88, not five pointers in the source.
 */
int BOX_SAVEDATA_FindFreeSlot(struct GameData *gameData, int *pBox, int *pSlot)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);
    int box;
    int slot;

    if (*pBox == -1) {
        *pBox = header->currentBox;
    }
    box = *pBox;
    slot = *pSlot;
    while (1) {
        struct BoxPokemon *boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);

        while (slot < BOX_CAPACITY) {
            if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_EXISTS, 0) == 0) {
                *pBox = box;
                *pSlot = slot;
                return 1;
            }
            slot++;
        }
        box++;
        if (box >= header->usableBoxCount) {
            box = 0;
        }
        if (box == *pBox) {
            break;
        }
        slot = 0;
    }
    if (header->usableBoxCount != MAX_BOXES) {
        *pBox = header->usableBoxCount;
        *pSlot = 0;
        header->usableBoxCount += BOX_EXPAND_STEP;
        return 1;
    }
    return 0;
}


/*
 * Free slots over all boxes and in one box, the current box setter, and the
 * getter and setter for the per box wallpaper byte.
 *
 * BOX_SAVEDATA_CountFreeSlots spills its outer loop counter to the stack even though it is
 * an ordinary `int`: r4 through r7 are already carrying the inner counter,
 * the running total, the box array and the constant 0x88, and the GameData
 * pointer is on the stack too.  The spill is register pressure.
 *
 * The failure path of BOX_SAVEDATA_CountFreeSlotsInBox passes the same pointer as the first and
 * the third argument of SAVEDATA_PanicFail, which is the shape of an assertion
 * helper taking a file name twice; see
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md.
 */
int BOX_SAVEDATA_CountFreeSlots(struct GameData *gameData)
{
    int box;
    int slot;
    int freeCount = 0;

    for (box = 0; box < MAX_BOXES; box++) {
        struct BoxPokemon *boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);

        for (slot = 0; slot < BOX_CAPACITY; slot++) {
            if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_EXISTS, 0) == 0) {
                freeCount++;
            }
        }
    }
    return freeCount;
}


int BOX_SAVEDATA_CountFreeSlotsInBox(struct GameData *gameData, u32 box)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);
    struct BoxPokemon *boxMons;
    int slot;
    int freeCount;

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box >= MAX_BOXES) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    freeCount = 0;
    boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);
    for (slot = 0; slot < BOX_CAPACITY; slot++) {
        if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_EXISTS, 0) == 0) {
            freeCount++;
        }
    }
    return freeCount;
}



void BOX_SAVEDATA_SetCurrentBox(struct GameData *gameData, u32 box)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box < MAX_BOXES) {
        header->currentBox = box;
    }
}



u8 BOX_SAVEDATA_GetWallpaper(struct GameData *gameData, u32 box)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box < MAX_BOXES) {
        return header->wallpaper[box];
    }
    return 0;
}



void BOX_SAVEDATA_SetWallpaper(struct GameData *gameData, u32 box, u8 wallpaper)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < MAX_BOXES) {
        header->wallpaper[box] = wallpaper;
    }
}


/*
 * The box name getter and setter, two per box counts, and the whole-storage
 * totals that sum each of them over all 24 boxes.
 *
 * The range has to be exactly these six functions.  BOX_SAVEDATA_CountPokemonInBox is called
 * from one place in the image and BOX_SAVEDATA_CountNonEggPokemonInBox from one place, and those two
 * places are BOX_SAVEDATA_CountPokemon and BOX_SAVEDATA_CountNonEggPokemon respectively, so a file that
 * stopped before the summing loops would leave both counts with no witness
 * outside the compared range.  It cuts the other way too: the file cannot
 * start any later than 0x0200785C, because that is where the 0x28 byte name
 * array's first user is.
 *
 * The header's layout falls out of the shapes.  The name accessors do
 * `adds r2, r1, #4` and then multiply the box index by 0x28, so the names
 * are an array of 24 0x28 byte entries starting at offset 4 and ending at
 * 4 + 24 * 0x28 = 0x3C4, which is exactly where the per box byte starts.
 *
 * Two of the six needed their locals reordering before they matched, and the
 * evidence is only ever which register a value lands in.  BOX_SAVEDATA_CountNonEggPokemonInBox
 * declares its slot counter before the box array, the reverse of
 * BOX_SAVEDATA_CountPokemonInBox immediately above it.  The two summing loops initialise the
 * box index before the running total, which is why they are written
 * `for (box = 0, total = 0; ...)`: the order of the two `movs rN, #0` follows
 * the order of the initialisers.
 */
void BOX_SAVEDATA_GetBoxName(struct GameData *gameData, u32 box, struct Strbuf *dest)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < MAX_BOXES) {
        STRBUF_SetString(dest, header->names[box].chars);
        return;
    }
    SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
}


void BOX_SAVEDATA_SetBoxName(struct GameData *gameData, u32 box, const struct Strbuf *name)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < MAX_BOXES) {
        STRBUF_ToChars(name, header->names[box].chars, 0x14);
    }
}


/* Number of Pokemon in a box. */
int BOX_SAVEDATA_CountPokemonInBox(struct GameData *gameData, u32 box)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);
    struct BoxPokemon *boxMons;
    int slot;
    int count;

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < MAX_BOXES) {
        count = 0;
        boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);
        for (slot = 0; slot < BOX_CAPACITY; slot++) {
            if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_EXISTS, 0) != 0) {
                count++;
            }
        }
        return count;
    }
    SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    return 0;
}


/* Number of Pokemon in a box that are not eggs. */
int BOX_SAVEDATA_CountNonEggPokemonInBox(struct GameData *gameData, u32 box)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);
    int slot;
    struct BoxPokemon *boxMons;
    int count;

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < MAX_BOXES) {
        count = 0;
        boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);
        for (slot = 0; slot < BOX_CAPACITY; slot++) {
            if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_EXISTS, 0) != 0 &&
                POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_IS_EGG, 0) == 0) {
                count++;
            }
        }
        return count;
    }
    SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    return 0;
}


/* Pokemon in all boxes. */
int BOX_SAVEDATA_CountPokemon(struct GameData *gameData)
{
    int total;
    u32 box;

    for (box = 0, total = 0; box < MAX_BOXES; box++) {
        total += BOX_SAVEDATA_CountPokemonInBox(gameData, box);
    }
    return total;
}


/* Pokemon in all boxes that are not eggs. */
int BOX_SAVEDATA_CountNonEggPokemon(struct GameData *gameData)
{
    int total;
    u32 box;

    for (box = 0, total = 0; box < MAX_BOXES; box++) {
        total += BOX_SAVEDATA_CountNonEggPokemonInBox(gameData, box);
    }
    return total;
}


/*
 * The checked slot accessor in its two forms, the flag byte in the header,
 * the size of one box page, and the four byte allocation the box code hangs
 * its per-save state on.
 *
 * The file identity is in the image.  BOX_SAVEDATA_CreateWordHolder passes 0x020A706C to the
 * debug allocator at 0x02030734, and the bytes at 0x020A706C spell
 * "box_savedata.c".  PERAPVOICE_Create, further down the same run, passes
 * 0x020A707C instead, and those bytes spell "perapvoice.c", so a translation
 * unit boundary falls between the two.  See "The string class" in
 * docs/MATCHING.md for why 0x020A706C is carried.
 *
 * BOX_SAVEDATA_GetBoxPageSize carries no label because it saves nothing: `movs r0, #0xFF`,
 * `lsls r0, r0, #4`, `bx lr`.  0xFF0 is 30 entries of 0x88 bytes, which is
 * one box, and it never reaches a literal pool because a byte shifted left
 * costs two halfwords against a pool word plus its `ldr`.
 */
int BOX_SAVEDATA_GetPokemonValue(struct GameData *gameData, u32 box, u32 slot, int field, int arg)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box >= MAX_BOXES && box != BOX_CURRENT) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    if (slot >= BOX_CAPACITY) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    return POKE_TOOL_GetBoxValue(&BOX_SAVEDATA_GetBoxPokemon(gameData, box)[slot], field, arg);
}


struct BoxPokemon *BOX_SAVEDATA_GetPokemon(struct GameData *gameData, u32 box, u32 slot)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box >= MAX_BOXES && box != BOX_CURRENT) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    if (slot >= BOX_CAPACITY) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    return &BOX_SAVEDATA_GetBoxPokemon(gameData, box)[slot];
}


void BOX_SAVEDATA_SetFlags(struct GameData *gameData, u32 bits)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    header->flags |= (u8)bits;
}


int BOX_SAVEDATA_CheckFlags(struct GameData *gameData, u32 bits)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (header->flags & bits) {
        return 1;
    }
    return 0;
}


/* Size of one box page. */
u32 BOX_SAVEDATA_GetBoxPageSize(void)
{
    return BOX_CAPACITY * sizeof(struct BoxPokemon);
}


/* Allocate the four byte word holder (line 0x3B9 of box_savedata.c) and store `value` in it. */
u32 *BOX_SAVEDATA_CreateWordHolder(u32 heapId, u32 value)
{
    u32 *word = GFL_HEAP_Alloc(heapId, 4, 0, _BoxSavedataFileName, 0x3B9);

    *word = value;
    return word;
}


/*
 * The two block lookups everything above goes through, the page clear, and a
 * constructor.  BOX_SAVEDATA_GetBoxDataSize and PERAPVOICE_GetSize return the two object sizes,
 * 0xFF0 and 0x3EC, each as `movs` plus `lsls` rather than a pool word;
 * BOX_SAVEDATA_GetBoxPokemon is a tail call through a pool word, and it is the function
 * every accessor above reaches the box array with.
 */
void BOX_SAVEDATA_Delete(void *memory)
{
    GFL_HEAP_Free(memory);
}


/* Clear every Pokemon of a box page. */
void BOX_SAVEDATA_ClearBoxPage(struct BoxPokemon *boxMons)
{
    u32 slot;

    for (slot = 0; slot < BOX_CAPACITY; slot++) {
        POKE_TOOL_ClearBoxParam(&boxMons[slot]);
    }
}

u32 BOX_SAVEDATA_GetBoxDataSize(void)
{
    return BOX_CAPACITY * sizeof(struct BoxPokemon);
}

/* The Pokemon of one box: block box + 1 (block 0 is the header). */
struct BoxPokemon *BOX_SAVEDATA_GetBoxPokemon(struct GameData *gameData, u32 box)
{
    return SAVE_CONTROL_GetBlock(gameData->saveControl, box + 1);
}


/*
 * "perapvoice.c" starts here (Perap is the Japanese name of Chatot).
 * PERAPVOICE_Create passes 0x020A707C to the debug allocator with the line number
 * 0x57, and the bytes at 0x020A707C spell "perapvoice.c".  The string is
 * named by one pool word in the whole image and it is this function's own,
 * so the `literal` class discards its only witness; the `string` class
 * closes it, because "box_savedata.c" ends with its NUL at 0x020A707A and
 * one byte of padding puts the next string at 0x020A707C by construction.
 *
 * PERAPVOICE_GetSize returns the block size 0x3EC, which is what PERAPVOICE_Init
 * clears and what PERAPVOICE_Create allocates.  The object is one `u32` flag
 * followed by 1000 bytes, and PERAPVOICE_IsRecorded reads the flag that PERAPVOICE_ClearRecorded
 * and PERAPVOICE_SetRecorded write.  Four of the functions carry no label, because
 * none of them saves lr.
 */
u32 PERAPVOICE_GetSize(void)
{
    return sizeof(struct PerapVoice);
}

void PERAPVOICE_Init(struct PerapVoice *voice)
{
    func_02082A7C(0, voice, sizeof(struct PerapVoice));
    voice->isRecorded = 0;
}

struct PerapVoice *PERAPVOICE_Create(u32 heapId)
{
    struct PerapVoice *voice = GFL_HEAP_Alloc(heapId, sizeof(struct PerapVoice), 1, _PerapVoiceFileName, 0x57);

    PERAPVOICE_Init(voice);
    return voice;
}

/* The recording block of the save. */
struct PerapVoice *PERAPVOICE_GetFromSave(struct SaveControl *saveControl)
{
    return SAVE_CONTROL_GetBlock(saveControl, 0x24);
}

u32 PERAPVOICE_IsRecorded(struct PerapVoice *voice)
{
    return voice->isRecorded;
}


/*
 * The payload is 1000 bytes holding two signed four bit samples each.
 * PERAPVOICE_Unpack expands them to 8000 bytes, four copies of each sample in the
 * high nibble of a byte, and zero fills to 0x1FF4; PERAPVOICE_Pack is the exact
 * inverse, 0x1F40 bytes in and 1000 out.  The bias of eight in both
 * directions is what makes the four bit field signed.
 *
 *  - the `lsls #28` / `asrs #24` pair at the end of each expansion is
 *    `(s8)(v << 4)` and not `v << 4`: the truncation is materialised because
 *    the value is assigned to an `s8` local before the inner store loop, and
 *    writing the shift straight into the store gives `lsls #4` alone.
 *  - PERAPVOICE_Pack packs the two nibbles into one byte with a plain store
 *    followed by an `|=`, which is why the byte is stored, reloaded with
 *    `ldrb` and stored again.  Neither half is masked on the way in, so the
 *    source is two `u8` statements and not a bitfield.
 *  - PERAPVOICE_Unpack reloads `src[i]` for the second nibble rather than keeping
 *    it: source and destination are both `s8 *`, so the stores in between may
 *    alias and the compiler has to re-read.
 */
void PERAPVOICE_ClearRecorded(struct PerapVoice *voice)
{
    voice->isRecorded = 0;
}

void PERAPVOICE_SetRecorded(struct PerapVoice *voice)
{
    voice->isRecorded = 1;
}

u8 *PERAPVOICE_GetSamples(struct PerapVoice *voice)
{
    return voice->samples;
}

/* Unpack the 4 bit samples to 8 bit PCM, each sample repeated four times. */
void PERAPVOICE_Unpack(s8 *dest, const s8 *src)
{
    int srcIndex;
    int repeat;
    int destIndex;

    destIndex = 0;
    for (srcIndex = 0; srcIndex < PERAP_PACKED_BYTES; srcIndex++) {
        s8 lowSample = (s8)((s8)((u8)(src[srcIndex] & 0xF) - 8) << 4);

        for (repeat = 0; repeat < 4; repeat++) {
            dest[destIndex + repeat] = lowSample;
        }
        {
            s8 highSample = (s8)((s8)((u8)(src[srcIndex] >> 4) - 8) << 4);

            for (repeat = 4; repeat < 8; repeat++) {
                dest[destIndex + repeat] = highSample;
            }
        }
        destIndex += 8;
    }
    for (srcIndex = PERAP_UNPACKED_BYTES; srcIndex < PERAP_UNPACKED_SIZE; srcIndex++) {
        dest[srcIndex] = 0;
    }
}

/* Pack 8 bit PCM into the 4 bit samples (inverse of the above) and mark the voice recorded. */
void PERAPVOICE_Pack(struct PerapVoice *voice, const s8 *src)
{
    int srcIndex;
    int destIndex;

    voice->isRecorded = 1;
    destIndex = 0;
    for (srcIndex = 0; srcIndex < PERAP_UNPACKED_BYTES; srcIndex += 8) {
        u8 lowNibble = (u8)((s8)(src[srcIndex] / 16) + 8);

        voice->samples[destIndex] = lowNibble;
        {
            u8 highNibble = (u8)((s8)(src[srcIndex + 4] / 16) + 8);

            voice->samples[destIndex] |= (u8)(highNibble << 4);
        }
        destIndex++;
    }
}

void PERAPVOICE_Copy(struct PerapVoice *dest, const struct PerapVoice *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct PerapVoice));
}

/* Drop the recording when the party has no Chatot. */
void PERAPVOICE_ClearIfNoChatot(struct PerapVoice *voice, struct PokeParty *party)
{
    int index;
    int count = POKEPARTY_GetCount(party);

    for (index = 0; index < count; index++) {
        if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, index), MON_DATA_SPECIES, 0) == SPECIES_CHATOT) {
            return;
        }
    }
    PERAPVOICE_ClearRecorded(voice);
}

/* Classify a recording by a check value of three payload bytes: 1 below 100, 2 from 150, else 0. */
u32 PERAPVOICE_GetVoiceKind(struct PerapVoice *voice)
{
    if (PERAPVOICE_IsRecorded(voice) == 1) {
        u8 checkValue = (u8)(voice->samples[0x64] ^ voice->samples[0x1F4] ^ voice->samples[0x2BC]);

        if (checkValue < 100) {
            return 1;
        }
        if (checkValue >= 150 && checkValue < 256) {
            return 2;
        }
    }
    return 0;
}


/*
 * "myitem_savedata.c" starts here: the bag, a 0x9C0 byte block holding five
 * pockets of `{u16 itemId; u16 quantity;}` slots, and the add, take, count
 * and sort routines over them.  The file boundary at the low end is the block
 * file opening idiom: MYITEM_SAVEDATA_GetSize returns 0x9C0 and MYITEM_SAVEDATA_Init fills
 * exactly 0x9C0 bytes with zero, and the function before it belongs to
 * "perapvoice.c".  (The bag cursor allocated by MYITEM_SAVEDATA_CreateBagCursor passes
 * 0x020A708C, "myitem_savedata.c", so the cursor code is in this file too.)
 *
 * The pockets are named by the two switches, MYITEM_SAVEDATA_GetPocket and MYITEM_SAVEDATA_GetSlot,
 * which agree entry for entry:
 *
 *   pocket 0 items      offset 0x000   0x136 slots
 *   pocket 4 key items  offset 0x4D8   0x053 slots
 *   pocket 2 TM/HM      offset 0x624   0x06D slots (stack of 1)
 *   pocket 1 medicine   offset 0x7D8   0x030 slots
 *   pocket 3 berries    offset 0x898   0x040 slots
 *
 * and 0x898 + 0x40 * 4 is 0x998, which is the whole block bar 0x28 trailing
 * bytes.  The case bodies of both switches are emitted in the order 4, 0, 3,
 * 1, 2, and per docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md
 * that order is the order the source wrote the case labels in, so it is kept
 * here.  Neither switch has a `default:` that sets the count, and
 * MYITEM_SAVEDATA_GetSlot reads an uninitialised count on an unknown pocket: the
 * dispatch chain branches past the merged tail rather than into it, which is
 * the reading in docs/idioms/switch-arms-tail-merge.md.
 *
 *  - MYITEM_SAVEDATA_FindAddSlotForItem, MYITEM_SAVEDATA_AddItem and MYITEM_SAVEDATA_RemoveItem pass the address of a local
 *    pointer to MYITEM_SAVEDATA_GetPocketOfItem after having already used that pointer for
 *    something else, and the compiler gives both uses the same stack slot.
 *    Writing them as two variables produces two slots and moves every offset
 *    in the frame, so the source really does reuse the one variable.
 *  - the loop bound in MYITEM_SAVEDATA_CompactPocket and its two siblings is assigned after
 *    the induction variable, not before: `for (i = 0, lim = n - 1; ...)`.
 *    Written the other way round the compiler has no zero in hand at the
 *    point it needs one and materialises it from a literal pool, which costs
 *    four bytes of pool the original does not have.
 *  - MYITEM_SAVEDATA_SortPocketByItemOrder compares two calls to FILE_UTIL_GetId.  The first result is
 *    spilled across the second call and the comparison comes out `cmp r1, r0`
 *    with the spilled operand first, which is the same tell
 *    docs/idioms/cmp-operand-order-names-the-temporary.md records.
 *  - MYITEM_SAVEDATA_FindRemoveSlot returns `&slots[i]` from a second `return` statement rather
 *    than through a merged local.  MYITEM_SAVEDATA_FindAddSlot does use the merged form, and
 *    the difference is visible: the merged form reaches the shared epilogue
 *    with an extra `adds r0, rN, #0`.
 */
u32 MYITEM_SAVEDATA_GetSize(void)
{
    return sizeof(struct MyItem);
}


void MYITEM_SAVEDATA_Init(struct MyItem *bag)
{
    MI_CpuFill8(bag, 0, sizeof(struct MyItem));
}


/* Copy a pocket to (toBuffer) or from the buffer. */
void MYITEM_SAVEDATA_CopyPocket(struct MyItem *bag, void *buffer, u32 pocket, int toBuffer)
{
    struct BagSlot *slots;
    u32 count;

    MYITEM_SAVEDATA_GetPocket(bag, pocket, &slots, &count);
    if (toBuffer) {
        MI_CpuCopy8(slots, buffer, count * sizeof(struct BagSlot));
    } else {
        MI_CpuCopy8(buffer, slots, count * sizeof(struct BagSlot));
    }
}


/* Array and size of a pocket. */
u32 MYITEM_SAVEDATA_GetPocket(struct MyItem *bag, u32 pocket, struct BagSlot **slots, u32 *count)
{
    switch (pocket) {
    case BAG_POCKET_KEY_ITEMS:
        *slots = bag->keyItems;
        *count = BAG_KEY_ITEMS_COUNT;
        break;
    case BAG_POCKET_ITEMS:
        *slots = bag->items;
        *count = BAG_ITEMS_COUNT;
        break;
    case BAG_POCKET_BERRIES:
        *slots = bag->berries;
        *count = BAG_BERRIES_COUNT;
        break;
    case BAG_POCKET_MEDICINE:
        *slots = bag->medicine;
        *count = BAG_MEDICINE_COUNT;
        break;
    case BAG_POCKET_TMHM:
        *slots = bag->tmhm;
        *count = BAG_TMHM_COUNT;
        break;
    default:
        *slots = NULL;
        break;
    }
    return pocket;
}


/* Pocket of an item (item parameter 5), with its array and size; returns the pocket. */
u32 MYITEM_SAVEDATA_GetPocketOfItem(struct MyItem *bag, u32 itemId, struct BagSlot **slots, u32 *count, u16 heapId)
{
    u32 pocket = FILE_UTIL_Get_0FE4(itemId, 5, heapId);

    MYITEM_SAVEDATA_GetPocket(bag, pocket, slots, count);
    return pocket;
}


/* Slot to add `quantity` of an item to: its own slot if the total stays within the limit, else the first empty one. */
struct BagSlot *MYITEM_SAVEDATA_FindAddSlot(struct BagSlot *slots, u32 count, u16 itemId, u16 quantity, u16 maxQuantity)
{
    u32 index;
    u32 freeIndex = -1;

    for (index = 0; index < count; index++) {
        if (itemId == slots[index].itemId) {
            struct BagSlot *slot = &slots[index];

            if (quantity + slot->quantity > maxQuantity) {
                slot = NULL;
            }
            return slot;
        }
        if (freeIndex == -1 && slots[index].itemId == 0 && slots[index].quantity == 0) {
            freeIndex = index;
        }
    }
    if (freeIndex == -1) {
        return NULL;
    }
    return &slots[freeIndex];
}

/* Slot that can take the item; TM/HM stack to 1, the other pockets to 999. */
struct BagSlot *MYITEM_SAVEDATA_FindAddSlotForItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    struct BagSlot *slots;
    u32 count;

    if (MYITEM_SAVEDATA_GetPocketOfItem(bag, itemId, &slots, &count, heapId) == BAG_POCKET_TMHM) {
        return MYITEM_SAVEDATA_FindAddSlot(slots, count, itemId, quantity, 1);
    }
    return MYITEM_SAVEDATA_FindAddSlot(slots, count, itemId, quantity, BAG_STACK_MAX);
}

u32 MYITEM_SAVEDATA_CanAddItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    if (MYITEM_SAVEDATA_FindAddSlotForItem(bag, itemId, quantity, heapId) != NULL) {
        return 1;
    }
    return 0;
}

/* Add items; the pocket is then re-sorted (berries by id, TM/HM by item order) or the new item moved to the front. */
u32 MYITEM_SAVEDATA_AddItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    struct BagSlot *slot; /* reused as the pocket array below: one stack slot in the original */
    u32 count;
    struct BagSlot *usedSlots;
    u32 usedCount;
    u16 oldQuantity;
    u32 pocket;

    slot = MYITEM_SAVEDATA_FindAddSlotForItem(bag, itemId, quantity, heapId);
    if (slot == NULL) {
        return 0;
    }
    oldQuantity = slot->quantity;
    slot->itemId = itemId;
    slot->quantity = (u16)(slot->quantity + quantity);
    pocket = MYITEM_SAVEDATA_GetPocketOfItem(bag, itemId, &slot, &count, heapId);
    if (pocket == BAG_POCKET_BERRIES) {
        MYITEM_SAVEDATA_SortPocketById(slot, count);
    } else if (pocket == BAG_POCKET_TMHM) {
        MYITEM_SAVEDATA_SortPocketByItemOrder(slot, count);
    } else if (oldQuantity == 0) {
        MYITEM_SAVEDATA_GetPocket(bag, pocket, &usedSlots, &usedCount);
        usedCount = MYITEM_SAVEDATA_CountUsedSlots(usedSlots, usedCount);
        MYITEM_SAVEDATA_MoveLastUsedToFront(usedSlots, usedCount);
    }
    return 1;
}

/* Slot of an item holding at least `quantity`, else NULL. */
struct BagSlot *MYITEM_SAVEDATA_FindRemoveSlot(struct BagSlot *slots, u32 count, u16 itemId, u16 quantity)
{
    u32 index;

    for (index = 0; index < count; index++) {
        if (itemId == slots[index].itemId) {
            if (slots[index].quantity < quantity) {
                return NULL;
            }
            return &slots[index];
        }
    }
    return NULL;
}

struct BagSlot *MYITEM_SAVEDATA_FindItemSlot(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    struct BagSlot *slots;
    u32 count;

    MYITEM_SAVEDATA_GetPocketOfItem(bag, itemId, &slots, &count, heapId);
    return MYITEM_SAVEDATA_FindRemoveSlot(slots, count, itemId, quantity);
}

/* Remove items and compact the pocket. */
u32 MYITEM_SAVEDATA_RemoveItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    struct BagSlot *slot; /* reused as the pocket array below */
    u32 count;

    slot = MYITEM_SAVEDATA_FindItemSlot(bag, itemId, quantity, heapId);
    if (slot == NULL) {
        return 0;
    }
    slot->quantity = (u16)(slot->quantity - quantity);
    if (slot->quantity == 0) {
        slot->itemId = 0;
    }
    MYITEM_SAVEDATA_GetPocketOfItem(bag, itemId, &slot, &count, heapId);
    MYITEM_SAVEDATA_CompactPocket(slot, count);
    return 1;
}

u32 MYITEM_SAVEDATA_HasItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId)
{
    if (MYITEM_SAVEDATA_FindItemSlot(bag, itemId, quantity, heapId) != NULL) {
        return 1;
    }
    return 0;
}

/* Number of slots in use. */
u32 MYITEM_SAVEDATA_CountUsedSlots(const struct BagSlot *slots, u32 count)
{
    u32 used = 0;
    u32 index;

    if (slots != NULL) {
        for (index = 0; index < count; index++) {
            if (slots[index].itemId != 0) {
                used++;
            }
        }
    }
    return used;
}

u32 MYITEM_SAVEDATA_CountUsedSlotsInPocket(struct MyItem *bag, u32 pocket)
{
    struct BagSlot *slots;
    u32 count;

    MYITEM_SAVEDATA_GetPocket(bag, pocket, &slots, &count);
    return MYITEM_SAVEDATA_CountUsedSlots(slots, count);
}

/* Quantity of an item held. */
u32 MYITEM_SAVEDATA_GetItemQuantity(struct MyItem *bag, u16 itemId, u16 heapId)
{
    struct BagSlot *slot = MYITEM_SAVEDATA_FindItemSlot(bag, itemId, 1, heapId);

    if (slot == NULL) {
        return 0;
    }
    return slot->quantity;
}

void MYITEM_SAVEDATA_SwapSlots(struct BagSlot *a, struct BagSlot *b)
{
    struct BagSlot temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/* Move the last used slot to the front, shifting the slots before it up by one. */
void MYITEM_SAVEDATA_MoveLastUsedToFront(struct BagSlot *slots, u32 count)
{
    struct BagSlot temp;
    int index;

    temp.itemId = 0;
    if (count <= 1) {
        return;
    }
    for (index = (int)count - 1; index >= 0; index--) {
        if (temp.itemId == 0) {
            MI_CpuCopy8(&slots[index], &temp, sizeof(struct BagSlot));
        } else {
            MI_CpuCopy8(&slots[index], &slots[index + 1], sizeof(struct BagSlot));
        }
    }
    MI_CpuCopy8(&temp, slots, sizeof(struct BagSlot));
}

/* Zero the quantity of every empty slot. */
void MYITEM_SAVEDATA_ClearEmptyQuantities(struct BagSlot *slots, u32 count)
{
    u32 index;

    for (index = 0; index < count; index++) {
        if (slots[index].itemId == 0) {
            slots[index].quantity = 0;
        }
    }
}

/* Move empty slots to the end, keeping the order of the others. */
void MYITEM_SAVEDATA_CompactPocket(struct BagSlot *slots, u32 count)
{
    u32 lastIndex;
    u32 i;
    u32 j;

    MYITEM_SAVEDATA_ClearEmptyQuantities(slots, count);
    for (i = 0, lastIndex = count - 1; i < lastIndex; i++) {
        for (j = i + 1; j < count; j++) {
            if (slots[i].quantity == 0) {
                MYITEM_SAVEDATA_SwapSlots(&slots[i], &slots[j]);
            }
        }
    }
}

/* Sort a pocket by item id, empty slots last. */
void MYITEM_SAVEDATA_SortPocketById(struct BagSlot *slots, u32 count)
{
    u32 lastIndex;
    u32 i;
    u32 j;

    MYITEM_SAVEDATA_ClearEmptyQuantities(slots, count);
    for (i = 0, lastIndex = count - 1; i < lastIndex; i++) {
        for (j = i + 1; j < count; j++) {
            if (slots[i].quantity == 0 ||
                (slots[j].quantity != 0 && slots[i].itemId > slots[j].itemId)) {
                MYITEM_SAVEDATA_SwapSlots(&slots[i], &slots[j]);
            }
        }
    }
}

/* Sort a pocket by the item sort key (FILE_UTIL_GetId), empty slots last. */
void MYITEM_SAVEDATA_SortPocketByItemOrder(struct BagSlot *slots, u32 count)
{
    u32 lastIndex;
    u32 i;
    u32 j;

    MYITEM_SAVEDATA_ClearEmptyQuantities(slots, count);
    for (i = 0, lastIndex = count - 1; i < lastIndex; i++) {
        for (j = i + 1; j < count; j++) {
            if (slots[i].quantity == 0 ||
                (slots[j].quantity != 0 &&
                 FILE_UTIL_GetId(slots[i].itemId) > FILE_UTIL_GetId(slots[j].itemId))) {
                MYITEM_SAVEDATA_SwapSlots(&slots[i], &slots[j]);
            }
        }
    }
}

/* Compact every pocket. */
void MYITEM_SAVEDATA_CompactAllPockets(struct MyItem *bag)
{
    struct BagSlot *slots;
    u32 count;

    MYITEM_SAVEDATA_GetPocket(bag, BAG_POCKET_KEY_ITEMS, &slots, &count);
    MYITEM_SAVEDATA_CompactPocket(slots, count);
    MYITEM_SAVEDATA_GetPocket(bag, BAG_POCKET_ITEMS, &slots, &count);
    MYITEM_SAVEDATA_CompactPocket(slots, count);
    MYITEM_SAVEDATA_GetPocket(bag, BAG_POCKET_BERRIES, &slots, &count);
    MYITEM_SAVEDATA_CompactPocket(slots, count);
    MYITEM_SAVEDATA_GetPocket(bag, BAG_POCKET_MEDICINE, &slots, &count);
    MYITEM_SAVEDATA_CompactPocket(slots, count);
    MYITEM_SAVEDATA_GetPocket(bag, BAG_POCKET_TMHM, &slots, &count);
    MYITEM_SAVEDATA_CompactPocket(slots, count);
}

/* Slot `index` of a pocket, NULL past its end. */
struct BagSlot *MYITEM_SAVEDATA_GetSlot(struct MyItem *bag, u32 pocket, u32 index)
{
    u32 count;
    struct BagSlot *slots;

    switch (pocket) {
    case BAG_POCKET_KEY_ITEMS:
        slots = bag->keyItems;
        count = BAG_KEY_ITEMS_COUNT;
        break;
    case BAG_POCKET_ITEMS:
        slots = bag->items;
        count = BAG_ITEMS_COUNT;
        break;
    case BAG_POCKET_BERRIES:
        slots = bag->berries;
        count = BAG_BERRIES_COUNT;
        break;
    case BAG_POCKET_MEDICINE:
        slots = bag->medicine;
        count = BAG_MEDICINE_COUNT;
        break;
    case BAG_POCKET_TMHM:
        slots = bag->tmhm;
        count = BAG_TMHM_COUNT;
        break;
    }
    if (index >= count) {
        return NULL;
    }
    return &slots[index];
}

/* Largest stack of an item: 1 for items that FILE_UTIL_Check1288 flags, else 999. */
u32 MYITEM_SAVEDATA_GetMaxStack(u32 itemId)
{
    if (FILE_UTIL_Check1288(itemId) == 1) {
        return 1;
    }
    return BAG_STACK_MAX;
}


/*
 * The bag cursor (0x2C bytes, line 0x342 of "myitem_savedata.c"): the last
 * position and scroll of each field bag pocket and each of the four battle
 * bag pockets, plus the last pocket and the last item used in battle.  Nine
 * of the ten functions carry no label, because only the constructor saves lr.
 *
 * Every one of the four array reads is an `ldrsh` with a register offset,
 * which per docs/idioms/ldrsh-register-offset-is-signedness.md is the only
 * evidence that those elements are signed; the writers use plain `strh` and
 * say nothing.
 *
 * The range stops short of 0x020082DC, a six byte tail call whose pool words
 * are both unattestable (no other branch or pool word in the image names
 * either address); it closes the day anything else names them.
 */
struct BagCursor *MYITEM_SAVEDATA_CreateBagCursor(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(struct BagCursor), 1, _MyItemSavedataFileName, 0x342);
}


void MYITEM_SAVEDATA_GetFieldPocketCursor(struct BagCursor *cursor, int pocket, s16 *scroll, s16 *position)
{
    *scroll = cursor->fieldPocketScroll[pocket];
    *position = cursor->fieldPocketPosition[pocket];
}

u16 MYITEM_SAVEDATA_GetLastFieldPocket(const struct BagCursor *cursor)
{
    return cursor->lastFieldPocket;
}

void MYITEM_SAVEDATA_SetFieldPocketCursor(struct BagCursor *cursor, int pocket, s16 scroll, s16 position)
{
    cursor->fieldPocketScroll[pocket] = scroll;
    cursor->fieldPocketPosition[pocket] = position;
}

void MYITEM_SAVEDATA_SetLastFieldPocket(struct BagCursor *cursor, u16 lastFieldPocket)
{
    cursor->lastFieldPocket = lastFieldPocket;
}

void MYITEM_SAVEDATA_GetBattlePocketCursor(const struct BagCursor *cursor, int pocket, s16 *scroll, s16 *position)
{
    *scroll = cursor->battlePocketScroll[pocket];
    *position = cursor->battlePocketPosition[pocket];
}

u16 MYITEM_SAVEDATA_GetLastBattleItem(const struct BagCursor *cursor)
{
    return cursor->lastBattleItem;
}

u16 MYITEM_SAVEDATA_GetLastBattleItemPocket(const struct BagCursor *cursor)
{
    return cursor->lastBattleItemPocket;
}

void MYITEM_SAVEDATA_SetBattlePocketCursors(struct BagCursor *cursor, const s16 *scrolls, const s16 *positions)
{
    u32 pocket;

    for (pocket = 0; pocket < 4; pocket++) {
        cursor->battlePocketScroll[pocket] = scrolls[pocket];
        cursor->battlePocketPosition[pocket] = positions[pocket];
    }
}

void MYITEM_SAVEDATA_SetLastBattleItem(struct BagCursor *cursor, u16 lastBattleItem, u16 lastBattleItemPocket)
{
    cursor->lastBattleItem = lastBattleItem;
    cursor->lastBattleItemPocket = lastBattleItemPocket;
}
