/*
 * file:     btl_msg.c
 * unit:     yes
 * function: BTL_MSG_Init, BTL_MSG_Exit, BTL_MSG_SetPokeName, BTL_MSG_SetPokeSpecies, BTL_MSG_SetPokeNickname, BTL_MSG_SetClientValue, BTL_MSG_SetClientName, BTL_MSG_FormatArgs, BTL_MSG_FormatWithSide, BTL_MSG_BuildString, BTL_MSG_DispatchTagged, BTL_MSG_FindWordTag, BTL_MSG_CountWordTags, BTL_MSG_ExpandTags, BTL_MSG_BuildStandard, BTL_MSG_BuildStandardSingle, BTL_MSG_BuildStandardPair, BTL_MSG_BuildMoveEffectA, BTL_MSG_BuildMoveEffectB, BTL_MSG_BuildMoveEffectC, BTL_MSG_BuildClientAction, BTL_MSG_BuildItemUse, BTL_MSG_BuildPlainEntry, BTL_MSG_GetUiString, BTL_MSG_BuildUiString, BTL_MSG_BuildUiStringFlagged, BTL_MSG_BuildTrainerString, BTL_MSG_BuildTrainerStringBody, BTL_MSG_BuildBallStatusOpen, BTL_MSG_BuildBallStatusRefresh
 * address:  0x021EEC78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btl_adapter.c by tools/splitfile.py.
 *
 * symbols:
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   gBtlMsgState     0x021F6398  data  ov093  a4
 *   sBtlMsgBankFileIds     0x021F3990  data  ov093  a2
 *   WORDSET_Delete  0x0201ED04  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   BTL_SIDE_GetPokeById  0x021B9940  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   WORDSET_SetSlotMonSpeciesName  0x0201EE84  thumb
 *   BTL_MAIN_GetTrainerType  0x021BA020  thumb  ov093
 *   WORDSET_SetSlotFromMsgBF  0x0201F0F8  thumb
 *   BTL_MAIN_IsTrainerSlotNpc  0x021B9F70  thumb  ov093
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   BTL_MAIN_GetTrainerId  0x021BA004  thumb  ov093
 *   BTL_MAIN_GetTrainerNameAndType  0x021B9FAC  thumb  ov093
 *   BTL_MAIN_GetTrainerHandle  0x021BA064  thumb  ov093
 *   BTL_MAIN_UpdateCommPlayerSupport  0x021BA080  thumb  ov093
 *   TPOKE_DATA_GetGenderValue  0x0202A3CC  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_SetSlotFromMsgBE  0x0201F134  thumb
 *   BTL_MAIN_IsLocalSide  0x021B8BD0  thumb  ov093
 *   sBtlMsgSidePairIds     0x021F39A0  data  a2
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   sBtlMsgBuilders  0x021F39D8  data  a4
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   PRINTSYS_GetTagChar  0x0201D5C4  thumb
 *   PRINTSYS_IsWordSlotTag  0x0201D5CC  thumb
 *   PRINTSYS_GetTagParam  0x0201D670  thumb
 *   PRINTSYS_GetTagGroup  0x0201D5F4  thumb
 *   PRINTSYS_GetTagKind  0x0201D658  thumb
 *   PRINTSYS_SkipTag  0x0201D688  thumb
 *   STRBUF_GetChars  0x02045A90  arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_SetSlotFromMsgB6 0x0201EF8C thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   WORDSET_SetSlotFromMsgC7 0x0201F020 thumb
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_MAIN_IsOpposingPos  0x021B8CE8  thumb  ov093
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 */
#include "btl_adapter_shared_types.h"

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))

#define va_arg(ap, t) (*(t *)((ap += 4) - 4))

typedef signed int s32;

typedef char *va_list;

struct BtlMain;

struct BtlPokeList;

struct BtlPoke;

struct WordSet;

struct MsgBank;

struct Strbuf;

/* Message formatter state (gBtlMsgState). */
struct BtlMsgState {
    struct BtlMain *battle;       /* 0x00 */
    struct BtlPokeList *pokeList;   /* 0x04 */
    struct WordSet *wordSet;        /* 0x08 */
    struct Strbuf *msgBuf;          /* 0x0c */
    struct MsgBank *banks[8];       /* 0x10 */
    u32 args[8];                    /* 0x30 argument table of the variadic builder */
    u16 heapId;                     /* 0x50 */
    u16 pad52;
    u32 clientId;                   /* 0x54 viewing client */
    u16 plainWording;               /* 0x58 nonzero: skip the own/foe/ally wording */
    u16 useSpeciesName;             /* 0x5a nonzero: pokemon tags print the species */
};

