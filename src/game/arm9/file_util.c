/*
 * file:     file_util.c
 * unit:     yes
 * function: FILE_UTIL_OpenById, FILE_UTIL_LoadRange, FILE_UTIL_Get, FILE_UTIL_GetItemCount, FILE_UTIL_GetBankCount, FILE_UTIL_GetBaseIndex, FILE_UTIL_Create_0F14, FILE_UTIL_LoadArcMember, FILE_UTIL_CreateArcTool0F34, FILE_UTIL_ReadString, FILE_UTIL_ReadStringAlt, FILE_UTIL_Get_0FE4, FILE_UTIL_Get_1014, FILE_UTIL_GetMonProp, FILE_UTIL_Check1288, FILE_UTIL_Get_12B0, FILE_UTIL_Check12E4, FILE_UTIL_GetId, FILE_UTIL_GetMachineIndex, FILE_UTIL_Check136C, FILE_UTIL_GetItemSlot, FILE_UTIL_GetItemId
 * address:  0x02020DEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from bmp_menulist.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   func_0200575C  0x0200575C  thumb
 *   FS_InitFile  0x020788AC  arm
 *   FS_OpenFile  0x02078C18  arm
 *   FILE_UTIL_FILE_NAME     0x020A73B0  data
 *   FS_CloseFile   0x02078A80  arm
 *   FS_SeekFile    0x02078B44  arm
 *   FS_ReadFile    0x02078B70  arm
 *   FS_GetLength   0x02078C28  arm
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   ITEM_GFX_GetRowIndex       0x0202F170  thumb
 *   ARC_TOOL_CreateHandle       0x020490F4  arm
 *   ARC_TOOL_LoadHandleMember       0x02049250  arm
 *   ARC_TOOL_LoadMember       0x02048F60  arm
 *   item_gfx_member     0x0209EB6C  data
 *   item_gfx_member_x   0x0209E9E8  data
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   g_0209EAA0     0x0209EAA0  data
 *   g_0209E8EC     0x0209E8EC  data
 */
#include "bmp_menulist_shared_types.h"

typedef signed char    s8;

struct MsgBank;

struct ArcFile;

struct FSFile {
    u8 raw[0x48];
};

struct ItemGfxMember {
    u16 lo;
    u16 hi;
};

/* The extension record at +0x10 of the item record: packed fields. */
struct ItemExt {
    u8 cureSleep : 1;
    u8 curePoison : 1;
    u8 cureBurn : 1;
    u8 cureFreeze : 1;
    u8 cureParalysis : 1;
    u8 cureConfusion : 1;
    u8 cureInfatuation : 1;
    u8 guardSpec : 1;

    u8 revive : 1;
    u8 reviveAll : 1;
    u8 levelUp : 1;
    u8 evolve : 1;
    u8 atkStage : 4;

    u8 defStage : 4;
    u8 spAtkStage : 4;

    u8 spDefStage : 4;
    u8 accStage : 4;

    u8 critStage : 4;
    u8 ppRestoreKind : 2;
    u8 ppUp : 1;
    u8 ppUpMax : 1;

    u8 ppRestore : 1;
    u8 ppRestoreAll : 1;
    u8 hpRestore : 1;
    u8 hpEvUp : 1;
    u8 atkEvUp : 1;
    u8 defEvUp : 1;
    u8 speedEvUp : 1;
    u8 spAtkEvUp : 1;

    u8 spDefEvUp : 1;
    u8 friendshipLow : 1;
    u8 friendshipMid : 1;
    u8 friendshipHigh : 1;
    u8 evLimitIgnore : 1;

    s8 hpEv;
    s8 atkEv;
    s8 defEv;
    s8 speedEv;
    s8 spAtkEv;
    s8 spDefEv;
    u8 hpRestoreAmount;
    u8 ppRestoreAmount;
    s8 friendshipDeltaLow;
    s8 friendshipDeltaMid;
    s8 friendshipDeltaHigh;
};

