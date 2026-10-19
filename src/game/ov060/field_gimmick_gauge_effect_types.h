#ifndef GAME_OV060_FIELD_GIMMICK_GAUGE_EFFECT_TYPES_H
#define GAME_OV060_FIELD_GIMMICK_GAUGE_EFFECT_TYPES_H

/* ov060: field gimmick of the intrude (visit) field. It keeps 21 field
 * expansion models: models 0..9 and 10..19 are two rows of ten gauge steps
 * (one row per record value of the visited player), model 20 is a one-shot
 * effect that the intrude sub display can show at a position. The gauges sit
 * in the column of the visited player, relative to the own net ID. */

#include "../types.h"

#define FIELD_GIMMICK_GAUGE_EFFECT_GAUGE_MODEL_COUNT  0x14   /* models 0..0x13 */
#define FIELD_GIMMICK_GAUGE_EFFECT_GAUGE_STEP_COUNT   10     /* steps per gauge row */
#define FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_MODEL       0x14
#define FIELD_GIMMICK_GAUGE_EFFECT_MODEL_COUNT        0x15
#define FIELD_GIMMICK_GAUGE_EFFECT_EFFECT_ANIME_COUNT 3

#include "../sdk_fx.h"

/* Field map common work (4 bytes), allocated in the setup function. */
typedef struct FieldGimmickGaugeEffectWork {
    u8 shownIntrudeId;      /* 0x00 intrude ID whose gauges are on show */
    u8 effectActive;        /* 0x01 nonzero while the effect model plays */
    u8 reserved02[2];
} FieldGimmickGaugeEffectWork;

#endif
