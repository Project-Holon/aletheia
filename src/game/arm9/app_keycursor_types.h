#ifndef GAME_ARM9_APP_KEYCURSOR_TYPES_H
#define GAME_ARM9_APP_KEYCURSOR_TYPES_H

#include "../types.h"

/*
 * Field skill availability flags (0x18 bytes, filled by
 * FIELD_SKILL_CHECK_FillUseFlags): bit i of usableMask is set when field skill
 * i can be used.
 */
typedef struct FieldSkillUseFlags {
    u32 reserved00;
    u32 playerObjCode;
    u8  reserved08[0xC];
    u32 usableMask;
} FieldSkillUseFlags;

#endif
