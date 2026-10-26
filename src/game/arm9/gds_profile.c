/*
 * file:     gds_profile.c
 * unit:     yes
 * function: GDS_PROFILE_Create, GDS_PROFILE_Delete, GDS_PROFILE_Init, GDS_PROFILE_CreateNameStr, GDS_PROFILE_GetEggFlag, GDS_PROFILE_GetSpecies, GDS_PROFILE_GetFormSpecies, GDS_PROFILE_GetNicknameFlag, GDS_PROFILE_GetBadEggFlag, GDS_PROFILE_GetValidatedCountry, GDS_PROFILE_GetValidatedRegion, GDS_PROFILE_ExportRecord, GDS_PROFILE_GetBirthMonth, GDS_PROFILE_GetTrainerSprite, GDS_PROFILE_GetLanguage, BSUBWAY_PLAYDATA_GetSize, BSUBWAY_PLAYDATA_Init, BSUBWAY_PLAYDATA_SetFlag01, BSUBWAY_PLAYDATA_GetFlag01, BSUBWAY_PLAYDATA_GetField, BSUBWAY_PLAYDATA_SetField, BSUBWAY_PLAYDATA_AddCounters, BSUBWAY_PLAYDATA_ClearRound, BSUBWAY_PLAYDATA_IncRound, BSUBWAY_PLAYDATA_GetRound, BSUBWAY_SCOREDATA_GetSize, BSUBWAY_SCOREDATA_Init, BSUBWAY_SCOREDATA_AddBattlePoints, BSUBWAY_SCOREDATA_SubBattlePoints, BSUBWAY_SCOREDATA_GetBattlePoints, BSUBWAY_SCOREDATA_MapPlayMode, BSUBWAY_SCOREDATA_GetWinCount, BSUBWAY_SCOREDATA_GetMaxWinCount, BSUBWAY_SCOREDATA_UpdateMaxWinCount, BSUBWAY_SCOREDATA_SetWinCount, BSUBWAY_SCOREDATA_ResetClearCount, BSUBWAY_SCOREDATA_SetFirstClear, BSUBWAY_SCOREDATA_HasCleared, BSUBWAY_SCOREDATA_IncClearCount, BSUBWAY_SCOREDATA_GetRepeatClearCount, BSUBWAY_SCOREDATA_AccessFlag, BSUBWAY_SCOREDATA_IncLevel, BSUBWAY_SCOREDATA_DecLevel, BSUBWAY_SCOREDATA_GetLevel, BSUBWAY_SCOREDATA_UpdateStreak, BSUBWAY_SCOREDATA_SetRecordBlob, BSUBWAY_SCOREDATA_GetRecordBlob, BSUBWAY_SCOREDATA_CalcRecordScore, BSUBWAY_SCOREDATA_GetRecordScore, BSUBWAY_SCOREDATA_GetRecordScoreTier, BSUBWAY_WIFIDATA_GetSize, BSUBWAY_WIFIDATA_Init, BSUBWAY_WIFIDATA_SetTrainerBit, BSUBWAY_WIFIDATA_ClearStampAndBitmap, BSUBWAY_WIFIDATA_IsStampNewer, BSUBWAY_WIFIDATA_GetTrainerBit
 * address:  0x0200D59C
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_HEAP_Free       0x020307B0  arm
 *   func_0200D59C_File  0x020A71E8  data
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   STRBUF_GetEosChar    0x02045A98  arm
 *   GF_STANDARD_CalcCrc16    0x0203F1FC  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   PMSI_PARAM_InitSentence  0x020242A4  thumb
 *   PMS_WORD_MakeWordId  0x02024888  thumb
 *   PMS_WORD_SplitWordId  0x020248D8  thumb
 *   GREETING_SAVEDATA_GetSentence  0x0200E6FC  thumb
 *   MISC_GetMonRecord  0x0200C164  thumb
 *   POKE_TOOL_FilterSpecies  0x02019D58  thumb
 *   WORDSET_CopyString  0x0201F41C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   WIFI_HISTORY_GetBlock  0x02009470  thumb
 *   GREETING_SAVEDATA_GetFromSaveThunk  0x0200E6E8  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   MYSTATUS_GetTrainerView  0x02008554  thumb
 *   MYSTATUS_GetNation  0x0200856C  thumb
 *   MYSTATUS_GetArea  0x02008570  thumb
 *   NATION_AREA_SanitizeNation  0x02025C1C  thumb
 *   NATION_AREA_SanitizeArea  0x02025C30  thumb
 */
#include "../version.h"
struct GameSys;
struct ProgressBlock;
struct MyStatus;
struct SaveDataObj;
struct RecordData;
struct Strbuf;
#include "../types.h"
#include "os_ownerinfo.h"

struct GdsMonRecord {
    u8 isEgg : 1;
    u8 form : 6;
    u8 gender : 1;
};

struct GdsProfile {
    u16 name[8];
    u32 trainerId;
    u8  gender;
    u8  birthMonth;
    u8  trainerSprite;
    u8  country;
    u8  region;
    u8  gameVersion;
    u8  language;
    struct GdsMonRecord mon;
    u16 species;
    u8  recordIsRaw;
    u8  pad1F;
    u16 record[0x28];
    u8  reserved70[0x0C];
    u16 checksum;
    u16 pad7E;
};


struct StoredMon {
    u8  reserved00[0x14];
    u8  isEgg;
    u8  reserved15[6];
    u8  isBadEgg : 1;
    u8  form : 6;
    u8  isNicknamed : 1;
    u16 species;
};

struct GdsRecord {
    u16 word00;
    u16 word02;
    u16 word04;
    u16 word06;
    u8  data08[0x20];
};

struct GdsProfileRaw {
    u8  reserved00[0x15];
    u8  birthMonth;
    u8  trainerSprite;
    u8  country;
    u8  region;
    u8  gameVersion;
    u8  language;
    u8  reserved1B[3];
    u8  isRaw;
    u8  reserved1F;
    struct GdsRecord record;
};

