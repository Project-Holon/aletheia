/*
 * file:     poke_regulation.c
 * unit:     yes
 * function: POKE_CRYPTO_XorBlock, POKE_CRYPTO_NextRandom, POKE_CRYPTO_Checksum, POKE_TOOL_IsDefaultName, POKE_TOOL_ApplyNatureModifier, POKE_TOOL_GetNatureModifier, POKE_TOOL_SetDefaultName, POKE_TOOL_SetNameFromSpecies, POKE_TOOL_LoadExpTable, POKE_TOOL_GetExpValue, POKE_TOOL_GetBoxSubstruct, POKE_TOOL_GetPersonalData, POKE_TOOL_GetPersonalGender, POKE_TOOL_GetPersonalParam, POKE_TOOL_SetLevelAndRecalc, POKE_TOOL_CopyPartyPokemon, POKE_TOOL_GetPlateTypeForwarder, POKE_TOOL_GetBoxParamIndex, POKE_TOOL_NormalizeForm, POKE_TOOL_FilterSpecies, POKE_REGULATION_IsInSpeciesTable, POKE_REGULATION_CheckPokemon, POKE_REGULATION_CheckSelection, POKE_REGULATION_CheckPartyUsable, POKE_REGULATION_CheckPokemonFlags, POKE_REGULATION_CheckParty, POKE_REGULATION_AdjustLevel, POKE_REGULATION_AdjustPartyLevels, POKE_REGULATION_ResetPartyNicknames, POKE_REGULATION_Load, POKE_REGULATION_LoadInto, POKE_REGULATION_BuildPartySizeLine, POKE_REGULATION_BuildLevelLine, POKE_REGULATION_GetBannedSpeciesLine, POKE_REGULATION_GetSpeciesClauseLine, POKE_REGULATION_GetItemClauseLine, POKE_REGULATION_GetBattleModeLine, POKE_REGULATION_CreateText, POKE_REGULATION_DeleteText, POKE_REGULATION_FindValidOrder, POKE_REGULATION_CheckOrder, POKE_REGULATION_NextOrder, POKE_REGULATION_GetDataSize
 * address:  0x02019A50
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from pokeparty.c at 0x0201A920 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   poke_regulation_File 0x020A72F0 data
 *   gSpeciesNameBank   0x020A7370  data
 *   gNameBuf   0x021462F0  data
 *   func_02019B04_Table  0x0209E324  data
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   gExpTableBuf       0x02146398  data
 *   gBlockOrder  0x0209E3A4  data
 *   gPersonalCache   0x02146270  data
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_GetExpForLevel  0x02018584  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   sub_0209E280_Map  0x0209E280  data
 *   d_0209E42C 0x0209E42C data a2
 *   REGULATION_GetRuleValue   0x0200AE54  thumb
 *   REGULATION_GetVetoBit   0x0200AFD4  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKEPARTY_GetBattleReadyCount   0x0201AA50  thumb
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   WORDSET_SetSlotNumber   0x0201EFA4  thumb
 *   STRBUF_Create   0x020457B0  arm
 *   MSGDATA_ReadString   0x02045CAC  arm
 *   WORDSET_CopyTaggedText   0x0201F250  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   GFL_HEAP_Alloc 0x02030734  arm
 *   STRBUF_Delete 0x02045808  arm
 *   MSGDATA_CreateFromArchive 0x02045B38  arm
 *   POKE_REGULATION_LineFns  0x0209E444  data
 *   MSGDATA_Delete   0x02045C04  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   POKE_REGULATION_InitialOrder      0x0209E424  data
 *   POKE_PERSONAL_LoadData 0x0201ADA4 thumb
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   WORDSET_CheckF448  0x0201F448  thumb
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 */
struct MsgBank;
struct Pokemon;
struct Party;
struct PersonalData;
struct WordSet;
struct Strbuf;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned long long u64;

#include "poke_tool_types.h"

/* Cache of the last personal-data record fetched (species, form, data). */
struct PersonalCache {
    u16 form;
    u16 species;
    u8  data[0x10];
};

/* Party pokemon record, 0xDC bytes. */
struct PartyPokemon {
    u32 words[0x37];
};

/* Battle regulation data (0x534 bytes in the save; only the fields read here). */
struct Regulation {
    u8 reserved0[2];
    u8 minPartySize;
    u8 maxPartySize;
    u8 levelValue;
    u8 levelRule;
    u8 reserved6[2];
    u8 speciesClause;
    u8 itemClause;
    u8 bannedSpecies[0x52];
    u8 otherRules[0x4F];
    u8 battleMode;
};

/* Regulation summary: the message bank, one label and one rule line per
 * entry, and the battle mode used to pick the last line. */
struct RegulationText {
    struct MsgBank *bank;
    struct Strbuf  *labels[6];
    struct Strbuf  *lines[6];
    u8              battleMode;
};

/* Builds one rule line: (regulation, word set, text, scratch, heap). */
typedef struct Strbuf *(*RegulationLineFn)(const struct Regulation *, struct WordSet *,
                                           struct RegulationText *, struct Strbuf *, u16);

