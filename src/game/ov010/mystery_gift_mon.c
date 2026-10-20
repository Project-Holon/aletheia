/*
 * file:     mystery_gift_mon.c
 * unit:     yes
 * function: MYSTERY_GIFT_CreateMon
 * address:  0x02157E9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from delivery_irc.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   POKE_TOOL_CreatePersonalRnd  0x020186C8  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetDefaultMoves  0x02017FA8  thumb
 *   POKE_TOOL_AddMove  0x0201808C  thumb
 *   POKE_TOOL_PushMove  0x020180F4  thumb
 *   POKE_TOOL_SetAbility  0x02018A00  thumb
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   SAVE_EVENT_WriteWithDate  0x0202F2AC  thumb
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   sGiftRibbonIds     0x02170068  data
 *   GAME_VERSION_Code     0x0209DF08  data  a1
 *   GAME_LANGUAGE_Code     0x0209DF0C  data  a1
 *   gSpeciesNameBank     0x020A7370  data
 */
#include "mystery_gift_mon_shared_types.h"

#include "../types.h"

struct PokemonParam;

struct StrBank;

/*
 * Mystery gift Pokemon record (0xB4 bytes). The three Pokemon values at
 * 0x46, 0x47 and 0x48 are named by the slot they take in the packed IV word
 * (speed fourth, special attack fifth, special defense sixth).
 */
typedef struct GiftMon {
    u32 otId;               /* 0x00: 0 = the player's own trainer ID */
    u32 originGame;         /* 0x04: 0 = the running game's version */
    u32 pid;                /* 0x08: 0 = derived from pidType */
    u16 ribbons;            /* 0x0C: bit k set = ribbon sGiftRibbonIds[k] */
    u16 ball;               /* 0x0E: 0 or above 0x19 = ball 4 */
    u16 item;               /* 0x10 */
    u16 moves[4];           /* 0x12 */
    u16 species;            /* 0x1A */
    u8 form;                /* 0x1C */
    u8 language;            /* 0x1D: 0 = the running game's language */
    u16 nickname[11];       /* 0x1E: first char 0 = invalid, EOS = default name */
    u8 nature;              /* 0x34: 0xFF = random */
    u8 gender;              /* 0x35: 0xFF = random (stored as 2) */
    u8 abilityKind;         /* 0x36: 0, 1, 2 (hidden), 3, 4 = random */
    u8 pidType;             /* 0x37 */
    u16 eggLocation;        /* 0x38 */
    u16 metLocation;        /* 0x3A */
    u8 ballExtra;           /* 0x3C: nonzero = set as ball extra value */
    u8 contestStats[6];     /* 0x3D: cool, beauty, cute, smart, tough; entry 4 is also stored as sheen, entry 5 is unread */
    u8 ivHp;                /* 0x43 */
    u8 ivAttack;            /* 0x44 */
    u8 ivDefense;           /* 0x45 */
    u8 ivSlot5;             /* 0x46: packed sixth (special defense slot) */
    u8 ivSlot3;             /* 0x47: packed fourth (speed slot) */
    u8 ivSlot4;             /* 0x48: packed fifth (special attack slot) */
    u8 pad49;
    u16 otName[8];          /* 0x4A: first char EOS = the player's name */
    u8 otGender;            /* 0x5A: above 2 = the player's gender */
    u8 level;               /* 0x5B: 0 = random 1 to 100 */
    u8 isEgg;               /* 0x5C */
    u8 pad5D[0xAC - 0x5D];
    s32 receivedDate;       /* 0xAC: year in bits 16 to 31, month in 8 to 15, day in 0 to 7 */
    u8 padB0[3];
    u8 formatVersion;       /* 0xB3: must be 1 */
} GiftMon;

#include "../arm9/gfl_use.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/game_data.h"

#include "../arm9/mystatus.h"


#ifdef __MWERKS__
extern void *POKE_TOOL_Create(u16 species, u16 level, u64 id, int heap); /* original prototype; the definition differs in return type, argument width */
#else
extern struct PokemonParam*POKE_TOOL_Create(u16, u16, u64, u16);
#endif

extern u32 POKE_TOOL_CreatePersonalRnd(u32 otId, s32 species, u16 form, s32 ratioMode, s32 shinyWanted, s32 mode);

extern void POKE_TOOL_SetupPartyParamEx(struct PokemonParam *mon, u16 species, u16 level, unsigned long long id, u32 packedIvs, unsigned long long personalRnd);

extern void POKE_TOOL_SetPartyValue(struct PokemonParam *pp, u32 paramId, u32 value);

extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);

extern u32 POKE_TOOL_SetDefaultMoves(struct PokemonParam *pp);

extern u16 POKE_TOOL_AddMove(struct PokemonParam *pp, u16 move);

extern void POKE_TOOL_PushMove(struct PokemonParam *pp, u16 move);
struct BoxPokemon;

