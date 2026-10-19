/*
 * file:     poke_tool.c
 * unit:     yes
 * function: POKE_TOOL_InitSystem, POKE_TOOL_GetBoxParamSize, POKE_TOOL_GetPartyParamSize, POKE_TOOL_Create, POKE_TOOL_CreateEx, POKE_TOOL_CreateFromBoxParam, POKE_TOOL_ClearPartyParam, POKE_TOOL_ClearBoxParam, POKE_TOOL_SetupPartyParam, POKE_TOOL_SetupPartyParamEx, POKE_TOOL_SetupBoxParam, POKE_TOOL_SetupBoxParamEx, POKE_TOOL_ChangeSpecies, POKE_TOOL_ChangeBoxSpecies, POKE_TOOL_ChangeForm, POKE_TOOL_ChangeBoxForm, POKE_TOOL_SetRotomFormMove, POKE_TOOL_HatchEgg, POKE_TOOL_HatchBoxEgg, POKE_TOOL_DeleteMoveSlot, POKE_TOOL_UpdateAbilityForSpecies, POKE_TOOL_UpdateGenderForSpecies, POKE_TOOL_DecodePartyParam, POKE_TOOL_EncodePartyParam, POKE_TOOL_DecodeBoxParam, POKE_TOOL_EncodeBoxParam, POKE_TOOL_GetPartyValue, POKE_TOOL_SetPartyValue, POKE_TOOL_SetBoxValue, POKE_TOOL_GetBoxValue, POKE_TOOL_IsShiny, POKE_TOOL_IsBoxShiny, POKE_TOOL_IsShinyOtIdPersonality, POKE_TOOL_GetGender, POKE_TOOL_GetBoxGender, POKE_TOOL_CalcGender, POKE_TOOL_GetStatusCondition, POKE_TOOL_SetStatusCondition, POKE_TOOL_SetBoxDefaultMoves, POKE_TOOL_AddMove, POKE_TOOL_AddBoxMove, POKE_TOOL_PushMove, POKE_TOOL_PushBoxMove, POKE_TOOL_RecoverAllPP, POKE_TOOL_RecoverBoxAllPP, POKE_TOOL_SetMoveSlot, POKE_TOOL_SetBoxMoveSlot, POKE_TOOL_FindMoveSlot, POKE_TOOL_FindBoxMoveSlot, POKE_TOOL_ReplaceMoveSlot, POKE_TOOL_ReplaceBoxMoveSlot, POKE_TOOL_LearnLevelUpMove, POKE_TOOL_CalcLevel, POKE_TOOL_CalcBoxLevel, POKE_TOOL_IsOwnedByPlayer, POKE_TOOL_IsBoxOwnedByPlayer, POKE_TOOL_CalcLevelFromExp, POKE_TOOL_GetLevelMinExp, POKE_TOOL_GetBoxLevelMinExp, POKE_TOOL_GetExpForLevel, POKE_TOOL_GetNature, POKE_TOOL_GetBoxNature, POKE_TOOL_SetNature, POKE_TOOL_RecalcParam, POKE_TOOL_Dummy, POKE_TOOL_GetBoxParam, POKE_TOOL_GetGenderRatioClass, POKE_TOOL_AdjustPersonalRnd, POKE_TOOL_CreatePersonalRnd, POKE_TOOL_GetHiddenPowerType, POKE_TOOL_GetHiddenPowerPower, POKE_TOOL_CheckTmCompat, POKE_TOOL_CheckBoxTmCompat, POKE_TOOL_CheckSpeciesTmCompat, POKE_TOOL_CheckTutorCompat, POKE_TOOL_CheckSpeciesTutorCompat, POKE_TOOL_GetNatureStatMod, POKE_TOOL_GetBoxNatureStatMod, POKE_TOOL_GetNatureStatModByNature, POKE_TOOL_SetAbility, POKE_TOOL_SetBoxAbility, POKE_TOOL_CalcParam, POKE_TOOL_DecodeCalcBlock, POKE_TOOL_DecodeBoxBlock, POKE_TOOL_EncodeCalcBlock, POKE_TOOL_EncodeBoxBlock, POKE_TOOL_GetPartyValueRaw, POKE_TOOL_GetBoxValueRaw, POKE_TOOL_SetPartyValueRaw, POKE_TOOL_SetBoxValueRaw
 * address:  0x020173D0
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
 *   GFL_HEAP_Alloc     0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   gPersonalCache      0x02146270  data
 *   sPokeToolFile  0x020A72E4  data
 *   MAIL_Create  0x02008F08  thumb
 *   POKE_CRYPTO_XorBlock  0x02019A50  thumb
 *   POKE_TOOL_GetPersonalData  0x02019C54  thumb
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_TOOL_GetPersonalGender  0x02019C7C  thumb
 *   gDefaultLanguage      0x0209DF0C  data  a1
 *   gSpeciesNameBank       0x020A7370  data
 *   gNameBuf       0x021462F0  data
 *   gGameVersion      0x0209DF08  data  a1
 *   sRotomFormMoves       0x0209E298  data  a2
 *   SAVE_EVENT_WriteMode  0x0202F1B4  thumb
 *   POKE_PERSONAL_IsPlaceholderAbility  0x0201AF6C  thumb
 *   POKE_CRYPTO_Checksum  0x02019A9C  thumb
 *   POKE_PERSONAL_LoadDataDirect  0x0201ADD0  thumb
 *   gLevelUpMoveBuf      0x02146330  data
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   WAZA_TOOL_GetMaxPP  0x0201C158  thumb
 *   gNameCompareBuf  0x021462B0  data
 *   gExpTableBuf  0x02146398  data
 *   POKE_TOOL_GetExpValue  0x02019BA4  thumb
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   sHiddenPowerTypes  0x0209E288  data
 *   POKE_TOOL_GetBoxSubstruct        0x02019C38  thumb
 *   sNatureStatMods   0x0209E2A4  data  a1
 *   MAIL_Copy   0x02008F3C  thumb
 *   POKE_TOOL_GetPlateType  0x02019BBC  thumb
 *   STRBUF_ToChars  0x02045A38  arm
 *   POKE_PERSONAL_OpenHandle  0x0201AD88  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   WORDSET_CheckF448  0x0201F448  thumb
 *   POKE_TOOL_IsDefaultName  0x02019ABC  thumb
 *   POKE_TOOL_ApplyNatureModifier  0x02019B04  thumb
 *   POKE_TOOL_LoadExpTable  0x02019B94  thumb
 *   WORDSET_CopyString  0x0201F41C  thumb
 *   MYSTATUS_CopyNameChars  0x020084F8  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned long long u64;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

/* Which block of the personality-shuffled box area to fetch. */
enum {
    POKE_TOOL_BLOCK_A,
    POKE_TOOL_BLOCK_B,
    POKE_TOOL_BLOCK_C,
    POKE_TOOL_BLOCK_D
};

/* Parameter ids of the get/set switch below (the selector of
 * POKE_TOOL_GetPartyValue and the other accessors). */
enum PokeToolParam {
    POKE_TOOL_PARAM_PERSONALITY = 0x00,
    POKE_TOOL_PARAM_PARTY_DECODED = 0x01,
    POKE_TOOL_PARAM_BOX_DECODED = 0x02,
    POKE_TOOL_PARAM_CHECKSUM_FAILED = 0x03,
    POKE_TOOL_PARAM_CHECKSUM = 0x04,
    POKE_TOOL_PARAM_SPECIES = 0x05,
    POKE_TOOL_PARAM_HELD_ITEM = 0x06,
    POKE_TOOL_PARAM_OT_ID = 0x07,
    POKE_TOOL_PARAM_EXP = 0x08,
    POKE_TOOL_PARAM_FRIENDSHIP = 0x09,
    POKE_TOOL_PARAM_ABILITY = 0x0A,
    POKE_TOOL_PARAM_MARKINGS = 0x0B,
    POKE_TOOL_PARAM_LANGUAGE = 0x0C,
    POKE_TOOL_PARAM_EV_HP = 0x0D,
    POKE_TOOL_PARAM_EV_ATTACK = 0x0E,
    POKE_TOOL_PARAM_EV_DEFENSE = 0x0F,
    POKE_TOOL_PARAM_EV_SPEED = 0x10,
    POKE_TOOL_PARAM_EV_SP_ATTACK = 0x11,
    POKE_TOOL_PARAM_EV_SP_DEFENSE = 0x12,
    POKE_TOOL_PARAM_CONTEST_COOL = 0x13,
    POKE_TOOL_PARAM_CONTEST_BEAUTY = 0x14,
    POKE_TOOL_PARAM_CONTEST_CUTE = 0x15,
    POKE_TOOL_PARAM_CONTEST_SMART = 0x16,
    POKE_TOOL_PARAM_CONTEST_TOUGH = 0x17,
    POKE_TOOL_PARAM_CONTEST_SHEEN = 0x18,
    POKE_TOOL_PARAM_RIBBON_SINNOH_CHAMPION = 0x19,
    POKE_TOOL_PARAM_RIBBON_SINNOH_ABILITY = 0x1A,
    POKE_TOOL_PARAM_RIBBON_SINNOH_GREAT_ABILITY = 0x1B,
    POKE_TOOL_PARAM_RIBBON_SINNOH_DOUBLE_ABILITY = 0x1C,
    POKE_TOOL_PARAM_RIBBON_SINNOH_MULTI_ABILITY = 0x1D,
    POKE_TOOL_PARAM_RIBBON_SINNOH_PAIR_ABILITY = 0x1E,
    POKE_TOOL_PARAM_RIBBON_SINNOH_WORLD_ABILITY = 0x1F,
    POKE_TOOL_PARAM_RIBBON_SINNOH_ALERT = 0x20,
    POKE_TOOL_PARAM_RIBBON_SINNOH_SHOCK = 0x21,
    POKE_TOOL_PARAM_RIBBON_SINNOH_DOWNCAST = 0x22,
    POKE_TOOL_PARAM_RIBBON_SINNOH_CAREFUL = 0x23,
    POKE_TOOL_PARAM_RIBBON_SINNOH_RELAX = 0x24,
    POKE_TOOL_PARAM_RIBBON_SINNOH_SNOOZE = 0x25,
    POKE_TOOL_PARAM_RIBBON_SINNOH_SMILE = 0x26,
    POKE_TOOL_PARAM_RIBBON_SINNOH_GORGEOUS = 0x27,
    POKE_TOOL_PARAM_RIBBON_SINNOH_ROYAL = 0x28,
    POKE_TOOL_PARAM_RIBBON_SINNOH_GORGEOUS_ROYAL = 0x29,
    POKE_TOOL_PARAM_RIBBON_SINNOH_ARTIST = 0x2A,
    POKE_TOOL_PARAM_RIBBON_SINNOH_FOOTPRINT = 0x2B,
    POKE_TOOL_PARAM_RIBBON_SINNOH_RECORD = 0x2C,
    POKE_TOOL_PARAM_RIBBON_SINNOH_HISTORY = 0x2D,
    POKE_TOOL_PARAM_RIBBON_SINNOH_LEGEND = 0x2E,
    POKE_TOOL_PARAM_RIBBON_SINNOH_RED = 0x2F,
    POKE_TOOL_PARAM_RIBBON_SINNOH_GREEN = 0x30,
    POKE_TOOL_PARAM_RIBBON_SINNOH_BLUE = 0x31,
    POKE_TOOL_PARAM_RIBBON_SINNOH_FESTIVAL = 0x32,
    POKE_TOOL_PARAM_RIBBON_SINNOH_CARNIVAL = 0x33,
    POKE_TOOL_PARAM_RIBBON_SINNOH_CLASSIC = 0x34,
    POKE_TOOL_PARAM_RIBBON_SINNOH_PREMIER = 0x35,
    POKE_TOOL_PARAM_MOVE1 = 0x36,
    POKE_TOOL_PARAM_MOVE2 = 0x37,
    POKE_TOOL_PARAM_MOVE3 = 0x38,
    POKE_TOOL_PARAM_MOVE4 = 0x39,
    POKE_TOOL_PARAM_PP1 = 0x3A,
    POKE_TOOL_PARAM_PP2 = 0x3B,
    POKE_TOOL_PARAM_PP3 = 0x3C,
    POKE_TOOL_PARAM_PP4 = 0x3D,
    POKE_TOOL_PARAM_PP_UP1 = 0x3E,
    POKE_TOOL_PARAM_PP_UP2 = 0x3F,
    POKE_TOOL_PARAM_PP_UP3 = 0x40,
    POKE_TOOL_PARAM_PP_UP4 = 0x41,
    POKE_TOOL_PARAM_MAX_PP1 = 0x42,
    POKE_TOOL_PARAM_MAX_PP2 = 0x43,
    POKE_TOOL_PARAM_MAX_PP3 = 0x44,
    POKE_TOOL_PARAM_MAX_PP4 = 0x45,
    POKE_TOOL_PARAM_IV_HP = 0x46,
    POKE_TOOL_PARAM_IV_ATTACK = 0x47,
    POKE_TOOL_PARAM_IV_DEFENSE = 0x48,
    POKE_TOOL_PARAM_IV_SPEED = 0x49,
    POKE_TOOL_PARAM_IV_SP_ATTACK = 0x4A,
    POKE_TOOL_PARAM_IV_SP_DEFENSE = 0x4B,
    POKE_TOOL_PARAM_IS_EGG = 0x4C,
    POKE_TOOL_PARAM_RIBBON_HOENN_COOL = 0x4D,
    POKE_TOOL_PARAM_RIBBON_HOENN_COOL_SUPER = 0x4E,
    POKE_TOOL_PARAM_RIBBON_HOENN_COOL_HYPER = 0x4F,
    POKE_TOOL_PARAM_RIBBON_HOENN_COOL_MASTER = 0x50,
    POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY = 0x51,
    POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY_SUPER = 0x52,
    POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY_HYPER = 0x53,
    POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY_MASTER = 0x54,
    POKE_TOOL_PARAM_RIBBON_HOENN_CUTE = 0x55,
    POKE_TOOL_PARAM_RIBBON_HOENN_CUTE_SUPER = 0x56,
    POKE_TOOL_PARAM_RIBBON_HOENN_CUTE_HYPER = 0x57,
    POKE_TOOL_PARAM_RIBBON_HOENN_CUTE_MASTER = 0x58,
    POKE_TOOL_PARAM_RIBBON_HOENN_SMART = 0x59,
    POKE_TOOL_PARAM_RIBBON_HOENN_SMART_SUPER = 0x5A,
    POKE_TOOL_PARAM_RIBBON_HOENN_SMART_HYPER = 0x5B,
    POKE_TOOL_PARAM_RIBBON_HOENN_SMART_MASTER = 0x5C,
    POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH = 0x5D,
    POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH_SUPER = 0x5E,
    POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH_HYPER = 0x5F,
    POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH_MASTER = 0x60,
    POKE_TOOL_PARAM_RIBBON_HOENN_CHAMPION = 0x61,
    POKE_TOOL_PARAM_RIBBON_HOENN_WINNING = 0x62,
    POKE_TOOL_PARAM_RIBBON_HOENN_VICTORY = 0x63,
    POKE_TOOL_PARAM_RIBBON_HOENN_ARTIST = 0x64,
    POKE_TOOL_PARAM_RIBBON_HOENN_EFFORT = 0x65,
    POKE_TOOL_PARAM_RIBBON_HOENN_MARINE = 0x66,
    POKE_TOOL_PARAM_RIBBON_HOENN_LAND = 0x67,
    POKE_TOOL_PARAM_RIBBON_HOENN_SKY = 0x68,
    POKE_TOOL_PARAM_RIBBON_HOENN_COUNTRY = 0x69,
    POKE_TOOL_PARAM_RIBBON_HOENN_NATIONAL = 0x6A,
    POKE_TOOL_PARAM_RIBBON_HOENN_EARTH = 0x6B,
    POKE_TOOL_PARAM_RIBBON_HOENN_WORLD = 0x6C,
    POKE_TOOL_PARAM_FATEFUL_ENCOUNTER = 0x6D,
    POKE_TOOL_PARAM_GENDER = 0x6E,
    POKE_TOOL_PARAM_FORM = 0x6F,
    POKE_TOOL_PARAM_NATURE = 0x70,
    POKE_TOOL_PARAM_HIDDEN_ABILITY = 0x71,
    POKE_TOOL_PARAM_SPARE_WORD = 0x72,
    POKE_TOOL_PARAM_NICKNAME_STRBUF = 0x73,
    POKE_TOOL_PARAM_NICKNAME = 0x74,
    POKE_TOOL_PARAM_HAS_NICKNAME = 0x75,
    POKE_TOOL_PARAM_SPARE_BYTE = 0x76,
    POKE_TOOL_PARAM_ORIGIN_GAME = 0x77,
    POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_NORMAL = 0x78,
    POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_GREAT = 0x79,
    POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_ULTRA = 0x7A,
    POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_MASTER = 0x7B,
    POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_NORMAL = 0x7C,
    POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_GREAT = 0x7D,
    POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_ULTRA = 0x7E,
    POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_MASTER = 0x7F,
    POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_NORMAL = 0x80,
    POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_GREAT = 0x81,
    POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_ULTRA = 0x82,
    POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_MASTER = 0x83,
    POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_NORMAL = 0x84,
    POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_GREAT = 0x85,
    POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_ULTRA = 0x86,
    POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_MASTER = 0x87,
    POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_NORMAL = 0x88,
    POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_GREAT = 0x89,
    POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_ULTRA = 0x8A,
    POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_MASTER = 0x8B,
    POKE_TOOL_PARAM_RIBBON_CONTEST_EXTRA = 0x8C,
    POKE_TOOL_PARAM_OT_NAME_STRBUF = 0x8D,
    POKE_TOOL_PARAM_OT_NAME = 0x8E,
    POKE_TOOL_PARAM_EGG_YEAR = 0x8F,
    POKE_TOOL_PARAM_EGG_MONTH = 0x90,
    POKE_TOOL_PARAM_EGG_DAY = 0x91,
    POKE_TOOL_PARAM_MET_YEAR = 0x92,
    POKE_TOOL_PARAM_MET_MONTH = 0x93,
    POKE_TOOL_PARAM_MET_DAY = 0x94,
    POKE_TOOL_PARAM_EGG_LOCATION = 0x95,
    POKE_TOOL_PARAM_MET_LOCATION = 0x96,
    POKE_TOOL_PARAM_POKERUS = 0x97,
    POKE_TOOL_PARAM_BALL = 0x98,
    POKE_TOOL_PARAM_MET_LEVEL = 0x99,
    POKE_TOOL_PARAM_OT_GENDER = 0x9A,
    POKE_TOOL_PARAM_ENCOUNTER_TYPE = 0x9B,
    POKE_TOOL_PARAM_BALL_EXTRA = 0x9C,
    POKE_TOOL_PARAM_STATUS_CONDITION = 0x9D,
    POKE_TOOL_PARAM_LEVEL = 0x9E,
    POKE_TOOL_PARAM_CAPSULE_INDEX = 0x9F,
    POKE_TOOL_PARAM_HP = 0xA0,
    POKE_TOOL_PARAM_MAX_HP = 0xA1,
    POKE_TOOL_PARAM_ATTACK = 0xA2,
    POKE_TOOL_PARAM_DEFENSE = 0xA3,
    POKE_TOOL_PARAM_SPEED = 0xA4,
    POKE_TOOL_PARAM_SP_ATTACK = 0xA5,
    POKE_TOOL_PARAM_SP_DEFENSE = 0xA6,
    POKE_TOOL_PARAM_MAIL = 0xA7,
    POKE_TOOL_PARAM_NO_DATA = 0xA8,
    POKE_TOOL_PARAM_SPECIES_EXISTS = 0xA9,
    POKE_TOOL_PARAM_IS_EGG_CHECKED = 0xAA,
    POKE_TOOL_PARAM_SPECIES_OR_EGG = 0xAB,
    POKE_TOOL_PARAM_PACKED_IVS = 0xAC,
    POKE_TOOL_PARAM_NICKNAME_NOT_DEFAULT_NIDORAN = 0xAD,
    POKE_TOOL_PARAM_TYPE1 = 0xAE,
    POKE_TOOL_PARAM_TYPE2 = 0xAF,
    POKE_TOOL_PARAM_NICKNAME_STRBUF_KEEP_FLAG = 0xB0,
    POKE_TOOL_PARAM_NICKNAME_KEEP_FLAG = 0xB1,
    POKE_TOOL_PARAM_RIBBON_SINNOH_FIRST = POKE_TOOL_PARAM_RIBBON_SINNOH_CHAMPION,
    POKE_TOOL_PARAM_RIBBON_HOENN_FIRST = POKE_TOOL_PARAM_RIBBON_HOENN_COOL,
    POKE_TOOL_PARAM_RIBBON_CONTEST_FIRST = POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_NORMAL
};

/* One entry of a species' level-up table; the table ends at 0xFFFF/0xFFFF. */
struct LevelUpMove {
    u16 move;
    u16 level;
};

/* The six moves Rotom may be forced to hold per form: slot 0 is empty. */
struct RotomFormMoves {
    u16 moves[6];
};

/* The leading part of the personal data of one species/form. */
struct PersonalData {
    u8 baseHp;
    u8 baseAttack;
    u8 baseDefense;
    u8 baseSpeed;
    u8 baseSpAttack;
    u8 baseSpDefense;
};

/* Cache of the last personal data record fetched (poke_regulation.c). */
struct PersonalCache {
    u16 form;
    u16 species;
    u8  data[0x10];
};

struct MsgData;
struct Strbuf;
struct MyStatus;
struct MailData;

#include "poke_tool_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *ptr);
extern void POKE_PERSONAL_OpenHandle(u32 heapId);
extern struct Mail *MAIL_Create(int heapId);
extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);
extern void POKE_CRYPTO_XorBlock(u16 *data, u32 size, u32 seed);
extern struct PersonalData *POKE_TOOL_GetPersonalData(u32 species, u16 form);
extern u32   GFL_USE_GetRandom(u32 range);
extern u32   GF_STANDARD_Rand(void);
extern void MSGDATA_ReadUnits(struct MsgData *msgData, u32 msgIndex, u16 *dest, u32 maxLen);
extern u32 POKE_PERSONAL_GetParam(const struct PersonalData *personal, u32 field);
extern u32   POKE_TOOL_GetPersonalGender(const struct PersonalData *personal);
extern void SAVE_EVENT_WriteMode(u32 box, u32 mode, u32 trainer, u32 location, u32 arg);
extern u32  POKE_PERSONAL_IsPlaceholderAbility(u32 genderRatio);
extern u16 POKE_CRYPTO_Checksum(const u16 *data, u32 size);
extern void POKE_PERSONAL_LoadDataDirect(u32 species, int form, struct LevelUpMove *dest);
extern u32 WAZA_TOOL_GetParam(u16 move, u32 field);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUps);
extern u32 MYSTATUS_GetId(const struct MyStatus *status);
extern u8 MYSTATUS_GetOutfitVariant(const struct MyStatus *status);
extern u32 MYSTATUS_CopyNameChars(struct MyStatus *status, u32 dest, u32 maxLen);
extern u32 WORDSET_CheckF448(const u16 *a, const u16 *b);
extern void  POKE_TOOL_LoadExpTable(u32 growthRate, u32 *dest);
extern u32 POKE_TOOL_GetExpValue(u32 growthRate, u32 level);
extern u32 POKE_TOOL_GetPersonalParam(u16 species, u16 form, u32 field);
extern void *POKE_TOOL_GetBoxSubstruct(struct BoxPokemon *box, u32 personality, u32 block);
extern u32  POKE_TOOL_ApplyNatureModifier(u32 nature, u32 stat, u32 statIndex);
extern void MAIL_Copy(const struct Mail *src, struct Mail *dest);
extern u32 POKE_TOOL_GetPlateType(u32 item);
extern void WORDSET_CopyString(const u16 *src, u16 *dest, u32 count);
extern void STRBUF_SetString(struct Strbuf *dest, const u16 *src);
extern void MSGDATA_ReadString(struct MsgData *bank, u32 index, struct Strbuf *dest);
extern u32  POKE_TOOL_IsDefaultName(struct BoxPokemon *box);
extern void STRBUF_ToChars(struct Strbuf *src, u16 *dest, u32 count);