/* Table of tags with their own builder (sBtlMsgBuilders). */
struct BtlMsgBuilder {
    u16 tag;
    u16 pad;
    void (*build)(struct Strbuf *dest, u32 msgId, u32 *args);
};

/* Argument block of BTL_MSG_BuildMoveEffectA. */
typedef struct {
    u32 clientId;
    u32 value;
    int entry;
    int tier;
} BtlMsgEffectArgsA;

/* Argument block of BTL_MSG_BuildMoveEffectB. */
typedef struct {
    u32 clientId;
    int entry;
    int tier;
} BtlMsgEffectArgsB;
struct BtlMain;

extern int BTL_MAIN_CheckSetupStatusFlag(struct BtlMain *main, s32 mask);

extern struct WordSet *WORDSET_CreateDefault(u32 heapId);

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 WORDSET_Delete(struct WordSet *wordSet);

extern void STRBUF_Delete(struct Strbuf *buf);

extern u32 MSGDATA_Delete(struct MsgBank *bank);
struct BtlSide;
struct BtlPokeParam;

extern struct BtlPokeParam *BTL_SIDE_GetPokeById(struct BtlSide *side, u8 pokeId);
struct PokemonParam;

extern struct PokemonParam *BTL_POKEPARAM_GetDisplayMon(struct BtlPokeParam *pp);

extern void WORDSET_SetSlotMonNickname(struct WordSet *wordSet, u32 slot, void *mon);

extern struct PokemonParam *BTL_POKEPARAM_GetMon(struct BtlPokeParam *pp);

extern void WORDSET_SetSlotMonSpeciesName(struct WordSet *wordSet, u32 slot, void *mon);

extern unsigned short BTL_MAIN_GetTrainerType(struct BtlMain *main, s32 slot);

extern void WORDSET_SetSlotFromMsgBF(struct WordSet *wordSet, u32 slot, u32 value);

extern int BTL_MAIN_IsTrainerSlotNpc(struct BtlMain *main, s32 slot);

extern u32 BTL_MAIN_GetCompetitor(struct BtlMain *main);

extern u16 BTL_MAIN_GetTrainerId(struct BtlMain *main, s32 slot);

extern u32 BTL_MAIN_GetTrainerNameAndType(struct BtlMain *main, s32 slot, u32 *outTrainerType);

extern s32 BTL_MAIN_GetTrainerHandle(struct BtlMain *main, s32 slot);

extern struct Strbuf *BTL_MAIN_UpdateCommPlayerSupport(struct BtlMain *battle);

extern u8 TPOKE_DATA_GetGenderValue(u32 trainerClass);

extern void WORDSET_SetSlotTag(struct WordSet *words, u32 slot, struct Strbuf *src, u32 grammarCase, u32 isPlural, u32 gender);

extern void WORDSET_SetSlotMyStatus(struct WordSet *wordSet, u32 slot, struct Strbuf *src);

extern void WORDSET_SetSlotFromMsgBE(struct WordSet *wordSet, u32 slot, u32 value);

extern int BTL_MAIN_IsLocalSide(struct BtlMain *main, u8 side);

extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);

extern void WORDSET_CopyTaggedText(struct WordSet *wordSet, struct Strbuf *dest, struct Strbuf *src);

extern u16 STRBUF_GetEosChar(void);

extern u32 PRINTSYS_GetTagChar(void);

extern u32 PRINTSYS_IsWordSlotTag(const u16 *tag);

extern u32 PRINTSYS_GetTagParam(const u16 *tag, u32 index);

extern u32 PRINTSYS_GetTagGroup(const u16 *tag);

extern u32 PRINTSYS_GetTagKind(const u16 *tag);

extern u16 *PRINTSYS_SkipTag(u16 *tag);

extern u16 *STRBUF_GetChars(struct Strbuf *buf);

extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 slot, u32 value, u32 digits, u32 padding, u32 charSet);

