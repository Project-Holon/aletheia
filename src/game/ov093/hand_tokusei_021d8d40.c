/*
 * file:     hand_tokusei_021d8d40.c
 * unit:     yes
 * function: HAND_TOKUSEI_PlusMinusBoostSpecialPower, HAND_TOKUSEI_GetPlusMinusHandlers, HAND_TOKUSEI_CheckAllyHasAbility, HAND_TOKUSEI_IsCherrim, HAND_TOKUSEI_FlowerGiftUpdateForm, HAND_TOKUSEI_FlowerGiftUpdateFormIfOwner, HAND_TOKUSEI_ChangeCherrimForm, HAND_TOKUSEI_FlowerGiftReapplyForm, HAND_TOKUSEI_FlowerGiftRevertFormIfOwner, HAND_TOKUSEI_FlowerGiftRevertForm, HAND_TOKUSEI_FlowerGiftRevertFormOnFactorChange, HAND_TOKUSEI_FlowerGiftBoostAllyAttack, HAND_TOKUSEI_FlowerGiftBoostAllySpecialDefense, HAND_TOKUSEI_GetFlowerGiftHandlers, HAND_TOKUSEI_RivalryScalePower, HAND_TOKUSEI_GetRivalryHandlers, HAND_TOKUSEI_TechnicianBoostWeakMove, HAND_TOKUSEI_GetTechnicianHandlers
 * address:  0x021D8D40
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   gPlusMinusHandlers     0x021F06A0  data   ov093  a4
 *   gFlowerGiftHandlers     0x021F0E1C  data   ov093  a4
 *   gTechnicianHandlers 0x021F0608 data a4
 *   gRivalryHandlers     0x021F07E0  data   ov093  a4
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

/* Header word of the server command made by BTL_SERVER_FLOW_AllocCmdRecord. */
struct BtlCmdHeader { u32 lowBits : 23; u32 announce : 1; u32 kind : 8; };

extern int BTL_EVENT_GetVar(int key);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern int BTL_SERVER_FLOW_GetPokeViewPos(void *server, unsigned int pokeId);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(void *server, int sideKey, u8 *out);
extern void *BTL_SERVER_FLOW_GetPokeParam(void *server, int pokeId);
extern int func_021D59B4(u8 *pokeParam, int statKey);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *pokeParam);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(void *server);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *server, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *message, int kind, int stringId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct BtlMessage *message, u32 arg);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *server, void *cmd);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern int BTL_MAIN_IsPokeSamePair(unsigned int pokeIdA, unsigned int pokeIdB);
void HAND_TOKUSEI_PlusMinusBoostSpecialPower(struct BtlEventFactor *factor, void *server, int pokeId, u8 *work);
int *HAND_TOKUSEI_GetPlusMinusHandlers(int *handlerCount);
int HAND_TOKUSEI_CheckAllyHasAbility(void *server, int pokeId, u8 *idBuf, int abilityId);
int HAND_TOKUSEI_IsCherrim(void *server, int pokeId);
void HAND_TOKUSEI_FlowerGiftUpdateForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_FlowerGiftUpdateFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_ChangeCherrimForm(struct BtlEventFactor *factor, void *server, u32 pokeId, u32 form, u8 announce);
void HAND_TOKUSEI_FlowerGiftReapplyForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_FlowerGiftRevertFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_FlowerGiftRevertForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_FlowerGiftRevertFormOnFactorChange(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void HAND_TOKUSEI_FlowerGiftBoostAllyAttack(struct BtlEventFactor *factor, void *server, int pokeId);
void HAND_TOKUSEI_FlowerGiftBoostAllySpecialDefense(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_TOKUSEI_GetFlowerGiftHandlers(int *handlerCount);
void HAND_TOKUSEI_RivalryScalePower(struct BtlEventFactor *factor, void *server, int pokeId);
int *HAND_TOKUSEI_GetRivalryHandlers(int *handlerCount);
void HAND_TOKUSEI_TechnicianBoostWeakMove(struct BtlEventFactor *factor, void *server, int pokeId);
void *HAND_TOKUSEI_GetTechnicianHandlers(int *handlerCount);
extern int gPlusMinusHandlers[];
extern int gFlowerGiftHandlers[];
extern unsigned int gTechnicianHandlers;
extern int gRivalryHandlers[];

/* Plus/Minus (ability 57/58): power event of the owner, special move, an ally has Plus or Minus. */
void HAND_TOKUSEI_PlusMinusBoostSpecialPower(struct BtlEventFactor *factor, void *server, int pokeId, u8 *work)
{
    if (pokeId == BTL_EVENT_GetVar(3)) {
        if (HAND_TOKUSEI_CheckAllyHasAbility(server, pokeId, work, 0x39) != 0 || HAND_TOKUSEI_CheckAllyHasAbility(server, pokeId, work, 0x3a) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 2)
                BTL_EVENT_MultiplyVar(0x35, 6 << 10);
        }
    }
}

int *HAND_TOKUSEI_GetPlusMinusHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPlusMinusHandlers;
}

/* Collects the pokemon on the side of pokeId into idBuf; true if another one has ability abilityId. */
int HAND_TOKUSEI_CheckAllyHasAbility(void *server, int pokeId, u8 *idBuf, int abilityId)
{
    int side;
    u8 count;
    u8 i;

    side = BTL_SERVER_FLOW_GetPokeViewPos(server, pokeId);
    if (side != 6) {
        count = BTL_SERVER_FLOW_CollectAlivePokeIds(server, (u16)((7 << 8) | side), idBuf);
        for (i = 0; i < count; i++) {
            if (pokeId != idBuf[i]) {
                if (abilityId == func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(server, idBuf[i]), 0x11))
                    return 1;
            }
        }
    }
    return 0;
}