/* The item data record header. */
struct ItemRecord {
    u16 price;
    u8  holdEffect;
    u8  holdEffectParam;
    u8  pluckEffect;
    u8  flingEffect;
    u8  flingPower;
    u8  naturalGiftPower;
    u16 naturalGiftType  : 5;
    u16 preventToss  : 1;
    u16 selectable  : 1;
    u16 pocket  : 4;
    u16 sortGroup : 5;
    u8  fieldUse;
    u8  battleUse;
    u8  extType;
    u8  partyUse;
    u8  partyUseParam;
    u8  partyUseOption;
    union {
        u8              f10;
        struct ItemExt  ext;
    } u;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *block);

extern void *func_0200575C(u32 archiveId);

extern void  FS_InitFile(struct FSFile *file);

extern void  FS_OpenFile(struct FSFile *file, void *path);

extern void  FS_CloseFile(struct FSFile *file);

extern u32   FS_SeekFile(struct FSFile *file, int offset, u32 origin);

extern u32   FS_ReadFile(struct FSFile *file, void *dst, u32 size);

extern u32   FS_GetLength(struct FSFile *file);

extern u32   ITEM_GFX_GetRowIndex(u32 item);

extern void *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);

extern void *ARC_TOOL_LoadMember(u32 archiveId, u32 member, u32 heap);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dst);

extern u32 MSGDATA_Delete(struct MsgBank *bank);

void FILE_UTIL_OpenById(struct FSFile *file, u32 archiveId);

void *FILE_UTIL_LoadRange(u32 archiveId, u32 heap, u32 offset, u32 size);

u32 FILE_UTIL_Get(u32 item, u32 which);

u32 FILE_UTIL_GetItemCount(void);

u32 FILE_UTIL_GetBankCount(void);

u32 FILE_UTIL_GetBaseIndex(void);

void *FILE_UTIL_Create_0F14(u32 heap);

void *FILE_UTIL_LoadArcMember(struct ArcFile *arc, u32 item, u32 heap);

void *FILE_UTIL_CreateArcTool0F34(u32 item, u32 which, u32 heap);

void FILE_UTIL_ReadString(void *dst, u32 entry, u32 heap);

void FILE_UTIL_ReadStringAlt(void *dst, u32 entry, u32 heap);

u32 FILE_UTIL_Get_0FE4(u32 item, u32 sel, u32 heap);

u32 FILE_UTIL_Get_1014(struct ItemRecord *record, u32 prop);

int FILE_UTIL_GetMonProp(struct ItemExt *ext, u32 prop);

u32 FILE_UTIL_Check1288(u32 id);

u16 FILE_UTIL_Get_12B0(u16 machineId);

u32 FILE_UTIL_Check12E4(u16 moveId);

u32 FILE_UTIL_GetId(u32 machineId);

u8 FILE_UTIL_GetMachineIndex(u16 machineId);

u32 FILE_UTIL_Check136C(u16 itemId);

u8 FILE_UTIL_GetItemSlot(u16 itemId);

u16 FILE_UTIL_GetItemId(u32 idx);

extern const char FILE_UTIL_FILE_NAME[];

extern struct ItemGfxMember item_gfx_member[];

extern struct ItemGfxMember item_gfx_member_x[];

extern const u16 g_0209EAA0[];

extern const u16 g_0209E8EC[];

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_OpenById.c \
 *       --func FILE_UTIL_OpenById --addr 0x02020DEC --cc 1.1p1 --thumb
 */
void FILE_UTIL_OpenById(struct FSFile *file, u32 archiveId)
{
    void *path;

    path = func_0200575C(archiveId);
    FS_InitFile(file);
    FS_OpenFile(file, path);
}

/*
 * "Read a byte range out of a whole file, by archive id", the raw-file
 * counterpart to the arc_tool.c NARC member API.  FILE_UTIL_OpenById (already
 * EXACT) opens the file whose path is name-table entry `archiveId`; this
 * function then seeks to `offset`, allocates `size` bytes on `heap` and
 * reads them in.  A zero `size` means "the whole file", which is why the
 * FS_GetLength call is guarded rather than unconditional.
 *
 * FILE_UTIL_FILE_NAME is the __FILE__ argument of the allocation site.  Its bytes
 * spell "file_util.c", and the run is fixed from outside this function by
 * the terminator of "bmp_cursor.c" immediately before it
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md), so the
 * enclosing translation unit for both this function and FILE_UTIL_OpenById is
 * file_util.c.
 *
 * The only caller in the image is ZONEDATA_CreateAreaData, the a/0/1/3 record reader
 * (src/matched/ZONEDATA_CreateAreaData.c), which passes archiveId 13 with size 10:
 * a/0/1/3 is a flat 2820-byte file, not a NARC, so it cannot go through
 * the member API at all.  See the "Archive readers traced by call graph"
 * section of docs/ASSETS.md.
 *
 * `size` has to stay live in its own local across the guarded call: the
 * compiler keeps r5 as both the parameter and the FS_GetLength result, so
 * writing the length into a fresh variable and selecting afterwards costs
 * an extra move.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_LoadRange.c \
 *       --func FILE_UTIL_LoadRange --addr 0x02020E08 --cc 1.1p1 --thumb
 */
