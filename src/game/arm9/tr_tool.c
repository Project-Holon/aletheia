/*
 * file:     tr_tool.c
 * unit:     yes
 * function: TR_TOOL_LoadTrainerInfo, TR_TOOL_BuildParty, TR_TOOL_AdjustPersonality, TR_TOOL_FinalizePartyMember
 * address:  0x0202A440
 * packet:   pkt_0202A4B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020A76DC     0x020A76DC  data
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   POKEPARTY_InitEx  0x0201A954  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   TPOKE_DATA_ReadRecord  0x0202A3AC  thumb
 *   TPOKE_DATA_ReadParty  0x0202A3BC  thumb
 *   TPOKE_DATA_GetGenderValue  0x0202A3CC  thumb
 *   TR_TOOL_AdjustPersonality  0x0202A994  thumb
 *   TR_TOOL_FinalizePartyMember  0x0202A9F4  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_SetMoveSlot  0x020181F4  thumb
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   POKE_PERSONAL_Create         0x0201ADE4  thumb
 *   POKE_PERSONAL_Delete         0x0201AE14  thumb
 *   POKE_PERSONAL_GetParam       0x0201AE1C  thumb
 *   POKE_TOOL_GetPartyValue      0x02017E1C  thumb
 *   POKE_TOOL_GetPersonalParam   0x02019C90  thumb
 *   POKE_TOOL_SetAbility         0x02018A00  thumb
 *   POKE_TOOL_SetNature          0x020185B0  thumb
 *
 * tr_tool.c: build a trainer's party.  Loads the trainer record (0x14
 * bytes) and its party table (up to 6 entries) from the archive, then per
 * entry: form/gender adjust (TR_TOOL_AdjustPersonality), a personality seeded from
 * dv + level + species + trainer id and stepped cls times through the
 * 64-bit LCG (mul 0x5D588B656C078965, add 0x269EC3, top 16 bits taken as
 * ((u64)(seed >> 32) * 0x10000) >> 32), IVs dv * 31 / 255 in all six
 * slots, then the per-type extras: type 1 moves, type 2 item, type 3 item
 * and moves.  Entry strides 8, 16, 10, 18 bytes.
 *
 * Shape facts that the allocator depends on (each one measured):
 *  - pid, seed, j and iv are function-scope; dv, level and species are
 *    declared in each case block (per-case stack homes);
 *  - the party table is read as ((TrMonN *)tp)[i] everywhere, no typed
 *    local pointer;
 *  - pid is one variable for the seed sum, the random draw and the final
 *    personality (it is what keeps the draw out of a callee-saved
 *    register);
 *  - the random draw's (u64)(u32) product by 0x10000 is what leaves the
 *    `lsls rX, zero, #16; orrs` pair and the hoisted zero;
 *  - case 3 passes the species to POKE_TOOL_SetupPartyParamEx as a fresh table read.
 */

#include "../types.h"

/* The 0x14-byte trainer record read from archive member 0x5c.  Both
 * TR_TOOL_LoadTrainerInfo and TR_TOOL_BuildParty read the same record, so it is one
 * struct: partyType/genderClass/partyCount are the party builder's view,
 * data04/data0C are the trainer-info view (data04 is the 8 bytes copied to
 * the info record, data0C the word stored there). */
typedef struct {
    u8  partyType;
    u8  genderClass;
    u8  pad02;
    u8  partyCount;
    u8  data04[8];
    u32 data0C;
    u32 data10;
} TrTrainerRecord;

typedef struct { u8 dv; u8 ability; u16 level; u16 species; u16 form; } TrPartyMon;
typedef struct { u8 dv; u8 ability; u16 level; u16 species; u16 form; u16 moves[4]; } TrPartyMonMoves;
typedef struct { u8 dv; u8 ability; u16 level; u16 species; u16 form; u16 item; } TrPartyMonItem;
typedef struct { u8 dv; u8 ability; u16 level; u16 species; u16 form; u16 item; u16 moves[4]; } TrPartyMonItemMoves;

extern char  g_020A76DC[];

