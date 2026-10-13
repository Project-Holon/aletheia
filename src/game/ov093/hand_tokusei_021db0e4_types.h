#ifndef UNIT_021DB0E4_TYPES_H
#define UNIT_021DB0E4_TYPES_H
#include "hand_common_types.h"
/*
 * ov093 ability handlers (Run Away, Mold Breaker, Forecast, Storm Drain,
 * Lightning Rod, Suction Cups, Liquid Ooze, Klutz, Sticky Hold, Pressure,
 * Magic Guard, Stench, Shadow Tag, Arena Trap): the command records that the
 * handlers push to the battle server flow, and the event variable keys they use.
 */
#include "btl_action_word_types.h"

struct BtlEventFactor;

/* Poke parameter values read through func_021D59B4. */
enum {
    BPP_VALUE_CURRENT_ABILITY = 0x11,
    BPP_VALUE_FORM = 0x13
};

#define SPECIES_CASTFORM 0x15F
#define POKETYPE_ELECTRIC 12
#define BTL_STAT_SP_ATTACK 3

/* Command kinds that the handlers pass to BTL_SERVER_FLOW_AllocCmdRecord and BTL_SERVER_FLOW_PushCmdRecord. */
enum {
    HANDEX_TOKWIN_IN = 2,
    HANDEX_TOKWIN_OUT = 3,
    HANDEX_MESSAGE = 4,
    HANDEX_DAMAGE = 7,
    HANDEX_POKE_NOTICE = 0x21,
    HANDEX_CHANGE_FORM = 0x39
};

/* String record inside a command: string id, string kind, up to 8 arguments. */
typedef struct HandExStr {
    u16 strId;
    u8 strType;
    u8 argCount : 7;
    u8 extraSet : 1;
    u32 args[8];
} HandExStr;

/* HANDEX_MESSAGE: show a string. */
typedef struct HandExMessage {
    u32 header;
    HandExStr str;
} HandExMessage;

/* HANDEX_DAMAGE: hurt a poke, then show a string. */
typedef struct HandExDamage {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07;
    u32 pad08;
    HandExStr str;
} HandExDamage;

/* HANDEX_CHANGE_FORM: set the form of a poke, then show a string. */
typedef struct HandExChangeForm {
    u32 header;
    u8 pokeId;
    u8 form;
    u8 pad06[2];
    HandExStr str;
} HandExChangeForm;

/* HANDEX_POKE_NOTICE: names one poke and nothing else. */
typedef struct HandExPokeNotice {
    u32 header;
    u8 pokeId;
} HandExPokeNotice;

/* Services of the battle server flow and the event factor list used by several of these files. */
extern int BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern u8 BTL_EVENT_GetFactorPokeId(struct BtlEventFactor *factor);
extern void BTL_EVENT_MarkFactorDead(struct BtlEventFactor *factor);
extern void BTL_EVENT_SetFactorSkipCheck(struct BtlEventFactor *factor, u32 skipCheck);
extern void BTL_EVENT_ClearFactorSkipCheck(struct BtlEventFactor *factor);
extern void BTL_SERVER_FLOW_PushCmdRecord(struct BtlSvFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_SetMsgRecordSe(void *str, u32 extra);
extern int BTL_MAIN_IsPokeSamePair(u32 pokeIdA, u32 pokeIdB);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(struct BtlSvFlow *flow, int posKey, u8 *out);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(struct BtlSvFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_IsPokeGroundedById(struct BtlSvFlow *flow, int pokeId);
extern int func_021E85F8(int pokeId);

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define BTL_EVAR_FLINCH_BASE_CHANCE BTL_EVAR_EFFECT_PERCENT_LOCKED
#define BTL_EVAR_FLINCH_CHANCE BTL_EVAR_EFFECT_PERCENT
#define BTL_EVAR_EFFECT_FLAG BTL_EVAR_FORCE_FLOATING_FLAG

#endif