extern void MSGDATA_ReadUnits(struct MsgBank *bank, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 WORDSET_CheckF448(const u16 *a, const u16 *b);
extern struct Pokemon *POKE_TOOL_Dummy();
extern u32   POKE_TOOL_GetBoxValue(struct Pokemon *mon, u32 paramId, u32 value);
extern void  POKE_TOOL_SetBoxValue(struct Pokemon *mon, u32 paramId, const void *value);
extern void  ARC_TOOL_ReadMember(void *dst, u32 archiveId, u32 memberId);
extern u32  POKE_TOOL_GetPartyValue(struct Pokemon *mon, u32 paramId, u32 value);
extern void POKE_TOOL_SetPartyValue(struct Pokemon *mon, u32 paramId, u32 value);
extern u32  POKE_TOOL_GetExpForLevel(u16 species, u16 form, u16 level);
extern void POKE_TOOL_RecalcParam(struct Pokemon *mon);
extern u32 POKE_PERSONAL_GetParam(const struct PersonalData *data, u32 field);
extern u32 REGULATION_GetRuleValue(const struct Regulation *reg, u32 ruleId);
extern u32 REGULATION_GetVetoBit(const struct Regulation *reg, u32 ruleId, s32 value);
extern u32 POKEPARTY_GetCount(struct Party *party);
extern void MI_CpuFill8(void *dst, u8 v, u32 n);
extern struct Pokemon *POKEPARTY_GetMember(struct Party *party, u32 index);
extern u32 POKEPARTY_GetBattleReadyCount(struct Party *party);
extern void *ARC_TOOL_LoadMember(unsigned int archiveId, unsigned int memberId, unsigned int heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 slot, u32 number, u32 digits, u32 padMode, u32 flags);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *format);
extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void STRBUF_Delete(struct Strbuf *str);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 GFL_HEAP_Free(void *p);
void POKE_CRYPTO_XorBlock(u16 *data, u32 size, u32 seed);
u16 POKE_CRYPTO_NextRandom(u32 *state);
u16 POKE_CRYPTO_Checksum(const u16 *data, u32 size);
u32 POKE_TOOL_IsDefaultName(struct BoxPokemon *box);
u32 POKE_TOOL_ApplyNatureModifier(u32 nature, u32 stat, u32 statIndex);
s8 POKE_TOOL_GetNatureModifier(u32 nature, u32 statIndex);
void POKE_TOOL_SetDefaultName(struct Pokemon *mon);
void POKE_TOOL_SetNameFromSpecies(struct Pokemon *mon);
void POKE_TOOL_LoadExpTable(u32 species, void *dst);
u32 POKE_TOOL_GetExpValue(u32 species, u32 index);
u32 POKE_TOOL_GetPlateType(u32 item);
void *POKE_TOOL_GetBoxSubstruct(struct BoxPokemon *box, u32 personality, u32 blockIndex);
void *POKE_TOOL_GetPersonalData(u32 species, u32 form);
u32 POKE_TOOL_GetPersonalGender(const struct PersonalData *data);
u32 POKE_TOOL_GetPersonalParam(u16 species, u16 form, u32 field);
void POKE_TOOL_SetLevelAndRecalc(struct Pokemon *mon, u32 level);
void POKE_TOOL_CopyPartyPokemon(const struct PartyPokemon *src, struct PartyPokemon *dest);
unsigned int POKE_TOOL_GetPlateTypeForwarder(unsigned int item);
u32 POKE_TOOL_GetBoxParamIndex(u32 paramId);
u32 POKE_TOOL_NormalizeForm(u16 species, u16 form);
int POKE_TOOL_FilterSpecies(u16 species, int value);
int POKE_REGULATION_IsInSpeciesTable(unsigned short species);
int POKE_REGULATION_CheckPokemon(const struct Regulation *reg, struct Pokemon *mon);
int POKE_REGULATION_CheckSelection(u32 reg, u32 party, u32 order);
int POKE_REGULATION_CheckPartyUsable(const struct Regulation *reg, struct Party *party);
int POKE_REGULATION_CheckPokemonFlags(const struct Regulation *reg, struct Pokemon *mon, u32 *flags);
int POKE_REGULATION_CheckParty(const struct Regulation *reg, struct Party *party, u32 *flags);
u32 POKE_REGULATION_AdjustLevel(const struct Regulation *reg, u32 level);
void POKE_REGULATION_AdjustPartyLevels(const struct Regulation *reg, struct Party *party);
void POKE_REGULATION_ResetPartyNicknames(const struct Regulation *reg, struct Party *party, u32 unused);
void *POKE_REGULATION_Load(int memberId, int heapId);
void POKE_REGULATION_LoadInto(int memberId, void *dst);
struct Strbuf *POKE_REGULATION_BuildPartySizeLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct Strbuf *POKE_REGULATION_BuildLevelLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct Strbuf *POKE_REGULATION_GetBannedSpeciesLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct Strbuf *POKE_REGULATION_GetSpeciesClauseLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct Strbuf *POKE_REGULATION_GetItemClauseLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct Strbuf *POKE_REGULATION_GetBattleModeLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId);
struct RegulationText *POKE_REGULATION_CreateText(const struct Regulation *reg, struct WordSet *wordSet, u16 heapId, u32 battleMode);
void POKE_REGULATION_DeleteText(struct RegulationText *text);
int POKE_REGULATION_FindValidOrder(const struct Regulation *reg, struct Party *party, char *picked);
int POKE_REGULATION_CheckOrder(const struct Regulation *reg, struct Party *party, u8 *order, char *picked, u32 *flags);
int POKE_REGULATION_NextOrder(u8 *order);
int POKE_REGULATION_GetDataSize(void);
void POKE_PERSONAL_LoadData(u32 species, int form, void *dst);
extern const char poke_regulation_File[];
extern struct MsgBank *gSpeciesNameBank;
extern u16   gNameBuf[];
extern const s8 func_02019B04_Table[][5];
extern u32   gExpTableBuf[];
extern const u8 gBlockOrder[32][4];
extern struct PersonalCache gPersonalCache;
extern u16 sub_0209E280_Map[];
extern const unsigned short d_0209E42C[];
extern RegulationLineFn POKE_REGULATION_LineFns[6];
extern const u8 POKE_REGULATION_InitialOrder[6];









/*
 * The three primitives the whole save record in this region is protected
 * with.  POKE_CRYPTO_NextRandom is one step of the linear congruential generator
 * `s = s * 0x41C64E6D + 0x6073` returning the middle halfword of the new
 * state, POKE_CRYPTO_XorBlock XOR masks a byte range with that stream halfword by
 * halfword, and POKE_CRYPTO_Checksum is the plain halfword sum used as the checksum.
 *
 * POKE_CRYPTO_XorBlock opens `push {r0, r1, r2, r3}` and closes `pop {r3}` /
 * `add sp, #0x10` / `bx r3`, which is what taking the address of a register
 * parameter costs on this front end; see
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md.  The
 * seed is passed by value and updated in place through that home slot, so a
 * caller's seed is never modified, which is what lets POKE_TOOL_DecodeBoxBlock mask the
 * same area twice with the same seed to undo itself.
 *
 * POKE_CRYPTO_NextRandom carries no label in the generated listing.
 */
void POKE_CRYPTO_XorBlock(u16 *data, u32 size, u32 seed)
{
    u32 i = 0;
    u32 halfwords = size >> 1;

    if (halfwords != 0) {
        u32 *state = &seed;

        do {
            data[i] ^= POKE_CRYPTO_NextRandom(state);
            i++;
        } while (i < halfwords);
    }
}









u16 POKE_CRYPTO_NextRandom(u32 *state)
{
    *state = *state * 0x41C64E6D + 0x6073;
    return (u16)(*state >> 16);
}









u16 POKE_CRYPTO_Checksum(const u16 *data, u32 size)
{
    u16 sum = 0;
    u32 i = 0;
    u32 halfwords = size >> 1;

    if (halfwords != 0) {
        do {
            sum = (u16)(sum + data[i]);
            i++;
        } while (i < halfwords);
    }
    return sum;
}









/*
 * "Is the name in substruct C still the species' default name": it renders the
 * species name for substruct A's species id into the shared 0x20 halfword
 * buffer at 0x021462F0 and compares it with substruct C's own name, returning
 * 1 when they are equal.  POKE_TOOL_SetBoxValueRaw (src/matched/POKE_TOOL_SetBoxValueRaw.c) calls it
 * from ids 0x73 and 0x74 and stores the result in substruct B +0x10 bit 31,
 * which is the bit POKE_TOOL_GetBoxValueRaw reads back as id 0x75.  Those two calls are
 * the only references to this address in the image.
 *
 * The result local is declared before the two substruct fetches, which is what
 * puts `movs r5, #0` in front of the first call rather than after the second.
 *
 * The message bank at 0x020A7370 is a global pointer, so its address is a
 * build property and has to be re-derived for a White build rather than
 * copied; the 0x20 is a halfword count and the species id is data, so nothing
 * else here is version specific.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019ABC.c \
 *       --addr 0x02019ABC --thumb
 */
