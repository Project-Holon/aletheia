#ifndef ARM9_BATTLE_REC_TYPES_H
#define ARM9_BATTLE_REC_TYPES_H

#include "../arm9/btl_setup_types.h"

/*
 * Battle recorder record types (src/game/arm9/battle_rec.c, and the online
 * upload code in ov125) and the replay tools (ov186, ov188).  The one
 * definition of these records; uses only built-in types.
 */

/* Server id of a recorded battle, also read as two words. */
#ifdef __MWERKS__
#define BATTLE_REC_PACKED
#else
#define BATTLE_REC_PACKED __attribute__((packed)) /* the DS compiler aligns 64-bit members to 4 */
#endif
typedef union BATTLE_REC_PACKED BattleRecDataNumber {
    unsigned long long value;
    struct {
        unsigned int lo;
        unsigned int hi;
    } half;
} BattleRecDataNumber;

/* Battle recorder.  The header is a 0x44-byte summary of the recorded battle
 * (shown in lists without decoding the body); the body holds the battle
 * setup and the four parties.  Both carry the magic BATTLE_REC_MAGIC and a
 * CRC. */
struct BattleRecHeader {
    unsigned short species[12];
    unsigned char  formGender[12];     /* form in bits 0..6, gender in bit 7 */
    unsigned short battleCount;
    unsigned short mode;
    unsigned short magic;
    unsigned char  secure;
    unsigned char  version;
    unsigned char  unusedBytes[0x0C];
    BattleRecDataNumber dataNumber;
    unsigned short crc;
    unsigned short padding;
};

/* One Pokemon in packed form (0x70 bytes): the fields a replay needs. */
struct BattleRecMon {
    unsigned int   personality;             /* 0x00 */
    unsigned short partyDecoded : 1;        /* 0x04 always packed as 0 */
    unsigned short boxDecoded : 1;
    unsigned short checksumFailed : 1;
    unsigned short nature : 8;
    unsigned short spareFlags : 5;
    unsigned short species;                 /* 0x06 */
    unsigned short heldItem;                /* 0x08 */
    unsigned char  padAlign0A[2];           /* 0x0A alignment of otId */
    unsigned int   otId;                    /* 0x0C */
    unsigned int   exp;                     /* 0x10 */
    unsigned char  friendship;              /* 0x14 */
    unsigned char  ability;                 /* 0x15 */
    unsigned char  evs[6];                  /* 0x16 */
    unsigned short moves[4];                /* 0x1C */
    unsigned char  pp[4];                   /* 0x24 */
    unsigned char  ppUps[4];                /* 0x28 */
    unsigned int   ivHp : 5;                /* 0x2C */
    unsigned int   ivAttack : 5;
    unsigned int   ivDefense : 5;
    unsigned int   ivSpeed : 5;
    unsigned int   ivSpAttack : 5;
    unsigned int   ivSpDefense : 5;
    unsigned int   isEgg : 1;
    unsigned int   hasNickname : 1;
    unsigned char  fatefulEncounter : 1;    /* 0x30 */
    unsigned char  gender : 2;
    unsigned char  form : 5;
    unsigned char  padAlign31;              /* 0x31 alignment of nickname */
    unsigned short nickname[11];            /* 0x32 */
    unsigned short otName[8];               /* 0x48 */
    unsigned char  ball;                    /* 0x58 */
    unsigned char  language;                /* 0x59 */
    unsigned char  padAlign5A[2];           /* 0x5A alignment of statusCondition */
    unsigned int   statusCondition;         /* 0x5C */
    unsigned char  level;                   /* 0x60 */
    unsigned char  capsuleIndex;            /* 0x61 */
    unsigned short hp;                      /* 0x62 */
    unsigned short maxHp;                   /* 0x64 */
    unsigned short attack;                  /* 0x66 */
    unsigned short defense;                 /* 0x68 */
    unsigned short speed;                   /* 0x6A */
    unsigned short spAttack;                /* 0x6C */
    unsigned short spDefense;               /* 0x6E */
};

/* A packed party (0x2A4 bytes). */
struct BattleRecParty {
    unsigned short capacity;
    unsigned short count;
    struct BattleRecMon members[6];
};

/* A trainer in packed form (0x40 bytes). */
struct BattleRecTrainer {
    unsigned int   aiFlags;                 /* 0x00 */
    unsigned short trainerId;               /* 0x04 */
    unsigned short trainerType;             /* 0x06 */
    unsigned short itemIds[4];              /* 0x08 */
    unsigned short name[16];                /* 0x10 */
    unsigned short winWords[4];             /* 0x30 */
    unsigned short loseWords[4];            /* 0x38 */
};

enum BattleRecPlayerKind {
    BATTLE_REC_PLAYER_NONE = 0,
    BATTLE_REC_PLAYER_STATUS = 1,           /* a player: 0x20-byte status block */
    BATTLE_REC_PLAYER_TRAINER = 2           /* an AI trainer: BattleRecTrainer */
};

/* One battle participant (0x44 bytes). */
struct BattleRecPlayer {
    unsigned short kind;
    unsigned short voiceFlags;
    union {
        unsigned char status[0x20];         /* kind 1 (MyStatus copy) */
        struct BattleRecTrainer trainer;    /* kind 2 */
    } data;
};

/* The packed battle (0x17D8 bytes). */
struct BattleRecData {
    struct BattleRngState rng;              /* 0x0000 */
    struct FieldSituation field;            /* 0x0018 */
    unsigned char  config[4];               /* 0x0028 copy of struct Config */
    unsigned short bgmBattle;               /* 0x002C */
    unsigned short bgmWin;                  /* 0x002E */
    unsigned short resultCount;             /* 0x0030 BattleSetupParam+0x86 */
    unsigned char  competitor : 5;          /* 0x0032 */
    unsigned char  netId : 3;
    unsigned char  rule : 4;                /* 0x0033 */
    unsigned char  multiMode : 3;
    unsigned char  recordEnabled : 1;
    unsigned int   inputLogSize;            /* 0x0034 */
    unsigned char  inputLog[0xC00];         /* 0x0038 */
    struct BattleRecParty parties[4];       /* 0x0C38 */
    struct BattleRecPlayer players[4];      /* 0x16C8 */
};

/* The recorder work object: 0xC4 bytes this file never touches, then the data. */
struct BattleRec {
    unsigned char unknown00[0xC4];
    struct BattleRecData data;
};

struct BattleRecBody {
    unsigned char  setup[0xC38];
    struct BattleRecParty party[4];
    struct BattleRecPlayer players[4];  /* 0x16C8 */
    unsigned short magic;
    unsigned short unusedHalf;
    unsigned short crc;
    unsigned short padding;
};

struct BattleRecSave {
    unsigned char  profile[0x80];
    struct BattleRecHeader head;
    struct BattleRecBody body;
};

#endif