extern const char sPokeToolFile[];
extern struct PersonalCache gPersonalCache;
extern u8 gDefaultLanguage;
extern u8 gGameVersion;
extern struct MsgData *gSpeciesNameBank;
extern u16 gNameBuf[];
extern u16 gNameCompareBuf[];
extern struct LevelUpMove gLevelUpMoveBuf[];
extern u32 gExpTableBuf[];
extern const struct RotomFormMoves sRotomFormMoves;
extern const u8 sHiddenPowerTypes[];
extern const s8 sNatureStatMods[][5];

void POKE_TOOL_InitSystem(u32 heapId);
u32 POKE_TOOL_GetBoxParamSize(void);
u32 POKE_TOOL_GetPartyParamSize(void);
struct PokemonParam *POKE_TOOL_Create(u16 species, u16 level, u64 otId, u16 heapId);
struct PokemonParam *POKE_TOOL_CreateEx(u16 species, u16 level, u64 otId, u32 ivs, u64 personality, u16 heapId);
struct PokemonParam *POKE_TOOL_CreateFromBoxParam(struct PokemonParam *src, u16 heapId);
void POKE_TOOL_ClearPartyParam(struct PokemonParam *pp);
void POKE_TOOL_ClearBoxParam(struct BoxPokemon *box);
void POKE_TOOL_SetupPartyParam(struct PokemonParam *pp, u16 species, u16 level, u64 otId);
void POKE_TOOL_SetupPartyParamEx(struct PokemonParam *pp, u16 species, u16 level, u64 otId, u32 ivs, u64 personality);
void POKE_TOOL_SetupBoxParam(struct BoxPokemon *box, u16 species, u16 level, u64 otId);
void POKE_TOOL_SetupBoxParamEx(struct BoxPokemon *box, u16 species, u16 level, u64 otId, u32 ivs, u64 personality);
void POKE_TOOL_ChangeSpecies(struct PokemonParam *pp, u32 species);
u32 POKE_TOOL_ChangeBoxSpecies(struct BoxPokemon *box, u32 newSpecies);
u32 POKE_TOOL_ChangeForm(struct PokemonParam *pp, u32 form);
int POKE_TOOL_ChangeBoxForm(struct BoxPokemon *box, int newForm);
u32 POKE_TOOL_SetRotomFormMove(struct PokemonParam *pp, u32 formIndex, u32 fallbackSlot);
void POKE_TOOL_HatchEgg(struct PokemonParam *pp, u32 trainer, u32 location, u32 arg);
u32 POKE_TOOL_HatchBoxEgg(struct BoxPokemon *box, u32 trainer, u32 location, u32 arg);
void POKE_TOOL_DeleteMoveSlot(struct PokemonParam *pp, u32 slot);
void POKE_TOOL_UpdateAbilityForSpecies(struct BoxPokemon *box, int newSpecies, int oldSpecies);
void POKE_TOOL_UpdateGenderForSpecies(struct BoxPokemon *box, u32 newSpecies, u32 oldSpecies);
u32 POKE_TOOL_DecodePartyParam(struct PokemonParam *pp);
u32 POKE_TOOL_EncodePartyParam(struct PokemonParam *pp, u32 didDecode);
u32 POKE_TOOL_DecodeBoxParam(struct BoxPokemon *box);
u32 POKE_TOOL_EncodeBoxParam(struct BoxPokemon *box, u32 didDecode);
u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);
void POKE_TOOL_SetPartyValue(struct PokemonParam *pp, u32 paramId, u32 value);
void POKE_TOOL_SetBoxValue(struct BoxPokemon *box, u32 paramId, u32 value);
u32 POKE_TOOL_GetBoxValue(struct BoxPokemon *box, u32 paramId, u32 arg);
u32 POKE_TOOL_IsShiny(struct PokemonParam *pp);
u32 POKE_TOOL_IsBoxShiny(struct BoxPokemon *box);
u32 POKE_TOOL_IsShinyOtIdPersonality(u32 otId, u32 personality);
u8 POKE_TOOL_GetGender(struct PokemonParam *pp);
u8 POKE_TOOL_GetBoxGender(struct BoxPokemon *box);
u8 POKE_TOOL_CalcGender(u32 species, u16 form, u32 personality);
u32 POKE_TOOL_GetStatusCondition(struct PokemonParam *pp);
void POKE_TOOL_SetStatusCondition(struct PokemonParam *pp, u32 statusCondition);
u32 POKE_TOOL_SetDefaultMoves(struct PokemonParam *pp);
u32 POKE_TOOL_SetBoxDefaultMoves(struct BoxPokemon *box);
u16 POKE_TOOL_AddMove(struct PokemonParam *pp, u16 move);
u16 POKE_TOOL_AddBoxMove(struct BoxPokemon *box, u16 move);
void POKE_TOOL_PushMove(struct PokemonParam *pp, u16 move);
void POKE_TOOL_PushBoxMove(struct BoxPokemon *box, u16 move);
void POKE_TOOL_RecoverAllPP(struct PokemonParam *pp);
void POKE_TOOL_RecoverBoxAllPP(struct BoxPokemon *box);
void POKE_TOOL_SetMoveSlot(struct PokemonParam *pp, u16 move, u32 slot);
void POKE_TOOL_SetBoxMoveSlot(struct BoxPokemon *box, u16 move, u32 slot);
u32 POKE_TOOL_FindMoveSlot(struct PokemonParam *pp, u16 move);
u32 POKE_TOOL_FindBoxMoveSlot(struct BoxPokemon *box, u16 move);
void POKE_TOOL_ReplaceMoveSlot(struct PokemonParam *pp, u16 move, u8 slot);
void POKE_TOOL_ReplaceBoxMoveSlot(struct BoxPokemon *box, u16 move, u8 slot);
u16 POKE_TOOL_LearnLevelUpMove(struct PokemonParam *pp, u32 *tableIndex, u32 heapId);
u32 POKE_TOOL_CalcLevel(struct PokemonParam *pp);
u32 POKE_TOOL_CalcBoxLevel(struct BoxPokemon *box);
int POKE_TOOL_IsOwnedByPlayer(struct PokemonParam *pp, struct MyStatus *myStatus);
u32 POKE_TOOL_IsBoxOwnedByPlayer(struct BoxPokemon *box, struct MyStatus *myStatus);
u32 POKE_TOOL_CalcLevelFromExp(u16 species, u16 form, u32 exp);
u32 POKE_TOOL_GetLevelMinExp(struct PokemonParam *pp);
u32 POKE_TOOL_GetBoxLevelMinExp(struct BoxPokemon *box);
u32 POKE_TOOL_GetExpForLevel(u16 species, u16 form, u16 level);
u8 POKE_TOOL_GetNature(struct PokemonParam *pp);
u8 POKE_TOOL_GetBoxNature(struct BoxPokemon *box);
void POKE_TOOL_SetNature(struct PokemonParam *pp, u32 nature);
void POKE_TOOL_RecalcParam(struct PokemonParam *pp);
void POKE_TOOL_Dummy(void);
struct BoxPokemon *POKE_TOOL_GetBoxParam(struct PokemonParam *pp);
u32 POKE_TOOL_GetGenderRatioClass(int species, u16 form, int ratioMode);
u32 POKE_TOOL_AdjustPersonalRnd(u32 otId, u16 species, u16 form, u8 ratioMode, u8 shinyWanted, int genderMode);
u32 POKE_TOOL_CreatePersonalRnd(u32 otId, int species, u16 form, int ratioMode, int shinyWanted, int mode);
u32 POKE_TOOL_GetHiddenPowerType(struct PokemonParam *pp);
u32 POKE_TOOL_GetHiddenPowerPower(struct PokemonParam *pp);
u32 POKE_TOOL_CheckTmCompat(struct PokemonParam *pp, int tmIndex);
u32 POKE_TOOL_CheckBoxTmCompat(struct BoxPokemon *box, s32 tmIndex);
u32 POKE_TOOL_CheckSpeciesTmCompat(u16 species, u16 form, s32 tmIndex);
u32 POKE_TOOL_CheckTutorCompat(struct PokemonParam *pp, s32 tutorIndex);
u32 POKE_TOOL_CheckSpeciesTutorCompat(u16 species, u16 form, s32 tutorIndex);
u32 POKE_TOOL_HasRibbonData(struct BoxPokemon *box);
int POKE_TOOL_GetNatureStatMod(struct BoxPokemon *box, int stat);
s8 POKE_TOOL_GetBoxNatureStatMod(struct BoxPokemon *box, u32 stat);
s8 POKE_TOOL_GetNatureStatModByNature(u8 nature, u32 stat);
void POKE_TOOL_SetAbility(struct BoxPokemon *box, u32 species, u32 form);
void POKE_TOOL_SetBoxAbility(struct BoxPokemon *box, u32 species, u32 form);
void POKE_TOOL_CalcParam(struct PokemonParam *pp);
u32 POKE_TOOL_DecodeCalcBlock(struct PokemonParam *pp);
u32 POKE_TOOL_DecodeBoxBlock(struct BoxPokemon *box);
void POKE_TOOL_EncodeCalcBlock(struct PokemonParam *pp);
void POKE_TOOL_EncodeBoxBlock(struct BoxPokemon *box);
u32 POKE_TOOL_GetPartyValueRaw(struct PokemonParam *pp, u32 paramId, u32 arg);
u32 POKE_TOOL_GetBoxValueRaw(struct BoxPokemon *box, u32 paramId, u32 arg);
void POKE_TOOL_SetPartyValueRaw(struct PokemonParam *pp, u32 paramId, u32 value);
void POKE_TOOL_SetBoxValueRaw(struct BoxPokemon *box, u32 paramId, u32 value);



void POKE_TOOL_InitSystem(u32 heapId)
{
    POKE_PERSONAL_OpenHandle(heapId);
    gPersonalCache.species = 0x28b;
}


/*
 * The two record sizes this region's files open with, `movs r0, #imm; bx lr`,
 * neither of them labelled in the generated listing because neither saves lr.
 * 0xDC is exactly what POKE_TOOL_ClearPartyParam in src/matched/unit_02017528.c clears and
 * 0x88 exactly what POKE_TOOL_ClearBoxParam clears, so the two constants and the struct
 * declaration check each other.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The three functions in front of them are parked in
 * src/pending/unit_020173B4.c.
 *
 * The original file name of the two constructors after them is recoverable
 * even though neither is matched yet: POKE_TOOL_Create and POKE_TOOL_CreateEx both
 * pass 0x020A72E4 to the debug allocator at 0x02030734, and the bytes there
 * spell "poke_tool.c".  Its left neighbours in the packed string area are
 * "d_status.c" at 0x020A72C0 and "mcss.c" at 0x020A72CC, and between "mcss.c"
 * and it sit four pointer words at 0x020A72D4, so the `string` class cannot
 * reach it (docs/idioms/a-string-after-a-data-table-has-no-witness.md).  The
 * `literal` class can: two pool words name it, 0x0201742C and 0x02017478, so
 * a range holding exactly one of the two constructors attests it.  Neither is
 * matched here because each is in turn the only caller of its worker.
 */
u32 POKE_TOOL_GetBoxParamSize(void)
{
    return 0x88;
}


u32 POKE_TOOL_GetPartyParamSize(void)
{
    return 0xDC;
}


/*
 * Allocate a record (0xA0 is the __LINE__ passed to GFL_HEAP_Alloc with the
 * poke_tool.c __FILE__ anchor) and initialise it through POKE_TOOL_SetupPartyParam.
 * Wave 11, 2026-09-23.  The "one remaining codegen wall" of
 * docs/families/poke_tool.h section 11 was a declaration error: the id is a
 * single u64 in r2:r3, not two u32s.  A u64 parameter gets a memory home at
 * entry and is reloaded at the call, which is exactly the str/ldr pair the
 * earlier passes could not force.
 */
struct PokemonParam *POKE_TOOL_Create(u16 species, u16 level, u64 otId, u16 heapId)
{
    struct PokemonParam *pp = GFL_HEAP_Alloc(heapId, POKE_TOOL_GetPartyParamSize(), 1, sPokeToolFile, 0xa0);
    if (pp != 0) {
        POKE_TOOL_SetupPartyParam(pp, species, level, otId);
    }
    return pp;
}


/*
 * Allocate a record (line 0xBA) and initialise it through POKE_TOOL_SetupPartyParamEx,
 * forwarding the u64 id, the packed IVs `pow` and the u64 personality
 * `rnd`; the heap id (u16, `ldrh`) is the LAST parameter, after rnd.
 * Wave 11, 2026-09-23: closed by the u64 id/rnd declarations (see
 * POKE_TOOL_Create.c).
 */
struct PokemonParam *POKE_TOOL_CreateEx(u16 species, u16 level, u64 otId, u32 ivs, u64 personality, u16 heapId)
{
    struct PokemonParam *pp = GFL_HEAP_Alloc(heapId, POKE_TOOL_GetPartyParamSize(), 1, sPokeToolFile, 0xba);
    if (pp != 0) {
        POKE_TOOL_SetupPartyParamEx(pp, species, level, otId, ivs, personality);
    }
    return pp;
}


/*
 * "Clone this Pokemon into a fresh allocation on heap `heap`."
 *
 * It takes the block lock (POKE_TOOL_DecodeBoxParam), reads species (id 0x05), level
 * (id 0x9E) and OT id (id 0x07) -- all three through the block-lock getter
 * POKE_TOOL_GetBoxValue, and species and level truncated to u16 at the assignment,
 * which is what the two `lsls #0x10 / lsrs #0x10` pairs at +0x18 and +0x26
 * are -- builds a fresh record with POKE_TOOL_Create(species, level, otId, 0,
 * heap), releases the lock, copies the WHOLE 0x88-word record over the fresh
 * one, then zeroes the three party-area ids the clone must not inherit
 * (0x9D, 0xA0 current HP, 0xA1 max HP), attaches a fresh mail block and
 * recomputes the stats.
 *
 * THE ONE LEVER, and the whole residue of the first draft:
 *
 *   THE RECORD COPY IS A STRUCT ASSIGNMENT, NOT A HAND-WRITTEN WORD LOOP.
 *
 * The original's copy is
 *
 *     020174C8  adds r3, r4, #0
 *     020174CA  movs r2, #0x11
 *     020174CC  ldm r5!, {r0, r1}
 *     020174CE  stm r3!, {r0, r1}
 *     020174D0  subs r2, r2, #1
 *     020174D2  bne #0x20174cc
 *
 * i.e. 0x11 iterations of an eight-byte ldm/stm pair, which is exactly
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md: above the unroll
 * threshold mwcc turns a whole-struct assignment into a counted ldm/stm loop
 * whose step is the struct's alignment.  Writing the same copy as an explicit
 * `d[0] = s[0]; d[1] = s[1]; s += 2; d += 2;` loop compiles to four separate
 * `ldr`/`str` plus two pointer bumps -- eight bytes longer and the whole tail
 * shifted (the first draft was 180 bytes against 172, with everything up to
 * +0x4C already byte-identical).  Only the aggregate assignment reaches it.
 *
 * The copy is 0x22 words = 0x88 bytes, NOT the record's full 0xDC: it copies
 * the plaintext header and the 0x80-byte masked block area and stops at the
 * party area, which is what the three explicit zeroes that follow then
 * rebuild.  That is why the copy is a `struct BoxPokemon` (0x88 bytes, 0x22 words) and not
 * the full PokemonParam -- the copied size IS the
 * evidence, since it is what sets the loop's trip count to 0x11.
 *
 * The heap tag handed to MAIL_Create is `(heap & 0x7fff) | 0x8000`: the pool
 * word at 0x02017524 is 0x00007FFF and the original derives the OR mask from
 * it with `adds r0, r0, #1` rather than pooling 0x8000 separately
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Nothing here is version specific: 0x05, 0x07, 0x9D, 0x9E, 0xA0, 0xA1 and
 * 0xA7 are all field selectors.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_CreateFromBoxParam.c \
 *       --func POKE_TOOL_CreateFromBoxParam --addr 0x0201747C --cc 1.1p1 --thumb
 */
struct PokemonParam *POKE_TOOL_CreateFromBoxParam(struct PokemonParam *src, u16 heapId)
{
    u32 didDecode = POKE_TOOL_DecodeBoxParam(&src->box);
    u16 species = (u16)POKE_TOOL_GetBoxValue(&src->box, POKE_TOOL_PARAM_SPECIES, 0);
    u16 level = (u16)POKE_TOOL_GetBoxValue(&src->box, POKE_TOOL_PARAM_LEVEL, 0);
    u32 otId = POKE_TOOL_GetBoxValue(&src->box, POKE_TOOL_PARAM_OT_ID, 0);
    struct PokemonParam *copy = POKE_TOOL_Create(species, level, otId, heapId);
    struct Mail *mail;

    POKE_TOOL_EncodeBoxParam(&src->box, didDecode);

    copy->box = src->box;

    POKE_TOOL_SetPartyValue(copy, POKE_TOOL_PARAM_STATUS_CONDITION, 0);
    POKE_TOOL_SetPartyValue(copy, POKE_TOOL_PARAM_HP, 0);
    POKE_TOOL_SetPartyValue(copy, POKE_TOOL_PARAM_MAX_HP, 0);
    mail = MAIL_Create((u16)((heapId & 0x7fff) | 0x8000));
    POKE_TOOL_SetPartyValue(copy, POKE_TOOL_PARAM_MAIL, (u32)mail);
    GFL_HEAP_Free(mail);
    POKE_TOOL_RecalcParam(copy);
    return copy;
}


/*
 * The two clears of the 0xDC byte record src/matched/unit_02017D30.c and
 * src/matched/unit_02018D10.c work on: POKE_TOOL_ClearPartyParam wipes the whole of it and
 * re-masks both areas, POKE_TOOL_ClearBoxParam wipes only the first 0x88 bytes and
 * re-masks the 0x80 byte one.  The masking calls are what say the record's
 * seed word and checksum halfword survive a clear in the caller's copy: the
 * value handed to POKE_CRYPTO_XorBlock is read back out of the object *after*
 * MIi_CpuClearFast has zeroed it, so both areas are masked with zero and the
 * call is the identity.
 *
 * The range stops at 0x0201756C.  That function and its twin at 0x02017600
 * are five argument entry points to eight argument workers, passing
 * 0xFFFFFFFF, 0 and 0xFFFFFFFF for the three arguments they do not take, and
 * neither reproduces: the original spends a third callee-saved register on
 * the incoming fifth argument and stores it into the outgoing frame last,
 * after all three constants, while every forwarding spelling tried loads it
 * first and reuses one register for it and for the zero.  Eighteen bytes, all
 * of them register numbers and store order.
 */
void POKE_TOOL_ClearPartyParam(struct PokemonParam *pp)
{
    MIi_CpuClearFast(0, pp, sizeof(struct PokemonParam));
    POKE_CRYPTO_XorBlock((u16 *)pp->box.blocks, 0x80, pp->box.checksum);
    POKE_CRYPTO_XorBlock((u16 *)&pp->statusCondition, 0x54, pp->box.personality);
}


void POKE_TOOL_ClearBoxParam(struct BoxPokemon *box)
{
    MIi_CpuClearFast(0, box, 0x88);
    POKE_CRYPTO_XorBlock((u16 *)box->blocks, 0x80, box->checksum);
}


/*
 * Forwarder: POKE_TOOL_SetupPartyParamEx(obj, species, level, id, 0xFFFFFFFF,
 * 0xFFFFFFFF00000000) -- random IVs, random personality.  Wave 11,
 * 2026-09-23: the u64 `id` straddles r3 and the first stack word; declaring
 * it u64 is the whole fix for the 18-byte prologue residue (push {r4,r5,r6}
 * and the late `ldr r6,[sp,#0x20]`).
 */
void POKE_TOOL_SetupPartyParam(struct PokemonParam *pp, u16 species, u16 level, u64 otId)
{
    POKE_TOOL_SetupPartyParamEx(pp, species, level, otId, 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
}


/*
 * Build a full party record: clear it (POKE_TOOL_ClearPartyParam), initialise the block
 * area (POKE_TOOL_SetupBoxParamEx), mask the party area with seed 0 then with the PID,
 * write the level (id 0x9E) through the party-lock setter, attach a fresh
 * mail block (tag 0x8000, id 0xA7, then freed), and refresh the stats
 * (POKE_TOOL_RecalcParam).  Wave 11, 2026-09-23.  EXACT* only because the listing
 * extent includes the two alignment bytes at 0x020175FE.
 */
void POKE_TOOL_SetupPartyParamEx(struct PokemonParam *pp, u16 species, u16 level, u64 otId, u32 ivs, u64 personality)
{
    struct Mail *mail;

    POKE_TOOL_ClearPartyParam(pp);
    POKE_TOOL_SetupBoxParamEx(&pp->box, species, level, otId, ivs, personality);
    POKE_CRYPTO_XorBlock((u16 *)&pp->statusCondition, 0x54, 0);
    POKE_CRYPTO_XorBlock((u16 *)&pp->statusCondition, 0x54, pp->box.personality);
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_LEVEL, level);
    mail = MAIL_Create(0x8000);
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_MAIL, (u32)mail);
    GFL_HEAP_Free(mail);
    POKE_TOOL_RecalcParam(pp);
}


/*
 * Forwarder: POKE_TOOL_SetupBoxParamEx(obj, species, level, id, 0xFFFFFFFF,
 * 0xFFFFFFFF00000000).  Twin of POKE_TOOL_SetupPartyParam; wave 11, 2026-09-23, closed
 * by the u64 `id` parameter.
 */