u32 POKE_TOOL_IsDefaultName(struct BoxPokemon *box)
{
    u32 isDefault = 0;
    struct BoxPokemonBlockA *blockA = (struct BoxPokemonBlockA *)POKE_TOOL_GetBoxSubstruct(box, box->personality, 0);
    void *blockC = POKE_TOOL_GetBoxSubstruct(box, box->personality, 2);

    MSGDATA_ReadUnits(gSpeciesNameBank, blockA->species, gNameBuf, 0x20);
    if (WORDSET_CheckF448(gNameBuf, blockC) == 0) {
        isDefault = 1;
    }
    return isDefault;
}









/*
 * Scales b by a per (a, n) table entry of -1, 0 or 1; the multipliers are
 * 0x5A and 0x6E, which are 90 and 110 percent. Both arms are written out in
 * full and the compiler cross jumps their common muls/truncate/divide tail
 * into one block that the missing default branches past, which is
 * docs/idioms/switch-arms-tail-merge.md; hoisting the multiplication out of
 * the switch puts the default branch to that block instead of past it and
 * costs eight bytes.
 *
 * The table at 0x0209E324 is witnessed by the pool word of the neighbouring
 * leaf POKE_TOOL_GetNatureModifier.c (seeded via layout/function_starts.txt), and this
 * file's own pool word witnesses it for that one: the unit_02005DF8 /
 * unit_02005E30 pairwise treatment.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019B04.c \
 *       --addr 0x02019B04 --thumb
 */
u32 POKE_TOOL_ApplyNatureModifier(u32 nature, u32 stat, u32 statIndex)
{
    s8 modifier;

    if (statIndex >= 6) {
        return stat;
    }
    modifier = func_02019B04_Table[nature][statIndex - 1];
    switch (modifier) {
    case 1:
        stat = (u16)((u16)(stat * 0x6E) / 100);
        break;
    case -1:
        stat = (u16)((u16)(stat * 0x5A) / 100);
        break;
    }
    return stat;
}









/*
 * The unlabelled leaf whose pool word is the second image-wide reference to
 * the table at 0x0209E324; traced via layout/function_starts.txt. Its pool
 * word witnesses the table for unit_02019B04.c and vice versa.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_GetNatureModifier.c \
 *       --func POKE_TOOL_GetNatureModifier --addr 0x02019B44
 */
s8 POKE_TOOL_GetNatureModifier(u32 nature, u32 statIndex)
{
    return func_02019B04_Table[nature][statIndex - 1];
}









/*
 *           POKE_TOOL_GetPlateType
 *
 * The first five of the seven functions between POKE_TOOL_IsDefaultName and the cache
 * helper at 0x02019C54.  The range stops at 0x02019C38 on purpose: the two
 * functions after it, POKE_TOOL_GetBoxSubstruct and POKE_TOOL_GetPersonalData, each reach a data
 * object through a pool word that is the object's only reference in the whole
 * image (0x0209E3A4 at 0x02019C50 and 0x02146274 at 0x02019C78), so the
 * `literal` class has no outside witness for either and both cap at MATCH
 * however they are written.  Cutting in front of them leaves these five
 * clean.
 *
 * POKE_TOOL_SetDefaultName reaches POKE_TOOL_Dummy, which src/matched/unit_020185F0.c
 * proves is an empty `bx lr`, and then calls POKE_TOOL_SetNameFromSpecies with whatever r0
 * holds, with no register saved across the first call.  That only compiles
 * from a declaration in which POKE_TOOL_Dummy returns a value, so this unit
 * declares it `void *POKE_TOOL_Dummy(void)` and passes the result straight on;
 * declaring it `void` the way unit_020185F0.c does forces a callee-saved
 * register and a four byte longer prologue.  The two declarations disagree,
 * and the image cannot say which one the original header carried, because an
 * empty function's return value is unobservable.
 *
 * POKE_TOOL_LoadExpTable is docs/idioms/tail-call-is-a-pool-word-and-bx.md: it permutes
 * three arguments into an ARM callee at 0x02048F4C and has no prologue at all.
 *
 * POKE_TOOL_GetPlateType is the plate-to-type table of ids 0xAE and 0xAF of
 * POKE_TOOL_GetBoxValueRaw: sixteen consecutive item ids from 0x12A map to sixteen type
 * ids and everything else to 0.  The switch value arrives as a pool word
 * rather than a `subs` immediate only because 0x12A does not fit the eight bit
 * form, so it is an ordinary constant and not the linker symbol of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * VERSION SENSITIVITY: POKE_TOOL_GetPlateType's sixteen case labels are item ids and
 * its sixteen results are type ids, and POKE_TOOL_SetNameFromSpecies passes id 5 (species)
 * and id 0x74 (the name) of the record.  None of them is a version flag and
 * there is no exclusive-species table here, but the item ids 0x12A..0x139 are
 * content numbering and are the values to re-read first for a White build.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019B58.c \
 *       --addr 0x02019B58 --thumb
 */
void POKE_TOOL_SetDefaultName(struct Pokemon *mon)
{
    POKE_TOOL_SetNameFromSpecies(POKE_TOOL_Dummy());
}









void POKE_TOOL_SetNameFromSpecies(struct Pokemon *mon)
{
    u32 species = POKE_TOOL_GetBoxValue(mon, 5, 0);

    MSGDATA_ReadUnits(gSpeciesNameBank, species, gNameBuf, 0x20);
    POKE_TOOL_SetBoxValue(mon, 0x74, gNameBuf);
}









void POKE_TOOL_LoadExpTable(u32 species, void *dst)
{
    ARC_TOOL_ReadMember(dst, 0x11, species);
}









u32 POKE_TOOL_GetExpValue(u32 species, u32 index)
{
    POKE_TOOL_LoadExpTable(species, gExpTableBuf);
    return gExpTableBuf[index];
}









u32 POKE_TOOL_GetPlateType(u32 item)
{
    switch (item) {
    case 0x12A: return 9;
    case 0x12B: return 10;
    case 0x12C: return 12;
    case 0x12D: return 11;
    case 0x12E: return 14;
    case 0x12F: return 1;
    case 0x130: return 3;
    case 0x131: return 4;
    case 0x132: return 2;
    case 0x133: return 13;
    case 0x134: return 6;
    case 0x135: return 5;
    case 0x136: return 7;
    case 0x137: return 15;
    case 0x138: return 16;
    case 0x139: return 8;
    }
    return 0;
}










