/*
 * file:     unit_021D9118.c
 * unit:     yes
 * function: func_021D9118, func_021D9148, BTL_ABILITY_RecklessBoostRecoilPower, BTL_ABILITY_GetRecklessHandlers, func_021D919C, func_021D91D8, BTL_ABILITY_MoldBreakerSetIgnoreAbilities, BTL_ABILITY_GetMoldBreakerHandlers, BTL_ABILITY_GetIndirectGuardCause1Handlers, BTL_ABILITY_IndirectGuardCause1Block, BTL_ABILITY_IndirectGuardCause1ShowMessage, BTL_ABILITY_GetIndirectGuardCause6Handlers, BTL_ABILITY_IndirectGuardCause6Block, BTL_ABILITY_IndirectGuardCause6ShowMessage, BTL_ABILITY_GetIndirectGuardCause8Handlers, BTL_ABILITY_IndirectGuardCause8Block, BTL_ABILITY_IndirectGuardCause8ShowMessage, BTL_ABILITY_BlockIndirectDamage, BTL_ABILITY_ShowIndirectGuardMessage, func_021D9340, BTL_ABILITY_LeafGuardBlockStatus, func_021D93A8
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
 *   gIronFistHandlerTable 0x021F0758 data a4
 *   func_0201BD28  0x0201BD28  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   gMarvelScaleHandlerTable     0x021F06A8  data   ov093  a4
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   gRecklessHandlerTable     0x021F0720  data   ov093  a4
 *   gMoldBreakerHandlerTable     0x021F0618  data   ov093  a4
 *   gIndirectGuardCause1HandlerTable     0x021F0880  data   ov093  a4
 *   gIndirectGuardCause6HandlerTable     0x021F0890  data   ov093  a4
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   gHalveResidualDamageHandlerTable 0x021F06B8 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   BTL_CALC_HasDefaultSickCont 0x021D7D6C thumb ov093
 *   gLeafGuardHandlerTable 0x021F0A40 data a4
 *   gIndirectGuardCause8HandlerTable     0x021F08A0  data   ov093  a4
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
extern u32 func_0201BD28(u16 moveId, u32 field);
extern void *func_021C7CF4(void *server, int pokeId);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *pokeParam);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void func_021C88B4(void *server, int phase, int pokeId);
extern void *func_021C88A4(char *server, int cmdKind, int pokeId);
extern void func_021C8838(void *message, int kind, int stringId);
extern void func_021C8860(struct BtlMessage *message, u32 arg);
extern void func_021C88C8(void *server, void *cmd);
extern int func_021C8288(void *server);
extern int BTL_CALC_HasDefaultSickCont(int condition);
void func_021D9118(struct BtlEventFactor *factor, void *server, int pokeId);
void *func_021D9148(int *handlerCount);
void BTL_ABILITY_RecklessBoostRecoilPower(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ABILITY_GetRecklessHandlers(int *handlerCount);
void func_021D919C(struct BtlEventFactor *factor, void *server, int pokeId);
int *func_021D91D8(int *handlerCount);
void BTL_ABILITY_MoldBreakerSetIgnoreAbilities(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ABILITY_GetMoldBreakerHandlers(int *handlerCount);
int *BTL_ABILITY_GetIndirectGuardCause1Handlers(int *handlerCount);
void BTL_ABILITY_IndirectGuardCause1Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ABILITY_IndirectGuardCause1ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ABILITY_GetIndirectGuardCause6Handlers(int *handlerCount);
void BTL_ABILITY_IndirectGuardCause6Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ABILITY_IndirectGuardCause6ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ABILITY_GetIndirectGuardCause8Handlers(int *handlerCount);
void BTL_ABILITY_IndirectGuardCause8Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ABILITY_IndirectGuardCause8ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ABILITY_BlockIndirectDamage(void *server, int pokeId, int *work, int blockedCause);
void BTL_ABILITY_ShowIndirectGuardMessage(void *server, int pokeId, int *work, int stringId);
void func_021D9340(struct BtlEventFactor *factor, void *server, int pokeId);
void *func_021D9360(int *handlerCount);
void BTL_ABILITY_LeafGuardBlockStatus(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void func_021D93A8(struct BtlEventFactor *factor, void *server, int pokeId);
void *func_021D93CC(int *handlerCount);
extern unsigned int gIronFistHandlerTable;
extern int gMarvelScaleHandlerTable[];
extern int gRecklessHandlerTable[];
extern int gMoldBreakerHandlerTable[];
extern int gIndirectGuardCause1HandlerTable[];
extern int gIndirectGuardCause6HandlerTable[];
extern unsigned int gHalveResidualDamageHandlerTable;
extern unsigned int gLeafGuardHandlerTable;
extern int gIndirectGuardCause8HandlerTable[];

/* Iron Fist: punching moves (move flag 7) x1.2. */
void func_021D9118(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(3) && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 7)) BTL_EVENT_MultiplyVar(0x31, 0x1333);
}

void *func_021D9148(int *handlerCount) { *handlerCount = 1; return &gIronFistHandlerTable; }

