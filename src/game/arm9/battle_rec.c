/*
 * file:     battle_rec.c
 * unit:     yes
 * function: BATTLE_REC_Create, BATTLE_REC_AllocWork, BATTLE_REC_FreeWork, BATTLE_REC_Delete, BATTLE_REC_GetWorkSize, BATTLE_REC_Clear, BATTLE_REC_IsDataExist, BATTLE_REC_ClearWork, BATTLE_REC_DecodeWork, BATTLE_REC_EncodeWork, BATTLE_REC_LoadToWork, BATTLE_REC_Load, BATTLE_REC_LoadAlloc, BATTLE_REC_CheckSaved, BATTLE_REC_SaveSeq, BATTLE_REC_BeginSave, BATTLE_REC_GetModeLayout, BATTLE_REC_MakeHeader, BATTLE_REC_IsMagicBroken, BATTLE_REC_IsValid, BATTLE_REC_Decode, BATTLE_REC_Encode, BATTLE_REC_GetWork, BATTLE_REC_GetBody, BATTLE_REC_GetHeader, BATTLE_REC_GetHeaderOf, BATTLE_REC_SetData, BATTLE_REC_GetHeaderParam, BATTLE_REC_IsVersionSupported, BATTLE_REC_SetBodyCrc, BATTLE_REC_LoadToolOverlay, BATTLE_REC_UnloadToolOverlay
 * address:  0x0200B3DC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_rec.c by tools/splitfile.py.
 *
 * symbols:
 *   _BattleRecFileName  0x020A71C4  data
 *   GFL_HEAP_Free   0x020307B0  arm
 *   pBattleRec   0x0214616C  data
 *   MIi_CpuClear32  0x02082A7C  arm
 *   GF_STANDARD_Checksum   0x0203F2FC  arm
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 *   MI_CpuFill8          0x02082BCC  arm
 *   GF_STANDARD_ShuffleEx  0x0203F37C  arm
 *   GF_STANDARD_Shuffle  0x0203F328  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   BattleRecModeTable 0x0209DDCC data
 *   ov188_id       0x000000BC  data  a1
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SAVE_CONTROL_DeleteExtraSave  0x020072A4  thumb
 *   SAVE_CONTROL_GetExtraSaveRecord  0x020073D8  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   SAVE_CONTROL_CreateExtraSaveWithBuffer  0x02007324  thumb
 *   SAVE_CONTROL_DeleteExtraSaveBuffered  0x0200734C  thumb
 */
#include "battle_rec_types.h"
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int s32;
typedef unsigned short u16;

typedef unsigned long long u64;

#define BATTLE_REC_MAGIC 0xE281

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void MIi_CpuClear32(u32 data, void *dest, u32 size);

extern u32 SAVE_CONTROL_LoadExtraSave(struct SaveControl *save, u32 id, u32 heap);

extern void SAVE_CONTROL_DeleteExtraSave(struct SaveControl *save, u32 id);

extern u32 SAVE_CONTROL_LoadExtraSaveWithBuffer(struct SaveControl *save, u32 id, u32 heap, void *buf, u32 size);

extern void SAVE_CONTROL_CreateExtraSaveWithBuffer(struct SaveControl *save, u32 id, u32 heap, void *buf, u32 size);

extern void SAVE_CONTROL_DeleteExtraSaveBuffered(struct SaveControl *save, u32 id);

extern void *SAVE_CONTROL_GetExtraSaveRecord(struct SaveControl *save, u32 id, u32 arg);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern u32 GFL_HEAP_Free(void *mem);

extern u32 GF_STANDARD_Checksum(const u8 *data, u32 size);

extern u16 GF_STANDARD_SetupCalc(const u8 *data, u32 size);

extern void GF_STANDARD_Shuffle(void *data, u32 size, u32 code);

extern void GF_STANDARD_ShuffleEx(void *data, u32 size, u32 code);

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);

extern void GAME_DATA_PartSaveStart(struct GameData *gameData, u32 id);

extern int GAME_DATA_PartSaveMain(struct GameData *gameData, int id);

extern int GF_OVERLAY_Load(u32 overlayId);

extern void GF_OVERLAY_Unload(u32 overlayId);

struct BattleRecSave *BATTLE_REC_Create(u32 heap);

void BATTLE_REC_AllocWork(u32 heap);

void BATTLE_REC_FreeWork(void);

void BATTLE_REC_Delete(struct BattleRecSave *rec);

u32 BATTLE_REC_GetWorkSize(void);

