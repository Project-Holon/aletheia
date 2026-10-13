#ifndef SCRCMD_POKEMON_FLD_TYPES_H
#define SCRCMD_POKEMON_FLD_TYPES_H

/*
 * Mystery gift handlers of the Pokemon field script commands
 * (scrcmd_pokemon_fld.c). The script command that reads a received gift
 * (SCRCMD_POKEMON_FLD_HandleMysteryGift) picks a row of the kind table by the gift type of the
 * card and runs one handler of it.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct ScrcmdWork;
struct GameData;
struct WordSet;

/* A received gift card (0xCC bytes), same layout as MysteryCard in mystery_data.c. */
typedef struct MysteryGiftCard {
    u32 param;              /* 0x00: item id of an item card, flag id of a kind 3 card */
    u8 body[0xAC];          /* 0x04 */
    u16 eventId;            /* 0xB0: distribution event number */
    u8 padB2;
    u8 giftType;            /* 0xB3: MYSTERY_GIFT_TYPE_* */
    u8 flags;               /* 0xB4 */
    u8 tail[0x17];          /* 0xB5 */
} MysteryGiftCard;

#define MYSTERY_GIFT_TYPE_NONE   0
#define MYSTERY_GIFT_TYPE_MON    1   /* a Pokemon or an egg */
#define MYSTERY_GIFT_TYPE_ITEM   2   /* an item */
#define MYSTERY_GIFT_TYPE_FLAG   3   /* sets an obtained flag of the intrude save */

#define MYSTERY_GIFT_PARTY_MAX   6
#define MYSTERY_GIFT_ITEM_MAX    0x272   /* highest item id a card may carry */
#define MYSTERY_GIFT_MON_PARAM_IS_EGG 0x4C

/* Values of getReceiveType (what kind of scene the script plays). */
#define MYSTERY_GIFT_RECEIVE_MON          1
#define MYSTERY_GIFT_RECEIVE_EGG          2
#define MYSTERY_GIFT_RECEIVE_ITEM         3
#define MYSTERY_GIFT_RECEIVE_LIBERTY_PASS 4
#define MYSTERY_GIFT_RECEIVE_FLAG         5

/* Message ids the prepare handlers return (the script shows them). */
#define MYSTERY_GIFT_MSG_MON_RECEIVED   5
#define MYSTERY_GIFT_MSG_MON_FOLLOW_UP  6
#define MYSTERY_GIFT_MSG_ITEM_RECEIVED  7
#define MYSTERY_GIFT_MSG_ITEM_FOLLOW_UP 8
#define MYSTERY_GIFT_MSG_FLAG_RECEIVED  9
#define MYSTERY_GIFT_MSG_FLAG_FOLLOW_UP 10
#define MYSTERY_GIFT_MSG_EGG_RECEIVED   11

/* Gift whose card carries this item and event number is the Liberty Pass. */
#define MYSTERY_GIFT_LIBERTY_PASS_ITEM  0x23E
#define MYSTERY_GIFT_LIBERTY_PASS_EVENT 0x7FE

typedef int (*MysteryGiftQueryFn)(struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
typedef void (*MysteryGiftReceiveFn)(struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
typedef int (*MysteryGiftMessageFn)(struct WordSet *wordSet, MysteryGiftCard *card, struct ScrcmdWork *work);

/* One row (0x18 bytes) of the gift kind table, indexed by gift type. A null
 * handler means the kind does that step with no code. */
typedef struct MysteryGiftKindHandlers {
    int kind;                                   /* 0x00: same as the row index, 0 for a missing kind */
    MysteryGiftQueryFn canReceive;              /* 0x04: 1 when the player can take the gift now */
    MysteryGiftReceiveFn receive;               /* 0x08: puts the gift into the save */
    MysteryGiftQueryFn getReceiveType;          /* 0x0C: scene class of the gift for the script */
    MysteryGiftMessageFn prepareReceiveMessage; /* 0x10: fills the word set, returns the message id */
    MysteryGiftMessageFn prepareFollowUpMessage; /* 0x14: second message, same contract */
} MysteryGiftKindHandlers;

extern const MysteryGiftKindHandlers sMysteryGiftKindHandlers[];

#endif
