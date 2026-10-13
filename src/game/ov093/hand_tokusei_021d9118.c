/*
 * file:     hand_tokusei_021d9118.c
 * unit:     yes
 * function: HAND_TOKUSEI_IronFistBoostPunchPower, HAND_TOKUSEI_GetIronFistHandlers, HAND_TOKUSEI_RecklessBoostRecoilPower, HAND_TOKUSEI_GetRecklessHandlers, HAND_TOKUSEI_MarvelScaleBoostDefense, HAND_TOKUSEI_GetMarvelScaleHandlers, HAND_TOKUSEI_MoldBreakerSetIgnoreAbilities, HAND_TOKUSEI_GetMoldBreakerFlagHandlers, HAND_TOKUSEI_GetIndirectGuardCause1Handlers, HAND_TOKUSEI_IndirectGuardCause1Block, HAND_TOKUSEI_IndirectGuardCause1ShowMessage, HAND_TOKUSEI_GetIndirectGuardCause6Handlers, HAND_TOKUSEI_IndirectGuardCause6Block, HAND_TOKUSEI_IndirectGuardCause6ShowMessage, HAND_TOKUSEI_GetIndirectGuardCause8Handlers, HAND_TOKUSEI_IndirectGuardCause8Block, HAND_TOKUSEI_IndirectGuardCause8ShowMessage, HAND_TOKUSEI_BlockIndirectDamage, HAND_TOKUSEI_ShowIndirectGuardMessage, HAND_TOKUSEI_HalveResidualDamage, HAND_TOKUSEI_LeafGuardBlockStatus, HAND_TOKUSEI_LeafGuardBlockOwnerEvent
 * address:  0x021D9118
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
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetFlag 0x0201BEB8 thumb
 *   gIronFistHandlers 0x021F0758 data a4
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   gMarvelScaleHandlers     0x021F06A8  data   ov093  a4
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   gRecklessHandlers     0x021F0720  data   ov093  a4
 *   gMoldBreakerFlagHandlers     0x021F0618  data   ov093  a4
 *   gIndirectGuardCause1Handlers     0x021F0880  data   ov093  a4
 *   gIndirectGuardCause6Handlers     0x021F0890  data   ov093  a4
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gHalveResidualDamageHandlers 0x021F06B8 data a4
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   BTL_CALC_HasDefaultSickCont 0x021D7D6C thumb ov093
 *   gLeafGuardHandlers 0x021F0A40 data a4
 *   gIndirectGuardCause8Handlers     0x021F08A0  data   ov093  a4
 */
struct BtlPokeParam;
struct BtlMessage;
struct BtlEventFactor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern unsigned int WAZA_TOOL_GetFlag(unsigned short moveId, unsigned int flagBit);
extern u32 WAZA_TOOL_GetParam(u16 moveId, u32 field);
extern void *BTL_SERVER_FLOW_GetPokeParam(void *server, int pokeId);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *pokeParam);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *server, int phase, int pokeId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *server, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *message, int kind, int stringId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct BtlMessage *message, u32 arg);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *server, void *cmd);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(void *server);
extern int BTL_CALC_HasDefaultSickCont(int condition);
void HAND_TOKUSEI_IronFistBoostPunchPower(struct BtlEventFactor *factor, void *server, int pokeId);
void *HAND_TOKUSEI_GetIronFistHandlers(int *handlerCount);
void HAND_TOKUSEI_RecklessBoostRecoilPower(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_TOKUSEI_GetRecklessHandlers(int *handlerCount);
void HAND_TOKUSEI_MarvelScaleBoostDefense(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_TOKUSEI_GetMarvelScaleHandlers(int *handlerCount);
void HAND_TOKUSEI_MoldBreakerSetIgnoreAbilities(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_TOKUSEI_GetMoldBreakerFlagHandlers(int *handlerCount);
int *HAND_TOKUSEI_GetIndirectGuardCause1Handlers(int *handlerCount);
void HAND_TOKUSEI_IndirectGuardCause1Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_IndirectGuardCause1ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_TOKUSEI_GetIndirectGuardCause6Handlers(int *handlerCount);
void HAND_TOKUSEI_IndirectGuardCause6Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_IndirectGuardCause6ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *HAND_TOKUSEI_GetIndirectGuardCause8Handlers(int *handlerCount);
void HAND_TOKUSEI_IndirectGuardCause8Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_IndirectGuardCause8ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_BlockIndirectDamage(void *server, int pokeId, int *work, int blockedCause);
void HAND_TOKUSEI_ShowIndirectGuardMessage(void *server, int pokeId, int *work, int stringId);
void HAND_TOKUSEI_HalveResidualDamage(struct BtlEventFactor *factor, void *server, int pokeId);
void *HAND_TOKUSEI_GetHalveResidualDamageHandlers(int *handlerCount);
void HAND_TOKUSEI_LeafGuardBlockStatus(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_LeafGuardBlockOwnerEvent(struct BtlEventFactor *factor, void *server, int pokeId);
void *HAND_TOKUSEI_GetLeafGuardHandlers(int *handlerCount);
extern unsigned int gIronFistHandlers;
extern int gMarvelScaleHandlers[];
extern int gRecklessHandlers[];
extern int gMoldBreakerFlagHandlers[];
extern int gIndirectGuardCause1Handlers[];
extern int gIndirectGuardCause6Handlers[];
extern unsigned int gHalveResidualDamageHandlers;
extern unsigned int gLeafGuardHandlers;
extern int gIndirectGuardCause8Handlers[];

/* Iron Fist: punching moves (move flag 7) x1.2. */
void HAND_TOKUSEI_IronFistBoostPunchPower(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(3) && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 7)) BTL_EVENT_MultiplyVar(0x31, 0x1333);
}

void *HAND_TOKUSEI_GetIronFistHandlers(int *handlerCount) { *handlerCount = 1; return &gIronFistHandlers; }

/* Reckless: recoil moves, Jump Kick and Hi Jump Kick x1.2. */
void HAND_TOKUSEI_RecklessBoostRecoilPower(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u16 moveId;

    if (pokeId == BTL_EVENT_GetVar(3)) {
        moveId = BTL_EVENT_GetVar(0x12);
        if (WAZA_TOOL_GetParam(moveId, 0x1e) != 0 || moveId == 0x1a || moveId == 0x88)
            BTL_EVENT_MultiplyVar(0x31, 0x1333);
    }
}

int *HAND_TOKUSEI_GetRecklessHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRecklessHandlers;
}

/* Marvel Scale: defender has a status condition, physical move: defense x1.5. */
void HAND_TOKUSEI_MarvelScaleBoostDefense(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(4)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(server, pokeId))) {
            BTL_EVENT_GetVar(0x12);
            if (BTL_EVENT_GetVar(0x1a) == 1)
                BTL_EVENT_MultiplyVar(0x35, 0x1800);
        }
    }
}