void POKE_TOOL_SetupBoxParam(struct BoxPokemon *box, u16 species, u16 level, u64 otId)
{
    POKE_TOOL_SetupBoxParamEx(box, species, level, otId, 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
}


/*
 * Initialise a record's block area: species, level, a 64-bit trainer id and
 * a 64-bit personality with two sentinel values each, and packed IVs (or
 * 0xFFFFFFFF for six fresh draws).  Wave 11, 2026-09-23.  The levers
 * that closed it after 2026-09-21's 612-against-700 DIFF:
 *   - the 4th parameter is a u64 `id` straddling r3 and the first stack
 *     word; the 7th is a u64 `rnd`.  Sentinels: id == ~0 (draw a fresh one),
 *     id == 0xFFFFFFFF00000000 (search for a non-shiny id: the
 *     POKE_TOOL_IsShinyOtIdPersonality retry loop, `id = (u32)(rnd + 1)` then
 *     `id = (id + 1) & 0xFFFFFFFF`); rnd == 0xFFFFFFFF00000000 (draw),
 *     rnd == 0xFFFFFFFF00000001 (take id).  Callers 0x0201756C/0x02017600
 *     pass pow = -1, rnd = 0xFFFFFFFF00000000.
 *   - the IV draws are `(u64)GF_STANDARD_Rand() * 32 >> 32`
 *     (docs/idioms/random-below-n-is-a-64-bit-multiply-high.md).
 *   - POKE_TOOL_ClearBoxParam takes `obj` (it is unit_02017528.c's area clear).  The
 *     last ten prologue bytes (r1 vs r0 as the scratch for the stack-param
 *     home rewrite) came from that alone: r0 must survive to the call.
 *     The permuter (hill 800 + anneal 1000, --types) could not move them.
 *     gNameBuf (passed by address), as docs/families/poke_tool.h says.
 */
void POKE_TOOL_SetupBoxParamEx(struct BoxPokemon *box, u16 species, u16 level, u64 otId, u32 ivs, u64 personality)
{
    struct PersonalData *personal;
    u32 didDecode;
    u32 abilitySlot;

    POKE_TOOL_ClearBoxParam(box);
    didDecode = POKE_TOOL_DecodeBoxParam(box);
    personal = POKE_TOOL_GetPersonalData(species, 0);

    if (personality == 0xFFFFFFFF00000000ULL) {
        personality = GFL_USE_GetRandom(0);
        GF_STANDARD_Rand();
    } else if (personality == 0xFFFFFFFF00000001ULL) {
        personality = otId;
    }
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_PERSONALITY, (u32)personality);

    if (otId == 0xFFFFFFFFFFFFFFFFULL) {
        otId = GFL_USE_GetRandom(0);
    } else if (otId == 0xFFFFFFFF00000000ULL) {
        otId = (u32)(personality + 1);
        while (POKE_TOOL_IsShinyOtIdPersonality((u32)otId, (u32)personality)) {
            otId = (otId + 1) & 0xFFFFFFFF;
        }
    }
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_OT_ID, (u32)otId);
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_LANGUAGE, gDefaultLanguage);
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_SPECIES, species);
    MSGDATA_ReadUnits(gSpeciesNameBank, species, gNameBuf, 0x20);
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_NICKNAME, (u32)gNameBuf);
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_EXP, POKE_TOOL_GetExpForLevel(species, 0, level));
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_FRIENDSHIP, POKE_PERSONAL_GetParam(personal, 0x16));
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_MET_LEVEL, level);
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_ORIGIN_GAME, gGameVersion);
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_BALL, 4);

    if (ivs == 0xFFFFFFFF) {
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_HP, (u32)(((u64)GF_STANDARD_Rand() * 32) >> 32));
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_ATTACK, (u32)(((u64)GF_STANDARD_Rand() * 32) >> 32));
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_DEFENSE, (u32)(((u64)GF_STANDARD_Rand() * 32) >> 32));
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_SP_ATTACK, (u32)(((u64)GF_STANDARD_Rand() * 32) >> 32));
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_SP_DEFENSE, (u32)(((u64)GF_STANDARD_Rand() * 32) >> 32));
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_SPEED, (u32)(((u64)GF_STANDARD_Rand() * 32) >> 32));
    } else {
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_HP, (u8)(ivs & 0x1f));
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_ATTACK, (u8)((ivs >> 5) & 0x1f));
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_DEFENSE, (u8)((ivs >> 10) & 0x1f));
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_SP_ATTACK, (u8)((ivs >> 15) & 0x1f));
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_SP_DEFENSE, (u8)((ivs >> 20) & 0x1f));
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IV_SPEED, (u8)((ivs >> 25) & 0x1f));
    }

    abilitySlot = 0x1a;
    if (POKE_TOOL_GetPersonalGender(personal) == 2 && (personality & 0x10000) != 0) {
        abilitySlot = 0x1b;
    }
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_ABILITY, POKE_PERSONAL_GetParam(personal, abilitySlot));
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_GENDER, POKE_TOOL_GetBoxGender(box));
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_NATURE, GFL_USE_GetRandom(0x19));
    POKE_TOOL_SetBoxDefaultMoves(box);
    POKE_TOOL_EncodeBoxParam(box, didDecode);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/pending/POKE_TOOL_ChangeSpecies.c \
 *       --func POKE_TOOL_ChangeSpecies --addr 0x020178D8 --cc 1.1p1 --thumb
 */
void POKE_TOOL_ChangeSpecies(struct PokemonParam *pp, u32 species)
{
    u8 didDecode = (u8)POKE_TOOL_DecodePartyParam(pp);

    POKE_TOOL_ChangeBoxSpecies(&pp->box, species);
    POKE_TOOL_RecalcParam(pp);
    POKE_TOOL_EncodePartyParam(pp, didDecode);
}


/*
 * poke_tool.c: "change this record's species to a1".  It takes the block
 * lock, reads the current species (id 5) and does nothing at all when it
 * already matches.  Otherwise it touches id 0x6F for its side effect, reads
 * the "nickname is not the default" bit (id 0x75), writes the new species,
 * refreshes the two derived type fields through POKE_TOOL_UpdateAbilityForSpecies and
 * POKE_TOOL_UpdateGenderForSpecies, and -- only when the nickname was still the default -- also
 * renders the new species' name into the shared buffer at 0x021462F0 and
 * stores it back as id 0x74.  Then it releases the lock.
 *
 * The id 0x75 guard is what makes this correct game behaviour: a record the
 * player has renamed keeps its nickname across a species change, and one that
 * never was renamed follows the species.  POKE_TOOL_IsDefaultName (unit_02019ABC.c) is
 * what sets that bit, and POKE_TOOL_GetBoxValueRaw reads it back as id 0x75.
 *
 * WHAT WAS WRONG IN THE EARLIER NOTE, AND WHAT CLOSED IT
 * -----------------------------------------------------
 * docs/notes/POKE_TOOL_ChangeBoxSpecies.diff.c.txt records this as a DIFF and its skeleton
 * is correct in every structural respect -- the guard, the nested 0x75 test,
 * the call order.  Only the extern declarations are wrong, and in exactly the
 * same way as its sibling src/matched/POKE_TOOL_HatchBoxEgg.c, which the same note
 * file pairs it with.
 *
 * The note declares the accessors narrow (`u8 POKE_TOOL_DecodeBoxParam`, `u16
 * POKE_TOOL_GetBoxValue`).  With the callee declared narrow the compiler emits no
 * truncation at all and then spills the live values to the frame.  The
 * original truncates at the ASSIGNMENT with a `lsls`/`lsrs` pair and keeps
 * both narrowed values in callee-saved registers.  That shape needs the
 * callee declared returning a full word and the LOCAL declared narrow, so the
 * cast belongs to the source rather than to the callee.  Declaring
 * POKE_TOOL_DecodeBoxParam and POKE_TOOL_GetBoxValue u32 and keeping `u8 v` / `u16 w` is the
 * entire fix; the body is the note's, unchanged.
 *
 * This is docs/families/poke_tool.h's adjudication rule: a truncation at the
 * call constrains the callee's width, a truncation at the assignment
 * constrains the local's.  Every other matched file in the family
 * (unit_02017E64.c, unit_0201854C.c, unit_02018430.c) already declares
 * POKE_TOOL_GetBoxValue returning u32, so the note's spelling was the outlier.
 *
 * The third argument of POKE_TOOL_SetBoxValue is a plain u32, not a `void *`: ids 5
 * and 0x74 take an integer and a buffer address respectively, and spelling
 * the parameter as a pointer is a claim the bytes do not make.
 *
 * Nothing here is version specific: 5, 0x6F, 0x74 and 0x75 are field
 * selectors and 0x20 is a halfword count.  gSpeciesNameBank and gNameBuf are
 * globals, so their addresses are build properties and must be re-derived
 * for a White build rather than copied.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_ChangeBoxSpecies.c \
 *       --func POKE_TOOL_ChangeBoxSpecies --addr 0x02017900 --cc 1.1p1 --thumb
 */
u32 POKE_TOOL_ChangeBoxSpecies(struct BoxPokemon *box, u32 newSpecies)
{
    u8  didDecode = (u8)POKE_TOOL_DecodeBoxParam(box);
    u16 oldSpecies = (u16)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_SPECIES, 0);

    if (oldSpecies != newSpecies) {
        u32 hasNickname;

        POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, 0);
        hasNickname = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_HAS_NICKNAME, 0);
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_SPECIES, newSpecies);
        POKE_TOOL_UpdateAbilityForSpecies(box, newSpecies, oldSpecies);
        POKE_TOOL_UpdateGenderForSpecies(box, newSpecies, oldSpecies);
        if (hasNickname == 0) {
            MSGDATA_ReadUnits(gSpeciesNameBank, newSpecies, gNameBuf, 0x20);
            POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_NICKNAME, (u32)gNameBuf);
        }
    }
    return POKE_TOOL_EncodeBoxParam(box, didDecode);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_ChangeForm.c \
 *       --func POKE_TOOL_ChangeForm --addr 0x02017988 --cc 1.1p1 --thumb
 */
u32 POKE_TOOL_ChangeForm(struct PokemonParam *pp, u32 form)
{
    u8 didDecode = (u8)POKE_TOOL_DecodePartyParam(pp);
    u32 changed = POKE_TOOL_ChangeBoxForm(&pp->box, form);

    if (changed == 1) {
        POKE_TOOL_RecalcParam(pp);
    }
    POKE_TOOL_EncodePartyParam(pp, didDecode);
    return changed;
}


/*
 * A "select and apply" pair, structurally the sibling of POKE_TOOL_ChangeBoxSpecies.
 * The value at selector 5 is compared against a1; when they already agree
 * nothing but the +0x18 restore happens.  Otherwise the old selection is read
 * back out of selector 0x6f into r4 (the local that was 0, which is why the
 * clearing write passes r4 and not a literal 0) and the new value is written
 * with selector 0x6f before the two geometry calls run with it.
 *
 * The `cmp` operand order is the tell: `(u16)POKE_TOOL_GetBoxValue(...)` only reaches
 * cmp's left slot because it was first bound to a named local (`t`), see
 * docs/idioms/cmp-operand-order-names-the-temporary.md.  Comparing the call
 * result directly emits `cmp a1, r0` and differs by one byte.
 *
 * EXACT*: the compared extent ran into the follower's four-byte pad, which is
 * identical in both objects.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_ChangeBoxForm.c \
 *       --func POKE_TOOL_ChangeBoxForm --addr 0x020179B8 --cc 1.1p1 --thumb
 */
int POKE_TOOL_ChangeBoxForm(struct BoxPokemon *box, int newForm)
{
    int changed = 0;
    int didDecode = (unsigned char)POKE_TOOL_DecodeBoxParam(box);
    int oldForm = (unsigned short)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, 0);

    if (oldForm != newForm) {
        POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, changed);
        changed = (unsigned short)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_SPECIES, changed);
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_FORM, newForm);
        POKE_TOOL_UpdateAbilityForSpecies(box, changed, changed);
        POKE_TOOL_UpdateGenderForSpecies(box, changed, changed);
        changed = 1;
    }
    POKE_TOOL_EncodeBoxParam(box, didDecode);
    return changed;
}


/*
 * Species check (id 5 == 0x1DF), then teach the move tbl[idx] from a
 * six-entry u16 table {0, 0x13B, 0x38, 0x3B, 0x193, 0x1B5} at 0x0209E298:
 * any slot already holding one of tbl[1..5] is overwritten (first hit) or
 * deleted (POKE_TOOL_DeleteMoveSlot, then the slot is re-examined), else the first
 * empty slot, else slot `val`; slot 0 empty gets move 0x54; finally
 * POKE_TOOL_ChangeForm(p, idx).  Wave 11, 2026-09-23.
 *
 * The straight-line six ldrh/strh copy with TWO `add rN, sp, #8` is a
 * 12-byte, 2-aligned aggregate copy scoped AFTER the guard: in the original
 * very likely a local initializer `u16 tbl[6] = {...}` inside a block (that
 * spelling is byte-identical but its anonymous rodata symbol cannot be named
 * in `symbols:`), written here as the equivalent struct copy from a named
 * extern so the relocation resolves (sole-ref).  Also load-bearing: `v` and
 * `val` are u32, so the (u16)/(u8) truncations land at the POKE_TOOL_SetMoveSlot
 * calls; `k` is unsigned (`blo`), `i` signed (`blt`); `r != 0 && r ==
 * tbl.v[k]` is the inner test.
 */
u32 POKE_TOOL_SetRotomFormMove(struct PokemonParam *pp, u32 formIndex, u32 fallbackSlot)
{
    u32 formMove;
    int slot;
    u32 i;

    if (POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_SPECIES, 0) != 0x1df)
        return 0;
    {
    struct RotomFormMoves formMoves = sRotomFormMoves;
    formMove = formMoves.moves[formIndex];
    for (slot = 0; slot < 4; slot++) {
        u32 move = POKE_TOOL_GetPartyValue(pp, slot + POKE_TOOL_PARAM_MOVE1, 0);

        for (i = 1; i < 6; i++) {
            if (move != 0 && move == formMoves.moves[i]) {
                if (formMove != 0) {
                    POKE_TOOL_SetMoveSlot(pp, formMove, (u8)slot);
                    formMove = 0;
                } else {
                    POKE_TOOL_DeleteMoveSlot(pp, slot);
                    slot--;
                }
                break;
            }
        }
    }
    }
    if (formMove != 0) {
        for (slot = 0; slot < 4; slot++) {
            if (POKE_TOOL_GetPartyValue(pp, slot + POKE_TOOL_PARAM_MOVE1, 0) == 0) {
                POKE_TOOL_SetMoveSlot(pp, formMove, (u8)slot);
                break;
            }
        }
        if (slot == 4)
            POKE_TOOL_SetMoveSlot(pp, formMove, (u8)fallbackSlot);
    }
    if (POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_MOVE1, 0) == 0)
        POKE_TOOL_SetMoveSlot(pp, 0x54, (u8)0);
    POKE_TOOL_ChangeForm(pp, (u16)formIndex);
    return 1;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/pending/POKE_TOOL_HatchEgg.c \
 *       --func POKE_TOOL_HatchEgg --addr 0x02017B24 --cc 1.1p1 --thumb
 */
void POKE_TOOL_HatchEgg(struct PokemonParam *pp, u32 trainer, u32 location, u32 arg)
{
    u8 didDecode = (u8)POKE_TOOL_DecodePartyParam(pp);

    POKE_TOOL_HatchBoxEgg(&pp->box, trainer, location, arg);
    POKE_TOOL_EncodePartyParam(pp, didDecode);
}


/*
 * poke_tool.c: the "reset this record to a fresh hatched state" writer.  It
 * takes the block lock, reads the species (id 5) and the form (id 0x6F, for
 * its side effect only -- the result is discarded, which is why the call is a
 * statement), clears the egg flag (id 0x4C), stores 0x78 into id 9, renders
 * the species name into the shared 0x20 halfword buffer at 0x021462F0 and
 * writes it back as the nickname (id 0x74), then hands the record and the
 * three caller arguments to SAVE_EVENT_WriteMode before releasing the lock.
 *
 * WHAT WAS WRONG IN THE EARLIER NOTE, AND WHAT CLOSED IT
 * -----------------------------------------------------
 * docs/notes/POKE_TOOL_HatchBoxEgg.diff.c.txt records this function as a 104-byte
 * DIFF at 120 bytes against 124, and that source is four bytes short with the
 * whole body misaligned.  The note's skeleton is correct; only two
 * declarations are wrong, and they are the whole difference.
 *
 * The note declares the two accessor externs as returning narrow types --
 * `u8 POKE_TOOL_DecodeBoxParam(box)` and `u16 POKE_TOOL_GetBoxValue(...)` -- and assigns their
 * results to same-width locals.  With the callee declared narrow the compiler
 * believes the value is already truncated, emits no shift pair, and then has
 * nothing cheap to keep the value in, so it spills BOTH to the frame
 * (`str r0, [sp, #4]` / `str r0, [sp, #8]`) and burns the two argument
 * registers r6 and r7 on a1 and a2 instead.
 *
 * The original does the opposite: it truncates at the ASSIGNMENT
 * (`lsls r0, r0, #0x18` / `lsrs r7, r0, #0x18` for the u8 and
 * `lsls r0, r0, #0x10` / `lsrs r6, r0, #0x10` for the u16) and keeps both
 * narrowed values live in r7 and r6, which frees the frame slots for a1 and
 * a2 (`str r1, [sp, #4]` / `str r2, [sp, #8]`).  That shape only compiles
 * when the CALLEE is declared to return a full word and the LOCAL is declared
 * narrow, so the cast is the source's own and not the callee's.  Declaring
 * both externs u32 and both locals u8/u16 is the entire fix; nothing else in
 * the note's body changed.
 *
 * This is the same adjudication rule docs/families/poke_tool.h states: a
 * truncation emitted at the call constrains the callee's parameter width,
 * while a truncation emitted at the assignment constrains the local's.  Here
 * it is the assignment, so the accessors stay u32 -- which also agrees with
 * every other matched file in the family (unit_02017E64.c, unit_0201854C.c,
 * unit_02018430.c all declare POKE_TOOL_GetBoxValue returning u32).
 *
 * The third argument of POKE_TOOL_SetBoxValue is a plain u32 and not a pointer: the
 * note spells it `void *` and passes `(void *)0x78`, which compiles the same
 * here but is a claim the bytes do not support, since id 9 is a byte field.
 *
 * Nothing here is version specific: 5, 9, 0x4C, 0x6F and 0x74 are field
 * selectors and 0x20 is a halfword count.  gSpeciesNameBank and gNameBuf are
 * globals, so their addresses are build properties.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_HatchBoxEgg.c \
 *       --func POKE_TOOL_HatchBoxEgg --addr 0x02017B4C --cc 1.1p1 --thumb
 */
u32 POKE_TOOL_HatchBoxEgg(struct BoxPokemon *box, u32 trainer, u32 location, u32 arg)
{
    u8  didDecode = (u8)POKE_TOOL_DecodeBoxParam(box);
    u16 species = (u16)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_SPECIES, 0);

    POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, 0);
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_IS_EGG, 0);
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_FRIENDSHIP, 0x78);
    MSGDATA_ReadUnits(gSpeciesNameBank, species, gNameBuf, 0x20);
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_NICKNAME, (u32)gNameBuf);
    SAVE_EVENT_WriteMode((u32)box, 2, trainer, location, arg);
    return POKE_TOOL_EncodeBoxParam(box, didDecode);
}


/*
 * Three "rows" of a dialog/UI record: for each row index below 3, read the
 * three fields at +0x37/+0x3B/+0x3F and write the copies back at
 * +0x36/+0x3A/+0x3E (the field before each), then clear the three
 * single-byte fields at 0x39/0x3D/0x41.
 *
 * The loop counter is the function's own second parameter -- there is no
 * initialiser, the entry test is `cmp r4, #3 / bhs` straight off the
 * argument, and the back edge is `cmp r4, #3 / blo`, so the source is
 * `for (; i < 3; i++)` over an unsigned i, not a local counter.
 *
 * The u16/u8 shift pairs are the destination widths of the three temporaries
 * (`lsls #16 / lsrs #16` versus `lsls #24 / lsrs #24` for a u8), which is
 * what fixes the return type of POKE_TOOL_GetPartyValue as wider than both.  The first
 * temporary is live across the other two reads and spills to the `push`
 * home area (`str r0, [sp]` / `ldr r2, [sp]`), which is why r3 is in the
 * push list without being read anywhere.
 *
 * EXACT*: the listing extent runs to 136 bytes because the follower at
 * 0x02017C50 saves no lr and carries no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_DeleteMoveSlot.c \
 *       --func POKE_TOOL_DeleteMoveSlot --addr 0x02017BC8 --cc 1.1p1 --thumb
 */
void POKE_TOOL_DeleteMoveSlot(struct PokemonParam *pp, u32 slot)
{
    for (; slot < 3; slot++) {
        u16 move = POKE_TOOL_GetPartyValue(pp, slot + POKE_TOOL_PARAM_MOVE2, 0);
        u8  curPp = POKE_TOOL_GetPartyValue(pp, slot + POKE_TOOL_PARAM_PP2, 0);
        u8  ppUps = POKE_TOOL_GetPartyValue(pp, slot + POKE_TOOL_PARAM_PP_UP2, 0);

        POKE_TOOL_SetPartyValue(pp, slot + POKE_TOOL_PARAM_MOVE1, move);
        POKE_TOOL_SetPartyValue(pp, slot + POKE_TOOL_PARAM_PP1, curPp);
        POKE_TOOL_SetPartyValue(pp, slot + POKE_TOOL_PARAM_PP_UP1, ppUps);
    }
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_MOVE4, 0);
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_PP4, 0);
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_PP_UP4, 0);
}


/*
 * Picks one of three record types and writes selector 0xa.  `mask` is a
 * bit test against the byte returned by selector 0, and which bit it is
 * depends on selector 0x77: below 0x14 the mask is bit 0, at or above it the
 * mask is bit 16.  The comparison against 0x14 is *unsigned* in the original
 * (`bhs`, not `bge`), so POKE_TOOL_GetBoxValue must be declared returning an unsigned
 * type - an `int` declaration emits `bge` and costs four bytes.
 *
 * Declaration order is load bearing: `r6` (the 0x1a/0x1b/0x1c selector) is
 * declared first and takes the higher register, `mask` second and takes the
 * lower one.  Reversing them keeps the same instruction count but swaps r4
 * and r6 in nine places.
 *
 * EXACT*: the extent runs into the follower's four-byte pad.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_UpdateAbilityForSpecies.c \
 *       --func POKE_TOOL_UpdateAbilityForSpecies --addr 0x02017C50 --cc 1.1p1 --thumb
 */
void POKE_TOOL_UpdateAbilityForSpecies(struct BoxPokemon *box, int newSpecies, int oldSpecies)
{
    struct PersonalData *personal = POKE_TOOL_GetPersonalData(newSpecies, (unsigned short)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, 0));
    int personality = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_PERSONALITY, 0);
    int abilitySlot = 0x1a;
    u32 mask = 1 << 16;

    if (POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_ORIGIN_GAME, 0) < 0x14) {
        mask = 1;
    }
    if (POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_HIDDEN_ABILITY, 0) != 0) {
        abilitySlot = 0x1c;
    } else if (POKE_TOOL_GetPersonalGender(personal) == 2 && (personality & mask) != 0) {
        abilitySlot = 0x1b;
    }
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_ABILITY, POKE_PERSONAL_GetParam(personal, abilitySlot));
}


/*
 * verdict:  EXACT* (match.py: compiled 102, listing extent 104).  The two
 *           trailing bytes at 0x02017D2E are `00 00` padding after the `pop`
 *           and the follower at 0x02017D30 carries no label, so the inferred
 *           extent runs two bytes long.  Never a byte difference; the follower
 *           is reported for the integrator rather than seeded here
 *           (layout/function_starts.txt is not this lane's file).
 */
void POKE_TOOL_UpdateGenderForSpecies(struct BoxPokemon *box, u32 newSpecies, u32 oldSpecies)
{
    u32 form = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, 0);
    u32 newRatio = POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(newSpecies, form), 0x14);
    u32 oldRatio = POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(oldSpecies, form), 0x14);

    if (POKE_PERSONAL_IsPlaceholderAbility(newRatio) == 1 && oldRatio != 0xff) {
        return;
    }
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_GENDER, POKE_TOOL_CalcGender(newSpecies, form, POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_PERSONALITY, 0)));
}


u32 POKE_TOOL_DecodePartyParam(struct PokemonParam *pp)
{
    u32 didDecode = 0;

    if (pp->box.partyDecoded == 0) {
        didDecode = 1;
        pp->box.partyDecoded = 1;
        pp->box.boxDecoded = 1;
        POKE_CRYPTO_XorBlock((u16 *)&pp->statusCondition, 0x54, pp->box.personality);
        POKE_CRYPTO_XorBlock((u16 *)pp->box.blocks, 0x80, pp->box.checksum);
    }
    return didDecode;
}


u32 POKE_TOOL_EncodePartyParam(struct PokemonParam *pp, u32 didDecode)
{
    u32 didEncode = 0;

    if (pp->box.partyDecoded == 1 && didDecode == 1) {
        pp->box.partyDecoded = 0;
        pp->box.boxDecoded = 0;
        didEncode = 1;
        POKE_CRYPTO_XorBlock((u16 *)&pp->statusCondition, 0x54, pp->box.personality);
        pp->box.checksum = POKE_CRYPTO_Checksum((const u16 *)pp->box.blocks, 0x80);
        POKE_CRYPTO_XorBlock((u16 *)pp->box.blocks, 0x80, pp->box.checksum);
    }
    return didEncode;
}


