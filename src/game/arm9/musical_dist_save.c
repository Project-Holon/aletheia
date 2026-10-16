/*
 * file:     musical_dist_save.c
 * unit:     yes
 * function: MUSICAL_DIST_SAVE_Create, MUSICAL_DIST_SAVE_Delete, MUSICAL_DIST_SAVE_CreateFromData, MUSICAL_DIST_SAVE_ProcessApply, MUSICAL_DIST_SAVE_GetBlockSize, MUSICAL_DIST_SAVE_IsFooterSet, ZUKAN_SAVE_IsInvalidSpecies, ZUKAN_SAVE_SetLanguageFlag, ZUKAN_SAVE_IsCountedForNationalCompletion, ZUKAN_SAVE_IsCountedForRegionalCompletion, ZUKAN_SAVE_GetFormBitBase, ZUKAN_SAVE_GetFormTableIndex, ZUKAN_SAVE_SetSeenGenderFlag, ZUKAN_SAVE_SetSeenFormFlag, ZUKAN_SAVE_GetSize, ZUKAN_SAVE_Init, ZUKAN_SAVE_GetBlock, ZUKAN_SAVE_GetFromGameData, ZUKAN_SAVE_EnableNationalDex, ZUKAN_SAVE_IsNationalDexEnabled, ZUKAN_SAVE_SetDexObtained, ZUKAN_SAVE_GetViewMode, ZUKAN_SAVE_SetLastViewedSpecies, ZUKAN_SAVE_GetLastViewedSpecies, ZUKAN_SAVE_UpdateViewFlags, ZUKAN_SAVE_GetFormCount, ZUKAN_SAVE_GetViewGenderAndForm, ZUKAN_SAVE_RegisterCaught, ZUKAN_SAVE_IsCaught, ZUKAN_SAVE_CountCaught, ZUKAN_SAVE_CountCaughtNational, ZUKAN_SAVE_CountCaughtRegional, ZUKAN_SAVE_RegisterSeen, ZUKAN_SAVE_IsSeen, ZUKAN_SAVE_CountSeen, ZUKAN_SAVE_CountSeenNational, ZUKAN_SAVE_CountSeenRegional, ZUKAN_SAVE_HasSeenGenderForm, ZUKAN_SAVE_GetSpindaPersonality, ZUKAN_SAVE_IsNationalCaughtComplete, ZUKAN_SAVE_IsRegionalCaughtComplete, ZUKAN_SAVE_IsRegionalSeenComplete, ZUKAN_SAVE_CountCaughtNationalCounted, ZUKAN_SAVE_CountCaughtRegionalCounted, ZUKAN_SAVE_CountSeenRegionalCounted, ZUKAN_SAVE_HasLanguageFlag, MOVE_POKEMON_SAVE_GetBlock, MOVE_POKEMON_SAVE_Init, MOVE_POKEMON_SAVE_RollStartLocation, MOVE_POKEMON_SAVE_GetStartLocation, MOVE_POKEMON_SAVE_SetCommonArea, MOVE_POKEMON_SAVE_GetEntryState, MOVE_POKEMON_SAVE_SetEntryState
 * address:  0x0200C52C
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
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   g_MusicalDistSaveFileName     0x020A71D4  data  a1
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_CreateHandleFromMemory  0x0204913C  arm
 *   ARC_UTIL_LoadHandleMemberWithSize  0x0204A39C  arm
 *   MSGDATA_CreateFromMemory  0x02045C44  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   sZukanNationalExcludedSpecies      0x0209DE2C  data
 *   sZukanRegionalExcludedSpecies      0x0209DE20  data
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb
 *   GAME_DATA_PartSaveMain  0x02012E7C  thumb
 *   sZukanFormTable  0x0209DE4C  data
 *   sZukanFormTable  0x0209DE4C  data
 *   POKE_PERSONAL_Create        0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam        0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete        0x0201AE14  thumb
 *   ZUKAN_SAVE_IsCountedForRegionalCompletion   0x0200C7A0  thumb
 *   ZUKAN_SAVE_IsCaught   0x0200CED4  thumb
 *   POKE_PERSONAL_LoadFormTable   0x0201AF80  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   POKE_TOOL_GetGender  0x02017F00  thumb
 *   MUSICAL_SAVE_GetFromSave  0x0200A5F8  thumb
 *   MUSICAL_SAVE_SetHasDistData  0x0200A7EC  thumb
 *   MUSICAL_SAVE_GetStageData  0x0200A7F8  thumb
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_IsShiny  0x02017EAC  thumb
 */
struct SaveWork;
struct SaveBlockCtrl;
struct MsgBank;
struct MsgString;
struct Sub020071CCCtrl;
struct Personal;
struct Sav;
struct ZukanSave;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct DistHeader {
    u32 payload_size;
    u32 reserved[3];
};

struct MusicalDist {
    u16 heap_id;
    u32 load_ok;
    u32 state;
    struct DistHeader header;
    void *block;
    struct DistHeader *block_head;
    u8   *payload;
    void *game_sys;
};

typedef signed int     s32;

struct BlockImage {
    u8 body[0x1FE0];
    u8 footer[0x20];
};

struct DistEnt {
    u16 id;
    u16 count;
};

struct ZukanSave {
    u32 magic;                          /* +0x00, 0xBEEFCAFE once initialised */
    u32 nationalDexEnabled : 1;         /* +0x04 bit 0 */
    u32 dexObtained : 10;               /* bits 1..10 */
    u32 viewMode : 1;                   /* bit 11 */
    u32 lastViewedSpecies : 10;         /* bits 12..21 */
    u32 unusedBits : 10;                /* bits 22..31, nothing reads them */
    u8  caughtFlags[0x54];              /* one bit per species, 1-based */
    u8  seenFlags[4][0x54];             /* [gender + 2 * shiny]: male, female, shiny male, shiny female */
    u8  viewGenderFlags[4][0x54];       /* gender and colour shown in the dex, same index */
    u8  seenFormFlags[2][9];            /* [shiny], one bit per form of the multi-form species */
    u8  viewFormFlags[2][9];            /* form shown in the dex, [shiny] */
    u8  languageFlags[0x1B0];           /* 7 language bits per species up to 493 */
    u32 spindaPersonality;              /* +0x4D0, personality of the first Spinda registered */
};                                      /* 0x4D4 */

struct MovePokemonEntry {
    u16 entryId;                        /* +0x00, 0xFFFF when empty */
    u8  extraData;                      /* +0x02 */
    u8  pad03;
    u32 ivData;                         /* +0x04 */
    u32 personality;                    /* +0x08 */
    u16 species;                        /* +0x0C */
    u16 hp;                             /* +0x0E */
    u8  level;                          /* +0x10 */
    u8  status;                         /* +0x11 */
    u8  isActive;                       /* +0x12 */
    u8  spawned;                        /* +0x13 */
};                                      /* 0x14 */

struct MovePokemonSave {
    u16 commonArea;                     /* +0x00 */
    u16 prevCommonArea;                 /* +0x02 */
    struct MovePokemonEntry entries[2]; /* +0x04 */
    u8  entryLocation[2];               /* +0x2C */
    u8  entryState[2];                  /* +0x2E */
    u8  startLocation;                  /* +0x30 */
    volatile u8 moveCooldown;           /* +0x31 */
    u8  pad32[2];
};                                      /* 0x34 */

