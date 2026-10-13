#ifndef ALETHEIA_OV021_EVENT_TRAINER_EYE_TYPES_H
#define ALETHEIA_OV021_EVENT_TRAINER_EYE_TYPES_H

/*
 * Trainer eye event types (event_trainer_eye.c). The script command code
 * (unit_021AE948.c) keeps one TrainerEyeHit per trainer and the work block
 * that the event creator returns.
 */
#include "../arm9/billboard_types.h"
#include "../ov010/fldmmdl_types.h"

struct FieldMap;
struct FieldPlayer;
struct FieldEffectObj;

/* A trainer that sees the player (0x18 bytes). */
typedef struct TrainerEyeHit {
    Mmdl *trainer;                                 /* 0x00 */
    int distance;                                  /* 0x04 tiles between trainer and player */
    u32 direction;                                 /* 0x08 facing the trainer sees along */
    u32 eventId;                                   /* 0x0C object event id of the trainer */
    u32 trainerId;                                 /* 0x10 */
    u32 hitKind;                                   /* 0x14 TRAINER_EYE_HIT_* */
} TrainerEyeHit;

/* Work of the trainer eye event (0x38 bytes). */
typedef struct TrainerEyeWork {
    int state;                                     /* 0x00 index in the step table */
    int finished;                                  /* 0x04 set by the last step */
    TrainerEyeHit hit;                             /* 0x08 */
    int reserved20;                                /* 0x20 cleared, never read */
    int recordIndex;                               /* 0x24 which record of the script command */
    int delayCount;                                /* 0x28 */
    struct FieldEffectObj *markEffect;             /* 0x2C "!" mark effect object */
    struct FieldMap *fieldMap;                     /* 0x30 */
    struct FieldPlayer *player;                    /* 0x34 */
} TrainerEyeWork;

/* Step table indices. */
#define TRAINER_EYE_STATE_FACE_TARGET       1
#define TRAINER_EYE_STATE_WAIT_PLAYER       2
#define TRAINER_EYE_STATE_START_TURN        3
#define TRAINER_EYE_STATE_WAIT_TURN         4
#define TRAINER_EYE_STATE_START_MARK        5
#define TRAINER_EYE_STATE_WAIT_MARK         6
#define TRAINER_EYE_STATE_START_ALERT       7
#define TRAINER_EYE_STATE_WAIT_ALERT        8
#define TRAINER_EYE_STATE_DELAY             9
#define TRAINER_EYE_STATE_SELECT_APPROACH   10
#define TRAINER_EYE_STATE_APPROACH          11
#define TRAINER_EYE_STATE_WAIT_STEP         12
#define TRAINER_EYE_STATE_ADJACENT          13
#define TRAINER_EYE_STATE_PLAYER_FACE       14
#define TRAINER_EYE_STATE_WAIT_PLAYER_FACE  15
#define TRAINER_EYE_STATE_RELEASE           16
#define TRAINER_EYE_STATE_DONE              17

/* Animation command base codes of a field model (FLDMMDL_ACMD_ConvertCodeByDir adds the direction). */
#define TRAINER_EYE_ACMD_TURN 0
#define TRAINER_EYE_ACMD_WALK 12

#endif