/*
 * note:     28 bytes including its pool word, one function
 * note:     re-verified 2026-09-21: EXACT.  The MATCH cap was lifted by the
 *           sole-ref widening of 2026-09-21, not by any edit to the C:
 *           the data address this file reaches now attests as
 *           sole-ref/data.  Promoted from src/pending/ unchanged.
 *
 * The substruct permuter the whole poke_tool.c field machinery reaches every
 * block through: bits 13 to 17 of the personality word select one of 32
 * orderings, and the ordering's n-th byte is the offset of the n-th 0x20 byte
 * substruct inside the 0x80 byte block area at +0x08, so the table at
 * 0x0209E3A4 is 32 rows of four offsets drawn from 0x00, 0x20, 0x40 and 0x60.
 * src/matched/POKE_TOOL_SetBoxValueRaw.c, src/matched/unit_020188B4.c and
 * src/pending/POKE_TOOL_GetBoxValueRaw.c all index through it, and ov188 calls it eight
 * more times.
 *
 * Why it WAS capped (historical, resolved 2026-09-21): the one relocation is an ABS32 against the table at
 * 0x0209E3A4, and a scan of every word in all 242 regions finds exactly one
 * occurrence of that address, the pool word at 0x02019C50 inside this
 * function.  The `literal` class discards its only witness under the honesty
 * rule and no cut helps, because the range cannot be made smaller than the one
 * function that holds the pool word.  The `matched` class never applies to
 * data (docs/MATCHING.md, "The matched class"), so this is the same shape as
 * src/matched/ZONEDATA_GetSecondSpecialKind.c's private table and not the same shape as
 * POKE_TOOL_GetBoxValueRaw's runtime helper.  It closes the day anything else in the image
 * names 0x0209E3A4, or the day the table itself is a matched data entry.
 *
 * The neighbour POKE_TOOL_GetPersonalData, which is the one-entry memo in front of this
 * function, has no such site and was cut off into
 * src/matched/unit_02019C54.c rather than left capped with it
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md is the same
 * remedy applied to a data reference).
 *
 * What pinned the source: the mask is written `(pid & 0x3E000) >> 13` and not
 * `(pid >> 13) & 0x1F`.  The first is the `movs #0x3E` / `lsls #0xC` / `ands`
 * / `lsrs #0xD` the original has; the second folds to a `lsrs` and an `ands`
 * against a pooled 0x1F.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/POKE_TOOL_GetBoxSubstruct.c \
 *       --addr 0x02019C38 --thumb
 */
void *POKE_TOOL_GetBoxSubstruct(struct BoxPokemon *box, u32 personality, u32 blockIndex)
{
    return &box->blocks[gBlockOrder[(personality & 0x3E000) >> 13][blockIndex]];
}









/*
 * A one-entry memo: the (a, b) key pair at 0x02146270 and the 0x10 byte
 * object built for it at 0x02146274, rebuilt through POKE_PERSONAL_LoadData
 * (src/matched/unit_0201ADA4.c) only when the key changes.  POKE_TOOL_GetPersonalParam in
 * src/matched/unit_02019C7C.c is its only caller.
 *
 * Two things pin the source.
 *
 * The guard is one `||` expression rather than two ifs, which is what puts
 * both stores and the call in one block, per
 * docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md; and the
 * arm that falls through the first `bne` is the second half of the
 * disjunction, not the body.
 *
 * The two pool words 0x02146270 and 0x02146274 are one symbol and an addend,
 * per docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 * Declared as two symbols, 0x02146274 would need a witness of its own and the
 * only word in the image that holds it is the one under test.
 *
 * The neighbour POKE_TOOL_GetBoxSubstruct at the head of this packet is byte-correct but
 * MATCH-capped on its private table and is parked in
 * src/pending/POKE_TOOL_GetBoxSubstruct.c; this range is cut to exclude it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02019C54.c \
 *       --addr 0x02019C54 --thumb
 */
void *POKE_TOOL_GetPersonalData(u32 species, u32 form)
{
    if (species != gPersonalCache.species || form != gPersonalCache.form) {
        gPersonalCache.form = (u16)form;
        gPersonalCache.species = (u16)species;
        POKE_PERSONAL_LoadData(species, form, gPersonalCache.data);
    }
    return gPersonalCache.data;
}









/*
 * POKE_TOOL_CopyPartyPokemon carries no label in the generated listing: it saves r3 and r4
 * but not lr, so disasm.py's prologue sweep never fires on it and its 24 bytes
 * arrive as a run of .word between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  It is one
 * struct assignment: 27 ldm/stm pairs of eight bytes plus a trailing word is
 * 0xDC bytes, and the eight byte step is what says the record is at least four
 * aligned, which is docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x02019CF8, which is an eight byte tail call whose pool
 * word names 0x02019BBC.  That address carries no func_ label and no other
 * pool word in the image holds it, so neither the label nor the literal class
 * can attest it and the stub cannot be matched from either side.
 */
u32 POKE_TOOL_GetPersonalGender(const struct PersonalData *data)
{
    if (POKE_PERSONAL_GetParam(data, 0x1B) != 0) {
        return 2;
    }
    return 1;
}









u32 POKE_TOOL_GetPersonalParam(u16 species, u16 form, u32 field)
{
    return POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(species, form), field);
}









void POKE_TOOL_SetLevelAndRecalc(struct Pokemon *mon, u32 level)
{
    u32 species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    u32 form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);

    POKE_TOOL_SetPartyValue(mon, 8, POKE_TOOL_GetExpForLevel((u16)species, (u16)form, (u16)level));
    POKE_TOOL_RecalcParam(mon);
}









void POKE_TOOL_CopyPartyPokemon(const struct PartyPokemon *src, struct PartyPokemon *dest)
{
    *dest = *src;
}











/*
 * Plain forwarder to POKE_TOOL_GetPlateType (ldr r3, =target; bx r3).  Callee of
 * ov170 BOX2_MAIN_SyncItemForm.
 */
unsigned int POKE_TOOL_GetPlateTypeForwarder(unsigned int item)
{
    return POKE_TOOL_GetPlateType(item);
}











/*
 * Neither carries a label in the generated listing.  POKE_TOOL_GetBoxParamIndex
 * is a dense switch over 0x74..0x77 whose four arms each return a constant,
 * and the `subs r0, #0x74` in front of the `cmp`/`bhi` is the compiler's
 * normalisation of the range rather than anything the source wrote; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *
 * The range stops at 0x02019D58.  The two unlabelled search loops after it,
 * at 0x02019D58 and 0x02019D84, reproduce every concrete byte but read
 * halfword tables at 0x0209E280 and 0x0209E42C, and each of those addresses
 * appears in exactly one literal pool in the whole image, the one under test,
 * so the literal class discards its only witness and no cut helps.
 */
u32 POKE_TOOL_GetBoxParamIndex(u32 paramId)
{
    switch (paramId) {
    case 0x74:
        return 1;
    case 0x75:
        return 2;
    case 0x76:
        return 3;
    case 0x77:
        return 4;
    }
    return 0;
}











u32 POKE_TOOL_NormalizeForm(u16 species, u16 form)
{
    if (species != 0x28A) {
        if ((s32)form >= (s32)POKE_TOOL_GetPersonalParam(species, form, 0x20)) {
            form = 0;
        }
        return form;
    }
    if (form >= 2) {
        form = 0;
    }
    return form;
}










/*
 * note:     re-verified 2026-09-21: EXACT*.  The MATCH cap was lifted by the
 *           sole-ref widening of 2026-09-21, not by any edit to the C:
 *           the data address this file reaches now attests as
 *           sole-ref/data.  Promoted from src/pending/ unchanged.
 */
int POKE_TOOL_FilterSpecies(u16 species, int value)
{
    u16 i;

    if (value != 0) {
        for (i = 0; i < 4; i++)
            if (sub_0209E280_Map[i] == species)
                return 0;
    }
    return value;
}









/*
 * Witness leaf for ov119 POKETRADE_PROC_CanTradeMon: membership test in a 12 entry u16 table.
 */
int POKE_REGULATION_IsInSpeciesTable(unsigned short species)
{
    unsigned i;
    for (i = 0; i < 12; i++) {
        if (species == d_0209E42C[i])
            return 1;
    }
    return 0;
}