struct BsubwayPlayData {
    u16 flag00  : 1;
    u16 flag01  : 1;
    u16 value02  : 4;
    u16 value06  : 3;
    u16 flag09  : 1;
    u16 flag10 : 1;
    u16 value11 : 5;
    u8  round;
    u8  count03;
    u16 count04;
    u16 count06;
    u8  blob08[4];
    u8  blob0C[0x1C];
    u8  blob28[0x14];
};

struct BsubwayScoreData {
    u16 battlePoints;
    u8  streak;
    u8  level;
    u32 flags;
    u16 winCount[9];
    u16 maxWinCount[9];
    u16 clearCount[9];
    u16 score;
    u32 reserved40;
    u8  blob44[0xB4];
    u8  blobF8[0xB4];
};

struct GdsScoreSrc {
    u8  flags00;
    u8  flags01;
    u8  rank;
    u8  bonusA;
    u16 turns;
    u16 hp;
};

struct BsubwayWifiData {
    u32 stamp;
    u8  bitmap[250];
    u8  payload[0xA92];
};

struct Stamp {
    u32 time0;
    u32 time1;
    u32 time2;
    u32 tag;
};

#include "mi_memory.h"
#include "gfl_heap_wrap.h"
#include "strbuf.h"
#include "gf_standard.h"
struct GameData;
struct SaveControl;
#include "game_data.h"
struct WifiHistory;
#include "wifi_history.h"
#include "greeting_savedata.h"
struct QuadRecord;
#include "mystatus.h"
#include "wordset.h"
struct MiscSave;
#include "beacon.h"
#include "poke_tool.h"
#include "bmp_oam.h"
#include "pms_word.h"
#include "pmsi_param.h"
struct GdsProfile *GDS_PROFILE_Create(u32 heap);
void GDS_PROFILE_Delete(struct GdsProfile *profile);
void GDS_PROFILE_Init(struct GdsProfile *profile, void *sys);
void *GDS_PROFILE_CreateNameStr(const void *src, u32 tag);
u32 GDS_PROFILE_GetEggFlag(struct StoredMon *p);
u32 GDS_PROFILE_GetSpecies(struct StoredMon *p);
u32 GDS_PROFILE_GetFormSpecies(struct StoredMon *p);
u32 GDS_PROFILE_GetNicknameFlag(struct StoredMon *p);
u32 GDS_PROFILE_GetBadEggFlag(struct StoredMon *p);
u32 GDS_PROFILE_GetValidatedCountry(struct GdsProfileRaw *p);
u32 GDS_PROFILE_GetValidatedRegion(struct GdsProfileRaw *p);
void *GDS_PROFILE_ExportRecord(struct GdsProfileRaw *p, struct GdsRecord *out, u32 tag);
u32 GDS_PROFILE_GetBirthMonth(struct GdsProfileRaw *p);
u32 GDS_PROFILE_GetTrainerSprite(struct GdsProfileRaw *p);
u32 GDS_PROFILE_GetLanguage(struct GdsProfileRaw *p);
u32 BSUBWAY_PLAYDATA_GetSize(void);
void BSUBWAY_PLAYDATA_Init(struct BsubwayPlayData *p);
void BSUBWAY_PLAYDATA_SetFlag01(struct BsubwayPlayData *p, u32 v);
u32 BSUBWAY_PLAYDATA_GetFlag01(struct BsubwayPlayData *p);
u32 BSUBWAY_PLAYDATA_GetField(struct BsubwayPlayData *p, u32 id, void *out);
void BSUBWAY_PLAYDATA_SetField(struct BsubwayPlayData *p, u32 id, const void *src);
void BSUBWAY_PLAYDATA_AddCounters(struct BsubwayPlayData *p, s32 a, s32 b, s32 c);
void BSUBWAY_PLAYDATA_ClearRound(struct BsubwayPlayData *p);
void BSUBWAY_PLAYDATA_IncRound(struct BsubwayPlayData *p);
u16 BSUBWAY_PLAYDATA_GetRound(struct BsubwayPlayData *p);
u32 BSUBWAY_SCOREDATA_GetSize(void);
void BSUBWAY_SCOREDATA_Init(struct BsubwayScoreData *p);
void BSUBWAY_SCOREDATA_AddBattlePoints(struct BsubwayScoreData *p, s32 v);
void BSUBWAY_SCOREDATA_SubBattlePoints(struct BsubwayScoreData *p, u16 v);
u16 BSUBWAY_SCOREDATA_GetBattlePoints(struct BsubwayScoreData *p);
u32 BSUBWAY_SCOREDATA_MapPlayMode(u32 i);
u16 BSUBWAY_SCOREDATA_GetWinCount(struct BsubwayScoreData *p, u32 i);
u16 BSUBWAY_SCOREDATA_GetMaxWinCount(struct BsubwayScoreData *p, u32 i);
void BSUBWAY_SCOREDATA_UpdateMaxWinCount(struct BsubwayScoreData *p, u32 i, u16 v);
void BSUBWAY_SCOREDATA_SetWinCount(struct BsubwayScoreData *p, u32 i, u16 v);
void BSUBWAY_SCOREDATA_ResetClearCount(struct BsubwayScoreData *p, u32 i);
void BSUBWAY_SCOREDATA_SetFirstClear(struct BsubwayScoreData *p, u32 i);
u32 BSUBWAY_SCOREDATA_HasCleared(struct BsubwayScoreData *p, u32 i);
void BSUBWAY_SCOREDATA_IncClearCount(struct BsubwayScoreData *p, u32 i);
u16 BSUBWAY_SCOREDATA_GetRepeatClearCount(struct BsubwayScoreData *p, u32 i);
u32 BSUBWAY_SCOREDATA_AccessFlag(struct BsubwayScoreData *p, s32 i, u32 op);
void BSUBWAY_SCOREDATA_IncLevel(struct BsubwayScoreData *p);
void BSUBWAY_SCOREDATA_DecLevel(struct BsubwayScoreData *p);
u8 BSUBWAY_SCOREDATA_GetLevel(struct BsubwayScoreData *p);
u8 BSUBWAY_SCOREDATA_UpdateStreak(struct BsubwayScoreData *p, u32 kind);
void BSUBWAY_SCOREDATA_SetRecordBlob(struct BsubwayScoreData *p, u32 which, const void *src);
void BSUBWAY_SCOREDATA_GetRecordBlob(struct BsubwayScoreData *p, u32 which, void *dest);
void BSUBWAY_SCOREDATA_CalcRecordScore(struct BsubwayScoreData *p, const struct GdsScoreSrc *q);
u16 BSUBWAY_SCOREDATA_GetRecordScore(struct BsubwayScoreData *p);
u8 BSUBWAY_SCOREDATA_GetRecordScoreTier(struct BsubwayScoreData *p);
u32 BSUBWAY_WIFIDATA_GetSize(void);
void BSUBWAY_WIFIDATA_Init(struct BsubwayWifiData *p);
void BSUBWAY_WIFIDATA_SetTrainerBit(u8 *p, u8 a, u8 b, u32 *q);
void BSUBWAY_WIFIDATA_ClearStampAndBitmap(struct BsubwayWifiData *p);
u32 BSUBWAY_WIFIDATA_IsStampNewer(const struct Stamp *a, const struct Stamp *b);
int BSUBWAY_WIFIDATA_GetTrainerBit(struct BsubwayWifiData *p, u8 a, u8 b, const struct Stamp *q);
extern const char func_0200D59C_File[];

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 52 bytes, 0x0200D59C..0x0200D5D0, 2 functions, one of which carries no
 * label in the generated listing.
 *
 * alias: 0x020A71E8 spells "gds_profile.c", the sixth original source file
 * name this project has recovered, attested by the `string` class off the
 * terminator of "musical_dist_save.c" at 0x020A71E6.  The constructor at
 * 0x0200D59C passes it to the debug allocator at 0x02030734 with line 0x50,
 * and the rest of the file is src/matched/unit_0200D6D0.c,
 * src/matched/unit_0200D6EC.c and src/matched/unit_0200D74C.c, with
 * GDS_PROFILE_Init the one function of it left out; see below.
 *
 * The record is 0x80 bytes, which is what the constructor allocates and
 * clears, and which src/matched/unit_0200D5D0.c fills field by field.
 *
 * The heap id is a full word cast to `u16` at the call, not a `u16`
 * parameter: this front end assumes an incoming `u16` parameter is already
 * zero extended and emits nothing, so the `lsls #0x10` / `lsrs #0x10` pair at
 * 0x0200D5A2 is a narrowing the source wrote.  The same reading applies to
 * the tag parameters of GDS_PROFILE_CreateNameStr and GDS_PROFILE_ExportRecord.
 *
 * GDS_PROFILE_Delete is the destructor and is eight bytes: a pool word and a `bx`,
 * with no argument set-up at all; see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Left out of this range: GDS_PROFILE_Init, 256 bytes, which builds the whole
 * record.  Every concrete byte of it reproduces and it is capped at MATCH,
 * because 0x0200C164 is the target of exactly one branch in the image, its
 * own call at 0x0200D610, so the `label` class has no witness outside the
 * compared range and no cut helps.  The source is parked in
 * src/matched/unit_0200D5D0.c.
 */
