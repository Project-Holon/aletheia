/*
 * file:     unit_02165FC0.c
 * unit:     yes
 * function: func_02165FC0, func_02165FCC, func_02166164, func_02166168, func_02166180, func_02166198, func_0216619C, func_021661B4, func_021661CC, func_021661EC, func_02166200, func_02166218, func_02166230, func_02166248, func_0216625C, func_0216626C, func_0216627C, func_0216628C
 * address:  0x02165FC0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02171CE8  0x02171CE8  data  a1
 *   func_0201F31C  0x0201F31C  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201EF4C  0x0201EF4C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F104  0x0201F104  thumb
 *   func_0201F134  0x0201F134  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_0201F1E0  0x0201F1E0  thumb
 *   func_02165C34  0x02165C34  thumb  ov010
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165D8C  0x02165D8C  thumb  ov010
 *   func_02165E24  0x02165E24  thumb  ov010
 *   func_02165E34  0x02165E34  thumb  ov010
 *   func_02165E78  0x02165E78  thumb  ov010
 *   func_02165E8C  0x02165E8C  thumb  ov010
 *   func_02165E9C  0x02165E9C  thumb  ov010
 *   func_02165EAC  0x02165EAC  thumb  ov010
 *   func_02165ECC  0x02165ECC  thumb  ov010
 *   func_02165F30  0x02165F30  thumb  ov010
 *   func_02165F64  0x02165F64  thumb  ov010
 *   func_02165F74  0x02165F74  thumb  ov010
 *   func_02165F84  0x02165F84  thumb  ov010
 *   func_02165F94  0x02165F94  thumb  ov010
 *   func_02165FA4  0x02165FA4  thumb  ov010
 *   func_02165FB4  0x02165FB4  thumb  ov010
 *   func_0200E184  0x0200E184  thumb
 *   func_0200E164  0x0200E164  thumb
 *   func_0200E06C  0x0200E06C  thumb
 *   func_0200E27C  0x0200E27C  thumb
 *   func_0200E024  0x0200E024  thumb
 *   func_0200E18C  0x0200E18C  thumb
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

/* One-word struct: the record move in func_0216628C needs a word copy. */
typedef struct {
    u32 word;
} RecordWord;

extern void func_0201F31C(struct WordSet *wordSet);
extern struct StrBuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct StrBuf *buf);
extern void func_0201EE0C(struct WordSet *wordSet, u32 bufferIndex, const void *str, u32 sex, u32 flag, u32 language);
extern void func_0201EE60(struct WordSet *wordSet, u32 bufferIndex, u16 value);
extern void func_0201EF34(struct WordSet *wordSet, u32 bufferIndex, u32 value);
extern void func_0201EF40(struct WordSet *wordSet, u32 bufferIndex, u32 value);
extern void func_0201EF4C(struct WordSet *wordSet, u32 bufferIndex, u32 value);
extern void func_0201EFA4(struct WordSet *wordSet, u32 bufferIndex, u32 value, u32 digits, u32 padding, u32 flag);
extern void func_0201F104(struct WordSet *wordSet, u32 bufferIndex, u32 value);
extern void func_0201F134(struct WordSet *wordSet, u32 bufferIndex, u32 value);
extern void func_0201F184(struct WordSet *wordSet, u32 bufferIndex, s32 value);
extern void func_0201F1E0(struct WordSet *wordSet, u32 bufferIndex, u32 value);
extern void func_02165C34(GameBeaconInfo *info, void *buf);
extern u8 func_02165D08(GameBeaconInfo *info);
extern int func_02165D8C(int info, int buf);
extern u16 func_02165E24(GameBeaconInfo *info);
extern u16 func_02165E34(GameBeaconInfo *info);
extern u16 func_02165E78(GameBeaconInfo *info);
extern u16 func_02165E8C(GameBeaconInfo *info);
extern u16 func_02165E9C(GameBeaconInfo *info);
extern u16 func_02165EAC(GameBeaconInfo *info);
extern void func_02165ECC(GameBeaconInfo *info, void *buf);
extern u16 func_02165F30(GameBeaconInfo *info);
extern u32 func_02165F64(GameBeaconInfo *info);
extern u16 func_02165F74(GameBeaconInfo *info);
extern u32 func_02165F84(GameBeaconInfo *info);
extern u8 func_02165F94(GameBeaconInfo *info);
extern u16 func_02165FA4(GameBeaconInfo *info);
extern u8 func_02165FB4(u16 actionType);
extern u32 func_0200E184(u32 recordIndex);
extern u32 func_0200E164(u32 *save, u32 band);
extern void func_0200E06C(char *save);
extern void func_0200E27C(u8 *save, int recordIndex);
extern void func_0200E024(void *save);
extern void func_0200E18C(u32 *save, u32 recordIndex);
u8 func_02165FC0(u32 actionType);
void func_02165FCC(GameBeaconInfo *info, struct WordSet *wordSet, u32 heapId);
int func_02166164(GameBeaconInfo *info);
int func_02166168(GameBeaconInfo *info);
int func_02166180(GameBeaconInfo *info);
int func_02166198(GameBeaconInfo *info);
int func_0216619C(GameBeaconInfo *info);
int func_021661B4(GameBeaconInfo *info);
int func_021661CC(GameBeaconInfo *info);
int func_021661EC(GameBeaconInfo *info);
int func_02166200(GameBeaconInfo *info);
int func_02166218(GameBeaconInfo *info);
int func_02166230(GameBeaconInfo *info);
int func_02166248(GameBeaconInfo *info);
int func_0216625C(GameBeaconInfo *info);
int func_0216626C(GameBeaconInfo *info);
int func_0216627C(GameBeaconInfo *info);
int func_0216628C(u32 *save, u32 recordIndex);
extern const ActionTypeRow d_02171CE8[];


