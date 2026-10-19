/*
 * file:     btl_sick.c
 * unit:     yes
 * function: BTL_SICK_ProcAddedOrTurnEnd, BTL_SICK_ProcTurnEnd, BTL_SICK_BuildDamageMessage, BTL_SICK_GetDamageStringId, BTL_SICK_TickPerishSong, BTL_SICK_ApplyLeechSeed, BTL_SICK_RecoverHpIngrain, BTL_SICK_ApplyBindDamage, BTL_SICK_RecoverHpAquaRing, BTL_SICK_EndEncoreWhenPpEmpty, BTL_SICK_OnAdded, BTL_SICK_StartYawnSleep, BTL_SICK_ApplyPerishFaint, BTL_SICK_ShowPerishCount, BTL_SICK_OnHealBlockAdded, BTL_SICK_OnItemBlockAdded, BTL_SICK_GetCureStringId, BTL_SICK_BuildCureMessage, BTL_SICK_GetAddStringId, BTL_SICK_BuildAddMessage, BTL_SICK_OverrideGroundImmunity, BTL_SICK_ForceGroundedByTrap, BTL_SICK_ForceGroundedOrFloating, BTL_SICK_ShowIngrainRoots
 * address:  0x0689B7A8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Cut from unit_0689B780.c by tools/splitfile.py.
 * lever: inline Slot-to-Word reinterpretation preserves the extra aggregate home word; passing the aggregate directly differed only at the four frame bytes.
 * lever: BD40 returns Word passed by value to BD50/BD70, reserving the
 *   original two frame words; node declaration before species fixes r4/r5.
 * Extent ends with two-byte alignment padding at 0689C0D2.
 * Calls fixed bx-pc veneers 0689C0D4 -> 021D5440,
 * 0689C0E4 -> 021C88A4, 0689C0F4 -> 021C88C8.
 * Extent remainder: two-byte alignment padding at 0x0689C1D2.
 * Extent remainder: two-byte alignment padding at 0x0689C242.
 *
 * symbols:
 *   BTL_SERVER_FLOW_ProcSickDamage  0x021C4A64  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   BTL_POKEPARAM_CalcSickDamage  0x021D6324  thumb
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb
 *   BTL_POKEPARAM_GetSickTurn  0x021D631C  thumb
 *   BTL_SICKCONT_GetLow  0x021E8AFC  thumb
 *   BTL_SERVER_FLOW_GetPosTableEntryForPoke  0x021C7D44  thumb
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb
 *   BTL_SICKCONT_GetValue  0x021E8B80  thumb
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb
 *   BTL_SICKCONT_GetFlag  0x021E8C24  thumb
 *   BTL_POKEPARAM_GetMovePPById  0x021D55A0  thumb
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb
 *   BTL_CALC_RandRange  0x021D7B8C  thumb
 *   BTL_SICKCONT_MakeKind2Index  0x021E8940  thumb
 *   BTL_SICKCONT_IsKind1Index15  0x021E8A78  thumb
 *   BTL_SERVER_FLOW_ClearMsgRecord  0x021C8810  thumb
 *   gSickAddStringTable   0x0689E21C  data  ov095  a4
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 */
#include "btl_sick_types.h"

/* One row of the table of messages for a condition that was added. */
typedef struct SickAddStringEntry {
    u32 sickKind;
    s16 stringId;
    s16 stringIdWithArg;     /* negative: the plain string is used for both */
} SickAddStringEntry;