extern void *GFL_HEAP_Alloc(u16 heap, u32 size, u32 align, const char *file, u32 line);
extern u32 GFL_HEAP_Free(void *p);
struct Mon;
struct Party;
struct PartyMon;
#include "pokeparty.h"
struct PokemonParam;
extern u32   POKE_TOOL_GetPartyParamSize(void);
#include "tpoke_data.h"
extern void  TR_TOOL_AdjustPersonality(u32 species, u32 form, int ability, u32 *gender, u16 heap);
extern void  TR_TOOL_FinalizePartyMember(u32 id, void *mon, u32 form, u32 ability);
extern void POKE_TOOL_SetupPartyParamEx(struct PokemonParam *pp, u16 species, u16 level, u64 otId, u32 ivs, u64 personality);
extern void  POKE_TOOL_SetPartyValue(struct PokemonParam *pp, u32 paramId, u32 value);
extern void POKE_TOOL_SetMoveSlot(struct PokemonParam *pp, u16 move, u32 slot);
struct Personal;
struct PersonalData;
#include "poke_personal.h"
extern u32  POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);
struct BoxPokemon;
extern void POKE_TOOL_SetAbility(struct BoxPokemon *box, u32 species, u32 form);
extern u32  POKE_TOOL_GetPersonalParam(u32 species, u16 form, u32 personalField);
extern void POKE_TOOL_SetNature(struct PokemonParam *pp, u32 nature);

typedef struct {
    u32 trainerId;    /* +0x00 the trainer id this record was loaded for */
    u32 genderClass;  /* +0x04 copied from the record's genderClass byte */
    u32 data0C;       /* +0x08 copied from the record's data0C word */
    u32 data04[2];    /* +0x0C the record's 8 data04 bytes, copied verbatim */
    u32 name;         /* +0x14 destination buffer for the trainer name string */
    u32 sentence[2];  /* +0x18 PmsData easy-chat sentence (2 words) */
    u32 sentence2[2]; /* +0x20 PmsData easy-chat sentence (2 words) */
} TrTrainerInfo;

struct MsgBank;
#include "msgdata.h"
struct Strbuf;
#include "mi_memory.h"
extern void  PMSI_PARAM_ClearSentence(void *p);
void TR_TOOL_LoadTrainerInfo(u32 id, TrTrainerInfo *out, u16 heap);

/*
 * The __FILE__ argument at 0x020A76DC is the tr_tool.c anchor recorded in
 * layout/file_anchors.txt for this range; it is pinned by address, not
 * spelled as a literal __FILE__
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 */
void TR_TOOL_LoadTrainerInfo(u32 id, TrTrainerInfo *out, u16 heap)
{
    TrTrainerRecord *t;
    void *bank;

    t = GFL_HEAP_Alloc(heap, 0x14, 0, g_020A76DC, 0x159);
    TPOKE_DATA_ReadRecord((void *)id, t);

    out->trainerId = id;
    out->genderClass = t->genderClass;
    out->data0C = t->data0C;

    bank = MSGDATA_CreateFromArchive(0, 2, 0xbe, heap);
    MSGDATA_ReadString(bank, id, (void *)out->name);
    MSGDATA_Delete(bank);

    MIi_CpuCopy16(t->data04, &out->data04, 8);
    PMSI_PARAM_ClearSentence(&out->sentence);
    PMSI_PARAM_ClearSentence(&out->sentence2);

    GFL_HEAP_Free(t);
}

/*
 * tr_tool.c: build a trainer's party.  Loads the trainer record (0x14
 * bytes) and its party table (up to 6 entries) from the archive, then per
 * entry: form/gender adjust (TR_TOOL_AdjustPersonality), a personality seeded from
 * dv + level + species + trainer id and stepped cls times through the
 * 64-bit LCG (mul 0x5D588B656C078965, add 0x269EC3, top 16 bits taken as
 * ((u64)(seed >> 32) * 0x10000) >> 32), IVs dv * 31 / 255 in all six
 * slots, then the per-type extras: type 1 moves, type 2 item, type 3 item
 * and moves.  Entry strides 8, 16, 10, 18 bytes.
 *
 * Shape facts that the allocator depends on (each one measured):
 *  - pid, seed, j and iv are function-scope; dv, level and species are
 *    declared in each case block (per-case stack homes);
 *  - the party table is read as ((TrMonN *)tp)[i] everywhere, no typed
 *    local pointer;
 *  - pid is one variable for the seed sum, the random draw and the final
 *    personality (it is what keeps the draw out of a callee-saved
 *    register);
 *  - the random draw's (u64)(u32) product by 0x10000 is what leaves the
 *    `lsls rX, zero, #16; orrs` pair and the hoisted zero;
 *  - case 3 passes the species to POKE_TOOL_SetupPartyParamEx as a fresh table read.
 */
