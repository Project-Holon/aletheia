/*
 * file:     unit_021D3568.c
 * unit:     yes
 * function: BTL_CLIENT_CmdSwapViewPositions, BTL_CLIENT_CmdChangeForm, BTL_CLIENT_CmdShowStatusPanel, BTL_CLIENT_CmdHideStatusPanel, BTL_CLIENT_CmdHpMinus, BTL_CLIENT_CmdHpPlus, BTL_CLIENT_CmdPpMinusOriginal, BTL_CLIENT_CmdPpMinusWorking, BTL_CLIENT_CmdMarkMoveUsed, BTL_CLIENT_CmdHpZero, BTL_CLIENT_CmdPpPlusOriginal, BTL_CLIENT_CmdPpPlusWorking, BTL_CLIENT_CmdStatStageUp, BTL_CLIENT_CmdStatStageDown, BTL_CLIENT_CmdSetStatStages, BTL_CLIENT_CmdRecoverStatStages, BTL_CLIENT_CmdResetStatStages, BTL_CLIENT_CmdAddCritStage, BTL_CLIENT_CmdSetSick, BTL_CLIENT_CmdCureMajorSick, BTL_CLIENT_CmdCureSick, BTL_CLIENT_CmdMemberIn, BTL_CLIENT_CmdSetPokeType, BTL_CLIENT_CmdCureSickMulti
 * address:  0x021D3568
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689C9F8  0x0689C9F8  thumb
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   func_021EA3E8  0x021EA3E8  thumb  ov093
 *   func_021EA3F8  0x021EA3F8  thumb  ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_ChangeForm  0x021D66D8  thumb  ov093
 *   func_021EA888  0x021EA888  thumb  ov093
 *   func_021EA8A4  0x021EA8A4  thumb  ov093
 *   func_021EA768  0x021EA768  thumb  ov093
 *   func_021EA778  0x021EA778  thumb  ov093
 *   func_021EA788  0x021EA788  thumb  ov093
 *   func_021EA798  0x021EA798  thumb  ov093
 *   BTL_POKEPARAM_SubHp 0x021D5F90 thumb ov093
 *   BTL_POKEPARAM_AddHp 0x021D5FA4 thumb ov093
 *   BTL_POKEPARAM_DecrementMovePP 0x021D5608 thumb ov093
 *   BTL_POKEPARAM_DecrementRealMovePP 0x021D5640 thumb ov093
 *   BTL_POKEPARAM_MarkMoveUsed 0x021D56CC thumb ov093
 *   BTL_POKEPARAM_ZeroHp   0x021D5FB8  thumb
 *   BTL_POKEPARAM_RestoreMovePP 0x021D5674 thumb ov093
 *   BTL_POKEPARAM_RestoreRealMovePP 0x021D56A0 thumb ov093
 *   BTL_POKEPARAM_RaiseStatStage 0x021D5DC0 thumb ov093
 *   BTL_POKEPARAM_LowerStatStage 0x021D5E38 thumb ov093
 *   BTL_POKEPARAM_SetStatStage  0x021D5EA8  thumb  ov093
 *   BTL_POKEPARAM_RaiseLoweredStatStages   0x021D5EFC  thumb
 *   BTL_POKEPARAM_ResetStatStages   0x021D5F08  thumb
 *   BTL_POKEPARAM_AddCritStage 0x021D5F38 thumb ov093
 *   BTL_POKEPARAM_SetSickCont 0x021D6034 thumb ov093
 *   BTL_POKEPARAM_ClearMajorStatus   0x021D61F0  thumb
 *   BTL_POKEPARAM_CureSick 0x021D6238 thumb ov093
 *   BTL_SIDE_GetSlotOfClient  0x021B9AEC  thumb  ov093
 *   BTL_SLOT_Swap  0x021B9C10  thumb  ov093
 *   BTL_SLOT_GetPoke  0x021B9BF0  thumb  ov093
 *   BTL_POKEPARAM_StartTurnThreshold  0x021D63EC  thumb  ov093
 *   BTL_POKEPARAM_ReloadAndResetEffects  0x021D6580  thumb  ov093
 *   BTL_POKEPARAM_SetTypes 0x021D66B0 thumb ov093
 *   BTL_CALC_UnpackPokeIds  0x021D8090  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_TickSickCont  0x021D6064  thumb  ov093
 */