/*
 * A stat comparison against a threshold picked by selector 4 of the first
 * argument: selector 5 (one over the limit) and 6 (under it) are both
 * rejected with 2, and the tail reports 0x20 for the presence flag, 4 or
 * 0x40 for the two range checks, and 1 when there is no object at all.  The
 * two comparisons are signed, which is what `ble`/`bge` says.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckPokemon.c \
 *       --func POKE_REGULATION_CheckPokemon --addr 0x02019DA4 --cc 1.1p1 --thumb
 */
int POKE_REGULATION_CheckPokemon(const struct Regulation *reg, struct Pokemon *mon)
{
    u16 species = (u16)POKE_TOOL_GetPartyValue(mon, 5, 0);
    u16 item = (u16)POKE_TOOL_GetPartyValue(mon, 6, 0);
    int levelLimit;
    int levelRule;
    int level;
    int reason;

    if (reg == 0)
        return 1;

    levelLimit = REGULATION_GetRuleValue(reg, 4);
    levelRule = REGULATION_GetRuleValue(reg, 5);
    level = POKE_TOOL_GetPartyValue(mon, 0x9E, 0);

    switch (levelRule) {
    case 1:
        if (levelLimit > level)
            return 2;
        break;
    case 2:
        if (levelLimit < level)
            return 2;
        break;
    }

    reason = 0;
    if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) != 0)
        return 0x20;
    if (REGULATION_GetVetoBit(reg, 9, species) != 0)
        return 4;
    if (REGULATION_GetVetoBit(reg, 0xA, item) != 0)
        reason = 0x40;
    return reason;
}












/*
 * Maps a flag word to a small code: the four bits 2, 4, 0x20 and 0x40 all
 * answer 5 (one disjunction, so they share a single exit), then 8, 0x10,
 * 0x100, 0x80 and 1 each answer their own code and zero answers 0.  The
 * query is answered through two stack words whose addresses are passed to
 * POKE_REGULATION_CheckOrder, and the caller's second and third registers are forwarded
 * unchanged, so the query takes five arguments.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckSelection.c \
 *       --func POKE_REGULATION_CheckSelection --addr 0x02019E54 --cc 1.1p1 --thumb
 */
int POKE_REGULATION_CheckSelection(u32 reg, u32 party, u32 order)
{
    u64 picked;
    u32 flags;

    if (reg == 0)
        return 0;

    POKE_REGULATION_CheckOrder((struct Regulation *)reg, (struct Party *)party, (u8 *)order, (char *)(&picked), &flags);
    if (flags == 0)
        return 0;

    if ((flags & 2) || (flags & 4) || (flags & 0x20) || (flags & 0x40))
        return 5;
    if (flags & 8)
        return 2;
    if (flags & 0x10)
        return 3;
    if (flags & 0x100)
        return 1;
    if (flags & 0x80)
        return 7;
    if (flags & 1)
        return 4;
    return 0;
}












/*
 * EXACT*: the inferred extent runs 2 bytes past the 250-byte body because the
 * follower at 0x02019FD0 has no lr-saving prologue and so carries no label.
 * No byte differs.
 *
 * The party "is this team legal for the rule set" check.  It reads each
 * member's species (id 5) and form (id 0x9E) into two parallel u16[6] stack
 * arrays, zeroes the species of any member POKE_REGULATION_CheckPokemon rejects, then runs an
 * O(n^2) duplicate-species scan that zeroes the worse of each colliding pair
 * (worse = the larger form value) and decrements a running count.  If the
 * surviving count is below what REGULATION_GetRuleValue(ctx, 2) requires it answers 4;
 * otherwise the answer is 0 or 1 from POKE_REGULATION_FindValidOrder.
 *
 * Two layout tells pin the frame:
 *   - the 12-byte MI_CpuFill8 buffer is declared LAST, not first: the later
 *     declarator gets the lower stack address, which is what puts `pad` at
 *     sp+0x10 and `species` at sp+0x28
 *     (docs/idioms/local-declaration-order-is-stack-order.md).
 *   - the outer scan loop assigns its counter before its bound (`i = 0;`
 *     then `lim = n - 1;`), or the `movs r0,#0` and the `subs r0,r0,#1`
 *     swap places
 *     (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 *
 * VERSION SENSITIVITY: party ids 5 and 0x9E and the rule-set keys 7 and 2 are
 * content numbering; the team size 6 is the array bound and is structural.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckPartyUsable.c \
 *       --func POKE_REGULATION_CheckPartyUsable --addr 0x02019ED4 --cc 1.1p1 --thumb
 */
int POKE_REGULATION_CheckPartyUsable(const struct Regulation *reg, struct Party *party)
{
    u16 species[6];
    u16 levels[6];
    u8 unused[12];
    int partyCount;
    int usable;
    int i;
    int j;
    int last;
    int result;

    partyCount = POKEPARTY_GetCount(party);
    usable = partyCount;
    MI_CpuFill8(unused, 0, 12);
    for (i = 0; i < partyCount; i++) {
        struct Pokemon *mon = POKEPARTY_GetMember(party, i);

        species[i] = (u16)POKE_TOOL_GetPartyValue(mon, 5, 0);
        levels[i] = (u16)POKE_TOOL_GetPartyValue(mon, 0x9E, 0);
        if (POKE_REGULATION_CheckPokemon(reg, mon) != 0) {
            species[i] = 0;
            usable--;
        }
    }

    if ((int)REGULATION_GetRuleValue(reg, 7) == 0 && partyCount > 1) {
        i = 0;
        last = partyCount - 1;
        for (; i < last; i++) {
            for (j = i + 1; j < partyCount; j++) {
                if (species[i] == species[j] && species[i] != 0) {
                    if (levels[i] > levels[j]) {
                        species[i] = 0;
                    } else {
                        species[j] = 0;
                    }
                    usable--;
                }
            }
        }
    }

    if (usable < (int)REGULATION_GetRuleValue(reg, 2)) {
        return 4;
    }

    result = 0;
    if (POKE_REGULATION_FindValidOrder(reg, party, 0) != 1) {
        result = 1;
    }
    return result;
}












/*
 * EXACT* note: the 190 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A08E before the next labelled function at 0x0201A090.
 *
 * The same stat comparison as POKE_REGULATION_CheckPokemon, but it reports into the third
 * argument's word with or-bits instead of returning a code: bit 1 for a
 * selector 5 record above the threshold or a selector 6 one below it, bit 2
 * for the range check, bit 6 for the second one, and the return value stays 1
 * unless a bit was set.  The `*a2 |= 2; r = 0;` pair is written out in both
 * arms and the compiler cross-jumps them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckPokemonFlags.c \
 *       --func POKE_REGULATION_CheckPokemonFlags --addr 0x02019FD0 --cc 1.1p1 --thumb
 */
