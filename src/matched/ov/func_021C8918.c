/*
 * function: BTL_SERVER_FLOW_ExecCmd
 * address:  0x021C8918
 * packet:   pkt_021C8918
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_ExecCmd   0x021C8918  thumb
 *   BTL_SIDE_GetPokeById   0x021B9940  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdPokeCmd42   0x021C8C6C  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdAbilityPopupIn   0x021C8CBC  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdAbilityPopupOut   0x021C8D0C  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdRecoverHp   0x021C8D2C  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdDrainHeal   0x021C8DE4  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdAbsorbRecovery   0x021C8E58  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdChangeHp   0x021C8F24  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdRestoreMovePp   0x021C8FA4  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdConsumeMovePp   0x021C9010  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdCureSick   0x021C9068  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdAddSick   0x021C9178  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdChangeStatStage   0x021C9250  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdSetStatStages   0x021C9394  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdRaiseLoweredStatStages   0x021C9448  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdResetStatStages   0x021C947C  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdSetStatValues   0x021C94C8  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdFinishHpChange   0x021C95D0  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdSetPokeTypes   0x021C962C  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdPushMessage   0x021C96D4  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdSetTurnFlag   0x021C9728  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdClearTurnFlag   0x021C9750  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdSetContFlag   0x021C9778  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdClearContFlag   0x021C97A4  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdAdjustValueMessage   0x021C97D0  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdExpireSideEffects   0x021C9828  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdRegisterFieldSlot   0x021C9898  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdExpireFieldEffect   0x021C98C4  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdChangeWeather   0x021C98E4  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdTrainerMessage   0x021C9A24  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdChangeAbility   0x021C9A60  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdChangeHeldItem   0x021C9BB8  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdSwapHeldItems   0x021C9CC0  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdProcItemReaction   0x021C9DCC  thumb ov093
 *   BTL_SERVER_FLOW_ExecCmdActivateHeldItem   0x021C9DE8  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExForceItemFactor   0x021C9E3C  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExConsumeItem   0x021C9ECC  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExReplaceMove   0x021C9F0C  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExSetPokeCounter   0x021C9F4C  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExUseMoveOnTarget   0x021C9F6C  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExEscape   0x021CA128  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExForceMemberOut   0x021CA158  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExPassEffects   0x021CA1D0  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExRollFlinch   0x021CA248  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExReviveAndSendIn   0x021CA270  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExSetWeight   0x021CA2E8  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExForceSwitch   0x021CA318  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExPromoteAction   0x021CA370  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExPromoteActionsByMove   0x021CA394  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExDemoteAction   0x021CA3AC  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExSwapPositions   0x021CA3D0  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExTransform   0x021CA47C  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExBreakIllusion   0x021CA570  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExGroundPokes   0x021CA5CC  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExClearContFlag   0x021CA6C4  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExPlayEffectAnim   0x021CA6FC  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExNotifyViewCmd56   0x021CA738  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExChangeForm   0x021CA748  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExSetTurnStateArg   0x021CA7C4  thumb ov093
 *   BTL_SERVER_FLOW_ProcHandExLatchTurnStateFlag   0x021CA7D4  thumb ov093
 *   BTL_SERVER_FLOW_GetHandExScopeArg   0x021CC960  thumb ov093
 *   BTL_SERVER_FLOW_IsHandExScopeActive   0x021CC96C  thumb ov093
 *   BTL_SERVER_FLOW_SetHandExScopeResult   0x021CC974  thumb ov093
 *   BTL_SERVER_FLOW_GetHandExScopeResult   0x021CC99C  thumb ov093
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 id : 8;
    u32 client : 5;
    u32 unk13 : 11;
    u32 ignoreIfBusy : 1;
    u32 checkFainted : 1;
    u32 unk26 : 6;
} BtlCmd;

typedef struct {
    u8 unk0[8];
    void *party;        /* 0x0008 */
    u8 unk0C[0x1D68];
    u8 queue[4];        /* 0x1D74 */
} BattleCtx;