extern int BTL_POKEPARAM_CalcSickDamage(struct BtlPokeParam *bpp, int sickKind);
struct BtlServerFlow;
extern void BTL_SERVER_FLOW_ProcSickDamage(struct BtlServerFlow *flow, u8 *poke, u32 sickKind, u32 baseDamage);
void BTL_SICK_ProcAddedOrTurnEnd(struct BtlPokeParam *bpp, int sickKind, union SickCont cont, int isAdded);
void BTL_SICK_ProcTurnEnd(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId, int sickKind);
int BTL_SICK_BuildDamageMessage(BtlStrParam *message, struct BtlPokeParam *bpp, int sickKind);
int BTL_SICK_GetDamageStringId(int sickKind);
void BTL_SICK_TickPerishSong(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_ApplyLeechSeed(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_RecoverHpIngrain(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_ApplyBindDamage(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_RecoverHpAquaRing(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_EndEncoreWhenPpEmpty(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_OnAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId, int sickKind, union SickCont cont);
void BTL_SICK_StartYawnSleep(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
void BTL_SICK_ApplyPerishFaint(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
void BTL_SICK_ShowPerishCount(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, u8 count);
void BTL_SICK_OnHealBlockAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
void BTL_SICK_OnItemBlockAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
int BTL_SICK_GetCureStringId(unsigned int sickKind, union SickCont cont);
void BTL_SICK_BuildCureMessage(int sickKind, union SickCont cont, struct BtlPokeParam *bpp, BtlStrParam *message);
int BTL_SICK_GetAddStringId(u32 sickKind, int hasArg);
int BTL_SICK_BuildAddMessage(int sickKind, union SickCont cont, struct BtlPokeParam *bpp, u8 argValue, BtlStrParam *message);
void BTL_SICK_OverrideGroundImmunity(struct BtlEventFactor *factor, struct BtlPokeParam *bpp);
void BTL_SICK_ForceGroundedByTrap(struct BtlEventFactor *factor, struct BtlPokeParam *bpp);
void BTL_SICK_ForceGroundedOrFloating(struct BtlEventFactor *factor, struct BtlPokeParam *bpp);
void BTL_SICK_ShowIngrainRoots(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
extern SickAddStringEntry gSickAddStringTable[17];


/*
 * Handed at 0x0689B7AA (the second label after `push {r0-r3}` at 0x0689B7A8).
 * The fifth argument is read through &c ((&c)[2], the first stack slot):
 * taking the address of c is what pushes r0-r3 and makes c reload from its
 * home slot; a plain fifth parameter gives an ordinary push instead.
 */
void BTL_SICK_ProcAddedOrTurnEnd(struct BtlPokeParam *bpp, int sickKind, union SickCont cont, int isAdded)
{
    int pokeId;

    pokeId = BTL_POKEPARAM_GetPokeId(bpp);
    if (isAdded != 0)
        BTL_SICK_OnAdded(((struct BtlServerFlow **)&cont)[2], bpp, pokeId, sickKind, cont);
    else
        BTL_SICK_ProcTurnEnd(((struct BtlServerFlow **)&cont)[2], bpp, pokeId, sickKind);
}


void BTL_SICK_ProcTurnEnd(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId, int sickKind)
{
    int damage;

    if (BTL_POKEPARAM_IsFainted(bpp) != 0)
        return;
    damage = BTL_POKEPARAM_CalcSickDamage(bpp, sickKind);
    if (damage != 0)
        BTL_SERVER_FLOW_ProcSickDamage(flow, (u8 *)bpp, sickKind, damage);
    switch (sickKind) {
    case 0x14:
        BTL_SICK_TickPerishSong(flow, bpp, pokeId);
        break;
    case 0x12:
        BTL_SICK_ApplyLeechSeed(flow, bpp, pokeId);
        break;
    case 0x15:
        BTL_SICK_RecoverHpIngrain(flow, bpp, pokeId);
        break;
    case 8:
        BTL_SICK_ApplyBindDamage(flow, bpp, pokeId);
        break;
    case 0x23:
        BTL_SICK_RecoverHpAquaRing(flow, bpp, pokeId);
        break;
    case 0x17:
        BTL_SICK_EndEncoreWhenPpEmpty(flow, bpp, pokeId);
        break;
    }
}



int BTL_SICK_BuildDamageMessage(BtlStrParam *message, struct BtlPokeParam *bpp, int sickKind)
{
    int stringId;
    stringId = BTL_SICK_GetDamageStringId(sickKind);
    if (stringId > 0) {
        BTL_SERVER_FLOW_InitMsgRecord(message, BTL_STR_TYPE_STD, (u16)stringId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(message, BTL_POKEPARAM_GetPokeId(bpp));
    }
    return 0;
}




int BTL_SICK_GetDamageStringId(int sickKind)
{
    switch (sickKind) {
    case 5:
        return 0xf3;
    case 4:
        return 0x105;
    case BTL_SICK_NIGHTMARE:
        return 0x144;
    case BTL_SICK_CURSE:
        return 0x42f;
    }
    return -1;
}




void BTL_SICK_TickPerishSong(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId)
{
    union SickCont cont;
    int totalTurns;
    int turnsLeft;

    if (BTL_POKEPARAM_IsFainted(bpp) == 0) {
        cont = BTL_POKEPARAM_GetSickContRaw(bpp, BTL_SICK_PERISH_SONG);
        totalTurns = BTL_SICKCONT_GetLow(cont);
        turnsLeft = totalTurns - BTL_POKEPARAM_GetSickTurn(bpp, BTL_SICK_PERISH_SONG);
        if (turnsLeft > 0)
            BTL_SICK_ShowPerishCount(flow, bpp, turnsLeft);
    }
}



void BTL_SICK_ApplyLeechSeed(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId)
{
    union SickCont cont;
    u8 sourceId;
    int sourceEntry;
    u16 amount, curHp;
    BtlCmdDamage *damage;
    BtlCmdRecoverHp *recover;
    int effectStringId;
    cont = BTL_POKEPARAM_GetSickContRaw(bpp, BTL_SICK_LEECH_SEED);
    sourceId = (u8)BTL_SICKCONT_GetValue(*(union SickCont *)&cont);
    sourceEntry = BTL_SERVER_FLOW_GetPosTableEntryForPoke(flow, sourceId);
    if (sourceEntry == BTL_CMD_ACTIVE_NONE) return;
    amount = BTL_CALC_DivideMaxHpMin1(bpp, 8);
    curHp = BTL_POKEPARAM_GetValue(bpp, BTL_VALUE_HP);
    if (amount > curHp) amount = curHp;
    damage = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_DAMAGE, pokeId);
    damage->pokeId = pokeId;
    damage->amount = amount;
    effectStringId = 0x262;
    BTL_SERVER_FLOW_InitMsgRecord(&damage->message, BTL_STR_TYPE_STD, effectStringId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&damage->message, pokeId);
    damage->flags |= BTL_CMD_DAMAGE_HAS_EFFECT;
    effectStringId += 0x13;
    damage->effectStringId = effectStringId;
    damage->effectArgA = sourceId;
    damage->effectArgB = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, damage);
    if (sourceEntry != BTL_CMD_ACTIVE_NONE) {
        recover = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_RECOVER_HP, pokeId);
        recover->header |= BTL_CMD_HEADER_QUIET;
        recover->pokeId = sourceEntry;
        recover->sourceId = pokeId;
        recover->amount = amount;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, recover);
    }
}



void BTL_SICK_RecoverHpIngrain(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId)
{
    BtlCmdRecoverHp *recover;

    if (BTL_POKEPARAM_IsHpFull(bpp) == 0) {
        recover = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_RECOVER_HP, pokeId);
        recover->pokeId = pokeId;
        recover->sourceId = BTL_CMD_ACTIVE_NONE;
        recover->amount = BTL_CALC_DivideMaxHpMin1(bpp, 0x10);
        BTL_SERVER_FLOW_InitMsgRecord(&recover->message, BTL_STR_TYPE_STD, 0x2e3);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&recover->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, recover);
    }
}



void BTL_SICK_ApplyBindDamage(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId)
{
    union SickCont cont;
    BtlCmdDamage *damage;
    int moveId;
    int effectStringId;
    if (BTL_POKEPARAM_IsFainted(bpp) != 0)
        return;
    cont = BTL_POKEPARAM_GetSickContRaw(bpp, BTL_SICK_BIND);
    moveId = BTL_SICKCONT_GetValue(cont);
    effectStringId = -1;
    switch (moveId) {
    case 0x23: effectStringId = 0x277; break;
    case 0x14: effectStringId = 0x276; break;
    case 0x53: effectStringId = 0x278; break;
    case 0x1cf: effectStringId = 0x279; break;
    case 0x80: effectStringId = 0x27a; break;
    case 0xfa: effectStringId = 0x27b; break;
    case 0x148: effectStringId = 0x27c; break;
    }
    damage = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_DAMAGE, pokeId);
    damage->pokeId = pokeId;
    if (BTL_SICKCONT_GetFlag(cont) != 0)
        damage->amount = BTL_CALC_DivideMaxHpMin1(bpp, 8);
    else
        damage->amount = BTL_CALC_DivideMaxHpMin1(bpp, 16);
    if (effectStringId != -1) {
        damage->flags = BTL_CMD_DAMAGE_HAS_EFFECT | damage->flags;
        damage->effectStringId = effectStringId;
        damage->effectArgA = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        damage->effectArgB = 6;
    }
    BTL_SERVER_FLOW_InitMsgRecord(&damage->message, BTL_STR_TYPE_STD, 0x174);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&damage->message, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&damage->message, moveId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, damage);
}



void BTL_SICK_RecoverHpAquaRing(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId)
{
    BtlCmdRecoverHp *recover;

    if (BTL_POKEPARAM_IsHpFull(bpp) == 0 && BTL_POKEPARAM_IsFainted(bpp) == 0) {
        recover = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_RECOVER_HP, pokeId);
        recover->pokeId = pokeId;
        recover->sourceId = BTL_CMD_ACTIVE_NONE;
        recover->amount = BTL_CALC_DivideMaxHpMin1(bpp, 0x10);
        BTL_SERVER_FLOW_InitMsgRecord(&recover->message, BTL_STR_TYPE_STD, 0x25c);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&recover->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, recover);
    }
}