/*
 * Second byte of the two-byte table row for an action type.
 */
u8 func_02165FC0(u32 actionType)
{
    return d_02171CE8[actionType].viewVariant;
}


/*
 * Registers the words of a record for message printing: its name into
 * buffer 0, then the action-specific value (number, string or item) into
 * buffers 1 and 2.
 */
void func_02165FCC(GameBeaconInfo *info, struct WordSet *wordSet, u32 heapId)
{
    struct StrBuf *buf;
    u8 printKind;
    u32 value;

    func_0201F31C(wordSet);
    buf = func_020457B0(0x21, heapId);
    if (buf == 0)
        return;
    func_02165C34(info, buf);
    func_0201EE0C(wordSet, 0, buf, 0, 1, 2);
    printKind = func_02165FB4(func_02165E24(info));
    switch (printKind) {
    case BEACON_PRINT_TRAINER_NO:
        value = func_02165F30(info);
        func_0201F104(wordSet, 1, value);
        func_0201F134(wordSet, 2, value);
        break;
    case BEACON_PRINT_MONS_NO:
    case BEACON_PRINT_MONS_NO_AND_NICKNAME:
        func_0201EE60(wordSet, 1, func_02165E34(info));
        if (printKind == BEACON_PRINT_MONS_NO)
            break;
    case BEACON_PRINT_NICKNAME:
        func_02165ECC(info, buf);
        func_0201EE0C(wordSet, 2, buf, 0, 1, 2);
        break;
    case BEACON_PRINT_ITEM_NO:
        func_0201EF4C(wordSet, 1, func_02165E78(info));
        break;
    case BEACON_PRINT_SPECIAL_VALUE:
        func_0201EFA4(wordSet, 1, func_02165F74(info), 3, 0, 1);
        break;
    case BEACON_PRINT_PRESET_EVENT:
        func_0201EFA4(wordSet, 1, func_02165F64(info), 3, 0, 1);
        break;
    case BEACON_PRINT_DISTRIBUTION_MONS_NO:
        func_0201EE60(wordSet, 1, func_02165E9C(info));
        break;
    case BEACON_PRINT_DISTRIBUTION_ITEM_NO:
        func_0201EF40(wordSet, 1, func_02165EAC(info));
        break;
    case BEACON_PRINT_COUNT_VALUE:
        func_0201EF34(wordSet, 1, func_02165E8C(info));
        break;
    case BEACON_PRINT_WORD_VALUE:
        func_0201EFA4(wordSet, 1, func_02165F84(info), 1, 0, 1);
        break;
    case BEACON_PRINT_BYTE_VALUE:
        func_0201F1E0(wordSet, 1, func_02165F94(info));
        break;
    case BEACON_PRINT_HALFWORD_VALUE:
        func_0201F184(wordSet, 1, func_02165FA4(info));
        break;
    case BEACON_PRINT_FREE_TEXT:
        func_02165D8C((int)info, (int)buf);
        func_0201EE0C(wordSet, 1, buf, func_02165D08(info), 1, 2);
        break;
    case BEACON_PRINT_NONE:
        break;
    }
    func_02045808(buf);
}


/*
 * Record field validators: each returns 1 when the field it checks is out
 * of range for its action kind. This one accepts everything.
 */
int func_02166164(GameBeaconInfo *info)
{
    return 0;
}


/* Trainer number at +0x34 must be 1..0x267. */
int func_02166168(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value >= 0x268)
        return 1;
    return 0;
}


/* Pokemon number at +0x32 must be 1..0x289. */
int func_02166180(GameBeaconInfo *info)
{
    if (info->actionArg == 0 || info->actionArg > 0x289)
        return 1;
    return 0;
}


