#ifndef ALETHEIA_OV050_FIELD_GIMMICK_MODELS_B_TYPES_H
#define ALETHEIA_OV050_FIELD_GIMMICK_MODELS_B_TYPES_H

#include "../types.h"

/*
 * Field gimmick 50 (overlay 50): one expansion unit of two models. Model 0
 * has one animation, model 1 has two. Script commands start, stop and poll
 * them; model 1 is hidden until it is shown.
 */

/* Include ov021/fld_exp_obj_types.h first (the compiler resolves includes against the source file directory). */

struct FieldMap;
struct GameSystem;

#define FIELD_GIMMICK_MODELS_B_MODEL_COUNT 2

/* The common work of the gimmick on the field map (2 bytes, id 1). */
typedef struct FieldGimmickModelsBWork {
    u16 heapId;         /* 0x00: heap of the field map */
} FieldGimmickModelsBWork;

/* The functions of overlay 21 and arm9 that the gimmick uses. */
#include "../ov021/fld_exp_obj.h"
/* The model and animation indices are u16: the callers truncate them. */

#endif