void BTL_SICK_EndEncoreWhenPpEmpty(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId)
{
    HandExCureSick *cure;

    if (BTL_POKEPARAM_GetMovePPById(bpp, BTL_SICKCONT_GetValue(BTL_POKEPARAM_GetSickContRaw(bpp, BTL_SICK_ENCORE))) == 0) {
        cure = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_CURE_SICK, pokeId);
        cure->sickKind = BTL_SICK_ENCORE;
        cure->pokeIds[0] = pokeId;
        cure->pokeCount = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cure);
    }
}



void BTL_SICK_OnAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId, int sickKind, union SickCont cont)
{
    BtlStrParam message;
    HandExMessage *record;

    if (BTL_SICK_BuildAddMessage(sickKind, cont, bpp, 0, &message) != 0) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        record->message = message;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
    switch (sickKind) {
    case BTL_SICK_YAWN:
        BTL_SICK_StartYawnSleep(flow, bpp);
        return;
    case BTL_SICK_PERISH_SONG:
        BTL_SICK_ApplyPerishFaint(flow, bpp);
        return;
    case BTL_SICK_HEAL_BLOCK:
        BTL_SICK_OnHealBlockAdded(flow, bpp);
        return;
    case BTL_SICK_ITEM_BLOCK:
        BTL_SICK_OnItemBlockAdded(flow, bpp);
        return;
    }
}