int POKE_REGULATION_CheckPokemonFlags(const struct Regulation *reg, struct Pokemon *mon, u32 *flags)
{
    u16 species = (u16)POKE_TOOL_GetPartyValue(mon, 5, 0);
    u16 item = (u16)POKE_TOOL_GetPartyValue(mon, 6, 0);
    int allowed = 1;
    int levelLimit;
    int levelRule;
    int level;

    if (reg == 0)
        return allowed;

    levelLimit = REGULATION_GetRuleValue(reg, 4);
    levelRule = REGULATION_GetRuleValue(reg, 5);
    level = POKE_TOOL_GetPartyValue(mon, 0x9E, 0);

    switch (levelRule) {
    case 1:
        if (levelLimit > level) {
            allowed = 0;
            *flags |= 2;
        }
        break;
    case 2:
        if (levelLimit < level) {
            allowed = 0;
            *flags |= 2;
        }
        break;
    }

    if (REGULATION_GetVetoBit(reg, 9, species) != 0) {
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            allowed = 0;
            *flags |= 4;
        }
    }
    if (REGULATION_GetVetoBit(reg, 0xA, item) != 0) {
        allowed = 0;
        *flags |= 0x40;
    }
    return allowed;
}











/*
 * poke_tool.c (wave 13): the party legality check against a rule set.
 * Three parallel six-entry u16 arrays (species, item, form) are collected
 * from the non-egg members; the rule set's queries 2 (minimum count),
 * 7 (duplicate species allowed), 8 (duplicate items allowed) and 0xB/0xC (a
 * required species/form) set bits 0x01/0x08/0x10/0x80 of *mask and the
 * error codes 4/2/3/7, a failing member check gives 5, and when nothing
 * failed POKE_REGULATION_FindValidOrder decides between 0 and 1.
 *
 * WHAT CLOSED IT (docs/notes/POKE_REGULATION_CheckParty.c.txt: 478 against 476, err
 * spilled to sp+8 with a six-register push): the arrays are indexed plainly,
 * `species[i]` -- the note's invented `j = i * 2; species[j >> 1]` was the
 * source of the `lsls/bics` fixups; the compiler itself CSEs `i * 2` into
 * the sp+8 slot.  Then the permuter (hill, one mutation) found the last
 * lever: in the duplicate-item test the mask update comes BEFORE the error
 * code (`*mask |= 0x10; err = 3;`), the opposite of the species test.  That
 * order is what keeps err in r7 for the whole function.
 *
 * EXACT* only because of the two-byte alignment pad at 0x0201A26A; the
 * follower 0x0201A26C is its own labelled EXACT entry.
 */
int POKE_REGULATION_CheckParty(const struct Regulation *reg, struct Party *party, u32 *flags)
{
    u16 species[6];
    u16 item[6];
    u16 levels[6];
    int i;
    int total;
    int levelSum;
    int error;
    struct Pokemon *mon;
    int k;
    int requiredSpecies, requiredForm;

    levelSum = 0;
    error = 0;
    if (reg == 0)
        return 0;
    for (i = 0; i < 6; i++) {
        species[i] = 0;
        levels[i] = 0;
        item[i] = 0;
    }
    total = POKEPARTY_GetBattleReadyCount(party);
    if (total < (int)REGULATION_GetRuleValue(reg, 2)) {
        *flags |= 1;
        error = 4;
    }
    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (POKE_REGULATION_CheckPokemonFlags(reg, mon, flags) == 0)
            error = 5;
        if (POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 0) {
            species[i] = POKE_TOOL_GetPartyValue(mon, 5, 0);
            item[i] = POKE_TOOL_GetPartyValue(mon, 6, 0);
            levels[i] = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
            levelSum += POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
        }
    }
    if ((int)REGULATION_GetRuleValue(reg, 7) == 0 && total > 1) {
        for (i = 0; i < 5; i++) {
            for (k = i + 1; k < 6; k++) {
                if (species[i] == species[k] && species[i] != 0) {
                    error = 2;
                    *flags |= 8;
                }
            }
        }
    }
    if ((int)REGULATION_GetRuleValue(reg, 8) == 0 && total > 1) {
        for (i = 0; i < 5; i++) {
            for (k = i + 1; k < 6; k++) {
                if (item[i] == item[k] && species[i] != 0 && item[i] != 0) {
                    *flags |= 0x10;
                    error = 3;
                }
            }
        }
    }
    requiredSpecies = (int)REGULATION_GetRuleValue(reg, 0xb);
    requiredForm = (int)REGULATION_GetRuleValue(reg, 0xc);
    i = 0;
    if (requiredSpecies != 0 && total > 1) {
        for (i = 0; i < 6; i++) {
            if (requiredSpecies == species[i] && requiredForm == levels[i])
                break;
        }
    }
    if (i == 6) {
        *flags |= 0x80;
        error = 7;
    }
    if (error == 0 && POKE_REGULATION_FindValidOrder(reg, party, 0) == 0)
        error = 1;
    return error;
}











/*
 * Picks the smaller (or larger, per selector 5) of a value read from the
 * object and the caller's second argument, with the selector 3 / 4 / 5 arms
 * emitted as a compare chain and the default falling through to the caller's
 * value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_AdjustLevel.c \
 *       --func POKE_REGULATION_AdjustLevel --addr 0x0201A26C --cc 1.1p1 --thumb
 */
u32 POKE_REGULATION_AdjustLevel(const struct Regulation *reg, u32 level)
{
    u32 levelValue = REGULATION_GetRuleValue(reg, 4);
    u32 levelRule = REGULATION_GetRuleValue(reg, 5);

    switch (levelRule) {
    case 3:
        if (level > levelValue)
            return levelValue;
        break;
    case 4:
        return levelValue;
    case 5:
        if (level < levelValue)
            return levelValue;
        break;
    }
    return level;
}











/*
 * EXACT* note: the 98 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A30A before the next labelled function at 0x0201A30C.
 *
 * Sweeps the records of the second argument and rewrites those whose 0xA9
 * flag is set and whose recomputed value disagrees with what the first
 * argument's own query returns.  The value from before the loop is a spilled
 * local, so it is re-read from the frame at the one place it is used.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_AdjustPartyLevels.c \
 *       --func POKE_REGULATION_AdjustPartyLevels --addr 0x0201A2A8 --cc 1.1p1 --thumb
 */
void POKE_REGULATION_AdjustPartyLevels(const struct Regulation *reg, struct Party *party)
{
    u32 levelValue = REGULATION_GetRuleValue(reg, 4);
    int i;

    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        struct Pokemon *mon = POKEPARTY_GetMember(party, i);

        if (POKE_TOOL_GetPartyValue(mon, 0xA9, 0) != 0) {
            u32 level = POKE_TOOL_GetPartyValue(mon, 0x9E, 0);

            if (POKE_REGULATION_AdjustLevel(reg, level) != level)
                POKE_TOOL_SetLevelAndRecalc(mon, levelValue);
        }
    }
}











/*
 * EXACT* note: the 70 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A352, then two unlabelled 12-byte argument-shuffling tail-call thunks at 0x0201A354 (calls 0x02048F60 with (0x69, a, b)) and 0x0201A364 (calls 0x02048F4C with (b, 0x69, a)), each followed by its own pool word, before the next labelled function at 0x0201A374.
 *
 * Guarded sweep over a record array: only when the object reports state zero
 * does it walk the records and act on those whose 0xA9 flag is set.  The
 * bound is re-evaluated at the bottom of the loop, so it stays a call in the
 * condition.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_ResetPartyNicknames.c \
 *       --func POKE_REGULATION_ResetPartyNicknames --addr 0x0201A30C --cc 1.1p1 --thumb
 */