struct GdsProfile *GDS_PROFILE_Create(u32 heap)
{
    struct GdsProfile *profile = GFL_HEAP_Alloc((u16)heap, sizeof(struct GdsProfile),
                                         0, func_0200D59C_File, 0x50);

    MI_CpuFill8(profile, 0, sizeof(struct GdsProfile));
    return profile;
}

void GDS_PROFILE_Delete(struct GdsProfile *profile)
{
    GFL_HEAP_Free(profile);
}

/*
 * 0x0200D5D0..0x0200D6D0, 256 bytes, one function.
 *
 * The record builder of "gds_profile.c"; see src/matched/unit_0200D59C.c for
 * the file name and the record.
 *
 * What held it open, and what closed it: 0x0200C164 is the target of exactly
 * one branch in the whole image, the `bl` at 0x0200D610 inside this very
 * function, so the `label` class discards its only witness under the honesty
 * rule, and `tu --suggest-split` could only answer by leaving this function
 * out.  0x0200C164 is part of src/matched/unit_0200C0E8.c, and that entry is
 * now evidence rather than a bare lookup: the `matched` class reads it as our
 * own byte-verified proof of what lives at that address, proved over a range
 * this file does not touch.  This header used to say a matched address is a
 * lookup and not evidence; the distinction it was missing is that an EXACT
 * entry is a comparison against the original bytes, not a name in a table.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0200D5D0.c \
 *       --addr 0x0200D5D0 --thumb
 *
 * Three details are worth having.
 *
 *  - the three bitfield writes at +0x1B each cast the source value to `u8`
 *    before the assignment, which is the `lsls #0x18` / `lsrs #0x18` pair in
 *    front of each mask; without the cast the pair is gone.  The widths come
 *    off the second pair: `lsls #0x1A` / `lsrs #0x19` is bits 1..6, `ands #1`
 *    is bit 0 and `lsls #0x1F` / `lsrs #0x18` is bit 7.
 *  - the four out-parameters of MISC_GetMonRecord are declared in the order the
 *    call passes them, so the first lands at sp+0x14 and the last at sp+8;
 *    declared the other way round every offset is mirrored and nothing else
 *    moves.  See docs/idioms/local-declaration-order-is-stack-order.md.
 *  - the byte of owner information is read as `add r0, sp, #8` /
 *    `ldrb r0, [r0, #0x12]` rather than off the OSOwnerInfo frame slot,
 *    because `sp + 8` is already a common subexpression: it is the fifth
 *    argument MISC_GetMonRecord took a few instructions earlier.
 */
