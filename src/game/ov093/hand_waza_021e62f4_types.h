#ifndef HAND_WAZA_021E62F4_TYPES_H
#define HAND_WAZA_021E62F4_TYPES_H
/*
 * ov093 move effect handlers (two-turn moves, Struggle, Destiny Bond, Grudge,
 * the moves that call other moves, and a few power modifiers): the command
 * records a handler pushes to the battle flow.
 *
 * A handler asks the flow for a record of one kind, fills it and hands it
 * back. Every record starts with a 32-bit header.
 */
#include "btl_event_types.h"

/* Record kinds written by these handlers. */
#define HANDEX_WAZA_KIND_MESSAGE 4
#define HANDEX_WAZA_KIND_PP_CHANGE 10
#define HANDEX_WAZA_KIND_ADD_SICK 12
#define HANDEX_WAZA_KIND_RANK_EFFECT 0xe
#define HANDEX_WAZA_KIND_KILL 0x13
#define HANDEX_WAZA_KIND_VISIBILITY 0x15
#define HANDEX_WAZA_KIND_SET_STATE 0x17
#define HANDEX_WAZA_KIND_CONSUME_ITEM 0x20
#define HANDEX_WAZA_KIND_ITEM_EFFECT 0x22
#define HANDEX_WAZA_KIND_ANIMATION 0x37

/* Event variables the move handlers read or write. */
#define WAZAVAR_POKE_ID 2
#define WAZAVAR_ATTACKER_ID 3
#define WAZAVAR_DEFENDER_ID 4
#define WAZAVAR_MOVE_ID 0x12
#define WAZAVAR_MOVE_SLOT 0xd
#define WAZAVAR_TARGET_SLOT 0xe
#define WAZAVAR_ITEM_SLOT 6
#define WAZAVAR_SECONDARY_RATE 0x1f
#define WAZAVAR_POWER_RATIO 0x31
#define WAZAVAR_FAIL_MESSAGE 0x3f
#define WAZAVAR_FAIL_FLAG 0x41
#define WAZAVAR_SKIP_FLAG 0x51

/* An opaque message parameter block that the string setters fill in. */
struct HandWazaMessage {
    u32 words[1];
};

/* Kind 4: show a message. */
struct HandWazaMessageRecord {
    u32 header;
    struct HandWazaMessage message;
};

/* Kinds 0x17 and 0x15: set a per-Pokemon state value (charge-turn flag, visibility). */
struct HandWazaStateRecord {
    u32 header;
    u32 state;
    u8 pokeId;
};

/* Kind 0xe: change a stat stage. */
struct HandWazaRankRecord {
    u32 header;
    u32 rankKind;
    u8 pad08[4];
    u8 volume;
    u8 pad0D;
    u8 flagB;
    u8 pokeCount;
    u8 pokeId;
};

/* Kind 0x20: use up a held item with a message. */
struct HandWazaConsumeItemRecord {
    u32 header;
    u16 flags;
    u8 pokeId;
    u8 pad07;
    u8 pad08[4];
    struct HandWazaMessage message;
};

/* Kind 0x22: apply the effect of a held item. */
struct HandWazaItemEffectRecord {
    u32 header;
    u8 pokeId;
    u8 pad05;
    u16 itemId;
};

/* Kind 0x13: kill a Pokemon, or print a message about it. */
struct HandWazaKillRecord {
    u32 header;
    u8 pokeId;
    u8 flag;
    u8 pad06[2];
    struct HandWazaMessage message;
};

/* Kind 10: change the PP of a move slot. */
struct HandWazaPpRecord {
    u32 header;
    s8 amount;
    u8 pokeId;
    u8 slot;
    u8 flags;
    struct HandWazaMessage message;
};

/* Kind 0x37: play a move animation. */
struct HandWazaAnimRecord {
    u32 header;
    u16 animId;
    u8 target;
    u8 mode;
    u8 pad08[3];
    u8 flag;
};

/* Kind 12: add a status condition. */
struct HandWazaSickRecord {
    u32 header;
    u32 sickKind;
    u32 sickCont;
    u8 pad0C;
    u8 flag;
    u8 pad0E;
    u8 pokeId;
};

#endif
