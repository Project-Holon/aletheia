#ifndef BTLV_EFFECT_SHARED_TYPES_H
#define BTLV_EFFECT_SHARED_TYPES_H

#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_stage_shared_types.h"
#include "btlv_field_shared_types.h"
#include "btlv_clact_shared_types.h"
#include "btlv_bg_types.h"
#include "btlv_timer_shared_types.h"
#include "btlv_b_gauge_types.h"
#include "btlv_mcss_shared_types.h"
#include "btlv_gauge_types.h"

struct Ctx;

struct Node;

struct S02030EE8;

struct PalAnmSlot;

typedef enum { SLOT_ZERO, SLOT_LAST = 14 } BtlvSlotIndex;

#include "../types.h"

/* Part of the battle setup returned by BTL_MAIN_GetFieldSituation (0x10 bytes): where the battle takes place. */
typedef struct BtlvEffFieldSituation {
    int stageGroup;         /* 0x00: row of the stage table */
    int stageIndex;         /* 0x04: column of the stage table */
    u8 lightArg0;           /* 0x08 */
    u8 variant;             /* 0x09: stage variant when the row allows one, also a light argument */
    u16 lightArg1;          /* 0x0A */
    u8 lightArg2;           /* 0x0C */
    u8 lightArg3;           /* 0x0D */
    u8 pad_0E[2];           /* never read */
} BtlvEffFieldSituation;

/* Battle effect setup, copied into the work by BTLV_EFFECT_Init (0x2C bytes), built by BTLV_EFFECT_CreateSetup. */
typedef struct BtlvEffSetup {
    int mode;                           /* 0x00: battle visual mode (BTL_MAIN_GetRule), also the stage kind (3 = special stage) */
    int competitor;                     /* 0x04: BTL_MAIN_GetCompetitor */
    BtlvEffFieldSituation situation;    /* 0x08 */
    u16 trainerType[4];                 /* 0x18 */
    int isMultiMode;                    /* 0x20: BTL_MAIN_IsMultiMode */
    int sceneUnit;                        /* 0x24: second argument of BTLV_EFFECT_CreateSetupFromBattleMain, returned by BTLV_EFFECT_GetSceneUnit */
    void *battle;                       /* 0x28: battle main, 0 outside battle */
} BtlvEffSetup;

/* Request to run a visual effect script with parameters (BTLV_EFFECT_StartEffectWithRequest). */
typedef struct BtlvEffScriptRequest {
    u16 scriptId;           /* 0x00 */
    u8 pad_02[2];           /* alignment */
    int attackerPos;        /* 0x04 */
    int defenderPos;        /* 0x08 */
    u8 variant;             /* 0x0C: BtlvEffVmParams.variant */
    u8 option;              /* 0x0D: BtlvEffVmParams.option */
    u8 pad_0E[2];           /* alignment */
    int kind;               /* 0x10: BtlvEffVmParams.kind */
} BtlvEffScriptRequest;

#define BTLV_EFFECT_TASK_MAX 32
#define BTLV_EFFECT_POKE_MAX 8

/* The battle effect work (0x24C bytes), allocated by BTLV_EFFECT_Init. */
typedef struct BtlvEff {
    void *owner;                                        /* 0x000: task system */
    void *taskBuf;                                      /* 0x004 */
    void *taskHandle[BTLV_EFFECT_TASK_MAX];             /* 0x008 */
    void (*taskCallback[BTLV_EFFECT_TASK_MAX])(void *); /* 0x088 */
    int taskArg[BTLV_EFFECT_TASK_MAX];                  /* 0x108 */
    BtlvEffVmWork *effvm;                                /* 0x188 */
    struct PalAnmSlot *palanm;                          /* 0x18C */
    BtlvMcssWork *mcss;                                  /* 0x190 */
    BtlvStage *stage;                                   /* 0x194 */
    BtlvField *field;                                   /* 0x198 */
    BtlvCamera *camera;                                 /* 0x19C */
    BtlvClact *clact;                                   /* 0x1A0 */
    BtlvGaugeWork *gauge;                                /* 0x1A4 */
    BtlvPartyBallBar *partyBallBar[2];                  /* 0x1A8 */
    BtlvTimer *timer;                                   /* 0x1B0 */
    BtlvBg *bg;                                         /* 0x1B4 */
    void *vblankTask;                                   /* 0x1B8 */
    BtlvEffSetup setup;                                 /* 0x1BC */
    int effvmActive;                                    /* 0x1E8: 1 while a started effect script runs */
    unsigned int damageTintTaskMask : 8;                /* 0x1EC */
    unsigned int hitTaskMask : 8;
    unsigned int spriteTransitionTaskMask : 2;
    unsigned int visibilityMode : 8;
    unsigned int seSuppressed : 1;
    unsigned short heap;                                /* 0x1F0 */
    char pad_1F2[2];
    int bgmSaved;                                       /* 0x1F4 */
    int pokeSprite[BTLV_EFFECT_POKE_MAX];               /* 0x1F8: mcss slot of each position, -1 = none */
    unsigned int pokeEffectValue[BTLV_EFFECT_POKE_MAX]; /* 0x218 */
    int introState;                                     /* 0x238 */
    int introPhase;                                     /* 0x23C */
    int introTimer;                                     /* 0x240 */
    int introTimerMax;                                  /* 0x244 */
    int introLastPick;                                  /* 0x248 */
} BtlvEff;

#endif
