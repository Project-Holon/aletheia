#ifndef GAME_OV074_FLD3D_CI_NAME_TYPES_H
#define GAME_OV074_FLD3D_CI_NAME_TYPES_H

#include "../types.h"

/* One row of the name cut-in table (g_Fld3dCiNameRows, 0x14 bytes). */
typedef struct Fld3dCiNameRow {
    u32 sequenceId;
    u32 chrFile;
    u32 plttFile;
    u32 nameMsgId;
    u32 nameLayout;
} Fld3dCiNameRow;

#endif