void TR_TOOL_BuildParty(u32 trid, void *party, u16 heap)
{
    u32 gender;
    TrTrainerRecord *td;
    int i;
    void *tp;
    void *mon;
    int h;
    u32 pid;
    long long seed;
    int j;
    u32 iv;

    POKEPARTY_InitEx(party, 6);
    h = (heap & 0x7FFF) | 0x8000;
    td = GFL_HEAP_Alloc(h, 0x14, 0, g_020A76DC, 387);
    tp = GFL_HEAP_Alloc(h, 0x6C, 0, g_020A76DC, 388);
    mon = GFL_HEAP_Alloc(h, POKE_TOOL_GetPartyParamSize(), 0, g_020A76DC, 389);
    TPOKE_DATA_ReadRecord((void *)trid, td);
    TPOKE_DATA_ReadParty((void *)trid, tp);
    if (TPOKE_DATA_GetGenderValue(td->genderClass) == 1) {
        gender = 0x78;
    } else {
        gender = 0x88;
    }

    switch (td->partyType) {
    case 0: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->partyCount; i++) {
            TR_TOOL_AdjustPersonality(((TrPartyMon *)tp)[i].species, ((TrPartyMon *)tp)[i].form, ((TrPartyMon *)tp)[i].ability, &gender, heap);
            level = ((TrPartyMon *)tp)[i].level;
            dv = ((TrPartyMon *)tp)[i].dv;
            species = ((TrPartyMon *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->genderClass; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            TR_TOOL_FinalizePartyMember(trid, mon, ((TrPartyMon *)tp)[i].form, ((TrPartyMon *)tp)[i].ability);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    case 1: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->partyCount; i++) {
            TR_TOOL_AdjustPersonality(((TrPartyMonMoves *)tp)[i].species, ((TrPartyMonMoves *)tp)[i].form, ((TrPartyMonMoves *)tp)[i].ability, &gender, heap);
            level = ((TrPartyMonMoves *)tp)[i].level;
            dv = ((TrPartyMonMoves *)tp)[i].dv;
            species = ((TrPartyMonMoves *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->genderClass; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            for (j = 0; j < 4; j++) {
                POKE_TOOL_SetMoveSlot(mon, ((TrPartyMonMoves *)tp)[i].moves[j], (u8)j);
            }
            TR_TOOL_FinalizePartyMember(trid, mon, ((TrPartyMonMoves *)tp)[i].form, ((TrPartyMonMoves *)tp)[i].ability);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    case 2: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->partyCount; i++) {
            TR_TOOL_AdjustPersonality(((TrPartyMonItem *)tp)[i].species, ((TrPartyMonItem *)tp)[i].form, ((TrPartyMonItem *)tp)[i].ability, &gender, heap);
            level = ((TrPartyMonItem *)tp)[i].level;
            dv = ((TrPartyMonItem *)tp)[i].dv;
            species = ((TrPartyMonItem *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->genderClass; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            POKE_TOOL_SetPartyValue(mon, 6, ((TrPartyMonItem *)tp)[i].item);
            TR_TOOL_FinalizePartyMember(trid, mon, ((TrPartyMonItem *)tp)[i].form, ((TrPartyMonItem *)tp)[i].ability);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    case 3: {
        int dv;
        u16 level;
        u16 species;

        for (i = 0; i < td->partyCount; i++) {
            TR_TOOL_AdjustPersonality(((TrPartyMonItemMoves *)tp)[i].species, ((TrPartyMonItemMoves *)tp)[i].form, ((TrPartyMonItemMoves *)tp)[i].ability, &gender, heap);
            level = ((TrPartyMonItemMoves *)tp)[i].level;
            dv = ((TrPartyMonItemMoves *)tp)[i].dv;
            species = ((TrPartyMonItemMoves *)tp)[i].species;
            pid = dv + level + species + trid;
            seed = pid;
            for (j = 0; j < td->genderClass; j++) {
                seed = seed * 0x5D588B656C078965LL + 0x269EC3;
                pid = (u32)((((u64)seed >> 32) * 0x10000) >> 32);
            }
            pid = (pid << 8) + gender;
            iv = (u8)(dv * 31 / 255);
            POKE_TOOL_SetupPartyParamEx(mon, ((TrPartyMonItemMoves *)tp)[i].species, level, 0xFFFFFFFF00000000ULL,
                          (iv & 31) | ((iv & 31) << 5) | ((iv & 31) << 10) | ((iv & 31) << 15) | ((iv & 31) << 20) | ((iv & 31) << 25),
                          pid);
            POKE_TOOL_SetPartyValue(mon, 6, ((TrPartyMonItemMoves *)tp)[i].item);
            for (j = 0; j < 4; j++) {
                POKE_TOOL_SetMoveSlot(mon, ((TrPartyMonItemMoves *)tp)[i].moves[j], (u8)j);
            }
            TR_TOOL_FinalizePartyMember(trid, mon, ((TrPartyMonItemMoves *)tp)[i].form, ((TrPartyMonItemMoves *)tp)[i].ability);
            POKEPARTY_Add(party, mon);
        }
        break;
    }
    }
    GFL_HEAP_Free(td);
    GFL_HEAP_Free(tp);
    GFL_HEAP_Free(mon);
}

void TR_TOOL_AdjustPersonality(u32 species, u32 form, int adjustFlags, u32 *personalityLow, u16 heapId)
{
    u32 genderAdjust = adjustFlags & 0xf;
    u32 abilityAdjust = (adjustFlags & 0xf0) >> 4;
    u32 personal;

    if (adjustFlags == 0)
        return;

    personal = (u32)POKE_PERSONAL_Create((u16)species, (u16)form, heapId);

    if (genderAdjust != 0) {
        *personalityLow = POKE_PERSONAL_GetParam((struct PersonalData *)personal, 0x14);
        if (genderAdjust == 1)
            *personalityLow = *personalityLow + 2;
        else
            *personalityLow = *personalityLow - 2;
    }

    if (abilityAdjust == 1)
        *personalityLow &= ~(u32)1;
    else if (abilityAdjust == 2)
        *personalityLow |= (u32)1;

    POKE_PERSONAL_Delete((void *)personal);
}

/*
 * tr_tool.c: finish one trainer party member.  Field 9 (friendship) is
 * 0xFF unless one of the four moves (fields 0x36..0x39) is 0xDA, then 0;
 * field 0x6F takes form; the 0xF0 nibble of abilityFlags selects the ability
 * path (0x30: POKE_TOOL_SetAbility, otherwise POKE_TOOL_GetPersonalParam with field 0x1A or
 * 0x1B); two trainer/species pairs force a fixed nature, the rest take
 * (personality >> 8) % 25.
 *
 * What closed the old 248-byte near miss (docs/notes/TR_TOOL_FinalizePartyMember.c.txt):
 * the register the note read as a copy of the loop counter (`adds r6, r4,
 * #0` before the loop) is the constant 0, kept in r6 for the call's third
 * argument and for `found = 0`.  That zero occupies the fourth callee-saved
 * register across the loop, which is what spills species to sp+0xC.  The
 * tail is the remainder of _s32_div_f (r1), so `% 25`, not `/ 25`.
 */
void TR_TOOL_FinalizePartyMember(u32 trainerId, void *mon, u32 form, u32 abilityFlags)
{
    s32 moveSlot;
    u32 friendship = 0xff;
    u32 species;
    u32 abilityField;
    u32 abilityField2;
    u32 abilityMode;
    u32 trainerIdBase;

    species = (u16)POKE_TOOL_GetPartyValue(mon, 5, 0);
    for (moveSlot = 0; moveSlot < 4; moveSlot++) {
        if (POKE_TOOL_GetPartyValue(mon, 0x36 + moveSlot, 0) == 0xda) {
            friendship = 0;
        }
    }
    POKE_TOOL_SetPartyValue(mon, 9, friendship);
    POKE_TOOL_SetPartyValue(mon, 0x6f, form);

    abilityMode = abilityFlags & 0xf0;
    if (abilityMode == 0x30) {
        POKE_TOOL_SetAbility(mon, species, form);
    } else if (abilityMode != 0) {
        abilityField = 0x1a;
        abilityField2 = 0x1b;
        if (POKE_TOOL_GetPersonalParam(species, (u16)form, 0x1b) != 0 && abilityMode == 0x20) {
            abilityField = abilityField2;
        }
        POKE_TOOL_SetPartyValue(mon, 0xa, POKE_TOOL_GetPersonalParam(species, (u16)form, abilityField));
    }

    trainerIdBase = 0x24a;
    if (trainerId == trainerIdBase && species == trainerIdBase + 0x39) {
        POKE_TOOL_SetNature(mon, 0xd);
        return;
    }
    trainerIdBase = 0x24b;
    if (trainerId == trainerIdBase && species == trainerIdBase + 0x39) {
        POKE_TOOL_SetNature(mon, 0xa);
        return;
    }
    POKE_TOOL_SetNature(mon, (u8)(((s32)POKE_TOOL_GetPartyValue(mon, 0, 0) >> 8) % 0x19));
}