void BATTLE_REC_Clear(struct BattleRecSave *rec);

u32 BATTLE_REC_IsDataExist(void);

void BATTLE_REC_ClearWork(void);

void BATTLE_REC_DecodeWork(void);

void BATTLE_REC_EncodeWork(void);

u32 BATTLE_REC_LoadToWork(struct SaveControl *save, struct BattleRecSave *rec, u32 heap, u32 *result, u32 id);

u32 BATTLE_REC_Load(struct SaveControl *save, u16 heap, u32 *result, u32 id);

struct BattleRecSave *BATTLE_REC_LoadAlloc(struct SaveControl *save, u32 heap, u32 *result, u32 id);

u32 BATTLE_REC_CheckSaved(struct SaveControl *save, u32 heap, u32 *result, u32 id);

u32 BATTLE_REC_SaveSeq(struct GameData *gameData, struct BattleRecSave *rec, u32 id, u16 *seq, u16 heap);

u32 BATTLE_REC_BeginSave(struct GameData *gameData, u16 heap, u32 modeIndex, u32 battleCount, u32 id, u16 *seq, u16 *subSeq);

void BATTLE_REC_GetModeLayout(u16 mode, s32 *sides, s32 *members);

void BATTLE_REC_MakeHeader(struct SaveControl *save, struct BattleRecHeader *head, const struct BattleRecBody *body, u32 modeIndex, u32 battleCount);

u32 BATTLE_REC_IsMagicBroken(struct SaveControl *save, struct BattleRecSave *rec);

u32 BATTLE_REC_IsValid(struct SaveControl *save, struct BattleRecSave *rec);

void BATTLE_REC_Decode(void *data, u32 size, u32 code);

void BATTLE_REC_Encode(void *data, u32 size, u32 code);

struct BattleRecSave *BATTLE_REC_GetWork(void);

struct BattleRecBody *BATTLE_REC_GetBody(void);

struct BattleRecHeader *BATTLE_REC_GetHeader(void);

struct BattleRecHeader *BATTLE_REC_GetHeaderOf(struct BattleRecSave *rec);

void BATTLE_REC_SetData(const void *profile, const struct BattleRecHeader *head, const struct BattleRecBody *body);

u64 BATTLE_REC_GetHeaderParam(const struct BattleRecHeader *head, int param, int index);

u32 BATTLE_REC_IsVersionSupported(u32 version);

void BATTLE_REC_SetBodyCrc(struct BattleRecBody *body);

void BATTLE_REC_LoadToolOverlay(void);

void BATTLE_REC_UnloadToolOverlay(void);

extern const char _BattleRecFileName[];

extern struct BattleRecSave *pBattleRec;

extern const u16 BattleRecModeTable[];

extern char ov188_id[];

struct BattleRecSave *BATTLE_REC_Create(u32 heap)
{
    struct BattleRecSave *rec = GFL_HEAP_Alloc(heap, 0x2000, 1, _BattleRecFileName, 0x67);

