#ifndef HAND_COMMON_TYPES_H
#define HAND_COMMON_TYPES_H
/*
 * ov093 battle handlers (abilities and held items): types shared by all handler files.
 * One name per event variable key; the same key is a differently named result slot in
 * different events (0x41 and 0x51 are shared flag slots: the names are the Iron Ball and
 * Air Balloon uses that decide them).
 */
#include "../ov093/btl_event_types.h"
#include "../ov093/btl_pokeparam_types.h"

/* A message the flow shows: string id, string type, argument count and up to eight argument words.
   Byte view: strType, argCount, argFlag. Halfword view of the same four bytes: strTypeHalf,
   argCountHalf, argFlagHalf (some handlers write the type and count through a halfword). */
typedef struct BtlStrParam {
    u16 strId;
    union {
        struct {
            u8 strType;
            u8 argCount : 7;
            u8 argFlag : 1;
        };
        struct {
            u16 strTypeHalf : 8;
            u16 argCountHalf : 7;
            u16 argFlagHalf : 1;
        };
    };
    u32 args[8];
} BtlStrParam;

/* HANDEX_KIND_MESSAGE: show a message. */
typedef struct HandExMessage {
    u32 header;
    BtlStrParam message;
} HandExMessage;

/* HANDEX_KIND_RECOVER_HP: recover HP, then show a message. */
typedef struct HandExRecoverHp {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07;
    BtlStrParam message;
} HandExRecoverHp;

/* HANDEX_KIND_DAMAGE: damage a Pokemon, then show a message. */
typedef struct HandExDamage {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 unblockable : 1;
    u8 flagsRest : 7;
    u32 pad08;
    BtlStrParam message;
} HandExDamage;

/* HANDEX_KIND_SET_ITEM: give a Pokemon a held item, then show a message. */
typedef struct HandExSetItem {
    u32 header;
    u16 itemId;
    u8 pokeId;
    u8 announce;
    u32 pad08;
    BtlStrParam message;
} HandExSetItem;

/* HANDEX_KIND_FAINT: make a Pokemon faint. */
typedef struct HandExFaint {
    u32 header;
    u8 pokeId;
} HandExFaint;

/* HANDEX_KIND_TRANSFORM: transform into the target, then show a message. */
typedef struct HandExTransform {
    u32 header;
    u8 targetId;
    u8 pad05[3];
    BtlStrParam message;
} HandExTransform;

/* HANDEX_KIND_SET_CONT_FLAG: set a condition flag on a Pokemon. */
typedef struct HandExSetContFlag {
    u32 header;
    s32 contFlag;
    u8 pokeId;
} HandExSetContFlag;

/* HANDEX_KIND_SET_COUNTER: set a counter of a Pokemon. */
typedef struct HandExSetCounter {
    u32 header;
    u8 pokeId;
    u8 counterId;
    u8 value;
} HandExSetCounter;

/* HANDEX_KIND_CURE_SICK: cure a status of up to 12 listed Pokemon. */
typedef struct HandExCureSick {
    u32 header;
    u32 sickKind;
    u8 pokeIds[12];
    u8 pokeCount;
    u8 suppressMessage;
    u8 pad16[2];
    BtlStrParam message;
} HandExCureSick;

/* HANDEX_KIND_ADD_SICK: add a status condition to a Pokemon. */
typedef struct HandExAddSick {
    u32 header;
    u32 sickKind;
    union SickCont sickCont;
    u8 suppressMessage;
    u8 fromMove;
    u8 ignoreImmunity;
    u8 pokeId;
    u8 useOwnMessage;
    u8 pad11[3];
    BtlStrParam message;
} HandExAddSick;

/* HANDEX_KIND_RANK_CHANGE: change stat stages. targetCount Pokemon ids at targets (pokeId is the first). */
typedef struct HandExRankChange {
    u32 header;
    u32 rankKind;
    u32 serialNumber;
    s8 volume;
    u8 fromMove;
    u8 showMessage;
    u8 targetCount;
    union {
        u8 pokeId;
        u8 targets[8];
    };
    BtlStrParam message;
} HandExRankChange;

/* Message command of the Btl*Cmd records (same layout as HandExMessage). */
typedef struct BtlMessageCmd {
    u32 header;
    BtlStrParam strParam;
} BtlMessageCmd;

/* Stat stage change command of the Btl*Cmd records (same layout as HandExRankChange). */
typedef struct BtlRankCmd {
    u32 header;
    u32 statId;
    u32 pad08;
    s8 amount;
    u8 pad0D;
    u8 showMessage;
    u8 targetCount;
    u8 targets[1];
} BtlRankCmd;