void GDS_PROFILE_Init(struct GdsProfile *profile, void *sys)
{
    OSOwnerInfo info;
    u32 species;
    u32 form;
    u32 isEgg;
    u32 monGender;
    void *miscSave;
    void *saveData = GAME_DATA_GetSaveControl(sys);
    void *trainerRec = GAME_DATA_GetMyStatus(sys);
    void *recordEnv;
    s32 i;

    WIFI_HISTORY_GetBlock(saveData);
    miscSave = GAME_DATA_GetMiscSave(sys);
    recordEnv = GREETING_SAVEDATA_GetFromSaveThunk(saveData);
    OS_GetOwnerInfo(&info);
    MISC_GetMonRecord(miscSave, &species, &form, &isEgg, &monGender);

    MI_CpuFill8(profile, 0, sizeof(struct GdsProfile));
    WORDSET_CopyString(MYSTATUS_GetName(trainerRec), (u16 *)profile, 8);
    profile->trainerId = MYSTATUS_GetId(trainerRec);
    profile->gender = MYSTATUS_GetSex(trainerRec);
    profile->species = species;
    profile->mon.form = (u8)form;
    profile->mon.isEgg = (u8)isEgg;
    profile->mon.gender = (u8)monGender;
    profile->country = MYSTATUS_GetNation(trainerRec);
    profile->region = MYSTATUS_GetArea(trainerRec);
    for (i = 0; i < 0x28; i++) {
        profile->record[i] = STRBUF_GetEosChar();
    }
    GREETING_SAVEDATA_GetSentence((struct QuadRecord *)recordEnv, 0, (struct QuadRecord *)profile->record);
    profile->birthMonth = info.birthday.month;
    profile->trainerSprite = MYSTATUS_GetTrainerView(trainerRec);
    profile->gameVersion = PM_VERSION_ID;
    profile->language = 2;
    profile->checksum = GF_STANDARD_CalcCrc16((const u8 *)profile, 0x7C);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 28 bytes, 0x0200D6D0..0x0200D6EC, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "gds_profile.c"; see src/matched/unit_0200D59C.c for how the
 * name is attested and why the range in front of this one is cut here.
 *
 * A fifteen-byte copy into a freshly allocated block: the same
 * STRBUF_Create / STRBUF_SetStringN pair GDS_PROFILE_ExportRecord uses for the 0x28-byte
 * record.  The size is materialised twice, once as the allocation size and
 * once as the copy length, because both are caller-saved argument registers.
 */
void *GDS_PROFILE_CreateNameStr(const void *src, u32 tag)
{
    void *h = STRBUF_Create(0xF, (u16)tag);

    STRBUF_SetStringN(h, src, 0xF);
    return h;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           GDS_PROFILE_GetBadEggFlag
 *
 * 96 bytes, 0x0200D6EC..0x0200D74C, 5 functions, none of which carries a
 * label in the generated listing.
 *
 * Five validating getters on one record: a byte at +0x14, three bitfields
 * packed into the byte at +0x1B and a halfword at +0x1C.  Each one reads the
 * field and substitutes a safe value when it is out of range, and the shape
 * of the guard is what says how the source was written.
 *
 * GDS_PROFILE_GetEggFlag and GDS_PROFILE_GetNicknameFlag both test the value against 0 and then
 * against 1 with two `beq` to the same address, which is one `if` with `&&`
 * and not two statements; see
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md.
 * That the test survives at all in GDS_PROFILE_GetNicknameFlag is the interesting part: the
 * field there is one bit wide, so `v != 0 && v != 1` is provably false and
 * the compiler still emits both compares, which is the same reading as
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md.
 *
 * GDS_PROFILE_GetBadEggFlag clamps rather than zeroes, and the branch is `bls` over a
 * `movs r0, #1`, so its guard is `if (v > 1) v = 1;` and the fall-through arm
 * is the assignment.
 *
 * The bitfield widths are read off the shift pairs: `lsls #0x1F` / `lsrs
 * #0x1F` is bit 0, `lsls #0x18` / `lsrs #0x1F` is bit 7, and `lsls #0x19` /
 * `lsrs #0x1A` is the six bits between them, which is what GDS_PROFILE_GetFormSpecies
 * passes as the second argument of POKE_TOOL_FilterSpecies.
 */
u32 GDS_PROFILE_GetEggFlag(struct StoredMon *p)
{
    u32 v = p->isEgg;

    if (v != 0 && v != 1) {
        v = 0;
    }
    return v;
}

u32 GDS_PROFILE_GetSpecies(struct StoredMon *p)
{
    u32 v = p->species;

    if (v >= SPECIES_LAST + 2) {
        v = 0;
    }
    return v;
}

u32 GDS_PROFILE_GetFormSpecies(struct StoredMon *p)
{
    if (p->species >= SPECIES_LAST + 2) {
        return 0;
    }
    return POKE_TOOL_FilterSpecies(p->species, p->form);
}

u32 GDS_PROFILE_GetNicknameFlag(struct StoredMon *p)
{
    u32 v = p->isNicknamed;

    if (v != 0 && v != 1) {
        v = 0;
    }
    return v;
}

u32 GDS_PROFILE_GetBadEggFlag(struct StoredMon *p)
{
    u32 v = p->isBadEgg;

    if (v > 1) {
        v = 1;
    }
    return v;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           GDS_PROFILE_GetTrainerSprite, GDS_PROFILE_GetLanguage
 *
 * 268 bytes, 0x0200D74C..0x0200D858, 6 functions, three of which carry no
 * label in the generated listing.
 *
 * alias: the tail of "gds_profile.c"; the constructor at 0x0200D59C names
 * 0x020A71E8, see src/matched/unit_0200D59C.c.
 */
u32 GDS_PROFILE_GetValidatedCountry(struct GdsProfileRaw *p)
{
    return NATION_AREA_SanitizeNation(p->country, p->region, GDS_PROFILE_GetLanguage(p));
}

u32 GDS_PROFILE_GetValidatedRegion(struct GdsProfileRaw *p)
{
    return NATION_AREA_SanitizeArea(p->country, p->region, GDS_PROFILE_GetLanguage(p));
}

void *GDS_PROFILE_ExportRecord(struct GdsProfileRaw *p, struct GdsRecord *out, u32 tag)
{
    u32 a;
    u32 b;
    s32 n = 0;

    if (p->isRaw == 0) {
        out->word00 = p->record.word00;
        out->word02 = p->record.word02;
        out->word04 = p->record.word04;
        out->word06 = p->record.word06;
        if (out->word00 >= 5) {
            n++;
            goto chk;
        }
        if (out->word02 > 0x13) {
            n++;
            goto chk;
        }
        if ((out->word04 != 0xFFFF && PMS_WORD_SplitWordId(out->word04, &a, &b) == 0)
            || (out->word06 != 0xFFFF
                && PMS_WORD_SplitWordId(out->word06, &a, &b) == 0)) {
            n++;
        }
    chk:
        if (n > 0) {
            PMSI_PARAM_InitSentence((struct PmsData *)out, 4);
            out->word02 = 0;
            out->word04 = PMS_WORD_MakeWordId(0x95, 0x1D);
            out->word06 = 0xFFFF;
        }
        return 0;
    } else {
        void *h = STRBUF_Create(0x28, (u16)tag);

        STRBUF_SetStringN(h, (const u16 *)&p->record, sizeof(p->record));
        return h;
    }
}

u32 GDS_PROFILE_GetBirthMonth(struct GdsProfileRaw *p)
{
    u32 v = p->birthMonth;

    if (v < 1 || v > 0xC) {
        v = 1;
    }
    return v;
}

u32 GDS_PROFILE_GetTrainerSprite(struct GdsProfileRaw *p)
{
    u32 v = p->trainerSprite;

    if (v > 0xF) {
        v = 0;
    }
    return v;
}

u32 GDS_PROFILE_GetLanguage(struct GdsProfileRaw *p)
{
    u32 v = p->language;

    switch (v) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
        return v;
    }
    return 2;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           BSUBWAY_PLAYDATA_GetField, BSUBWAY_PLAYDATA_SetField, BSUBWAY_PLAYDATA_AddCounters, BSUBWAY_PLAYDATA_ClearRound,
 *           BSUBWAY_PLAYDATA_IncRound, BSUBWAY_PLAYDATA_GetRound
 *
 * 524 bytes, 0x0200D858..0x0200DA64, 10 functions, eight of which carry no
 * label in the generated listing.
 *
 * A 0x3C-byte record reached almost entirely through one pair of dispatchers.
 * BSUBWAY_PLAYDATA_GetSize returns 0x3C and BSUBWAY_PLAYDATA_Init clears exactly that many bytes
 * as a bare tail call, which is the block-file opening this region keeps
 * producing.
 *
 * The first halfword is seven bitfields and the widths come off the shift
 * pairs rather than a guess: `lsls #0x1A` / `lsrs #0x1C` is bits 2..5,
 * `lsls #0x17` / `lsrs #0x1D` is bits 6..8, and the three single-bit fields
 * at 0, 9 and 10 are `lsls #k` / `lsrs #0x1F`.  The setter arm for each is the
 * mirror image, and the three masks that need a literal pool word
 * (0xFFFFFE3F, 0xFFFFFDFF, 0xFFFFFBFF) are exactly the complements of those
 * fields, which is the independent check.
 *
 * Both dispatchers carry twelve dense case labels from zero and both tables
 * are complete, so no arm is a gap; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.  The three
 * arms that move a block of bytes return 0 like the default does, and the
 * default is reached by the `bhi` in the preamble, so there is one `return 0`
 * after the switch and not a `default:` label.
 *
 * BSUBWAY_PLAYDATA_SetFlag01 truncates its value to `u16` before extracting the bit, which
 * a `u16` parameter does not produce: the parameter is wider and the source
 * casts at the use, the same shape as BATTLE_BOX_SetLockFlags in
 * src/matched/unit_0200BBC8.c.
 *
 * BSUBWAY_PLAYDATA_AddCounters adds three deltas into three counters, each guarded against
 * its own type's maximum, and each sum is computed once and reused by both
 * the compare and the store; the two halfword guards share one literal pool
 * word holding 0xFFFF.
 *
 * BSUBWAY_PLAYDATA_IncRound reads the counter at id 1 through the getter, increments it
 * in a stack byte and writes it back through the setter, reloading the byte
 * after storing it because its address escapes into the setter call.
 */
u32 BSUBWAY_PLAYDATA_GetSize(void)
{
    return sizeof(struct BsubwayPlayData);
}

void BSUBWAY_PLAYDATA_Init(struct BsubwayPlayData *p)
{
    MI_CpuFill8(p, 0, sizeof(struct BsubwayPlayData));
}

void BSUBWAY_PLAYDATA_SetFlag01(struct BsubwayPlayData *p, u32 v)
{
    p->flag01 = (u16)v;
}

u32 BSUBWAY_PLAYDATA_GetFlag01(struct BsubwayPlayData *p)
{
    return p->flag01;
}

u32 BSUBWAY_PLAYDATA_GetField(struct BsubwayPlayData *p, u32 id, void *out)
{
    switch (id) {
    case 0:
        return p->value02;
    case 1:
        return p->round;
    case 2:
        return p->count03;
    case 3:
        return p->count04;
    case 4:
        return p->count06;
    case 5:
        MI_CpuCopy8(p->blob08, out, sizeof(p->blob08));
        return 0;
    case 6:
        MI_CpuCopy8(p->blob28, out, sizeof(p->blob28));
        return 0;
    case 7:
        return p->flag00;
    case 8:
        MI_CpuCopy8(p->blob0C, out, sizeof(p->blob0C));
        return 0;
    case 9:
        return p->value06;
    case 10:
        return p->flag09;
    case 11:
        return p->flag10;
    }
    return 0;
}

void BSUBWAY_PLAYDATA_SetField(struct BsubwayPlayData *p, u32 id, const void *src)
{
    switch (id) {
    case 0:
        p->value02 = *(const u8 *)src;
        break;
    case 1:
        p->round = *(const u8 *)src;
        break;
    case 2:
        p->count03 = *(const u8 *)src;
        break;
    case 3:
        p->count04 = *(const u16 *)src;
        break;
    case 4:
        p->count06 = *(const u16 *)src;
        break;
    case 5:
        MI_CpuCopy8(src, p->blob08, sizeof(p->blob08));
        break;
    case 6:
        MI_CpuCopy8(src, p->blob28, sizeof(p->blob28));
        break;
    case 7:
        p->flag00 = *(const u8 *)src;
        break;
    case 8:
        MI_CpuCopy8(src, p->blob0C, sizeof(p->blob0C));
        break;
    case 9:
        p->value06 = *(const u8 *)src;
        break;
    case 10:
        p->flag09 = *(const u8 *)src;
        break;
    case 11:
        p->flag10 = *(const u8 *)src;
        break;
    }
}

void BSUBWAY_PLAYDATA_AddCounters(struct BsubwayPlayData *p, s32 a, s32 b, s32 c)
{
    if (p->count03 + a < 255) {
        p->count03 = p->count03 + a;
    }
    if (p->count04 + b < 0xFFFF) {
        p->count04 = p->count04 + b;
    }
    if (p->count06 + c < 0xFFFF) {
        p->count06 = p->count06 + c;
    }
}

void BSUBWAY_PLAYDATA_ClearRound(struct BsubwayPlayData *p)
{
    u8 v = 0;

    BSUBWAY_PLAYDATA_SetField(p, 1, &v);
}

void BSUBWAY_PLAYDATA_IncRound(struct BsubwayPlayData *p)
{
    u8 v = BSUBWAY_PLAYDATA_GetField(p, 1, 0);

    if (v < 255) {
        v++;
    }
    BSUBWAY_PLAYDATA_SetField(p, 1, &v);
}

u16 BSUBWAY_PLAYDATA_GetRound(struct BsubwayPlayData *p)
{
    return BSUBWAY_PLAYDATA_GetField(p, 1, 0);
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           BSUBWAY_SCOREDATA_GetBattlePoints, BSUBWAY_SCOREDATA_MapPlayMode, BSUBWAY_SCOREDATA_GetWinCount, BSUBWAY_SCOREDATA_GetMaxWinCount,
 *           BSUBWAY_SCOREDATA_UpdateMaxWinCount, BSUBWAY_SCOREDATA_SetWinCount, BSUBWAY_SCOREDATA_ResetClearCount, BSUBWAY_SCOREDATA_SetFirstClear,
 *           BSUBWAY_SCOREDATA_HasCleared, BSUBWAY_SCOREDATA_IncClearCount, BSUBWAY_SCOREDATA_GetRepeatClearCount, BSUBWAY_SCOREDATA_AccessFlag,
 *           BSUBWAY_SCOREDATA_IncLevel, BSUBWAY_SCOREDATA_DecLevel, BSUBWAY_SCOREDATA_GetLevel, BSUBWAY_SCOREDATA_UpdateStreak,
 *           BSUBWAY_SCOREDATA_SetRecordBlob, BSUBWAY_SCOREDATA_GetRecordBlob, BSUBWAY_SCOREDATA_CalcRecordScore, BSUBWAY_SCOREDATA_GetRecordScore,
 *           BSUBWAY_SCOREDATA_GetRecordScoreTier
 *
 * 684 bytes, 0x0200DA64..0x0200DD10, 25 functions, eighteen of which carry no
 * label in the generated listing.
 *
 * A 0x1AC-byte save record of counters: one clamped total at +0x00, a streak
 * byte at +0x02, a level byte at +0x03 that the constructor seeds with 1, a
 * word of eleven flag bits at +0x04, three nine-entry `u16` arrays at +0x08,
 * +0x1A and +0x2C, a derived score at +0x3E, and two 0xB4-byte blobs at +0x44
 * and +0xF8.  The size getter and the constructor's `MI_CpuFill8(p, 0, 0x1AC)`
 * agree with 0xF8 + 0xB4, which is what pins the last field's length.
 *
 * Five things here are worth naming.
 *
 *  - BSUBWAY_SCOREDATA_MapPlayMode is `bx lr` and nothing else, and it is a function, not
 *    padding: eight of the accessors `bl` it with the index in r0 and use
 *    the result.  It is `u32 f(u32 i) { return i; }`, an id-to-slot mapping
 *    that was never filled in, and the calls to it are what make the three
 *    arrays indexed rather than direct.
 *  - BSUBWAY_SCOREDATA_AccessFlag takes a **signed** index, which the `blt` on the range
 *    check says and the `blo` inside the shift loop does not contradict: the
 *    loop counter is unsigned, so the comparison against it is unsigned too.
 *    Its switch bodies are emitted in the order 2, 1, 0, which is the order
 *    the source wrote them in; written 0, 1, 2 the case-2 body stops being
 *    the fall-through and the function grows a branch.
 *  - the mask is cleared with `~(u32)0 ^ mask`, not `~mask`: the original
 *    materialises the all-ones word with `movs r1, #0; mvns r1, r1` and then
 *    `eors`, which is two instructions where `mvns r1, r4` would have been
 *    one.
 *  - BSUBWAY_SCOREDATA_UpdateStreak's two arms both end in a call to BSUBWAY_SCOREDATA_AccessFlag followed
 *    by a store to +0x02, and the compiler cross-jumps them into one copy
 *    that each arm sets up its arguments for and branches to.  See
 *    docs/idioms/switch-arms-tail-merge.md.
 *  - in BSUBWAY_SCOREDATA_CalcRecordScore the two products are each truncated to `u16` and their
 *    sum is not.  Holding the sum in a `u16` adds a `lsls`/`lsrs` pair the
 *    original does not have, which is the whole of the difference between
 *    that function and EXACT.
 */
u32 BSUBWAY_SCOREDATA_GetSize(void)
{
    return sizeof(struct BsubwayScoreData);
}

void BSUBWAY_SCOREDATA_Init(struct BsubwayScoreData *p)
{
    MI_CpuFill8(p, 0, sizeof(struct BsubwayScoreData));
    p->level = 1;
}

void BSUBWAY_SCOREDATA_AddBattlePoints(struct BsubwayScoreData *p, s32 v)
{
    s32 n = p->battlePoints + v;

    if (n > 9999) {
        p->battlePoints = 9999;
    } else {
        p->battlePoints = n;
    }
}

void BSUBWAY_SCOREDATA_SubBattlePoints(struct BsubwayScoreData *p, u16 v)
{
    s16 n = (s16)p->battlePoints - (s16)v;

    if (n >= 0) {
        p->battlePoints = p->battlePoints - v;
    } else {
        p->battlePoints = 0;
    }
}

u16 BSUBWAY_SCOREDATA_GetBattlePoints(struct BsubwayScoreData *p)
{
    return p->battlePoints;
}

u32 BSUBWAY_SCOREDATA_MapPlayMode(u32 i)
{
    return i;
}

u16 BSUBWAY_SCOREDATA_GetWinCount(struct BsubwayScoreData *p, u32 i)
{
    return p->winCount[BSUBWAY_SCOREDATA_MapPlayMode(i)];
}

u16 BSUBWAY_SCOREDATA_GetMaxWinCount(struct BsubwayScoreData *p, u32 i)
{
    return p->maxWinCount[BSUBWAY_SCOREDATA_MapPlayMode(i)];
}

void BSUBWAY_SCOREDATA_UpdateMaxWinCount(struct BsubwayScoreData *p, u32 i, u16 v)
{
    u32 k = BSUBWAY_SCOREDATA_MapPlayMode(i);

    if (p->maxWinCount[k] < v) {
        p->maxWinCount[k] = v;
    }
}

void BSUBWAY_SCOREDATA_SetWinCount(struct BsubwayScoreData *p, u32 i, u16 v)
{
    p->winCount[BSUBWAY_SCOREDATA_MapPlayMode(i)] = v;
}

void BSUBWAY_SCOREDATA_ResetClearCount(struct BsubwayScoreData *p, u32 i)
{
    p->clearCount[BSUBWAY_SCOREDATA_MapPlayMode(i)] = 0;
}

void BSUBWAY_SCOREDATA_SetFirstClear(struct BsubwayScoreData *p, u32 i)
{
    p->clearCount[BSUBWAY_SCOREDATA_MapPlayMode(i)] = 1;
}

u32 BSUBWAY_SCOREDATA_HasCleared(struct BsubwayScoreData *p, u32 i)
{
    if (p->clearCount[BSUBWAY_SCOREDATA_MapPlayMode(i)] != 0) {
        return 1;
    }
    return 0;
}

void BSUBWAY_SCOREDATA_IncClearCount(struct BsubwayScoreData *p, u32 i)
{
    u32 k = BSUBWAY_SCOREDATA_MapPlayMode(i);

    if (p->clearCount[k] < 0xFFFE) {
        p->clearCount[k] = p->clearCount[k] + 1;
    }
}

u16 BSUBWAY_SCOREDATA_GetRepeatClearCount(struct BsubwayScoreData *p, u32 i)
{
    u16 n = p->clearCount[BSUBWAY_SCOREDATA_MapPlayMode(i)] - 1;

    if ((s16)n < 0) {
        n = 0;
    }
    return n;
}

u32 BSUBWAY_SCOREDATA_AccessFlag(struct BsubwayScoreData *p, s32 i, u32 op)
{
    u32 j;
    u32 mask = 1;

    if (i >= 11) {
        return 0;
    }
    for (j = 0; j < i; j++) {
        mask <<= 1;
    }
    switch (op) {
    case 2:
        p->flags &= ~(u32)0 ^ mask;
        break;
    case 1:
        p->flags |= mask;
        break;
    case 0:
        return (p->flags >> i) & 1;
    }
    return 0;
}

void BSUBWAY_SCOREDATA_IncLevel(struct BsubwayScoreData *p)
{
    if (p->level < 10) {
        p->level = p->level + 1;
    }
}

void BSUBWAY_SCOREDATA_DecLevel(struct BsubwayScoreData *p)
{
    if (p->level > 1) {
        p->level = p->level - 1;
    }
}

u8 BSUBWAY_SCOREDATA_GetLevel(struct BsubwayScoreData *p)
{
    return p->level;
}

u8 BSUBWAY_SCOREDATA_UpdateStreak(struct BsubwayScoreData *p, u32 kind)
{
    switch (kind) {
    case 2:
        BSUBWAY_SCOREDATA_AccessFlag(p, 0, 2);
        p->streak = 0;
        break;
    case 3:
        if (BSUBWAY_SCOREDATA_AccessFlag(p, 0, 0)) {
            if (p->streak < 0xFF) {
                p->streak = p->streak + 1;
            }
        } else {
            BSUBWAY_SCOREDATA_AccessFlag(p, 0, 1);
            p->streak = 1;
        }
        break;
    }
    return p->streak;
}

void BSUBWAY_SCOREDATA_SetRecordBlob(struct BsubwayScoreData *p, u32 which, const void *src)
{
    if (which == 0) {
        MI_CpuCopy8(src, p->blobF8, sizeof(p->blobF8));
    } else {
        MI_CpuCopy8(src, p->blob44, sizeof(p->blob44));
    }
}

void BSUBWAY_SCOREDATA_GetRecordBlob(struct BsubwayScoreData *p, u32 which, void *dest)
{
    if (which == 0) {
        MI_CpuCopy8(p->blobF8, dest, sizeof(p->blobF8));
    } else {
        MI_CpuCopy8(p->blob44, dest, sizeof(p->blob44));
    }
}

void BSUBWAY_SCOREDATA_CalcRecordScore(struct BsubwayScoreData *p, const struct GdsScoreSrc *q)
{
    u16 a;
    u16 c;
    u16 d;
    s32 t;

    a = (q->rank - 1) * 1000;
    t = (u16)(q->turns * 10) + (u16)(q->bonusA * 20);
    if (t > 950) {
        c = 0;
    } else {
        c = 950 - t;
    }
    if (q->hp > 970) {
        d = 0;
    } else {
        d = (1000 - q->hp) / 30;
    }
    p->score = a + c + d;
}

u16 BSUBWAY_SCOREDATA_GetRecordScore(struct BsubwayScoreData *p)
{
    return p->score;
}

u8 BSUBWAY_SCOREDATA_GetRecordScoreTier(struct BsubwayScoreData *p)
{
    return p->score / 1000;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 24 bytes, 0x0200DD10..0x0200DD28, the size getter and the constructor of
 * the save block this file belongs to: 0xB90 bytes, of which the first four
 * are a packed stamp and the next 250 are a bitmap of 2000 bits.  Neither
 * function carries a label in the generated listing.
 *
 * Near miss, and the reason this unit stops at 0x0200DD28: BSUBWAY_WIFIDATA_SetTrainerBit,
 * 104 bytes, which sets one bit of that bitmap and then packs four bytes
 * into the stamp word.  It is
 *
 *     void BSUBWAY_WIFIDATA_SetTrainerBit(struct BsubwayWifiData *p, u32 a, u32 b,
 *                        const struct Stamp *q)
 *     {
 *         u16 idx;
 *         u8 sh;
 *
 *         if (b == 0 || b > 200 || a == 0 || a > 10) {
 *             return;
 *         }
 *         idx = (a - 1) * 200 + (b - 1);
 *         sh = idx % 8;
 *         p->bitmap[(u8)(idx / 8)] |= (u8)(1 << sh);
 *         p->stamp = (q->time0 << 24) | ((q->time1 << 24) >> 8)
 *                  | ((q->time2 << 24) >> 16) | q->tag;
 *     }
 *
 * and that reproduces the size to the byte and every instruction, in the
 * same order bar one, with a different register assignment throughout.  The
 * original keeps the block pointer in r0 and moves the stamp pointer out of
 * r3 into r4, saving three registers; this source moves both, saves four,
 * and schedules the `lsls #0x15` that forms the byte index twenty-two bytes
 * early, which is the one live value that costs it r7.  Sixteen spellings
 * were tried: the modulo and the division as `%`/`/` and as shifts, the
 * byte index as a `u8` cast, an `& 0xFF` and a named `u8` local, the bit as
 * a named local and at the use, the guard positive and negative, the two
 * statements in both orders, the stamp as a struct pointer and as a `u32 *`,
 * and `const` on either pointer.  Every one of them produces the same 104
 * bytes with the same allocation, so the shift-amount truncation and the
 * cast at the use (docs/idioms, MUSICAL_SAVE_AddProp) are already right and what is
 * left is not reachable from the source shape.  Forty bytes differ and every
 * one of them is a register number.
 */
u32 BSUBWAY_WIFIDATA_GetSize(void)
{
    return sizeof(struct BsubwayWifiData);
}

void BSUBWAY_WIFIDATA_Init(struct BsubwayWifiData *p)
{
    MI_CpuFill8(p, 0, sizeof(struct BsubwayWifiData));
}

/*
 * 100 bytes (0x0200DD28..0x0200DD8C). Sets one bit of the 2000-bit bitmap of
 * the 0xB90 save block (unit_0200DD10.c) and packs four bytes into its stamp.
 * The u8 mask initialised to 1 at the top gives the early `movs r3,#1`.
 */
void BSUBWAY_WIFIDATA_SetTrainerBit(u8 *p, u8 a, u8 b, u32 *q) {
    u8 mask = 1;
    u16 idx;
    if (b == 0 || b > 200 || a == 0 || a > 10) {
        return;
    }
    idx = (b - 1) + (a - 1) * 200;
    mask <<= (u8)(idx % 8);
    (p + 4)[(u8)(idx / 8)] |= mask;
    *(u32 *)p = (q[0] << 24) | ((q[1] << 24) >> 8) | ((q[2] << 24) >> 16) | q[3];
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * 208 bytes, 0x0200DD8C..0x0200DE5C.  This file is the merge the wave 4A
 * report asked for: BSUBWAY_WIFIDATA_ClearStampAndBitmap and BSUBWAY_WIFIDATA_IsStampNewer are each called from
 * exactly one instruction in the image, both inside BSUBWAY_WIFIDATA_GetTrainerBit, so as
 * separate files the caller could never attest them.  In one unit both
 * call sites are local and the whole range is EXACT.  See the header of
 * src/matched/unit_0200DD10.c for why the range starts at 0x0200DD8C.
 *
 * BSUBWAY_WIFIDATA_ClearStampAndBitmap clears the 250-byte bitmap and then the four-byte stamp, in
 * that order and as two separate calls: the second one's size is four, not
 * the 254 a single call would have used, so the two fields are cleared
 * independently even though they are adjacent.
 *
 * BSUBWAY_WIFIDATA_IsStampNewer compares the first three words of two stamps and answers
 * whether the first is greater, with an early return per word rather than a
 * combined expression.  The fourth word is not compared, which is what makes
 * the stamp's last field a tag rather than part of the ordering.
 *
 * BSUBWAY_WIFIDATA_GetTrainerBit is the query half of the 0xB90-byte block: it answers
 * whether the (a, b) pair has already been recorded and whether the stamp it
 * is asked about is newer than the stored one.  Four things pin the source:
 *  - the result local is initialised to 1 before the guard, and the bit
 *    mask is built off the register holding that 1 (see
 *    docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md);
 *  - the guard is one ||, not two statements (see
 *    docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md);
 *  - the stamp is unpacked into a local struct Stamp a byte at a time, big
 *    endian, stores in source order;
 *  - idx % 8 is the signed-modulo shift sequence with the shift amount
 *    truncated to u8 before the shift and the mask cast to u8 at the use
 *    (the MUSICAL_SAVE_AddProp shape), and the byte index is (u8)(idx / 8).
 */
void BSUBWAY_WIFIDATA_ClearStampAndBitmap(struct BsubwayWifiData *p)
{
    MI_CpuFill8(p->bitmap, 0, sizeof(p->bitmap));
    MI_CpuFill8(p, 0, sizeof(p->stamp));
}

u32 BSUBWAY_WIFIDATA_IsStampNewer(const struct Stamp *a, const struct Stamp *b)
{
    if (a->time0 > b->time0) {
        return 1;
    }
    if (a->time1 > b->time1) {
        return 1;
    }
    if (a->time2 > b->time2) {
        return 1;
    }
    return 0;
}

int BSUBWAY_WIFIDATA_GetTrainerBit(struct BsubwayWifiData *p, u8 a, u8 b, const struct Stamp *q)
{
    struct Stamp s;
    u16 idx;
    u8  sh;
    u32 r = 1;

    if (b > 200 || a > 10) {
        return 0;
    }
    s.time0 = (u8)(p->stamp >> 24);
    s.time1 = (u8)(p->stamp >> 16);
    s.time2 = (u8)(p->stamp >> 8);
    s.tag = (u8)p->stamp;
    if (BSUBWAY_WIFIDATA_IsStampNewer(q, &s) != 0) {
        BSUBWAY_WIFIDATA_ClearStampAndBitmap(p);
        return 0;
    }
    idx = (a - 1) * 200 + (b - 1);
    sh = idx % 8;
    if (!(p->bitmap[(u8)(idx / 8)] & (u8)(1 << sh))) {
        r = 0;
    }
    return r;
}
