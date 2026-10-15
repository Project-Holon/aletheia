/*
 * file:     game_beacon_accessor.c
 * unit:     yes
 * function: GAME_BEACON_ACCESSOR_GetActionViewVariant, GAME_BEACON_ACCESSOR_RegisterRecordWords, GAME_BEACON_ACCESSOR_IsNoArgInvalid, GAME_BEACON_ACCESSOR_IsActionTrainerNoInvalid, GAME_BEACON_ACCESSOR_IsActionMonsNoInvalid, GAME_BEACON_ACCESSOR_IsNoValueInvalid, GAME_BEACON_ACCESSOR_IsActionMonsNoWithNicknameInvalid, GAME_BEACON_ACCESSOR_IsActionItemNoInvalid, GAME_BEACON_ACCESSOR_IsPlayTimeInvalid, GAME_BEACON_ACCESSOR_IsActionCountValueInvalid, GAME_BEACON_ACCESSOR_IsDistributionMonsNoInvalid, GAME_BEACON_ACCESSOR_IsDistributionItemNoInvalid, GAME_BEACON_ACCESSOR_IsActionMoveNoInvalid, GAME_BEACON_ACCESSOR_IsActionPresetEventInvalid, GAME_BEACON_ACCESSOR_IsActionByteValueInvalid, GAME_BEACON_ACCESSOR_IsActionHalfwordValueInvalid, GAME_BEACON_ACCESSOR_IsDistributionSerialInvalid
 * address:  0x02165FC0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from unit_02165FC0.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_BEACON_ACCESSOR_ActionTable  0x02171CE8  data  a1
 *   func_0201F31C  0x0201F31C  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   WORDSET_Callback  0x0201EE60  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   WORDSET_Callback_EF40  0x0201EF40  thumb
 *   WORDSET_Callback_EF4C  0x0201EF4C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F104  0x0201F104  thumb
 *   func_0201F134  0x0201F134  thumb
 *   func_0201F184  0x0201F184  thumb
 *   WORDSET_DrawF1E0  0x0201F1E0  thumb
 *   GAME_BEACON_ACCESSOR_GetPlayerName  0x02165C34  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetSex  0x02165D08  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetFreeText  0x02165D8C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionNo  0x02165E24  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionMonsNo  0x02165E34  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionItemNo  0x02165E78  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionCountValue  0x02165E8C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetDistributionMonsNo  0x02165E9C  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetDistributionItemNo  0x02165EAC  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetNickname  0x02165ECC  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionTrainerNo  0x02165F30  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetPresetEventValue  0x02165F64  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionSpecialValue  0x02165F74  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionWordValue  0x02165F84  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionByteValue  0x02165F94  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionHalfwordValue  0x02165FA4  thumb  ov010
 *   GAME_BEACON_ACCESSOR_GetActionCheckIndex  0x02165FB4  thumb  ov010
 */
#include "../arm9/game_beacon_types.h"

struct StrBuf;

struct WordSet;

typedef signed int     s32;

/* Per action type row of the table at 0x02171CE8. */
typedef struct ActionTypeRow {
    u8 printKind;           /* BeaconPrintKind used by the record printer */
    u8 viewVariant;         /* variant the beacon view passes to its layout code */
} ActionTypeRow;

/* How the value of an action is registered for printing. */
enum BeaconPrintKind {
    BEACON_PRINT_TRAINER_NO = 1,
    BEACON_PRINT_MONS_NO = 2,
    BEACON_PRINT_NICKNAME = 3,
    BEACON_PRINT_MONS_NO_AND_NICKNAME = 4,
    BEACON_PRINT_ITEM_NO = 5,
    BEACON_PRINT_SPECIAL_VALUE = 6,
    BEACON_PRINT_PRESET_EVENT = 7,
    BEACON_PRINT_DISTRIBUTION_MONS_NO = 8,
    BEACON_PRINT_DISTRIBUTION_ITEM_NO = 9,
    BEACON_PRINT_COUNT_VALUE = 10,
    BEACON_PRINT_WORD_VALUE = 11,
    BEACON_PRINT_BYTE_VALUE = 12,
    BEACON_PRINT_HALFWORD_VALUE = 13,
    BEACON_PRINT_FREE_TEXT = 14,
    BEACON_PRINT_NONE = 15
};

extern void func_0201F31C(struct WordSet *wordSet);

extern struct StrBuf *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_Delete(struct StrBuf *buf);

extern void func_0201EE0C(struct WordSet *wordSet, u32 bufferIndex, const void *str, u32 sex, u32 flag, u32 language);

extern void WORDSET_Callback(struct WordSet *wordSet, u32 bufferIndex, u16 value);

extern void func_0201EF34(struct WordSet *wordSet, u32 bufferIndex, u32 value);

extern void WORDSET_Callback_EF40(struct WordSet *wordSet, u32 bufferIndex, u32 value);

extern void WORDSET_Callback_EF4C(struct WordSet *wordSet, u32 bufferIndex, u32 value);

extern void func_0201EFA4(struct WordSet *wordSet, u32 bufferIndex, u32 value, u32 digits, u32 padding, u32 flag);