/* HANDEX_KIND_CHANGE_TYPE: set the type pair of a Pokemon (two bytes packed in a halfword). */
typedef struct HandExChangeType {
    u32 header;
    u16 typePair;
    u8 pokeId;
    u8 showMessage;
} HandExChangeType;

/* HANDEX_KIND_FLINCH: make a Pokemon flinch with a chance in percent. */
typedef struct HandExFlinch {
    u32 header;
    u8 pokeId;
    u8 percent;
} HandExFlinch;

/* HANDEX_KIND_ITEM_MESSAGE: consume the item flag, then show a string (the string is not used by Natural Gift). */
typedef struct HandExItemMessage {
    u32 header;
    u32 consumeItem;
    BtlStrParam message;
} HandExItemMessage;

/* HANDEX_KIND_REMOVE_SIDE_EFFECT (0x1a): end a side effect. Two writers see the three bytes after
   the header differently: as the effect container, or as mode, a spare byte and flags. */
typedef struct HandExRemoveSideEffect {
    u32 header;
    union {
        u8 effectCont[3];
        struct {
            u8 mode;    /* 3 */
            u8 pad5;
            u8 flags;   /* bits 1 and 2 set when mode is above 2 */
        };
    };
    u8 side;
} HandExRemoveSideEffect;

/* HANDEX_KIND_PLAY_EFFECT (0x37): play a battle effect from one position to another (toPos 6 is none). */
typedef struct HandExPlayEffect {
    u32 header;
    u16 effectId;
    u8 fromPos;
    u8 toPos;
} HandExPlayEffect;

/* Constants named by several handler files. */
/* Species and item ids that decide whether a held item can be taken or given. */
#define BTL_SPECIES_GIRATINA 0x1E7
#define BTL_SPECIES_ARCEUS 493
#define BTL_SPECIES_GENESECT 649
#define BTL_ITEM_GRISEOUS_ORB 112
#define BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE 3
#define BTL_BPP_VALUE_HP 13
#define BTL_BPP_VALUE_FORM 19
#define BTL_CMD_KIND_MESSAGE 4
#define BTL_CMD_KIND_ADD_SICK 12
#define BTL_CMD_KIND_RANK_CHANGE 14
#define BTL_CMD_KIND_CHANGE_TYPE 0x14
#define BTL_CMD_KIND_SET_ITEM 0x20
#define BTL_CONT_FLAG_CRITICAL_UP 9
#define BTL_RANK_ATTACK 1
#define BTL_RANK_DEFENSE 2
#define BTL_RANK_SP_ATTACK 3
#define BTL_RANK_SP_DEFENSE 4
#define BTL_RANK_KIND_COUNT 5
#define BTL_RANK_SPEED 5
#define BTL_RATIO_HALF 0x800
#define BTL_RATIO_DOUBLE 0x2000
#define BTL_SICK_CONFUSION 6
#define BTL_SICK_INFATUATION 7
#define BTL_SICK_BIND 8
#define BTL_SICK_ITEM_BLOCK 15
#define BTL_SICK_ANY_VOLATILE 0x26
#define BTL_VALUE_HP 13
#define BTL_VALUE_MAX_HP 14
#define BTL_WEATHER_SUN 1
#define BTL_WEATHER_RAIN 2
#define BTL_WEATHER_HAIL 3
#define BTL_WEATHER_SAND 4
#define HANDEX_KIND_USE_ITEM 0
#define HANDEX_KIND_MESSAGE 4
#define HANDEX_KIND_RECOVER_HP 5
#define HANDEX_KIND_DAMAGE 7
#define HANDEX_KIND_ADD_SICK 12
#define HANDEX_KIND_RANK_EFFECT 14
#define HANDEX_KIND_SET_CONT_FLAG 0x17
#define HANDEX_KIND_ITEM_MESSAGE 0x23
#define HANDEX_KIND_FLINCH 0x2b
#define HANDEX_STR_SET 2
#define ITEM_WORK_USED 0
#define ITEM_WORK_FORCED_USE 6
#define POKETYPE_BUG 6
#define POKETYPE_DARK 0x10
#define POKETYPE_DRAGON 15
#define POKETYPE_ELECTRIC 12
#define POKETYPE_FIGHTING 1
#define POKETYPE_FIRE 9
#define POKETYPE_FLYING 2
#define POKETYPE_GHOST 7
#define POKETYPE_GRASS 11
#define POKETYPE_GROUND 4
#define POKETYPE_ICE 14
#define POKETYPE_NORMAL 0
#define POKETYPE_POISON 3
#define POKETYPE_PSYCHIC 13
#define POKETYPE_ROCK 5
#define POKETYPE_STEEL 8
#define POKETYPE_WATER 10