struct S;
extern unsigned short BTL_SERVER_FLOW_GetHandExScopeArg(struct S *p);
struct Cmd;
struct Q;
struct Q10;
struct Q9;
extern int BTL_SERVER_FLOW_IsHandExScopeActive(struct Q9 *p);
extern int BTL_SERVER_FLOW_GetHandExScopeResult(struct Q10 *p);
extern void BTL_SERVER_FLOW_SetHandExScopeResult(void *q, int r);
extern u8 *BTL_SIDE_GetPokeById(char *p, u8 i);
extern int BTL_POKEPARAM_IsFainted(void *mon);
extern u8 BTL_SERVER_FLOW_ExecCmdActivateHeldItem(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdPokeCmd42(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdAbilityPopupIn(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdAbilityPopupOut(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdPushMessage(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdRecoverHp(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 BTL_SERVER_FLOW_ExecCmdDrainHeal(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 BTL_SERVER_FLOW_ExecCmdAbsorbRecovery(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdChangeHp(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdRestoreMovePp(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 BTL_SERVER_FLOW_ExecCmdConsumeMovePp(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 BTL_SERVER_FLOW_ExecCmdCureSick(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 BTL_SERVER_FLOW_ExecCmdAddSick(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdChangeStatStage(BattleCtx *s, BtlCmd *cmd, int arg);
extern u8 BTL_SERVER_FLOW_ExecCmdSetStatStages(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdResetStatStages(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdSetStatValues(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdRaiseLoweredStatStages(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdFinishHpChange(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdSetPokeTypes(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdSetTurnFlag(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdClearTurnFlag(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdSetContFlag(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdClearContFlag(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdAdjustValueMessage(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdExpireSideEffects(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdRegisterFieldSlot(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdExpireFieldEffect(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdChangeWeather(u8 *w, struct Cmd *c);
extern u8 BTL_SERVER_FLOW_ExecCmdTrainerMessage(void *p, const struct Cmd *q);
extern u8 BTL_SERVER_FLOW_ExecCmdChangeAbility(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdChangeHeldItem(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdProcItemReaction(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExForceItemFactor(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExConsumeItem(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ExecCmdSwapHeldItems(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExReplaceMove(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExSetPokeCounter(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExUseMoveOnTarget(u8 *p, u8 *q);
extern u8 BTL_SERVER_FLOW_ProcHandExEscape(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExForceMemberOut(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExPassEffects(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExRollFlinch(u8 *p, const u8 *q);
extern u8 BTL_SERVER_FLOW_ProcHandExReviveAndSendIn(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExSetWeight(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExForceSwitch(u8 *p, const struct Q *q);
extern u8 BTL_SERVER_FLOW_ProcHandExPromoteAction(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExPromoteActionsByMove(u8 *p, const u8 *q);
extern u8 BTL_SERVER_FLOW_ProcHandExDemoteAction(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExSwapPositions(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExTransform(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExBreakIllusion(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExGroundPokes(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExClearContFlag(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExPlayEffectAnim(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExNotifyViewCmd56(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExChangeForm(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExSetTurnStateArg(BattleCtx *s, BtlCmd *cmd);
extern u8 BTL_SERVER_FLOW_ProcHandExLatchTurnStateFlag(BattleCtx *s, BtlCmd *cmd);

void BTL_SERVER_FLOW_ExecCmd(BattleCtx *s, BtlCmd *cmd)
{
    int arg = BTL_SERVER_FLOW_GetHandExScopeArg((struct S *)s->queue);
    u8 r;

    if (BTL_SERVER_FLOW_IsHandExScopeActive((struct Q9 *)s->queue))
        r = BTL_SERVER_FLOW_GetHandExScopeResult((struct Q10 *)s->queue);
    else
        r = 1;

    if (cmd->ignoreIfBusy && r == 0)
        return;
    if (cmd->checkFainted && BTL_POKEPARAM_IsFainted(BTL_SIDE_GetPokeById(s->party, cmd->client)))
        return;

    switch (cmd->id) {
    case 1:
        r = BTL_SERVER_FLOW_ExecCmdPokeCmd42(s, cmd);
        break;
    case 2:
        r = BTL_SERVER_FLOW_ExecCmdAbilityPopupIn(s, cmd);
        break;
    case 3:
        r = BTL_SERVER_FLOW_ExecCmdAbilityPopupOut(s, cmd);
        break;
    case 0:
        r = BTL_SERVER_FLOW_ExecCmdActivateHeldItem(s, cmd);
        break;
    case 5:
        r = BTL_SERVER_FLOW_ExecCmdRecoverHp(s, cmd, arg);
        break;
    case 6:
        r = BTL_SERVER_FLOW_ExecCmdDrainHeal(s, cmd, arg);
        break;
    case 7:
        r = BTL_SERVER_FLOW_ExecCmdAbsorbRecovery(s, cmd);
        break;
    case 8:
        r = BTL_SERVER_FLOW_ExecCmdChangeHp(s, cmd);
        break;
    case 9:
        r = BTL_SERVER_FLOW_ExecCmdRestoreMovePp(s, cmd, arg);
        break;
    case 10:
        r = BTL_SERVER_FLOW_ExecCmdConsumeMovePp(s, cmd, arg);
        break;
    case 11:
        r = BTL_SERVER_FLOW_ExecCmdCureSick(s, cmd, arg);
        break;
    case 12:
        r = BTL_SERVER_FLOW_ExecCmdAddSick(s, cmd);
        break;
    case 14:
        r = BTL_SERVER_FLOW_ExecCmdChangeStatStage(s, cmd, arg);
        break;
    case 15:
        r = BTL_SERVER_FLOW_ExecCmdSetStatStages(s, cmd);
        break;
    case 18:
        r = BTL_SERVER_FLOW_ExecCmdRaiseLoweredStatStages(s, cmd);
        break;
    case 16:
        r = BTL_SERVER_FLOW_ExecCmdResetStatStages(s, cmd);
        break;
    case 17:
        r = BTL_SERVER_FLOW_ExecCmdSetStatValues(s, cmd);
        break;
    case 19:
        r = BTL_SERVER_FLOW_ExecCmdFinishHpChange(s, cmd);
        break;
    case 20:
        r = BTL_SERVER_FLOW_ExecCmdSetPokeTypes(s, cmd);
        break;
    case 4:
        r = BTL_SERVER_FLOW_ExecCmdPushMessage(s, cmd);
        break;
    case 21:
        r = BTL_SERVER_FLOW_ExecCmdSetTurnFlag(s, cmd);
        break;
    case 22:
        r = BTL_SERVER_FLOW_ExecCmdClearTurnFlag(s, cmd);
        break;
    case 23:
        r = BTL_SERVER_FLOW_ExecCmdSetContFlag(s, cmd);
        break;
    case 24:
        r = BTL_SERVER_FLOW_ExecCmdClearContFlag(s, cmd);
        break;
    case 25:
        r = BTL_SERVER_FLOW_ExecCmdAdjustValueMessage(s, cmd);
        break;
    case 26:
        r = BTL_SERVER_FLOW_ExecCmdExpireSideEffects(s, cmd);
        break;
    case 27:
        r = BTL_SERVER_FLOW_ExecCmdRegisterFieldSlot(s, cmd);
        break;
    case 29:
        r = BTL_SERVER_FLOW_ExecCmdChangeWeather((u8 *)s, (struct Cmd *)cmd);
        break;
    case 28:
        r = BTL_SERVER_FLOW_ExecCmdExpireFieldEffect(s, cmd);
        break;
    case 30:
        r = BTL_SERVER_FLOW_ExecCmdTrainerMessage(s, (const struct Cmd *)cmd);
        break;
    case 31:
        r = BTL_SERVER_FLOW_ExecCmdChangeAbility(s, cmd);
        break;
    case 32:
        r = BTL_SERVER_FLOW_ExecCmdChangeHeldItem(s, cmd);
        break;
    case 33:
        r = BTL_SERVER_FLOW_ExecCmdProcItemReaction(s, cmd);
        break;
    case 34:
        r = BTL_SERVER_FLOW_ProcHandExForceItemFactor(s, cmd);
        break;
    case 35:
        r = BTL_SERVER_FLOW_ProcHandExConsumeItem(s, cmd);
        break;
    case 36:
        r = BTL_SERVER_FLOW_ExecCmdSwapHeldItems(s, cmd);
        break;
    case 37:
        r = BTL_SERVER_FLOW_ProcHandExReplaceMove(s, cmd);
        break;
    case 38:
        r = BTL_SERVER_FLOW_ProcHandExSetPokeCounter(s, cmd);
        break;
    case 39:
        r = BTL_SERVER_FLOW_ProcHandExUseMoveOnTarget((u8 *)s, (u8 *)cmd);
        break;
    case 40:
        r = BTL_SERVER_FLOW_ProcHandExEscape(s, cmd);
        break;
    case 41:
        r = BTL_SERVER_FLOW_ProcHandExForceMemberOut(s, cmd);
        break;
    case 42:
        r = BTL_SERVER_FLOW_ProcHandExPassEffects(s, cmd);
        break;
    case 43:
        r = BTL_SERVER_FLOW_ProcHandExRollFlinch((u8 *)s, (const u8 *)cmd);
        break;
    case 44:
        r = BTL_SERVER_FLOW_ProcHandExReviveAndSendIn(s, cmd);
        break;
    case 45:
        r = BTL_SERVER_FLOW_ProcHandExSetWeight(s, cmd);
        break;
    case 46:
        r = BTL_SERVER_FLOW_ProcHandExForceSwitch((u8 *)s, (const struct Q *)cmd);
        break;
    case 47:
        r = BTL_SERVER_FLOW_ProcHandExPromoteAction(s, cmd);
        break;
    case 48:
        r = BTL_SERVER_FLOW_ProcHandExPromoteActionsByMove((u8 *)s, (const u8 *)cmd);
        break;
    case 49:
        r = BTL_SERVER_FLOW_ProcHandExDemoteAction(s, cmd);
        break;
    case 50:
        r = BTL_SERVER_FLOW_ProcHandExSwapPositions(s, cmd);
        break;
    case 51:
        r = BTL_SERVER_FLOW_ProcHandExTransform(s, cmd);
        break;
    case 52:
        r = BTL_SERVER_FLOW_ProcHandExBreakIllusion(s, cmd);
        break;
    case 53:
        r = BTL_SERVER_FLOW_ProcHandExGroundPokes(s, cmd);
        break;
    case 54:
        r = BTL_SERVER_FLOW_ProcHandExClearContFlag(s, cmd);
        break;
    case 55:
        r = BTL_SERVER_FLOW_ProcHandExPlayEffectAnim(s, cmd);
        break;
    case 56:
        r = BTL_SERVER_FLOW_ProcHandExNotifyViewCmd56(s, cmd);
        break;
    case 57:
        r = BTL_SERVER_FLOW_ProcHandExChangeForm(s, cmd);
        break;
    case 58:
        r = BTL_SERVER_FLOW_ProcHandExSetTurnStateArg(s, cmd);
        break;
    case 59:
        r = BTL_SERVER_FLOW_ProcHandExLatchTurnStateFlag(s, cmd);
        break;
    }
    BTL_SERVER_FLOW_SetHandExScopeResult(s->queue, r);
}
