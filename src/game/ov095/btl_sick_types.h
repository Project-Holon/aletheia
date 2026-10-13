#ifndef BTL_SICK_TYPES_H
#define BTL_SICK_TYPES_H
/*
 * ov095 battle: volatile status conditions ("sick"). Per-turn damage, messages,
 * command records and the event handlers that read the conditions.
 */
#include "../ov093/hand_common_protos.h"

/* Condition kinds used here (the others live in the ov093 handler headers). */
#define BTL_SICK_NIGHTMARE 9
#define BTL_SICK_YAWN 0x0e
#define BTL_SICK_IDENTIFIED 0x11
#define BTL_SICK_HEAL_BLOCK 0x13   /* guess */
#define BTL_SICK_PERISH_SONG 0x14
#define BTL_SICK_TELEKINESIS 0x20
#define BTL_SICK_CURSE 10
#define BTL_SICK_LEECH_SEED 0x12
#define BTL_SICK_ENCORE 0x17
#define BTL_SICK_INGRAIN 0x15
#define BTL_SICK_FLOATING_BLOCK 0x1f
#define BTL_SICK_NO_ESCAPE 0x16
#define BTL_SICK_MAGNET_RISE 0x1e

/* Command record kinds the sick code writes. */
#define BTL_CMD_MESSAGE 4
#define BTL_CMD_RECOVER_HP 6
#define BTL_CMD_DAMAGE 7
#define BTL_CMD_CURE_SICK 0x0b
#define BTL_CMD_ADD_SICK 0x0c
#define BTL_CMD_FAINT 0x13
#define BTL_CMD_SET_SICK_STATE 0x21

/* Message type byte of a message record. */
#define BTL_STR_TYPE_STD 2

/* Services of the battle viewer slots and poke parameters that only this file uses. */
extern union SickCont BTL_POKEPARAM_GetSickContRaw(struct BtlPokeParam *bpp, int sickKind);
extern int BTL_POKEPARAM_GetSickTurn(struct BtlPokeParam *bpp, int sickKind);
extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_GetMovePPById(struct BtlPokeParam *bpp, int moveId);
extern int BTLV_CORE_GetSlotLow(union SickCont slot);
extern int BTLV_CORE_GetSlotValue(union SickCont slot);
extern int BTLV_CORE_GetSlotFlag(union SickCont slot);
extern int BTL_SERVER_FLOW_GetPosTableEntryForPoke(struct BtlServerFlow *flow, int pokeId);
extern int BTL_CALC_RandRange(int min, int max);
extern int func_021D62A8(struct BtlPokeParam *bpp);
extern int func_021E8A78(union SickCont slot);
extern void func_021C8810(void *message);

/* Command record kind 6: recover HP of one Pokemon, then show a message. */
typedef struct BtlCmdRecoverHp {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 sourceId;         /* who the HP comes from, BTL_EVENT_NO_POKE when nobody */
    BtlStrParam message;
} BtlCmdRecoverHp;

/* Command record kind 7: damage one Pokemon; an optional effect (message and view slots) follows. */
typedef struct BtlCmdDamage {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 flags;            /* bit 1: the effect fields are valid */
    u16 effectStringId;
    u8 effectArgA;
    u8 effectArgB;
    BtlStrParam message;
} BtlCmdDamage;

/* Command record kind 0x21: set a state flag of a Pokemon after a condition was added (guess). */
typedef struct BtlCmdSetSickState {
    u32 header;
    u8 pokeId;
    u8 pad05[3];
    u32 state;           /* 0 or 1, set by the condition that was added */
} BtlCmdSetSickState;

#define BTL_CMD_HEADER_QUIET 0x1000000   /* guess: the record shows no message of its own */
#define BTL_CMD_DAMAGE_HAS_EFFECT 2
#define BTL_CMD_ACTIVE_NONE 0x1f

/* The sick code of overlay 095 (names are mapped in rename_map.tsv). */
extern int BTL_SICK_BuildDamageMessage(BtlStrParam *message, struct BtlPokeParam *bpp, int sickKind);
extern int BTL_SICK_GetDamageStringId(int sickKind);
extern void BTL_SICK_TickPerishSong(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
extern void BTL_SICK_ApplyLeechSeed(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
extern void BTL_SICK_RecoverHpIngrain(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
extern void BTL_SICK_ApplyBindDamage(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
extern void BTL_SICK_RecoverHpAquaRing(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
extern void BTL_SICK_EndEncoreWhenPpEmpty(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
extern void BTL_SICK_OnAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId, int sickKind, union SickCont cont);
extern void BTL_SICK_StartYawnSleep(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
extern void BTL_SICK_ApplyPerishFaint(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
extern void BTL_SICK_ShowPerishCount(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, u8 count);
extern void BTL_SICK_OnHealBlockAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
extern void BTL_SICK_OnItemBlockAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
extern int BTL_SICK_GetCureStringId(unsigned int sickKind, union SickCont cont);
extern void BTL_SICK_BuildCureMessage(int sickKind, union SickCont cont, struct BtlPokeParam *bpp, BtlStrParam *message);
extern int BTL_SICK_GetAddStringId(u32 sickKind, int hasArg);
extern int BTL_SICK_BuildAddMessage(int sickKind, union SickCont cont, struct BtlPokeParam *bpp, u8 argValue, BtlStrParam *message);
extern void BTL_SICK_OverrideGroundImmunity(struct BtlEventFactor *factor, struct BtlPokeParam *bpp);
extern void BTL_SICK_ForceGroundedByTrap(struct BtlEventFactor *factor, struct BtlPokeParam *bpp);
extern void BTL_SICK_ForceGroundedOrFloating(struct BtlEventFactor *factor, struct BtlPokeParam *bpp);
extern void BTL_SICK_ShowIngrainRoots(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);

#endif