u32 POKE_TOOL_DecodeBoxParam(struct BoxPokemon *box)
{
    u32 didDecode = 0;

    if (box->boxDecoded == 0) {
        box->boxDecoded = 1;
        didDecode = 1;
        POKE_CRYPTO_XorBlock((u16 *)box->blocks, 0x80, box->checksum);
    }
    return didDecode;
}


u32 POKE_TOOL_EncodeBoxParam(struct BoxPokemon *box, u32 didDecode)
{
    u32 didEncode = 0;

    if (box->boxDecoded == 1 && didDecode == 1) {
        didEncode = 1;
        box->boxDecoded = 0;
        box->checksum = POKE_CRYPTO_Checksum((const u16 *)box->blocks, 0x80);
        POKE_CRYPTO_XorBlock((u16 *)box->blocks, 0x80, box->checksum);
    }
    return didEncode;
}


/*
 * 0x02017E1C..0x02017E40, 36 bytes, one function.
 *
 * The read wrapper for the party area of the 0xDC byte record: unlock, call
 * the party-area dispatcher POKE_TOOL_GetPartyValueRaw (src/matched/POKE_TOOL_GetPartyValueRaw.c), lock
 * again and return its result.  It is the exact counterpart of POKE_TOOL_GetBoxValue
 * in src/matched/unit_02017E64.c, which does the same around POKE_TOOL_GetBoxValueRaw,
 * and it is the entry point 240 call sites in the image use.
 *
 * What held it open, and what closed it: the `bl` at 0x02017E2E is the only
 * branch to POKE_TOOL_GetPartyValueRaw anywhere in the image, so the `label` class has no
 * witness once the compared range holds it, and the range cannot be cut
 * smaller than the one function.  The `matched` class carries it instead:
 * 0x02018DB4 is src/matched/POKE_TOOL_GetPartyValueRaw.c, an EXACT entry whose own byte
 * comparison covered a range this file does not touch, so the witness is our
 * compiled proof rather than anything inside 0x02017E1C..0x02017E40.  Its
 * setter twin src/matched/unit_02017E40.c closes the same way over
 * POKE_TOOL_SetPartyValueRaw.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02017E1C.c \
 *       --addr 0x02017E1C --thumb
 */
u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg)
{
    u32 value;

    POKE_TOOL_DecodeCalcBlock(pp);
    value = POKE_TOOL_GetPartyValueRaw(pp, paramId, arg);
    POKE_TOOL_EncodeCalcBlock(pp);
    return value;
}


/*
 * 0x02017E40..0x02017E64, 36 bytes, one function.
 *
 * The write wrapper for the party area of the 0xDC byte record, and the twin
 * of src/matched/unit_02017E1C.c: unlock, and only if the unlock reports 1
 * call the party-area setter POKE_TOOL_SetPartyValueRaw (src/matched/POKE_TOOL_SetPartyValueRaw.c), then
 * lock again.  It is the counterpart of POKE_TOOL_SetBoxValue in
 * src/matched/unit_02017E64.c, which does the same around POKE_TOOL_SetBoxValueRaw.
 *
 * What held it open, and what closed it: the `bl` at 0x02017E56 is the only
 * branch to POKE_TOOL_SetPartyValueRaw anywhere in the image, so no image class could
 * attest it from outside this range.  The `matched` class does:
 * 0x02019308 is src/matched/POKE_TOOL_SetPartyValueRaw.c, an EXACT entry proved against the
 * original bytes over a range this file does not touch.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02017E40.c \
 *       --addr 0x02017E40 --thumb
 */
void POKE_TOOL_SetPartyValue(struct PokemonParam *pp, u32 paramId, u32 value)
{
    if (POKE_TOOL_DecodeCalcBlock(pp) == 1) {
        POKE_TOOL_SetPartyValueRaw(pp, paramId, value);
    }
    POKE_TOOL_EncodeCalcBlock(pp);
}


/*
 *           POKE_TOOL_IsShinyOtIdPersonality, POKE_TOOL_GetGender, POKE_TOOL_GetBoxGender, POKE_TOOL_CalcGender,
 *           POKE_TOOL_GetStatusCondition, POKE_TOOL_SetStatusCondition, POKE_TOOL_SetDefaultMoves
 *
 * Five of the eleven carry no label in the generated listing: the three eight
 * to twelve byte pool-word tail calls at 0x02017EAC, 0x02017F00 and
 * 0x02017FA8, and the two twelve byte argument-setting thunks at 0x02017F90
 * and 0x02017F9C, all of them
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  POKE_TOOL_IsShiny, POKE_TOOL_GetGender
 * and POKE_TOOL_SetDefaultMoves each tail call the function immediately after them, which
 * makes two of the three sites the `local` class.
 *
 * POKE_TOOL_IsShinyOtIdPersonality folds two words to sixteen bits and its four XOR operands have
 * exactly one source order, which is not the order the `eors` appear in; see
 * docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md.
 *
 * POKE_TOOL_CalcGender dispatches 0, 0xFE and 0xFF out of a byte and falls through to
 * a comparison for everything else.  The three tests are one `switch`: written
 * as a chain of `if (n == k) return v;` statements each return gets its own
 * epilogue, while the switch puts the three bodies after the compare chain and
 * shares one `pop`, which is what the original does.  The `lsls`/`lsrs` pair
 * that truncates the call result is only emitted when the callee is declared
 * wider than `u8`, so POKE_PERSONAL_GetParam returns a word and the source assigns it to
 * a byte local.
 */
void POKE_TOOL_SetBoxValue(struct BoxPokemon *box, u32 paramId, u32 value)
{
    if (POKE_TOOL_DecodeBoxBlock(box) == 1) {
        POKE_TOOL_SetBoxValueRaw(box, paramId, value);
    }
    POKE_TOOL_EncodeBoxBlock(box);
}


u32 POKE_TOOL_GetBoxValue(struct BoxPokemon *box, u32 paramId, u32 arg)
{
    u32 value;

    POKE_TOOL_DecodeBoxBlock(box);
    value = POKE_TOOL_GetBoxValueRaw(box, paramId, arg);
    POKE_TOOL_EncodeBoxBlock(box);
    return value;
}


u32 POKE_TOOL_IsShiny(struct PokemonParam *pp)
{
    return POKE_TOOL_IsBoxShiny(&pp->box);
}


u32 POKE_TOOL_IsBoxShiny(struct BoxPokemon *box)
{
    u32 otId = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_OT_ID, 0);

    return POKE_TOOL_IsShinyOtIdPersonality(otId, POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_PERSONALITY, 0));
}


u32 POKE_TOOL_IsShinyOtIdPersonality(u32 otId, u32 personality)
{
    u32 x = ((otId & 0xFFFF0000) >> 16) ^ (u16)otId ^ ((personality & 0xFFFF0000) >> 16) ^ (u16)personality;

    if (x < 8) {
        return 1;
    }
    return 0;
}


u8 POKE_TOOL_GetGender(struct PokemonParam *pp)
{
    return POKE_TOOL_GetBoxGender(&pp->box);
}


u8 POKE_TOOL_GetBoxGender(struct BoxPokemon *box)
{
    u32 didDecode = POKE_TOOL_DecodeBoxParam(box);
    u16 species = (u16)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_SPECIES, 0);
    u32 form = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, 0);
    u32 personality = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_PERSONALITY, 0);

    POKE_TOOL_EncodeBoxParam(box, didDecode);
    return POKE_TOOL_CalcGender(species, (u16)form, personality);
}


u8 POKE_TOOL_CalcGender(u32 species, u16 form, u32 personality)
{
    u8 genderRatio = POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(species, form), 0x14);
    u8 gender;

    switch (genderRatio) {
    case 0x00:
        return 0;
    case 0xFE:
        return 1;
    case 0xFF:
        return 2;
    }
    if ((u8)personality < genderRatio) {
        gender = 1;
    } else {
        gender = 0;
    }
    return gender;
}


u32 POKE_TOOL_GetStatusCondition(struct PokemonParam *pp)
{
    return POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_STATUS_CONDITION, 0);
}


void POKE_TOOL_SetStatusCondition(struct PokemonParam *pp, u32 statusCondition)
{
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_STATUS_CONDITION, statusCondition);
}


u32 POKE_TOOL_SetDefaultMoves(struct PokemonParam *pp)
{
    return POKE_TOOL_SetBoxDefaultMoves(&pp->box);
}


static inline int POKE_TOOL_IsLevelUpMoveEnd(const struct LevelUpMove *entry)
{
    int isEnd = 0;
    if (entry->move == 0xFFFF && entry->level == 0xFFFF)
        isEnd = 1;
    return isEnd;
}


/*
 * Reset a record's moves to its level-up set: clear the four move/PP/PP-up
 * slots, load the species/form learnset into the shared buffer at
 * 0x02146330, then teach every entry at or below the current level
 * (POKE_TOOL_AddBoxMove; 0xFFFF = no free slot, so push it in with POKE_TOOL_PushBoxMove).
 * Block-lock sandwich (POKE_TOOL_DecodeBoxParam / POKE_TOOL_EncodeBoxParam).  Wave 11, 2026-09-23.
 *
 * Load-bearing: ONE loop variable `i` for both phases (the clearing loop
 * and the learnset walk, re-zeroed in between).  With two variables the
 * zero value argument and the walk index take separate registers and every
 * callee-saved register shifts (docs/idioms: reusing a loop variable
 * across phases); the permuter's hill (800, --types) found only volatile
 * hacks.  The frame's four entry copies and the pointer-taking terminator
 * inline follow POKE_TOOL_LearnLevelUpMove.c exactly (declaration order e, d, t, cur).
 */
u32 POKE_TOOL_SetBoxDefaultMoves(struct BoxPokemon *box)
{
    u32 didDecode;
    u16 species;
    u32 form;
    u8 level;
    int i;
    struct LevelUpMove levelEntry;
    struct LevelUpMove moveEntry;
    struct LevelUpMove endCheck;
    struct LevelUpMove cur;

    didDecode = POKE_TOOL_DecodeBoxParam(box);
    species = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_SPECIES, 0);
    form = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, 0);
    level = POKE_TOOL_CalcBoxLevel(box);
    POKE_PERSONAL_LoadDataDirect(species, (u16)form, gLevelUpMoveBuf);

    for (i = 0; i < 4; i++) {
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_MOVE1 + i, 0);
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_PP1 + i, 0);
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_PP_UP1 + i, 0);
    }
    i = 0;
    while (cur = gLevelUpMoveBuf[i], endCheck = cur, !POKE_TOOL_IsLevelUpMoveEnd(&endCheck)) {
        levelEntry = cur;
        if (levelEntry.level > level)
            break;
        moveEntry = cur;
        if (POKE_TOOL_AddBoxMove(box, moveEntry.move) == 0xFFFF)
            POKE_TOOL_PushBoxMove(box, moveEntry.move);
        i++;
    }
    return POKE_TOOL_EncodeBoxParam(box, didDecode);
}


/*
 * poke_tool.c: "teach this move if there is room".  POKE_TOOL_AddBoxMove unlocks the
 * record, walks the four move slots (ids 0x36 to 0x39 of the getter
 * POKE_TOOL_GetBoxValue), and writes the move into the first empty one through
 * POKE_TOOL_SetBoxMoveSlot (src/matched/unit_020181A0.c), locking again on the way out.
 * It answers with the move it wrote, 0xFFFE if the record already knows it,
 * and 0xFFFF if all four slots are full; POKE_TOOL_AddMove is a bare tail call to
 * it under a second name (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * 0xFFFE and 0xFFFF are ordinary integer constants and not relocations: both
 * are past the 255 an immediate reaches, so they arrive from the pool the way
 * any wide literal does.  The result is a stack local because it is live
 * across the unlock call, and it is assigned before the lock is taken, which
 * is what puts the `str` of 0xFFFF in front of the first `bl`.
 *
 * The third argument of every getter call comes out of a register that
 * already holds the loop counter's initial zero (`adds r7, r4, #0`), which is
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md
 * seen from the sharing side.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201808C.c \
 *       --addr 0x0201808C --thumb
 */
u16 POKE_TOOL_AddMove(struct PokemonParam *pp, u16 move)
{
    return POKE_TOOL_AddBoxMove(&pp->box, move);
}


u16 POKE_TOOL_AddBoxMove(struct BoxPokemon *box, u16 move)
{
    u16 result = 0xFFFF;
    u32 didDecode = POKE_TOOL_DecodeBoxParam(box);
    s32 slot;

    for (slot = 0; slot < 4; slot++) {
        u16 cur = (u16)POKE_TOOL_GetBoxValue(box, (u32)(POKE_TOOL_PARAM_MOVE1 + slot), 0);

        if (cur == 0) {
            POKE_TOOL_SetBoxMoveSlot(box, move, (u8)slot);
            result = move;
            break;
        }
        if (cur == move) {
            result = 0xFFFE;
            break;
        }
    }
    POKE_TOOL_EncodeBoxParam(box, didDecode);
    return result;
}


/*
 * An eight-byte Thumb tail thunk: `ldr r3, =POKE_TOOL_PushBoxMove; bx r3` with the
 * pool word immediately after.  It is the only callee of ov121 MYSTERY_NET_BuildPokemonFromRecord
 * with no `func_` label of its own (disasm.py sees the two-halfword stub as
 * data between POKE_TOOL_PushBoxMove's neighbour and POKE_TOOL_PushBoxMove).  Matching it
 * separately is what lets MYSTERY_NET_BuildPokemonFromRecord's `bl 0x020180F4` resolve as
 * `matched` rather than wildcarded; the veneer class is ARM-only, so the Thumb
 * stub has no other witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_PushMove.c \
 *       --func POKE_TOOL_PushMove --addr 0x020180F4 --cc 1.1p1 --thumb --region arm9
 */
void POKE_TOOL_PushMove(struct PokemonParam *pp, u16 move)
{
    POKE_TOOL_PushBoxMove(&pp->box, move);
}


/* Three parallel 4-entry channel tables.  They are three separate locals, NOT
 * one 16-byte struct: as a struct mwcc folds the member offset into the store
 * (`add r1, sp, #8 / adds r1, r1, r2 / strh r0, [r1, #8]`, three instructions
 * per element) where three arrays let it hoist `add r7, sp, #0x10` out of the
 * loop and emit `lsls r1, r4, #1 / strh r0, [r7, r1]`.  Declaration order
 * a, b, c (later declarator at the lower stack address) is what puts them at
 * sp+0x10 / sp+0xc / sp+8.  The fourth entry of each table is filled from a
 * different source: a[3] the parameter, b[3] a lookup, c[3] zero. */
/*
 * EXACT*: the listing extent runs 10 bytes past the body to 0x02018196
 * because the follower there is unlabelled -- 0x02018196 is two bytes of
 * padding and then a 4-byte ARM `ldr r3, [pc]; bx r3` veneer at 0x02018198.
 * No byte differs; the compiler's 154 bytes are byte-identical.
 */
void POKE_TOOL_PushBoxMove(struct BoxPokemon *box, u16 move)
{
    u16 moves[4];
    u8  pps[4];
    u8  ppUps[4];
    u32 didDecode;
    int i;
    int j;

    didDecode = POKE_TOOL_DecodeBoxParam(box);

    for (i = 0; i < 3; i++) {
        moves[i] = POKE_TOOL_GetBoxValue(box, i + POKE_TOOL_PARAM_MOVE2, 0);
        pps[i] = POKE_TOOL_GetBoxValue(box, i + POKE_TOOL_PARAM_PP2, 0);
        ppUps[i] = POKE_TOOL_GetBoxValue(box, i + POKE_TOOL_PARAM_PP_UP2, 0);
    }

    moves[3] = move;
    pps[3] = WAZA_TOOL_GetParam(move, 5);
    ppUps[3] = 0;

    for (j = 0; j < 4; j++) {
        POKE_TOOL_SetBoxValue(box, j + POKE_TOOL_PARAM_MOVE1, moves[j]);
        POKE_TOOL_SetBoxValue(box, j + POKE_TOOL_PARAM_PP1, pps[j]);
        POKE_TOOL_SetBoxValue(box, j + POKE_TOOL_PARAM_PP_UP1, ppUps[j]);
    }

    POKE_TOOL_EncodeBoxParam(box, didDecode);
}


/*
 * Unlabelled Thumb tail-call stub after POKE_TOOL_PushBoxMove (ldr r3, =POKE_TOOL_RecoverBoxAllPP;
 * bx r3). Filed as the witness for ov021 SODATEYA_SetupEggMon.
 */
void POKE_TOOL_RecoverAllPP(struct PokemonParam *pp)
{
    POKE_TOOL_RecoverBoxAllPP(&pp->box);
}


/*
 * Two move-slot writers over the record's ids 0x36..0x39 (the four move ids),
 * 0x3A..0x3D (their current PP) and 0x3E..0x41 (their PP-up counts), the same
 * three groups POKE_TOOL_GetBoxValueRaw reads.  POKE_TOOL_RecoverBoxAllPP refills every non-empty
 * slot's PP to the maximum WAZA_TOOL_GetMaxPP computes from the move and its PP-up
 * count; POKE_TOOL_SetBoxMoveSlot writes one slot outright, clearing the PP-up count and
 * setting the PP to the fresh maximum, or to zero when the move is zero.
 * POKE_TOOL_SetMoveSlot in front of it is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk, `local` because its
 * target is the next function in this unit.
 *
 * POKE_TOOL_SetBoxMoveSlot is what makes this unit and src/matched/unit_02018094.c-shaped
 * callers attest each other: its two call sites in the image are the thunk
 * here and one inside POKE_TOOL_AddBoxMove, so neither range can hold both.
 *
 * Two spellings are load bearing.  POKE_TOOL_RecoverBoxAllPP's loop counter is unsigned,
 * because the bound test is `blo` and not `blt`; the counter of the otherwise
 * identical loop in POKE_TOOL_AddBoxMove and POKE_TOOL_FindBoxMoveSlot is signed and those use
 * `blt`.  And the two truncations in POKE_TOOL_RecoverBoxAllPP sit at the call, `(u16)m`
 * and `(u8)u` on word locals, rather than on narrower locals, which is the
 * same shape as src/matched/unit_02018430.c.
 *
 * Nothing here is version specific: 0x36, 0x3A and 0x3E are field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_020181A0.c \
 *       --addr 0x020181A0 --thumb
 */
void POKE_TOOL_RecoverBoxAllPP(struct BoxPokemon *box)
{
    u32 didDecode = POKE_TOOL_DecodeBoxParam(box);
    u32 i;

    for (i = 0; i < 4; i++) {
        u32 move = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_MOVE1 + i, 0);

        if (move != 0) {
            u32 ppUps = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_PP_UP1 + i, 0);

            POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_PP1 + i, WAZA_TOOL_GetMaxPP((u16)move, (u8)ppUps));
        }
    }
    POKE_TOOL_EncodeBoxParam(box, didDecode);
}


void POKE_TOOL_SetMoveSlot(struct PokemonParam *pp, u16 move, u32 slot)
{
    POKE_TOOL_SetBoxMoveSlot(&pp->box, move, slot);
}


void POKE_TOOL_SetBoxMoveSlot(struct BoxPokemon *box, u16 move, u32 slot)
{
    u32 pp = 0;

    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_MOVE1 + slot, move);
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_PP_UP1 + slot, 0);
    if (move != 0) {
        pp = WAZA_TOOL_GetMaxPP(move, 0);
    }
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_PP1 + slot, pp);
}


u32 POKE_TOOL_FindMoveSlot(struct PokemonParam *pp, u16 move)
{
    return POKE_TOOL_FindBoxMoveSlot(&pp->box, move);
}


/*
 * status note: EXACT* -- the extent runs long because the unlabelled 8-byte
 *           thunk at 0x020182A0 follows without a label; never a byte
 *           difference.  Report it as an unlabelled follower for
 *           layout/function_starts.txt.
 *
 * WAS BLOCKED, now resolved (2026-09-22): the only branch to 0x020182A8 in the
 *           image is this function's own call at +0x30, so the `label` class
 *           had no outside witness and this file was capped at MATCH.
 *           src/matched/POKE_TOOL_ReplaceBoxMoveSlot.c now reproduces that address, so the
 *           site resolves through `matched` and this file is EXACT* with no
 *           edit to its C.
 *
 * "Put this move in the first empty slot": walks ids 0x36..0x39 and returns
 * 0xFFFF when no slot was touched, the move when one was filled, and 0xFFFE
 * when the move was already known.  The loop counter is signed (`blt`), unlike
 * the otherwise identical loop in POKE_TOOL_RecoverBoxAllPP, which is `blo`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_FindBoxMoveSlot.c \
 *       --func POKE_TOOL_FindBoxMoveSlot --addr 0x02018240 --cc 1.1p1 --thumb
 */
u32 POKE_TOOL_FindBoxMoveSlot(struct BoxPokemon *box, u16 move)
{
    u32 result = 0xFFFF;
    u32 didDecode = POKE_TOOL_DecodeBoxParam(box);
    int slot;

    for (slot = 0; slot < 4; slot++) {
        u32 cur = (u16)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_MOVE1 + slot, 0);

        if (cur == 0) {
            POKE_TOOL_ReplaceBoxMoveSlot(box, move, (u8)slot);
            result = move;
            break;
        }
        if (cur == move) {
            result = 0xFFFE;
            break;
        }
    }
    POKE_TOOL_EncodeBoxParam(box, didDecode);
    return result;
}


void POKE_TOOL_ReplaceMoveSlot(struct PokemonParam *pp, u16 move, u8 slot)
{
    POKE_TOOL_ReplaceBoxMoveSlot(&pp->box, move, slot);
}


/*
 * "Write this move into slot `slot`, keeping the PP the slot already had".
 * The twin of POKE_TOOL_SetBoxMoveSlot (src/matched/unit_020181A0.c), which writes the
 * slot outright: this one remembers whether the slot held a move (b), reads
 * the slot's current PP (0x3A + slot, as a u8), writes the move id
 * (0x36 + slot), clears the PP-up count (0x3E + slot), and finally writes a PP
 * that is the fresh maximum WAZA_TOOL_GetMaxPP computes -- except that when the
 * slot was previously occupied the PP is clamped down to whatever the old
 * slot had, so replacing a move never raises its remaining PP.
 *
 * THE LEVER, and the whole 128-byte residue this file's earlier attempts hit
 * (docs/notes/pkt_02018240.c.txt records ten prologue bytes wrong across every
 * statement-shape and declaration-order spelling tried, and tools/permuter.py
 * -- 197 single mutations, --types -- cannot move any of them):
 *
 *     THE THIRD PARAMETER IS u8, NOT u32.
 *
 * That is the family's own first-pass rule -- a truncation emitted at the CALL
 * constrains the CALLEE's parameter width -- read off the single caller,
 * POKE_TOOL_FindBoxMoveSlot at 0x02018268:
 *
 *     02018268  lsls r2, r4, #0x18
 *     0201826E  lsrs r2, r2, #0x18      <- (u8)i at the call site
 *
 * With `u8 slot` the front end gives the parameter a memory home at sp+0 and
 * reloads it (`str r2,[sp]` ... `ldr r1,[sp]`), which is exactly the prologue
 * the original has; with `u32 slot` it keeps the incoming r2 in a register
 * (`adds r1, r2, #0`) and the five entry halfwords permute.  No statement
 * shape, declaration order, volatile, address-taking or extra parameter
 * reaches it -- only the width does.
 *
 * Filing this address also unblocks src/pending/POKE_TOOL_FindBoxMoveSlot.c, whose only
 * missing witness was a manifest entry at 0x020182A8 (its own call at +0x30 is
 * the sole branch to this address in the image, so the `label` class had no
 * outside witness).  That file turns EXACT with no edit.
 *
 * Nothing here is version specific: 0x36, 0x3A and 0x3E are field selectors.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_ReplaceBoxMoveSlot.c \
 *       --func POKE_TOOL_ReplaceBoxMoveSlot --addr 0x020182A8 --cc 1.1p1 --thumb
 */