int *HAND_TOKUSEI_GetMarvelScaleHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMarvelScaleHandlers;
}

/* Mold Breaker: sets the ignore-ability flag while the owner attacks. */
void HAND_TOKUSEI_MoldBreakerSetIgnoreAbilities(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x51, 1);
}

int *HAND_TOKUSEI_GetMoldBreakerFlagHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMoldBreakerFlagHandlers;
}

int *HAND_TOKUSEI_GetIndirectGuardCause1Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause1Handlers;
}

void HAND_TOKUSEI_IndirectGuardCause1Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_BlockIndirectDamage(server, pokeId, work, 0x1);
}

void HAND_TOKUSEI_IndirectGuardCause1ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_ShowIndirectGuardMessage(server, pokeId, work, 0xc9);
}

int *HAND_TOKUSEI_GetIndirectGuardCause6Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause6Handlers;
}

void HAND_TOKUSEI_IndirectGuardCause6Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_BlockIndirectDamage(server, pokeId, work, 0x6);
}

void HAND_TOKUSEI_IndirectGuardCause6ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_ShowIndirectGuardMessage(server, pokeId, work, 0xcf);
}

int *HAND_TOKUSEI_GetIndirectGuardCause8Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause8Handlers;
}

void HAND_TOKUSEI_IndirectGuardCause8Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_BlockIndirectDamage(server, pokeId, work, 0x8);
}

void HAND_TOKUSEI_IndirectGuardCause8ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    HAND_TOKUSEI_ShowIndirectGuardMessage(server, pokeId, work, 0xc6);
}

/* Indirect damage guard: when the owner takes damage of cause 8 or blockedCause, cancel it and arm the work flag. */
void HAND_TOKUSEI_BlockIndirectDamage(void *server, int pokeId, int *work, int blockedCause)
{
    if (pokeId == BTL_EVENT_GetVar(2) && pokeId != BTL_EVENT_GetVar(3)) {
        if (blockedCause == 8 || blockedCause == BTL_EVENT_GetVar(0x1f)) {
            if (BTL_EVENT_GetVar(0x20) < 0)
                work[0] = BTL_EVENT_OverwriteVar(0x41, 1);
        }
    }
}

/* Shows the guard message once; work[0] is the armed flag, work[1] the weather of the last message. */
void HAND_TOKUSEI_ShowIndirectGuardMessage(void *server, int pokeId, int *work, int stringId)
{
    int weather;
    u8 *cmd;

    if (pokeId == BTL_EVENT_GetVar(2) && work[0] != 0) {
        weather = BTL_EVENT_GetVar(0x19);
        if (weather == 0 || work[1] != weather) {
            BTL_SERVER_FLOW_PushCmdRecord(server, 2, pokeId);
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(server, 4, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(cmd + 4, 2, stringId);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct BtlMessage *)(cmd + 4), pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(server, cmd);
            BTL_SERVER_FLOW_PushCmdRecord(server, 3, pokeId);
            work[1] = weather;
        }
        work[0] = 0;
    }
}

/* Halves residual damage: doubles the damage divisor of the owner. */
void HAND_TOKUSEI_HalveResidualDamage(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(2)) BTL_EVENT_OverwriteVar(0x20, BTL_EVENT_GetVar(0x20) << 1);
}

void *HAND_TOKUSEI_GetHalveResidualDamageHandlers(int *handlerCount) { *handlerCount = 1; return &gHalveResidualDamageHandlers; }

/* Leaf Guard: in sun, the defender cannot get a major status condition or the condition 0xe. */
void HAND_TOKUSEI_LeafGuardBlockStatus(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    int condition;
    if (pokeId == BTL_EVENT_GetVar(4) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1) {
        condition = BTL_EVENT_GetVar(0x1d);
        if (BTL_CALC_HasDefaultSickCont(condition) || condition == 0xe) *work = BTL_EVENT_OverwriteVar(0x41, 1);
    }
}

/* Leaf Guard: in sun, cancels the event for the owner. */
void HAND_TOKUSEI_LeafGuardBlockOwnerEvent(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(2) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1) BTL_EVENT_OverwriteVar(0x41, 1);
}

void *HAND_TOKUSEI_GetLeafGuardHandlers(int *handlerCount) { *handlerCount = 3; return &gLeafGuardHandlers; }