/* Reckless: recoil moves, Jump Kick and Hi Jump Kick x1.2. */
void BTL_ABILITY_RecklessBoostRecoilPower(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u16 moveId;

    if (pokeId == BTL_EVENT_GetVar(3)) {
        moveId = BTL_EVENT_GetVar(0x12);
        if (func_0201BD28(moveId, 0x1e) != 0 || moveId == 0x1a || moveId == 0x88)
            BTL_EVENT_MultiplyVar(0x31, 0x1333);
    }
}

int *BTL_ABILITY_GetRecklessHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRecklessHandlerTable;
}

/* Marvel Scale: defender has a status condition, physical move: defense x1.5. */
void func_021D919C(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(4)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(func_021C7CF4(server, pokeId))) {
            BTL_EVENT_GetVar(0x12);
            if (BTL_EVENT_GetVar(0x1a) == 1)
                BTL_EVENT_MultiplyVar(0x35, 0x1800);
        }
    }
}

int *func_021D91D8(int *handlerCount)
{
    *handlerCount = 1;
    return gMarvelScaleHandlerTable;
}

/* Mold Breaker: sets the ignore-ability flag while the owner attacks. */
void BTL_ABILITY_MoldBreakerSetIgnoreAbilities(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x51, 1);
}

int *BTL_ABILITY_GetMoldBreakerHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMoldBreakerHandlerTable;
}

int *BTL_ABILITY_GetIndirectGuardCause1Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause1HandlerTable;
}

void BTL_ABILITY_IndirectGuardCause1Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_ABILITY_BlockIndirectDamage(server, pokeId, work, 0x1);
}

void BTL_ABILITY_IndirectGuardCause1ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_ABILITY_ShowIndirectGuardMessage(server, pokeId, work, 0xc9);
}

int *BTL_ABILITY_GetIndirectGuardCause6Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause6HandlerTable;
}

void BTL_ABILITY_IndirectGuardCause6Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_ABILITY_BlockIndirectDamage(server, pokeId, work, 0x6);
}

void BTL_ABILITY_IndirectGuardCause6ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_ABILITY_ShowIndirectGuardMessage(server, pokeId, work, 0xcf);
}

int *BTL_ABILITY_GetIndirectGuardCause8Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause8HandlerTable;
}

void BTL_ABILITY_IndirectGuardCause8Block(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_ABILITY_BlockIndirectDamage(server, pokeId, work, 0x8);
}

void BTL_ABILITY_IndirectGuardCause8ShowMessage(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_ABILITY_ShowIndirectGuardMessage(server, pokeId, work, 0xc6);
}

/* Indirect damage guard: when the owner takes damage of cause 8 or blockedCause, cancel it and arm the work flag. */
void BTL_ABILITY_BlockIndirectDamage(void *server, int pokeId, int *work, int blockedCause)
{
    if (pokeId == BTL_EVENT_GetVar(2) && pokeId != BTL_EVENT_GetVar(3)) {
        if (blockedCause == 8 || blockedCause == BTL_EVENT_GetVar(0x1f)) {
            if (BTL_EVENT_GetVar(0x20) < 0)
                work[0] = BTL_EVENT_OverwriteVar(0x41, 1);
        }
    }
}

/* Shows the guard message once; work[0] is the armed flag, work[1] the weather of the last message. */
void BTL_ABILITY_ShowIndirectGuardMessage(void *server, int pokeId, int *work, int stringId)
{
    int weather;
    u8 *cmd;

    if (pokeId == BTL_EVENT_GetVar(2) && work[0] != 0) {
        weather = BTL_EVENT_GetVar(0x19);
        if (weather == 0 || work[1] != weather) {
            func_021C88B4(server, 2, pokeId);
            cmd = func_021C88A4(server, 4, pokeId);
            func_021C8838(cmd + 4, 2, stringId);
            func_021C8860((struct BtlMessage *)(cmd + 4), pokeId);
            func_021C88C8(server, cmd);
            func_021C88B4(server, 3, pokeId);
            work[1] = weather;
        }
        work[0] = 0;
    }
}

/* Halves residual damage: doubles the damage divisor of the owner. */
void func_021D9340(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(2)) BTL_EVENT_OverwriteVar(0x20, BTL_EVENT_GetVar(0x20) << 1);
}

void *func_021D9360(int *handlerCount) { *handlerCount = 1; return &gHalveResidualDamageHandlerTable; }

/* Leaf Guard: in sun, the defender cannot get a major status condition or the condition 0xe. */
void BTL_ABILITY_LeafGuardBlockStatus(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    int condition;
    if (pokeId == BTL_EVENT_GetVar(4) && func_021C8288(server) == 1) {
        condition = BTL_EVENT_GetVar(0x1d);
        if (BTL_CALC_HasDefaultSickCont(condition) || condition == 0xe) *work = BTL_EVENT_OverwriteVar(0x41, 1);
    }
}

/* Leaf Guard: in sun, cancels the event for the owner. */
void func_021D93A8(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(2) && func_021C8288(server) == 1) BTL_EVENT_OverwriteVar(0x41, 1);
}

void *func_021D93CC(int *handlerCount) { *handlerCount = 3; return &gLeafGuardHandlerTable; }
