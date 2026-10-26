/*
 * file:     save_control.c
 * unit:     yes
 * function: SAVE_CONTROL_Create, SAVE_CONTROL_Delete, SAVE_CONTROL_Get, SAVE_CONTROL_Reload, SAVE_CONTROL_StartSave, SAVE_CONTROL_MainSave, SAVE_CONTROL_CancelSave, SAVE_CONTROL_GetWrittenSize, SAVE_CONTROL_GetBlock, SAVE_CONTROL_GetWorkArea, SAVE_CONTROL_IsNewGame, SAVE_CONTROL_GetLoadFlags, SAVE_CONTROL_HasFlashSave, SAVE_CONTROL_WouldOverwriteSave, SAVE_CONTROL_GetOutsideSaveLoaded, SAVE_CONTROL_SetOutsideSaveLoaded, SAVE_CONTROL_GetOutsideSaveBroken, SAVE_CONTROL_SetOutsideSaveBroken, SAVE_CONTROL_ResetToNewGame, SAVE_CONTROL_EraseMainSave, SAVE_CONTROL_GetDiffSize, SAVE_CONTROL_ReadRecordFromFlash, SAVE_CONTROL_LoadExtraSave, SAVE_CONTROL_DeleteExtraSave, SAVE_CONTROL_LoadExtraSaveWithBuffer, SAVE_CONTROL_CreateExtraSaveWithBuffer, SAVE_CONTROL_DeleteExtraSaveBuffered, SAVE_CONTROL_BeginExtraSaveWrite, SAVE_CONTROL_StepExtraSaveWrite, SAVE_CONTROL_GetExtraSaveRecord, SAVE_CONTROL_EraseExtraSave, SAVE_CONTROL_EraseOutsideSave
 * address:  0x02006F20
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from save_control.c by tools/splitfile.py.
 *
 * symbols:
 *   GF_OVERLAY_Load   0x02034AC4  arm
 *   GF_OVERLAY_Unload   0x02034A5C  arm
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   BACKUP_SYSTEM_Create   0x0203192C  arm
 *   BACKUP_SYSTEM_Load   0x02031AE0  arm
 *   BACKUP_SYSTEM_ClearWork   0x020319C0  arm
 *   GF_PANIC_Fail   0x02034714  arm
 *   SAVE_OUTSIDE_Load   0x021DFC20  thumb  ov228
 *   SAVE_OUTSIDE_IsLoaded   0x021DFE90  thumb  ov228
 *   SAVE_OUTSIDE_IsCorrupt   0x021DFE98  thumb  ov228
 *   SAVE_OUTSIDE_Free   0x021DFDB8  thumb  ov228
 *   SYSTEM_DATA_IsActive    0x02008754  thumb
 *   SYSTEM_DATA_IsMarked    0x02008784  thumb
 *   SAVE_CONTROL_LoadExtraSave    0x0200725C  thumb
 *   SAVE_CONTROL_DeleteExtraSave    0x020072A4  thumb
 *   MUSICAL_SAVE_GetFromSave    0x0200A5F8  thumb
 *   MUSICAL_SAVE_SetHasDistData    0x0200A7EC  thumb
 *   ov228_id        0x000000E4  data
 *   _SaveControlFileName  0x020A7054  data
 *   _pSaveControl  0x02146168  data
 *   _MainSaveDesc  0x0209D938  data
 *   _EmptyString  0x020A7064  data
 *   GFL_HEAP_Free       0x020307B0  arm
 *   BACKUP_SYSTEM_Delete       0x0203195C  arm
 *   SYSTEM_DATA_ClearMark  0x020087C0  thumb
 *   SAVE_CONTROL_EraseOutsideSave  0x02007428  thumb
 *   BACKUP_SYSTEM_MainSave  0x02031BB4  arm
 *   BACKUP_SYSTEM_GetWrittenSize 0x02031E68 arm
 *   BACKUP_SYSTEM_GetRecordWork  0x020319A4  arm
 *   BACKUP_SYSTEM_GetWork  0x02031994  arm
 *   BACKUP_SYSTEM_Erase    0x020319F0  arm
 *   BACKUP_SYSTEM_GetDiffSize  0x020319E4  arm
 *   BACKUP_SYSTEM_ReadRecordFromFlash  0x020334E8  arm
 *   _ExtraSaveDescs  0x0209D950  data
 *   SYSTEM_DATA_GetWordSlot        0x020087D4  thumb
 *   BACKUP_SYSTEM_LoadLinked        0x02031DC0  arm
 *   BACKUP_SYSTEM_CreateWithWork        0x02031948  arm
 *   SYSTEM_DATA_SetMark  0x020087A8  thumb
 *   BACKUP_SYSTEM_InitLinkedSave  0x02031C10  arm
 *   BACKUP_SYSTEM_MainLinkedSave  0x02031C30  arm
 *   BACKUP_SYSTEM_WriteFlash  0x02033478  arm
 *   SAVE_CONTROL_GetBlock       0x020071CC  thumb
 *   BACKUP_SYSTEM_StartSave  0x02031B8C  arm
 *   BACKUP_SYSTEM_CancelSave  0x02031C04  arm
 *   SYSTEM_DATA_SetActive  0x02008764  thumb
 *   SYSTEM_DATA_ClearActive  0x02008774  thumb
 */
#include "btl_setup_types.h"
#include "../types.h"

struct BackupSaveData;   /* backup_system.c: one flash save area (main or extra) */

struct SaveOutsideWork;

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

/* Callees in other files, under their current names. */
#include "gf_overlay.h"


#include "gfl_heap_wrap.h"


#include "gf_panic.h"
struct SaveDataParam;

#include "backup_system.h"


















