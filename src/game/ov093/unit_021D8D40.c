/*
 * file:     unit_021D8D40.c
 * unit:     yes
 * function: BTL_ABILITY_PlusMinusBoostSpecialPower, BTL_ABILITY_GetPlusMinusHandlers, BTL_ABILITY_CheckAllyHasAbility, BTL_ABILITY_IsCherrim, BTL_ABILITY_FlowerGiftUpdateForm, BTL_ABILITY_FlowerGiftUpdateFormIfOwner, BTL_ABILITY_ChangeCherrimForm, BTL_ABILITY_FlowerGiftReapplyForm, BTL_ABILITY_FlowerGiftRevertFormIfOwner, BTL_ABILITY_FlowerGiftRevertForm, BTL_ABILITY_FlowerGiftRevertFormOnFactorChange, BTL_ABILITY_FlowerGiftBoostAllyAttack, BTL_ABILITY_FlowerGiftBoostAllySpecialDefense, BTL_ABILITY_GetFlowerGiftHandlers, BTL_ABILITY_RivalryScalePower, BTL_ABILITY_GetRivalryHandlers, BTL_ABILITY_TechnicianBoostWeakMove, BTL_ABILITY_GetTechnicianHandlers
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
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   gPlusMinusHandlerTable     0x021F06A0  data   ov093  a4
 *   gFlowerGiftHandlerTable     0x021F0E1C  data   ov093  a4
 *   gTechnicianHandlerTable 0x021F0608 data a4
 *   gRivalryHandlerTable     0x021F07E0  data   ov093  a4
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

/* Header word of the server command made by func_021C88A4. */
struct BtlCmdHeader { u32 lowBits : 23; u32 announce : 1; u32 kind : 8; };

extern int BTL_EVENT_GetVar(int key);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern int func_021C8010(void *server, unsigned int pokeId);
extern u8 func_021C7F68(void *server, int sideKey, u8 *out);
extern void *func_021C7CF4(void *server, int pokeId);
extern int func_021D59B4(u8 *pokeParam, int statKey);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *pokeParam);
extern int func_021C8288(void *server);
extern void *func_021C88A4(char *server, int cmdKind, int pokeId);
extern void func_021C8838(void *message, int kind, int stringId);
extern void func_021C8860(struct BtlMessage *message, u32 arg);
extern void func_021C88C8(void *server, void *cmd);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern int func_021B9A24(unsigned int pokeIdA, unsigned int pokeIdB);
void BTL_ABILITY_PlusMinusBoostSpecialPower(struct BtlEventFactor *factor, void *server, int pokeId, u8 *work);
int *BTL_ABILITY_GetPlusMinusHandlers(int *handlerCount);
int BTL_ABILITY_CheckAllyHasAbility(void *server, int pokeId, u8 *idBuf, int abilityId);
int BTL_ABILITY_IsCherrim(void *server, int pokeId);
void BTL_ABILITY_FlowerGiftUpdateForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ABILITY_FlowerGiftUpdateFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ABILITY_ChangeCherrimForm(struct BtlEventFactor *factor, void *server, u32 pokeId, u32 form, u8 announce);
void BTL_ABILITY_FlowerGiftReapplyForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ABILITY_FlowerGiftRevertFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ABILITY_FlowerGiftRevertForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ABILITY_FlowerGiftRevertFormOnFactorChange(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ABILITY_FlowerGiftBoostAllyAttack(struct BtlEventFactor *factor, void *server, int pokeId);
void BTL_ABILITY_FlowerGiftBoostAllySpecialDefense(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ABILITY_GetFlowerGiftHandlers(int *handlerCount);
void BTL_ABILITY_RivalryScalePower(struct BtlEventFactor *factor, void *server, int pokeId);
int *BTL_ABILITY_GetRivalryHandlers(int *handlerCount);
void BTL_ABILITY_TechnicianBoostWeakMove(struct BtlEventFactor *factor, void *server, int pokeId);
void *BTL_ABILITY_GetTechnicianHandlers(int *handlerCount);
extern int gPlusMinusHandlerTable[];
extern int gFlowerGiftHandlerTable[];
extern unsigned int gTechnicianHandlerTable;
extern int gRivalryHandlerTable[];

/* Plus/Minus (ability 57/58): power event of the owner, special move, an ally has Plus or Minus. */
void BTL_ABILITY_PlusMinusBoostSpecialPower(struct BtlEventFactor *factor, void *server, int pokeId, u8 *work)
{
    if (pokeId == BTL_EVENT_GetVar(3)) {
        if (BTL_ABILITY_CheckAllyHasAbility(server, pokeId, work, 0x39) != 0 || BTL_ABILITY_CheckAllyHasAbility(server, pokeId, work, 0x3a) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 2)
                BTL_EVENT_MultiplyVar(0x35, 6 << 10);
        }
    }
}

int *BTL_ABILITY_GetPlusMinusHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPlusMinusHandlerTable;
}

/* Collects the pokemon on the side of pokeId into idBuf; true if another one has ability abilityId. */
int BTL_ABILITY_CheckAllyHasAbility(void *server, int pokeId, u8 *idBuf, int abilityId)
{
    int side;
    u8 count;
    u8 i;

    side = func_021C8010(server, pokeId);
    if (side != 6) {
        count = func_021C7F68(server, (u16)((7 << 8) | side), idBuf);
        for (i = 0; i < count; i++) {
            if (pokeId != idBuf[i]) {
                if (abilityId == func_021D59B4(func_021C7CF4(server, idBuf[i]), 0x11))
                    return 1;
            }
        }
    }
    return 0;
}