/* True if the pokemon is Cherrim (species 421). */
int HAND_TOKUSEI_IsCherrim(void *server, int pokeId)
{
    if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(server, pokeId)) == 0x1a5) return 1;
    return 0;
}

/* Flower Gift: Cherrim takes the sunshine form when the weather is sun; marks the work flag. */
void HAND_TOKUSEI_FlowerGiftUpdateForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (HAND_TOKUSEI_IsCherrim(server, pokeId)) {
        HAND_TOKUSEI_ChangeCherrimForm(factor, server, pokeId, (unsigned char)(BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1), 1);
        *work = 1;
    }
}

void HAND_TOKUSEI_FlowerGiftUpdateFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(2)) HAND_TOKUSEI_FlowerGiftUpdateForm(factor, server, pokeId, work);
}

/* Queues a form change of pokeId to form, unless it already has that form. */
void HAND_TOKUSEI_ChangeCherrimForm(struct BtlEventFactor *factor, void *server, u32 pokeId, u32 form, u8 announce)
{
    u8 *cmd;

    if (form != func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(server, pokeId), 0x13)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(server, 0x39, pokeId);
        cmd[4] = pokeId;
        cmd[5] = form;
        ((struct BtlCmdHeader *)cmd)->announce = announce;
        BTL_SERVER_FLOW_InitMsgRecord(cmd + 8, 2, 0xde);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct BtlMessage *)(cmd + 8), pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(server, cmd);
    }
}

void HAND_TOKUSEI_FlowerGiftReapplyForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work != 0 && HAND_TOKUSEI_IsCherrim(server, pokeId) != 0)
        HAND_TOKUSEI_ChangeCherrimForm(factor, server, pokeId, (u8)(BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1), 1);
}

void HAND_TOKUSEI_FlowerGiftRevertFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work && pokeId == BTL_EVENT_GetVar(2) && HAND_TOKUSEI_IsCherrim(server, pokeId))
        HAND_TOKUSEI_ChangeCherrimForm(factor, server, pokeId, 0, 0);
}

void HAND_TOKUSEI_FlowerGiftRevertForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work && HAND_TOKUSEI_IsCherrim(server, pokeId)) HAND_TOKUSEI_ChangeCherrimForm(factor, server, pokeId, 0, 0);
}

void HAND_TOKUSEI_FlowerGiftRevertFormOnFactorChange(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    int factorKey;

    if (*work != 0 && HAND_TOKUSEI_IsCherrim(server, pokeId) != 0) {
        if (pokeId == BTL_EVENT_GetVar(2)) {
            factorKey = BTL_EVENT_GetVar(0x10);
            if (factorKey != BTL_EVENT_GetFactorKey(factor))
                HAND_TOKUSEI_ChangeCherrimForm(factor, server, pokeId, 0, 0);
        }
    }
}

/* Flower Gift: ally of the attacker, sun, physical move: attack x1.5. */
void HAND_TOKUSEI_FlowerGiftBoostAllyAttack(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u8 attackerId;

    if (HAND_TOKUSEI_IsCherrim(server, pokeId) != 0 && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1) {
        attackerId = BTL_EVENT_GetVar(3);
        if (BTL_MAIN_IsPokeSamePair(pokeId, attackerId) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 1)
                BTL_EVENT_MultiplyVar(0x35, 3 << 11);
        }
    }
}

/* Flower Gift: ally of the defender, sun, special move: special defense x1.5. */
void HAND_TOKUSEI_FlowerGiftBoostAllySpecialDefense(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u8 defenderId;

    if (HAND_TOKUSEI_IsCherrim(server, pokeId) != 0 && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(server) == 1) {
        defenderId = BTL_EVENT_GetVar(4);
        if (BTL_MAIN_IsPokeSamePair(pokeId, defenderId) != 0) {
            if (BTL_EVENT_GetVar(0x1a) == 2)
                BTL_EVENT_MultiplyVar(0x35, 6 << 10);
        }
    }
}

int *HAND_TOKUSEI_GetFlowerGiftHandlers(int *handlerCount)
{
    *handlerCount = 11;
    return gFlowerGiftHandlers;
}

/* Rivalry: same gender x1.25, opposite gender x0.75, genderless no change. */
void HAND_TOKUSEI_RivalryScalePower(struct BtlEventFactor *factor, void *server, int pokeId)
{
    void *attacker;
    void *defender;
    u8 attackerGender;
    u8 defenderGender;

    if (pokeId == BTL_EVENT_GetVar(3)) {
        attacker = BTL_SERVER_FLOW_GetPokeParam(server, pokeId);
        defender = BTL_SERVER_FLOW_GetPokeParam(server, (u8)BTL_EVENT_GetVar(4));
        attackerGender = func_021D59B4(attacker, 0x12);
        defenderGender = func_021D59B4(defender, 0x12);
        if (attackerGender != 2 && defenderGender != 2) {
            if (attackerGender == defenderGender) {
                BTL_EVENT_MultiplyVar(0x31, 5 << 10);
                return;
            }
            BTL_EVENT_MultiplyVar(0x31, 3 << 10);
        }
    }
}

int *HAND_TOKUSEI_GetRivalryHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRivalryHandlers;
}

/* Technician: moves with base power 60 or less x1.5. */
void HAND_TOKUSEI_TechnicianBoostWeakMove(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(3) && (unsigned int)BTL_EVENT_GetVar(0x30) <= 0x3c) BTL_EVENT_MultiplyVar(0x31, 0x30 << 7);
}

void *HAND_TOKUSEI_GetTechnicianHandlers(int *handlerCount) { *handlerCount = 1; return &gTechnicianHandlers; }