extern void WORDSET_SetSlotFromMsgB6(struct WordSet *wordSet, u32 slot, u32 value);

extern void WORDSET_SetSlotFromMsgCB(struct WordSet *wordSet, u32 slot, u32 value);

extern void WORDSET_SetSlotFromMsg36(struct WordSet *wordSet, u32 slot, u32 value);

extern void WORDSET_SetSlotFromMsgC7(struct WordSet *wordSet, u32 slot, u32 value);

extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 clientId);

extern int BTL_MAIN_IsOpposingPos(void *unusedWork, s32 posA, s32 posB);

extern u8 BTL_MAIN_GetOwnClientId(struct BtlMain *main);

extern struct BtlMsgState gBtlMsgState;

extern const u16 sBtlMsgBankFileIds[];

extern const u16 sBtlMsgSidePairIds[];

extern struct BtlMsgBuilder sBtlMsgBuilders[];

void BTL_MSG_Init(struct BtlMain *battle, u32 clientId, struct BtlPokeList *pokeList, u32 heapId);

void BTL_MSG_Exit(void);

void BTL_MSG_SetPokeName(u8 pokeId, u32 slot);

void BTL_MSG_SetPokeSpecies(u8 pokeId, u32 slot);

void BTL_MSG_SetPokeNickname(u8 pokeId, u8 slot);

void BTL_MSG_SetClientValue(struct WordSet *wordSet, u8 slot, u8 clientId);

void BTL_MSG_SetClientName(struct WordSet *wordSet, u8 slot, u8 clientId);

void BTL_MSG_FormatArgs(struct Strbuf *dest, u16 msgId, u32 argCount, ...);

void BTL_MSG_FormatWithSide(struct Strbuf *dest, u16 msgId, u32 *args);

void BTL_MSG_BuildString(struct Strbuf *dest, u32 msgId, u32 *args);

void BTL_MSG_DispatchTagged(struct Strbuf *dest, u16 msgId, u32 *args);

u16 *BTL_MSG_FindWordTag(u16 *text, u32 *outGroup, u16 *outKind, u8 *outSlot);

u8 BTL_MSG_CountWordTags(struct Strbuf *text);

void BTL_MSG_ExpandTags(struct Strbuf *text, const u32 *values, struct WordSet *wordSet);

void BTL_MSG_BuildStandard(struct Strbuf *dest, u16 msgId, u32 *args);

void BTL_MSG_BuildStandardSingle(struct Strbuf *dest, u32 msgId, u32 *args);

void BTL_MSG_BuildStandardPair(struct Strbuf *dest, u16 msgId, u32 *args);

void BTL_MSG_BuildMoveEffectA(struct Strbuf *dest, u32 msgId, BtlMsgEffectArgsA *args);

void BTL_MSG_BuildMoveEffectB(struct Strbuf *dest, u32 msgId, BtlMsgEffectArgsB *args);

void BTL_MSG_BuildMoveEffectC(struct Strbuf *dest, int msgId, u32 *args);

void BTL_MSG_BuildClientAction(struct Strbuf *dest, u32 msgId, u32 *args);

void BTL_MSG_BuildItemUse(struct Strbuf *dest, u8 clientId, u16 entry);

void BTL_MSG_BuildPlainEntry(struct Strbuf *dest, u16 entry, int alternate);

void BTL_MSG_GetUiString(struct Strbuf *dest, u32 msgId);

void BTL_MSG_BuildUiString(struct Strbuf *dest, u32 msgId, u32 *args);

void BTL_MSG_BuildUiStringFlagged(struct Strbuf *dest, u32 msgId, u32 *args);

void BTL_MSG_BuildTrainerString(struct Strbuf *dest, u32 msgId, u32 *args);

void BTL_MSG_BuildTrainerStringBody(struct Strbuf *dest, u32 msgId, u32 *args);

void BTL_MSG_BuildBallStatusOpen(struct Strbuf *dest, u32 ball0, u32 ball1, u32 ball2, u32 ball3, u32 ball4, u32 ball5);

void BTL_MSG_BuildBallStatusRefresh(struct Strbuf *dest, u32 ball0, u32 ball1, u32 ball2, u32 ball3, u32 ball4, u32 ball5);

