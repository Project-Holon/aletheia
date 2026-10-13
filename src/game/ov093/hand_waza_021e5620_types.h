#ifndef HAND_WAZA_021E5620_TYPES_H
#define HAND_WAZA_021E5620_TYPES_H
/*
 * ov093 move effect handlers (Lunar Dance to Bounce range): the effect
 * records these handlers push to the battle flow, the event variables they
 * read, and the registry ids of the moves.
 *
 * Every handler has the signature (factor, flow, pokeId, work) and is
 * registered in the move registry (id, getter) at 0x021F3030. A getter
 * stores the number of handler rows through its argument and returns the
 * table of (event id, handler) rows.
 */

#include "hand_tokusei_021d9adc_types.h"
#include "btl_event_types.h"

struct BtlServerFlow;

/* Record kinds that only these handlers use (the shared ones are HANDEX_KIND_* in hand_tokusei_021d9adc_types.h). */
#define HAND_WAZA_KIND_CLEAR_TURN_FLAG 0x16
#define HAND_WAZA_KIND_SET_CONT_FLAG 0x17
#define HAND_WAZA_KIND_FAINT 0x13
#define HAND_WAZA_KIND_CLEAR_HAZARDS 0x1a
#define HAND_WAZA_KIND_SET_POS_EFFECT 0x1e
#define HAND_WAZA_KIND_USE_ITEM 0x22
#define HAND_WAZA_KIND_REMOVE_ITEM 0x23
#define HAND_WAZA_KIND_ESCAPE 0x28
#define HAND_WAZA_KIND_MESSAGE_ANIM 0x29
#define HAND_WAZA_KIND_SWITCH_OUT 0x37

/* Event variables (guesses are listed in the lane review notes). */
#define BTL_EVAR_TARGET_ID 6           /* the Pokemon the move aims at */
#define BTL_EVAR_TARGET_POSITION 0xd   /* where the move aims; 6 means "none chosen" */
#define BTL_EVAR_FAIL_REASON 0x22
#define BTL_EVAR_HIT_COUNT 0x2a
#define BTL_EVAR_BASE_POWER 0x30
#define BTL_EVAR_POWER_RATIO 0x31      /* 4096 based multiplier */
#define BTL_EVAR_HEAL_RATIO 0x35
#define BTL_EVAR_PROTECT_BYPASS 0x42
#define BTL_EVAR_HIT_SUBSTITUTE 0x46
#define BTL_EVAR_MOVE_BLOCKED 0x47
#define BTL_EVAR_GENERIC_FLAG 0x51     /* result slot; meaning depends on the event */
#define BTL_FAIL_REASON_MOVE_FAILED 0x1a

/* Move events these handlers answer. */
#define BTL_EVENT_MOVE_DELAYED_START 6   /* Future Sight and Doom Desire: the delayed attack is armed */
#define BTL_EVENT_MOVE_DELAYED_MESSAGE 7
#define BTL_EVENT_MOVE_NO_EFFECT 0xd
#define BTL_EVENT_MOVE_CHECK_FAIL 0x1f
#define BTL_EVENT_MOVE_EFFECT 0xa0       /* the effect of a status move */

/* Record header flag set by U-turn, Volt Switch and Baton Pass (meaning guessed: no wait after the message). */
#define HANDEX_FLAG_NO_WAIT (1 << 24)

/* Position effects (kind 0x1e, field effectKind). */
#define BTL_POS_EFFECT_WISH 0
#define BTL_POS_EFFECT_LUNAR_DANCE 1
#define BTL_POS_EFFECT_HEALING_WISH 2
#define BTL_POS_EFFECT_DELAYED_ATTACK 3   /* Future Sight, Doom Desire */
#define BTL_POS_EFFECT_BATON_PASS 4

/* Continuing flags set by kind 0x17. */
#define BTL_CONT_FLAG_FLYING 3
#define BTL_CONT_FLAG_SHADOW_FORCE 6
#define BTL_CONT_FLAG_BATON_PASS 0xe

/* Turn flag that Protect style moves set; cleared by kind 0x16. */
#define BTL_TURN_FLAG_PROTECTED 7
#define BTL_TURN_FLAG_ACTED 1

/* Status ids (guesses) used by Rapid Spin, Teleport and Magnet Rise. */
#define BTL_SICK_BIND 8
#define BTL_SICK_LEECH_SEED 0x12
#define BTL_SICK_INGRAIN 0x15
#define BTL_SICK_MAGNET_RISE 0x1e
#define BTL_SICK_FLOATING_BLOCK 0x1f
#define BTL_SICK_TRAPPED 0x16
#define BTL_SICK_ABILITY_SUPPRESSED 0x10

/* Kind 0x13: the user faints. */
struct HandExFaint {
    u32 header;
    u8 pokeId;
};

/* Kind 0x16: clear a turn flag of a Pokemon. */
struct HandExClearTurnFlag {
    u32 header;
    s32 turnFlag;
    u8 pokeId;
};

/* Kind 0x17: set a continuing flag of a Pokemon. */
struct HandExSetContFlag {
    u32 header;
    s32 contFlag;
    u8 pokeId;
};

/* Kind 0x1a: remove the entry hazards from a side. maskBytes[0] holds 3 and the other two bytes are the bit mask. */
struct HandExClearHazards {
    u32 header;
    u8 maskBytes[3];
    u8 side;
};

/* Kind 0x1e: arm a position effect (Wish, Lunar Dance, Healing Wish, delayed attack, Baton Pass). */
struct HandExSetPosEffect {
    u32 header;
    s32 effectKind;
    u8 position;
    u8 pad9[3];
    s32 param;       /* delayed attack: trigger turn; Baton Pass: the Pokemon that passes */
    s32 factorKey;   /* key of the event factor that owns the effect */
    u8 pad14[8];
    u8 mode;         /* 1 plain, 2 delayed attack */
};

/* Kind 0x22: use the held item of a Pokemon on another one. */
struct HandExUseItem {
    u32 header;
    u8 targetId;
    u8 pad5;
    u16 itemId;
};

/* Kind 0x23: remove the held item. */
struct HandExRemoveItem {
    u32 header;
    s32 consumeKind;
};

/* Kind 0x29: show a message and play the matching animation for pokeId. */
struct HandExMessageAnim {
    u32 header;
    struct HandExMessage message;
    u8 pad28[0x24];
    u8 pokeId;
    u8 animMode;
};

/* Kind 0x37: send a Pokemon back to its ball after a move (U-turn, Volt Switch). */
struct HandExSwitchOut {
    u32 header;
    u16 messageId;
    u8 position;
    u8 replacementSlot;
};

/* Kind 0xc with an announcement text: add a status condition and show a message. */
struct HandExAddSickAnnounce {
    u32 header;
    u32 sickKind;
    union SickCont sickCont;
    u8 suppressMessage;
    u8 pad0D[2];
    u8 pokeId;
    u8 pad10[4];
    struct HandExMessage message;
};

#endif
