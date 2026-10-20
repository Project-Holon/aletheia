#ifndef ALETHEIA_OV049_FIELD_GIMMICK_MODELS_A_TYPES_H
#define ALETHEIA_OV049_FIELD_GIMMICK_MODELS_A_TYPES_H

/*
 * Field gimmick 49 (overlay 49): one expansion unit of six models. Models 0
 * and 1 start their animation once all four event flags are set; models 2 to
 * 5 start theirs one by one with the flag of the same row.
 */

/* Include ov021/fld_exp_obj_types.h first (the compiler resolves includes against the source file directory). */

struct FieldMap;
struct GameSystem;
struct GameData;
struct EventWork;

#define FIELD_GIMMICK_MODELS_A_MODEL_COUNT 6

/* Event flags that switch on models 2, 3, 4 and 5. */
#define FIELD_GIMMICK_MODELS_A_FLAG_MODEL2 0x96B
#define FIELD_GIMMICK_MODELS_A_FLAG_MODEL3 0x96A
#define FIELD_GIMMICK_MODELS_A_FLAG_MODEL4 0x969
#define FIELD_GIMMICK_MODELS_A_FLAG_MODEL5 0x96C

/* The common work of the gimmick on the field map (2 bytes, id 0). */
typedef struct FieldGimmickModelsAWork {
    u16 heapId;         /* 0x00: heap of the field map */
} FieldGimmickModelsAWork;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
#include "../ov021/fld_exp_obj.h"

#endif