void *FILE_UTIL_LoadRange(u32 archiveId, u32 heap, u32 offset, u32 size)
{
    struct FSFile file;
    void *data;

    FILE_UTIL_OpenById(&file, archiveId);
    if (size == 0) {
        size = FS_GetLength(&file);
    }
    data = GFL_HEAP_Alloc(heap, size, 0, FILE_UTIL_FILE_NAME, 0xAC);
    FS_SeekFile(&file, offset, 0);
    FS_ReadFile(&file, data, size);
    FS_CloseFile(&file);
    return data;
}

/*
 * The item archive's own accessor block: 0x02020E60..0x02020F84, seven
 * functions, five of them unlabelled leaves that print as a `.word`/`.byte`
 * run in the listing (see docs/idioms/unlabelled-leaf-functions-hide-in-
 * word-runs.md).
 *
 * This is the file that closes the item chain
 * FILE_UTIL_Get_1014 <- FILE_UTIL_Get_0FE4 <- FILE_UTIL_CreateArcTool0F34: three separate functions
 * here name the item archive id 0x18 as a plain immediate
 * (FILE_UTIL_Create_0F14's handle open, FILE_UTIL_CreateArcTool0F34's one-shot member read) and
 * two name the item graphics archive 0x19 (FILE_UTIL_GetItemCount answers it as a
 * constant, FILE_UTIL_CreateArcTool0F34 reads members of it).  Archive ids are the
 * decimal spelling of the a/X/Y/Z path, so 0x18 = 24 = a/0/2/4 and
 * 0x19 = 25 = a/0/2/5.
 *
 * 626 is the last item id: a/0/2/4 has 627 members, 0..626.  Both bounds
 * checks in this file clamp an out of range id to 0 rather than rejecting.
 *
 * Blocked at MATCH, not EXACT: three relocation sites have no witness
 * outside this range.
 *   - item_gfx_member_x (0x0209E9E8) and ITEM_GFX_GetRowIndex (0x0202F170) are
 *     named only from here anywhere in the image.
 *   - item_gfx_member (0x0209EB6C) has exactly one literal witness,
 *     0x02020F7C, which is FILE_UTIL_CreateArcTool0F34's own pool and therefore inside
 *     this range.  FILE_UTIL_Get's copy of the same word sits at
 *     0x02020EF4 but is not indexed as a literal pool by disasm.py: that
 *     pool is inside the `.byte` run this unit's leaf functions live in.
 *     Splitting FILE_UTIL_Get and FILE_UTIL_CreateArcTool0F34 into two files does not
 *     fix it either: verified separately, the split leaves
 *     FILE_UTIL_Get attested (literal 0x02020F7C, now outside its range)
 *     and FILE_UTIL_CreateArcTool0F34 still not, since its only witness is its own
 *     pool word.  `tu --suggest-split` agrees and leaves both out.
 *
 * The middle piece that --suggest-split does keep, the five leaf
 * accessors 0x02020F08..0x02020F34, is filed EXACT on its own as
 * src/matched/unit_02020F08.c; this file stays as the whole-range record.
 *
 * Every concrete byte of this range is reproduced; only the relocation
 * fields above stay wildcarded.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02020E60.c \
 *       --addr 0x02020E60 --thumb
 */