#include "../ov228/save_outside.h"




#include "system_data.h"







#include "musical_save.h"


/* Data: symbols at fixed addresses (see the symbols block above). */
extern u8 ov228_id[]; /* absolute symbol: overlay id 228, see the note at the constructor */

extern struct SaveControl *_pSaveControl;

extern struct SaveAreaDesc _MainSaveDesc;        /* 0x0209D938 */

extern struct SaveAreaDesc _ExtraSaveDescs[];    /* 0x0209D950, follows _MainSaveDesc */

extern const char _SaveControlFileName[];        /* "save_control.c" */

extern const char _EmptyString[];                /* assert text of the first file, empty */

/* Own functions that are used before their definition. */
void SAVE_CONTROL_EraseOutsideSave(void);

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
    struct SaveOutsideWork *outsideSave;
    u8 outsideLoaded;
    int outsideBroken;
    int loadResult;
    int extraResult;
    ExtraSaveSlot slot;
    u32 *loadFlags;

    GF_OVERLAY_Load((sptr)ov228_id);
    outsideSave = SAVE_OUTSIDE_Load(heapId);
    outsideLoaded = SAVE_OUTSIDE_IsLoaded(outsideSave);
    outsideBroken = SAVE_OUTSIDE_IsCorrupt(outsideSave);
    SAVE_OUTSIDE_Free(outsideSave);
    GF_OVERLAY_Unload((sptr)ov228_id);
    saveControl = (struct SaveControl *)GFL_HEAP_Alloc(heapId, sizeof(*saveControl), 1, _SaveControlFileName, 0x58);
    _pSaveControl = saveControl;
    saveControl->isNewGame = 1;
    saveControl->loadNotClean = 1;
    saveControl->hasFlashSave = 0;
    saveControl->outsideSaveLoaded = outsideLoaded;
    saveControl->outsideSaveBroken = outsideBroken;
    saveControl->mainSave = BACKUP_SYSTEM_Create((struct SaveDataParam *)(&_MainSaveDesc), heapId);
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
        GF_PANIC_Fail(_EmptyString, 0, _EmptyString);
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
        GF_PANIC_Fail(_EmptyString, 0, _EmptyString);
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
    BACKUP_SYSTEM_StartSave(saveControl->mainSave);
#ifndef __MWERKS__
    return 0; /* the DS returns whatever BACKUP_SYSTEM_StartSave leaves in r0 */
#endif
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
void SAVE_CONTROL_CancelSave(struct SaveControl *saveControl)
{
    BACKUP_SYSTEM_CancelSave(saveControl->mainSave);
    if ((unsigned int)saveControl->wasActiveBeforeSave == (unsigned int)1) {
        SYSTEM_DATA_SetActive(saveControl);
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

int SAVE_CONTROL_EraseMainSave(struct SaveControl *saveControl)
{
    return BACKUP_SYSTEM_Erase(saveControl->mainSave, 1);
}

void SAVE_CONTROL_GetDiffSize(struct SaveControl *saveControl, u32 *diffSize, u32 *totalSize)
{
    BACKUP_SYSTEM_GetDiffSize(saveControl->mainSave, diffSize, totalSize);
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
int SAVE_CONTROL_ReadRecordFromFlash(struct SaveControl *saveControl, u32 recordId, u32 areaIndex, void *dest, u32 size)
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
    saveControl->extraSaves[slot] = BACKUP_SYSTEM_Create((struct SaveDataParam *)(&_ExtraSaveDescs[slot]), heapId);
    if (SYSTEM_DATA_IsMarked(saveControl, slot) == 0) {
        return 0;
    }
    return BACKUP_SYSTEM_LoadLinked(saveControl->extraSaves[slot], heapId, *SYSTEM_DATA_GetWordSlot(saveControl, slot));
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
        GF_PANIC_Fail(_EmptyString, 0, _EmptyString);
    }
    BACKUP_SYSTEM_Delete(saveControl->extraSaves[slot]);
    saveControl->extraSaves[slot] = 0;
}

/* Like SAVE_CONTROL_LoadExtraSave, but the area works in the caller's buffer (initMode 1) and is loaded. */
u32 SAVE_CONTROL_LoadExtraSaveWithBuffer(struct SaveControl *saveControl, u32 slot, u16 heapId, void *work, u32 workSize)
{
    saveControl->extraSaves[slot] = BACKUP_SYSTEM_CreateWithWork((struct SaveDataParam *)(&_ExtraSaveDescs[slot]), heapId, work, workSize, 1);
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
void SAVE_CONTROL_CreateExtraSaveWithBuffer(struct SaveControl *saveControl, u32 slot, u32 heapId, void *work, u32 workSize)
{
    saveControl->extraSaves[slot] = BACKUP_SYSTEM_CreateWithWork((struct SaveDataParam *)(&_ExtraSaveDescs[slot]), heapId, work, workSize, 0);
}

void SAVE_CONTROL_DeleteExtraSaveBuffered(struct SaveControl *saveControl, u32 slot)
{
    if (saveControl->extraSaves[slot] == 0) {
        GF_PANIC_Fail(_EmptyString, 0, _EmptyString);
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
        GF_PANIC_Fail(_EmptyString, 0, _EmptyString);
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
        GF_PANIC_Fail(_EmptyString, 0, _EmptyString);
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
        GF_PANIC_Fail(_EmptyString, 0, _EmptyString);
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
        GF_PANIC_Fail(_EmptyString, 0, _EmptyString);
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

    BACKUP_SYSTEM_WriteFlash((u32)0x7F800, &zero, 4);
    BACKUP_SYSTEM_WriteFlash((u32)0x7FC00, &zero, 4);
}