void POKE_TOOL_ReplaceBoxMoveSlot(struct BoxPokemon *box, u16 move, u8 slot)
{
    u32 hadMove;
    u32 moveParam;
    u32 ppParam;
    u32 newPp = 0;
    u32 oldPp;

    moveParam = slot + POKE_TOOL_PARAM_MOVE1;
    if (POKE_TOOL_GetBoxValue(box, moveParam, 0) != 0) {
        hadMove = 1;
    } else {
        hadMove = 0;
    }
    ppParam = slot + POKE_TOOL_PARAM_PP1;
    oldPp = (u8)POKE_TOOL_GetBoxValue(box, ppParam, 0);
    POKE_TOOL_SetBoxValue(box, moveParam, move);
    POKE_TOOL_SetBoxValue(box, slot + POKE_TOOL_PARAM_PP_UP1, 0);
    if (move != 0) {
        newPp = WAZA_TOOL_GetMaxPP(move, 0);
        if (hadMove != 0) {
            if (newPp <= oldPp) {
                oldPp = newPp;
            }
            newPp = (u8)oldPp;
        }
    }
    POKE_TOOL_SetBoxValue(box, ppParam, newPp);
}


/*
 * Level-up learnset scan: load the species/form learnset (POKE_PERSONAL_LoadDataDirect) into
 * a 0x68-byte heap block (poke_tool.c line 0x644), then walk it from *idx
 * until the {0xFFFF, 0xFFFF} terminator.  For an entry at the record's
 * level, try to teach it (POKE_TOOL_AddMove): 0xFFFF (no free slot) answers the
 * move with bit 15 set, 0xFFFE (already known) keeps scanning, anything else
 * is returned; *idx is left one past the entry.  Wave 11, 2026-09-23.
 *
 * Load-bearing, found by hand after the permuter's hill (800, --types) and
 * the r12 lane's register swap:
 *   - `species` is u16 (truncated at the assignment) but `form` is u32 and
 *     the (u16) lands at the POKE_PERSONAL_LoadDataDirect call; `level` is u8.
 *   - FIVE 4-byte struct copies live in the frame, in this declaration
 *     order (later declaration at the lower address): e, d, f, t, cur.
 *     They are by-value copies of the entry (e for the level test, d for the
 *     move, f for the final re-read, t for the terminator test).  Written
 *     as inline helpers taking the struct by value, the compiler elides one
 *     copy and swaps two slots; spelled as explicit locals it does not.
 *   - the terminator test is an inline taking `const struct Learn *` with
 *     the `end = 0; if (..) end = 1;` accumulator, called in the `while`
 *     condition so the loop is rotated (entry `b` to the test).
 *   - `level == e.level` (level first: cmp r0, r1).
 */
u16 POKE_TOOL_LearnLevelUpMove(struct PokemonParam *pp, u32 *tableIndex, u32 heapId)
{
    struct LevelUpMove *table;
    u16 species;
    u32 form;
    u8 level;
    u16 result = 0;
    struct LevelUpMove levelEntry;
    struct LevelUpMove moveEntry;
    struct LevelUpMove replacementEntry;
    struct LevelUpMove endCheck;
    struct LevelUpMove cur;

    table = GFL_HEAP_Alloc((u16)((heapId & 0x7fff) | 0x8000), 0x68, 0, sPokeToolFile, 0x644);
    species = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_SPECIES, 0);
    form = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_FORM, 0);
    level = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_LEVEL, 0);
    POKE_PERSONAL_LoadDataDirect(species, (u16)form, table);

    while (cur = table[*tableIndex], endCheck = cur, !POKE_TOOL_IsLevelUpMoveEnd(&endCheck)) {
        levelEntry = cur;
        if (level == levelEntry.level) {
            moveEntry = cur;
            result = POKE_TOOL_AddMove(pp, moveEntry.move);
            if (result == 0xFFFF) {
                replacementEntry = table[*tableIndex];
                result = replacementEntry.move | 0x8000;
                (*tableIndex)++;
                break;
            }
            if (result != 0xFFFE) {
                (*tableIndex)++;
                break;
            }
        }
        (*tableIndex)++;
    }
    GFL_HEAP_Free(table);
    return result;
}


/*
 * The record's level accessor: it unlocks the block area, reads ids 5, 0x6F
 * and 8 out of it (species, form and experience), locks it again and hands the
 * three to POKE_TOOL_CalcLevelFromExp (src/matched/unit_0201850C.c), which is the same
 * computation id 0x9E of POKE_TOOL_GetBoxValueRaw performs directly on the substructs.
 * POKE_TOOL_CalcLevel in front of it is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk with no prologue, and
 * its pool word is `local` because its target is the next function in the same
 * unit.
 *
 * The three values are held in word locals and truncated at the call, not at
 * the assignment: the two `lsls #0x10` / `lsrs #0x10` pairs sit immediately in
 * front of the `bl`, after the lock call, which is what fixes POKE_TOOL_CalcLevelFromExp's
 * first two parameters as u16 and POKE_TOOL_GetBoxValue's return as a word.  The same
 * shape appears in src/matched/unit_02017E64.c and src/matched/unit_0201854C.c.
 *
 * The range stops at 0x02018480, where another eight byte thunk forwards to
 * POKE_TOOL_IsBoxOwnedByPlayer; that thunk's pool word is the only reference to POKE_TOOL_IsBoxOwnedByPlayer
 * in the image, and POKE_TOOL_IsBoxOwnedByPlayer in turn is the only caller of 0x020084F8, so
 * neither can be attested and both are left out.
 *
 * Nothing here is version specific: 5, 0x6F and 8 are field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02018430.c \
 *       --addr 0x02018430 --thumb
 */
u32 POKE_TOOL_CalcLevel(struct PokemonParam *pp)
{
    return POKE_TOOL_CalcBoxLevel(&pp->box);
}


u32 POKE_TOOL_CalcBoxLevel(struct BoxPokemon *box)
{
    u32 didDecode = POKE_TOOL_DecodeBoxParam(box);
    u32 species = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_SPECIES, 0);
    u32 form = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, 0);
    u32 exp = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_EXP, 0);

    POKE_TOOL_EncodeBoxParam(box, didDecode);
    return POKE_TOOL_CalcLevelFromExp((u16)species, (u16)form, exp);
}


/*
 * Eight byte thunk (pool word and bx) that forwards both arguments to
 * POKE_TOOL_IsBoxOwnedByPlayer. Witness for the ov093 caller BTL_SERVER_FLOW_CheckDisobedience.
 */
int POKE_TOOL_IsOwnedByPlayer(struct PokemonParam *pp, struct MyStatus *myStatus)
{
    return POKE_TOOL_IsBoxOwnedByPlayer(&pp->box, myStatus);
}


/*
 * note:     132 bytes, one function
 * note:     re-verified 2026-09-21: EXACT.  The MATCH cap was lifted by the
 *           sole-ref widening of 2026-09-21, not by any edit to the C:
 *           the data address this file reaches now attests as
 *           sole-ref/data.  Promoted from src/pending/ unchanged.
 *
 * Why it WAS capped (historical, resolved 2026-09-21): the ABS32 against the 0x021462B0 scratch buffer.  A scan
 * of every word in all 242 regions finds 0x021462B0 exactly once, in the pool
 * word at 0x02018508 that this function owns, so the `literal` class discards
 * its only witness and no cut helps.  The buffer's neighbour 0x021462F0 is
 * named by six pool words and resolves; the two are 0x40 apart and are two
 * statics in one bss run rather than one object with an offset, so declaring
 * a single symbol at the attested one and reaching this one as a negative
 * addend would be a claim about the data layout the image does not support.
 * It closes the day anything else in the image names 0x021462B0.
 *
 * poke_tool.c: "does this record still belong to the trainer that owns this
 * mail", the comparison that unlocks the record with POKE_TOOL_DecodeBoxParam
 * (src/matched/unit_02017D30.c), reads the trainer id (field 0x07) and the
 * second name field (0x9A) out of it, reads the same two out of the mail
 * object through MYSTATUS_GetId and MYSTATUS_GetOutfitVariant, copies both names into the
 * two 0x20 byte scratch buffers at 0x021462F0 and 0x021462B0, and compares
 * the strings with WORDSET_CheckF448.
 *
 * The three tests are one conjunction: all three conditional branches land on
 * the same address and there is one `movs r6, #1`
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * The four comparison operands are stack locals rather than registers because
 * they are live across the calls that follow them, and they sit at sp+0,
 * sp+4, sp+8 and sp+0xC in the order the source declares them last to first
 * (docs/idioms/local-declaration-order-is-stack-order.md).
 *
 * The lock flag is truncated to u8 on the way out of POKE_TOOL_DecodeBoxParam, which is
 * the `lsls #0x18` / `lsrs #0x18` pair at 0x02018494.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/POKE_TOOL_IsBoxOwnedByPlayer.c \
 *       --addr 0x02018488 --thumb
 */
u32 POKE_TOOL_IsBoxOwnedByPlayer(struct BoxPokemon *box, struct MyStatus *myStatus)
{
    u32 monOtGender;
    u32 playerGender;
    u32 monOtId;
    u32 playerOtId;
    u8  didDecode = (u8)POKE_TOOL_DecodeBoxParam(box);
    u32 isOwned = 0;

    playerOtId = MYSTATUS_GetId(myStatus);
    monOtId = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_OT_ID, 0);
    playerGender = MYSTATUS_GetOutfitVariant(myStatus);
    monOtGender = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_OT_GENDER, 0);
    MYSTATUS_CopyNameChars(myStatus, (u32)gNameBuf, 0x20);
    POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_OT_NAME, (u32)gNameCompareBuf);
    if (playerOtId == monOtId && playerGender == monOtGender && WORDSET_CheckF448(gNameBuf, gNameCompareBuf) != 0) {
        isOwned = 1;
    }
    POKE_TOOL_EncodeBoxParam(box, didDecode);
    return isOwned;
}


/*
 * Experience to level.  This is the callee of id 0x9E of POKE_TOOL_GetBoxValueRaw
 * (src/pending/POKE_TOOL_GetBoxValueRaw.c), which passes it a species id, the five bit
 * form field of substruct B +0x18 and the experience word of substruct A +8.
 * It reads field 0x17 of the species' record, which is the growth-rate
 * selector, fills the shared word buffer at 0x02146398 with that curve through
 * POKE_TOOL_LoadExpTable, and then walks entries 1 to 0x64 for the first one that
 * exceeds the experience, returning the index before it.
 *
 * The loop is a `for` whose bound test the compiler rotates to the bottom, so
 * the first table read happens before any comparison with 0x65; the counter is
 * u16, which is what the `lsls #0x10` / `lsrs #0x10` pair after each increment
 * is, and writing it `u32` drops that pair and the function is four bytes
 * short.
 *
 * The range stops at 0x02018544, where an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk forwards to
 * POKE_TOOL_GetBoxLevelMinExp.  That thunk's pool word is the only reference to
 * POKE_TOOL_GetBoxLevelMinExp in the image, so including it caps the file at MATCH; it is
 * left out and this function is clean.
 *
 * 0x02146398 is the same scratch buffer POKE_TOOL_GetExpValue fills in
 * src/matched/unit_02019B58.c, which is what attests it here and what this
 * file's pool word attests there: the pairwise case of docs/MATCHING.md.
 *
 * Nothing here is version specific; 0x17 is a field selector and 0x65 is the
 * level table's length.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201850C.c \
 *       --addr 0x0201850C --thumb
 */
u32 POKE_TOOL_CalcLevelFromExp(u16 species, u16 form, u32 exp)
{
    u16 level;

    POKE_TOOL_LoadExpTable((u16)POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(species, form), 0x17),
                  gExpTableBuf);
    for (level = 1; level < 0x65; level = (u16)(level + 1)) {
        if (gExpTableBuf[level] > exp) {
            break;
        }
    }
    return level - 1;
}


u32 POKE_TOOL_GetLevelMinExp(struct PokemonParam *pp)
{
    return POKE_TOOL_GetBoxLevelMinExp(&pp->box);
}


/*
 * 0x0201854C..0x02018598, 76 bytes, two functions.
 *
 * What held it open, and what closed it: POKE_TOOL_GetExpForLevel is the only caller of
 * POKE_TOOL_GetExpValue in the whole image, so the `label` class has no witness once
 * the compared range holds that call, and no cut helps because the range
 * cannot be made smaller than the one function that needs it.  The `matched`
 * class carries it: 0x02019BA4 is inside src/matched/unit_02019B58.c, an
 * EXACT entry whose byte comparison covered that address over a range this
 * file does not touch.  Keeping POKE_TOOL_GetBoxLevelMinExp with POKE_TOOL_GetExpForLevel costs
 * nothing, since POKE_TOOL_GetBoxLevelMinExp is in turn the only caller of POKE_TOOL_GetExpForLevel.
 *
 * The three ids this reads, 5, 0x6F and 0x9E, are the same three
 * POKE_TOOL_CheckBoxTmCompat and POKE_TOOL_SetLevelAndRecalc read, and all three values are truncated to
 * u16 at the call rather than at the assignment, which is what fixes
 * POKE_TOOL_GetExpForLevel's parameters as u16 and the accessor's return as a word.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201854C.c \
 *       --addr 0x0201854C --thumb
 */
u32 POKE_TOOL_GetBoxLevelMinExp(struct BoxPokemon *box)
{
    u32 species = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_SPECIES, 0);
    u32 form = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, 0);
    u32 level = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_LEVEL, 0);

    return POKE_TOOL_GetExpForLevel((u16)species, (u16)form, (u16)level);
}


u32 POKE_TOOL_GetExpForLevel(u16 species, u16 form, u16 level)
{
    return POKE_TOOL_GetExpValue(POKE_TOOL_GetPersonalParam(species, form, 0x17), level);
}


/*
 * The middle piece of the run 0x0201854C..0x0201862C.  Its two neighbours are
 * parked in src/pending/: POKE_TOOL_GetExpForLevel is the only caller of POKE_TOOL_GetExpValue
 * in the image and POKE_TOOL_RecalcParam the only caller of POKE_TOOL_CalcParam, so neither
 * has a witness outside itself and no cut reaches them.
 *
 * POKE_TOOL_GetNature carries no label: it is the eight byte pool-word tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md to the function that follows
 * it, so the site is the `local` class.
 */
u8 POKE_TOOL_GetNature(struct PokemonParam *pp)
{
    return POKE_TOOL_GetBoxNature(&pp->box);
}


u8 POKE_TOOL_GetBoxNature(struct BoxPokemon *box)
{
    return (u8)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_NATURE, 0);
}


void POKE_TOOL_SetNature(struct PokemonParam *pp, u32 nature)
{
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_NATURE, nature);
    POKE_TOOL_RecalcParam(pp);
}


/*
 * 0x020185C4..0x020185F0, 44 bytes, one function.
 *
 * The shape is the lock/recompute/unlock sandwich the whole region uses:
 * POKE_TOOL_DecodePartyParam takes the lock and returns whether it actually took it, and
 * that flag is what POKE_TOOL_EncodePartyParam is handed back.  Between them it refreshes
 * the level (id 0x9E, from POKE_TOOL_CalcLevel) and then recalculates the six stats
 * with POKE_TOOL_CalcParam.
 *
 * What held it open, and what closed it: this is the only caller of
 * POKE_TOOL_CalcParam anywhere in the image, so the `label` class discards its only
 * witness under the honesty rule and no cut helps, because the range cannot be
 * made smaller than the one function that holds the call.  The `matched` class
 * carries it now: 0x02018A7C is src/matched/POKE_TOOL_CalcParam.c, an EXACT entry
 * proved byte for byte against the original over a range this file does not
 * touch.  It was parked in src/pending/ until that entry existed.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_020185C4.c \
 *       --addr 0x020185C4 --thumb
 */
void POKE_TOOL_RecalcParam(struct PokemonParam *pp)
{
    u32 didDecode = POKE_TOOL_DecodePartyParam(pp);

    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_LEVEL, POKE_TOOL_CalcLevel(pp));
    POKE_TOOL_CalcParam(pp);
    POKE_TOOL_EncodePartyParam(pp, didDecode);
}


/*
 * POKE_TOOL_Dummy and POKE_TOOL_GetBoxParam are a bare `bx lr` padded to four bytes,
 * which is `void f(void) {}`: a hook that was never filled in.  Neither
 * carries a label in the generated listing.  POKE_TOOL_Dummy is reached from
 * POKE_TOOL_SetDefaultName, which is what attests the pair's addresses.
 */
void POKE_TOOL_Dummy(void)
{
}


struct BoxPokemon *POKE_TOOL_GetBoxParam(struct PokemonParam *pp)
{
    return &pp->box;
}


u32 POKE_TOOL_GetGenderRatioClass(int species, u16 form, int ratioMode)
{
    u32 result = 8;
    u8 genderRatio = (u8)POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(species, form), 0x14);

    if (POKE_PERSONAL_IsPlaceholderAbility(genderRatio) != 1) {
        if (ratioMode == 0) {
            result = genderRatio;
        } else {
            result = genderRatio - 1;
            if (genderRatio == 0) {
                result = 0;
            }
        }
    }
    return result;
}


/*
 * Force a personality value's shininess against trainer id a0: with a5 set,
 * a fresh value from POKE_TOOL_GetGenderRatioClass whose high half is made to xor to the
 * id's key; otherwise an all-0xFF00 construction plus the species' stage
 * byte.  Bit 16 is then forced to a4.  Wave 11, 2026-09-23.
 *
 * The 9-byte residue of 2026-09-22 (permuter floor, `commute(^)`) closed by
 * naming the id key as a block-scoped local, `k = hi(a0) ^ (u16)a0`, and
 * writing `k ^ (u16)v`: the key is computed first into r2 and the chain
 * stays in r1/r2, as the image has it.  No inline form of the same xor
 * reached it (docs/notes/pkt_0201862C.c.txt).
 */
u32 POKE_TOOL_AdjustPersonalRnd(u32 otId, u16 species, u16 form, u8 ratioMode, u8 shinyWanted, int genderMode)
{
    if (genderMode != 0) {
        u32 genderByte = POKE_TOOL_GetGenderRatioClass(species, form, ratioMode);

        {
            u32 idHash = ((otId & 0xFFFF0000u) >> 16) ^ (u16)otId;

            otId = genderByte | ((idHash ^ (u16)genderByte) << 16);
        }
        if ((otId & 0x10000u) != ((u32)shinyWanted << 16)) {
            otId ^= 0x10000u;
        }
    } else {
        u8 genderRatio = (u8)POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(species, form), 0x14);

        otId = (0xFF00u ^ ((((otId & 0xFFFF0000u) >> 16) ^ (u16)otId) & 0xFF00u)) << 16;
        if ((otId & 0x10000u) != ((u32)shinyWanted << 16)) {
            otId ^= 0x10000u;
        }
        if (POKE_PERSONAL_IsPlaceholderAbility(genderRatio) == 1) {
            goto done;
        }
        otId |= genderRatio;
        if (ratioMode == 1) {
            otId -= 1;
        }
    }
done:
    return otId;
}


/*
 * Build a personality value for trainer id a0: a3 selects the gender
 * handling (2 = fully random), a5 the shininess (1 = force shiny through
 * the id key, 0 = force NOT shiny by flipping bit 28 when POKE_TOOL_IsShinyOtIdPersonality
 * says shiny, 2 = leave), and bit 16 is forced to a4 (read as a word, so
 * a4 is int-sized).  Wave 11, 2026-09-23.
 *
 * The 8-byte shortfall of the r4-3/r4-6 lanes ("duplicated compare, shared
 * eors", judged a cross-jump no source can request) is the SOURCE shape:
 * case 1 carries its own bit-16 fix and `break`s, case 0 FALLS THROUGH into
 * case 2, which carries the other copy; the compiler tail-merges the two
 * `v ^= 0x10000` statements and nothing else.  Case bodies in the order
 * 1, 0, 2; the case-1 key written `hi(a0) ^ (u16)a0` first.
 */
u32 POKE_TOOL_CreatePersonalRnd(u32 otId, int species, u16 form, int ratioMode, int shinyWanted, int mode)
{
    u32 personality;

    if (ratioMode == 2) {
        personality = GFL_USE_GetRandom(0);
    } else {
        u32 highBits = GFL_USE_GetRandom(0) & ~0xFFu;

        personality = POKE_TOOL_GetGenderRatioClass(species, form, (u8)ratioMode);
        if (ratioMode == 0) {
            if (POKE_PERSONAL_IsPlaceholderAbility(personality) == 0) {
                personality = personality + GFL_USE_GetRandom(0xFE - personality);
                goto L;
            }
        }
        if (ratioMode == 1) {
            if (POKE_PERSONAL_IsPlaceholderAbility(personality) == 0) {
                personality = GFL_USE_GetRandom(personality) + 1;
            }
        }
    L:
        personality |= highBits;
    }
    switch (mode) {
    case 1:
        personality = (u8)personality | (((((otId & 0xFFFF0000u) >> 16) ^ (u16)otId) ^ (u8)personality) << 16);
        if ((personality & 0x10000u) != ((u32)shinyWanted << 16)) {
            personality ^= 0x10000u;
        }
        break;
    case 0:
        if (POKE_TOOL_IsShinyOtIdPersonality(otId, personality) == 1) {
            personality ^= 0x10000000u;
        }
    case 2:
        if ((personality & 0x10000u) != ((u32)shinyWanted << 16)) {
            personality ^= 0x10000u;
        }
        break;
    }
    return personality;
}


/*
 * note:     144 bytes, one function
 *
 * The type half of the Hidden Power pair; the power half is
 * src/matched/unit_02018820.c and is EXACT.  It folds bit 0 of each of the six
 * 5 bit fields at substruct B +0x10 into a 0..63 index, scales it by 15/63,
 * reduces it below 17 with a subtract loop rather than a modulo, and indexes a
 * byte table at 0x0209E288.
 *
 * Why it WAS capped (historical, resolved 2026-09-21): the pool word at 0x0201881C is the only word in the whole
 * image that holds 0x0209E288, so the `literal` class discards its only
 * witness and the table cannot be attested.  Same shape as
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md.  No cut helps:
 * the load and the pool word are in the one function.
 *
 * The reduction is a `while (n > 16) n -= 16;` and not `n %= 16`, which would
 * be a single `ands`; and the division is unsigned, so the whole expression is
 * `n * 15 / 63`.
 *
 * VERSION SENSITIVITY: the 17 byte table at 0x0209E288 is type ids, which is
 * content numbering; it is expected to be identical in a White build, but it
 * is data rather than structure and should be re-read.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_02018790.c \
 *       --addr 0x02018790 --thumb
 *
 * RESOLVED 2026-09-21: the sole-ref widening accepts 0x0209E288 as
 * sole-ref/data, so the table now attests and this unit verifies EXACT with no
 * change to its C.  The one edit this wave made is the missing `_u32_div_f`
 * line in the symbols: block below -- without it that site was unresolved and
 * the unit reported MATCH for a reason that had nothing to do with the table.
 *
 * Historical note, no longer binding:
 * The `matched` class does not reach it either: an EXACT entry attests the code
 * it reproduced, never a data object one of its instructions loads, and
 * 0x0209E288 is a table.
 */
u32 POKE_TOOL_GetHiddenPowerType(struct PokemonParam *pp)
{
    u32 typeIndex = 0;

    if (POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_HP, 0) & 1) {
        typeIndex += 1;
    }
    if (POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_ATTACK, 0) & 1) {
        typeIndex += 2;
    }
    if (POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_DEFENSE, 0) & 1) {
        typeIndex += 4;
    }
    if (POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_SPEED, 0) & 1) {
        typeIndex += 8;
    }
    if (POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_SP_ATTACK, 0) & 1) {
        typeIndex += 16;
    }
    if (POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_SP_DEFENSE, 0) & 1) {
        typeIndex += 32;
    }
    typeIndex = typeIndex * 15 / 63;
    while (typeIndex > 16) {
        typeIndex -= 16;
    }
    return sHiddenPowerTypes[typeIndex];
}