/* Accepts everything (actions without a value). */
int func_02166198(GameBeaconInfo *info)
{
    return 0;
}


/* Pokemon number at +0x32 must be 1..0x289 (actions that also carry a nickname). */
int func_0216619C(GameBeaconInfo *info)
{
    if (info->actionArg == 0 || info->actionArg > 0x289)
        return 1;
    return 0;
}


/* Item number at +0x34 must be 1..0x272. */
int func_021661B4(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value > 0x272)
        return 1;
    return 0;
}


/* Play time: hours must be at most 999 and minutes at most 59. */
int func_021661CC(GameBeaconInfo *info)
{
    if (info->playHours > 999 || info->playMinutes > 59)
        return 1;
    return 0;
}


/* Count value at +0x34 (32 bit) must be at most 99999. */
int func_021661EC(GameBeaconInfo *info)
{
    if (info->actionData.wordValue > 99999)
        return 1;
    return 0;
}


/* Distributed pokemon number at +0x34 must be 1..0x289. */
int func_02166200(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value > 0x289)
        return 1;
    return 0;
}


/* Distributed item number at +0x36 must be 1..0x272. */
int func_02166218(GameBeaconInfo *info)
{
    if (info->actionData.special.itemNo == 0 || info->actionData.special.itemNo > 0x272)
        return 1;
    return 0;
}


/* Move number at +0x34 must be 1..0x22F. */
int func_02166230(GameBeaconInfo *info)
{
    if (info->actionData.value == 0 || info->actionData.value >= 0x230)
        return 1;
    return 0;
}


/* Preset event number at +0x34 (32 bit) must be 1..7. */
int func_02166248(GameBeaconInfo *info)
{
    if (info->actionData.wordValue == 0 || info->actionData.wordValue > 7)
        return 1;
    return 0;
}


/* Byte value at +0x34 must be at most 6. */
int func_0216625C(GameBeaconInfo *info)
{
    if (info->actionData.byteValue > 6)
        return 1;
    return 0;
}


/* Halfword value at +0x34 must be below 0x30. */
int func_0216626C(GameBeaconInfo *info)
{
    if (info->actionData.value >= 0x30)
        return 1;
    return 0;
}


/* Distribution serial at +0x38 must be below 0x30. */
int func_0216627C(GameBeaconInfo *info)
{
    if (info->actionData.special.serial >= 0x30)
        return 1;
    return 0;
}


/*
 * closed 2026-10-05: the unlabelled leaves it calls are now matched files, so every relocation resolves.
 *
 * Moves a record of the symbol save to the paired band: maps the band of
 * the record (0..3, via the 0x0200E184 thunk) to the paired band (0 and 2,
 * 1 and 3), asks func_0200E164 for a free index in that band, and moves
 * the word at save[recordIndex] there; band 3 also runs func_0200E27C on
 * it. Returns 0 on failure.
 *
 * 2026-10-05 (P25L5): all 128 bytes match. The word move is a one-word
 * struct copy (RecordWord, lever "one-word structs for word copies"); the
 * plain u32 copy gave 8 bytes off (cmp r5,#3 after the str, dst*4 in r0).
 * Only blocker: func_0200E184 is a Thumb veneer (ldr r3,[pc]; bx r3) to
 * the real function at 0x0200E0BC (44 bytes, maps a value to 0..3 by a
 * 4-entry threshold table). It has no witness outside this function, so
 * the relocation stays unresolved. No C can express the veneer; the
 * integrator should seed a label or witness for 0x0200E184.
 * Tried and inert (8 bytes off): raw byte offsets, u16 dst (31 off),
 * const callee proto, u8 obj, u8 kind, inline copy helper, byte offset
 * locals, per-arm store (45 off), each pragma (scheduling, peephole,
 * opt_propagation, opt_common_subs, opt_lifetimes, opt_dead_assignments).
 */
int func_0216628C(u32 *save, u32 recordIndex)
{
    u32 targetBand;
    u32 newIndex;

    switch (func_0200E184(recordIndex)) {
    case 0:
        targetBand = 2;
        break;
    case 1:
        targetBand = 3;
        break;
    case 2:
        targetBand = 0;
        break;
    case 3:
        targetBand = 1;
        break;
    default:
        return 0;
    }
    newIndex = func_0200E164(save, targetBand);
    if (newIndex == 0xFFFF)
        return 0;
    func_0200E06C((char *)save);
    ((RecordWord *)save)[newIndex] = ((RecordWord *)save)[recordIndex];
    if (targetBand == 3)
        func_0200E27C((u8 *)save, (u16)newIndex);
    func_0200E024(save);
    func_0200E18C(save, recordIndex);
    return 1;
}