extern void POKE_TOOL_SetAbility(struct BoxPokemon *box, u32 species, u32 form);

extern struct BoxPokemon *POKE_TOOL_CastToBoxParam(struct PokemonParam *mon);

extern void POKE_TOOL_RecalcParam(struct PokemonParam *pp);
struct SaveData;

#include "../arm9/save_event.h"

#include "../arm9/strbuf.h"
struct MsgBank;
struct Strbuf;

#include "../arm9/msgdata.h"



struct PokemonParam *MYSTERY_GIFT_CreateMon(const GiftMon *gift, int heapId, struct GameData *gameData);

extern const u32 sGiftRibbonIds[15];

extern u8 GAME_VERSION_Code[];

extern u8 GAME_LANGUAGE_Code[];

extern struct StrBank *gSpeciesNameBank;

/*
 * Builds a Pokemon from a mystery gift record, or returns 0 when the record
 * is invalid (wrong format version, species above 649, level above 100, item
 * above 626, bad ability kind, empty nickname or OT name) or the finished
 * Pokemon fails its final value check. The Pokemon is allocated in heap
 * heapId. A random value is taken for every field the record leaves open.
 *
 * Lever: gender is a u8 local, loaded from GiftMon.gender and remapped from
 * 0xFF to 2; the form argument of the personality call is cast to u8.
 */
struct PokemonParam *MYSTERY_GIFT_CreateMon(const GiftMon *gift, int heapId, struct GameData *gameData)
{
    u16 moves[4];
    u8 ivValues[6];
    u32 month;
    u32 abilityKind;
    u8 gender;
    u64 personalRnd;
    u32 species;
    u32 otId;
    u64 otId64;
    u16 level;
    u32 abilitySlot;
    struct PokemonParam *result;
    u32 packedIvs;
    int i;
    u32 ribbonBit;
    u16 move;
    struct PokemonParam *mon;
    void *eggName;
    u32 nature;
    u8 day;
    u16 year;
    u32 metLocation;

    level = gift->level;
    otId = gift->otId;
    species = gift->species;
    gender = gift->gender;
    abilityKind = gift->abilityKind;
    ivValues[0] = gift->ivHp;
    ivValues[1] = gift->ivAttack;
    ivValues[2] = gift->ivDefense;
    ivValues[3] = gift->ivSlot3;
    ivValues[4] = gift->ivSlot4;
    ivValues[5] = gift->ivSlot5;
    moves[0] = gift->moves[0];
    moves[1] = gift->moves[1];
    moves[2] = gift->moves[2];
    moves[3] = gift->moves[3];

    if (gift->formatVersion != 1) {
        result = 0;
        goto out;
    }
    if (species > 649) {
        result = 0;
        goto out;
    }
    if (species == 0) {
        result = 0;
        goto out;
    }
    if (level > 100) {
        result = 0;
        goto out;
    }
    if (gift->item > 626) {
        result = 0;
        goto out;
    }

    if (level == 0)
        level = GFL_USE_GetRandom(100) + 1;
    if (gift->otId == 0)
        otId = MYSTATUS_GetId(GAME_DATA_GetMyStatus(gameData));
    if (gender == 0xFF)
        gender = 2;
    for (i = 0; i < 6; i++) {
        if (ivValues[i] == 0xFF)
            ivValues[i] = GFL_USE_GetRandom(32);
    }

    otId64 = otId;
    mon = (void *)POKE_TOOL_Create(species, level, otId64, heapId);
    packedIvs = (ivValues[0] & 0x1F) | ((ivValues[1] & 0x1F) << 5) | ((ivValues[2] & 0x1F) << 10)
        | ((ivValues[3] & 0x1F) << 15) | ((ivValues[4] & 0x1F) << 20) | ((ivValues[5] & 0x1F) << 25);

    if (abilityKind == 4)
        abilityKind = (u8)GFL_USE_GetRandom(3);
    switch (abilityKind) {
    case 0:
        abilitySlot = 0;
        break;
    case 1:
        abilitySlot = 1;
        break;
    case 2:
        abilitySlot = 0;
        break;
    case 3:
        abilitySlot = 2;
        break;
    default:
        result = 0;
        goto out;
    }

    if (gift->pid != 0) {
        personalRnd = gift->pid;
    } else if (gift->pidType == 0) {
        personalRnd = POKE_TOOL_CreatePersonalRnd(otId, (u16)species, (u8)gift->form, gender, abilitySlot, 0);
    } else if (gift->pidType == 1) {
        personalRnd = POKE_TOOL_CreatePersonalRnd(otId, (u16)species, (u8)gift->form, gender, abilitySlot, 2);
    } else if (gift->pidType == 2) {
        personalRnd = POKE_TOOL_CreatePersonalRnd(otId, (u16)species, (u8)gift->form, gender, abilitySlot, 1);
    }

