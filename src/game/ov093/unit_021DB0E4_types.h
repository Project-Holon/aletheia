#ifndef UNIT_021DB0E4_TYPES_H
#define UNIT_021DB0E4_TYPES_H
/*
 * ov093 ability handlers (Run Away, Mold Breaker, Forecast, Storm Drain,
 * Lightning Rod, Suction Cups, Liquid Ooze, Klutz, Sticky Hold, Pressure,
 * Magic Guard, Stench, Shadow Tag, Arena Trap): the command records that the
 * handlers push to the battle server flow, and the event variable keys they use.
 */
#include "unit_021D8434_types.h"

struct BtlEventFactor;

/* Event variable keys used here, besides those in unit_021D8434_types.h. */
enum {
    BTL_EVAR_NEW_ABILITY_ID = 0x10,
    BTL_EVAR_VOLUME = 0x20,
    BTL_EVAR_FLINCH_BASE_CHANCE = 0x25,
    BTL_EVAR_FLINCH_CHANCE = 0x26,
    BTL_EVAR_NO_EFFECT_FLAG = 0x40,
    BTL_EVAR_SELF_CAUSED_FLAG = 0x2D,
    BTL_EVAR_EFFECT_FLAG = 0x51
};

/* Poke parameter values read through func_021D59B4. */
enum {
    BPP_VALUE_CURRENT_ABILITY = 0x11,
    BPP_VALUE_FORM = 0x13
};

#define SPECIES_CASTFORM 0x15F
#define POKETYPE_ELECTRIC 12
#define BTL_STAT_SP_ATTACK 3

/* Command kinds that the handlers pass to func_021C88A4 and func_021C88B4. */
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
extern void func_021C88B4(struct BtlSvFlow *flow, int kind, int pokeId);
extern void func_021C888C(void *str, u32 extra);
extern int func_021B9A24(u32 pokeIdA, u32 pokeIdB);
extern u8 func_021C7F68(struct BtlSvFlow *flow, int posKey, u8 *out);
extern int func_021C7D00(struct BtlSvFlow *flow, int pokeId);
extern int func_021C8234(struct BtlSvFlow *flow, int pokeId);
extern int func_021E85F8(int pokeId);

#endif
