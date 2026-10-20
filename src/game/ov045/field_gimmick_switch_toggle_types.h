#ifndef OV045_GIMMICK_TYPES_H
#define OV045_GIMMICK_TYPES_H

/* Types of the ov045 field gimmick: three floor switches. Each switch is
 * drawn by two expansion-object models (index 0..2 and index 3..5) that each
 * have an "off" animation (0) and an "on" animation (1). */

#include "../types.h"

#define FIELD_GIMMICK_SWITCH_TOGGLE_SWITCH_COUNT 3
#define FIELD_GIMMICK_SWITCH_TOGGLE_SECONDARY_MODEL_OFFSET 3
#define FIELD_GIMMICK_SWITCH_TOGGLE_REQUIREMENT_COUNT 8

#define FIELD_GIMMICK_SWITCH_TOGGLE_SAVE_BLOCK_ID 9
#define FIELD_GIMMICK_SWITCH_TOGGLE_CTRL_TYPE_HYBRID 2

#define FIELD_GIMMICK_SWITCH_TOGGLE_SE_SWITCH_PRESS 0x6d0
#define FIELD_GIMMICK_SWITCH_TOGGLE_SE_SWITCH_DONE 0x6f0

/* Gimmick block of the field save (block 9). */
typedef struct FieldGimmickSwitchToggleSave {
    int switchOn[FIELD_GIMMICK_SWITCH_TOGGLE_SWITCH_COUNT];  /* nonzero: the switch is on */
} FieldGimmickSwitchToggleSave;

/* Common work of the gimmick (allocated by the setup function). */
typedef struct FieldGimmickSwitchToggleWork {
    int switchIndex;  /* switch that the running event animates */
} FieldGimmickSwitchToggleWork;

#include "../sdk_fx.h"
#endif