u32 FILE_UTIL_Get(u32 item, u32 which)
{
    if (item > 626) {
        item = 0;
    }

    switch (which) {
    case 0:
        if (item == 0 || item == 0xFFFF) {
            break;
        }
        return item;
    case 1:
        if (item == 0) {
            return 1001;
        }
        if (item == 0xFFFF) {
            return 1003;
        }
        return item_gfx_member[item].lo;
    case 2:
        if (item == 0) {
            return 1002;
        }
        if (item == 0xFFFF) {
            return 1004;
        }
        return item_gfx_member[item].hi;
    case 3:
        return item_gfx_member_x[ITEM_GFX_GetRowIndex(item)].lo;
    case 4:
        return item_gfx_member_x[ITEM_GFX_GetRowIndex(item)].hi;
    }

    return 0;
}

u32 FILE_UTIL_GetItemCount(void)
{
    return 0x19;
}

u32 FILE_UTIL_GetBankCount(void)
{
    return 1;
}

u32 FILE_UTIL_GetBaseIndex(void)
{
    return 0;
}

void *FILE_UTIL_Create_0F14(u32 heap)
{
    return ARC_TOOL_CreateHandle(0x18, heap);
}

void *FILE_UTIL_LoadArcMember(struct ArcFile *arc, u32 item, u32 heap)
{
    if (item > 626) {
        item = 0;
    }

    return ARC_TOOL_LoadHandleMember(arc, item, heap);
}

void *FILE_UTIL_CreateArcTool0F34(u32 item, u32 which, u32 heap)
{
    if (item > 626) {
        item = 0;
    }

    switch (which) {
    case 0:
        return ARC_TOOL_LoadMember(0x18, item, heap);
    case 1:
        return ARC_TOOL_LoadMember(0x19, item_gfx_member[item].lo, heap);
    case 2:
        return ARC_TOOL_LoadMember(0x19, item_gfx_member[item].hi, heap);
    }

    return 0;
}

/*
 * One of a pair of near-identical entry points (FILE_UTIL_ReadString uses table 0x36,
 * FILE_UTIL_ReadStringAlt table 0x35) that open a message archive, read one entry into
 * the caller's buffer and close it again.  An out-of-range entry index falls
 * back to 0; the bound 0x272 is one more than the last id FILE_UTIL_Check1288
 * accepts, which is why it is a pool word rather than a folded immediate.
 *
 * The heap argument stays in r3 across the guard because it is the fourth
 * argument of the archive open, not a leftover: the ARM callee clobbers r0-r3,
 * so a value still in r3 at the second call could not have survived the first
 * (docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-
 * arity.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_ReadString.c  *       --func FILE_UTIL_ReadString --addr 0x02020F84 --cc 1.1p1 --thumb
 */
void FILE_UTIL_ReadString(void *dst, u32 entry, u32 heap)
{
    void *bank;

    if (entry > 0x272) {
        entry = 0;
    }
    bank = MSGDATA_CreateFromArchive(0, 2, 0x36, heap);
    MSGDATA_ReadString(bank, entry, dst);
    MSGDATA_Delete(bank);
}

/*
 * One of a pair of near-identical entry points (FILE_UTIL_ReadString uses table 0x36,
 * FILE_UTIL_ReadStringAlt table 0x35) that open a message archive, read one entry into
 * the caller's buffer and close it again.  An out-of-range entry index falls
 * back to 0; the bound 0x272 is one more than the last id FILE_UTIL_Check1288
 * accepts, which is why it is a pool word rather than a folded immediate.
 *
 * The heap argument stays in r3 across the guard because it is the fourth
 * argument of the archive open, not a leftover: the ARM callee clobbers r0-r3,
 * so a value still in r3 at the second call could not have survived the first
 * (docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-
 * arity.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_ReadStringAlt.c  *       --func FILE_UTIL_ReadStringAlt --addr 0x02020FB4 --cc 1.1p1 --thumb
 */
void FILE_UTIL_ReadStringAlt(void *dst, u32 entry, u32 heap)
{
    void *bank;

    if (entry > 0x272) {
        entry = 0;
    }
    bank = MSGDATA_CreateFromArchive(0, 2, 0x35, heap);
    MSGDATA_ReadString(bank, entry, dst);
    MSGDATA_Delete(bank);
}

/*
 * One-shot wrapper over the record getter of src/matched/unit_02021014.c:
 * build a temporary record for the id (with bit 15 forced on and the rest of
 * the id masked to fifteen bits), read one property out of it, free it, and
 * answer the property.
 *
 * 0x8000 costs no second pool word: the compiler keeps 0x7FFF in r3 for the
 * mask and derives the set bit from it with `adds r2, r3, #1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_Get_0FE4.c \
 *       --func FILE_UTIL_Get_0FE4 --addr 0x02020FE4 --cc 1.1p1 --thumb
 */