/* True if the pokemon is Cherrim (species 421). */
int BTL_ABILITY_IsCherrim(void *server, int pokeId)
{
    if (BTL_POKEPARAM_GetSpecies(func_021C7CF4(server, pokeId)) == 0x1a5) return 1;
    return 0;
}

/* Flower Gift: Cherrim takes the sunshine form when the weather is sun; marks the work flag. */
void BTL_ABILITY_FlowerGiftUpdateForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (BTL_ABILITY_IsCherrim(server, pokeId)) {
        BTL_ABILITY_ChangeCherrimForm(factor, server, pokeId, (unsigned char)(func_021C8288(server) == 1), 1);
        *work = 1;
    }
}

void BTL_ABILITY_FlowerGiftUpdateFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(2)) BTL_ABILITY_FlowerGiftUpdateForm(factor, server, pokeId, work);
}

/* Queues a form change of pokeId to form, unless it already has that form. */
void BTL_ABILITY_ChangeCherrimForm(struct BtlEventFactor *factor, void *server, u32 pokeId, u32 form, u8 announce)
{
    u8 *cmd;

    if (form != func_021D59B4(func_021C7CF4(server, pokeId), 0x13)) {
        cmd = func_021C88A4(server, 0x39, pokeId);
        cmd[4] = pokeId;
        cmd[5] = form;
        ((struct BtlCmdHeader *)cmd)->announce = announce;
        func_021C8838(cmd + 8, 2, 0xde);
        func_021C8860((struct BtlMessage *)(cmd + 8), pokeId);
        func_021C88C8(server, cmd);
    }
}

void BTL_ABILITY_FlowerGiftReapplyForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work != 0 && BTL_ABILITY_IsCherrim(server, pokeId) != 0)
        BTL_ABILITY_ChangeCherrimForm(factor, server, pokeId, (u8)(func_021C8288(server) == 1), 1);
}

void BTL_ABILITY_FlowerGiftRevertFormIfOwner(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work && pokeId == BTL_EVENT_GetVar(2) && BTL_ABILITY_IsCherrim(server, pokeId))
        BTL_ABILITY_ChangeCherrimForm(factor, server, pokeId, 0, 0);
}

void BTL_ABILITY_FlowerGiftRevertForm(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    if (*work && BTL_ABILITY_IsCherrim(server, pokeId)) BTL_ABILITY_ChangeCherrimForm(factor, server, pokeId, 0, 0);
}

void BTL_ABILITY_FlowerGiftRevertFormOnFactorChange(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    int factorKey;

    if (*work != 0 && BTL_ABILITY_IsCherrim(server, pokeId) != 0) {
        if (pokeId == BTL_EVENT_GetVar(2)) {
            factorKey = BTL_EVENT_GetVar(0x10);
            if (factorKey != BTL_EVENT_GetFactorKey(factor))
                BTL_ABILITY_ChangeCherrimForm(factor, server, pokeId, 0, 0);
        }
    }
}

/* Flower Gift: ally of the attacker, sun, physical move: attack x1.5. */
void BTL_ABILITY_FlowerGiftBoostAllyAttack(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u8 attackerId;

    if (BTL_ABILITY_IsCherrim(server, pokeId) != 0 && func_021C8288(server) == 1) {
        attackerId = BTL_EVENT_GetVar(3);
        if (func_021B9A24(pokeId, attackerId) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 1)
                BTL_EVENT_MultiplyVar(0x35, 3 << 11);
        }
    }
}

/* Flower Gift: ally of the defender, sun, special move: special defense x1.5. */
void BTL_ABILITY_FlowerGiftBoostAllySpecialDefense(struct BtlEventFactor *factor, void *server, int pokeId)
{
    u8 defenderId;

    if (BTL_ABILITY_IsCherrim(server, pokeId) != 0 && func_021C8288(server) == 1) {
        defenderId = BTL_EVENT_GetVar(4);
        if (func_021B9A24(pokeId, defenderId) != 0) {
            if (BTL_EVENT_GetVar(0x1a) == 2)
                BTL_EVENT_MultiplyVar(0x35, 6 << 10);
        }
    }
}

int *BTL_ABILITY_GetFlowerGiftHandlers(int *handlerCount)
{
    *handlerCount = 11;
    return gFlowerGiftHandlerTable;
}

/* Rivalry: same gender x1.25, opposite gender x0.75, genderless no change. */
void BTL_ABILITY_RivalryScalePower(struct BtlEventFactor *factor, void *server, int pokeId)
{
    void *attacker;
    void *defender;
    u8 attackerGender;
    u8 defenderGender;

    if (pokeId == BTL_EVENT_GetVar(3)) {
        attacker = func_021C7CF4(server, pokeId);
        defender = func_021C7CF4(server, (u8)BTL_EVENT_GetVar(4));
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

int *BTL_ABILITY_GetRivalryHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRivalryHandlerTable;
}

/* Technician: moves with base power 60 or less x1.5. */
void BTL_ABILITY_TechnicianBoostWeakMove(struct BtlEventFactor *factor, void *server, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(3) && (unsigned int)BTL_EVENT_GetVar(0x30) <= 0x3c) BTL_EVENT_MultiplyVar(0x31, 0x30 << 7);
}

void *BTL_ABILITY_GetTechnicianHandlers(int *handlerCount) { *handlerCount = 1; return &gTechnicianHandlerTable; }