/*
 * Folds the six ids 0x46 to 0x4B, the six 5 bit fields of substruct B +0x10
 * that POKE_TOOL_GetBoxValueRaw reads, into a 0 to 63 index on bit 1 of each and scales
 * it to 30..70.  Its neighbour POKE_TOOL_GetHiddenPowerType is the same fold on bit 0 with a
 * table lookup at the end, and the two are the pair a Hidden Power power and
 * type are computed with.
 *
 * The range is one function on purpose.  POKE_TOOL_GetHiddenPowerType, immediately before,
 * reads a byte table at 0x0209E288 whose only reference anywhere in the image
 * is the pool word under test, so it caps at MATCH however it is written; and
 * POKE_TOOL_CheckTmCompat, immediately after, is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk whose pool word is the
 * only reference to POKE_TOOL_CheckBoxTmCompat in the image, so it caps too.  Both are
 * byte-correct and neither can be cut free; this middle function is what is
 * left, and it is clean.
 *
 * The six tests are `(x & 3) > 1` rather than a bit test, which is `movs #3` /
 * `ands` / `cmp #1` / `bls`; the accumulator takes `adds rD, rN, #imm3` for 1,
 * 2 and 4 and `adds rD, #imm8` from 8 up, which is encoding and not source.
 * The scale is one `muls` by 40 and one `_u32_div_f` by 63, so the division is
 * unsigned and written as `n * 40 / 63 + 30`; `+ 30` folds into the `adds`
 * after the call.
 *
 * Nothing here is version specific: the six ids are structure field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02018820.c \
 *       --addr 0x02018820 --thumb
 */
u32 POKE_TOOL_GetHiddenPowerPower(struct PokemonParam *pp)
{
    u32 powerIndex = 0;

    if ((POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_HP, 0) & 3) > 1) {
        powerIndex += 1;
    }
    if ((POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_ATTACK, 0) & 3) > 1) {
        powerIndex += 2;
    }
    if ((POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_DEFENSE, 0) & 3) > 1) {
        powerIndex += 4;
    }
    if ((POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_SPEED, 0) & 3) > 1) {
        powerIndex += 8;
    }
    if ((POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_SP_ATTACK, 0) & 3) > 1) {
        powerIndex += 16;
    }
    if ((POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_SP_DEFENSE, 0) & 3) > 1) {
        powerIndex += 32;
    }
    return powerIndex * 40 / 63 + 30;
}


/*
 * Eight byte tail-call thunk to POKE_TOOL_CheckBoxTmCompat
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Filed as the relocation
 * witness for ov021 SCRCMD_POKEMON_FLD_GetMonTypeForTm (wave A1).
 */
u32 POKE_TOOL_CheckTmCompat(struct PokemonParam *pp, int tmIndex)
{
    return POKE_TOOL_CheckBoxTmCompat(&pp->box, tmIndex);
}


/*
 *           POKE_TOOL_HasRibbonData
 *
 * The three functions at 0x020189D0, 0x020189D8 and 0x020189F0 sit between
 * this file and src/matched/unit_02018A00.c and are a documented near miss:
 * every concrete byte of them is reproduced, but POKE_TOOL_GetNatureStatModByNature loads the
 * s8[][5] table at 0x0209E2A4 and the only word in the image that holds that
 * address is the pool word under test, so no cut attests it.  See
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md for the same
 * shape on a string.
 */
u32 POKE_TOOL_CheckBoxTmCompat(struct BoxPokemon *box, s32 tmIndex)
{
    u16 species = (u16)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_SPECIES, 0);
    u16 form = (u16)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_FORM, 0);

    return POKE_TOOL_CheckSpeciesTmCompat(species, form, tmIndex);
}


u32 POKE_TOOL_CheckSpeciesTmCompat(u16 species, u16 form, s32 tmIndex)
{
    u32 result;

    if (species == 0x28A) {
        result = 0;
    } else if (POKE_TOOL_GetPersonalParam(species, form, tmIndex / 32 + 0x27) & (1 << (tmIndex % 32))) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}


u32 POKE_TOOL_CheckTutorCompat(struct PokemonParam *pp, s32 tutorIndex)
{
    u16 species = (u16)POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_SPECIES, 0);
    u16 form = (u16)POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_FORM, 0);

    return POKE_TOOL_CheckSpeciesTutorCompat(species, form, tutorIndex);
}


u32 POKE_TOOL_CheckSpeciesTutorCompat(u16 species, u16 form, s32 tutorIndex)
{
    u32 result;

    if (species == 0x28A) {
        result = 0;
    } else if (POKE_TOOL_GetPersonalParam(species, form, 0x2B) & (1 << (tutorIndex % 32))) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}


u32 POKE_TOOL_HasRibbonData(struct BoxPokemon *box)
{
    u32 hasRibbons;
    struct BoxPokemonBlockA *blockA;
    struct BoxPokemonBlockB *blockB;
    struct BoxPokemonBlockC *blockC;

    POKE_TOOL_DecodeCalcBlock((struct PokemonParam *)box);
    hasRibbons = 0;
    blockA = POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_A);
    blockB = POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_B);
    blockC = POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_C);
    if (blockA->sinnohRibbons != 0 || blockB->hoennRibbons != 0 || blockC->contestRibbons != 0) {
        hasRibbons = 1;
    }
    POKE_TOOL_EncodeCalcBlock((struct PokemonParam *)box);
    return hasRibbons;
}


int POKE_TOOL_GetNatureStatMod(struct BoxPokemon *box, int stat)
{
    return POKE_TOOL_GetBoxNatureStatMod(box, stat);
}


s8 POKE_TOOL_GetBoxNatureStatMod(struct BoxPokemon *box, u32 stat)
{
    return POKE_TOOL_GetNatureStatModByNature((u8)POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_NATURE, 0), stat);
}


/*
 * The nature table lookup: a signed byte out of the s8[25][5] table at
 * 0x0209E2A4 (row = nature, column = stat).  POKE_TOOL_GetBoxNatureStatMod is the one
 * caller, and it truncates the nature to u8 at the call.  Wave 11,
 * 2026-09-23.
 *
 * Closes the "one byte the language cannot express" of
 * docs/notes/POKE_TOOL_GetNatureStatModByNature.c.txt: earlier lanes read the SECOND argument as
 * a base pointer (`b[o + (u32)tbl]`), which makes the scaled index the
 * running operand of the final add.  It is an integer column index and the
 * natural two-dimensional subscript gives the image's `adds r0, r0, r2`
 * (table as accumulator) directly.
 */
s8 POKE_TOOL_GetNatureStatModByNature(u8 nature, u32 stat)
{
    return sNatureStatMods[nature][stat];
}


/*
 * The two functions after src/matched/unit_020188B4.c and the three that its
 * header records as a near miss.  POKE_TOOL_SetAbility is the eight byte
 * `ldr r3, [pc, #0]; bx r3` tail call that
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes; its callee is the
 * next function in this same range, so the site is the `local` class.
 */
void POKE_TOOL_SetAbility(struct BoxPokemon *box, u32 species, u32 form)
{
    POKE_TOOL_SetBoxAbility(box, species, form);
}


void POKE_TOOL_SetBoxAbility(struct BoxPokemon *box, u32 species, u32 form)
{
    struct PersonalData *personal;
    u32 personality;
    u32 abilitySlot;
    u32 hiddenAbility;

    hiddenAbility = POKE_TOOL_GetPersonalParam((u16)species, (u16)form, 0x1C);
    if (hiddenAbility != 0) {
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_ABILITY, hiddenAbility);
        POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_HIDDEN_ABILITY, 1);
        return;
    }
    personal = POKE_TOOL_GetPersonalData((u16)species, (u16)form);
    personality = POKE_TOOL_GetBoxValue(box, POKE_TOOL_PARAM_PERSONALITY, 0);
    abilitySlot = 0x1A;
    if (POKE_TOOL_GetPersonalGender(personal) == 2 && (personality & (1 << 16))) {
        abilitySlot = 0x1B;
    }
    POKE_TOOL_SetBoxValue(box, POKE_TOOL_PARAM_ABILITY, POKE_PERSONAL_GetParam(personal, abilitySlot));
}


/*
 * 660 bytes, one function, no jump table.
 *
 * The six-stat recalculation of poke_tool.c, and the only thing in the region
 * that reads and writes the record through both halves of the dispatcher
 * quartet at once.  It takes no arguments but the record pointer: everything
 * it needs is read back through POKE_TOOL_GetPartyValue (src/matched/unit_02017E1C.c)
 * and everything it produces is written through POKE_TOOL_SetPartyValue
 * (src/matched/unit_02017E40.c), so the whole function is seventeen reads, a
 * base-stat table lookup, six formulas and six writes.
 *
 * Its single caller is POKE_TOOL_RecalcParam (src/pending/unit_020185C4.c), which was
 * MATCH-capped on exactly this address; with this entry EXACT the `matched`
 * class carries that site and the parked file graduates.
 *
 * ---------------------------------------------------------------------------
 * THE IDS, AND WHERE THE FIELD MAP FOR THEM IS
 * ---------------------------------------------------------------------------
 * The party-area ids are POKE_TOOL_GetPartyValueRaw's (src/matched/POKE_TOOL_GetPartyValueRaw.c) and the
 * block-area ids are POKE_TOOL_GetBoxValueRaw's (src/pending/POKE_TOOL_GetBoxValueRaw.c, whose header
 * carries the full map).  What this function uses:
 *
 *   read  0x9E  level          0xA1  current max HP   0xA0  current HP
 *   read  0x46..0x4B           the six 5 bit IVs, in stat order
 *   read  0x0D..0x12           the six effort values, capped at 510 together
 *   read  0x6F  form           0x05  species
 *   write 0xA1  max HP
 *   write 0xA2..0xA6           attack, defence, speed, sp. attack, sp. defence
 *   write 0xA0  current HP, and only when the result is non zero
 *
 * POKE_TOOL_GetPersonalData(species, form) returns the species' base-stat record and the
 * first six bytes of it are the six base stats, indexed here in the same order
 * the ids are: HP, attack, defence, speed, sp. attack, sp. defence.  The
 * nature multiplier POKE_TOOL_ApplyNatureModifier (src/matched/unit_02019B04.c) is indexed
 * differently, 1, 2, 5, 3, 4 for that same sequence, so its table is in
 * attack, defence, sp. attack, sp. defence, speed order.  That permutation is
 * in the game and not in this reconstruction; the two orderings are visible
 * side by side in the five `movs r2, #k` immediates.
 *
 * The formulas are the ordinary third-generation-onwards ones, in signed
 * arithmetic throughout (the divides are `_s32_div_f`, and `ev / 4` carries
 * the rounding correction a signed shift needs):
 *
 *   max HP = (base * 2 + iv + ev / 4) * level / 100 + level + 10
 *   stat   = ((base * 2 + iv + ev / 4) * level / 100 + 5) scaled by nature
 *
 * Species 292 is the exception: its max HP is 1 and its current HP is 1,
 * whatever its level, IVs or EVs are.  The constant appears twice and the
 * compiler materialises it two different ways, `0x6F + 0xB5` off the id
 * constant that is still live from the id 0x6F read, and `0x49 << 2` in the
 * tail where nothing is live; both are written `292` in the source.
 *
 * ---------------------------------------------------------------------------
 * THE THREE THINGS THAT COST THE MOST TIME
 * ---------------------------------------------------------------------------
 * **The nature multiplier's first argument is a named local.**  Written
 * inline, `POKE_TOOL_ApplyNatureModifier(POKE_TOOL_GetNature(p), (u16)stat, k)`, the first three
 * stats are byte for byte right and the last two are not: the compiler hoists
 * the `bl POKE_TOOL_GetNature` in front of the arithmetic, which costs the `adds r5,
 * r0, #5` its fold and adds three instructions per stat, twelve bytes and 203
 * concrete bytes in total.  Binding the call result to a local before the
 * outer call, `nature = POKE_TOOL_GetNature(p);`, pins the evaluation order for all
 * five and is EXACT.  This is the store form of
 * docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md
 * seen at an argument rather than at a field, and the new file
 * docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md
 * records it, because the asymmetry (three sites right, two wrong, from one
 * source shape) is what makes it expensive to read back.
 *
 * **The named local also decides the two callee-saved registers.**  With the
 * call inline, level lands in r7 and the current HP in r6; with `nature`
 * bound, they are the original's r6 and r7.  Nothing about the register
 * numbering points at the argument that caused it.
 *
 * **Max HP is two statements, not one.**  The original stores the running
 * value into the max-HP slot, adds ten, and stores it again; the dead first
 * store is what says the source wrote `newMax = ... + level;` and then
 * `newMax = newMax + 10;`.  Written as one expression the `+ 10` folds into
 * the same instruction stream, the first `str` disappears, and the species 292
 * arm's `b` then cross-jumps onto a different store.
 *
 * The five IVs and five EVs that reach the stack are grouped, all five IVs at
 * sp+0x30 down to sp+0x20 and then all five EVs at sp+0x1C down to sp+0x0C,
 * which is what says they were declared in two runs rather than interleaved in
 * the order they are read; declared read-interleaved every slot is right by
 * four bytes and nothing else moves.  See
 * docs/idioms/local-declaration-order-is-stack-order.md.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * One content id: 292, the species whose max HP is forced to 1.  It appears
 * twice, at the max-HP branch and in the current-HP tail.  Black and White
 * share their species numbering, so it is expected to be identical in IRAO,
 * but it is the one number to re-read.  Everything else here is a structure
 * offset, a stat index or a formula constant (2, 4, 100, 5, 10), and the stat
 * formulas themselves are content in the sense that they decide the game's
 * numbers: if a White build ever diverges here, it diverges on 292 or on the
 * base-stat table POKE_TOOL_GetPersonalData hands back, not on this code.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_CalcParam.c \
 *       --func POKE_TOOL_CalcParam --addr 0x02018A7C --cc 1.1p1
 */
void POKE_TOOL_CalcParam(struct PokemonParam *pp)
{
    s32 hp;
    s32 level;
    s32 form;
    s32 ivHp;
    s32 oldMaxHp;
    s32 ivAttack;
    s32 ivDefense;
    s32 ivSpeed;
    s32 ivSpAttack;
    s32 ivSpDefense;
    s32 evAttack;
    s32 evDefense;
    s32 evSpeed;
    s32 evSpAttack;
    s32 evSpDefense;
    s32 species;
    const struct PersonalData *base;
    s32 maxHp;
    s32 evHp;
    s32 stat;
    u32 nature;
    s32 maxHpDelta;

    level = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_LEVEL, 0);
    oldMaxHp = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_MAX_HP, 0);
    hp = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_HP, 0);
    ivHp = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_HP, 0);
    evHp = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_EV_HP, 0);
    ivAttack = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_ATTACK, 0);
    evAttack = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_EV_ATTACK, 0);
    ivDefense = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_DEFENSE, 0);
    evDefense = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_EV_DEFENSE, 0);
    ivSpeed = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_SPEED, 0);
    evSpeed = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_EV_SPEED, 0);
    ivSpAttack = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_SP_ATTACK, 0);
    evSpAttack = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_EV_SP_ATTACK, 0);
    ivSpDefense = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_IV_SP_DEFENSE, 0);
    evSpDefense = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_EV_SP_DEFENSE, 0);
    form = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_FORM, 0);
    species = POKE_TOOL_GetPartyValue(pp, POKE_TOOL_PARAM_SPECIES, 0);
    base = POKE_TOOL_GetPersonalData((u16)species, (u16)form);

    if (species == 292) {
        maxHp = 1;
    } else {
        maxHp = (base->baseHp * 2 + ivHp + evHp / 4) * level / 100 + level;
        maxHp = maxHp + 10;
    }
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_MAX_HP, maxHp);

    stat = (base->baseAttack * 2 + ivAttack + evAttack / 4) * level / 100 + 5;
    nature = POKE_TOOL_GetNature(pp);
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_ATTACK, POKE_TOOL_ApplyNatureModifier(nature, (u16)stat, 1));

    stat = (base->baseDefense * 2 + ivDefense + evDefense / 4) * level / 100 + 5;
    nature = POKE_TOOL_GetNature(pp);
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_DEFENSE, POKE_TOOL_ApplyNatureModifier(nature, (u16)stat, 2));

    stat = (base->baseSpeed * 2 + ivSpeed + evSpeed / 4) * level / 100 + 5;
    nature = POKE_TOOL_GetNature(pp);
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_SPEED, POKE_TOOL_ApplyNatureModifier(nature, (u16)stat, 5));

    stat = (base->baseSpAttack * 2 + ivSpAttack + evSpAttack / 4) * level / 100 + 5;
    nature = POKE_TOOL_GetNature(pp);
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_SP_ATTACK, POKE_TOOL_ApplyNatureModifier(nature, (u16)stat, 3));

    stat = (base->baseSpDefense * 2 + ivSpDefense + evSpDefense / 4) * level / 100 + 5;
    nature = POKE_TOOL_GetNature(pp);
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_SP_DEFENSE, POKE_TOOL_ApplyNatureModifier(nature, (u16)stat, 4));

    if (hp != 0 || oldMaxHp == 0) {
        if (species == 292) {
            hp = 1;
        } else if (hp == 0) {
            hp = maxHp;
        } else {
            maxHpDelta = maxHp - oldMaxHp;
            if (maxHpDelta < 0) {
                if (hp > maxHp) {
                    hp = maxHp;
                }
            } else {
                hp = hp + maxHpDelta;
            }
        }
    }
    if (hp != 0) {
        POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_HP, hp);
    }
}


/*
 * The four lock/unlock helpers every accessor wrapper in this region opens and
 * closes with.  The object is the same record as src/matched/unit_02017D30.c:
 * a seed word at +0x00, three flag bits at +0x04, a halfword checksum at
 * +0x06, an 0x80 byte area at +0x08 and a 0x54 byte area at +0x88, each
 * area XOR masked in place by POKE_CRYPTO_XorBlock.  Bit 2 of +0x04 is the sticky
 * "checksum did not match" flag POKE_TOOL_DecodeBoxBlock sets.
 *
 * The three flag tests are `lsls`/`lsrs` pairs of width one, which is the
 * bitfield shape of docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md;
 * spelling them as masks gives movs/ands instead.
 */
u32 POKE_TOOL_DecodeCalcBlock(struct PokemonParam *pp)
{
    u32 ok = 1;

    if (pp->box.partyDecoded == 0) {
        POKE_CRYPTO_XorBlock((u16 *)&pp->statusCondition, 0x54, pp->box.personality);
        ok = POKE_TOOL_DecodeBoxBlock(&pp->box);
    }
    return ok;
}


u32 POKE_TOOL_DecodeBoxBlock(struct BoxPokemon *box)
{
    u32 ok = 1;
    u16 sum;

    if (box->boxDecoded == 0) {
        POKE_CRYPTO_XorBlock((u16 *)box->blocks, 0x80, box->checksum);
        sum = POKE_CRYPTO_Checksum((const u16 *)box->blocks, 0x80);
        if (sum != box->checksum) {
            ok = 0;
            box->checksumFailed = 1;
        }
    }
    return ok;
}


void POKE_TOOL_EncodeCalcBlock(struct PokemonParam *pp)
{
    if (pp->box.partyDecoded == 0) {
        POKE_CRYPTO_XorBlock((u16 *)&pp->statusCondition, 0x54, pp->box.personality);
        POKE_TOOL_EncodeBoxBlock(&pp->box);
    }
}


void POKE_TOOL_EncodeBoxBlock(struct BoxPokemon *box)
{
    if (box->boxDecoded == 0) {
        box->checksum = POKE_CRYPTO_Checksum((const u16 *)box->blocks, 0x80);
        POKE_CRYPTO_XorBlock((u16 *)box->blocks, 0x80, box->checksum);
    }
}


/*
 * The party-data half of the record's read accessor, and the outer half of the
 * get/set dispatcher quartet of poke_tool.c.  The record is the 0xDC byte
 * structure src/matched/unit_02017D30.c and src/matched/unit_02018D10.c
 * describe: a seed word at +0x00, three flag bits and a checksum at +0x04, an
 * 0x80 byte XOR masked block area at +0x08 and an 0x54 byte XOR masked party
 * area at +0x88.  This function owns the twelve ids that live in the party
 * area, 0x9D to 0xA8, and tail calls POKE_TOOL_GetBoxValueRaw for everything else, which
 * is the 176 case accessor over the block area (src/pending/POKE_TOOL_GetBoxValueRaw.c).
 *
 * The twelve ids are a dense switch from 0x9D, so the `cmp r3, #0xb` / `bhi` /
 * `add pc, r3` preamble and the twelve halfword table come out of a plain C
 * switch; see docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 * Only 0xA7 and 0xA8 have bodies that are not a field load: 0xA7 copies the
 * 0x38 byte object at +0x9C out through the third argument with
 * MAIL_Copy (the same whole-object copy src/matched/unit_02008F80.c
 * describes), and 0xA8 returns 1 with no field at all.  Both return 1 out of
 * their own `movs r0, #1` / `pop`, not a shared one.
 *
 * The setter half is POKE_TOOL_SetPartyValueRaw, src/matched/POKE_TOOL_SetPartyValueRaw.c, which has the
 * same twelve ids in the same order over the same offsets.
 *
 * Nothing here is version specific: the ids are structure offsets, not species
 * or version tables.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_GetPartyValueRaw.c \
 *       --func POKE_TOOL_GetPartyValueRaw --addr 0x02018DB4 --cc 1.1p1
 */
u32 POKE_TOOL_GetPartyValueRaw(struct PokemonParam *pp, u32 paramId, u32 arg)
{
    switch (paramId) {
    case POKE_TOOL_PARAM_STATUS_CONDITION: return pp->statusCondition;
    case POKE_TOOL_PARAM_LEVEL: return pp->level;
    case POKE_TOOL_PARAM_CAPSULE_INDEX: return pp->capsuleIndex;
    case POKE_TOOL_PARAM_HP: return pp->hp;
    case POKE_TOOL_PARAM_MAX_HP: return pp->maxHp;
    case POKE_TOOL_PARAM_ATTACK: return pp->attack;
    case POKE_TOOL_PARAM_DEFENSE: return pp->defense;
    case POKE_TOOL_PARAM_SPEED: return pp->speed;
    case POKE_TOOL_PARAM_SP_ATTACK: return pp->spAttack;
    case POKE_TOOL_PARAM_SP_DEFENSE: return pp->spDefense;
    case POKE_TOOL_PARAM_MAIL:
        MAIL_Copy(&pp->mail, (struct Mail *)arg);
        return 1;
    case POKE_TOOL_PARAM_NO_DATA:
        return 1;
    }
    return POKE_TOOL_GetBoxValueRaw(&pp->box, paramId, arg);
}