u32 FILE_UTIL_Get_0FE4(u32 item, u32 sel, u32 heap)
{
    struct ItemRecord *record;
    u32   value;

    record = FILE_UTIL_CreateArcTool0F34(item, 0, (u16)((heap & 0x7FFF) | 0x8000));
    value = FILE_UTIL_Get_1014(record, sel);
    GFL_HEAP_Free(record);
    return value;
}

/*
 * A whole translation unit range, matched as one byte range.
 *
 * The two halves of one property-getter interface over a packed record: a
 * caller hands in a record pointer and a property id, and gets an unsigned
 * quantity back.  Ids 0..0x11 are answered by FILE_UTIL_Get_1014 out of the record
 * header; anything above that is delegated, for one of the two header layouts,
 * to FILE_UTIL_GetMonProp on the sub-record at +0x10, which answers ids 0x12..0x3E out
 * of a seventeen-byte bitfield block.
 *
 * The two are one file rather than two because FILE_UTIL_Get_1014's call to
 * FILE_UTIL_GetMonProp is the only branch to that address anywhere in the image: as
 * separate files neither can attest the other and both cap at MATCH, while in
 * one translation unit the call is `local` and needs no image evidence at all
 * (docs/AGENT-BRIEF.md section 5, the `local` class).
 *
 * Two shape findings, both of which cost real bytes:
 *
 *  - FILE_UTIL_Get_1014's dispatch runs in r2, not in the switch value's own r1
 *    (docs/idioms/a-void-return-frees-r0-for-the-switch-dispatch-index.md: the
 *    index register is the switch value's register only when that register is
 *    dead across the arms).  Here it is not dead, and the reason is the
 *    delegation: FILE_UTIL_GetMonProp takes the property id as its second argument,
 *    which is already sitting in r1, so the call site sets only r0 and r1 stays
 *    live to the end of the function.  Declaring FILE_UTIL_GetMonProp as a one
 *    argument function is byte for byte right everywhere else and wrong in
 *    those nine bytes.  FILE_UTIL_GetMonProp's own `subs r1, #0x12` is the independent
 *    confirmation that its second parameter is the same id.
 *  - the fall-through of FILE_UTIL_Get_1014 is a two-case `switch` on the header
 *    byte at +0xC, not a chain of `if`s: the switch form emits
 *    cmp/beq, cmp/beq, b-to-default, the `if` chain emits the inverted
 *    bne-over form and is two bytes shorter.
 *
 * The `ldrsb r0, [r0, r1]` arms of FILE_UTIL_GetMonProp are the signedness evidence
 * for the six plain fields at +7..+0xC and the three at +0xF..+0x11: there is
 * no immediate-offset `ldrsb`, so a signed byte load has to materialise its
 * offset in a register (docs/idioms/ldrsh-register-offset-is-signedness.md).
 * +0xD and +0xE load with a plain `ldrb` and are unsigned, which is why the
 * declared return type has to be signed for the rest to sign-extend.
 *
 * Addresses are Black-image addresses.  The bitfield block's contents are
 * content data, not code shape: if Pokemon White sizes this record
 * differently, the field list here is the thing to re-derive, not the dispatch.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02021014.c \
 *       --addr 0x02021014 --thumb
 */
u32 FILE_UTIL_Get_1014(struct ItemRecord *record, u32 prop)
{
    switch (prop) {
    case 0:
        return record->price * 10;
    case 1:
        return record->holdEffect;
    case 2:
        return record->holdEffectParam;
    case 3:
        return record->preventToss;
    case 4:
        return record->selectable;
    case 5:
        return record->pocket;
    case 6:
        return record->fieldUse;
    case 7:
        return record->battleUse;
    case 8:
        return record->pluckEffect;
    case 9:
        return record->flingEffect;
    case 10:
        return record->flingPower;
    case 11:
        return record->naturalGiftPower;
    case 12:
        return record->naturalGiftType;
    case 13:
        return record->sortGroup;
    case 14:
        return record->extType;
    case 15:
        return record->partyUse;
    case 16:
        return record->partyUseParam;
    case 17:
        return record->partyUseOption;
    }

    switch (record->extType) {
    case 0:
        return record->u.f10;
    case 1:
        return FILE_UTIL_GetMonProp(&record->u.ext, prop);
    }
    return 0;
}