/* Moved from the item handler header (used by the move handler registry code). */
#define BTL_GEM_STATE_IDLE 0
#define BTL_GEM_STATE_CONSUMED 1     /* the gem was used for this move; the power boost applies */
#define BTL_GEM_STATE_DONE 2         /* the damage of the move is finished */
#define BTL_GEM_RATIO 0x1800         /* 1.5 in 20.12 fixed point */
#define WAZA_HANDLER_REGISTRY_COUNT 0x102
#define BTL_EVENT_TYPE_WAZA 0
#define WAZA_HANDLER_FACTOR_LIMIT 8       /* at most 9 factors are scanned; a longer list refuses a new handler */
#define BTL_FACTOR_WORK_KEEP 6            /* work slot: nonzero for a handler that stays active */
/* One row of the move handler registry: move id and the function that returns its handler table. */
typedef struct {
    u16 moveId;
    BtlEventHandler *(*getHandlers)(int *handlerCount);
} WazaHandlerEntry;

/* Event variable keys read and written with BTL_EVENT_GetVar and BTL_EVENT_OverwriteVar. */
enum BtlEventVarKey {
    BTL_EVAR_POKE_ID = 0x02,
    BTL_EVAR_ATTACKER_ID = 0x03,
    BTL_EVAR_DEFENDER_ID = 0x04,
    BTL_EVAR_DEFENDER_COUNT = 0x05,
    BTL_EVAR_DEFENDER_FIRST = 0x06,
    BTL_EVAR_TURN_PHASE = 0x0C,
    BTL_EVAR_NEW_ABILITY_ID = 0x10,
    BTL_EVAR_ACTION_ORDER = 0x11,
    BTL_EVAR_MOVE_ID = 0x12,
    BTL_EVAR_MOVE_ID_USED = 0x14,
    BTL_EVAR_DEFENDER_TYPE = 0x15,
    BTL_EVAR_MOVE_TYPE = 0x16,
    BTL_EVAR_MOVE_PRIORITY = 0x18,
    BTL_EVAR_DAMAGE_TYPE = 0x1A,
    BTL_EVAR_SICK_ID = 0x1D,
    BTL_EVAR_SICK_CONT = 0x1E,
    BTL_EVAR_VOLUME = 0x20,
    BTL_EVAR_FAIL_REASON = 0x22,
    BTL_EVAR_WEATHER_TURNS = 0x24,
    BTL_EVAR_EFFECT_PERCENT_LOCKED = 0x25,
    BTL_EVAR_EFFECT_PERCENT = 0x26,
    BTL_EVAR_ATTACK_STAGE = 0x27,
    BTL_EVAR_DEFENSE_STAGE = 0x28,
    BTL_EVAR_ACCURACY = 0x2B,
    BTL_EVAR_CRITICAL_RANK = 0x2C,
    BTL_EVAR_SELF_CAUSED_FLAG = 0x2D,
    BTL_EVAR_TRIGGER_KIND = 0x2E,
    BTL_EVAR_POWER_RATIO = 0x31,
    BTL_EVAR_DAMAGE = 0x32,
    BTL_EVAR_POWER = 0x33,
    BTL_EVAR_RATIO = 0x35,
    BTL_EVAR_TYPE_AFFINITY = 0x38,
    BTL_EVAR_WEATHER = 0x39,
    BTL_EVAR_ENDURE_REASON = 0x3A,
    BTL_EVAR_NO_EFFECT_FLAG = 0x40,
    BTL_EVAR_FORCE_GROUNDED_FLAG = 0x41,
    BTL_EVAR_SAME_TYPE_FLAG = 0x44,
    BTL_EVAR_CRITICAL_FLAG = 0x45,
    BTL_EVAR_HIT_SUBSTITUTE_FLAG = 0x46,
    BTL_EVAR_EFFECT_BLOCKED_FLAG = 0x47,
    BTL_EVAR_ADDED_EFFECT_OFF_FLAG = 0x48,
    BTL_EVAR_IMMUNITY_OVERRIDE_FLAG = 0x4B,
    BTL_EVAR_SHEER_FORCE_FLAG = 0x4D,
    BTL_EVAR_FORCE_FLOATING_FLAG = 0x51,
    BTL_EVAR_SCREEN_KIND = 0x53,