/*
 * 1236 bytes, one function, a 176 case jump table.  The read accessor over
 * the encrypted block area of the 0xDC byte record, and the larger half of
 * poke_tool.c's get/set dispatcher quartet.  POKE_TOOL_GetPartyValueRaw
 * (src/matched/POKE_TOOL_GetPartyValueRaw.c) owns ids 0x9D to 0xA8 and forwards everything
 * else here; the writer twin is POKE_TOOL_SetBoxValueRaw (src/matched/POKE_TOOL_SetBoxValueRaw.c).
 *
 * Of the eighteen relocation sites, three are calls to 0x0209C074 (_ll_shl,
 * the compiler's own 64 bit shift helper) and one is to POKE_TOOL_GetPlateType; a scan
 * of every Thumb BL and BLX in the image finds those four sites and no
 * others, all four inside this one function, so neither the `label` nor
 * `matched` class alone ever had an outside witness for both.  POKE_TOOL_GetPlateType
 * resolves via the `matched` class (src/matched/unit_02019B58.c, an EXACT
 * entry proved over a range this file does not touch); 0x0209C074 resolves
 * via the `runtime` class, layout/runtime_arm9.txt's curated identification
 * of the MSL/runtime.a routines mwccarm links in, which carries the same
 * evidentiary standing as an SDK symbol without needing a label or an
 * outside call.  See docs/AGENT-BRIEF.md's attestation section.
 *
 * ---------------------------------------------------------------------------
 * THE FIELD MAP
 * ---------------------------------------------------------------------------
 * POKE_TOOL_GetBoxSubstruct(box, box->personality, n) returns the n-th of four 0x20 byte substructs
 * inside the 0x80 byte block area at +0x08, permuted by the seed word; so the
 * four pointers blockA, blockB, blockC, blockD below are the substructs and every id is one field
 * of one of them.  Ids not listed fall to `default` and read back 0.
 *
 *   id         where                       what the code does
 *   0x00       record +0x00 u32            the seed word
 *   0x01/02/03 record +0x04 bits 0/1/2     the three lock flags
 *   0x04       record +0x06 u16            the block-area checksum
 *   0x05       A +0x00 u16                 species; 650 when flag bit 2 is set
 *   0x06       A +0x02 u16                 held item; 0 when above 626
 *   0x07       A +0x04 u32
 *   0x08       A +0x08 u32                 experience
 *   0x09       A +0x0C u8
 *   0x0A       A +0x0D u8                  ability (see 0xAE below)
 *   0x0B       A +0x0E u8
 *   0x0C       A +0x0F u8
 *   0x0D..0x12 A +0x10..0x15 u8 x6         the six the setter caps at 510 total
 *   0x13..0x18 A +0x16..0x1B u8 x6
 *   0x19..0x35 A +0x1C u32                 29 flag bits, bit (id - 0x19)
 *   0x36..0x39 B +0x00 u16[4]
 *   0x3A..0x3D B +0x08 u8[4]
 *   0x3E..0x41 B +0x0C u8[4]
 *   0x42..0x45 derived                     WAZA_TOOL_GetMaxPP(B move[i], B +0x0C[i])
 *                                          when the move is non zero, else 0
 *   0x46..0x4B B +0x10 bits 0..29          six 5 bit fields
 *   0x4C       B +0x10 bit 30              1 when flag bit 2 is set
 *   0x4D..0x6C B +0x14 u32                 32 flag bits, bit (id - 0x4D)
 *   0x6D       B +0x18 bit 0
 *   0x6E       derived, and it WRITES      POKE_TOOL_CalcGender(species, form, seed),
 *                                          stored into B +0x18 bits 1..2, then
 *                                          the block-area checksum is recomputed
 *   0x6F       B +0x18 bits 3..7           form
 *   0x70       B +0x19 u8
 *   0x71       B +0x1A bit 0
 *   0x72       B +0x1C u32
 *   0x73       C +0x00                     copied out through the third
 *                                          argument, or the id 651 string from
 *                                          the bank at 0x020A7370 when flag
 *                                          bit 2 is set
 *   0x74       C +0x00                     the same, length 11
 *   0x75       B +0x10 bit 31
 *   0x76       C +0x16 u8
 *   0x77       C +0x17 u8
 *   0x78..0x8C C +0x18 u64                 21 flag bits, bit (id - 0x78)
 *   0x8D/0x8E  D +0x00                     copied out, length 8 for 0x8E
 *   0x8F..0x94 D +0x10..0x15 u8 x6
 *   0x95       D +0x16 u16
 *   0x96       D +0x18 u16
 *   0x97       D +0x1A u8
 *   0x98       D +0x1B u8
 *   0x99       D +0x1C bits 0..6
 *   0x9A       D +0x1C bit 7
 *   0x9B       D +0x1D u8
 *   0x9C       D +0x1E u16
 *   0x9E       derived                     POKE_TOOL_CalcLevelFromExp(species, form, exp)
 *   0x9D, 0x9F..0xA8                       gaps here; the party area, owned by
 *                                          POKE_TOOL_GetPartyValueRaw
 *   0xA9       derived                     species != 0
 *   0xAA       derived                     flag bit 2, else B +0x10 bit 30
 *   0xAB       derived                     species, or 650 when it is an egg
 *                                          or flag bit 2 is set
 *   0xAC       derived                     B +0x10 bits 0..29 repacked
 *   0xAD       derived                     0 for species 29 or 32 with
 *                                          B +0x10 bit 31 clear, else 1
 *   0xAE/0xAF  derived                     POKE_TOOL_GetPlateType(item) for species 493
 *                                          with A +0x0D == 121, otherwise
 *                                          POKE_TOOL_GetPersonalParam(species, form,
 *                                          id - 0xA8)
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Six numeric constants in this function are content ids rather than structure
 * offsets, and they are the only things here that could differ between the two
 * paired versions: 650 (ids 0x05 and 0xAB), 651 (the string id for ids 0x73
 * and 0x74), 626 (the item ceiling for id 0x06), 493 and 121 (the species and
 * ability that select the item-derived type at ids 0xAE and 0xAF) and 29 and
 * 32 (the two species id 0xAD special cases).  There is no
 * version-exclusive-species table and no version flag anywhere in this
 * function; Black and White share their species, item and ability numbering,
 * so all six are expected to be identical in IRAO, but they are the addresses
 * to re-read first if a White build diverges here.  The message bank pointer
 * at 0x020A7370 is a global, so its address will differ between builds and
 * must be re-derived rather than copied.
 *
 * ---------------------------------------------------------------------------
 * WHAT PINNED THE SOURCE
 * ---------------------------------------------------------------------------
 * The 176 entry halfword table is read as
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md: the entries
 * that point at the default body are the ids with no case label, and the
 * addresses the other entries point at, sorted, are the source order of the
 * arms.  That order is not the numeric order and reconstructing it is most of
 * the work: the switch opens with `default`, then 0x00 to 0x04, then 0xA9,
 * 0xAA, 0xAB and 0x9E, and only then 0x05 onwards, with 0x75 sitting between
 * 0x4C and the 0x4D group.  Writing the arms in numeric order instead is a
 * whole-function diff with the size still exactly right.
 *
 * Three further details each cost bytes:
 *
 *   * `u32 r = 0;` has to be declared before the four substruct calls and
 *     `u32 ok = 1;` after them.  The original's `movs r4, #0` sits in front of
 *     the first call and its `str r2, [sp, #8]` just after it, and the two
 *     stack slots are assigned in that declaration order, which is
 *     docs/idioms/local-declaration-order-is-stack-order.md.
 *   * `default:` has to be the first arm written, not a statement after the
 *     switch.  Written after the switch its block lands at the end and all 176
 *     displacements move.
 *   * ids POKE_TOOL_PARAM_IS_EGG (0x4C) and POKE_TOOL_PARAM_IS_EGG_CHECKED (0xAA) are the same two-line test and both have to be written
 *     `r = box->checksumFailed; if (r == 0) { r = blockB->isEgg; }`, so that the flag bit lands
 *     directly in the result register.  Written as
 *     `if (box->checksumFailed != 0) { r = 1; } else { r = blockB->isEgg; }` the compiler computes
 *     the bit into a scratch register and 0x4C loses the two byte `b` to the
 *     shared exit that id 0x42's `beq` needs to reach, which turns that `beq`
 *     into a `bne` plus a long `b` and shifts everything after it by two.
 *
 * The three 64 bit flag-bit tests are one shape: `((u64)ok << n) & field`,
 * with the field zero extended, compared against zero in 64 bits.  The u64 is
 * what calls 0x0209C074 (_ll_shl).
 *
 * Verified with
 *   python tools/match.py one --src src/pending/POKE_TOOL_GetBoxValueRaw.c \
 *       --func POKE_TOOL_GetBoxValueRaw --addr 0x02018E34 --cc 1.1p1
 */
u32 POKE_TOOL_GetBoxValueRaw(struct BoxPokemon *box, u32 paramId, u32 arg)
{
    u32 result = 0;
    struct BoxPokemonBlockA *blockA = (struct BoxPokemonBlockA *)POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_A);
    struct BoxPokemonBlockB *blockB = (struct BoxPokemonBlockB *)POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_B);
    struct BoxPokemonBlockC *blockC = (struct BoxPokemonBlockC *)POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_C);
    struct BoxPokemonBlockD *blockD = (struct BoxPokemonBlockD *)POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_D);
    u32 flag = 1;

    switch (paramId) {
    default:
        result = 0;
        break;
    case POKE_TOOL_PARAM_PERSONALITY: result = box->personality; break;
    case POKE_TOOL_PARAM_PARTY_DECODED: result = box->partyDecoded; break;
    case POKE_TOOL_PARAM_BOX_DECODED: result = box->boxDecoded; break;
    case POKE_TOOL_PARAM_CHECKSUM_FAILED: result = box->checksumFailed; break;
    case POKE_TOOL_PARAM_CHECKSUM: result = box->checksum; break;
    case POKE_TOOL_PARAM_SPECIES_EXISTS:
        if (blockA->species == 0) {
            flag = 0;
        }
        result = flag;
        break;
    case POKE_TOOL_PARAM_IS_EGG_CHECKED:
        result = box->checksumFailed;
        if (result == 0) {
            result = blockB->isEgg;
        }
        break;
    case POKE_TOOL_PARAM_SPECIES_OR_EGG:
        result = blockA->species;
        if (result != 0) {
            if (blockB->isEgg != 0 || box->checksumFailed != 0) {
                result = 650;
            }
        }
        break;
    case POKE_TOOL_PARAM_LEVEL:
        result = POKE_TOOL_CalcLevelFromExp(blockA->species, blockB->form, blockA->exp);
        break;
    case POKE_TOOL_PARAM_SPECIES:
        if (box->checksumFailed != 0) {
            result = 650;
        } else {
            result = blockA->species;
        }
        break;
    case POKE_TOOL_PARAM_HELD_ITEM:
        result = blockA->heldItem;
        if (result > 626) {
            result = 0;
        }
        break;
    case POKE_TOOL_PARAM_OT_ID: result = blockA->otId; break;
    case POKE_TOOL_PARAM_EXP: result = blockA->exp; break;
    case POKE_TOOL_PARAM_FRIENDSHIP: result = blockA->friendship; break;
    case POKE_TOOL_PARAM_ABILITY: result = blockA->ability; break;
    case POKE_TOOL_PARAM_MARKINGS: result = blockA->markings; break;
    case POKE_TOOL_PARAM_LANGUAGE: result = blockA->language; break;
    case POKE_TOOL_PARAM_EV_HP: result = blockA->evs[0]; break;
    case POKE_TOOL_PARAM_EV_ATTACK: result = blockA->evs[1]; break;
    case POKE_TOOL_PARAM_EV_DEFENSE: result = blockA->evs[2]; break;
    case POKE_TOOL_PARAM_EV_SPEED: result = blockA->evs[3]; break;
    case POKE_TOOL_PARAM_EV_SP_ATTACK: result = blockA->evs[4]; break;
    case POKE_TOOL_PARAM_EV_SP_DEFENSE: result = blockA->evs[5]; break;
    case POKE_TOOL_PARAM_CONTEST_COOL: result = blockA->contestStats[0]; break;
    case POKE_TOOL_PARAM_CONTEST_BEAUTY: result = blockA->contestStats[1]; break;
    case POKE_TOOL_PARAM_CONTEST_CUTE: result = blockA->contestStats[2]; break;
    case POKE_TOOL_PARAM_CONTEST_SMART: result = blockA->contestStats[3]; break;
    case POKE_TOOL_PARAM_CONTEST_TOUGH: result = blockA->contestStats[4]; break;
    case POKE_TOOL_PARAM_CONTEST_SHEEN: result = blockA->contestStats[5]; break;
    case POKE_TOOL_PARAM_RIBBON_SINNOH_CHAMPION: case POKE_TOOL_PARAM_RIBBON_SINNOH_ABILITY:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_GREAT_ABILITY: case POKE_TOOL_PARAM_RIBBON_SINNOH_DOUBLE_ABILITY:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_MULTI_ABILITY: case POKE_TOOL_PARAM_RIBBON_SINNOH_PAIR_ABILITY:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_WORLD_ABILITY: case POKE_TOOL_PARAM_RIBBON_SINNOH_ALERT:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_SHOCK: case POKE_TOOL_PARAM_RIBBON_SINNOH_DOWNCAST:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_CAREFUL: case POKE_TOOL_PARAM_RIBBON_SINNOH_RELAX:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_SNOOZE: case POKE_TOOL_PARAM_RIBBON_SINNOH_SMILE:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_GORGEOUS: case POKE_TOOL_PARAM_RIBBON_SINNOH_ROYAL:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_GORGEOUS_ROYAL: case POKE_TOOL_PARAM_RIBBON_SINNOH_ARTIST:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_FOOTPRINT: case POKE_TOOL_PARAM_RIBBON_SINNOH_RECORD:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_HISTORY: case POKE_TOOL_PARAM_RIBBON_SINNOH_LEGEND:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_RED: case POKE_TOOL_PARAM_RIBBON_SINNOH_GREEN:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_BLUE: case POKE_TOOL_PARAM_RIBBON_SINNOH_FESTIVAL:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_CARNIVAL: case POKE_TOOL_PARAM_RIBBON_SINNOH_CLASSIC:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_PREMIER:
        paramId -= POKE_TOOL_PARAM_RIBBON_SINNOH_FIRST;
        if ((((u64)flag << paramId) & blockA->sinnohRibbons) == 0) {
            flag = 0;
        }
        result = flag;
        break;
    case POKE_TOOL_PARAM_MOVE1: case POKE_TOOL_PARAM_MOVE2: case POKE_TOOL_PARAM_MOVE3: case POKE_TOOL_PARAM_MOVE4:
        paramId -= POKE_TOOL_PARAM_MOVE1;
        result = blockB->moves[paramId];
        break;
    case POKE_TOOL_PARAM_PP1: case POKE_TOOL_PARAM_PP2: case POKE_TOOL_PARAM_PP3: case POKE_TOOL_PARAM_PP4:
        paramId -= POKE_TOOL_PARAM_PP1;
        result = blockB->pp[paramId];
        break;
    case POKE_TOOL_PARAM_PP_UP1: case POKE_TOOL_PARAM_PP_UP2: case POKE_TOOL_PARAM_PP_UP3: case POKE_TOOL_PARAM_PP_UP4:
        paramId -= POKE_TOOL_PARAM_PP_UP1;
        result = blockB->ppUps[paramId];
        break;
    case POKE_TOOL_PARAM_MAX_PP1: case POKE_TOOL_PARAM_MAX_PP2: case POKE_TOOL_PARAM_MAX_PP3: case POKE_TOOL_PARAM_MAX_PP4:
        paramId -= POKE_TOOL_PARAM_MAX_PP1;
        if (blockB->moves[paramId] != 0) {
            result = WAZA_TOOL_GetMaxPP(blockB->moves[paramId], blockB->ppUps[paramId]);
        }
        break;
    case POKE_TOOL_PARAM_IV_HP: result = blockB->ivHp; break;
    case POKE_TOOL_PARAM_IV_ATTACK: result = blockB->ivAttack; break;
    case POKE_TOOL_PARAM_IV_DEFENSE: result = blockB->ivDefense; break;
    case POKE_TOOL_PARAM_IV_SPEED: result = blockB->ivSpeed; break;
    case POKE_TOOL_PARAM_IV_SP_ATTACK: result = blockB->ivSpAttack; break;
    case POKE_TOOL_PARAM_IV_SP_DEFENSE: result = blockB->ivSpDefense; break;
    case POKE_TOOL_PARAM_IS_EGG:
        result = box->checksumFailed;
        if (result == 0) {
            result = blockB->isEgg;
        }
        break;
    case POKE_TOOL_PARAM_HAS_NICKNAME: result = blockB->hasNickname; break;
    case POKE_TOOL_PARAM_RIBBON_HOENN_COOL: case POKE_TOOL_PARAM_RIBBON_HOENN_COOL_SUPER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_COOL_HYPER: case POKE_TOOL_PARAM_RIBBON_HOENN_COOL_MASTER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY: case POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY_SUPER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY_HYPER: case POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY_MASTER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_CUTE: case POKE_TOOL_PARAM_RIBBON_HOENN_CUTE_SUPER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_CUTE_HYPER: case POKE_TOOL_PARAM_RIBBON_HOENN_CUTE_MASTER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_SMART: case POKE_TOOL_PARAM_RIBBON_HOENN_SMART_SUPER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_SMART_HYPER: case POKE_TOOL_PARAM_RIBBON_HOENN_SMART_MASTER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH: case POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH_SUPER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH_HYPER: case POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH_MASTER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_CHAMPION: case POKE_TOOL_PARAM_RIBBON_HOENN_WINNING:
    case POKE_TOOL_PARAM_RIBBON_HOENN_VICTORY: case POKE_TOOL_PARAM_RIBBON_HOENN_ARTIST:
    case POKE_TOOL_PARAM_RIBBON_HOENN_EFFORT: case POKE_TOOL_PARAM_RIBBON_HOENN_MARINE:
    case POKE_TOOL_PARAM_RIBBON_HOENN_LAND: case POKE_TOOL_PARAM_RIBBON_HOENN_SKY:
    case POKE_TOOL_PARAM_RIBBON_HOENN_COUNTRY: case POKE_TOOL_PARAM_RIBBON_HOENN_NATIONAL:
    case POKE_TOOL_PARAM_RIBBON_HOENN_EARTH: case POKE_TOOL_PARAM_RIBBON_HOENN_WORLD:
        paramId -= POKE_TOOL_PARAM_RIBBON_HOENN_FIRST;
        if ((((u64)flag << paramId) & blockB->hoennRibbons) == 0) {
            flag = 0;
        }
        result = flag;
        break;
    case POKE_TOOL_PARAM_FATEFUL_ENCOUNTER: result = blockB->fatefulEncounter; break;
    case POKE_TOOL_PARAM_GENDER:
        result = POKE_TOOL_CalcGender(blockA->species, blockB->form, box->personality);
        blockB->gender = (u8)result;
        box->checksum = POKE_CRYPTO_Checksum((const u16 *)box->blocks, 0x80);
        break;
    case POKE_TOOL_PARAM_FORM: result = blockB->form; break;
    case POKE_TOOL_PARAM_NATURE: result = blockB->nature; break;
    case POKE_TOOL_PARAM_HIDDEN_ABILITY: result = blockB->hasHiddenAbility; break;
    case POKE_TOOL_PARAM_SPARE_WORD: result = blockB->spareWord; break;
    case POKE_TOOL_PARAM_NICKNAME_STRBUF:
        if (box->checksumFailed != 0) {
            MSGDATA_ReadString(gSpeciesNameBank, 651, (struct Strbuf *)arg);
        } else {
            STRBUF_SetString((struct Strbuf *)arg, blockC->nickname);
        }
        break;
    case POKE_TOOL_PARAM_NICKNAME:
        if (box->checksumFailed != 0) {
            MSGDATA_ReadUnits(gSpeciesNameBank, 651, (u16 *)arg, 11);
        } else {
            WORDSET_CopyString(blockC->nickname, (u16 *)arg, 11);
        }
        break;
    case POKE_TOOL_PARAM_SPARE_BYTE: result = blockC->spareByte; break;
    case POKE_TOOL_PARAM_ORIGIN_GAME: result = blockC->originGame; break;
    case POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_NORMAL: case POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_GREAT:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_ULTRA: case POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_MASTER:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_NORMAL: case POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_GREAT:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_ULTRA: case POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_MASTER:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_NORMAL: case POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_GREAT:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_ULTRA: case POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_MASTER:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_NORMAL: case POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_GREAT:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_ULTRA: case POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_MASTER:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_NORMAL: case POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_GREAT:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_ULTRA: case POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_MASTER:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_EXTRA:
        paramId -= POKE_TOOL_PARAM_RIBBON_CONTEST_FIRST;
        if ((((u64)flag << paramId) & blockC->contestRibbons) == 0) {
            flag = 0;
        }
        result = flag;
        break;
    case POKE_TOOL_PARAM_OT_NAME_STRBUF:
        STRBUF_SetString((struct Strbuf *)arg, blockD->otName);
        break;
    case POKE_TOOL_PARAM_OT_NAME:
        WORDSET_CopyString(blockD->otName, (u16 *)arg, 8);
        break;
    case POKE_TOOL_PARAM_EGG_YEAR: result = blockD->eggYear; break;
    case POKE_TOOL_PARAM_EGG_MONTH: result = blockD->eggMonth; break;
    case POKE_TOOL_PARAM_EGG_DAY: result = blockD->eggDay; break;
    case POKE_TOOL_PARAM_MET_YEAR: result = blockD->metYear; break;
    case POKE_TOOL_PARAM_MET_MONTH: result = blockD->metMonth; break;
    case POKE_TOOL_PARAM_MET_DAY: result = blockD->metDay; break;
    case POKE_TOOL_PARAM_EGG_LOCATION: result = blockD->eggLocation; break;
    case POKE_TOOL_PARAM_MET_LOCATION: result = blockD->metLocation; break;
    case POKE_TOOL_PARAM_POKERUS: result = blockD->pokerus; break;
    case POKE_TOOL_PARAM_BALL: result = blockD->ball; break;
    case POKE_TOOL_PARAM_MET_LEVEL: result = blockD->metLevel; break;
    case POKE_TOOL_PARAM_OT_GENDER: result = blockD->otGender; break;
    case POKE_TOOL_PARAM_ENCOUNTER_TYPE: result = blockD->encounterType; break;
    case POKE_TOOL_PARAM_BALL_EXTRA: result = blockD->ballExtra; break;
    case POKE_TOOL_PARAM_PACKED_IVS:
        result = blockB->ivHp | (blockB->ivAttack << 5) | (blockB->ivDefense << 10) | (blockB->ivSpeed << 15)
            | (blockB->ivSpAttack << 20) | (blockB->ivSpDefense << 25);
        break;
    case POKE_TOOL_PARAM_NICKNAME_NOT_DEFAULT_NIDORAN:
        if ((blockA->species == 29 || blockA->species == 32) && blockB->hasNickname == 0) {
            result = 0;
        } else {
            result = 1;
        }
        break;
    case POKE_TOOL_PARAM_TYPE1:
    case POKE_TOOL_PARAM_TYPE2:
        if (blockA->species == 493 && blockA->ability == 121) {
            result = POKE_TOOL_GetPlateType(blockA->heldItem);
        } else {
            paramId -= 0xA8;
            result = POKE_TOOL_GetPersonalParam(blockA->species, blockB->form, paramId);
        }
        break;
    }
    return result;
}


/*
 * The setter twin of POKE_TOOL_GetPartyValueRaw (src/matched/POKE_TOOL_GetPartyValueRaw.c): the same
 * twelve party-area ids 0x9D to 0xA8 over the same offsets of the 0xDC byte
 * record, with everything else forwarded to POKE_TOOL_SetBoxValueRaw, the 178 case
 * writer over the block area (src/matched/POKE_TOOL_SetBoxValueRaw.c).
 *
 * Two details cost the time here and both are about where the two ids that
 * store nothing send control.
 *
 * The forwarding call has to be written as `default:` inside the switch rather
 * than as a statement after it.  Written after the switch the compiler places
 * the forwarding block first, at the head of the case bodies, and every one of
 * the twelve table displacements moves.
 *
 * `case 0xA8` has to be an empty arm ending in `break`, not `return`.  Both
 * spellings produce the same twelve entry table and the same eleven bodies,
 * and they differ in one byte: the twelfth displacement.  With `break` the
 * empty arm lands on the function's last `pop`, the one the forwarding call
 * falls into; with `return` it lands on the `pop` that ends case 0xA7's body
 * instead, four bytes earlier.  The original names the last one.
 *
 * Nothing here is version specific.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_SetPartyValueRaw.c \
 *       --func POKE_TOOL_SetPartyValueRaw --addr 0x02019308 --cc 1.1p1
 */