    POKE_TOOL_SetupPartyParamEx(mon, gift->species, level, otId64, packedIvs, personalRnd);
    POKE_TOOL_SetPartyValue(mon, 6, gift->item);
    POKE_TOOL_SetDefaultMoves(mon);
    for (i = 0; i < 4; i++) {
        move = moves[i];
        if (move != 0 && move < 0x230) {
            if (POKE_TOOL_AddMove(mon, move) == 0xFFFF)
                POKE_TOOL_PushMove(mon, move);
        }
    }
    if (gift->pid == 0 && abilityKind == 2)
        POKE_TOOL_SetAbility((struct BoxPokemon *)mon, species, gift->form);
    POKE_TOOL_SetPartyValue(mon, 0x6F, gift->form);
    if (gift->ball != 0 && gift->ball <= 0x19)
        POKE_TOOL_SetPartyValue(mon, 0x98, gift->ball);
    else
        POKE_TOOL_SetPartyValue(mon, 0x98, 4);
    if (gift->ballExtra != 0)
        POKE_TOOL_SetPartyValue(mon, 0x99, gift->ballExtra);
    POKE_TOOL_SetPartyValue(mon, 0x13, gift->contestStats[0]);
    POKE_TOOL_SetPartyValue(mon, 0x14, gift->contestStats[1]);
    POKE_TOOL_SetPartyValue(mon, 0x15, gift->contestStats[2]);
    POKE_TOOL_SetPartyValue(mon, 0x16, gift->contestStats[3]);
    POKE_TOOL_SetPartyValue(mon, 0x17, gift->contestStats[4]);
    POKE_TOOL_SetPartyValue(mon, 0x18, gift->contestStats[4]);
    for (ribbonBit = 0; ribbonBit < 15; ribbonBit++) {
        if (gift->ribbons & (1 << ribbonBit))
            POKE_TOOL_SetPartyValue(mon, sGiftRibbonIds[ribbonBit], 1);
    }
    if (gift->originGame == 0)
        POKE_TOOL_SetPartyValue(mon, 0x77, GAME_VERSION_Code[0]);
    else
        POKE_TOOL_SetPartyValue(mon, 0x77, gift->originGame);
    if (gift->language == 0)
        POKE_TOOL_SetPartyValue(mon, 0xC, GAME_LANGUAGE_Code[0]);
    else
        POKE_TOOL_SetPartyValue(mon, 0xC, gift->language);
    if (gift->nickname[0] == 0) {
        GFL_HEAP_Free(mon);
        result = 0;
        goto out;
    }
    if (gift->nickname[0] != STRBUF_GetEosChar())
        POKE_TOOL_SetPartyValue(mon, 0x74, (uptr)gift->nickname);
    nature = gift->nature;
    if (nature == 0xFF)
        nature = (u8)GFL_USE_GetRandom(25);
    POKE_TOOL_SetPartyValue(mon, 0x70, nature);
    POKE_TOOL_SetPartyValue(mon, 0x95, gift->eggLocation);
    POKE_TOOL_SetPartyValue(mon, 0x96, gift->metLocation);
    if (gift->otName[0] == 0) {
        GFL_HEAP_Free(mon);
        result = 0;
        goto out;
    }
    if (gift->otName[0] == STRBUF_GetEosChar())
        POKE_TOOL_SetPartyValue(mon, 0x8E, (uptr)MYSTATUS_GetName(GAME_DATA_GetMyStatus(gameData)));
    else
        POKE_TOOL_SetPartyValue(mon, 0x8E, (uptr)gift->otName);
    if (gift->otGender <= 2)
        POKE_TOOL_SetPartyValue(mon, 0x9A, gift->otGender);
    else
        POKE_TOOL_SetPartyValue(mon, 0x9A, MYSTATUS_GetSex(GAME_DATA_GetMyStatus(gameData)));
    if (gift->isEgg) {
        POKE_TOOL_SetPartyValue(mon, 0x4C, 1);
        eggName = MSGDATA_AllocString((struct MsgBank *)gSpeciesNameBank, 0x28A);
        POKE_TOOL_SetPartyValue(mon, 0x73, (uptr)eggName);
        STRBUF_Delete(eggName);
        POKE_TOOL_SetPartyValue(mon, 9, 10);
    }
    year = gift->receivedDate >> 16;
    month = (u8)(gift->receivedDate >> 8);
    day = gift->receivedDate;
    metLocation = gift->isEgg ? gift->eggLocation : gift->metLocation;
    SAVE_EVENT_WriteWithDate((struct SaveData *)POKE_TOOL_CastToBoxParam(mon), metLocation, year - 2000, month, day);
    POKE_TOOL_RecalcParam(mon);
    result = 0;
    if (POKE_TOOL_GetPartyValue(mon, 3, 0) != 0)
        GFL_HEAP_Free(mon);
    else
        result = mon;
out:
    return result;
}