void BTL_SICK_StartYawnSleep(struct BtlServerFlow *flow, struct BtlPokeParam *bpp)
{
    int turns;
    int pokeId;
    HandExAddSick *add;

    turns = BTL_CALC_RandRange(2, 4);
    if (turns > 0) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(bpp) == 0) {
            pokeId = BTL_POKEPARAM_GetPokeId(bpp);
            add = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_ADD_SICK, pokeId);
            add->suppressMessage = 1;
            add->sickKind = 2;
            add->sickCont = BTL_SICKCONT_MakeKind2Index((u8)turns);
            add->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, add);
        }
    }
}



void BTL_SICK_ApplyPerishFaint(struct BtlServerFlow *flow, struct BtlPokeParam *bpp)
{
    int pokeId;
    HandExFaint *faint;
    BTL_SICK_ShowPerishCount(flow, bpp, 0);
    pokeId = BTL_POKEPARAM_GetPokeId(bpp);
    faint = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_FAINT, pokeId);
    faint->pokeId = pokeId;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, faint);
}



void BTL_SICK_ShowPerishCount(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, u8 count)
{
    int pokeId;
    HandExMessage *record;

    pokeId = BTL_POKEPARAM_GetPokeId(bpp);
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STR_TYPE_STD, 0x35c);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, count);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
}



void BTL_SICK_OnHealBlockAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp)
{
    BtlCmdSetSickState *record;
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_SET_SICK_STATE, BTL_POKEPARAM_GetPokeId(bpp));
    record->pokeId = BTL_POKEPARAM_GetPokeId(bpp);
    record->state = 0;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
}



void BTL_SICK_OnItemBlockAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp)
{
    BtlCmdSetSickState *record;
    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_SET_SICK_STATE, BTL_POKEPARAM_GetPokeId(bpp));
    record->pokeId = BTL_POKEPARAM_GetPokeId(bpp);
    record->state = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
}



int BTL_SICK_GetCureStringId(unsigned int sickKind, union SickCont cont)
{
    int stringId = -1;
    switch (sickKind) {
    case 4: stringId = 0xff; break;
    case 1: stringId = 0x111; break;
    case 3: stringId = 0x120; break;
    case 2: stringId = 0x132; break;
    case 6: stringId = 0x159; break;
    case 7: stringId = 0x147; break;
    case 9: stringId = 0x141; break;
    case 11: stringId = 0x238; break;
    case 12: stringId = 0x241; break;
    case 14: stringId = 0x29b; break;
    case 18: stringId = 0x25f; break;
    case 17: stringId = 0x171; break;
    case 21: stringId = 0x2e0; break;
    case 19: stringId = 0x2d7; break;
    case 13: stringId = 0x250; break;
    case 15: stringId = 0x371; break;
    case 5:
        if (BTL_SICKCONT_IsKind1Index15(cont) != 0) stringId = 0xed;
        else stringId = 0xea;
        break;
    }
    return stringId;
}