void BTL_MSG_Init(struct BtlMain *battle, u32 clientId, struct BtlPokeList *pokeList, u32 heapId)
{
    int i;

    gBtlMsgState.battle = battle;
    gBtlMsgState.pokeList = pokeList;
    gBtlMsgState.heapId = heapId;
    gBtlMsgState.clientId = clientId;
    gBtlMsgState.plainWording = BTL_MAIN_CheckSetupStatusFlag((struct BtlMain *)battle, 0x200);
    gBtlMsgState.useSpeciesName = 0;
    gBtlMsgState.wordSet = WORDSET_CreateDefault(heapId);
    gBtlMsgState.msgBuf = STRBUF_Create(0x200 >> 1, heapId);
    for (i = 0; i < 8; i++) {
        gBtlMsgState.banks[i] = MSGDATA_CreateFromArchive(0, 2, sBtlMsgBankFileIds[i], heapId);
    }
}

void BTL_MSG_Exit(void)
{
    int i;

    WORDSET_Delete(gBtlMsgState.wordSet);
    STRBUF_Delete(gBtlMsgState.msgBuf);
    for (i = 0; i < 8; i++)
        MSGDATA_Delete(gBtlMsgState.banks[i]);
}

void BTL_MSG_SetPokeName(u8 pokeId, u32 slot)
{
    WORDSET_SetSlotMonNickname(gBtlMsgState.wordSet, slot, BTL_POKEPARAM_GetDisplayMon(BTL_SIDE_GetPokeById((struct BtlSide *)gBtlMsgState.pokeList, pokeId)));
}

void BTL_MSG_SetPokeSpecies(u8 pokeId, u32 slot)
{
    WORDSET_SetSlotMonNickname(gBtlMsgState.wordSet, slot, BTL_POKEPARAM_GetMon(BTL_SIDE_GetPokeById((struct BtlSide *)gBtlMsgState.pokeList, pokeId)));
}

void BTL_MSG_SetPokeNickname(u8 pokeId, u8 slot)
{
    WORDSET_SetSlotMonSpeciesName(gBtlMsgState.wordSet, slot, BTL_POKEPARAM_GetDisplayMon(BTL_SIDE_GetPokeById((struct BtlSide *)gBtlMsgState.pokeList, pokeId)));
}

void BTL_MSG_SetClientValue(struct WordSet *wordSet, u8 slot, u8 clientId)
{
    WORDSET_SetSlotFromMsgBF(wordSet, slot, (u8)BTL_MAIN_GetTrainerType((struct BtlMain *)gBtlMsgState.battle, clientId));
}

void BTL_MSG_SetClientName(struct WordSet *wordSet, u8 slot, u8 clientId)
{
    u32 trainerClass;
    int trainerId;
    const void *trainerData;

    if (clientId != 4) {
        if (BTL_MAIN_IsTrainerSlotNpc((struct BtlMain *)gBtlMsgState.battle, clientId) != 0) {
            if (BTL_MAIN_GetCompetitor(gBtlMsgState.battle) == 1) {
                trainerId = BTL_MAIN_GetTrainerId((struct BtlMain *)gBtlMsgState.battle, clientId);
                if (trainerId != 0)
                    WORDSET_SetSlotFromMsgBE(wordSet, slot, trainerId);
            } else {
                trainerData = (void *)BTL_MAIN_GetTrainerNameAndType((struct BtlMain *)gBtlMsgState.battle, clientId, &trainerClass);
                WORDSET_SetSlotTag(wordSet, slot, (struct Strbuf *)trainerData, TPOKE_DATA_GetGenderValue(trainerClass), 1, 2);
            }
        } else {
            WORDSET_SetSlotMyStatus(wordSet, slot, (struct Strbuf *)BTL_MAIN_GetTrainerHandle((struct BtlMain *)gBtlMsgState.battle, clientId));
        }
    } else {
        WORDSET_SetSlotMyStatus(wordSet, slot, BTL_MAIN_UpdateCommPlayerSupport(gBtlMsgState.battle));
    }
}

/*
 * Variadic: copies argCount words into the eight-word table
 * BtlMsgState.args (zero-filling the rest), then hands the table
 * to BTL_MSG_FormatWithSide.
 */