extern void *GAME_DATA_GetSaveControl(struct SaveWork *saveWork);
extern void *func_02030734(u32 heap_id, u32 size, int clear, const char *file_name, u16 line);
extern u32   SAVE_CONTROL_LoadExtraSaveWithBuffer(void *save_ctrl, u32 block_id, u32 heap_id, void *buf, u32 size);
extern void *func_020073D8(struct SaveBlockCtrl *save_ctrl, u32 block_id, u32 mode);
extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void func_020072A4(struct SaveBlockCtrl *save_ctrl, u32 block_id);
extern u32 func_020307B0(void *mem);
extern void GAME_DATA_PartSaveStart(u8 *game_sys, u32 block_id);
extern int GAME_DATA_PartSaveMain(char *game_sys, int block_id);
extern void *MUSICAL_SAVE_GetFromSave(void *save);
extern void MUSICAL_SAVE_SetHasDistData(struct SaveWork *profile, u8 value);
extern u8 *MUSICAL_SAVE_GetStageData(struct SaveWork *profile);
extern void *ARC_TOOL_CreateHandleFromMemory(void *data, u32 size, u32 heap_id);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int file_id, int decompress, u32 heap_id, u32 *out_size);
extern struct MsgBank *MSGDATA_CreateFromMemory(const void *file, u32 heap_id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void  STRBUF_ToChars(struct MsgString *str, u16 *dest, u32 max_len);
extern void STRBUF_Delete(struct MsgString *str);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern void  ARC_TOOL_DeleteHandle(void *narc);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *POKE_PERSONAL_Create(u32 a, int b, u32 c);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern u32   POKE_TOOL_GetPartyValue(void *m, u32 field, u32 arg);
extern u8    POKE_TOOL_GetGender(void *m);
extern u32   POKE_TOOL_IsShiny(void *m);
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern int ZUKAN_SAVE_CountCaughtRegionalCounted(struct ZukanSave *pZukan, int heap);
extern u32 ZUKAN_SAVE_IsCaught(struct ZukanSave *p, u16 id);
extern int ZUKAN_SAVE_IsCountedForRegionalCompletion(u32 v);
extern u32 func_02005728(u32 range);
struct MusicalDist *MUSICAL_DIST_SAVE_Create(void *game_sys, u32 heap_id);
void MUSICAL_DIST_SAVE_Delete(struct MusicalDist *dist);
struct MusicalDist *MUSICAL_DIST_SAVE_CreateFromData(void *game_sys, const void *data, u32 size, u32 heap_id);
u32 MUSICAL_DIST_SAVE_ProcessApply(struct MusicalDist *dist);
u32 MUSICAL_DIST_SAVE_GetPayload(struct MusicalDist *dist);
u32 MUSICAL_DIST_SAVE_GetPayloadSize(struct MusicalDist *dist);
u32 MUSICAL_DIST_SAVE_GetBlockSize(void);
void MUSICAL_DIST_SAVE_NoOp(void);
u32 MUSICAL_DIST_SAVE_IsFooterSet(struct BlockImage *image);
u32 ZUKAN_SAVE_IsInvalidSpecies(u32 species);
void ZUKAN_SAVE_SetLanguageFlag(struct ZukanSave *pZukan, u32 species, u32 language);
int ZUKAN_SAVE_IsCountedForNationalCompletion(u32 species);
u32 ZUKAN_SAVE_GetFormBitBase(u16 species);
u32 ZUKAN_SAVE_GetFormTableIndex(u32 species);
void ZUKAN_SAVE_SetSeenGenderFlag(struct ZukanSave *pZukan, u32 idx, int sel, int half);
void ZUKAN_SAVE_SetSeenFormFlag(struct ZukanSave *pZukan, u32 id, u32 sel, u32 shiny, u32 form);
u32 ZUKAN_SAVE_GetSize(void);
void ZUKAN_SAVE_Init(struct ZukanSave *pZukan);
void *ZUKAN_SAVE_GetBlock(void *saveControl);
void *ZUKAN_SAVE_GetFromGameData(void *gameData);
struct ZukanSave *ZUKAN_SAVE_EnableNationalDex(struct ZukanSave *pZukan);
u32 ZUKAN_SAVE_IsNationalDexEnabled(struct ZukanSave *pZukan);
struct ZukanSave *ZUKAN_SAVE_SetDexObtained(struct ZukanSave *pZukan);
u32 ZUKAN_SAVE_GetDexObtained(struct ZukanSave *pZukan);
void ZUKAN_SAVE_SetViewMode(struct ZukanSave *pZukan, u32 value);
u32 ZUKAN_SAVE_GetViewMode(struct ZukanSave *pZukan);
void ZUKAN_SAVE_SetLastViewedSpecies(struct ZukanSave *pZukan, u32 value);
u16 ZUKAN_SAVE_GetLastViewedSpecies(struct ZukanSave *pZukan);
void ZUKAN_SAVE_UpdateViewFlags(struct ZukanSave *pZukan, u16 id, u32 gender, u32 alt, u32 form);
u16 ZUKAN_SAVE_GetFormCount(u32 species);
void ZUKAN_SAVE_GetViewGenderAndForm(struct ZukanSave *pZukan, u16 id, u32 *outGender, u32 *outShiny, u32 *outForm, u16 language);
void ZUKAN_SAVE_RegisterCaught(struct ZukanSave *pZukan, void *pMon);
u16 ZUKAN_SAVE_CountCaught(struct ZukanSave *pZukan, u32 heap);
u16 ZUKAN_SAVE_CountCaughtNational(struct ZukanSave *pZukan);
u16 ZUKAN_SAVE_CountCaughtRegional(struct ZukanSave *pZukan, u32 heap);
void ZUKAN_SAVE_RegisterSeen(struct ZukanSave *pZukan, void *pMon);
u32 ZUKAN_SAVE_IsSeen(struct ZukanSave *pZukan, u16 species);
u32 ZUKAN_SAVE_CountSeen(struct ZukanSave *pZukan, u32 heap);
u16 ZUKAN_SAVE_CountSeenNational(struct ZukanSave *pZukan);
u16 ZUKAN_SAVE_CountSeenRegional(struct ZukanSave *pZukan, u32 heap);
u32 ZUKAN_SAVE_HasSeenGenderForm(struct ZukanSave *pZukan, u16 id, u32 gender, u32 shiny, u32 form);
u32 ZUKAN_SAVE_GetSpindaPersonality(struct ZukanSave *pZukan, u32 which);
int ZUKAN_SAVE_IsNationalCaughtComplete(struct ZukanSave *pZukan);
int ZUKAN_SAVE_IsRegionalCaughtComplete(struct ZukanSave *pZukan, int heap);
int ZUKAN_SAVE_IsRegionalSeenComplete(struct ZukanSave *pZukan, unsigned int heap);
u16 ZUKAN_SAVE_CountCaughtNationalCounted(struct ZukanSave *pZukan);
u16 ZUKAN_SAVE_CountSeenRegionalCounted(struct ZukanSave *pZukan, u32 heap);
u32 ZUKAN_SAVE_HasLanguageFlag(struct ZukanSave *pZukan, u32 a, u32 b);
u32 MOVE_POKEMON_SAVE_GetSize(void);
void *MOVE_POKEMON_SAVE_GetBlock(void *saveControl);
void MOVE_POKEMON_SAVE_Init(struct MovePokemonSave *pSave);
void MOVE_POKEMON_SAVE_RollStartLocation(void *saveControl);
u8 MOVE_POKEMON_SAVE_GetStartLocation(struct MovePokemonSave *pSave);
void MOVE_POKEMON_SAVE_SetCommonArea(struct MovePokemonSave *pSave, u16 area);
u8 MOVE_POKEMON_SAVE_GetEntryState(struct MovePokemonSave *pSave, u32 slot);
void MOVE_POKEMON_SAVE_SetEntryState(struct MovePokemonSave *pSave, u32 slot, u32 state);
u8 MOVE_POKEMON_SAVE_GetEntryLocation(struct MovePokemonSave *pSave, u32 slot);
void MOVE_POKEMON_SAVE_SetEntryLocation(struct MovePokemonSave *pSave, u32 slot, u8 location);
u8 MOVE_POKEMON_SAVE_IsEntryActive(struct MovePokemonSave *pSave, u32 slot);
void MOVE_POKEMON_SAVE_InitEntry(struct MovePokemonEntry *pEntry);
struct MovePokemonEntry *MOVE_POKEMON_SAVE_GetEntry(struct MovePokemonSave *pSave, u32 slot);
u32 MOVE_POKEMON_SAVE_GetEntryField(const struct MovePokemonEntry *pEntry, u32 field);
void MOVE_POKEMON_SAVE_SetEntryField(struct MovePokemonEntry *pEntry, u32 field, u32 value);
void MOVE_POKEMON_SAVE_SetCooldown(struct MovePokemonSave *pSave, u8 cooldown);
u32 MOVE_POKEMON_SAVE_TickCooldown(struct MovePokemonSave *pSave);
u32 MOVE_POKEMON_SAVE_IsCooldownDone(struct MovePokemonSave *pSave);
extern const char g_MusicalDistSaveFileName[];
extern u16 sZukanNationalExcludedSpecies[];
extern u16 sZukanRegionalExcludedSpecies[];
extern const struct DistEnt sZukanFormTable[];
extern const struct DistEnt sZukanFormTable[];



/*
 * musical_dist_save.c constructor: allocate the 0x2C-byte control block and
 * a 0x20000-byte buffer, load save block 6 into the buffer through the save
 * system, record heap/system, then attach the loaded block.
 *
 * Closed in wave 15.  The residue since wave 11 (image homes sys to the
 * stack and keeps sv in r6 and the id 6 in r7; every earlier shape did the
 * reverse) was not an allocation tie: the func_020073D8 call is written in
 * BOTH arms of the `r == 1` test and the compiler tail-merges the two
 * copies.  The merged call is what keeps 6 live in a callee-saved register
 * and lets the shared zero land in r2 as the third argument.
 */
struct MusicalDist *MUSICAL_DIST_SAVE_Create(void *game_sys, u32 heap_id)
{
    void *save_ctrl;
    struct MusicalDist *dist;
    u32 load_result;
    u8 *block;

    save_ctrl = GAME_DATA_GetSaveControl(game_sys);
    dist = func_02030734(heap_id, 0x2C, 1, g_MusicalDistSaveFileName, 0x4A);
    dist->block = func_02030734(heap_id, 0x20000, 1, g_MusicalDistSaveFileName, 0x4C);
    load_result = SAVE_CONTROL_LoadExtraSaveWithBuffer(save_ctrl, 6, heap_id, dist->block, 0x20000);
    dist->heap_id = heap_id;
    dist->game_sys = game_sys;
    dist->state = 0;
    if (load_result == 1) {
        dist->load_ok = 1;
        block = func_020073D8(save_ctrl, 6, 0);
    } else {
        dist->load_ok = 0;
        block = func_020073D8(save_ctrl, 6, 0);
    }
    dist->block = block;
    dist->block_head = (struct DistHeader *)block;
    dist->payload = block + 0x10;
    return dist;
}



/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 84 bytes, 0x0200C5A4..0x0200C5F8, 2 functions, both of which carry a label
 * in the generated listing.
 *
 * alias: inside "musical_dist_save.c"; see src/matched/unit_0200C6D8.c for
 * how the file name at 0x020A71D4 is attested.  The record the file works on
 * is 0x2C bytes: a heap id at +0x00, a flag at +0x04, a state counter at
 * +0x08, a 0x10-byte header at +0x0C, the working buffer at +0x1C, the
 * buffer's base again at +0x20, the payload at base + 0x10 in +0x24, and the
 * system pointer at +0x28.  Every field is pinned by the constructor at
 * 0x0200C52C and by MUSICAL_DIST_SAVE_ProcessApply, neither of which is in this range; see the
 * two near misses below.
 *
 * MUSICAL_DIST_SAVE_Delete is the destructor.  The guard around the buffer free is
 * written as a plain `if`, and the fall-through arm is the free, so the test
 * in the source is `dist->block != 0` and not the inverse; see
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.
 *
 * Two near misses bracket this range, and they are of different kinds.
 *
 *  - MUSICAL_DIST_SAVE_Create, 118 bytes, the constructor.  It is a codegen miss and not
 *    an evidence one: 0x0200C52C is attested by one branch from an overlay,
 *    so it resolves here as `label`.  The original spends one instruction
 *    this source cannot buy, `movs r7, #6` at 0x0200C56C, which parks the
 *    save-block id in a callee-saved register so that the second use of it
 *    (the func_020073D8 call at 0x0200C560) is a register copy rather than a
 *    second `movs`.  Doing so costs the original a register, and the visible
 *    consequence is that the first parameter is homed to the stack at entry
 *    (`str r0, [sp, #4]`) while the GAME_DATA_GetSaveControl result keeps r6; every
 *    source shape tried here does the reverse and is 116 bytes against the
 *    original's 118.  Thirty-six shapes were compiled and ranked by diff
 *    count: six permutations of the three field stores crossed with four
 *    positions for the SAVE_CONTROL_LoadExtraSaveWithBuffer call, the result as a named local
 *    against the call written inline in the `if`, the id 6 as a literal
 *    against a local, five declaration orders for the locals, and a six
 *    argument reading of SAVE_CONTROL_LoadExtraSaveWithBuffer.  The ranking is flat at 57 to 80
 *    concrete bytes and every one of them is 116 bytes, so the missing
 *    instruction is not reachable by statement order.  All nine front ends
 *    agree, at every optimisation level.  Same class as the near misses at
 *    0x0200B2A4 and 0x0200B37C: a register the original spends and the source
 *    does not.
 *  - MUSICAL_DIST_SAVE_ProcessApply, 224 bytes, the state machine.  Every concrete byte of it
 *    reproduces; it is capped at MATCH because 0x0200A7F8 is branched to from
 *    exactly one instruction in the whole image, its own call at 0x0200C680,
 *    so the `label` class has no witness left once that call is inside the
 *    compared range and no cut helps.  The source is parked in
 *    src/matched/unit_0200C5F8.c.
 */
void MUSICAL_DIST_SAVE_Delete(struct MusicalDist *dist)
{
    func_020072A4(GAME_DATA_GetSaveControl(dist->game_sys), 6);
    if (dist->block != 0) {
        func_020307B0(dist->block);
    }
    func_020307B0(dist);
}


struct MusicalDist *MUSICAL_DIST_SAVE_CreateFromData(void *game_sys, const void *data, u32 size,
                                  u32 heap_id)
{
    struct MusicalDist *dist = MUSICAL_DIST_SAVE_Create(game_sys, heap_id);

    if (dist->block != 0) {
        dist->header.payload_size = size;
        MI_CpuCopy8(&dist->header, dist->block, sizeof(dist->header));
        MI_CpuCopy8(data, dist->payload, size);
    }
    return dist;
}



/*
 * 0x0200C5F8..0x0200C6D8, 224 bytes, one function.
 *
 * The state machine of "musical_dist_save.c"; see src/matched/unit_0200C5A4.c
 * for the record it works on and for how the file name is attested.
 *
 * What held it open, and what closed it: 0x0200A7F8 is the target of exactly
 * one branch in the whole image, the `bl` at 0x0200C680 inside this very
 * function, so the `label` class discards its only witness under the honesty
 * rule and no cut helps, because shrinking the range to this one function
 * keeps the call in it.  The `matched` class carries it: 0x0200A7F8 is inside
 * src/matched/unit_0200A6F8.c, an EXACT entry verified against the original
 * bytes over a range this file does not touch.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0200C5F8.c \
 *       --addr 0x0200C5F8 --thumb
 *
 * The tag the three service calls take is `(u16)((dist->heap_id & 0x7FFF) |
 * 0x8000)` written out at each of the three sites: the original reloads the
 * halfword and redoes the mask each time while keeping 0x7FFF alive in r4,
 * and 0x8000 is reached as `adds rN, r4, #1` off that pool word rather than
 * from one of its own.
 */
u32 MUSICAL_DIST_SAVE_ProcessApply(struct MusicalDist *dist)
{
    u32 out_size;
    void *profile;
    void *narc;
    void *msg_file;
    void *msg_bank;
    void *msg_str;

    switch (dist->state) {
    case 0:
        if (dist->block == 0) {
            MUSICAL_DIST_SAVE_Delete(dist);
            return 1;
        }
        profile = MUSICAL_SAVE_GetFromSave(GAME_DATA_GetSaveControl(dist->game_sys));
        MUSICAL_SAVE_SetHasDistData(profile, 1);
        narc = ARC_TOOL_CreateHandleFromMemory(dist->payload, dist->header.payload_size,
                             (u16)((dist->heap_id & 0x7FFF) | 0x8000));
        msg_file = ARC_UTIL_LoadHandleMemberWithSize(narc, 1, 0, (u16)((dist->heap_id & 0x7FFF) | 0x8000), &out_size);
        msg_bank = MSGDATA_CreateFromMemory(msg_file, (u16)((dist->heap_id & 0x7FFF) | 0x8000));
        msg_str = func_02045EC0(msg_bank, 0);
        STRBUF_ToChars(msg_str, (u16 *)MUSICAL_SAVE_GetStageData(profile), 0x25);
        STRBUF_Delete(msg_str);
        MSGDATA_Delete(msg_bank);
        func_020307B0(msg_file);
        ARC_TOOL_DeleteHandle(narc);
        GAME_DATA_PartSaveStart(dist->game_sys, 6);
        dist->state++;
        break;
    case 1:
        if (GAME_DATA_PartSaveMain(dist->game_sys, 6) == 2) {
            MUSICAL_DIST_SAVE_Delete(dist);
            return 1;
        }
        break;
    }
    return 0;
}



/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           MUSICAL_DIST_SAVE_IsFooterSet, ZUKAN_SAVE_IsInvalidSpecies
 *
 * 96 bytes, 0x0200C6D8..0x0200C738, 6 functions, none of which carries a
 * label in the generated listing.
 *
 * alias: this range is inside "musical_dist_save.c".  The constructor of the
 * file, MUSICAL_DIST_SAVE_Create, loads 0x020A71D4 as the file-name argument to the
 * debug allocator at 0x02030734, and the bytes at 0x020A71D4 spell
 * "musical_dist_save.c"; the string before it is "battle_rec.c", whose
 * terminator at 0x020A71DF fixes that start.  That is the fourth original
 * source file name this project has recovered, after "playtime.c",
 * "box_savedata.c" and "battle_rec.c".  The functions keep their
 * `func_<address>` names, because the file identity is attested and the
 * individual entry points are not.
 *
 * The two getters at the top reach the 0x2C-byte object MUSICAL_DIST_SAVE_Create
 * allocates; MUSICAL_DIST_SAVE_IsFooterSet works on a 0x2000-byte buffer instead, comparing
 * the 0x20 bytes at +0x1FE0 against a cleared stack copy of the same length,
 * which is a "is this record still blank" test.  MUSICAL_DIST_SAVE_NoOp is `bx lr` and
 * nothing else, a hook that was never filled in.
 *
 * ZUKAN_SAVE_IsInvalidSpecies is the shape docs/idioms/the-fall-through-arm-is-the-source-order.md
 * warns about, read the other way: the `beq` jumps **into** the `return 1`
 * block and the `bls` jumps **past** it, which is the short-circuit `||` of
 * one `if`, not two statements.
 */
u32 MUSICAL_DIST_SAVE_GetPayload(struct MusicalDist *dist)
{
    return (u32)dist->payload;
}


u32 MUSICAL_DIST_SAVE_GetPayloadSize(struct MusicalDist *dist)
{
    return dist->block_head->payload_size;
}


u32 MUSICAL_DIST_SAVE_GetBlockSize(void)
{
    return 0x2600;
}



void MUSICAL_DIST_SAVE_NoOp(void)
{
}



u32 MUSICAL_DIST_SAVE_IsFooterSet(struct BlockImage *image)
{
    u8 blank[0x20];
    u32 footer_set = 0;

    MI_CpuFill8(blank, 0, sizeof(blank));
    if (GF_STANDARD_CompareBytes(blank, image->footer, sizeof(blank)) != 0) {
        footer_set = 1;
    }
    return footer_set;
}


u32 ZUKAN_SAVE_IsInvalidSpecies(u32 species)
{
    if (species == 0 || species > 0x289) {
        return 1;
    }
    return 0;
}



/*
 * Leaf bitset setter.  Guard chain (language > 8, language == 6, species > 0x1ED all bail),
 * then a 7-wide row/column flattening into a u16 index, then a read-modify-
 * write of one bit in the 0x320-byte bitset that follows *p.  The 0x1ED bound
 * needs a pool word because it is not encodable as a Thumb movs immediate.
 *
 * The index shift is `asrs` because the u16 index promotes to signed int
 * before `>> 3`; the (u8) truncation of the one-hot mask is what the lsls/
 * lsrs #24 pair is.
 */
void ZUKAN_SAVE_SetLanguageFlag(struct ZukanSave *pZukan, u32 species, u32 language)
{
    u16 bitIndex;
    u8 *languageBits;

    if (language > 8)
        return;
    if (language == 6)
        return;
    if (species > 493)
        return;
    if (language >= 7)
        language--;
    species--;

    bitIndex = (u16)((language - 1) + species * 7);
    languageBits = pZukan->languageFlags;
    languageBits[bitIndex >> 3] |= (u8)(1 << (bitIndex & 7));
}



int ZUKAN_SAVE_IsCountedForNationalCompletion(u32 species)
{
    u32 tableIdx;

    for (tableIdx = 0; tableIdx < 0xf; tableIdx++) {
        if (species == sZukanNationalExcludedSpecies[tableIdx])
            return 0;
    }
    return 1;
}



int ZUKAN_SAVE_IsCountedForRegionalCompletion(u32 species)
{
    u32 tableIdx;

    for (tableIdx = 0; tableIdx < 6; tableIdx++) {
        if (species == sZukanRegionalExcludedSpecies[tableIdx])
            return 0;
    }
    return 1;
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 88 bytes, 0x0200C7C0..0x0200C818, 2 functions, neither of which carries a
 * label in the generated listing.
 *
 * alias: inside "musical_dist_save.c"; see src/matched/unit_0200C6D8.c for
 * how the name is attested.
 *
 * Two searches of the same zero-terminated table of `{u16 id, u16 count}`
 * pairs at 0x0209DE4C: the first returns the running sum of the counts in
 * front of the match, which is a base index into a flat array, and the second
 * returns the entry's own index.  Both return ~0 when the id is not listed,
 * spelled `movs r0, #0` / `mvns r0, r0` rather than a pool word.
 *
 * Both are `do`/`while` loops and not `while` loops: the key of entry zero is
 * never tested before the first body, so the table is known to be non-empty
 * by construction.  A `while (tbl[i].key != 0)` adds the entry test in front
 * of the loop and moves every instruction after it.
 *
 * The declaration order of the two locals in ZUKAN_SAVE_GetFormBitBase is load bearing
 * and is the only thing the bytes say about it: the running sum is declared
 * first and lands in r2, the index second and lands in r3.  Declared the
 * other way round the two swap registers and five bytes differ with nothing
 * else moving.
 *
 * The pool word holding 0x0209DE4C is attested as `literal`: three literal
 * pools in the image hold that address, so even with both of these functions
 * in one range a witness survives outside it.
 *
 * The two neighbours immediately before this range, ZUKAN_SAVE_IsCountedForNationalCompletion and
 * ZUKAN_SAVE_IsCountedForRegionalCompletion, reproduce every concrete byte and stay at MATCH.  Each is a
 * linear scan of a `u16` table, at 0x0209DE2C with fifteen entries and at
 * 0x0209DE20 with six, and each table's address appears in exactly one
 * literal pool in the whole image: its own.  The `literal` class discards
 * that witness under the honesty rule and no cut helps, because shrinking the
 * range to one function keeps its own pool word in it.  Evidence class:
 * `literal`, no outside witness; the C is not in question.
 */
u32 ZUKAN_SAVE_GetFormBitBase(u16 species)
{
    u32 bitBase = 0, tableIdx = 0;

    do {
        if (species == sZukanFormTable[tableIdx].id) {
            return bitBase;
        }
        bitBase += sZukanFormTable[tableIdx].count;
        tableIdx++;
    } while (sZukanFormTable[tableIdx].id != 0);
    return (u32)-1;
}





u32 ZUKAN_SAVE_GetFormTableIndex(u32 species)
{
    u32 tableIdx = 0;

    do {
        if (species == sZukanFormTable[tableIdx].id) {
            return tableIdx;
        }
        tableIdx++;
    } while (sZukanFormTable[tableIdx].id != 0);
    return (u32)-1;
}





/*
 * Set one bit in a byte array of a manager struct.  `sel` picks the pair of
 * tables, `half` which table of the pair, and the bit is entry `idx - 1`
 * (the parameter is 1-based).  Each of the six arms is an independent
 * read-modify-write of one byte.
 *
 * Shape notes:
 *  - `idx` is 32-bit in the ABI: every arm opens with a cast-to-u16 /
 *    subtract-one / cast-to-u16 quintet, which is `u16 i = (u16)idx - 1;`
 *    and only exists when the parameter is wider than u16.  Declaring the
 *    parameter `u16` loses the leading shift pair and reallocates the whole
 *    function (196 vs 250 bytes).
 *  - The index local is declared inside each arm, not hoisted above the
 *    `sel` tests.  Hoisting it keeps it in r1 and drops the callee-saved
 *    r5, which is where the original parks it -- each arm alone needs
 *    r0 (base), r1 (offset), r2 (pointer), r3/r4 (mask temps), so the
 *    index has to be r5, and that is what pulls in `push {r4, r5}`.
 *  - `|= (u8)(1 << (i & 7))` on a u8 lvalue is what emits the
 *    lsls/lsrs #0x18 pair around the mask.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ZUKAN_SAVE_SetSeenGenderFlag.c \
 *       --func ZUKAN_SAVE_SetSeenGenderFlag --addr 0x0200C818 --cc 1.1p1 --thumb
 *   -> EXACT* (250 of 250 bytes; the listing extent runs two bytes long
 *      over the pool padding after the body)
 */
void ZUKAN_SAVE_SetSeenGenderFlag(struct ZukanSave *pZukan, u32 species, int sel, int half)
{
    if (sel == 0) {
        if (half == 1) {
            u16 bitIndex = (u16)species - 1;
            pZukan->seenFlags[2][bitIndex >> 3] |= (u8)(1 << (bitIndex & 7));
        } else {
            u16 bitIndex = (u16)species - 1;
            pZukan->seenFlags[0][bitIndex >> 3] |= (u8)(1 << (bitIndex & 7));
        }
    } else if (sel == 1) {
        if (half == 1) {
            u16 bitIndex = (u16)species - 1;
            pZukan->seenFlags[3][bitIndex >> 3] |= (u8)(1 << (bitIndex & 7));
        } else {
            u16 bitIndex = (u16)species - 1;
            pZukan->seenFlags[1][bitIndex >> 3] |= (u8)(1 << (bitIndex & 7));
        }
    } else {
        if (half == 1) {
            u16 bitIndex = (u16)species - 1;
            pZukan->seenFlags[2][bitIndex >> 3] |= (u8)(1 << (bitIndex & 7));
        } else {
            u16 bitIndex = (u16)species - 1;
            pZukan->seenFlags[0][bitIndex >> 3] |= (u8)(1 << (bitIndex & 7));
        }
    }
}





/*
 * The "caught" half of the musical-distribution form bookkeeping in
 * "musical_dist_save.c": it sets one bit of one of the two nine-byte form
 * bitmaps at +0x2FC (base) and +0x305 (alt), indexed by the flat form index
 * ZUKAN_SAVE_GetFormBitBase answers for the species.
 *
 * Four species ids get a fixed form count and a forced start of zero: 0x15F
 * with four forms and 0x1A5 / 0x22B / 0x288 with two each.  Everything else
 * takes one form and clamps the caller's form index against ZUKAN_SAVE_GetFormCount's
 * count for that species.
 *
 * What closed it, after the two things the older DIFF note
 * (docs/notes/pkt_0200C914.c.txt) had wrong:
 *
 *  - the loop counter is `u16`, not `unsigned`.  Its `lsls #0x10 / lsrs
 *    #0x10` truncation at the top of each loop body is the tell, and the note's
 *    `unsigned i` loses eight bytes of it (208 against the original's 216 code
 *    bytes).  See docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 *    for the general shape.
 *  - the "not listed" sentinel is compared as `u32`, not as `int`.  The
 *    original builds it with `movs r1, #0 / mvns r1, r1` and a register
 *    `cmp`, which is what `res == (u32)-1` emits when ZUKAN_SAVE_GetFormBitBase is
 *    declared to return `u32`, exactly as src/matched/musical_dist_save_1.c
 *    defines it.  Declared `int` with a literal `-1` the compare folds to an
 *    immediate and the whole head reallocates; that was the "codegen,
 *    register allocation" verdict the old note recorded, and it was really a
 *    type error.
 *  - `idx` is a SIGNED int holding a `(u16)` value.  `idx >> 3` is `asrs` in
 *    the original and `lsrs` when idx is `u32`; those two instructions were
 *    the last two concrete bytes out.  See
 *    docs/idioms/ldrsh-register-offset-is-signedness.md for the same class of
 *    tell read off a load.
 *
 * The first parameter is spelled `u8 *` here and `struct ZukanSave *` in the two
 * callers (src/matched/unit_0200CDE0.c and src/matched/unit_0200CFA0.c); the
 * second is `u32` here and `u16` at the call sites, which widens without
 * truncation, so neither caller's argument changes.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/ZUKAN_SAVE_SetSeenFormFlag.c \
 *       --func ZUKAN_SAVE_SetSeenFormFlag --addr 0x0200C914 --cc 1.1p1 --thumb
 *   -> EXACT* (216 code bytes; the listing extent runs to 224 over the eight
 *      bytes of literal pool that follow the body)
 */
void ZUKAN_SAVE_SetSeenFormFlag(struct ZukanSave *pZukan, u32 species, u32 sel, u32 shiny, u32 form)
{
    u32 formBitBase;
    u32 numForms;
    u16 formOffset;

    formBitBase = ZUKAN_SAVE_GetFormBitBase((u16)species);
    if (formBitBase == (u32)-1) {
        return;
    }
    if (species == 0x15F) {
        form = 0;
        numForms = 4;
    } else if (species == 0x1A5) {
        form = 0;
        numForms = 2;
    } else if (species == 0x22B) {
        form = 0;
        numForms = 2;
    } else if (species == 0x288) {
        form = 0;
        numForms = 2;
    } else {
        if (form >= ZUKAN_SAVE_GetFormCount((u16)species)) {
            form = 0;
        }
        numForms = 1;
    }
    if (shiny == 1) {
        for (formOffset = 0; formOffset < numForms; formOffset++) {
            u8 bitMask;
            s32 bitIndex = (u16)(formBitBase + form + formOffset);
            bitMask = (u8)(1 << (bitIndex & 7));
            pZukan->seenFormFlags[1][bitIndex >> 3] |= bitMask;
        }
    } else {
        for (formOffset = 0; formOffset < numForms; formOffset++) {
            u8 bitMask;
            s32 bitIndex = (u16)(formBitBase + form + formOffset);
            bitMask = (u8)(1 << (bitIndex & 7));
            pZukan->seenFormFlags[0][bitIndex >> 3] |= bitMask;
        }
    }
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           ZUKAN_SAVE_EnableNationalDex, ZUKAN_SAVE_IsNationalDexEnabled, ZUKAN_SAVE_SetDexObtained, ZUKAN_SAVE_GetDexObtained,
 *           ZUKAN_SAVE_SetViewMode, ZUKAN_SAVE_GetViewMode, ZUKAN_SAVE_SetLastViewedSpecies, ZUKAN_SAVE_GetLastViewedSpecies
 *
 * 172 bytes, 0x0200C9EC..0x0200CA98, 12 functions, nine of which carry no
 * label in the generated listing.
 *
 * The opening of the save block with id 0x37: ZUKAN_SAVE_GetSize returns 0x4D4,
 * ZUKAN_SAVE_Init clears exactly 0x4D4 bytes and stamps 0xBEEFCAFE into the
 * first word, and ZUKAN_SAVE_GetBlock is the whole of the lookup
 * `func_020071CC(sys, 0x37)`.  The magic word is the tell that the record is
 * checked rather than merely zeroed; nothing in this range reads it back.
 *
 * The word at +0x04 is a packed set of bitfields, and the widths are read off
 * the shift pairs rather than guessed: `lsls #0x15` / `lsrs #0x16` is bits
 * 1..10 and `lsls #0x0A` / `lsrs #0x16` is bits 12..21, so the layout is
 * 1 + 10 + 1 + 10 bits with the top ten unused by anything in this range.
 * ZUKAN_SAVE_GetLastViewedSpecies truncates its ten-bit field to `u16` on the way out, which is
 * the second shift pair in it and is a return type rather than a field width.
 *
 * This unit stops at 0x0200CA98 rather than running to the end of the
 * original file: ZUKAN_SAVE_UpdateViewFlags is 376 bytes of bit-array maintenance over
 * three module-level tables and is not attempted here.
 */
u32 ZUKAN_SAVE_GetSize(void)
{
    return sizeof(struct ZukanSave);
}





void ZUKAN_SAVE_Init(struct ZukanSave *pZukan)
{
    MI_CpuFill8(pZukan, 0, sizeof(struct ZukanSave));
    pZukan->magic = 0xBEEFCAFE;
}



void *ZUKAN_SAVE_GetBlock(void *saveControl)
{
    return func_020071CC(saveControl, 0x37);
}



void *ZUKAN_SAVE_GetFromGameData(void *gameData)
{
    return ZUKAN_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
}



struct ZukanSave *ZUKAN_SAVE_EnableNationalDex(struct ZukanSave *pZukan)
{
    pZukan->nationalDexEnabled = 1;
    return pZukan;
}



u32 ZUKAN_SAVE_IsNationalDexEnabled(struct ZukanSave *pZukan)
{
    return pZukan->nationalDexEnabled;
}



struct ZukanSave *ZUKAN_SAVE_SetDexObtained(struct ZukanSave *pZukan)
{
    pZukan->dexObtained = 1;
    return pZukan;
}



u32 ZUKAN_SAVE_GetDexObtained(struct ZukanSave *pZukan)
{
    return pZukan->dexObtained;
}



void ZUKAN_SAVE_SetViewMode(struct ZukanSave *pZukan, u32 value)
{
    pZukan->viewMode = value;
}



u32 ZUKAN_SAVE_GetViewMode(struct ZukanSave *pZukan)
{
    return pZukan->viewMode;
}



void ZUKAN_SAVE_SetLastViewedSpecies(struct ZukanSave *pZukan, u32 value)
{
    pZukan->lastViewedSpecies = value;
}



u16 ZUKAN_SAVE_GetLastViewedSpecies(struct ZukanSave *pZukan)
{
    return pZukan->lastViewedSpecies;
}




static inline void FormSetBit(u8 *flags, u16 bitIndex)
{
    flags[bitIndex >> 3] |= (u8)(1 << (bitIndex & 7));
}




static inline void FormResetBit(u8 *flags, u16 bitIndex)
{
    flags[bitIndex >> 3] &= (u8)((1 << (bitIndex & 7)) ^ 0xFF);
}




static inline void SetBit(u8 *flags, u16 species)
{
    species--;
    flags[species >> 3] |= (u8)(1 << (species & 7));
}




static inline void ResetBit(u8 *flags, u16 species)
{
    species--;
    flags[species >> 3] &= (u8)((1 << (species & 7)) ^ 0xFF);
}




/*
 * The bitmap maintenance of "musical_dist_save.c" (block 0x37): for a
 * species id listed in the {id, count} form table it clears the species'
 * run of form bits in the two nine-byte form rows at +0x30E and +0x317,
 * clamps the caller's form index to the species' count and sets that one
 * form bit in the row `alt` picks; then, for every species, it clears the
 * id's bit in the four 0x54-byte rows at +0x1AC and sets it in the row
 * chosen by (sel, alt), with the same six-arm shape as ZUKAN_SAVE_SetSeenGenderFlag.
 *
 * Written from the start (wave 20, lane musical_fresh) after five lanes
 * iterated on one inherited source and stopped at 89 bytes out; see
 * docs/notes/pkt_0200CA98.c.txt.  Two things closed it:
 *
 *  - The bit operations are four inline helpers on a u16 index, two plain
 *    ones for the flat form index and two that decrement the 1-based
 *    species id first (the `subs #1` / `lsls #0x10` / `lsrs #0x10` on the
 *    id, with no narrowing of id itself because it arrives as u16).  The
 *    inlining is what puts x>>3, 1<<(x&7) and the 0xFF mask into shared
 *    values: the tail's bit and byte offset are computed once, before the
 *    clear loop, and reused by all six set arms.
 *  - Every row argument is passed through an explicit `(u8 *)` cast.  With
 *    the bare array (`p->viewGenderFlags[i]`, which decays to the same type) the
 *    optimizer reassociates the address as (p + off) + K and keeps K in a
 *    register; the cast keeps p + K as one operand, so p + 0x30E / p + 0x317
 *    are hoisted out of the form loop and p + 0x1AC out of the clear loop,
 *    as the image does.  That also moves p off the register file onto the
 *    stack, which was the tail's register rotation.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/ZUKAN_SAVE_UpdateViewFlags.c \
 *       --func ZUKAN_SAVE_UpdateViewFlags --addr 0x0200CA98
 *   -> EXACT (392 bytes, both table literals resolved)
 */
void ZUKAN_SAVE_UpdateViewFlags(struct ZukanSave *pZukan, u16 species, u32 gender, u32 shiny, u32 form)
{
    u32 tableIdx;
    u32 formIdx;
    u32 formBitBase;

    formBitBase = 0;
    tableIdx = 0;
    do {
        if (species == sZukanFormTable[tableIdx].id) {
            for (formIdx = 0; formIdx < sZukanFormTable[tableIdx].count; formIdx++) {
                FormResetBit((u8 *)pZukan->viewFormFlags[0], formBitBase + formIdx);
                FormResetBit((u8 *)pZukan->viewFormFlags[1], formBitBase + formIdx);
            }
            if (form >= sZukanFormTable[tableIdx].count) {
                form = 0;
            }
            if (shiny == 1) {
                FormSetBit((u8 *)pZukan->viewFormFlags[1], formBitBase + form);
            } else {
                FormSetBit((u8 *)pZukan->viewFormFlags[0], formBitBase + form);
            }
            break;
        }
        formBitBase += sZukanFormTable[tableIdx].count;
        tableIdx++;
    } while (sZukanFormTable[tableIdx].id != 0);

    for (tableIdx = 0; tableIdx < 4; tableIdx++) {
        ResetBit((u8 *)pZukan->viewGenderFlags[tableIdx], species);
    }
    if (gender == 0) {
        if (shiny == 1) {
            SetBit((u8 *)pZukan->viewGenderFlags[2], species);
        } else {
            SetBit((u8 *)pZukan->viewGenderFlags[0], species);
        }
    } else if (gender == 1) {
        if (shiny == 1) {
            SetBit((u8 *)pZukan->viewGenderFlags[3], species);
        } else {
            SetBit((u8 *)pZukan->viewGenderFlags[1], species);
        }
    } else {
        if (shiny == 1) {
            SetBit((u8 *)pZukan->viewGenderFlags[2], species);
        } else {
            SetBit((u8 *)pZukan->viewGenderFlags[0], species);
        }
    }
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 32 bytes, 0x0200CC20..0x0200CC40, one function, which carries a label in the
 * generated listing.
 *
 * The table at 0x0209DE4C is a run of `{u16 form; u16 count;}` pairs: this
 * function returns the count for a form group and ZUKAN_SAVE_UpdateViewFlags walks the same
 * array looking for the first pair whose first halfword matches.  The stride is
 * four, which is the `lsls #2` here and in ZUKAN_SAVE_UpdateViewFlags, so the two halfwords
 * are one record and not two parallel arrays; the pool word for the second
 * field is the symbol plus two rather than a second symbol.
 *
 * The branch that answers 1 is the `else`, so the table lookup is the source's
 * `then`: written the other way round, as a guard returning 1 first, the
 * condition inverts and the two arms swap.  See
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.
 *
 * Two near misses in the same original file, recorded here because this is the
 * matched file next to them.
 *
 * ZUKAN_SAVE_UpdateViewFlags, 376 bytes at 0x0200CA98, the bit-array maintenance this
 * table drives.  It comes out four bytes short of 392 with the right control
 * flow throughout: mwccarm hoists the two loop-invariant bitmap pointers above
 * the loop's own entry test, where the original computes them in the loop
 * preheader and reloads the block pointer from its spill slot once for each of
 * them, and it hoists `m + (id >> 3)` out of the four-iteration clearing loop,
 * where the original forms `m + i * 0x54` first and leaves the byte index as
 * the load's register operand.  Both are the same choice of which half of an
 * address expression to make loop-invariant, and neither moved under any of the
 * shapes tried: the two pointers as locals assigned before the loop, assigned
 * inside it and written out inline; the loop as `for`, as `do`/`while` and
 * behind an explicit `if (n != 0)` guard; the mask operands in both orders; and
 * the row index through a `u8 (*)[0x54]` local, through the struct member and
 * through a flat offset.
 *
 * ZUKAN_SAVE_GetViewGenderAndForm, 402 bytes at 0x0200CC40, the query that reads the same three
 * bitmap groups back.  Its first half reproduces instruction for instruction;
 * its second half, four independent `if`s that each test one bitmap and write
 * two out-parameters, does not, because the original recomputes the shift, the
 * mask and the base address inside every one of the four blocks and mwccarm
 * computes them once in the dominating block and reuses them.  That is 52 bytes
 * of common subexpressions the original does not share, and writing the
 * expressions out in full in each block does not restore them.
 */
u16 ZUKAN_SAVE_GetFormCount(u32 species)
{
    s32 tableIdx = ZUKAN_SAVE_GetFormTableIndex(species);

    if (tableIdx != -1) {
        return sZukanFormTable[tableIdx].count;
    }
    return 1;
}








static inline u32 TestBit(const u8 *row, u16 bitIndex)
{
    return row[bitIndex >> 3] & (1 << (bitIndex & 7));
}








static inline u32 TestSpecies(const u8 *row, u32 species)
{
    u16 bitIndex = species - 1;
    return row[bitIndex >> 3] & (1 << (bitIndex & 7));
}








/*
 * The reader half of ZUKAN_SAVE_UpdateViewFlags: find which form bit (rows +0x30E /
 * +0x317) and which of the four per-species rows (+0x1AC/+0x200/+0x254/
 * +0x2A8) are set for species `id`, report them through out1/out2/outForm,
 * then look the result up through POKE_PERSONAL_Create (docs/notes/
 * pkt_0200CC40.c.txt has the decode and the wave-11 form-loop work).
 *
 * Closed in wave 13 by two declaration facts:
 *   - `id` is a u16 PARAMETER.  The image homes r1 to [sp] and then RELOADS
 *     it for the first call (`str r1, [sp] ... ldr r0, [sp]`), the
 *     narrow-parameter tell (docs/idioms/a-narrow-parameter-pins-its-home-
 *     store-to-the-front-of-the-prologue.md); a u32 id copies r1 instead.
 *   - the per-species row tests go through their OWN helper that takes the
 *     1-based species id and forms `u16 x = id - 1` inside.  Each inlined
 *     copy has its own `x`, so the subtraction is shared but `x & 7` and
 *     `x >> 3` are rebuilt at every test, exactly the "rebuild at every
 *     join" the wave-11 note could not reproduce with one shared index.
 *     The two tests of an `||` pair still share the mask, as in the image.
 */
void ZUKAN_SAVE_GetViewGenderAndForm(struct ZukanSave *pZukan, u16 species, u32 *outGender, u32 *outShiny, u32 *outForm, u16 language)
{
    u32 tableIdx;
    u32 formBitBase;
    u32 formIdx;
    void *pPersonal;

    tableIdx = ZUKAN_SAVE_GetFormTableIndex(species);
    if (tableIdx != (u32)-1) {
        formBitBase = ZUKAN_SAVE_GetFormBitBase(species);
        for (formIdx = 0; formIdx < sZukanFormTable[tableIdx].count; formIdx++) {
            if (TestBit(pZukan->viewFormFlags[0], formBitBase + formIdx)) {
                *outForm = formIdx;
                *outShiny = 0;
                break;
            }
            if (TestBit(pZukan->viewFormFlags[1], formBitBase + formIdx)) {
                *outForm = formIdx;
                *outShiny = 1;
                break;
            }
        }
        if (TestSpecies(pZukan->viewGenderFlags[0], species) || TestSpecies(pZukan->viewGenderFlags[2], species)) {
            *outGender = 0;
        }
        if (TestSpecies(pZukan->viewGenderFlags[1], species) || TestSpecies(pZukan->viewGenderFlags[3], species)) {
            *outGender = 1;
        }
    } else {
        *outForm = 0;
        if (TestSpecies(pZukan->viewGenderFlags[0], species)) {
            *outGender = 0;
            *outShiny = 0;
        }
        if (TestSpecies(pZukan->viewGenderFlags[1], species)) {
            *outGender = 1;
            *outShiny = 0;
        }
        if (TestSpecies(pZukan->viewGenderFlags[2], species)) {
            *outGender = 0;
            *outShiny = 1;
        }
        if (TestSpecies(pZukan->viewGenderFlags[3], species)) {
            *outGender = 1;
            *outShiny = 1;
        }
    }
    pPersonal = POKE_PERSONAL_Create(species, (u16)*outForm, language);
    if (POKE_PERSONAL_GetParam(pPersonal, 0x14) == 0xFF) {
        *outGender = 2;
    }
    POKE_PERSONAL_Delete(pPersonal);
}









/*
 * 244 bytes, 0x0200CDE0..0x0200CED4, one function, which carries a label in
 * the generated listing.
 *
 * PROMOTED from src/pending/, where it was parked at MATCH on the `matched`
 * class: the call at +0xCC into ZUKAN_SAVE_SetLanguageFlag had no witness outside the
 * compared range.  0x0200C738 acquired its own EXACT entry
 * (src/matched/ZUKAN_SAVE_SetLanguageFlag.c, shard layout/matched/arm9/pkt_0200C738.json)
 * in a later wave, and the tu now resolves 16 of 16 relocations.  No byte of
 * the C changed to close it.
 *
 * src/matched/unit_0200CFA0.c is the same function without the ZUKAN_SAVE_SetLanguageFlag
 * call and without the final bit set; the two were written together and the
 * diff between them is the honest description of what this one does extra.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0200CDE0.c \
 *       --addr 0x0200CDE0 --thumb
 *
 * Addresses are Black-image addresses.
 */
void ZUKAN_SAVE_RegisterCaught(struct ZukanSave *pZukan, void *pMon)
{
    u32 savedPartyParam;
    u32 shiny;
    u32 personality;
    u32 language;
    u32 gender;
    u32 form;
    u16 species;
    s32 bitIndex;

    savedPartyParam = POKE_TOOL_DecodePartyParam(pMon);
    if (POKE_TOOL_GetPartyValue(pMon, 0x4C, 0) == 1) {
        POKE_TOOL_EncodePartyParam(pMon, savedPartyParam);
        return;
    }
    species = (u16)POKE_TOOL_GetPartyValue(pMon, 5, 0);
    personality = POKE_TOOL_GetPartyValue(pMon, 0, 0);
    form = POKE_TOOL_GetPartyValue(pMon, 0x6F, 0);
    language = POKE_TOOL_GetPartyValue(pMon, 0xC, 0);
    gender = POKE_TOOL_GetGender(pMon);
    shiny = POKE_TOOL_IsShiny(pMon);
    POKE_TOOL_EncodePartyParam(pMon, savedPartyParam);
    if (ZUKAN_SAVE_IsInvalidSpecies(species) != 0) {
        return;
    }
    if (ZUKAN_SAVE_IsSeen(pZukan, species) == 0) {
        ZUKAN_SAVE_UpdateViewFlags(pZukan, species, gender, shiny, form);
    }
    if (species == 0x147 && pZukan->spindaPersonality == 0) {
        pZukan->spindaPersonality = personality;
    }
    ZUKAN_SAVE_SetSeenGenderFlag(pZukan, species, gender, shiny);
    ZUKAN_SAVE_SetSeenFormFlag(pZukan, species, gender, shiny, form);
    ZUKAN_SAVE_SetLanguageFlag(pZukan, species, language);
    bitIndex = (u16)(species - 1);
    pZukan->caughtFlags[bitIndex >> 3] |= (u8)(1 << (bitIndex & 7));
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 */
u32 ZUKAN_SAVE_IsCaught(struct ZukanSave *pZukan, u16 species)
{
    s32 bitIndex;
    u32 isCaught;

    if (ZUKAN_SAVE_IsInvalidSpecies(species) != 0) {
        return 0;
    }
    bitIndex = (u16)(species - 1);
    isCaught = 1;
    if ((pZukan->caughtFlags[bitIndex >> 3] & (1 << (bitIndex & 7))) == 0) {
        isCaught = 0;
    }
    return isCaught;
}



u16 ZUKAN_SAVE_CountCaught(struct ZukanSave *pZukan, u32 heap)
{
    if (ZUKAN_SAVE_IsNationalDexEnabled(pZukan) != 0) {
        return ZUKAN_SAVE_CountCaughtNational(pZukan);
    }
    return ZUKAN_SAVE_CountCaughtRegional(pZukan, heap);
}



u16 ZUKAN_SAVE_CountCaughtNational(struct ZukanSave *pZukan)
{
    s32 count;
    s32 species;

    count = 0;
    for (species = 1; species <= 0x289; species++) {
        if (ZUKAN_SAVE_IsCaught(pZukan, (u16)species) == 1) {
            count++;
        }
    }
    return (u16)count;
}



u16 ZUKAN_SAVE_CountCaughtRegional(struct ZukanSave *pZukan, u32 heap)
{
    u16 species;
    u16 count;
    u16 *pFormTable;

    count = 0;
    pFormTable = POKE_PERSONAL_LoadFormTable(heap, 0);
    for (species = 1; species <= 0x289; species++) {
        if (ZUKAN_SAVE_IsCaught(pZukan, species) == 1 && pFormTable[species] != 0x3E7) {
            count = (u16)(count + 1);
        }
    }
    func_020307B0(pFormTable);
    return count;
}




void ZUKAN_SAVE_RegisterSeen(struct ZukanSave *pZukan, void *pMon)
{
    u32 savedPartyParam;
    u32 shiny;
    u32 personality;
    u32 gender;
    u32 form;
    u16 species;

    savedPartyParam = POKE_TOOL_DecodePartyParam(pMon);
    if (POKE_TOOL_GetPartyValue(pMon, 0x4C, 0) == 1) {
        POKE_TOOL_EncodePartyParam(pMon, savedPartyParam);
        return;
    }
    species = (u16)POKE_TOOL_GetPartyValue(pMon, 5, 0);
    personality = POKE_TOOL_GetPartyValue(pMon, 0, 0);
    form = POKE_TOOL_GetPartyValue(pMon, 0x6F, 0);
    gender = POKE_TOOL_GetGender(pMon);
    shiny = POKE_TOOL_IsShiny(pMon);
    POKE_TOOL_EncodePartyParam(pMon, savedPartyParam);
    if (ZUKAN_SAVE_IsInvalidSpecies(species) != 0) {
        return;
    }
    if (ZUKAN_SAVE_IsSeen(pZukan, species) == 0) {
        ZUKAN_SAVE_UpdateViewFlags(pZukan, species, gender, shiny, form);
    }
    if (species == 0x147 && pZukan->spindaPersonality == 0) {
        pZukan->spindaPersonality = personality;
    }
    ZUKAN_SAVE_SetSeenGenderFlag(pZukan, species, gender, shiny);
    ZUKAN_SAVE_SetSeenFormFlag(pZukan, species, gender, shiny, form);
}




static inline u8 *SeenRow(struct ZukanSave *pZukan, u16 row)
{
    return pZukan->seenFlags[row];
}



/*
 * The four-row "distributed" test: after the ZUKAN_SAVE_IsInvalidSpecies range guard,
 * true when species `id` has its bit set in any of the four 0x54-byte rows
 * struct ZukanSave::seenFlags (docs/families/musical_dist_save.h).
 *
 * Closed in wave 13 by writing it through two small inline helpers instead
 * of one open-coded address (docs/notes/pkt_0200D064.c.txt has the long
 * history of the open-coded spellings, best 10 bytes out):
 *   - a row accessor taking a u16 row index, which is where the image's
 *     `lsls/lsrs #16` of the u32 loop counter at every use comes from;
 *   - the species-bit test `TestSpecies(row, id)` that forms `u16 x = id -
 *     1` itself (the same helper closed ZUKAN_SAVE_GetViewGenderAndForm).  Inlined, it keeps
 *     `row + (x >> 3)` in the image's operand order instead of letting the
 *     compiler hoist `p + (x >> 3)` out of the loop, and the plain
 *     `return 1;` inside the loop then gives the preheader `movs r0, #1`.
 */
u32 ZUKAN_SAVE_IsSeen(struct ZukanSave *pZukan, u16 species)
{
    u32 row;

    if (ZUKAN_SAVE_IsInvalidSpecies(species) != 0) {
        return 0;
    }
    for (row = 0; row < 4; row++) {
        if (TestSpecies(SeenRow(pZukan, row), species)) {
            return 1;
        }
    }
    return 0;
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 152 bytes, 0x0200D0AC..0x0200D144, 3 functions, all labelled.
 *
 * The "seen" counterpart of src/matched/unit_0200CED4.c: the same three
 * functions over ZUKAN_SAVE_IsSeen's four-bitmap test instead of ZUKAN_SAVE_IsCaught's
 * single one.  0x289 is 649, one past the last species id this block tracks,
 * and 0x3E7 is the 999 the id-to-index table uses for "no entry".
 *
 * Near miss, and the reason this range starts at 0x0200D0AC: ZUKAN_SAVE_IsSeen,
 * 72 bytes, the four-bitmap test itself.  Every instruction reproduces bar the
 * placement of one `adds`: the original recomputes `p + i * 0x54 + (id >> 3)`
 * inside the loop, and mwccarm hoists the loop-invariant `p + (id >> 3)` into
 * the preheader instead, which leaves the same instruction count and the same
 * 72 bytes with 30 concrete bytes differing in register numbers.  Eighty
 * source shapes were compiled and ranked: the loop counter as `u16`, `u32` and
 * `s32`, the index with and without a `(u16)` cast, the bit mask and the byte
 * index as locals and inline, `for` against `do`/`while`, `goto` against
 * `return`, and the row as a pointer local, a dereferenced sum and a flat
 * index.  Only the `(u16)` cast on the index and the mask in a local reach the
 * right size at all, and past that the ranking is flat at 30, so the hoist is
 * not reachable from the source shape.  Same class as the near misses at
 * 0x0200B2A4 and 0x0200B37C.
 */
u32 ZUKAN_SAVE_CountSeen(struct ZukanSave *pZukan, u32 heap)
{
    if (ZUKAN_SAVE_IsNationalDexEnabled(pZukan) != 0) {
        return ZUKAN_SAVE_CountSeenNational(pZukan);
    }
    return ZUKAN_SAVE_CountSeenRegional(pZukan, heap);
}



u16 ZUKAN_SAVE_CountSeenNational(struct ZukanSave *pZukan)
{
    s32 count;
    s32 species;

    count = 0;
    for (species = 1; species <= 0x289; species++) {
        if (ZUKAN_SAVE_IsSeen(pZukan, (u16)species) == 1) {
            count++;
        }
    }
    return (u16)count;
}



u16 ZUKAN_SAVE_CountSeenRegional(struct ZukanSave *pZukan, u32 heap)
{
    u16 species;
    u16 count;
    u16 *pFormTable;

    count = 0;
    pFormTable = POKE_PERSONAL_LoadFormTable(heap, 0);
    for (species = 1; species <= 0x289; species++) {
        if (ZUKAN_SAVE_IsSeen(pZukan, species) == 1 && pFormTable[species] != 0x3E7) {
            count = (u16)(count + 1);
        }
    }
    func_020307B0(pFormTable);
    return count;
}





/*
 * The five-way reader over the bitmaps ZUKAN_SAVE_SetSeenGenderFlag/ZUKAN_SAVE_SetSeenFormFlag write
 * (decode in docs/notes/pkt_0200D144.c.txt).  EXACT* only because the
 * 16-byte leaf that follows it, ZUKAN_SAVE_GetSpindaPersonality, has no label; that leaf is
 * filed as its own witness, src/matched/ZUKAN_SAVE_GetSpindaPersonality.c.
 *
 * Closed in wave 13: the two-row tests of the last two arms go through the
 * species-bit helper `TestSpecies(row, id)` (it forms `u16 x = id - 1`
 * itself, as in ZUKAN_SAVE_GetViewGenderAndForm and ZUKAN_SAVE_IsSeen), joined by `||`.  Each
 * inlined copy has its own `x`, so the image's second `adds r0, r5, r1`
 * (p + off formed again for the +0xB0 row) comes out, which no open-coded
 * spelling reached (it was 2 bytes short or 2 long, never right).  The
 * single-row arms keep the open-coded `r = 1; if (!bit) r = 0; return r;`
 * shape that gives their shared `bne` tail.
 */
u32 ZUKAN_SAVE_HasSeenGenderForm(struct ZukanSave *pZukan, u16 species, u32 gender, u32 shiny, u32 form)
{
    u32 formBitBase;
    s32 bitIndex;
    u32 bitMask;
    u32 isSet;

    if (ZUKAN_SAVE_IsInvalidSpecies(species) != 0) {
        return (u32)-1;
    }
    formBitBase = ZUKAN_SAVE_GetFormBitBase(species);
    if (formBitBase != (u32)-1) {
        bitIndex = (u16)(formBitBase + form);
        bitMask = 1 << (bitIndex & 7);
        isSet = 1;
        if ((pZukan->seenFormFlags[shiny][bitIndex >> 3] & bitMask) == 0) {
            isSet = 0;
        }
        return isSet;
    }
    if (gender == 0) {
        if (shiny == 1) {
            bitIndex = (u16)(species - 1);
            bitMask = 1 << (bitIndex & 7);
            isSet = 1;
            if ((pZukan->seenFlags[2][bitIndex >> 3] & bitMask) == 0) {
                isSet = 0;
            }
            return isSet;
        }
        bitIndex = (u16)(species - 1);
        bitMask = 1 << (bitIndex & 7);
        isSet = 1;
        if ((pZukan->seenFlags[0][bitIndex >> 3] & bitMask) == 0) {
            isSet = 0;
        }
        return isSet;
    }
    if (gender == 1) {
        if (shiny == 1) {
            bitIndex = (u16)(species - 1);
            bitMask = 1 << (bitIndex & 7);
            isSet = 1;
            if ((pZukan->seenFlags[3][bitIndex >> 3] & bitMask) == 0) {
                isSet = 0;
            }
            return isSet;
        }
        bitIndex = (u16)(species - 1);
        bitMask = 1 << (bitIndex & 7);
        isSet = 1;
        if ((pZukan->seenFlags[1][bitIndex >> 3] & bitMask) == 0) {
            isSet = 0;
        }
        return isSet;
    }
    if (shiny == 1) {
        if (TestSpecies(pZukan->seenFlags[2], species) || TestSpecies(pZukan->seenFlags[3], species)) {
            goto oneA;
        }
        goto zero;
oneA:
        return 1;
    }
    if (TestSpecies(pZukan->seenFlags[0], species) || TestSpecies(pZukan->seenFlags[1], species)) {
        goto oneB;
    }
    goto zero;
oneB:
    return 1;
zero:
    return 0;
}





/*
 * The 16-byte leaf that follows ZUKAN_SAVE_HasSeenGenderForm inside its listing extent
 * (0x0200D288..0x0200D298): `cmp r1, #0 / bne / movs r1, #0x4d / lsls r1,
 * #4 / ldr r0, [r0, r1] / bx lr / movs r0, #0 / bx lr`.  It saves nothing,
 * so disasm.py never labels it (docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md); filed as its own compiled witness in wave 13.  It reads
 * struct ZukanSave's +0x4D0 word, the first-write-wins species-0x147 cache that
 * ZUKAN_SAVE_RegisterCaught/ZUKAN_SAVE_RegisterSeen fill (docs/families/musical_dist_save.h), and
 * answers 0 for any selector but 0.  Wants seeding into
 * layout/function_starts.txt.
 */
u32 ZUKAN_SAVE_GetSpindaPersonality(struct ZukanSave *pZukan, u32 which)
{
    if (which == 0) {
        return pZukan->spindaPersonality;
    }
    return 0;
}




int ZUKAN_SAVE_IsNationalCaughtComplete(struct ZukanSave *pZukan)
{
    u32 caughtCount = ZUKAN_SAVE_CountCaughtNationalCounted(pZukan);

    if (caughtCount >= 0x27a)
        return 1;
    return 0;
}





/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 */
int ZUKAN_SAVE_IsRegionalCaughtComplete(struct ZukanSave *pZukan, int heap)
{
    u32 caughtCount = ZUKAN_SAVE_CountCaughtRegionalCounted(pZukan, heap);

    if (caughtCount >= 0x96)
        return 1;
    return 0;
}




int ZUKAN_SAVE_IsRegionalSeenComplete(struct ZukanSave *pZukan, unsigned int heap)
{
    return ZUKAN_SAVE_CountSeenRegionalCounted(pZukan, heap) >= 0x96;
}





u16 ZUKAN_SAVE_CountCaughtNationalCounted(struct ZukanSave *pZukan)
{
    int species;
    u16 count = 0;

    for (species = 1; species <= 0x289; species++) {
        if (ZUKAN_SAVE_IsCaught(pZukan, species) == 1 && ZUKAN_SAVE_IsCountedForNationalCompletion((u16)species) == 1)
            count++;
    }
    return count;
}





int ZUKAN_SAVE_CountCaughtRegionalCounted(struct ZukanSave *pZukan, int heap)
{
    u16 *pFormTable = POKE_PERSONAL_LoadFormTable(heap, 0);
    u16 species;
    u16 count = 0;

    for (species = 1; species <= 0x289; species++) {
        if (ZUKAN_SAVE_IsCaught(pZukan, species) != 1) {
            continue;
        }
        if (pFormTable[species] == 0x3e7) {
            continue;
        }
        if (ZUKAN_SAVE_IsCountedForRegionalCompletion(species) == 1) {
            count++;
        }
    }
    func_020307B0(pFormTable);
    return count;
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 172 bytes, 0x0200D368..0x0200D414, 2 functions, one of which carries a label
 * in the generated listing.
 *
 * The tail of the save block with id 0x37, whose head is
 * src/matched/unit_0200C9EC.c.  ZUKAN_SAVE_CountSeenRegionalCounted counts the species this block
 * records as seen that the id table has an entry for and that ZUKAN_SAVE_IsCountedForRegionalCompletion
 * accepts; ZUKAN_SAVE_HasLanguageFlag reads a bit out of the flat 0x1B0-byte bitmap at
 * +0x320, indexed by `(b - 1) + (a - 1) * 7` over a range of 0x1ED rows.
 *
 * ZUKAN_SAVE_HasLanguageFlag saves `r4` without saving `lr`, so `disasm.py` does not label
 * it and it arrives in the listing as a run of `.word`s.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Its second selector is rejected above 8 and at exactly 6, and then
 * decremented above 6, so the seven live values 1..5, 7, 8 map onto 0..6; the
 * hole at 6 and the shift around it are in the original and are what the two
 * compares and the `subs` encode.
 *
 * This range starts at 0x0200D368 rather than at the head of the group because
 * ZUKAN_SAVE_IsCountedForRegionalCompletion is reached from exactly two places in the image, 0x0200D33A in
 * ZUKAN_SAVE_CountCaughtRegionalCounted and 0x0200D392 here, so a range holding both has no witness
 * left for it.  Cut between them and this half closes.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The other
 * half does not close, because ZUKAN_SAVE_IsCountedForNationalCompletion is reached only from
 * ZUKAN_SAVE_CountCaughtNationalCounted; it is parked in src/pending/unit_0200D288.c.
 *
 * Near miss in the same original file: ZUKAN_SAVE_HasSeenGenderForm, 322 bytes at
 * 0x0200D144, the five-way reader over the same bitmaps.  It reaches the right
 * size and the right control flow, and sixteen bytes in its last arm differ in
 * register numbers alone: the original keeps the shifted id in one register and
 * masks it into a scratch, and mwccarm masks in place and allocates the bit and
 * the loaded byte the other way round.  Adding a named local for the mask
 * fixes the arm before it, which is where the original also spends a register
 * copy, and adding one here costs an instruction the original does not have;
 * all 120 permutations of the five locals and every spelling of the two
 * operands rank flat at sixteen.
 */
u16 ZUKAN_SAVE_CountSeenRegionalCounted(struct ZukanSave *pZukan, u32 heap)
{
    u16 species;
    u16 count;
    u16 *pFormTable;

    count = 0;
    pFormTable = POKE_PERSONAL_LoadFormTable(heap, 0);
    for (species = 1; species <= 0x289; species++) {
        if (ZUKAN_SAVE_IsSeen(pZukan, species) == 1 && pFormTable[species] != 0x3E7 && ZUKAN_SAVE_IsCountedForRegionalCompletion(species) == 1) {
            count = (u16)(count + 1);
        }
    }
    func_020307B0(pFormTable);
    return count;
}



u32 ZUKAN_SAVE_HasLanguageFlag(struct ZukanSave *pZukan, u32 species, u32 language)
{
    s32 bitIndex;
    u32 isSet;

    if (language > 8 || language == 6) {
        return 0;
    }
    if (species > 0x1ED) {
        return 0;
    }
    if (language >= 7) {
        language--;
    }
    species--;
    bitIndex = (u16)((language - 1) + species * 7);
    isSet = 1;
    if ((pZukan->languageFlags[bitIndex >> 3] & (1 << (bitIndex & 7))) == 0) {
        isSet = 0;
    }
    return isSet;
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           MOVE_POKEMON_SAVE_GetStartLocation, MOVE_POKEMON_SAVE_SetCommonArea, MOVE_POKEMON_SAVE_GetEntryState, MOVE_POKEMON_SAVE_SetEntryState,
 *           MOVE_POKEMON_SAVE_GetEntryLocation, MOVE_POKEMON_SAVE_SetEntryLocation, MOVE_POKEMON_SAVE_IsEntryActive, MOVE_POKEMON_SAVE_InitEntry,
 *           MOVE_POKEMON_SAVE_GetEntry, MOVE_POKEMON_SAVE_GetEntryField, MOVE_POKEMON_SAVE_SetEntryField, MOVE_POKEMON_SAVE_SetCooldown,
 *           MOVE_POKEMON_SAVE_TickCooldown, MOVE_POKEMON_SAVE_IsCooldownDone
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * MOVE_POKEMON_SAVE_RollStartLocation is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: MOVE_POKEMON_SAVE_GetSize returns 0x34,
 * MOVE_POKEMON_SAVE_GetBlock is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * MOVE_POKEMON_SAVE_Init clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - MOVE_POKEMON_SAVE_TickCooldown reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    MOVE_POKEMON_SAVE_SetCooldown or MOVE_POKEMON_SAVE_IsCooldownDone, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 */
u32 MOVE_POKEMON_SAVE_GetSize(void)
{
    return sizeof(struct MovePokemonSave);
}




void *MOVE_POKEMON_SAVE_GetBlock(void *saveControl)
{
    return func_020071CC(saveControl, 0x38);
}




void MOVE_POKEMON_SAVE_Init(struct MovePokemonSave *pSave)
{
    MI_CpuFill8(pSave, 0, sizeof(struct MovePokemonSave));
    pSave->startLocation = 0;
    pSave->moveCooldown = 0;
}



void MOVE_POKEMON_SAVE_RollStartLocation(void *saveControl)
{
    struct MovePokemonSave *pSave = MOVE_POKEMON_SAVE_GetBlock(saveControl);

    pSave->startLocation = func_02005728(0x11);
}



u8 MOVE_POKEMON_SAVE_GetStartLocation(struct MovePokemonSave *pSave)
{
    return pSave->startLocation;
}



void MOVE_POKEMON_SAVE_SetCommonArea(struct MovePokemonSave *pSave, u16 area)
{
    if (pSave->commonArea != area) {
        pSave->prevCommonArea = pSave->commonArea;
        pSave->commonArea = area;
    }
}



u8 MOVE_POKEMON_SAVE_GetEntryState(struct MovePokemonSave *pSave, u32 slot)
{
    return pSave->entryState[slot];
}



void MOVE_POKEMON_SAVE_SetEntryState(struct MovePokemonSave *pSave, u32 slot, u32 state)
{
    pSave->entryState[slot] = state;
}



u8 MOVE_POKEMON_SAVE_GetEntryLocation(struct MovePokemonSave *pSave, u32 slot)
{
    return pSave->entryLocation[slot];
}



void MOVE_POKEMON_SAVE_SetEntryLocation(struct MovePokemonSave *pSave, u32 slot, u8 location)
{
    pSave->entryLocation[slot] = location;
}



u8 MOVE_POKEMON_SAVE_IsEntryActive(struct MovePokemonSave *pSave, u32 slot)
{
    return pSave->entries[slot].isActive;
}



void MOVE_POKEMON_SAVE_InitEntry(struct MovePokemonEntry *pEntry)
{
    MI_CpuFill8(pEntry, 0, sizeof(struct MovePokemonEntry));
    pEntry->entryId = 0xFFFF;
}



struct MovePokemonEntry *MOVE_POKEMON_SAVE_GetEntry(struct MovePokemonSave *pSave, u32 slot)
{
    return &pSave->entries[slot];
}



u32 MOVE_POKEMON_SAVE_GetEntryField(const struct MovePokemonEntry *pEntry, u32 field)
{
    switch (field) {
    case 0:
        break;
    case 1:
        return pEntry->entryId;
    case 2:
        return pEntry->ivData;
    case 3:
        return pEntry->personality;
    case 10:
        return pEntry->extraData;
    case 4:
        return pEntry->species;
    case 5:
        return pEntry->hp;
    case 6:
        return pEntry->level;
    case 7:
        return pEntry->status;
    case 8:
        return pEntry->isActive;
    case 9:
        return pEntry->spawned;
    }
    return 0;
}



void MOVE_POKEMON_SAVE_SetEntryField(struct MovePokemonEntry *pEntry, u32 field, u32 value)
{
    switch (field) {
    case 0:
        break;
    case 1:
        pEntry->entryId = value;
        break;
    case 2:
        pEntry->ivData = value;
        break;
    case 3:
        pEntry->personality = value;
        break;
    case 10:
        pEntry->extraData = value;
        break;
    case 4:
        pEntry->species = value;
        break;
    case 5:
        pEntry->hp = value;
        break;
    case 6:
        pEntry->level = value;
        break;
    case 7:
        pEntry->status = value;
        break;
    case 8:
        pEntry->isActive = value;
        break;
    case 9:
        pEntry->spawned = value;
        break;
    }
}



void MOVE_POKEMON_SAVE_SetCooldown(struct MovePokemonSave *pSave, u8 cooldown)
{
    pSave->moveCooldown = cooldown;
}



u32 MOVE_POKEMON_SAVE_TickCooldown(struct MovePokemonSave *pSave)
{
    if (pSave->moveCooldown != 0) {
        pSave->moveCooldown = pSave->moveCooldown - 1;
        if (pSave->moveCooldown == 0) {
            return 1;
        }
    }
    return 0;
}



u32 MOVE_POKEMON_SAVE_IsCooldownDone(struct MovePokemonSave *pSave)
{
    if (pSave->moveCooldown == 0) {
        return 1;
    }
    return 0;
}