    /* Other names of keys above and a few more, used by single handler files. Several names
       share one key where the key is a result slot whose meaning depends on the event. */
    BTL_EVAR_DAMAGED_ID = 6,  /* the target whose damage was just applied (guess) */
    BTL_EVAR_SWITCHING_POKE_ID = 6,  /* pursuit-before-switch event: the Pokemon that leaves */
    BTL_EVAR_TARGET_ID = 6,  /* target of the move being used */
    BTL_EVAR_TARGET_POSITION = 0xd,  /* where the move aims; 6 means "none chosen" */
    BTL_EVAR_MOVE_CATEGORY = BTL_EVAR_DAMAGE_TYPE,
    BTL_EVAR_MOVE_TARGET_KIND = 0x1b,
    BTL_EVAR_HIDE_KIND = 0x21,  /* how the target is hidden (BTL_CONT_FLAG_*) */
    BTL_EVAR_TARGET_SEMI_INVULNERABLE = 0x21,  /* contFlag of the target's semi-invulnerable state, 0x10 when none */
    BTL_EVAR_FLINCH_BASE_CHANCE = BTL_EVAR_EFFECT_PERCENT_LOCKED,
    BTL_EVAR_FLINCH_CHANCE = BTL_EVAR_EFFECT_PERCENT,
    BTL_EVAR_HIT_COUNT = 0x2a,
    BTL_EVAR_BASE_POWER = 0x30,
    BTL_EVAR_MAGNITUDE = 0x30,  /* guess: magnitude level the message shows */
    BTL_EVAR_WAZA_POWER = 0x30,
    BTL_EVAR_MOVE_POWER_RATIO = BTL_EVAR_POWER_RATIO,
    BTL_EVAR_DAMAGE_RATIO = 0x35,
    BTL_EVAR_HEAL_RATIO = 0x35,
    BTL_EVAR_FIXED_DAMAGE = 0x37,  /* damage that replaces the calculation (Bide) */
    BTL_EVAR_AFFINITY_SCALED = BTL_EVAR_TYPE_AFFINITY,
    BTL_EVAR_SURVIVE_RESULT = BTL_EVAR_ENDURE_REASON,
    BTL_EVAR_MOVE_HANDLED_FLAG = 0x3E,  /* move execute query: the handler took over the move (guess) */
    BTL_EVAR_MOVE_PHASE = 0x3E,  /* guess: 2 makes the flow skip the normal move execution */
    BTL_EVAR_MESSAGE = 0x3F,  /* pointer to the message the event is about to show */
    BTL_EVAR_NO_EFFECT_STRING = 0x3F,  /* no-effect check: string record to fill when the move fails */
    BTL_EVAR_MOVE_FAIL_FLAG = 0x40,  /* set to 1 to make the move fail */
    BTL_EVAR_PREVENT_FLAG = BTL_EVAR_FORCE_GROUNDED_FLAG,
    BTL_EVAR_AVOID_BY_SEMI_INVULNERABLE = 0x42,  /* nonzero: the target dodges because it is semi-invulnerable */
    BTL_EVAR_AVOID_FLAG = 0x42,  /* nonzero: the hidden target is not hit (guess) */
    BTL_EVAR_CHECK_EACH_HIT_FLAG = 0x42,  /* multi-hit count: check accuracy for every hit */
    BTL_EVAR_PROTECT_BYPASS = 0x42,
    BTL_EVAR_HIT_SUBSTITUTE = BTL_EVAR_HIT_SUBSTITUTE_FLAG,
    BTL_EVAR_SUBSTITUTE_FLAG = BTL_EVAR_HIT_SUBSTITUTE_FLAG,
    BTL_EVAR_MOVE_BLOCKED = 0x47,
    BTL_EVAR_IGNORE_IMMUNITY_FLAG = BTL_EVAR_IMMUNITY_OVERRIDE_FLAG,
    BTL_EVAR_ACCURACY_CHECK_FLAG = 0x51,  /* result of event 0x3d, default 0 (same key as the speed penalty flag) */
    BTL_EVAR_EFFECT_FLAG = BTL_EVAR_FORCE_FLOATING_FLAG,
    BTL_EVAR_GENERIC_FLAG = BTL_EVAR_FORCE_FLOATING_FLAG,
    BTL_EVAR_HANDLED_FLAG = BTL_EVAR_FORCE_FLOATING_FLAG,
    BTL_EVAR_RESULT_FLAG = 0x51,  /* boolean answer of many query events; move end passes the succeeded flag here */
    BTL_EVAR_SKIP_CHARGE_FLAG = BTL_EVAR_FORCE_FLOATING_FLAG,
    BTL_EVAR_SPEED_PENALTY_FLAG = BTL_EVAR_FORCE_FLOATING_FLAG,
    BTL_EVAR_USE_COUNT = 0x3D,  /* use counter */
    BTL_EVAR_REVERSE_SPEED_FLAG = 0x4A,  /* reverse the speed order (Trick Room) */
};

#endif
