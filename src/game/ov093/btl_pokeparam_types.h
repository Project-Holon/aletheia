#ifndef BTL_POKEPARAM_TYPES_H
#define BTL_POKEPARAM_TYPES_H
/* ov093 battle: the battle-side state of one Pokemon (BtlPokeParam), 0x1f8 bytes. */

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

struct PokemonParam;

#define BTL_POKEPARAM_FOUGHT_MAX 0x18
#define BTL_POKEPARAM_HIT_TURNS 3
#define BTL_POKEPARAM_HIT_MAX 6
#define BTL_POKEPARAM_MOVE_COUNT 4
#define BTL_POKEPARAM_NO_POKE 0x1F

/*
 * One status condition ("sick") slot of a battle Pokemon: a kind and the
 * parameters that go with it. Kind 0 means the slot is empty.
 */
union SickCont {
    u32 raw;
    struct { u32 kind : 3; u32 paramLow : 6; u32 paramHigh : 6; u32 flags : 17; } byPart;
    struct { u32 kind : 3; u32 skipped : 6; u32 value : 16; u32 flagsWide : 7; } byValue;
};

/* One half of a move slot: move id, PP, PP maximum, PP ups and two counters. */
struct MoveInfo {
    u16 id;
    u8 pp;
    u8 ppMax;
    u8 ppUp;
    union {
        u8 counters;
        struct {
            u8 counterLow : 4;
            u8 counterHigh : 4;
        };
    };
};

/*
 * One move slot, 14 bytes. cur is the move as stored in the Pokemon, saved is
 * the move as the battle uses it (changed by Mimic and Transform). savedActive
 * is 1 while saved mirrors cur.
 */
struct BattleMoveSlot {
    union {
        u16 halves[6];
        struct {
            struct MoveInfo cur;
            struct MoveInfo saved;
        };
    };
    u8 savedActive;
    u8 savedSpare;
};

/* Stat stages in the order attack, defense, sp. attack, sp. defense, speed, accuracy, evasion. Neutral is 6, the cap is 12. */
struct StatStages {
    union {
        u8 stage[7];
        struct {
            s8 attack;
            s8 defense;
            s8 spAttack;
            s8 spDefense;
            u8 speed;
            s8 accuracy;
            s8 evasion;
        };
    };
};

/* One damage taken: the move that hit, the damage, the move type and the attacker. */
struct BtlHitRecord {
    u16 moveId;
    u16 damage;
    u16 moveType;
    u16 attackerId;
};

/* Stat gains of one level up, filled by BTL_POKEPARAM_AddExp. */
struct BtlLevelUpResult {
    u8 level;
    u8 reserved;
    u16 maxHpGain;
    u16 attackGain;
    u16 defenseGain;
    u16 spAttackGain;
    u16 spDefenseGain;
    u16 speedGain;
};

/*
 * The part of the record that a Transform keeps (everything before the
 * recorded stats); copied as words.
 */
typedef struct {
    u32 words[0x3b];
} BtlPokeParamKept;

struct BtlPokeParam {
    struct PokemonParam *mon;           /* 0x00 */
    struct PokemonParam *illusionMon;     /* 0x04 shown instead of mon while illusionActive */
    u32 exp;                            /* 0x08 */
    u16 species;                        /* 0x0c */
    u16 maxHp;                          /* 0x0e */
    u16 hp;                             /* 0x10 */
    u16 heldItem;                       /* 0x12 */
    u16 consumedItem;                   /* 0x14 */
    u16 baseAbility;                    /* 0x16 */
    u8 level;                           /* 0x18 */
    u8 partyIndex;                      /* 0x19 battle-wide id of the Pokemon */
    u8 genderRatio;                     /* 0x1a */
    u8 baseForm : 5;                    /* 0x1b form to restore after the battle */
    u8 isTransformed : 1;
    u8 illusionActive : 1;
    u8 thresholdArmed : 1;
    union SickCont sickCont[36];        /* 0x1c */
    u8 sickTurn[36];                    /* 0xac */
    u8 foughtCount;                     /* 0xd0 opponents this Pokemon fought (for exp) */
    u8 foughtIds[BTL_POKEPARAM_FOUGHT_MAX]; /* 0xd1 */
    u8 padE9[0xee - 0xe9];
    u16 attack;                         /* 0xee stats recorded at level up */
    u16 defense;                        /* 0xf0 */
    u16 spAttack;                       /* 0xf2 */
    u16 spDefense;                      /* 0xf4 */
    u16 speed;                          /* 0xf6 */
    u8 type1;                           /* 0xf8 */
    u8 type2;                           /* 0xf9 */
    u8 gender;                          /* 0xfa */
    u8 padFB;
    struct StatStages stages;           /* 0xfc */
    u8 pad103[1];
    struct BattleMoveSlot moves[BTL_POKEPARAM_MOVE_COUNT];     /* 0x104 */
    u16 ability;                        /* 0x13c effective ability */
    u16 weight;                         /* 0x13e */
    u8 moveCount;                       /* 0x140 */
    u8 form;                            /* 0x141 */
    u8 critStage;                       /* 0x142 */
    u8 usedMoveCount;                   /* 0x143 */
    u8 lastTargetPos;                   /* 0x144, 0x11 when none */
    u8 pad145[1];
    u16 turnsOnField;                   /* 0x146 */
    u16 turnThreshold;                  /* 0x148 */
    u16 lastSelectedMoveId;             /* 0x14a */
    u16 lastUsedMoveId;                 /* 0x14c */
    u16 moveStreak;                     /* 0x14e times the same move was used in a row */
    u8 pad150[2];
    u8 lastMoveSlot;                    /* 0x152 */
    u8 turnFlags[2];                    /* 0x153 cleared each turn */
    u8 contFlags[2];                    /* 0x155 cleared on switch-out */
    u8 counters[5];                     /* 0x157 */
    struct BtlHitRecord hitHistory[BTL_POKEPARAM_HIT_TURNS][BTL_POKEPARAM_HIT_MAX]; /* 0x15c */
    u8 hitCount[BTL_POKEPARAM_HIT_TURNS]; /* 0x1ec */
    u8 hitTurnIndex;                    /* 0x1ef */
    u8 hitHistorySpare;                 /* 0x1f0 */
    u8 pad1F1[1];
    u16 substituteHp;                   /* 0x1f2 */
    u16 storedMoveId;                   /* 0x1f4 reserved choice: move key */
    u8 storedPokeId;                    /* 0x1f6 reserved choice: Pokemon id, BTL_POKEPARAM_NO_POKE when none */
    u8 pad1F7;
};

typedef char BtlPokeParamSizeCheck[sizeof(struct BtlPokeParam) == 0x1f8 ? 1 : -1];

#endif