void POKE_REGULATION_ResetPartyNicknames(const struct Regulation *reg, struct Party *party, u32 unused)
{
    int i;

    if (REGULATION_GetRuleValue(reg, 0x11) != 0)
        return;

    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        struct Pokemon *mon = POKEPARTY_GetMember(party, i);

        if (POKE_TOOL_GetPartyValue(mon, 0xA9, 0) != 0)
            POKE_TOOL_SetDefaultName(mon);
    }
}











/*
 * Witness leaf for ov021 SCRCMD_FLD_BATTLE_CheckPartyRegulation and SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames.
 */
void *POKE_REGULATION_Load(int memberId, int heapId)
{
    return ARC_TOOL_LoadMember(0x69, memberId, heapId);
}











/*
 * Unlabelled Thumb argument-shuffling tail-call thunk: ARC_TOOL_ReadMember(b, 0x69, a).
 */
void POKE_REGULATION_LoadInto(int memberId, void *dst)
{
    ARC_TOOL_ReadMember(dst, 0x69, memberId);
}










/*
 * Load one 0x40-byte sprite record whose mode word is chosen from the pair of
 * bytes at a0+2/+3: (1,6) selects 6, equal bytes select 7, a byte above 1
 * with 6 following selects 8 and anything else 9.  Both palette fields are
 * stamped through WORDSET_SetSlotNumber, the record is allocated against a4, its
 * slots are filled from *a2 through MSGDATA_ReadString and the pair is bound by
 * WORDSET_CopyTaggedText.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_BuildPartySizeLine.c \
 *       --func POKE_REGULATION_BuildPartySizeLine --addr 0x0201A374 --cc 1.1p1 --thumb
 */
struct Strbuf *POKE_REGULATION_BuildPartySizeLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    u32 messageId;
    struct Strbuf *line;

    if (reg->minPartySize == 1 && reg->maxPartySize == 6) {
        messageId = 6;
    } else if (reg->minPartySize == reg->maxPartySize) {
        messageId = 7;
    } else if (reg->minPartySize > 1 && reg->maxPartySize == 6) {
        messageId = 8;
    } else {
        messageId = 9;
    }
    WORDSET_SetSlotNumber(wordSet, 0, reg->minPartySize, 1, 0, 1);
    WORDSET_SetSlotNumber(wordSet, 1, reg->maxPartySize, 1, 0, 1);
    line = STRBUF_Create(0x40, heapId);
    MSGDATA_ReadString(text->bank, messageId, scratch);
    WORDSET_CopyTaggedText(wordSet, line, scratch);
    return line;
}










/*
 * poke_tool.c tail (wave 13), the twin of POKE_REGULATION_BuildPartySizeLine: pick the sprite
 * record's mode from the format byte at a0+5 (0 -> 6, 4 -> 0xb, 1 -> 0xd,
 * 2 -> 0xc, 3 -> 0xe, 5 -> 0xf, anything else 6; an if chain in that order,
 * the image tests it in source order), stamp the byte at a0+4 through
 * WORDSET_SetSlotNumber, allocate the 0x40-byte record against a4, fill it from *a2
 * and bind it with WORDSET_CopyTaggedText.
 *
 * WHAT CLOSED IT (docs/notes/pkt_0201A3F4.c.txt: 8 bytes out, the byte at
 * a0+4 loaded after the two outgoing stack stores instead of before): the
 * record parameter is `const u8 *`.  A load through a const pointer may move
 * above the stores to the outgoing-argument area; through a plain pointer it
 * may not.  Same lever as PARTICLE_CreateSystem and BUTTON_MAN_SetEmitterPos this wave.
 *
 * EXACT* because the follower at 0x0201A468 (a leaf that scans 0x52 bytes
 * from +0xa and tail-calls 0x02045EC0) carries no label.
 */
struct Strbuf *POKE_REGULATION_BuildLevelLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    u32 messageId;
    struct Strbuf *line;

    if (reg->levelRule == 0) {
        messageId = 6;
    } else if (reg->levelRule == 4) {
        messageId = 0xb;
    } else if (reg->levelRule == 1) {
        messageId = 0xd;
    } else if (reg->levelRule == 2) {
        messageId = 0xc;
    } else if (reg->levelRule == 3) {
        messageId = 0xe;
    } else if (reg->levelRule == 5) {
        messageId = 0xf;
    } else {
        messageId = 6;
    }
    WORDSET_SetSlotNumber(wordSet, 0, reg->levelValue, 3, 0, 1);
    line = STRBUF_Create(0x40, heapId);
    MSGDATA_ReadString(text->bank, messageId, scratch);
    WORDSET_CopyTaggedText(wordSet, line, scratch);
    return line;
}






struct Strbuf *POKE_REGULATION_GetBannedSpeciesLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    int i;
    u32 messageId;

    for (i = 0; i < 0x52; i++) {
        if (reg->bannedSpecies[i] != 0)
            break;
    }
    messageId = 0x10;
    if (i != 0x52)
        messageId = 0x11;
    return MSGDATA_AllocString(text->bank, messageId);
}






struct Strbuf *POKE_REGULATION_GetSpeciesClauseLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    u32 messageId = 0x12;

    if (reg->speciesClause != 1)
        messageId = 0x13;
    return MSGDATA_AllocString(text->bank, messageId);
}






struct Strbuf *POKE_REGULATION_GetItemClauseLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    u32 messageId = 0x14;

    if (reg->itemClause != 1)
        messageId = 0x15;
    return MSGDATA_AllocString(text->bank, messageId);
}






struct Strbuf *POKE_REGULATION_GetBattleModeLine(const struct Regulation *reg, struct WordSet *wordSet, struct RegulationText *text, struct Strbuf *scratch, u16 heapId)
{
    u32 messageId;
    u8 battleMode = text->battleMode;

    if (battleMode == 1) {
        messageId = 0x16;
    } else {
        messageId = 0x17;
        if (battleMode != 0)
            messageId = 0x16;
    }
    return MSGDATA_AllocString(text->bank, messageId);
}










/*
 * Wave 17 lane untried_small. What closed it (from 6 halfwords out): the heap
 * id parameter a2 is u16. The image homes it to the stack and reloads it for
 * every use (the allocator's first argument included); declared u32 it stays
 * in r2 and is copied, which was the whole parameter-homing residue.
 */
struct RegulationText *POKE_REGULATION_CreateText(const struct Regulation *reg, struct WordSet *wordSet, u16 heapId, u32 battleMode)
{
    struct RegulationText *text;
    struct Strbuf *scratch;
    int i;
    u32 regulationMode;

    text = (struct RegulationText *)GFL_HEAP_Alloc(heapId, 0x38, 1, poke_regulation_File, 0x312);
    text->bank = MSGDATA_CreateFromArchive(0, 2, 0xa5, heapId);
    scratch = STRBUF_Create(0x40, heapId);
    regulationMode = reg->battleMode;
    if (regulationMode == 2)
        text->battleMode = battleMode;
    else
        text->battleMode = regulationMode;
    for (i = 0; i < 6; i++) {
        text->labels[i] = MSGDATA_AllocString(text->bank, i);
        text->lines[i] = POKE_REGULATION_LineFns[i](reg, wordSet, text, scratch, heapId);
    }
    STRBUF_Delete(scratch);
    return text;
}