void BTL_MSG_FormatArgs(struct Strbuf *dest, u16 msgId, u32 argCount, ...)
{
    va_list ap;
    u32 i;

    va_start(ap, argCount);
    for (i = 0; i < argCount; i++) {
        gBtlMsgState.args[i] = va_arg(ap, s32);
    }
    for (; i < 8; i++) {
        gBtlMsgState.args[i] = 0;
    }
    BTL_MSG_FormatWithSide(dest, msgId, gBtlMsgState.args);
}

void BTL_MSG_FormatWithSide(struct Strbuf *dest, u16 msgId, u32 *args)
{
    u32 i;

    for (i = 0; i < 27; i++) {
        if (msgId == sBtlMsgSidePairIds[i]) {
            if (BTL_MAIN_IsLocalSide((struct BtlMain *)gBtlMsgState.battle, (u8)*args) == 0)
                msgId = msgId + 1;
            break;
        }
    }
    BTL_MSG_BuildString(dest, msgId, args);
}

void BTL_MSG_BuildString(struct Strbuf *dest, u32 msgId, u32 *args)
{
    MSGDATA_ReadString(gBtlMsgState.banks[0], msgId, gBtlMsgState.msgBuf);
    BTL_MSG_ExpandTags(gBtlMsgState.msgBuf, args, gBtlMsgState.wordSet);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

void BTL_MSG_DispatchTagged(struct Strbuf *dest, u16 msgId, u32 *args)
{
    u32 i;

    for (i = 0; i < 14; i++) {
        if (msgId == sBtlMsgBuilders[i].tag) {
            sBtlMsgBuilders[i].build(dest, msgId, args);
            return;
        }
    }
    BTL_MSG_BuildStandard(dest, msgId, args);
}

/*
 * Walks a message string for the first 0xF000 tag that PRINTSYS_IsWordSlotTag calls a
 * word reference; the guard on text wraps the whole walk (two `return 0` tails).
 */
u16 *BTL_MSG_FindWordTag(u16 *text, u32 *outGroup, u16 *outKind, u8 *outSlot)
{
    u16 endMark;
    u32 tagMark;

    if (text != 0) {
        endMark = STRBUF_GetEosChar();
        tagMark = PRINTSYS_GetTagChar();
        while (*text != endMark) {
            if (*text == tagMark) {
                if (PRINTSYS_IsWordSlotTag(text) != 0) {
                    *outSlot = PRINTSYS_GetTagParam(text, 0);
                    *outGroup = PRINTSYS_GetTagGroup(text);
                    *outKind = PRINTSYS_GetTagKind(text);
                    return PRINTSYS_SkipTag(text);
                }
                text = PRINTSYS_SkipTag(text);
            } else {
                text = text + 1;
            }
        }
        return 0;
    }
    return 0;
}

u8 BTL_MSG_CountWordTags(struct Strbuf *text)
{
    u32 group;
    u16 kind;
    u8 slot;
    u16 *cursor;
    u8 count;

    cursor = STRBUF_GetChars(text);
    count = 0;
    if (cursor != 0) {
        do {
            cursor = BTL_MSG_FindWordTag(cursor, &group, &kind, &slot);
            if (cursor != 0 && group == 1) {
                if (kind == 1 || kind == 2 || kind == 12)
                    count = count + 1;
            }
        } while (cursor != 0);
    }
    return count;
}

/*
 * Two passes over message tags: count removed slots, then install values.
 * A u8 kind local narrows before argument setup; const values schedules
 * the index shift ahead of the last outgoing argument store.
 */
void BTL_MSG_ExpandTags(struct Strbuf *text, const u32 *values, struct WordSet *wordSet)
{
    u16 endMark;
    u32 tagMark;
    u8 removedBefore[8];
    u16 *cursor;
    u32 i;
    u32 slot;
    u32 valueIndex;
    u8 group;
    u8 kind;
    endMark = STRBUF_GetEosChar();
    tagMark = PRINTSYS_GetTagChar();
    for (i = 0; i < 8; i++)
        removedBefore[i] = 0;
    cursor = STRBUF_GetChars(text);
    while (*cursor != endMark) {
        if (*cursor == tagMark) {
            if (PRINTSYS_IsWordSlotTag(cursor)) {
                slot = PRINTSYS_GetTagParam(cursor, 0);
                if ((u8)PRINTSYS_GetTagGroup(cursor) == 1 && PRINTSYS_GetTagKind(cursor) == 14) {
                    for (i = slot + 1; i < 8; i++)
                        removedBefore[i]++;
                }
            }
            cursor = PRINTSYS_SkipTag(cursor);
        } else
            cursor++;
    }
    cursor = STRBUF_GetChars(text);
    while (*cursor != endMark) {
        if (*cursor == tagMark) {
            if (PRINTSYS_IsWordSlotTag(cursor)) {
                slot = PRINTSYS_GetTagParam(cursor, 0);
                valueIndex = slot;
                group = PRINTSYS_GetTagGroup(cursor);
                if (slot >= removedBefore[slot])
                    valueIndex = slot - removedBefore[slot];
                if (group == 2) {
                    kind = PRINTSYS_GetTagKind(cursor) + 1;
                    WORDSET_SetSlotNumber(wordSet, slot, values[valueIndex], kind, 0, 1);
                } else {
                    switch (PRINTSYS_GetTagKind(cursor)) {
                    case 14:
                        BTL_MSG_SetClientValue(wordSet, slot, values[valueIndex]);
                        break;
                    case 0:
                        BTL_MSG_SetClientName(wordSet, slot, values[valueIndex]);
                        break;
                    case 2:
                        if (gBtlMsgState.useSpeciesName == 0)
                            BTL_MSG_SetPokeName(values[valueIndex], slot);
                        else
                            BTL_MSG_SetPokeSpecies(values[valueIndex], slot);
                        break;
                    case 12:
                        BTL_MSG_SetPokeSpecies(values[valueIndex], slot);
                        break;
                    case 1:
                        BTL_MSG_SetPokeNickname(values[valueIndex], slot);
                        break;
                    case 3:
                        WORDSET_SetSlotFromMsgC7(wordSet, slot, values[valueIndex]);
                        break;
                    case 6:
                        WORDSET_SetSlotFromMsgB6(wordSet, slot, values[valueIndex]);
                        break;
                    case 7:
                        WORDSET_SetSlotFromMsgCB(wordSet, slot, values[valueIndex]);
                        break;
                    case 9:
                        WORDSET_SetSlotFromMsg36(wordSet, slot, values[valueIndex]);
                        break;
                    case 15:
                        WORDSET_SetSlotFromMsgC7(wordSet, slot, values[valueIndex]);
                        break;
                    }
                }
            }
            cursor = PRINTSYS_SkipTag(cursor);
        } else
            cursor++;
    }
}

void BTL_MSG_BuildStandard(struct Strbuf *dest, u16 msgId, u32 *args)
{
    MSGDATA_ReadString(gBtlMsgState.banks[1], msgId, gBtlMsgState.msgBuf);
    if (BTL_MSG_CountWordTags(gBtlMsgState.msgBuf) == 2)
        BTL_MSG_BuildStandardPair(dest, msgId, args);
    else
        BTL_MSG_BuildStandardSingle(dest, msgId, args);
}

/* Message offset (0, 1 or 2) for the side a client is on, 0 when wording is plain. */
static inline int BTL_MSG_GetSideVariant(u8 clientId)
{
    int sideVariant;
    if (gBtlMsgState.plainWording == 0 && BTL_MAIN_IsOpposingPos(gBtlMsgState.battle, (u8)gBtlMsgState.clientId, BTL_MAIN_PokeIdToClientIdThunk(clientId))) {
        if (BTL_MAIN_GetCompetitor(gBtlMsgState.battle) == 0 || BTL_MAIN_GetCompetitor(gBtlMsgState.battle) == 4) sideVariant = 1;
        else sideVariant = 2;
    } else sideVariant = 0;
    return sideVariant;
}

void BTL_MSG_BuildStandardSingle(struct Strbuf *dest, u32 msgId, u32 *args)
{
    int sideVariant;
    u8 clientId = *args;

    sideVariant = BTL_MSG_GetSideVariant(clientId);
    MSGDATA_ReadString(gBtlMsgState.banks[1], (u16)(msgId + sideVariant), gBtlMsgState.msgBuf);
    BTL_MSG_ExpandTags(gBtlMsgState.msgBuf, args, gBtlMsgState.wordSet);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

/*
 * lever: explicit msgId = msgId + variant avoids compound-assignment RHS narrowing.
 */
void BTL_MSG_BuildStandardPair(struct Strbuf *dest, u16 msgId, u32 *args)
{
    u8 secondClient = args[1];
    int firstVariant = BTL_MSG_GetSideVariant(args[0]);
    switch (firstVariant) {
    case 0:
        msgId = msgId + BTL_MSG_GetSideVariant(secondClient);
        break;
    case 1:
        msgId += 3;
        goto second;
    case 2:
        msgId += 5;
    default:
second:
        if (firstVariant == BTL_MSG_GetSideVariant(secondClient)) msgId++;
        break;
    }
    MSGDATA_ReadString(gBtlMsgState.banks[1], msgId, gBtlMsgState.msgBuf);
    BTL_MSG_ExpandTags(gBtlMsgState.msgBuf, args, gBtlMsgState.wordSet);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

/*
 * Twin of BTL_MSG_BuildMoveEffectB (partial sum in a named local, sideVariant added last).
 */
void BTL_MSG_BuildMoveEffectA(struct Strbuf *dest, u32 msgId, BtlMsgEffectArgsA *args)
{
    u8 entryIndex;
    int tierSelect;
    int sideVariant;
    u8 clientId;
    u32 position;

    entryIndex = args->entry - 1;
    tierSelect = 0;
    if (args->tier >= 3)
        tierSelect = 2;
    if (args->tier == 2)
        tierSelect = 1;
    msgId = (u16)(msgId + (u16)(tierSelect * 0x15));
    clientId = args->clientId;
    sideVariant = BTL_MSG_GetSideVariant(clientId);
    BTL_MSG_SetPokeName(args->clientId, 0);
    WORDSET_SetSlotFromMsg36(gBtlMsgState.wordSet, 1, args->value);
    position = msgId + entryIndex * 3;
    MSGDATA_ReadString(gBtlMsgState.banks[1], (u16)(position + sideVariant), gBtlMsgState.msgBuf);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

/*
 * Lever: the partial sum msgId + entryIndex * 3 is a named local (`position`)
 * and sideVariant is added last; written inline as
 * `msgId + entryIndex * 3 + sideVariant` the final add comes out with its
 * operands swapped (one byte).
 */
void BTL_MSG_BuildMoveEffectB(struct Strbuf *dest, u32 msgId, BtlMsgEffectArgsB *args)
{
    u8 entryIndex;
    int tierSelect;
    int sideVariant;
    u8 clientId;
    u32 position;

    entryIndex = args->entry - 1;
    tierSelect = 0;
    if (args->tier >= 3)
        tierSelect = 2;
    if (args->tier == 2)
        tierSelect = 1;
    msgId = (u16)(msgId + (u16)(tierSelect * 0x15));
    BTL_MSG_SetPokeName(args->clientId, 0);
    clientId = args->clientId;
    sideVariant = BTL_MSG_GetSideVariant(clientId);
    position = msgId + entryIndex * 3;
    MSGDATA_ReadString(gBtlMsgState.banks[1], (u16)(position + sideVariant), gBtlMsgState.msgBuf);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

void BTL_MSG_BuildMoveEffectC(struct Strbuf *dest, int msgId, u32 *args)
{
    u8 entryIndex = args[1] - 1;
    int sideVariant;
    int position;
    u8 clientId;

    BTL_MSG_SetPokeName(args[0], 0);
    clientId = args[0];
    sideVariant = BTL_MSG_GetSideVariant(clientId);
    position = msgId + entryIndex * 3;
    MSGDATA_ReadString(gBtlMsgState.banks[1], (u16)(position + sideVariant), gBtlMsgState.msgBuf);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

void BTL_MSG_BuildClientAction(struct Strbuf *dest, u32 msgId, u32 *args)
{
    u8 clientId = args[0];
    int msgIndex;

    if (clientId != BTL_MAIN_GetOwnClientId((struct BtlMain *)gBtlMsgState.battle)) {
        if (BTL_MAIN_IsTrainerSlotNpc((struct BtlMain *)gBtlMsgState.battle, clientId))
            msgIndex = 0x23;
        else
            msgIndex = 0x22;
    } else {
        msgIndex = 0x21;
    }
    MSGDATA_ReadString(gBtlMsgState.banks[0], msgIndex, gBtlMsgState.msgBuf);
    BTL_MSG_ExpandTags(gBtlMsgState.msgBuf, args, gBtlMsgState.wordSet);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

void BTL_MSG_BuildItemUse(struct Strbuf *dest, u8 clientId, u16 entry)
{
    int sideVariant;
    u16 base;

    sideVariant = BTL_MSG_GetSideVariant(clientId);
    BTL_MSG_SetPokeName(clientId, 0);
    base = entry * 3;
    MSGDATA_ReadString(gBtlMsgState.banks[2], (u16)(base + sideVariant), gBtlMsgState.msgBuf);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

void BTL_MSG_BuildPlainEntry(struct Strbuf *dest, u16 entry, int alternate)
{
    u16 msgIndex;

    if (entry != 0) {
        msgIndex = (entry - 1) * 3;
        if (alternate == 0)
            msgIndex = msgIndex + 1;
        else
            msgIndex = msgIndex + 2;
        MSGDATA_ReadString(gBtlMsgState.banks[7], msgIndex, dest);
    }
}

void BTL_MSG_GetUiString(struct Strbuf *dest, u32 msgId)
{
    MSGDATA_ReadString(gBtlMsgState.banks[3], msgId, dest);
}

void BTL_MSG_BuildUiString(struct Strbuf *dest, u32 msgId, u32 *args)
{
    BTL_MSG_BuildUiStringFlagged(dest, msgId, args);
}

void BTL_MSG_BuildUiStringFlagged(struct Strbuf *dest, u32 msgId, u32 *args)
{
    MSGDATA_ReadString(gBtlMsgState.banks[5], msgId, gBtlMsgState.msgBuf);
    gBtlMsgState.useSpeciesName = 1;
    BTL_MSG_ExpandTags(gBtlMsgState.msgBuf, args, gBtlMsgState.wordSet);
    gBtlMsgState.useSpeciesName = 0;
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

/*
 * Tail-call stub (ldr r3,[pc]; bx r3) to BTL_MSG_BuildTrainerStringBody; callee of BTLV_CORE_BuildMessage case 6.
 */
void BTL_MSG_BuildTrainerString(struct Strbuf *dest, u32 msgId, u32 *args)
{
    BTL_MSG_BuildTrainerStringBody(dest, msgId, args);
}

/*
 * Unlabelled leaf, callee of the tail stub 0x021EF6E8 that BTLV_CORE_BuildMessage calls.
 * Twin of BTL_MSG_BuildUiStringFlagged without the useSpeciesName stores, using the +0x28 slot.
 */
void BTL_MSG_BuildTrainerStringBody(struct Strbuf *dest, u32 msgId, u32 *args)
{
    MSGDATA_ReadString(gBtlMsgState.banks[6], msgId, gBtlMsgState.msgBuf);
    BTL_MSG_ExpandTags(gBtlMsgState.msgBuf, args, gBtlMsgState.wordSet);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

void BTL_MSG_BuildBallStatusOpen(struct Strbuf *dest, u32 ball0, u32 ball1, u32 ball2, u32 ball3, u32 ball4, u32 ball5)
{
    MSGDATA_ReadString(gBtlMsgState.banks[3], 0x10, gBtlMsgState.msgBuf);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 0, ball0, 2, 0, 1);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 1, ball1, 2, 0, 1);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 2, ball2, 2, 0, 1);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 3, ball3, 2, 0, 1);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 4, ball4, 2, 0, 1);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 5, ball5, 2, 0, 1);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}

void BTL_MSG_BuildBallStatusRefresh(struct Strbuf *dest, u32 ball0, u32 ball1, u32 ball2, u32 ball3, u32 ball4, u32 ball5)
{
    MSGDATA_ReadString(gBtlMsgState.banks[3], 0x11, gBtlMsgState.msgBuf);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 0, ball0, 3, 0, 1);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 1, ball1, 3, 0, 1);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 2, ball2, 3, 0, 1);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 3, ball3, 3, 0, 1);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 4, ball4, 3, 0, 1);
    WORDSET_SetSlotNumber(gBtlMsgState.wordSet, 5, ball5, 3, 0, 1);
    WORDSET_CopyTaggedText(gBtlMsgState.wordSet, dest, gBtlMsgState.msgBuf);
}
