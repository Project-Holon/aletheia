/*
 * function: BTL_SERVER_FLOW_ProcFaintedPoke
 * address: 0x021C4F64
 * packet: pkt_ov093_021C4F64
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 recoup: `ok = 0;` written after the call to BTL_SERVER_FLOW_ProcPokeLeaveField (it is
 * only read by the later compare), not before it; this puts the zero store in r2 as in the
 * original. EXACT in c99 and c. Callees: BTL_POKEPARAM_GetValue and BTL_MAIN_CheckSetupStatusFlag return int,
 * BTL_MAIN_PokeIdToClientIdThunk (unlabelled in ov093 matched set) returns u8, BTL_SERVER_FLOW_ProcPokeLeaveField and
 * BTL_MAIN_UpdateFriendshipIfPlayer are void with three arguments.
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   ZUKAN_DETAIL_FORM_DeleteModel 0x021C5078 thumb ov093
 *   BTL_MAIN_CheckSetupStatusFlag 0x021BA1A8 thumb ov093
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_ProcPokeLeaveField 0x021C5108 thumb ov093
 *   BTL_POKEPARAM_ResetAllEffects 0x021D646C thumb ov093
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_SERVER_FLOW_GetHighestOpponentLevel 0x021C5098 thumb ov093
 *   BTL_MAIN_UpdateFriendshipIfPlayer 0x021B92B0 thumb ov093
 *   func_021C5088 0x021C5088 thumb ov093
 *   BTL_MAIN_IsSameTeamClient 0x021B902C thumb ov093
 *   BTL_MAIN_TrainerRecordAdd 0x021BA1B4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void ZUKAN_DETAIL_FORM_DeleteModel(u8 *, u8);
extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_ProcPokeLeaveField(u8 *, u8 *, int);
extern void BTL_POKEPARAM_ResetAllEffects(u8 *);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u32 BTL_SERVER_FLOW_GetHighestOpponentLevel(u8 *);
extern void BTL_MAIN_UpdateFriendshipIfPlayer(char *p, void *m, int k);
extern void func_021C5088(u8 *, u8);
extern int BTL_MAIN_IsSameTeamClient(int, int);
extern void BTL_MAIN_TrainerRecordAdd(char **p, int i);
int BTL_SERVER_FLOW_ProcFaintedPoke(u8 *p, u8 *a)
{
    u8 k = BTL_POKEPARAM_GetPokeId(a);
    u8 *flags = p + 0x7a9;
    int ok;
    int side;
    int health;
    if (!flags[k] && BTL_POKEPARAM_IsFainted(a)) {
    flags[k] = 1;
    ZUKAN_DETAIL_FORM_DeleteModel(p + 0x3e0, k);
    if (!(BTL_MAIN_CheckSetupStatusFlag(*(void **)(p + 4), 0x200) && BTL_MAIN_PokeIdToClientIdThunk(k) != 0) && p[0x789] != k)
        BTL_SERVER_CMD_PushVariable(*(void **)(p + 12), 0x5b, 0, k, 0xffff0000);
    BTL_SERVER_CMD_Push(*(void **)(p + 12), 0x39, k);
    BTL_SERVER_FLOW_ProcPokeLeaveField(p, a, 0);
    ok = 0;
    BTL_POKEPARAM_ResetAllEffects(a);
    side = BTL_MAIN_PokeIdToClientIdThunk(k);
    if (side == BTL_MAIN_GetOwnClientId(*(u8 **)(p + 4))) {
        health = BTL_POKEPARAM_GetValue(a, 15);
        if (health + 30 <= (int)BTL_SERVER_FLOW_GetHighestOpponentLevel(p)) ok = 1;
        BTL_MAIN_UpdateFriendshipIfPlayer((char *)(*(u8 **)(p + 4)), a, ok);
    }
    func_021C5088(p + 0x1ab8, k);
    side = BTL_MAIN_PokeIdToClientIdThunk(k);
    {
        int current = BTL_MAIN_GetOwnClientId(*(u8 **)(p + 4));
        if (side == current) {
            BTL_MAIN_TrainerRecordAdd((char **)(*(u8 **)(p + 4)), 0x4c);
        } else if (!BTL_MAIN_IsSameTeamClient(side, current)) {
            BTL_MAIN_TrainerRecordAdd((char **)(*(u8 **)(p + 4)), 0x19);
            BTL_MAIN_TrainerRecordAdd((char **)(*(u8 **)(p + 4)), 0x52);
        }
    }
    return 1;
    }
    return 0;
}