#include "unit_021D3568_types.h"

/*
 * Server command handlers of the battle client (module BTL_CLIENT): each
 * one is a row of the client command table, whose second column is the
 * command id (given per handler below). The first part drives the battle
 * view; the second part applies a state change to one Pokemon.
 */

extern u32 BTL_CLIENT_IsMainStepActive(struct BtlClient *client);
extern u8 BTL_MAIN_GetViewPosOfSlot(struct BtlMain *main, u32 position);
extern void func_021EA3E8(struct BtlvCore *view, int viewPosA, int viewPosB, u32 param);
extern int func_021EA3F8(struct BtlvCore *view);
extern int BTL_MAIN_GetTrainerSlotOfPoke(struct BtlMain *main, struct BtlPokeContainer *container, u32 pokeId);
extern struct BtlPokeParam *BTL_SIDE_GetPokeByIdThunk(struct BtlPokeContainer *container, int pokeId);
extern void BTL_POKEPARAM_ChangeForm(struct BtlPokeParam *pokeParam, u8 form);
extern void func_021EA888(struct BtlvCore *view, int viewPos);
extern int func_021EA8A4(struct BtlvCore *view);
extern void func_021EA768(struct BtlvCore *view, u32 position, u32 flag);
extern int func_021EA778(struct BtlvCore *view, u32 position);
extern void func_021EA788(struct BtlvCore *view, u32 position);
extern int func_021EA798(struct BtlvCore *view, u32 position);
extern void BTL_POKEPARAM_SubHp(struct BtlPokeParam *pokeParam, u16 damage);
extern void BTL_POKEPARAM_AddHp(struct BtlPokeParam *pokeParam, u16 amount);
extern void BTL_POKEPARAM_DecrementMovePP(struct BtlPokeParam *pokeParam, u8 slot, u8 amount);
extern void BTL_POKEPARAM_DecrementRealMovePP(struct BtlPokeParam *pokeParam, u32 slot, u32 amount);
extern void BTL_POKEPARAM_MarkMoveUsed(struct BtlPokeParam *pokeParam, u8 slot);
extern void BTL_POKEPARAM_ZeroHp(struct BtlPokeParam *pokeParam);
extern u16 BTL_POKEPARAM_RestoreMovePP(struct BtlPokeParam *pokeParam, u32 slot, u8 amount);
extern u16 BTL_POKEPARAM_RestoreRealMovePP(struct BtlPokeParam *pokeParam, u32 slot, u8 amount);
extern u8 BTL_POKEPARAM_RaiseStatStage(struct BtlPokeParam *pokeParam, int statIndex, u8 steps);
extern u8 BTL_POKEPARAM_LowerStatStage(struct BtlPokeParam *pokeParam, int statIndex, u8 steps);
extern void BTL_POKEPARAM_SetStatStage(struct BtlPokeParam *pokeParam, int statIndex, u8 stage);
extern int BTL_POKEPARAM_RaiseLoweredStatStages(struct BtlPokeParam *pokeParam);
extern void BTL_POKEPARAM_ResetStatStages(struct BtlPokeParam *pokeParam);
extern int BTL_POKEPARAM_AddCritStage(struct BtlPokeParam *pokeParam, int delta);
extern void BTL_POKEPARAM_SetSickCont(struct BtlPokeParam *pokeParam, int sickIndex, union SickCont cont);
extern void BTL_POKEPARAM_ClearMajorStatus(struct BtlPokeParam *pokeParam);
extern void BTL_POKEPARAM_CureSick(struct BtlPokeParam *pokeParam, int sickIndex);
extern void *BTL_SIDE_GetSlotOfClient(struct BtlPokeContainer *container, int clientId);
extern void BTL_SLOT_Swap(void *party, int indexA, int indexB);
extern struct BtlPokeParam *BTL_SLOT_GetPoke(void *party, u32 index);
extern void BTL_POKEPARAM_StartTurnThreshold(struct BtlPokeParam *pokeParam, u16 threshold);
extern void BTL_POKEPARAM_ReloadAndResetEffects(struct BtlPokeParam *pokeParam);
extern void BTL_POKEPARAM_SetTypes(struct BtlPokeParam *pokeParam, int species);
extern void BTL_CALC_UnpackPokeIds(u32 packed, u8 *out);
extern u32 func_0689C9F8(u32 index);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *pokeParam);
extern int BTL_POKEPARAM_TickSickCont(struct BtlPokeParam *pokeParam, u32 sickIndex, union SickCont *outCont, int *outCured);