/*
 * EXACT* note: the 42 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A59A before the next labelled function at 0x0201A59C.
 *
 * Six records of 0x20 bytes, each with a pair of ARM calls at +4 and +0x1C,
 * then the object's first word through the ARM at 0x02045C04 and the object
 * itself through 0x020307B0.  The loop index is a signed int, so the bound
 * test is `blt` and no truncation appears.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_DeleteText.c \
 *       --func POKE_REGULATION_DeleteText --addr 0x0201A570 --cc 1.1p1 --thumb
 */
void POKE_REGULATION_DeleteText(struct RegulationText *text)
{
    int i;

    for (i = 0; i < 6; i++) {
        STRBUF_Delete(text->labels[i]);
        STRBUF_Delete(text->lines[i]);
    }
    MSGDATA_Delete(text->bank);
    GFL_HEAP_Free(text);
}










/*
 * Verified with:
 *   python tools/match.py one --src src/pending/POKE_REGULATION_FindValidOrder.c \
 *       --func POKE_REGULATION_FindValidOrder --addr 0x0201A59C --cc 1.1p1 --thumb
 */
int POKE_REGULATION_FindValidOrder(const struct Regulation *reg, struct Party *party, char *picked)
{
    char order[6];

    order[0] = POKE_REGULATION_InitialOrder[0];
    order[1] = POKE_REGULATION_InitialOrder[1];
    order[2] = POKE_REGULATION_InitialOrder[2];
    order[3] = POKE_REGULATION_InitialOrder[3];
    order[4] = POKE_REGULATION_InitialOrder[4];
    order[5] = POKE_REGULATION_InitialOrder[5];

    if (POKE_REGULATION_NextOrder((u8 *)order) != 0) {
        do {
            if (POKE_REGULATION_CheckOrder(reg, party, (u8 *)order, picked, 0) == 1) {
                return 1;
            }
        } while (POKE_REGULATION_NextOrder((u8 *)order) != 0);
    }

    return 0;
}










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckOrder.c  *       --func POKE_REGULATION_CheckOrder --addr 0x0201A5FC --cc 1.1p1 --thumb
 */
int POKE_REGULATION_CheckOrder(const struct Regulation *reg, struct Party *party, u8 *order, char *picked, u32 *flags)
{
    u8 count = 0;
    u32 speciesList[6] = {0};
    u32 formList[6] = {0};
    u32 itemList[6] = {0};
    u8 i;
    int allowed;
    u32 levelTotal;
    struct Pokemon *mon;
    u32 species;
    u32 levelCost;
    u32 levelBudget;
    u8 slot;
    u8 j;
    u32 item;
    u32 requiredSpecies;
    u8 k;
    u32 requiredForm;
    u32 reason;
    int found;

    levelTotal = 0;
    levelBudget = (u32)(int)REGULATION_GetRuleValue(reg, (int)6);

    if (picked != 0)
        *picked = 0;
    if (flags != 0)
        *flags = 0;

    for (i = 0; i < 6; i++) {
        if (order[i] == 0)
            continue;
        slot = (u8)(order[i] - 1);
        if ((int)slot >= (int)POKEPARTY_GetCount(party))
            continue;
        mon = POKEPARTY_GetMember(party, slot);
        species = POKE_TOOL_GetPartyValue(mon, 5, 0);
        item = POKE_TOOL_GetPartyValue(mon, 6, 0);
        levelCost = (u32)POKE_REGULATION_AdjustLevel(reg, POKE_TOOL_GetPartyValue(mon, 0x9e, 0));
        reason = POKE_REGULATION_CheckPokemon(reg, mon);
        if (reason != 0) {
            if (flags != 0)
                *flags |= reason;
            continue;
        }
        allowed = 1;
        for (j = 0; j < count; j++) {
            if ((int)REGULATION_GetRuleValue(reg, (int)7) == 0 && species == speciesList[j]) {
                allowed = 0;
                if (flags != 0)
                    *flags |= 8;
                break;
            }
            if ((int)REGULATION_GetRuleValue(reg, (int)8) == 0 && item != 0 && item == itemList[j]) {
                allowed = 0;
                if (flags != 0)
                    *flags |= 0x10;
                break;
            }
        }
        if (allowed == 0)
            continue;
        if (levelBudget != 0 && (u32)(levelTotal + levelCost) > levelBudget) {
            if (flags != 0)
                *flags |= 0x100;
            continue;
        }
        if (picked != 0)
            picked[count] = (char)(slot + 1);
        speciesList[count] = species;
        formList[count] = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
        itemList[count] = item;
        levelTotal = (u16)(levelTotal + (u16)levelCost);
        count = (u8)(count + 1);
        if ((int)count < (int)REGULATION_GetRuleValue(reg, (int)3))
            continue;
        if (flags != 0 && count < 6 && order[count] != 0)
            *flags |= 1;
        break;
    }

    if ((int)count >= (int)REGULATION_GetRuleValue(reg, (int)2)) {
        requiredSpecies = (u32)(int)REGULATION_GetRuleValue(reg, (int)0xb);
        found = 1;
        if (requiredSpecies != 0) {
            requiredForm = (u32)(int)REGULATION_GetRuleValue(reg, (int)0xc);
            found = 0;
            for (k = 0; k < count; k++) {
                if (requiredSpecies == speciesList[k] && requiredForm == formList[k]) {
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1)
            return 1;
        if (flags != 0)
            *flags |= 0x80;
    } else {
        if (flags != 0)
            *flags |= 1;
    }
    return 0;
}










/*
 * A base-7 odometer with a distinctness test: six nested counters (a[0]
 * outermost) over 0..6, and the innermost body returns 1 as soon as all six
 * values differ.  The entry `a[5]++` is the source's own first statement, not
 * a loop increment.
 *
 * The fifteen `!=` tests are one conjunction: every `cmp` in the listing
 * branches to the same increment block (0x0201A8B8) on equality, which is the
 * "guard chain sharing one exit block" spelling, not a chain of ifs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_NextOrder.c \
 *       --func POKE_REGULATION_NextOrder --addr 0x0201A858 --cc 1.1p1 --thumb
 */
int POKE_REGULATION_NextOrder(u8 *order)
{
    order[5]++;
    while (order[0] <= 6) {
        while (order[1] <= 6) {
            while (order[2] <= 6) {
                while (order[3] <= 6) {
                    while (order[4] <= 6) {
                        while (order[5] <= 6) {
                            if (order[0] != order[1] && order[0] != order[2] &&
                                order[0] != order[3] && order[0] != order[4] &&
                                order[0] != order[5] && order[1] != order[2] &&
                                order[1] != order[3] && order[1] != order[4] &&
                                order[1] != order[5] && order[2] != order[3] &&
                                order[2] != order[4] && order[2] != order[5] &&
                                order[3] != order[4] && order[3] != order[5] &&
                                order[4] != order[5]) {
                                return 1;
                            }
                            order[5]++;
                        }
                        order[5] = 1;
                        order[4]++;
                    }
                    order[4] = 1;
                    order[3]++;
                }
                order[3] = 1;
                order[2]++;
            }
            order[2] = 1;
            order[1]++;
        }
        order[1] = 1;
        order[0]++;
    }
    return 0;
}









/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
int POKE_REGULATION_GetDataSize(void)
{
    return 0x534;
}