void POKE_TOOL_SetPartyValueRaw(struct PokemonParam *pp, u32 paramId, u32 value)
{
    switch (paramId) {
    case POKE_TOOL_PARAM_STATUS_CONDITION: pp->statusCondition = value; return;
    case POKE_TOOL_PARAM_LEVEL: pp->level = (u8)value; return;
    case POKE_TOOL_PARAM_CAPSULE_INDEX: pp->capsuleIndex = (u8)value; return;
    case POKE_TOOL_PARAM_HP: pp->hp = (u16)value; return;
    case POKE_TOOL_PARAM_MAX_HP: pp->maxHp = (u16)value; return;
    case POKE_TOOL_PARAM_ATTACK: pp->attack = (u16)value; return;
    case POKE_TOOL_PARAM_DEFENSE: pp->defense = (u16)value; return;
    case POKE_TOOL_PARAM_SPEED: pp->speed = (u16)value; return;
    case POKE_TOOL_PARAM_SP_ATTACK: pp->spAttack = (u16)value; return;
    case POKE_TOOL_PARAM_SP_DEFENSE: pp->spDefense = (u16)value; return;
    case POKE_TOOL_PARAM_MAIL:
        MAIL_Copy((const struct Mail *)value, &pp->mail);
        return;
    case POKE_TOOL_PARAM_NO_DATA:
        break;
    default:
        POKE_TOOL_SetBoxValueRaw(&pp->box, paramId, value);
        break;
    }
}


/*
 * 1736 bytes, one function, 178 case jump table.
 *
 * The write accessor over the encrypted block area of the 0xDC byte record,
 * and the largest of poke_tool.c's get/set dispatcher quartet.  POKE_TOOL_SetPartyValueRaw
 * (src/matched/POKE_TOOL_SetPartyValueRaw.c) owns the party-area ids 0x9D to 0xA8 and
 * forwards everything else here; the reader twin is POKE_TOOL_GetBoxValueRaw
 * (src/pending/POKE_TOOL_GetBoxValueRaw.c), whose header carries the full field map.  The
 * two dispatchers agree field for field, so only what is specific to writing
 * is repeated below.
 *
 * What held it open, and what closed it: two of the thirteen relocation sites
 * call POKE_TOOL_IsDefaultName, both from inside this function, and a scan of every
 * Thumb BL and BLX in the image finds no third site.  The `label` class
 * therefore has no witness and no cut helps, because the range cannot be made
 * smaller than the one function that holds both calls.  The `matched` class
 * carries both: 0x02019ABC is src/matched/unit_02019ABC.c, an EXACT entry
 * proved against the original bytes over a range this file does not touch.
 *
 * ---------------------------------------------------------------------------
 * WHAT THE WRITER ADDS OVER THE READER
 * ---------------------------------------------------------------------------
 * Two ids exist here that the reader does not have, 0xB0 and 0xB1, and they
 * sit in the source between 0x74 and 0x76.  They are 0x73 and 0x74 without the
 * trailing recomputation, so the pairs read: 0x73 copies 11 halfwords into
 * substruct C and then sets C's "renamed" bit from POKE_TOOL_IsDefaultName, 0xB0 copies
 * the same 11 halfwords and leaves the bit alone; 0x74 and 0xB1 are the same
 * pair through the other copier.
 *
 * Nine ids the reader answers are absent here and fall to `default`, which
 * writes nothing: 0x42 to 0x45 (derived from a move and its use count), 0x75,
 * 0x9D to 0xAB (the party area plus the derived species, egg and level
 * queries) and 0xAD to 0xAF (the derived nickname and type queries).
 *
 * Ids 0x0D to 0x12, the six bytes at A +0x10, are the only arms with real
 * logic: each sums all six, clamps the increment so that the total cannot pass
 * 510, and then clamps the single value to 255.  The comparison is signed
 * (`ble`) while the values are unsigned bytes, so the clamp has to be written
 * through an explicit signed cast or the compiler emits `bls` and the arm is
 * a byte short.
 *
 * Id 0x06 refuses any value above 626 by branching into the `default` body,
 * which is why the writer's `default` is the last arm and the reader's is the
 * first: here it is a shared do-nothing exit that two arms jump to.
 *
 * ---------------------------------------------------------------------------
 * THE TWO THINGS THAT COST THE MOST TIME
 * ---------------------------------------------------------------------------
 * **One u64 mask serves all three flag-bit groups, and its complement is
 * written `mask ^ -1`, not `~mask`.**  Ids 0x19..0x35, 0x4D..0x6C and
 * 0x78..0x8C are all `mask = 1 << n; if (v) field |= mask; else field &=
 * complement;`, with `mask` a single function-scope `u64`.  The 64 bit type is
 * what makes the two u32 fields behave the way the original does: the shift
 * stays a plain `lsls` because only the low half is ever used, while the
 * complement is emitted as the low half of a 64 bit NOT, which mwccarm builds
 * as `movs r1, #3` / `subs r1, r1, #4` / `eors` rather than as `mvns`.
 * Spelling it `~mask` gives `mvns` and 904 wrong bytes; spelling it
 * `mask ^ 0xFFFFFFFF` gives the right size but 346 wrong bytes, because the
 * constant then fits one word and the 21 bit group at C +0x18 loses its
 * second `eors`.  Declaring `mask` u32, or one mask per group, also sinks the
 * shift into both arms of the test and costs a further eight bytes.
 * Getting this wrong is also what decides the register allocation: with three
 * separate 32 bit masks the record pointer loses r7 to the id and is reloaded
 * from the frame before each of the four substruct calls.
 *
 * **Id 0xAC writes the six 5 bit fields in the order 0, 1, 2, 4, 5, 3, and the
 * value it takes them from is permuted.**  The masks the original ANDs in are,
 * in order, 0xFFFFFC1F, 0xFFFF83FF, 0xFE0FFFFF, 0xC1FFFFFF and one derived
 * from the last by `asrs #0xa`, which is 0xFFF07FFF: that is bits 5, 10, 20,
 * 25 and 15, in that order.  Matching them against the shift amounts gives
 * field[4] = (v >> 15) & 0x1F, field[5] = (v >> 20) & 0x1F and
 * field[3] = (v >> 25) & 0x1F, so the packed argument orders the last three
 * fields differently from the structure.  The reader's 0xAC is a plain
 * identity repack of the same word, so the asymmetry is real and is in the
 * game, not in this reconstruction; writing 0xAC as an identity here is 89
 * wrong bytes and four bytes long, because the derived mask becomes a fifth
 * pool word.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Only one content id appears here, 626, the item ceiling at id 0x06, and it
 * is the same constant the reader uses.  There is no version-exclusive-species
 * table, no version flag and no message bank in this function; everything else
 * is a structure offset or a field width.  Black and White share their item
 * numbering, so 626 is expected to be identical in IRAO, but it is the one
 * number to re-read.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_SetBoxValueRaw.c \
 *       --func POKE_TOOL_SetBoxValueRaw --addr 0x02019388 --cc 1.1p1
 */
void POKE_TOOL_SetBoxValueRaw(struct BoxPokemon *box, u32 paramId, u32 value)
{
    struct BoxPokemonBlockA *blockA = (struct BoxPokemonBlockA *)POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_A);
    struct BoxPokemonBlockB *blockB = (struct BoxPokemonBlockB *)POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_B);
    struct BoxPokemonBlockC *blockC = (struct BoxPokemonBlockC *)POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_C);
    struct BoxPokemonBlockD *blockD = (struct BoxPokemonBlockD *)POKE_TOOL_GetBoxSubstruct(box, box->personality, POKE_TOOL_BLOCK_D);
    u32 evSum;
    u64 mask;

    switch (paramId) {
    case POKE_TOOL_PARAM_PERSONALITY: box->personality = value; break;
    case POKE_TOOL_PARAM_PARTY_DECODED: box->partyDecoded = (u16)value; break;
    case POKE_TOOL_PARAM_BOX_DECODED: box->boxDecoded = (u16)value; break;
    case POKE_TOOL_PARAM_CHECKSUM_FAILED: box->checksumFailed = (u16)value; break;
    case POKE_TOOL_PARAM_CHECKSUM: box->checksum = (u16)value; break;
    case POKE_TOOL_PARAM_SPECIES: blockA->species = (u16)value; break;
    case POKE_TOOL_PARAM_HELD_ITEM:
        if (value > 626) {
            break;
        }
        blockA->heldItem = (u16)value;
        break;
    case POKE_TOOL_PARAM_OT_ID: blockA->otId = value; break;
    case POKE_TOOL_PARAM_EXP: blockA->exp = value; break;
    case POKE_TOOL_PARAM_FRIENDSHIP: blockA->friendship = (u8)value; break;
    case POKE_TOOL_PARAM_ABILITY: blockA->ability = (u8)value; break;
    case POKE_TOOL_PARAM_MARKINGS: blockA->markings = (u8)value; break;
    case POKE_TOOL_PARAM_LANGUAGE: blockA->language = (u8)value; break;
    case POKE_TOOL_PARAM_EV_HP:
        evSum = blockA->evs[0] + blockA->evs[1] + blockA->evs[2] + blockA->evs[3]
            + blockA->evs[4] + blockA->evs[5];
        if ((s32)(value - blockA->evs[0]) > (s32)(510 - evSum)) {
            value = blockA->evs[0] + (510 - evSum);
        }
        if (value > 255) {
            value = 255;
        }
        blockA->evs[0] = (u8)value;
        break;
    case POKE_TOOL_PARAM_EV_ATTACK:
        evSum = blockA->evs[0] + blockA->evs[1] + blockA->evs[2] + blockA->evs[3]
            + blockA->evs[4] + blockA->evs[5];
        if ((s32)(value - blockA->evs[1]) > (s32)(510 - evSum)) {
            value = blockA->evs[1] + (510 - evSum);
        }
        if (value > 255) {
            value = 255;
        }
        blockA->evs[1] = (u8)value;
        break;
    case POKE_TOOL_PARAM_EV_DEFENSE:
        evSum = blockA->evs[0] + blockA->evs[1] + blockA->evs[2] + blockA->evs[3]
            + blockA->evs[4] + blockA->evs[5];
        if ((s32)(value - blockA->evs[2]) > (s32)(510 - evSum)) {
            value = blockA->evs[2] + (510 - evSum);
        }
        if (value > 255) {
            value = 255;
        }
        blockA->evs[2] = (u8)value;
        break;
    case POKE_TOOL_PARAM_EV_SPEED:
        evSum = blockA->evs[0] + blockA->evs[1] + blockA->evs[2] + blockA->evs[3]
            + blockA->evs[4] + blockA->evs[5];
        if ((s32)(value - blockA->evs[3]) > (s32)(510 - evSum)) {
            value = blockA->evs[3] + (510 - evSum);
        }
        if (value > 255) {
            value = 255;
        }
        blockA->evs[3] = (u8)value;
        break;
    case POKE_TOOL_PARAM_EV_SP_ATTACK:
        evSum = blockA->evs[0] + blockA->evs[1] + blockA->evs[2] + blockA->evs[3]
            + blockA->evs[4] + blockA->evs[5];
        if ((s32)(value - blockA->evs[4]) > (s32)(510 - evSum)) {
            value = blockA->evs[4] + (510 - evSum);
        }
        if (value > 255) {
            value = 255;
        }
        blockA->evs[4] = (u8)value;
        break;
    case POKE_TOOL_PARAM_EV_SP_DEFENSE:
        evSum = blockA->evs[0] + blockA->evs[1] + blockA->evs[2] + blockA->evs[3]
            + blockA->evs[4] + blockA->evs[5];
        if ((s32)(value - blockA->evs[5]) > (s32)(510 - evSum)) {
            value = blockA->evs[5] + (510 - evSum);
        }
        if (value > 255) {
            value = 255;
        }
        blockA->evs[5] = (u8)value;
        break;
    case POKE_TOOL_PARAM_CONTEST_COOL: blockA->contestStats[0] = (u8)value; break;
    case POKE_TOOL_PARAM_CONTEST_BEAUTY: blockA->contestStats[1] = (u8)value; break;
    case POKE_TOOL_PARAM_CONTEST_CUTE: blockA->contestStats[2] = (u8)value; break;
    case POKE_TOOL_PARAM_CONTEST_SMART: blockA->contestStats[3] = (u8)value; break;
    case POKE_TOOL_PARAM_CONTEST_TOUGH: blockA->contestStats[4] = (u8)value; break;
    case POKE_TOOL_PARAM_CONTEST_SHEEN: blockA->contestStats[5] = (u8)value; break;
    case POKE_TOOL_PARAM_RIBBON_SINNOH_CHAMPION: case POKE_TOOL_PARAM_RIBBON_SINNOH_ABILITY:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_GREAT_ABILITY: case POKE_TOOL_PARAM_RIBBON_SINNOH_DOUBLE_ABILITY:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_MULTI_ABILITY: case POKE_TOOL_PARAM_RIBBON_SINNOH_PAIR_ABILITY:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_WORLD_ABILITY: case POKE_TOOL_PARAM_RIBBON_SINNOH_ALERT:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_SHOCK: case POKE_TOOL_PARAM_RIBBON_SINNOH_DOWNCAST:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_CAREFUL: case POKE_TOOL_PARAM_RIBBON_SINNOH_RELAX:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_SNOOZE: case POKE_TOOL_PARAM_RIBBON_SINNOH_SMILE:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_GORGEOUS: case POKE_TOOL_PARAM_RIBBON_SINNOH_ROYAL:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_GORGEOUS_ROYAL: case POKE_TOOL_PARAM_RIBBON_SINNOH_ARTIST:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_FOOTPRINT: case POKE_TOOL_PARAM_RIBBON_SINNOH_RECORD:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_HISTORY: case POKE_TOOL_PARAM_RIBBON_SINNOH_LEGEND:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_RED: case POKE_TOOL_PARAM_RIBBON_SINNOH_GREEN:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_BLUE: case POKE_TOOL_PARAM_RIBBON_SINNOH_FESTIVAL:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_CARNIVAL: case POKE_TOOL_PARAM_RIBBON_SINNOH_CLASSIC:
    case POKE_TOOL_PARAM_RIBBON_SINNOH_PREMIER:
        paramId -= POKE_TOOL_PARAM_RIBBON_SINNOH_FIRST;
        mask = 1 << paramId;
        if (value != 0) {
            blockA->sinnohRibbons |= mask;
        } else {
            blockA->sinnohRibbons &= (mask ^ -1);
        }
        break;
    case POKE_TOOL_PARAM_MOVE1: case POKE_TOOL_PARAM_MOVE2: case POKE_TOOL_PARAM_MOVE3: case POKE_TOOL_PARAM_MOVE4:
        paramId -= POKE_TOOL_PARAM_MOVE1;
        blockB->moves[paramId] = (u16)value;
        break;
    case POKE_TOOL_PARAM_PP1: case POKE_TOOL_PARAM_PP2: case POKE_TOOL_PARAM_PP3: case POKE_TOOL_PARAM_PP4:
        paramId -= POKE_TOOL_PARAM_PP1;
        blockB->pp[paramId] = (u8)value;
        break;
    case POKE_TOOL_PARAM_PP_UP1: case POKE_TOOL_PARAM_PP_UP2: case POKE_TOOL_PARAM_PP_UP3: case POKE_TOOL_PARAM_PP_UP4:
        paramId -= POKE_TOOL_PARAM_PP_UP1;
        blockB->ppUps[paramId] = (u8)value;
        break;
    case POKE_TOOL_PARAM_IV_HP: blockB->ivHp = value; break;
    case POKE_TOOL_PARAM_IV_ATTACK: blockB->ivAttack = value; break;
    case POKE_TOOL_PARAM_IV_DEFENSE: blockB->ivDefense = value; break;
    case POKE_TOOL_PARAM_IV_SPEED: blockB->ivSpeed = value; break;
    case POKE_TOOL_PARAM_IV_SP_ATTACK: blockB->ivSpAttack = value; break;
    case POKE_TOOL_PARAM_IV_SP_DEFENSE: blockB->ivSpDefense = value; break;
    case POKE_TOOL_PARAM_IS_EGG: blockB->isEgg = value; break;
    case POKE_TOOL_PARAM_RIBBON_HOENN_COOL: case POKE_TOOL_PARAM_RIBBON_HOENN_COOL_SUPER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_COOL_HYPER: case POKE_TOOL_PARAM_RIBBON_HOENN_COOL_MASTER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY: case POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY_SUPER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY_HYPER: case POKE_TOOL_PARAM_RIBBON_HOENN_BEAUTY_MASTER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_CUTE: case POKE_TOOL_PARAM_RIBBON_HOENN_CUTE_SUPER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_CUTE_HYPER: case POKE_TOOL_PARAM_RIBBON_HOENN_CUTE_MASTER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_SMART: case POKE_TOOL_PARAM_RIBBON_HOENN_SMART_SUPER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_SMART_HYPER: case POKE_TOOL_PARAM_RIBBON_HOENN_SMART_MASTER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH: case POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH_SUPER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH_HYPER: case POKE_TOOL_PARAM_RIBBON_HOENN_TOUGH_MASTER:
    case POKE_TOOL_PARAM_RIBBON_HOENN_CHAMPION: case POKE_TOOL_PARAM_RIBBON_HOENN_WINNING:
    case POKE_TOOL_PARAM_RIBBON_HOENN_VICTORY: case POKE_TOOL_PARAM_RIBBON_HOENN_ARTIST:
    case POKE_TOOL_PARAM_RIBBON_HOENN_EFFORT: case POKE_TOOL_PARAM_RIBBON_HOENN_MARINE:
    case POKE_TOOL_PARAM_RIBBON_HOENN_LAND: case POKE_TOOL_PARAM_RIBBON_HOENN_SKY:
    case POKE_TOOL_PARAM_RIBBON_HOENN_COUNTRY: case POKE_TOOL_PARAM_RIBBON_HOENN_NATIONAL:
    case POKE_TOOL_PARAM_RIBBON_HOENN_EARTH: case POKE_TOOL_PARAM_RIBBON_HOENN_WORLD:
        paramId -= POKE_TOOL_PARAM_RIBBON_HOENN_FIRST;
        mask = 1 << paramId;
        if (value != 0) {
            blockB->hoennRibbons |= mask;
        } else {
            blockB->hoennRibbons &= (mask ^ -1);
        }
        break;
    case POKE_TOOL_PARAM_FATEFUL_ENCOUNTER: blockB->fatefulEncounter = (u8)value; break;
    case POKE_TOOL_PARAM_GENDER:
        blockB->gender = POKE_TOOL_CalcGender(blockA->species, blockB->form, box->personality);
        break;
    case POKE_TOOL_PARAM_FORM: blockB->form = (u8)value; break;
    case POKE_TOOL_PARAM_NATURE: blockB->nature = (u8)value; break;
    case POKE_TOOL_PARAM_HIDDEN_ABILITY: blockB->hasHiddenAbility = (u16)value; break;
    case POKE_TOOL_PARAM_SPARE_WORD: blockB->spareWord = value; break;
    case POKE_TOOL_PARAM_NICKNAME_STRBUF:
        STRBUF_ToChars((struct Strbuf *)value, blockC->nickname, 11);
        blockB->hasNickname = POKE_TOOL_IsDefaultName(box);
        break;
    case POKE_TOOL_PARAM_NICKNAME:
        WORDSET_CopyString((const u16 *)value, blockC->nickname, 11);
        blockB->hasNickname = POKE_TOOL_IsDefaultName(box);
        break;
    case POKE_TOOL_PARAM_NICKNAME_STRBUF_KEEP_FLAG:
        STRBUF_ToChars((struct Strbuf *)value, blockC->nickname, 11);
        break;
    case POKE_TOOL_PARAM_NICKNAME_KEEP_FLAG:
        WORDSET_CopyString((const u16 *)value, blockC->nickname, 11);
        break;
    case POKE_TOOL_PARAM_SPARE_BYTE: blockC->spareByte = (u8)value; break;
    case POKE_TOOL_PARAM_ORIGIN_GAME: blockC->originGame = (u8)value; break;
    case POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_NORMAL: case POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_GREAT:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_ULTRA: case POKE_TOOL_PARAM_RIBBON_CONTEST_COOL_MASTER:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_NORMAL: case POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_GREAT:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_ULTRA: case POKE_TOOL_PARAM_RIBBON_CONTEST_BEAUTY_MASTER:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_NORMAL: case POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_GREAT:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_ULTRA: case POKE_TOOL_PARAM_RIBBON_CONTEST_CUTE_MASTER:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_NORMAL: case POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_GREAT:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_ULTRA: case POKE_TOOL_PARAM_RIBBON_CONTEST_SMART_MASTER:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_NORMAL: case POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_GREAT:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_ULTRA: case POKE_TOOL_PARAM_RIBBON_CONTEST_TOUGH_MASTER:
    case POKE_TOOL_PARAM_RIBBON_CONTEST_EXTRA:
        paramId -= POKE_TOOL_PARAM_RIBBON_CONTEST_FIRST;
        mask = 1 << paramId;
        if (value != 0) {
            blockC->contestRibbons |= mask;
        } else {
            blockC->contestRibbons &= (mask ^ -1);
        }
        break;
    case POKE_TOOL_PARAM_OT_NAME_STRBUF:
        STRBUF_ToChars((struct Strbuf *)value, blockD->otName, 8);
        break;
    case POKE_TOOL_PARAM_OT_NAME:
        WORDSET_CopyString((const u16 *)value, blockD->otName, 8);
        break;
    case POKE_TOOL_PARAM_EGG_YEAR: blockD->eggYear = (u8)value; break;
    case POKE_TOOL_PARAM_EGG_MONTH: blockD->eggMonth = (u8)value; break;
    case POKE_TOOL_PARAM_EGG_DAY: blockD->eggDay = (u8)value; break;
    case POKE_TOOL_PARAM_MET_YEAR: blockD->metYear = (u8)value; break;
    case POKE_TOOL_PARAM_MET_MONTH: blockD->metMonth = (u8)value; break;
    case POKE_TOOL_PARAM_MET_DAY: blockD->metDay = (u8)value; break;
    case POKE_TOOL_PARAM_EGG_LOCATION: blockD->eggLocation = (u16)value; break;
    case POKE_TOOL_PARAM_MET_LOCATION: blockD->metLocation = (u16)value; break;
    case POKE_TOOL_PARAM_POKERUS: blockD->pokerus = (u8)value; break;
    case POKE_TOOL_PARAM_BALL: blockD->ball = (u8)value; break;
    case POKE_TOOL_PARAM_MET_LEVEL: blockD->metLevel = (u8)value; break;
    case POKE_TOOL_PARAM_OT_GENDER: blockD->otGender = (u8)value; break;
    case POKE_TOOL_PARAM_ENCOUNTER_TYPE: blockD->encounterType = (u8)value; break;
    case POKE_TOOL_PARAM_BALL_EXTRA: blockD->ballExtra = (u16)value; break;
    case POKE_TOOL_PARAM_PACKED_IVS:
        blockB->ivHp = (u8)(value & 0x1F);
        blockB->ivAttack = (u8)((value >> 5) & 0x1F);
        blockB->ivDefense = (u8)((value >> 10) & 0x1F);
        blockB->ivSpAttack = (u8)((value >> 15) & 0x1F);
        blockB->ivSpDefense = (u8)((value >> 20) & 0x1F);
        blockB->ivSpeed = (u8)((value >> 25) & 0x1F);
        break;
    default:
        break;
    }
}
