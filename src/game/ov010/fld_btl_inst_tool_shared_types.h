#ifndef FLD_BTL_INST_TOOL_SHARED_TYPES_H
#define FLD_BTL_INST_TOOL_SHARED_TYPES_H

#include "../types.h"
#include "../arm9/pms_types.h"
#include "../arm9/btl_setup_types.h"

typedef struct GameData GameData;

typedef struct SaveControl SaveControl;

typedef struct Party Party;

/* Two PMS sentences back to back. */
typedef struct PmsSentencePair {
    u16 half[8];
} PmsSentencePair;

/* ---- Battle facility trainer data ---- */
typedef struct BattleMon {
    u16 species : 11;   /* 0x00 */
    u16 form : 5;
    u16 item;           /* 0x02 */
    u16 moves[4];       /* 0x04 */
    u32 otId;           /* 0x0C */
    u32 pid;            /* 0x10 */
    union {
        u32 ivs;        /* 0x14 */
        struct {
            u32 hpIv : 5;
            u32 atkIv : 5;
            u32 defIv : 5;
            u32 speIv : 5;
            u32 spaIv : 5;
            u32 spdIv : 5;
            u32 ivRest : 2;
        } b;
    } iv;
    u8 ev[6];           /* 0x18 */
    u8 ppUps;           /* 0x1E */
    u8 lang;            /* 0x1F */
    u8 ability;         /* 0x20 */
    u8 friendship;      /* 0x21 */
    u16 nick[11];       /* 0x22 */
    u8 nature;          /* 0x38 */
} BattleMon;

/* The first two draws, kept to build the matching record later. */
typedef struct BtlInstDraw {
    u32 otId;           /* 0x00 */
    u16 ids[2];         /* 0x04 */
    u32 pids[2];        /* 0x08 */
    u8 natures[2];      /* 0x10 */
} BtlInstDraw;

/* One facility trainer with the four Pokemon (0x120 bytes). */
typedef struct BtlInstTrainer {
    u32 trainerId;              /* 0x00 */
    u16 trainerType;            /* 0x04 */
    u8 reserved06[2];
    u16 name[8];                /* 0x08 */
    PmsData introMsg;           /* 0x18: type 0xFFFF = take the text from message bank 0xB8 at id */
    PmsSentencePair battleMsgs; /* 0x20 */
    BattleMon mons[4];          /* 0x30 */
} BtlInstTrainer;

#endif