    BATTLE_REC_Clear(rec);
    return rec;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 72 bytes, 0x0200B400..0x0200B448, 4 functions, three of which carry no
 * label in the generated listing: the last three save nothing or nothing but
 * r4, so the range arrives as a run of `.word`s.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * alias: this continues "battle_rec.c", whose constructor BATTLE_REC_Create is
 * the last function of src/matched/unit_0200B394.c and is what BATTLE_REC_AllocWork
 * calls.  The object it builds is hung off the single global at 0x0214616C,
 * the same one src/matched/unit_0200B900.c reads.
 *
 * BATTLE_REC_AllocWork frees the old object before building the new one and clears
 * the global in between, which is a guard the source wrote rather than dead
 * code: the store of NULL is inside the `if`, and the fresh pointer is
 * assigned unconditionally afterwards.  The address of the global is
 * materialised twice, once for the test and free and once for the final
 * store, because the pool word is reloaded after the call rather than kept
 * in the callee-saved register that already holds it.
 *
 * BATTLE_REC_GetWorkSize returns 0x18A4 out of its own pool word, which is the
 * "a block file opens with a function returning its own size" shape this
 * region keeps producing, except that here the size belongs to whatever the
 * next file allocates rather than to the 0x2000 buffer above it.
 */
void BATTLE_REC_AllocWork(u32 heap)
{
    if (pBattleRec != 0) {
        GFL_HEAP_Free(pBattleRec);
        pBattleRec = 0;
    }
    pBattleRec = BATTLE_REC_Create(heap);
}

void BATTLE_REC_FreeWork(void)
{
    GFL_HEAP_Free(pBattleRec);
    pBattleRec = 0;
}

void BATTLE_REC_Delete(struct BattleRecSave *rec)
{
    GFL_HEAP_Free(rec);
}

u32 BATTLE_REC_GetWorkSize(void)
{
    return sizeof(struct BattleRecSave);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           BATTLE_REC_EncodeWork
 *
 * 152 bytes, 0x0200B448..0x0200B4E0, 5 functions, three of which carry no
 * label in the generated listing.
 *
 * alias: this continues "battle_rec.c"; BATTLE_REC_Clear is the buffer clear the
 * constructor BATTLE_REC_Create calls, and the object is the 0x18A4-byte record
 * at 0x0214616C that src/matched/unit_0200B400.c allocates and
 * src/matched/unit_0200B938.c publishes.
 *
 * Two things are worth recording.
 *
 *  - BATTLE_REC_DecodeWork and BATTLE_REC_EncodeWork are the same four instructions of
 *    checksum arithmetic as BATTLE_REC_SetData, but as **tail calls**, and that
 *    changes the callee's arity.  A tail call needs r3 for the branch target,
 *    so the fourth argument BATTLE_REC_SetData passes cannot be passed here: the
 *    `ldrh r3` that loads the halfword is overwritten by the `ldr r3, [pc]`
 *    that loads BATTLE_REC_Decode's address.  The callee is therefore declared
 *    with three parameters in this file and with four in
 *    src/matched/unit_0200B900.c, and both are right, because nothing in
 *    BATTLE_REC_Decode reads its arguments.  A four-argument call here compiles
 *    to `push {r3, lr}` / `bl` / `pop` and is eight bytes longer.
 *  - the length 0x17DC is reached as `subs r1, #0xc4` off the 0x18A0 the
 *    halfword load already needed, and 0x18A0 itself is a pool word rather
 *    than a `movs`, so the file spends one pool word where BATTLE_REC_SetData
 *    spends none for the same value.  That is a consequence of the tail call
 *    having no register to spare, not of the source.
 */
void BATTLE_REC_Clear(struct BattleRecSave *rec)
{
    MIi_CpuClear32(0, rec, sizeof(struct BattleRecSave));
}

u32 BATTLE_REC_IsDataExist(void)
{
    if (GF_STANDARD_Checksum((const u8 *)(&pBattleRec->body), sizeof(pBattleRec->body))
        != 0) {
        return 1;
    }
    return 0;
}

void BATTLE_REC_ClearWork(void)
{
    BATTLE_REC_Clear(pBattleRec);
}

void BATTLE_REC_DecodeWork(void)
{
    u16 crc = pBattleRec->body.crc;

    BATTLE_REC_Decode(&pBattleRec->body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
}

void BATTLE_REC_EncodeWork(void)
{
    u16 crc = pBattleRec->body.crc;

    BATTLE_REC_Encode(&pBattleRec->body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 236 bytes, 0x0200B4E0..0x0200B5CC, 3 functions, all three of which carry a
 * label in the generated listing.
 *
 * alias: inside "battle_rec.c"; see src/matched/unit_0200B394.c for how the
 * name at 0x020A71C4 is attested and src/matched/unit_0200B448.c for the
 * 0x18A4-byte record these work on.
 *
 * BATTLE_REC_LoadToWork loads a saved battle record and classifies the result into
 * the caller's status word: 0 when the block is absent, 3 when the load
 * failed, 0 again when the record's own check rejects it, 2 when the second
 * check does, and 1 when it is good.  Every arm writes the status and returns
 * 1, and the last arm shares its `movs r0, #1` between the store and the
 * return, which is the compiler reusing one constant and not two statements.
 *
 * The address of the checksummed sub-record is a named local, not
 * `&rec->body` written out at each of the three uses: with the local the base
 * is formed once as `adds r0, #0xc4` and the field offset 0x17DC is the
 * register operand, and written inline the compiler folds 0xC4 + 0x17DC into
 * one pool word of 0x18A0 and then subtracts 0xC4 back off it, which is two
 * instructions more.
 *
 * This range stops at 0x0200B5CC and src/matched/unit_0200B5CC.c starts
 * there, because BATTLE_REC_IsMagicBroken and BATTLE_REC_IsValid are each called exactly
 * twice in the image, once from BATTLE_REC_LoadToWork and once from BATTLE_REC_CheckSaved;
 * one range holding both pairs has no witness left for either and caps at
 * MATCH with every byte right.  Cut between them, each file is the other's
 * witness.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md. *
 */
u32 BATTLE_REC_LoadToWork(struct SaveControl *save, struct BattleRecSave *rec, u32 heap, u32 *result, u32 id)
{
    struct BattleRecBody *body;
    u16 crc;

    *result = SAVE_CONTROL_LoadExtraSaveWithBuffer(save, id, heap, rec, 0x2000);
    SAVE_CONTROL_DeleteExtraSave(save, id);
    if (*result == 0) {
        *result = 0;
        return 1;
    }
    if (*result != 1) {
        *result = 3;
        return 1;
    }
    body = &rec->body;
    crc = body->crc;
    BATTLE_REC_Decode(body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
    if (BATTLE_REC_IsMagicBroken(save, rec) == 1) {
        *result = 0;
        return 1;
    }
    if (BATTLE_REC_IsValid(save, rec) == 0) {
        *result = 2;
        return 1;
    }
    *result = 1;
    return 1;
}

u32 BATTLE_REC_Load(struct SaveControl *save, u16 heap, u32 *result, u32 id)
{
    if (pBattleRec != 0) {
        BATTLE_REC_Clear(pBattleRec);
    } else {
        BATTLE_REC_AllocWork(heap);
    }
    return BATTLE_REC_LoadToWork(save, pBattleRec, heap, result, id);
}

struct BattleRecSave *BATTLE_REC_LoadAlloc(struct SaveControl *save, u32 heap, u32 *result, u32 id)
{
    struct BattleRecSave *rec = BATTLE_REC_Create(heap);

    BATTLE_REC_LoadToWork(save, rec, heap, result, id);
    return rec;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 176 bytes, 0x0200B5CC..0x0200B67C, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "battle_rec.c".  The same classification BATTLE_REC_LoadToWork does,
 * over a record the save system already holds rather than one just read, and
 * with a `SAVE_CONTROL_DeleteExtraSave` release on every path instead of only on entry.  See
 * src/matched/unit_0200B4E0.c for why the two are separate files. *
 */
u32 BATTLE_REC_CheckSaved(struct SaveControl *save, u32 heap, u32 *result, u32 id)
{
    struct BattleRecSave *rec;
    struct BattleRecBody *body;
    u16 crc;

    *result = SAVE_CONTROL_LoadExtraSave(save, id, heap);
    rec = SAVE_CONTROL_GetExtraSaveRecord(save, id, 0);
    if (*result == 0) {
        *result = 0;
        SAVE_CONTROL_DeleteExtraSave(save, id);
        return 0;
    }
    if (*result != 1) {
        *result = 3;
        SAVE_CONTROL_DeleteExtraSave(save, id);
        return 0;
    }
    body = &rec->body;
    crc = body->crc;
    BATTLE_REC_Decode(body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
    if (BATTLE_REC_IsMagicBroken(save, rec) == 1) {
        *result = 0;
        SAVE_CONTROL_DeleteExtraSave(save, id);
        return 0;
    }
    if (BATTLE_REC_IsValid(save, rec) == 0) {
        *result = 2;
        SAVE_CONTROL_DeleteExtraSave(save, id);
        return 0;
    }
    *result = 1;
    SAVE_CONTROL_DeleteExtraSave(save, id);
    return 1;
}

/*
 * 264 bytes, 0x0200B67C..0x0200B784, 2 functions, both labelled.  Every
 * concrete byte reproduces.
 *
 * What held it open, and what closed it.  Two call targets have exactly one
 * caller in the whole image and that caller is here:
 *
 *   0x02007324  reached only from 0x0200B6A6, inside BATTLE_REC_SaveSeq
 *   0x0200B7D8  reached only from 0x0200B71A, inside BATTLE_REC_BeginSave
 *
 * Shrinking the range to one function keeps the call that needs the witness in
 * it, which is the limit `docs/MATCHING.md` states for the cut remedy, so no
 * image class could carry either site.  Both are now `matched`:
 * 0x02007324 is src/matched/unit_02007324.c and 0x0200B7D8 is
 * src/matched/unit_0200B7D8.c, two EXACT entries proved byte for byte against
 * the original over ranges this file does not touch.  Pulling either function
 * across the boundary into this range is no longer needed, and would have been
 * wrong anyway: the two belong to different original files.
 *
 * alias: inside "battle_rec.c"; the two steps of the record-save state machine
 * that BATTLE_REC_LoadToWork and BATTLE_REC_CheckSaved read back.
 *
 * Three things cost time here.
 *
 *  - GAME_DATA_GetSaveControl is declared with **one** parameter, not four.  The call
 *    leaves r1 through r3 holding this function's own second, third and fourth
 *    arguments, which reads like a four-argument call and is not one: declaring
 *    four parameters keeps `b` live from the entry and the whole of
 *    BATTLE_REC_BeginSave's case 0 is then allocated the other way round, with the two
 *    sub-record pointers sharing registers with `b` instead of with `a`.  Seven
 *    bytes, and none of them in the arithmetic.  src/matched/unit_0200C9EC.c
 *    declares the same extern with one parameter.
 *  - inside case 0 the two sub-record pointers have to be assigned
 *    `head = &rec->head;` first and `body = &rec->body;` second.  The second
 *    assignment is the last use of `rec`, so it takes over `rec`'s register and the first one
 *    gets the copy; writing them the other way round swaps which of the two is
 *    the `adds rD, rP, #0` and is five bytes.
 *  - the state word is read with `switch (*state)` over the constants 0 and 1,
 *    which is the `cmp #0` / `beq` / `cmp #1` / `beq` / `b` chain the original
 *    has; an `if` / `else if` inverts the first test.
 */
u32 BATTLE_REC_SaveSeq(struct GameData *gameData, struct BattleRecSave *rec, u32 id, u16 *seq, u16 heap)
{
    struct SaveControl *save = GAME_DATA_GetSaveControl(gameData);
    u32 result;

    switch (*seq) {
    case 0:
        SAVE_CONTROL_CreateExtraSaveWithBuffer(save, id, heap, pBattleRec, 0x2000);
        GAME_DATA_PartSaveStart(gameData, id);
        (*seq)++;
        break;
    case 1:
        result = GAME_DATA_PartSaveMain(gameData, id);
        if (result == 2 || result == 3) {
            SAVE_CONTROL_DeleteExtraSaveBuffered(save, id);
            return result;
        }
        break;
    }
    return 0;
}

u32 BATTLE_REC_BeginSave(struct GameData *gameData, u16 heap, u32 modeIndex, u32 battleCount, u32 id, u16 *seq, u16 *subSeq)
{
    struct SaveControl *save;
    struct BattleRecSave *rec;
    struct BattleRecHeader *head;
    struct BattleRecBody *body;
    u16 crc;

    save = GAME_DATA_GetSaveControl(gameData);

    switch (*seq) {
    case 0:
        rec = pBattleRec;
        if (rec == 0) {
            return 3;
        }
        head = &rec->head;
        body = &rec->body;
        BATTLE_REC_MakeHeader(save, head, body, modeIndex, battleCount);
        head->magic = BATTLE_REC_MAGIC;
        head->crc = GF_STANDARD_SetupCalc((const u8 *)head, 0x38);
        body->magic = BATTLE_REC_MAGIC;
        BATTLE_REC_SetBodyCrc(body);
        crc = body->crc;
        BATTLE_REC_Encode(body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
        *subSeq = 0;
        (*seq)++;
        break;
    case 1:
        return BATTLE_REC_SaveSeq(gameData, pBattleRec, id, subSeq, heap);
    }
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 84 bytes, 0x0200B784..0x0200B7D8, one function, which carries a label in the
 * generated listing.
 *
 * alias: inside "battle_rec.c"; the team-layout lookup the record builder at
 * 0x0200B7D8 calls.  It walks a 0x29-entry `u16` table of mode ids at
 * 0x0209DDCC, and the indices 0x10..0x13 and 0x16 are the multi
 * battle modes, which get four sides of three; everything else gets two sides
 * of six.  Indices 0x14 and 0x15 fall back into the search rather than
 * answering, which is the pair of exit-valued entries in the jump table.
 *
 * The switch is written with `case 0x14:` and `case 0x15:` as empty arms even
 * though they do nothing, because without them the labels the compiler sees
 * are not dense and it emits a compare chain instead of the seven-entry
 * `.hword` table the original has.  See
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *
 * This is a file of its own rather than part of the range that follows it
 * because 0x0209DDCC is named by exactly two literal pool words in the whole
 * image, this function's and BATTLE_REC_MakeHeader's, so a range holding both has no
 * witness left.  Cut between them and this one is attested by the other's
 * pool word.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The cut
 * does not save BATTLE_REC_MakeHeader, which is the only caller of this function and
 * therefore cannot be split away from it and attested at the same time; it is
 * parked in src/pending/unit_0200B7D8.c.
 */
void BATTLE_REC_GetModeLayout(u16 mode, s32 *sides, s32 *members)
{
    s32 i;

    for (i = 0; i < 0x29; i++) {
        if (mode == BattleRecModeTable[i]) {
            switch (i) {
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x16:
                *sides = 4;
                *members = 3;
                return;
            case 0x14:
            case 0x15:
                break;
            }
        }
    }
    *sides = 2;
    *members = 6;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 176 bytes, 0x0200B7D8..0x0200B888, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "battle_rec.c".  It builds the 0x44-byte battle header out of
 * the party records that live at +0xC3C of the 0x17E0-byte second half of the
 * record.  The layout, four sides of three or two of six, comes from
 * BATTLE_REC_GetModeLayout, and the group stride 0x2A4 is six 0x70-byte entries plus a
 * word.  An entry is skipped when either of two bits is set, and those two
 * bitfield reads are the only evidence in the image for those field widths.
 *
 * The destination byte packs a five bit field into the low seven bits and a
 * two bit field at bit 7, where only one of the two bits survives the `strb`.
 * That truncation is in the original and is reproduced rather than corrected;
 * the explicit `& 0x7F` on a field that is already five bits wide is what puts
 * the `movs r1, #0x7f` / `ands` pair there, and dropping it loses four bytes.
 *
 * This range starts at 0x0200B7D8 rather than at BATTLE_REC_GetModeLayout, which is its
 * only caller, because 0x0209DDCC is named by exactly two literal pool words
 * in the whole image: this function's at 0x0200B880 and BATTLE_REC_GetModeLayout's at
 * 0x0200B7D4.  One range holding both has no witness for the table at all.
 * Cut between them and each pool word attests the other file.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The call
 * to BATTLE_REC_GetModeLayout survives the cut because three overlay branches reach that
 * address from outside this region.
 */
void BATTLE_REC_MakeHeader(struct SaveControl *save, struct BattleRecHeader *head, const struct BattleRecBody *body, u32 modeIndex,
                   u32 battleCount)
{
    s32 nsides;
    s32 nmembers;
    u16 mode;
    s32 side;
    s32 member;
    s32 slot;

    slot = 0;
    MI_CpuFill8(head, 0, sizeof(struct BattleRecHeader));
    mode = BattleRecModeTable[modeIndex];
    BATTLE_REC_GetModeLayout(mode, &nsides, &nmembers);
    for (side = 0; side < nsides; side++) {
        for (member = 0; member < nmembers; member++) {
            const struct BattleRecMon *poke = &body->party[side].members[member];

            if (poke->isEgg == 0 && poke->checksumFailed == 0) {
                head->species[slot] = poke->species;
                head->formGender[slot] = (u8)((poke->form & 0x7F) | (poke->gender << 7));
            }
            slot++;
        }
    }
    head->battleCount = battleCount;
    head->mode = mode;
    head->version = 100;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 120 bytes, 0x0200B888..0x0200B900, 2 functions, both of which carry a label
 * in the generated listing.
 *
 * alias: inside "battle_rec.c"; the two validity checks src/matched/
 * unit_0200B4E0.c and unit_0200B5CC.c run over a loaded record, and the reason
 * those two are separate files.
 *
 * 0xE281 is the record's magic, stamped into both halves by BATTLE_REC_BeginSave and
 * into the 0x44-byte header's +0x28 by BATTLE_REC_SetData.  BATTLE_REC_IsMagicBroken answers
 * "this record is NOT stamped", so its result is 1 on failure; BATTLE_REC_IsValid
 * answers "this record is whole", checking the magic in both halves and then
 * both checksums.
 *
 * Both take a first parameter they never read.  BATTLE_REC_IsMagicBroken reaches the
 * 0x17D8 field of the second half as one folded offset 0x189C off the record
 * pointer, because the source names the field through the record rather than
 * through a local, while BATTLE_REC_IsValid needs a local for the sub-record and so
 * carries 0x17D8 in a register instead; the difference is two instructions and
 * is a statement about the source rather than about the value.
 *
 * The two checksum comparisons each bind the call result to a local before
 * comparing, which is what puts it in `cmp`'s left slot; written inline the
 * operand order flips and the entry is two bytes out.  See
 * docs/idioms/cmp-operand-order-names-the-temporary.md.
 */
u32 BATTLE_REC_IsMagicBroken(struct SaveControl *save, struct BattleRecSave *rec)
{
    struct BattleRecHeader *head = &rec->head;

    if (rec->body.magic != BATTLE_REC_MAGIC || head->magic != BATTLE_REC_MAGIC) {
        return 1;
    }
    return 0;
}

u32 BATTLE_REC_IsValid(struct SaveControl *save, struct BattleRecSave *rec)
{
    struct BattleRecBody *body = &rec->body;
    struct BattleRecHeader *head = &rec->head;
    u16 crc;

    if (body->magic != BATTLE_REC_MAGIC || head->magic != BATTLE_REC_MAGIC) {
        return 0;
    }
    crc = GF_STANDARD_SetupCalc((const u8 *)head, 0x38);
    if (crc != head->crc) {
        return 0;
    }
    crc = GF_STANDARD_SetupCalc((const u8 *)body, 0x17DC);
    if (crc == body->crc) {
        return 1;
    }
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           BATTLE_REC_GetHeader, BATTLE_REC_GetHeaderOf
 *
 * 56 bytes, 0x0200B900..0x0200B938, 6 functions, none of which carries a
 * label in the generated listing.
 *
 * Four accessors on the single object whose address lives at 0x0214616C and
 * two forwarders to a pair of ARM routines.  The three pool words holding
 * 0x0214616C inside this range are not its only ones: seven literal pools in
 * the image hold that address, so the `literal` class keeps a witness outside
 * whatever is compared.
 *
 * The two forwarders are written with their parameters declared and **not**
 * passed on, and that is a property of the codegen rather than a claim about
 * the callees.  This front end only emits the pool-word tail call
 * `ldr r3, [pc, #0]; bx r3` when there is no argument register to set up; a
 * call that names its arguments, even when every one of them is already in
 * the right register, comes out as `push {r3, lr}; blx; pop {r3, pc}`, which
 * is four instructions and eight bytes wrong.  The callers do pass four
 * arguments through BATTLE_REC_Decode (BATTLE_REC_SetData sets r0 through r3 before
 * the `bl`), so the forwarding is real and is simply not expressible here.
 * See docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 */
void BATTLE_REC_Decode(void *data, u32 size, u32 code)
{
    GF_STANDARD_ShuffleEx(data, size, code);
}

void BATTLE_REC_Encode(void *data, u32 size, u32 code)
{
    GF_STANDARD_Shuffle(data, size, code);
}

struct BattleRecSave *BATTLE_REC_GetWork(void)
{
    return pBattleRec;
}

struct BattleRecBody *BATTLE_REC_GetBody(void)
{
    return &pBattleRec->body;
}

struct BattleRecHeader *BATTLE_REC_GetHeader(void)
{
    return &pBattleRec->head;
}

struct BattleRecHeader *BATTLE_REC_GetHeaderOf(struct BattleRecSave *rec)
{
    return &rec->head;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 84 bytes, 0x0200B938..0x0200B98C, one function, which carries a label in
 * the generated listing.
 *
 * The publisher of the battle record: three copies into the single object at
 * 0x0214616C and then a checksum word handed to BATTLE_REC_Decode.  The object is
 * 0x18A4 bytes, which is what BATTLE_REC_GetWorkSize in src/matched/unit_0200B400.c
 * returns, so the record is pinned from both ends: 0x80 + 0x44 + 0x17E0 is
 * exactly 0x18A4.
 *
 * The word handed over is `v + ((v ^ 0xFFFF) << 16)`, spelled with `+` and
 * not with `|`: the two halves cannot overlap and this compiler emits `adds`
 * for the one and `orrs` for the other.  The length 0x17DC is rematerialised
 * as `subs r1, r6, #4` off the 0x17E0 that is still live from the second
 * copy, which is the compiler reusing a value rather than a second constant
 * in the source.
 *
 * The range stops at 0x0200B98C because of a near miss there; see
 * src/matched/unit_0200BA38.c. *
 */
void BATTLE_REC_SetData(const void *profile, const struct BattleRecHeader *head, const struct BattleRecBody *body)
{
    u16 crc;

    MI_CpuCopy8(head, &pBattleRec->head, sizeof(pBattleRec->head));
    MI_CpuCopy8(body, &pBattleRec->body, sizeof(pBattleRec->body));
    MI_CpuCopy8(profile, pBattleRec->profile, sizeof(pBattleRec->profile));
    crc = pBattleRec->body.crc;
    BATTLE_REC_Decode(&pBattleRec->body, 0x17DC, crc + ((crc ^ 0xFFFF) << 16));
}

/*
 * A record field getter: selector picks the field, the result is 64-bit.
 * Callers: ov183 0x021DD228, 0x021DD25C, 0x021DEE7C, 0x021DF838 and others.
 */
u64 BATTLE_REC_GetHeaderParam(const struct BattleRecHeader *head, int param, int index)
{
    int i;
    u16 value;
    switch (param) {
    case 0:
        value = head->species[index];
        if (value > 0x289)
            return 0;
        return value;
    case 1:
        return head->formGender[index] & 0x7f;
    case 2:
        value = head->battleCount;
        if (value > 9999)
            return 9999;
        return value;
    case 3:
        for (i = 0; i < 41; i++) {
            if (head->mode == BattleRecModeTable[i])
                return i;
        }
        return 0;
    case 4:
        return head->dataNumber.value;
    case 5:
        return head->secure;
    case 6:
        return (head->formGender[index] & 0x80) >> 7;
    case 7:
        return head->version;
    }
    return 0;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 32 bytes, 0x0200BA38..0x0200BA58, 2 functions, one of which carries a
 * label in the generated listing.
 *
 * BATTLE_REC_SetBodyCrc stamps the record's own checksum into its last halfword, and
 * 0x17DC is both the length checksummed and the store's offset, so the
 * compiler holds it in one register and the store is a register-offset
 * `strh`; 0x17DC is far past the 62-byte reach of the immediate form anyway.
 *
 * Near miss, and the reason this range starts at 0x0200BA38: BATTLE_REC_GetHeaderParam,
 * 172 bytes, an eight-case dispatcher returning `long long`.  Every case, the
 * jump table and the three pool words reproduce; what does not is one
 * instruction in the `case 3` table search.  The original keeps the loop
 * index in r2 and copies it into r0 to return it (`adds r0, r2, #0`), where
 * every spelling tried here allocates the index to r0 directly and drops the
 * copy, which is two bytes short and moves the four later table entries.
 * Nine shapes were compiled and ranked: the table as a named `const u16 *`
 * local declared before and after the compared value, the comparison in both
 * operand orders, `while` against `for`, a `continue` form, the index at
 * function scope and at case scope, and the compared field as `u16` and
 * `u32`.  All nine are 168 bytes against the original's 172 and the ranking
 * is flat, so the missing copy is not reachable from the source shape.  Same
 * class as the near misses at 0x0200B2A4 and 0x0200B37C.
 *
 * Near miss, and the reason this range stops at 0x0200BA58: BATTLE_REC_LoadToolOverlay and
 * BATTLE_REC_UnloadToolOverlay, eight bytes of tail call each.  Both reproduce every
 * instruction but hold their argument in a pool word rather than in a `movs`,
 * and 0xBC fits a `movs` immediate, so the argument cannot be an integer
 * literal.  Both are now matched on their own: src/matched/arm9/
 * BATTLE_REC_LoadToolOverlay.c and BATTLE_REC_UnloadToolOverlay.c. *
 */
u32 BATTLE_REC_IsVersionSupported(u32 version)
{
    if (version <= 100) {
        return 1;
    }
    return 0;
}

void BATTLE_REC_SetBodyCrc(struct BattleRecBody *body)
{
    body->crc = GF_STANDARD_SetupCalc((const u8 *)body, 0x17DC);
}

/*
 * Loads overlay 188 (0xBC): a Thumb tail call to the ARM loader through
 * `ldr r3; bx r3`.  The id is a pool word, so it is the overlay-id symbol,
 * not an integer literal (0xBC would fit a movs).  Filed as the call witness
 * for the ov021 script dispatcher 0x021CA5C4 (also unblocks the pending
 * ov187 0x0220B164 and ov199 0x022132C4).
 */
void BATTLE_REC_LoadToolOverlay(void)
{
    GF_OVERLAY_Load((u32)ov188_id);
}

/*
 * Unloads overlay 188 (0xBC), the pair of BATTLE_REC_LoadToolOverlay: a Thumb tail call
 * to the ARM unloader through `ldr r3; bx r3`, the id as the overlay-id
 * symbol.  Filed as the call witness for the ov021 script dispatcher
 * 0x021CA5C4 (also unblocks the pending ov187 0x0220B164 and ov199
 * 0x022132C4).
 */
void BATTLE_REC_UnloadToolOverlay(void)
{
    GF_OVERLAY_Unload((u32)ov188_id);
}