int FILE_UTIL_GetMonProp(struct ItemExt *ext, u32 prop)
{
    switch (prop) {
    case 0x12:
        return ext->cureSleep;
    case 0x13:
        return ext->curePoison;
    case 0x14:
        return ext->cureBurn;
    case 0x15:
        return ext->cureFreeze;
    case 0x16:
        return ext->cureParalysis;
    case 0x17:
        return ext->cureConfusion;
    case 0x18:
        return ext->cureInfatuation;
    case 0x19:
        return ext->guardSpec;
    case 0x1A:
        return ext->revive;
    case 0x1B:
        return ext->reviveAll;
    case 0x1C:
        return ext->levelUp;
    case 0x1D:
        return ext->evolve;
    case 0x1E:
        return ext->atkStage;
    case 0x1F:
        return ext->defStage;
    case 0x20:
        return ext->spAtkStage;
    case 0x21:
        return ext->spDefStage;
    case 0x22:
        return ext->accStage;
    case 0x23:
        return ext->critStage;
    case 0x24:
        return ext->ppRestoreKind;
    case 0x25:
        return ext->ppUp;
    case 0x26:
        return ext->ppUpMax;
    case 0x27:
        return ext->ppRestore;
    case 0x28:
        return ext->ppRestoreAll;
    case 0x29:
        return ext->hpRestore;
    case 0x2A:
        return ext->hpEvUp;
    case 0x2B:
        return ext->atkEvUp;
    case 0x2C:
        return ext->defEvUp;
    case 0x2D:
        return ext->speedEvUp;
    case 0x2E:
        return ext->spAtkEvUp;
    case 0x2F:
        return ext->spDefEvUp;
    case 0x30:
        return ext->friendshipLow;
    case 0x31:
        return ext->friendshipMid;
    case 0x32:
        return ext->friendshipHigh;
    case 0x33:
        return ext->evLimitIgnore;
    case 0x34:
        return ext->hpEv;
    case 0x35:
        return ext->atkEv;
    case 0x36:
        return ext->defEv;
    case 0x37:
        return ext->speedEv;
    case 0x38:
        return ext->spAtkEv;
    case 0x39:
        return ext->spDefEv;
    case 0x3A:
        return ext->hpRestoreAmount;
    case 0x3B:
        return ext->ppRestoreAmount;
    case 0x3C:
        return ext->friendshipDeltaLow;
    case 0x3D:
        return ext->friendshipDeltaMid;
    case 0x3E:
        return ext->friendshipDeltaHigh;
    }
    return 0;
}

/*
 * The membership test for the two id windows this file's tables are indexed
 * by: 0x148..0x1A9 and 0x26A..0x26C.  Written as one disjunction so that both
 * true arms share the single `movs r0, #1` exit and both false arms the single
 * `movs r0, #0` (docs/idioms/disjunction-must-be-one-expression-to-share-its-
 * exit.md); as two separate `if` statements each window grows its own return.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_Check1288.c \
 *       --func FILE_UTIL_Check1288 --addr 0x02021288 --cc 1.1p1 --thumb
 */
u32 FILE_UTIL_Check1288(u32 id)
{
    if ((id >= 0x148 && id <= 0x1A9) || (id >= 0x26A && id <= 0x26C)) {
        return 1;
    }
    return 0;
}

/*
 * Halfword lookup keyed by one of the two id windows FILE_UTIL_Check1288 accepts:
 * 0x148..0x1A9 maps to entries 0..0x61 of the table at 0x0209EAA0 and
 * 0x26A..0x26C continues at 0x62..0x64, which is why the second window's
 * subtrahend is 0x208 rather than its own start.  Ids outside both windows
 * answer 0.
 *
 * The two subtrahends are one constant: the compiler keeps 0x26A in r0 for the
 * window test and derives 0x208 from it with `subs r0, #0x62` rather than
 * spending a second pool word.
 *
 * The id parameter is `u16` and the subtraction is written back into it, not
 * into a fresh local.  That is what puts the index in r4, the parameter's own
 * callee-saved home, and leaves r0 free for the table base: with a separate
 * `u16 i` local the narrowed index is a dead temporary, lands in r0, and the
 * last three instructions come out in the other order, five bytes wrong.  A
 * `u32` parameter with an explicit `(u16)` cast is the same five bytes wrong,
 * so the `u16` parameter type is real evidence and not a spelling choice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_Get_12B0.c \
 *       --func FILE_UTIL_Get_12B0 --addr 0x020212B0 --cc 1.1p1 --thumb
 */