extern void func_0201F104(struct WordSet *wordSet, u32 bufferIndex, u32 value);

extern void func_0201F134(struct WordSet *wordSet, u32 bufferIndex, u32 value);

extern void func_0201F184(struct WordSet *wordSet, u32 bufferIndex, s32 value);

extern void WORDSET_DrawF1E0(struct WordSet *wordSet, u32 bufferIndex, u32 value);

extern void GAME_BEACON_ACCESSOR_GetPlayerName(GameBeaconInfo *info, void *buf);

extern u8 GAME_BEACON_ACCESSOR_GetSex(GameBeaconInfo *info);

extern int GAME_BEACON_ACCESSOR_GetFreeText(int info, int buf);

extern u16 GAME_BEACON_ACCESSOR_GetActionNo(GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionMonsNo(GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionItemNo(GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionCountValue(GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetDistributionMonsNo(GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetDistributionItemNo(GameBeaconInfo *info);

extern void GAME_BEACON_ACCESSOR_GetNickname(GameBeaconInfo *info, void *buf);

extern u16 GAME_BEACON_ACCESSOR_GetActionTrainerNo(GameBeaconInfo *info);

extern u32 GAME_BEACON_ACCESSOR_GetPresetEventValue(GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionSpecialValue(GameBeaconInfo *info);

extern u32 GAME_BEACON_ACCESSOR_GetActionWordValue(GameBeaconInfo *info);

extern u8 GAME_BEACON_ACCESSOR_GetActionByteValue(GameBeaconInfo *info);

extern u16 GAME_BEACON_ACCESSOR_GetActionHalfwordValue(GameBeaconInfo *info);

extern u8 GAME_BEACON_ACCESSOR_GetActionCheckIndex(u16 actionType);

u8 GAME_BEACON_ACCESSOR_GetActionViewVariant(u32 actionType);

void GAME_BEACON_ACCESSOR_RegisterRecordWords(GameBeaconInfo *info, struct WordSet *wordSet, u32 heapId);

int GAME_BEACON_ACCESSOR_IsNoArgInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionTrainerNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionMonsNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsNoValueInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionMonsNoWithNicknameInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionItemNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsPlayTimeInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionCountValueInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsDistributionMonsNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsDistributionItemNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionMoveNoInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionPresetEventInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionByteValueInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsActionHalfwordValueInvalid(GameBeaconInfo *info);

int GAME_BEACON_ACCESSOR_IsDistributionSerialInvalid(GameBeaconInfo *info);

extern const ActionTypeRow GAME_BEACON_ACCESSOR_ActionTable[];

/*
 * Second byte of the two-byte table row for an action type.
 */
u8 GAME_BEACON_ACCESSOR_GetActionViewVariant(u32 actionType)
{
    return GAME_BEACON_ACCESSOR_ActionTable[actionType].viewVariant;
}

/*
 * Registers the words of a record for message printing: its name into
 * buffer 0, then the action-specific value (number, string or item) into
 * buffers 1 and 2.
 */
void GAME_BEACON_ACCESSOR_RegisterRecordWords(GameBeaconInfo *info, struct WordSet *wordSet, u32 heapId)
{
    struct StrBuf *buf;
    u8 printKind;
    u32 value;

    func_0201F31C(wordSet);
    buf = STRBUF_Create(0x21, heapId);
    if (buf == 0)
        return;
    GAME_BEACON_ACCESSOR_GetPlayerName(info, buf);
    func_0201EE0C(wordSet, 0, buf, 0, 1, 2);
    printKind = GAME_BEACON_ACCESSOR_GetActionCheckIndex(GAME_BEACON_ACCESSOR_GetActionNo(info));
    switch (printKind) {
    case BEACON_PRINT_TRAINER_NO:
        value = GAME_BEACON_ACCESSOR_GetActionTrainerNo(info);
        func_0201F104(wordSet, 1, value);
        func_0201F134(wordSet, 2, value);
        break;
    case BEACON_PRINT_MONS_NO:
    case BEACON_PRINT_MONS_NO_AND_NICKNAME:
        WORDSET_Callback(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionMonsNo(info));
        if (printKind == BEACON_PRINT_MONS_NO)
            break;
    case BEACON_PRINT_NICKNAME:
        GAME_BEACON_ACCESSOR_GetNickname(info, buf);
        func_0201EE0C(wordSet, 2, buf, 0, 1, 2);
        break;
    case BEACON_PRINT_ITEM_NO:
        WORDSET_Callback_EF4C(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionItemNo(info));
        break;
    case BEACON_PRINT_SPECIAL_VALUE:
        func_0201EFA4(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionSpecialValue(info), 3, 0, 1);
        break;
    case BEACON_PRINT_PRESET_EVENT:
        func_0201EFA4(wordSet, 1, GAME_BEACON_ACCESSOR_GetPresetEventValue(info), 3, 0, 1);
        break;
    case BEACON_PRINT_DISTRIBUTION_MONS_NO:
        WORDSET_Callback(wordSet, 1, GAME_BEACON_ACCESSOR_GetDistributionMonsNo(info));
        break;
    case BEACON_PRINT_DISTRIBUTION_ITEM_NO:
        WORDSET_Callback_EF40(wordSet, 1, GAME_BEACON_ACCESSOR_GetDistributionItemNo(info));
        break;
    case BEACON_PRINT_COUNT_VALUE:
        func_0201EF34(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionCountValue(info));
        break;
    case BEACON_PRINT_WORD_VALUE:
        func_0201EFA4(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionWordValue(info), 1, 0, 1);
        break;
    case BEACON_PRINT_BYTE_VALUE:
        WORDSET_DrawF1E0(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionByteValue(info));
        break;
    case BEACON_PRINT_HALFWORD_VALUE:
        func_0201F184(wordSet, 1, GAME_BEACON_ACCESSOR_GetActionHalfwordValue(info));
        break;
    case BEACON_PRINT_FREE_TEXT:
        GAME_BEACON_ACCESSOR_GetFreeText((int)info, (int)buf);
        func_0201EE0C(wordSet, 1, buf, GAME_BEACON_ACCESSOR_GetSex(info), 1, 2);
        break;
    case BEACON_PRINT_NONE:
        break;
    }
    STRBUF_Delete(buf);
}

/*
 * Record field validators: each returns 1 when the field it checks is out
 * of range for its action kind. This one accepts everything.
 */
int GAME_BEACON_ACCESSOR_IsNoArgInvalid(GameBeaconInfo *info)
{
    return 0;
}

/* Trainer number at +0x34 must be 1..0x267. */
int GAME_BEACON_ACCESSOR_IsActionTrainerNoInvalid(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value >= 0x268)
        return 1;
    return 0;
}

/* Pokemon number at +0x32 must be 1..0x289. */
int GAME_BEACON_ACCESSOR_IsActionMonsNoInvalid(GameBeaconInfo *info)
{
    if (info->actionArg == 0 || info->actionArg > 0x289)
        return 1;
    return 0;
}

/* Accepts everything (actions without a value). */
int GAME_BEACON_ACCESSOR_IsNoValueInvalid(GameBeaconInfo *info)
{
    return 0;
}

/* Pokemon number at +0x32 must be 1..0x289 (actions that also carry a nickname). */
int GAME_BEACON_ACCESSOR_IsActionMonsNoWithNicknameInvalid(GameBeaconInfo *info)
{
    if (info->actionArg == 0 || info->actionArg > 0x289)
        return 1;
    return 0;
}

/* Item number at +0x34 must be 1..0x272. */
int GAME_BEACON_ACCESSOR_IsActionItemNoInvalid(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value > 0x272)
        return 1;
    return 0;
}

/* Play time: hours must be at most 999 and minutes at most 59. */
int GAME_BEACON_ACCESSOR_IsPlayTimeInvalid(GameBeaconInfo *info)
{
    if (info->playHours > 999 || info->playMinutes > 59)
        return 1;
    return 0;
}

/* Count value at +0x34 (32 bit) must be at most 99999. */
int GAME_BEACON_ACCESSOR_IsActionCountValueInvalid(GameBeaconInfo *info)
{
    if (info->actionData.wordValue > 99999)
        return 1;
    return 0;
}

/* Distributed pokemon number at +0x34 must be 1..0x289. */
int GAME_BEACON_ACCESSOR_IsDistributionMonsNoInvalid(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value > 0x289)
        return 1;
    return 0;
}

/* Distributed item number at +0x36 must be 1..0x272. */
int GAME_BEACON_ACCESSOR_IsDistributionItemNoInvalid(GameBeaconInfo *info)
{
    if (info->actionData.special.itemNo == 0 || info->actionData.special.itemNo > 0x272)
        return 1;
    return 0;
}

/* Move number at +0x34 must be 1..0x22F. */
int GAME_BEACON_ACCESSOR_IsActionMoveNoInvalid(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value >= 0x230)
        return 1;
    return 0;
}

/* Preset event number at +0x34 (32 bit) must be 1..7. */
int GAME_BEACON_ACCESSOR_IsActionPresetEventInvalid(GameBeaconInfo *info)
{
    if (info->actionData.wordValue == 0 || info->actionData.wordValue > 7)
        return 1;
    return 0;
}

/* Byte value at +0x34 must be at most 6. */
int GAME_BEACON_ACCESSOR_IsActionByteValueInvalid(GameBeaconInfo *info)
{
    if (info->actionData.byteValue > 6)
        return 1;
    return 0;
}

/* Halfword value at +0x34 must be below 0x30. */
int GAME_BEACON_ACCESSOR_IsActionHalfwordValueInvalid(GameBeaconInfo *info)
{
    if (info->actionData.value >= 0x30)
        return 1;
    return 0;
}

/* Distribution serial at +0x38 must be below 0x30. */
int GAME_BEACON_ACCESSOR_IsDistributionSerialInvalid(GameBeaconInfo *info)
{
    if (info->actionData.special.serial >= 0x30)
        return 1;
    return 0;
}