int BTL_CLIENT_CmdSwapViewPositions(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdChangeForm(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdShowStatusPanel(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdHideStatusPanel(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdHpMinus(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdHpPlus(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdPpMinusOriginal(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdPpMinusWorking(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdMarkMoveUsed(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdHpZero(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdPpPlusOriginal(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdPpPlusWorking(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdStatStageUp(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdStatStageDown(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdSetStatStages(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdRecoverStatStages(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdResetStatStages(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdAddCritStage(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdSetSick(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdCureMajorSick(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdCureSick(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdMemberIn(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdSetPokeType(struct BtlClient *client, int *seq, u32 *args);
int BTL_CLIENT_CmdCureSickMulti(struct BtlClient *client, int *seq, u32 *args);


/* Command 0x4F. Two battle positions swap places in the view; args: positionA, positionB, animation. */
int BTL_CLIENT_CmdSwapViewPositions(struct BtlClient *client, int *seq, u32 *args)
{
    int viewPosA;
    int viewPosB;

    if (*seq == 0) {
        if (BTL_CLIENT_IsMainStepActive(client) != 0) {
            return 1;
        }
        viewPosA = BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[0]);
        viewPosB = BTL_MAIN_GetViewPosOfSlot(client->main, (u8)args[1]);
        func_021EA3E8(client->view, viewPosA, viewPosB, (u16)args[2]);
        (*seq)++;
    } else {
        if (func_021EA3F8(client->view) != 0) {
            return 1;
        }
    }
    return 0;
}


/* Command 0x50. A Pokemon changes form; args: pokeId, form. */
int BTL_CLIENT_CmdChangeForm(struct BtlClient *client, int *seq, u32 *args)
{
    int viewPos;

    switch (*seq) {
    case 0:
        viewPos = BTL_MAIN_GetViewPosOfSlot(client->main, BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->pokeContainer, (u8)args[0]));
        BTL_POKEPARAM_ChangeForm(BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]), (u8)args[1]);
        func_021EA888(client->view, viewPos);
        (*seq)++;
        break;
    case 1:
        if (func_021EA8A4(client->view) != 0) {
            (*seq)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}


/* Command 0x58. Show the status panel of a Pokemon; args: pokeId. */
int BTL_CLIENT_CmdShowStatusPanel(struct BtlClient *client, int *seq, u32 *args)
{
    int position;

    position = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->pokeContainer, (u8)args[0]);
    switch (*seq) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(client) != 0) {
            return 1;
        }
        func_021EA768(client->view, position, 1);
        (*seq)++;
        break;
    case 1:
        if (func_021EA778(client->view, position) != 0) {
            (*seq)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}


/* Command 0x01. Hide the status panel of a Pokemon; args: pokeId. */
int BTL_CLIENT_CmdHideStatusPanel(struct BtlClient *client, int *seq, u32 *args)
{
    int position;

    position = BTL_MAIN_GetTrainerSlotOfPoke(client->main, client->pokeContainer, (u8)args[0]);
    switch (*seq) {
    case 0:
        func_021EA788(client->view, position);
        (*seq)++;
        break;
    case 1:
        if (func_021EA798(client->view, position) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Command 0x02. Subtract HP; args: pokeId, damage.
 * extent: compiled 30 bytes followed by two zero alignment bytes.
 */
int BTL_CLIENT_CmdHpMinus(struct BtlClient *client, int *seq, u32 *args)
{
    BTL_POKEPARAM_SubHp(BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]), args[1]);
    return 1;
}

/* Command 0x03. Add HP up to the maximum; args: pokeId, amount. */
int BTL_CLIENT_CmdHpPlus(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_AddHp(pokeParam, args[1]);
    return 1;
}

/* Command 0x05. Subtract PP of a move in both the original and the working copy; args: pokeId, moveSlot, amount. */
int BTL_CLIENT_CmdPpMinusOriginal(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    u8 moveSlot, amount;
    moveSlot = args[1];
    amount = args[2];
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_DecrementMovePP(pokeParam, moveSlot, amount);
    return 1;
}

/* Command 0x06. Subtract PP of a move in the working copy only; args: pokeId, moveSlot, amount. */
int BTL_CLIENT_CmdPpMinusWorking(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    u8 moveSlot, amount;
    moveSlot = args[1];
    amount = args[2];
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_DecrementRealMovePP(pokeParam, moveSlot, amount);
    return 1;
}

/* Command 0x07. Mark a move slot as used; args: pokeId, moveSlot. */
int BTL_CLIENT_CmdMarkMoveUsed(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    u8 moveSlot;
    moveSlot = args[1];
    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_MarkMoveUsed(pokeParam, moveSlot);
    return 1;
}


/* Command 0x04. Set HP to 0; args: pokeId. */
int BTL_CLIENT_CmdHpZero(struct BtlClient *client, int *seq, u32 *args)
{
    BTL_POKEPARAM_ZeroHp(BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)*args));
    return 1;
}

/* Command 0x08. Restore PP of the original move; args: pokeId, moveSlot, amount. */
int BTL_CLIENT_CmdPpPlusOriginal(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_RestoreMovePP(pokeParam, (u8)args[1], args[2]);
    return 1;
}

/* Command 0x09. Restore PP of the working move copy; args: pokeId, moveSlot, amount. */
int BTL_CLIENT_CmdPpPlusWorking(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_RestoreRealMovePP(pokeParam, (u8)args[1], args[2]);
    return 1;
}

/* Command 0x0A. Raise one stat stage; args: pokeId, statIndex, steps. */
int BTL_CLIENT_CmdStatStageUp(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_RaiseStatStage(pokeParam, args[1], args[2]);
    return 1;
}

/* Command 0x0B. Lower one stat stage; args: pokeId, statIndex, steps. */
int BTL_CLIENT_CmdStatStageDown(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_LowerStatStage(pokeParam, args[1], args[2]);
    return 1;
}


/* Command 0x0C. Set all seven stat stages; args: pokeId, then one stage per stat. */
int BTL_CLIENT_CmdSetStatStages(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 1, args[1]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 2, args[2]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 3, args[3]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 4, args[4]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 5, args[5]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 6, args[6]);
    BTL_POKEPARAM_SetStatStage(pokeParam, 7, args[7]);
    return 1;
}


/* Command 0x0D. Recover lowered stat stages; args: pokeId. */
int BTL_CLIENT_CmdRecoverStatStages(struct BtlClient *client, int *seq, u32 *args)
{
    BTL_POKEPARAM_RaiseLoweredStatStages(BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)*args));
    return 1;
}


/* Command 0x0E. Reset all stat stages to neutral; args: pokeId. */
int BTL_CLIENT_CmdResetStatStages(struct BtlClient *client, int *seq, u32 *args)
{
    BTL_POKEPARAM_ResetStatStages(BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)*args));
    return 1;
}

/* Command 0x0F. Change the critical hit stage; args: pokeId, delta. */
int BTL_CLIENT_CmdAddCritStage(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_AddCritStage(pokeParam, args[1]);
    return 1;
}

/*
 * Command 0x10. Store a status condition; args: pokeId, sickIndex, condition.
 * lever: A declared one-word local assigned from args[2] preserves all 32
 * bits and emits the otherwise unused frame word. A cast lvalue at
 * args+2 compiled 30 bytes with the wrong frame and redundant address add.
 */
int BTL_CLIENT_CmdSetSick(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    union SickCont cont;

    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    cont.raw = args[2];
    BTL_POKEPARAM_SetSickCont(pokeParam, args[1], cont);
    return 1;
}


/* Command 0x11. Clear the major status; args: pokeId. */
int BTL_CLIENT_CmdCureMajorSick(struct BtlClient *client, int *seq, u32 *args)
{
    BTL_POKEPARAM_ClearMajorStatus(BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)*args));
    return 1;
}

/* Command 0x12. Clear one status condition; args: pokeId, sickIndex. */
int BTL_CLIENT_CmdCureSick(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_CureSick(pokeParam, args[1]);
    return 1;
}


/*
 * Command 0x13. A party member comes into battle: swap the two party
 * entries, reload the incoming Pokemon and arm its turn threshold; args[3]
 * is the threshold. The indices and the client come from the client work.
 */
int BTL_CLIENT_CmdMemberIn(struct BtlClient *client, int *seq, u32 *args)
{
    u8 indexFrom;
    u8 indexTo;
    void *party;
    struct BtlPokeParam *incoming;

    indexFrom = client->swapFrom;
    indexTo = client->swapTo;
    party = BTL_SIDE_GetSlotOfClient(client->pokeContainer, (u8)(client->swapClientId));
    if (indexFrom != indexTo)
        BTL_SLOT_Swap(party, indexFrom, indexTo);
    incoming = BTL_SLOT_GetPoke(party, indexFrom);
    BTL_POKEPARAM_StartTurnThreshold(incoming, args[3]);
    BTL_POKEPARAM_ReloadAndResetEffects(incoming);
    return 1;
}

/* Command 0x15. Set the two types of a Pokemon from a species; args: pokeId, species. */
int BTL_CLIENT_CmdSetPokeType(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, (u8)args[0]);
    BTL_POKEPARAM_SetTypes(pokeParam, (u16)args[1]);
    return 1;
}


/*
 * Command 0x17. Clear status conditions on several Pokemon; args:
 * pokeCount, sickCount, packed poke ids (six 5-bit values). Each sick index
 * comes from func_0689C9F8; a zero index ends the list.
 */
int BTL_CLIENT_CmdCureSickMulti(struct BtlClient *client, int *seq, u32 *args)
{
    u8 pokeIds[6];
    u32 i;
    u32 sickCount;
    u32 pokeCount;
    u32 j;
    u32 sickIndex;
    struct BtlPokeParam *pokeParam;

    sickCount = args[1];
    pokeCount = args[0];
    BTL_CALC_UnpackPokeIds(args[2], pokeIds);
    for (i = 0; i < sickCount; i++) {
        sickIndex = func_0689C9F8(i);
        if (sickIndex == 0)
            break;
        for (j = 0; j < pokeCount; j++) {
            pokeParam = BTL_SIDE_GetPokeByIdThunk(client->pokeContainer, pokeIds[j]);
            if (BTL_POKEPARAM_IsFainted(pokeParam) == 0)
                BTL_POKEPARAM_TickSickCont(pokeParam, sickIndex, 0, 0);
        }
    }
    return 1;
}