void BTL_SICK_BuildCureMessage(int sickKind, union SickCont cont, struct BtlPokeParam *bpp, BtlStrParam *message)
{
    int stringId;

    stringId = BTL_SICK_GetCureStringId(sickKind, cont);
    if (stringId >= 0) {
        BTL_SERVER_FLOW_InitMsgRecord(message, BTL_STR_TYPE_STD, (u16)stringId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(message, BTL_POKEPARAM_GetPokeId(bpp));
        if (sickKind == 8 || sickKind == 13)
            BTL_SERVER_FLOW_AppendMsgRecordArg(message, BTL_SICKCONT_GetValue(cont));
    } else {
        BTL_SERVER_FLOW_ClearMsgRecord(message);
    }
}



int BTL_SICK_GetAddStringId(u32 sickKind, int hasArg)
{
    u32 i;
    int stringId;

    for (i = 0; i < 17; i++) {
        if (sickKind == gSickAddStringTable[i].sickKind) {
            if (hasArg != 0)
                stringId = gSickAddStringTable[i].stringIdWithArg;
            else
                stringId = gSickAddStringTable[i].stringId;
            if (stringId < 0)
                return gSickAddStringTable[i].stringId;
            return stringId;
        }
    }
    return -1;
}




int BTL_SICK_BuildAddMessage(int sickKind, union SickCont cont, struct BtlPokeParam *bpp, u8 argValue, BtlStrParam *message)
{
    int hasArg;
    int stringId;

    hasArg = 1;
    if (argValue == 0)
        hasArg = 0;
    stringId = BTL_SICK_GetAddStringId(sickKind, hasArg);
    if (stringId >= 0) {
        BTL_SERVER_FLOW_InitMsgRecord(message, BTL_STR_TYPE_STD, (u16)stringId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(message, BTL_POKEPARAM_GetPokeId(bpp));
        if (hasArg != 0)
            BTL_SERVER_FLOW_AppendMsgRecordArg(message, argValue);
        switch (sickKind) {
        case 8:
            BTL_SERVER_FLOW_AppendMsgRecordArg(message, BTL_SICKCONT_GetValue(cont));
            break;
        case 0x12:
            BTL_SERVER_FLOW_AppendMsgRecordArg(message, 0x49);
            break;
        }
        return 1;
    }
    return 0;
}



void BTL_SICK_OverrideGroundImmunity(struct BtlEventFactor *factor, struct BtlPokeParam *bpp)
{
    int sickKind;
    union SickCont cont;
    u8 identifiedType;

    sickKind = BTL_SICK_IDENTIFIED;
    if (BTL_POKEPARAM_HasSick(bpp, sickKind) != 0) {
        cont = BTL_POKEPARAM_GetSickContRaw(bpp, sickKind);
        identifiedType = BTL_SICKCONT_GetValue(cont);
        if (identifiedType == (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_TYPE)) {
            BTL_EVENT_OverwriteVar(BTL_SICKCONT_GetFlag(cont) == 0 ? BTL_EVAR_IMMUNITY_OVERRIDE_FLAG : BTL_EVAR_IMMUNITY_OVERRIDE_FLAG + 1, 1);
        }
    }
    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_INGRAIN) != 0) {
        if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == 4)
            BTL_EVENT_OverwriteVar(BTL_EVAR_IMMUNITY_OVERRIDE_FLAG, 1);
    }
    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_FLOATING_BLOCK) != 0) {
        if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == 4)
            BTL_EVENT_OverwriteVar(BTL_EVAR_IMMUNITY_OVERRIDE_FLAG, 1);
    }
}



void BTL_SICK_ForceGroundedByTrap(struct BtlEventFactor *factor, struct BtlPokeParam *bpp)
{
    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_NO_ESCAPE) != 0 || BTL_POKEPARAM_HasSick(bpp, BTL_SICK_BIND) != 0) {
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
    }
}



void BTL_SICK_ForceGroundedOrFloating(struct BtlEventFactor *factor, struct BtlPokeParam *bpp)
{
    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_INGRAIN))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_FLOATING_BLOCK))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_TELEKINESIS) || BTL_POKEPARAM_HasSick(bpp, BTL_SICK_MAGNET_RISE))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}



void BTL_SICK_ShowIngrainRoots(struct BtlServerFlow *flow, struct BtlPokeParam *bpp)
{
    int pokeId;
    HandExMessage *record;

    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_INGRAIN) && BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1)) {
        pokeId = BTL_POKEPARAM_GetPokeId(bpp);
        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_STR_TYPE_STD, 0x2e6);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
    }
}