u16 FILE_UTIL_Get_12B0(u16 machineId)
{
    if (FILE_UTIL_Check1288(machineId) == 0) {
        return 0;
    }
    if (machineId >= 0x26A) {
        machineId -= 0x208;
    } else {
        machineId -= 0x148;
    }
    return g_0209EAA0[machineId];
}

/*
 * Linear search of the six-entry tail of the same halfword table
 * FILE_UTIL_Get_12B0 indexes, entries 0x5C..0x61.  The 0xB8 byte offset is kept out
 * of the `ldrh` encoding because it is past the halfword load's +62 reach
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md), so the address comes
 * out as base, plus the scaled index, plus a separate `adds r1, #0xb8`.
 *
 * The counter is a `u8`: the increment is `adds`/`lsls #0x18`/`lsrs #0x18`
 * through a scratch register, which a `u32` counter does not produce.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_Check12E4.c \
 *       --func FILE_UTIL_Check12E4 --addr 0x020212E4 --cc 1.1p1 --thumb
 */
u32 FILE_UTIL_Check12E4(u16 moveId)
{
    u8 idx;

    for (idx = 0; idx < 6; idx++) {
        if (moveId == g_0209EAA0[0x5C + idx]) {
            return 1;
        }
    }
    return 0;
}

/*
 * Maps an id in one of FILE_UTIL_Check1288's two accepted windows onto a byte-wide
 * slot number, in three ranges with three different subtrahends: 0x26A.. off
 * 0x20E, 0x1A4..0x269 off 0x145, and the rest off 0x148.  Ids the window test
 * rejects answer 0xFF.
 *
 * Only two pool words: 0x26A is loaded once and 0x1A4 derived from it with
 * `subs r0, #0xc6`, the same constant-sharing FILE_UTIL_Get_12B0 does.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_GetId.c \
 *       --func FILE_UTIL_GetId --addr 0x0202130C --cc 1.1p1 --thumb
 */
u32 FILE_UTIL_GetId(u32 machineId)
{
    if (FILE_UTIL_Check1288(machineId) == 0) {
        return 0xFF;
    }
    if (machineId >= 0x26A) {
        return (u8)(machineId - 0x20E);
    }
    if (machineId >= 0x1A4) {
        return (u8)(machineId - 0x145);
    }
    return (u8)(machineId - 0x148);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_GetMachineIndex.c  *       --func FILE_UTIL_GetMachineIndex --addr 0x02021350 --cc 1.1p1 --thumb
 */
u8 FILE_UTIL_GetMachineIndex(u16 machineId)
{
    if (machineId >= 0x1A4 && machineId <= 0x1A9) {
        return (u8)(machineId - 0x1A4);
    }
    return 0xFF;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_Check136C.c  *       --func FILE_UTIL_Check136C --addr 0x0202136C --cc 1.1p1 --thumb
 */
u32 FILE_UTIL_Check136C(u16 itemId)
{
    u32 idx;

    for (idx = 0; idx < 0xC; idx++) {
        if (itemId == g_0209E8EC[idx]) {
            return 1;
        }
    }
    return 0;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_GetItemSlot.c  *       --func FILE_UTIL_GetItemSlot --addr 0x0202138C --cc 1.1p1 --thumb
 */
u8 FILE_UTIL_GetItemSlot(u16 itemId)
{
    u32 idx;

    for (idx = 0; idx < 0xC; idx++) {
        if (itemId == g_0209E8EC[idx]) {
            return (u8)idx;
        }
    }
    return 0;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_GetItemId.c  *       --func FILE_UTIL_GetItemId --addr 0x020213AC --cc 1.1p1 --thumb
 */
u16 FILE_UTIL_GetItemId(u32 idx)
{
    if (idx >= 0xC) {
        return 0;
    }
    return g_0209E8EC[idx];
}
